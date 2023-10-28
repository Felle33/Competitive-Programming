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
const ll LL_MAX = 9223372036854775807;
vector<int> DX = {0, 1, -1, 0};
vector<int> DY = {1, 0, 0, -1};
string DIR = "RDUL";

void solve(){
    int n, k; cin >> n >> k;
    string s; cin >> s;
    vector<int> cnt(26);

    for(int i = 0; i < n; i++) {
        cnt[s[i] - 'a']++;
    }

    int rend_pari = 0;
    bool all_pari = true, one_dis = false, more_dis = false;
    for(int i = 0; i < 26; i++) {
        if(cnt[i] % 2 == 1) {
            rend_pari++;
            all_pari = 0;
            if(one_dis || more_dis) {
                more_dis = 1;
                one_dis = 0;
            } else {
                one_dis = 1;
            }
        }
    }

    if(all_pari || one_dis) {
        cout << "YES\n";
    } else {
        rend_pari--;
        if(k < rend_pari) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
        }
    }


}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    std::cout.precision(10);
    cout << std::fixed;

    int t;
    cin >> t;

    while(t--){
        solve();
    }
}