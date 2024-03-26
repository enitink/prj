//
//  main.cpp
//  CertVerifier
//
//  Created by Nitin Kumar on 04/01/23.
//

#include <iostream>

#include <Security/Security.h>

int main(int argc, const char * argv[]) {
    CFStringRef keys[] = { kSecClass,    kSecMatchLimit,    kSecReturnRef };
    //CFTypeRef values[] = { kSecClassKey, kSecMatchLimitAll, kCFBooleanTrue };
    CFTypeRef values[] = { kSecClassCertificate, kSecMatchLimitAll, kCFBooleanTrue };
    
    CFDictionaryRef query = CFDictionaryCreate(
        NULL,
        (const void **) keys,
        values,
        sizeof(keys) / sizeof(keys[0]),
        &kCFTypeDictionaryKeyCallBacks,
        &kCFTypeDictionaryValueCallBacks
    );

    CFTypeRef copyResult = NULL;
    OSStatus err = SecItemCopyMatching(query, &copyResult);
    if (err == errSecSuccess) {
        CFShow(copyResult);
    }
  
  return 0;
}

