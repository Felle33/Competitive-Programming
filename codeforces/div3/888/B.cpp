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
    // position of even and odd
    set<int> even, odd;

    int n;
    cin >> n;
    vector<int> nums(n);
    rep(i, n) {
        cin >> nums[i];
        if(nums[i] % 2 == 0) {
            even.insert(i);
        } else {
            odd.insert(i);
        }
    }

    sort(all(nums));
    rep(i, n) {
        if(nums[i] % 2 == 0) {
            if(even.count(i) == 0) {
                cout << "NO" << '\n';
                return;
            }
        } else {
            if(odd.count(i) == 0) {
                cout << "NO" << '\n';
                return;
            }
        }
    }

    cout << "YES" << '\n';
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