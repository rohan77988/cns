#include <iostream>
#include <cmath>
using namespace std;

// Function to calculate (base^exponent) % modulo efficiently
long long mod_pow(long long base, long long exponent, long long modulo)
{
    long long result = 1;
    while (exponent > 0)
    {
        if (exponent % 2 == 1)
        {
            result = (result * base) % modulo;
        }
        base = (base * base) % modulo;
        exponent /= 2;
    }
    return result;
}

int main()
{
    // Constants (publicly known)
    const long long p = 7; // Prime modulus
    const long long g = 5; // Primitive root modulo p

    // Alice's private key
    long long privateKeyAlice;
    cout << "Alice, enter your private key: ";
    cin >> privateKeyAlice;

    // Bob's private key
    long long privateKeyBob;
    cout << "Bob, enter your private key: ";
    cin >> privateKeyBob;

    // Alice computes her public key
    long long publicKeyAlice = mod_pow(g, privateKeyAlice, p);

    // Bob computes his public key
    long long publicKeyBob = mod_pow(g, privateKeyBob, p);

    // MITM attack (Eve)
    long long interceptedPublicKeyAlice;
    long long interceptedPublicKeyBob;

    // Eve intercepts the public keys
    interceptedPublicKeyAlice = publicKeyAlice;
    interceptedPublicKeyBob = publicKeyBob;
    
    
    // Eve computes her own shared secrets
    long long sharedSecretEveAlice = mod_pow(interceptedPublicKeyBob, privateKeyAlice, p);
    long long sharedSecretEveBob = mod_pow(interceptedPublicKeyAlice, privateKeyBob, p);

    // Display shared secrets
    cout << "Shared secret computed by Alice: " << sharedSecretEveAlice << endl;
    cout << "Shared secret computed by Bob: " << sharedSecretEveBob << endl;

    if (sharedSecretEveAlice == sharedSecretEveBob)
    {
        cout << "MITM attack successful! Eve has intercepted the messages." << endl;
        cout << "Eve's intercepted data: " << sharedSecretEveAlice << endl;
    }
    else
    {
        cout << "Communication is secure. Messages are not compromised." << endl;
    }
    
    // //Key Generation
    // long long secretKeyAlice = mod_pow(publicKeyBob,privateKeyAlice,p);
    // long long secretKeyBob = mod_pow(publicKeyAlice,privateKeyBob,p);
    // if(secretKeyAlice == secretKeyBob)
    // cout<<"Key Exchange Successfull";
    return 0;
}
