
#if defined(USE_WIN32_CRYPTO)
  /* Import certificates from the Windows root certificate store if requested.
     https://stackoverflow.com/questions/9507184/
     https://github.com/d3x0r/SACK/blob/master/src/netlib/ssl_layer.c#L1037
     https://datatracker.ietf.org/doc/html/rfc5280 */
  if((conn_config->verifypeer || conn_config->verifyhost) &&
     (ssl_config->native_ca_store)) {
    HCERTSTORE hStore = CertOpenSystemStore(0, TEXT("ROOT"));

    if(hStore) {
      PCCERT_CONTEXT pContext = NULL;
      /* The array of enhanced key usage OIDs will vary per certificate and is
         declared outside of the loop so that rather than malloc/free each
         iteration we can grow it with realloc, when necessary. */
      CERT_ENHKEY_USAGE *enhkey_usage = NULL;
      DWORD enhkey_usage_size = 0;

      /* This loop makes a best effort to import all valid certificates from
         the MS root store. If a certificate cannot be imported it is skipped.
         'result' is used to store only hard-fail conditions (such as out of
         memory) that cause an early break. */
      result = CURLE_OK;
      for(;;) {
        X509 *x509;
        FILETIME now;
        BYTE key_usage[2];
        DWORD req_size;
        const unsigned char *encoded_cert;
#if defined(DEBUGBUILD) && !defined(CURL_DISABLE_VERBOSE_STRINGS)
        char cert_name[256];
#endif

        pContext = CertEnumCertificatesInStore(hStore, pContext);
        if(!pContext)
          break;

#if defined(DEBUGBUILD) && !defined(CURL_DISABLE_VERBOSE_STRINGS)
        if(!CertGetNameStringA(pContext, CERT_NAME_SIMPLE_DISPLAY_TYPE, 0,
                               NULL, cert_name, sizeof(cert_name))) {
          strcpy(cert_name, "Unknown");
        }
        infof(data, "SSL: Checking cert \"%s\"", cert_name);
#endif

        encoded_cert = (const unsigned char *)pContext->pbCertEncoded;
        if(!encoded_cert)
          continue;

        GetSystemTimeAsFileTime(&now);
        if(CompareFileTime(&pContext->pCertInfo->NotBefore, &now) > 0 ||
           CompareFileTime(&now, &pContext->pCertInfo->NotAfter) > 0)
          continue;

        /* If key usage exists check for signing attribute */
        if(CertGetIntendedKeyUsage(pContext->dwCertEncodingType,
                                   pContext->pCertInfo,
                                   key_usage, sizeof(key_usage))) {
          if(!(key_usage[0] & CERT_KEY_CERT_SIGN_KEY_USAGE))
            continue;
        }
        else if(GetLastError())
          continue;

        /* If enhanced key usage exists check for server auth attribute.
         *
         * Note "In a Microsoft environment, a certificate might also have EKU
         * extended properties that specify valid uses for the certificate."
         * The call below checks both, and behavior varies depending on what is
         * found. For more details see CertGetEnhancedKeyUsage doc.
         */
        if(CertGetEnhancedKeyUsage(pContext, 0, NULL, &req_size)) {
          if(req_size && req_size > enhkey_usage_size) {
            void *tmp = realloc(enhkey_usage, req_size);

            if(!tmp) {
              failf(data, "SSL: Out of memory allocating for OID list");
              result = CURLE_OUT_OF_MEMORY;
              break;
            }

            enhkey_usage = (CERT_ENHKEY_USAGE *)tmp;
            enhkey_usage_size = req_size;
          }

          if(CertGetEnhancedKeyUsage(pContext, 0, enhkey_usage, &req_size)) {
            if(!enhkey_usage->cUsageIdentifier) {
              /* "If GetLastError returns CRYPT_E_NOT_FOUND, the certificate is
                 good for all uses. If it returns zero, the certificate has no
                 valid uses." */
              if((HRESULT)GetLastError() != CRYPT_E_NOT_FOUND)
                continue;
            }
            else {
              DWORD i;
              bool found = false;

              for(i = 0; i < enhkey_usage->cUsageIdentifier; ++i) {
                if(!strcmp("1.3.6.1.5.5.7.3.1" /* OID server auth */,
                           enhkey_usage->rgpszUsageIdentifier[i])) {
                  found = true;
                  break;
                }
              }

              if(!found)
                continue;
            }
          }
          else
            continue;
        }
        else
          continue;

        x509 = d2i_X509(NULL, &encoded_cert, pContext->cbCertEncoded);
        if(!x509)
          continue;

        /* Try to import the certificate. This may fail for legitimate reasons
           such as duplicate certificate, which is allowed by MS but not
           OpenSSL. */
        if(X509_STORE_add_cert(store, x509) == 1) {
#if defined(DEBUGBUILD) && !defined(CURL_DISABLE_VERBOSE_STRINGS)
          infof(data, "SSL: Imported cert \"%s\"", cert_name);
#endif
          imported_native_ca = true;
        }
        X509_free(x509);
      }

      free(enhkey_usage);
      CertFreeCertificateContext(pContext);
      CertCloseStore(hStore, 0);

      if(result)
        return result;
    }
    if(imported_native_ca)
      infof(data, "successfully imported Windows CA store");
    else
      infof(data, "error importing Windows CA store, continuing anyway");
  }
#endif
