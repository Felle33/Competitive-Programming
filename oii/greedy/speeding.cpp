// NOTE: it is recommended to use this even if you don't understand the following code.

#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long MOD = 1e9 + 7;

int main() {
    // uncomment the following lines if you want to read/write from files
    // ifstream cin("input.txt");
    // ofstream cout("output.txt");

    int n;
    cin >> n;
    
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    // insert your code here

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    vector<long long> slots(n);
    long long cur = 0;
    for(int i = n - 1, j = n - 1; i >= 0; i--) {
        while(j >= 0 && a[j] >= b[i]) {
            j--;
            cur++;
        }

        slots[i] = cur;
    }

    long long res = 1;
    cur = 0;
    for(int i = n - 1; i >= 0; i--) {
        res = res * (slots[i] - cur) % MOD;
        cur++;
    }

    cout << res << endl; // print the result
    return 0;
}
