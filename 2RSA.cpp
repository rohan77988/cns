#include <bits/stdc++.h>
using namespace std;

// Returns gcd of a and b
int gcd(int a, int h)
{
    int temp;
    while (1)
    {
        temp = a % h;
        if (temp == 0)
            return h;
        a = h;
        h = temp;
    }
}

int modo(int base, int exponent, int modulus)
{
    int result = 1;
    for (int i = 0; i < exponent; ++i)
    {
        result = (result * base) % modulus;
    }
    return result;
}
// Code to demonstrate RSA algorithm
int main()
{
    // Two random prime numbers
    int p = 3;
    int q = 11;

    // First part of public key:
    int n = p * q;

    // Finding other part of public key.
    // e stands for encrypt
    int e = 3;
    int phi = (p - 1) * (q - 1);
    while (e < phi)
    {
        // e must be co-prime to phi and
        // smaller than phi.
        if (gcd(e, phi) == 1)
            break;
        else
            e++;
    }

    // Private key (d stands for decrypt)
    // choosing d such that it satisfies
    // d*e = 1 + k * totient
    int d;
    for (d = 2; d < phi; d++)
    {
        if ((e * d) % phi == 1)
        {
            // Found the modular inverse
            break;
        }
    }

    // Message to be encrypted
    int msg = 3;

    cout << "MESSAGE DATA = " << msg << endl;
    // Encryption c = (msg ^ e) % n
    clock_t start = clock();
    int c = modo(msg, e, n);
    clock_t end = clock();
    int encryptionTime = static_cast<int>(end - start) / CLOCKS_PER_SEC;
    cout << "Encrypted data = " << c << endl;

    // Decryption m = (c ^ d) % n
    start = clock();
    int m = modo(c, d, n);
    end = clock();
    int decryptionTime = static_cast<int>(end - start) / CLOCKS_PER_SEC;
    cout << "Original Message sent = " << m << endl;
    cout << "\nTime taken for encryption: " << encryptionTime << " seconds\n";
    cout << "Time taken for decryption: " << decryptionTime << " seconds\n";

// For string input
    // string msg;
    // cout << "Enter a message to encrypt: ";
    // getline(cin, msg);

    // cout << "MESSAGE DATA = " << msg << endl;

    // // Encryption and Decryption
    // string encrypted_msg = "";
    // string decrypted_msg = "";

    // for (char ch : msg)
    // {
    //     // Encryption c = (msg ^ e) % n
    //     int encrypted_char = modo(ch, e, n);
    //     encrypted_msg += static_cast<char>(encrypted_char);

    //     // Decryption m = (c ^ d) % n
    //     int decrypted_char = modo(encrypted_char, d, n);
    //     decrypted_msg += static_cast<char>(decrypted_char);
    // }

    // cout << "Encrypted data: " << encrypted_msg << endl;
    // cout << "Decrypted data: " << decrypted_msg << endl;


    return 0;
}