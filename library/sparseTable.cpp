#include <algorithm>
#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
#include <cstring>
#include <unordered_map>
#include <map>
#include <set>
#include <iomanip>

#define all(x) (x).begin(), (x).end()
#define mp make_pair
#define pb push_back
#define rep(X,Y) for (int (X) = 0;(X) < (Y);++(X))
#define reps(X,S,Y) for (int (X) = S;(X) < (Y);++(X))

using namespace std;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<unsigned long long> vull;
typedef vector<vector<int>> vvi;
typedef long long ll;
typedef pair<int,int> pii;

const ll MOD = 1e9 + 7;
const ll DIM = 1e6;
const ll INF = 1e15;
vector<int> DX = {0, 1, -1, 0};
vector<int> DY = {1, 0, 0, -1};
string DIR = "RDUL";

int log2_floor(unsigned long long i) {
    return i ? __builtin_clzll(1) - __builtin_clzll(i) : -1;
}

// Minimum in O(1)
struct SparseTable {
    static const int K = 25;
    vector<ll> table[K];
    int n;

    SparseTable(vll& a) {
        n = a.size();
        for(int i = 0; i < K; i++) table[i].resize(n);
        for(int i = 0; i < n; i++) {
            table[0][i] = a[i];
        }

        for(int i = 1; i < K; i++) {
            for(int j = 0; j + (1 << i) <= n; j++) {
                table[i][j] = min(table[i - 1][j], table[i - 1][j + (1 << (i - 1))]);
            }
        }
    }

    // minimum from l to r inclusive [l, r]
    ll minimum(int l, int r) {
        int ln2 = log2_floor(r - l + 1);
        return min(table[ln2][l], table[ln2][r - (1 << ln2) + 1]);
    }
};