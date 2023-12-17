// NOTE: it is recommended to use this even if you don't understand the following code.

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef long long ll;

const int MAX_N = 1e5;

ll b = 31;
ll pows[MAX_N + 1];
ll hashes[MAX_N + 1];
// sum_of_pows[i][j] = sum of pows from k = 0 to 2^(j - 1) with k that increase by i each time
vector<ll> sum_of_pows[MAX_N + 1];
ll MOD = 1e9 + 7;

vector<int> divisors[MAX_N + 1];

ll ord(char c) {
    return c - 'a' + 1;
}

void calculate_hash(string& s) {
    int n = s.size();
    pows[0] = 1;
    for(int i = 1; i <= n; i++) {
        pows[i] = pows[i - 1] * b % MOD;
        hashes[i] = (hashes[i - 1] * b + ord(s[i - 1])) % MOD;
    }
}

void populate_divisors(ll num, vector<int>& divs) {
    for(int m = 1; m * m <= num; m++) {
        if(num % m == 0) {
            divs.push_back(m);
            if(m != 1)  divs.push_back(num / m);
        }
    }
}

// O(n * log(n))
void calculate_sum_of_pows(int n) {
    ll multiply_b = b;
    for(int len = 1; len <= n; len++) {
        sum_of_pows[len].push_back(1);
        for(int j = 1; j <= n; j += len) {
            sum_of_pows[len].push_back((sum_of_pows[len].back() * multiply_b % MOD + 1) % MOD);
        }
        multiply_b = multiply_b * b % MOD;
    }
}

// O(n * log(n))
void calculate_divisors(int n) {
    for(int div = 1; div <= n; div++) {
        for(int j = div; j <= n; j += div) {
            divisors[j].push_back(div);
        }
    }
}

int main() {
    // uncomment the two following lines if you want to read/write from files
    // ifstream cin("input.txt");
    // ofstream cout("output.txt");

    int n;
    cin >> n;
    
    string s;
    cin >> s;
    
    int q;
    cin >> q;
    
    vector<int> l(q), r(q);
    for (int i = 0; i < q; ++i)
        cin >> l[i] >> r[i];
    
    vector<string> ans(q);
    
    // INSERT YOUR CODE HERE
    calculate_hash(s);
    calculate_sum_of_pows(n);
    calculate_divisors(n);

    for(int k = 0; k < q; k++) {
        int left = l[k];
        int right = r[k];
        int len = right - left + 1;

        if(left == right) {
            ans[k] = "NO";
            continue;
        }   

        bool found_per = 0;
        ll hash_string = hashes[right + 1] - hashes[left] * pows[len] % MOD;
        if(hash_string < 0) hash_string += MOD;

        for(int div : divisors[len]) {
            if(div == len) continue;
            // check if the string can be divided in div strings
            ll hash_needle = hashes[left + div] - hashes[left] * pows[div] % MOD;
            if(hash_needle < 0) hash_needle += MOD;
            
            ll hash_needle_tmp = hash_needle * sum_of_pows[div][len / div - 1] % MOD;

            if(hash_needle_tmp == hash_string) {
                found_per = 1;
                break;
            }
        }

        if(found_per) {
            ans[k] = "YES";
        } else {
            ans[k] = "NO";
        }

    }
    
    
    for (int i = 0; i < q; ++i)
        cout << ans[i] << '\n';

    return 0;
}
