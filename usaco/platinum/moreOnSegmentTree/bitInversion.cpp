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
#include <bitset>

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

struct SegmentTree {
    int size;
    vector<ll> ones, sufOnes, prefOnes;
    vector<ll> zeroes, sufZeroes, prefZeroes;


    SegmentTree(int n) {
        size = 1;
        while(size < n) size *= 2;
        ones.resize(2 * size, 0LL);
        prefOnes.resize(2 * size, 0LL);
        sufOnes.resize(2 * size, 0LL);

        zeroes.resize(2 * size, 0LL);
        prefZeroes.resize(2 * size, 0LL);
        sufZeroes.resize(2 * size, 0LL);
    }

    void build(vector<ll>& numbers){
        build(numbers, 0, 0, size);
    }

    void build(vector<ll>& numbers, int x, int lx, int rx) {
        if(rx - lx == 1) {
            if(lx < (int) numbers.size()) {
                ones[x] = (numbers[lx] == 1);
                prefOnes[x] = ones[x];
                sufOnes[x] = ones[x];

                zeroes[x] = (numbers[lx] == 0);
                prefZeroes[x] = zeroes[x];
                sufZeroes[x] = zeroes[x];
            }
            return;
        }

        int mid = (lx + rx) / 2;
        build(numbers, 2 * x + 1, lx, mid);
        build(numbers, 2 * x + 2, mid, rx);

        prefOnes[x] = (prefOnes[2 * x + 1] == (mid - lx) ? (prefOnes[2 * x + 1] + prefOnes[2 * x + 2]) : prefOnes[2 * x + 1]);
        sufOnes[x] = (sufOnes[2 * x + 2] == (rx - mid) ? (sufOnes[2 * x + 2] + sufOnes[2 * x + 1]) : sufOnes[2 * x + 2]);
        ones[x] = max({ones[2 * x + 1], ones[2 * x + 2], sufOnes[2 * x + 1] + prefOnes[2 * x + 2]});

        prefZeroes[x] = (prefZeroes[2 * x + 1] == (mid - lx) ? (prefZeroes[2 * x + 1] + prefZeroes[2 * x + 2]) : prefZeroes[2 * x + 1]);
        sufZeroes[x] = (sufZeroes[2 * x + 2] == (rx - mid) ? (sufZeroes[2 * x + 2] + sufZeroes[2 * x + 1]) : sufZeroes[2 * x + 2]);
        zeroes[x] = max({zeroes[2 * x + 1], zeroes[2 * x + 2], sufZeroes[2 * x + 1] + prefZeroes[2 * x + 2]});
    }

    void invert(int i, int x, int lx, int rx) {
        if(rx - lx == 1) {
            ones[x] = !ones[x];
            prefOnes[x] = ones[x];
            sufOnes[x] = ones[x];

            zeroes[x] = !zeroes[x];
            prefZeroes[x] = zeroes[x];
            sufZeroes[x] = zeroes[x];
            return;
        }

        int mid = (lx + rx) / 2;
        if(i < mid) {
            invert(i, 2 * x + 1, lx, mid);
        } else {
            invert(i, 2 * x + 2, mid, rx);
        }

        prefOnes[x] = (prefOnes[2 * x + 1] == (mid - lx) ? (prefOnes[2 * x + 1] + prefOnes[2 * x + 2]) : prefOnes[2 * x + 1]);
        sufOnes[x] = (sufOnes[2 * x + 2] == (rx - mid) ? (sufOnes[2 * x + 2] + sufOnes[2 * x + 1]) : sufOnes[2 * x + 2]);
        ones[x] = max({ones[2 * x + 1], ones[2 * x + 2], sufOnes[2 * x + 1] + prefOnes[2 * x + 2]});

        prefZeroes[x] = (prefZeroes[2 * x + 1] == (mid - lx) ? (prefZeroes[2 * x + 1] + prefZeroes[2 * x + 2]) : prefZeroes[2 * x + 1]);
        sufZeroes[x] = (sufZeroes[2 * x + 2] == (rx - mid) ? (sufZeroes[2 * x + 2] + sufZeroes[2 * x + 1]) : sufZeroes[2 * x + 2]);
        zeroes[x] = max({zeroes[2 * x + 1], zeroes[2 * x + 2], sufZeroes[2 * x + 1] + prefZeroes[2 * x + 2]});
    }

    void invert(int i) {
        invert(i, 0, 0, size);
    }

    ll maxZeroes() {
        return zeroes[0];
    }

    ll maxOnes() {
        return ones[0];
    }
};

void solve(){
    string s; cin >> s;
    int n = s.size();
    vll nums(n);
    rep(i, n) {
        if(s[i] == '0') {
            nums[i] = 0;
        } else {
            nums[i] = 1;
        }
    }
    SegmentTree sgt(n);
    sgt.build(nums);
    int m; cin >> m;

    while(m--) {
        int a; cin >> a;
        a--;
        sgt.invert(a);
        if(m > 0) {
            cout << max(sgt.maxOnes(), sgt.maxZeroes()) << " ";
        } else {
            cout << max(sgt.maxOnes(), sgt.maxZeroes());
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    std::cout.precision(10);
    cout << std::fixed;

    solve();
}