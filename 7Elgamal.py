import random

def is_prime(num):
    """Check if a number is prime."""
    if num < 2:
        return False
    for i in range(2, int(num**0.5) + 1):
        if num % i == 0:
            return False
    return True

def generate_prime():
    """Generate a random prime number."""
    p = random.randint(50, 200)
    while not is_prime(p):
        p = random.randint(50, 200)
    return p

def find_primitive_root(p):
    """Find a primitive root modulo p."""
    primitive_roots = []
    for i in range(2, p):
        is_primitive = True
        for j in range(1, p - 1):
            if pow(i, j, p) == 1:
                is_primitive = False
                break
        if is_primitive:
            primitive_roots.append(i)

    return random.choice(primitive_roots)

def generate_keypair(p):
    """Generate ElGamal key pair."""
    x = random.randint(2, p - 1)
    g = find_primitive_root(p)
    y = pow(g, x, p)
    return x, y, p, g

def encrypt(message, y, p, g):
    """Encrypt a message using ElGamal."""
    k = random.randint(2, p - 2)
    c1 = pow(g, k, p)
    c2 = (pow(y, k, p) * message) % p
    return c1, c2

def decrypt(c1, c2, x, p):
    """Decrypt an ElGamal ciphertext."""
    s = pow(c1, x, p)
    s_inverse = pow(s, -1, p)
    decrypted_message = (c2 * s_inverse) % p
    return decrypted_message

def main():
    # Generate a random prime number
    prime = generate_prime()

    # Generate ElGamal key pair
    private_key, public_key, p, g = generate_keypair(prime)

    # Message to be encrypted
    message = 42

    # Encrypt the message
    c1, c2 = encrypt(message, public_key, p, g)

    # Decrypt the ciphertext
    decrypted_message = decrypt(c1, c2, private_key, p)

    print("Original Message:", message)
    print("Encrypted Message (c1, c2):", c1, c2)
    print("Decrypted Message:", decrypted_message)

if __name__ == "__main__":
    main()
