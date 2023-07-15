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
#define rep(X,Y) for (int (X) = 0;(X) < (Y);++(X))
#define reps(X,S,Y) for (int (X) = S;(X) < (Y);++(X))

typedef long long ll;
using namespace std;

const ll MOD = 1e9 + 7;
const ll DIM = 1e6;
const ll INF = 1e9;
vector<int> DX = {0, 1, -1, 0};
vector<int> DY = {1, 0, 0, -1};
string DIR = "RDUL";

void solve(){
    int n, m, q;
    cin >> n >> m >> q;

    vector<int> nums(n);
    vector<int> wu(n);

    rep(i, n){
        cin >> wu[i];
    }

    map<string, int> mp;
    string s;
    rep(i, m){
        cin >> s;
        mp[s]++;
    }

    string t;
    int k;
    rep(i, q){
        int ans = 0;
        cin >> t >> k;

        for(auto it = mp.begin(); it != mp.end(); it++){
            string q = it->first;
            int wuu = 0;

            for(int i = 0; i < n; i++){
                if(q[i] == t[i]){
                    wuu += wu[i];
                }
            }

            if(wuu <= k){
                ans += it->second;
            }
        }

        cout << ans << '\n';
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
}