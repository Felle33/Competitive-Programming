
using namespace std;

int exp(long long b, long long e, long long mod) {
    long long res = 1;
    b %= mod;

    while(e > 0) {
        if(e & 1) {
            res = res * b % mod;
        }  
        
        b = b * b % mod;
        e >>= 1;
    }

    return res;
}

void decifra(int n, int d, int L, int* messaggio, char* plaintext) {
    // Esempio di implementazione con un solo carattere da decifrare.
    // Mettiamo il risultato della decifrazione in plaintext[0] e il
    // carattere di fine stringa in plaintext[1].
    
    for(int i = 0; i < L; i++) {
        plaintext[i] = exp(messaggio[i], d, n);
    }
    plaintext[L] = '\0';
}
