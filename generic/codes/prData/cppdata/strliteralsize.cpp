#include <iostream>

#define SSLDEFAULT_LITERAL "Default"
#define SSLV3_LITERAL "SSLv3"
#define TLS1_2_LITERAL "TLSv1.2"


int main()
{

    static const char * SSL_VERSION[] =
    {
        SSLDEFAULT_LITERAL,
        SSLV3_LITERAL,
        TLS1_2_LITERAL
    };

    std::cout << std::endl << sizeof(SSL_VERSION);
    
    return 0;
}