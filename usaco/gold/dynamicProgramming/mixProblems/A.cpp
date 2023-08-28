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
typedef vector<vector<long long>> vvll;
typedef long long ll;
typedef pair<int,int> pii;

const ll MOD = 1e9 + 7;
const ll DIM = 1e6;
const ll INF = 1e15;
vector<int> DX = {0, 1, -1, 0};
vector<int> DY = {1, 0, 0, -1};
string DIR = "RDUL";
int n;
vi nums;

void solve(){
    cin >> n;
    nums.resize(n);
    rep(i, n) cin >> nums[i];
    vll dp1 = vll(3, INF);
    vll dp2 = vll(3, INF);

    dp1[0] = 0;
    for(int i = 0; i < n; i++) {
        for(int k = 0; k < 3; k++) {
            if(dp1[k] == INF) continue;

            if(nums[i] == 0) {
                dp2[0] = min(dp2[0], dp1[k] + 1);
            } else if(nums[i] == 1) {
                if(k != 1) {
                    dp2[1] = min(dp2[1], dp1[k]);
                }
                dp2[0] = min(dp2[0], dp1[k] + 1);

            } else if(nums[i] == 2) {
                if(k != 2) {
                    dp2[2] = min(dp2[2], dp1[k]);
                }
                dp2[0] = min(dp2[0], dp1[k] + 1);

            } else {
                if(k != 1) {
                    dp2[1] = min(dp2[1], dp1[k]);
                }

                if(k != 2) {
                    dp2[2] = min(dp2[2], dp1[k]);
                }
                
                dp2[0] = min(dp2[0], dp1[k] + 1);
            }
        }
        dp1 = dp2;
        dp2 = vector<ll>(3, INF);
    }

    cout << *min_element(all(dp1)) << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
}