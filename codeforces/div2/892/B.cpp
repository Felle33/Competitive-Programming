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
#define f first
#define s second
#define rep(X,Y) for (int (X) = 0;(X) < (Y);++(X))
#define reps(X,S,Y) for (int (X) = S;(X) < (Y);++(X))

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

const ll MOD = 1e9 + 7;
const ll DIM = 1e6;
const ll INF = 1e9 + 1;
vector<int> DX = {0, 1, -1, 0};
vector<int> DY = {1, 0, 0, -1};
string DIR = "RDUL";

void solve(){
    int n;
    cin >> n;

    ll min1Colonna = INF;
    ll min2Colonna = INF;
    ll conta2Colonna = 0;
    rep(i, n) {
        int m;
        cin >> m;
        vector<ll> nums(m);
        rep(j, m) {
            cin >> nums[j];
        }
        sort(all(nums));
        min1Colonna = min(min1Colonna, nums[0]);
        min2Colonna = min(min2Colonna, nums[1]);
        conta2Colonna += nums[1];
    }

    cout << (conta2Colonna - min2Colonna + min1Colonna) << '\n';
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