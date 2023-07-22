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

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

const ll MOD = 1e9 + 7;
const ll DIM = 1e6;
const ll INF = 1e9;
vector<int> DX = {0, 1, -1, 0};
vector<int> DY = {1, 0, 0, -1};
string DIR = "RDUL";

void solve(){
    int a, b, k;
    pii viki;
    cin >> a >> b >> k;
    cin >> viki.first >> viki.second;

    bool cat = false;
    bool same = false;
    rep(i, k) {
        pii f;
        cin >> f.first >> f.second;

        if(f.first == viki.first && f.second == viki.second) cat = true;
        
        int d = abs(viki.first - f.first) + abs(viki.second - f.second);
        if(d % 2 == 0) cat = true;
    }

    if(cat) cout << "NO\n";
    else cout << "YES\n";
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