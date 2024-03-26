//
//  certmain.cpp
//  CertVerifier
//
//  Created by Nitin Kumar on 05/01/23.
//

#include <iostream>

#include <Security/Security.h>

CFData *get_certificate_data(CFData *persistentRef) {
    CFDictionaryRef *query = @{(id)kSecClass: (id)kSecClassCertificate,
                            (id)kSecReturnRef: (id)kCFBooleanTrue,
                            (id)kSecValuePersistentRef: persistentRef};
    
    CFTypeRef item;
    OSStatus res = SecItemCopyMatching((CFDictionaryRef)query, &item);
    if (res != 0) {
        NSLog(@"Failed to extract certificate: %@", SecCopyErrorMessageString(res, NULL));
    } else {
        NSLog(@"Found certificate: %@", item);
        CFDataRef data;
        res = SecItemExport(item, kSecFormatPEMSequence, kSecItemPemArmour, NULL, &data);
        if (res != 0) {
            NSLog(@"Failed to export certificate: %@", SecCopyErrorMessageString(res, NULL));
        } else {
            return (__bridge NSData *)(data);
        }
    }
    return NULL;
}

void export_certificates(const SFAppleIDAccount *account, NSString *path) {
    NSData *intermediate_cert = get_certificate_data(account.identity.intermediateCertificatePersistentReference);
    
    NSData *cert = get_certificate_data(account.identity.certificatePersistentReference);
    
    if (intermediate_cert == NULL || cert == NULL) {
        NSLog(@"Failed to export certificates");
        return;
    }
    NSMutableData *certs = [NSMutableData dataWithLength:0];
    [certs appendData:cert];
    [certs appendData:intermediate_cert];
    
    [certs writeToFile:path atomically:FALSE];
    NSLog(@"Exported certificates to '%@'", path);
}

void export_validation_record(const SFAppleIDAccount *account, NSString *path) {
    [account.validationRecord.data writeToFile:path atomically:FALSE];
    NSLog(@"Exported validation record data to '%@'", path);
}

int main(int argc, const char * argv[]) {

    // as defined in sharingd`-[SDAppleIDDatabaseManager _readPrefs]
    NSData *plist = (__bridge NSData *) CFPreferencesCopyValue((CFStringRef)@"AppleIDAccount",
                                                               (CFStringRef)@"com.apple.sharingd",
                                                               (CFStringRef)kCFPreferencesCurrentUser,
                                                               (CFStringRef)kCFPreferencesCurrentHost);

    SFAppleIDAccount *account = [NSKeyedUnarchiver unarchivedObjectOfClass:SFAppleIDAccount.class fromData:plist error:NULL];
    
    // private key and certificate are stored in iCloud keychain
    // persistent reference seems to consist of SQLite table and 'rowid'
    //
    // example (privateKeyPersistentReference):
    // <63657274 00000000 00000002>
    //   c e r t                 ^
    //                         rowid
    
    export_validation_record(account, @"validation_record.cms");
    
    export_certificates(account, @"certificate.pem");

    export_key(account, @"key.pem");
    
    return 0;
}
