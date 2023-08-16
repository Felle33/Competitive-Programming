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
const ll INF = 1e9;
vector<int> DX = {0, 1, -1, 0};
vector<int> DY = {1, 0, 0, -1};
string DIR = "RDUL";

bool allEquals(vector<int>& nums) {
    int p = nums[0];
    for(int x : nums) {
        if(x != p) return false;
    }
    return true;
}

void solve(){
    int n;
    cin >> n;
    vector<int> nums(n);
    rep(i, n) {
        cin >> nums[i];
    }
    sort(all(nums));

    if(allEquals(nums)) {
        cout << -1 << '\n';
    } else {
        vector<int> b, c;
        int m = nums[nums.size() - 1];

        for(int x : nums) {
            if(x == m) {
                c.push_back(x);
            } else {
                b.push_back(x);
            }
        }

        cout << b.size() << " " << c.size() << '\n';

        for(int x : b) {
            cout << x << " ";
        }
        cout << '\n';

        for(int x : c) {
            cout << x << " ";
        }
        cout << '\n';
    }

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