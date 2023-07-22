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
    int n, k;
    cin >> n >> k;

    vector<int> stacc(n + 1);
    rep(i, n) {
        int col;
        cin >> col;
        col--;
        stacc[i + 1] = col;
    }

    vector<int> last_time(k);
    vector<vector<int>> intervals(k);

    for(int i = 1; i <= n; i++) {
        int col = stacc[i];
        int cells_to_jmp = i - 1 - last_time[col];
        last_time[col] = i;
        intervals[col].push_back(cells_to_jmp);
    }

    for(int col = 0; col < k; col++) {
        intervals[col].push_back(n - last_time[col]);
    }

    int ans = INF;

    for(int col = 0; col < k; col++) {
        auto it = max_element(all(intervals[col]));
        *it = *it / 2;

        int ans_part = 0;
        for(int in : intervals[col]) {
            ans_part = max(ans_part, in);
        }
        ans = min(ans, ans_part);
    }

    cout << ans << '\n';

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