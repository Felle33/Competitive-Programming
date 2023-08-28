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

bool cmp(pair<char, int> p1, pair<char, int> p2) {
    return p1.first < p2.first;
}

void solve(){
    int n, k; cin >> n >> k;
    string s;
    cin >> s;

    vector<char> characters(n);
    vector<char> vpari, vdispari;
    for(int i = 0; i < n; i++) {
        characters[i] = s[i];
        if(i % 2 == 0) {
            vpari.push_back(s[i]);
        } else {
            vdispari.push_back(s[i]);
        }
    }

    sort(all(characters));
    sort(all(vpari));
    sort(all(vdispari));
    if(k % 2 == 1) {
        int n = vpari.size();
        for(int i = 0; i < n; i++) {
            cout << vpari[i];
            if(i < (int) vdispari.size()) cout << vdispari[i];
        }
    } else {
        for(int i = 0; i < n; i++) {
            cout << characters[i];
        }
    }

    cout << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--){
        solve();
    }
}