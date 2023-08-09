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
    int n;
    cin >> n;
    int m = n * (n - 1) / 2;
    vector<int> nums(m);
    map<int, int> count;
    int p = 1e9;
    rep(i, m) {
        cin >> nums[i];
        count[nums[i]] += 1;
    }

    int rep = n - 1;
    for(auto it = count.begin(); it != count.end(); it++) {
        while(it->second > 0) {
            it->second -= rep;
            rep--;
            cout << it->first << " ";
        }
    }
    cout << p << '\n';
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