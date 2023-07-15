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
#include <stack>

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
    int n;
    cin >> n;

    vector<int> nums(n);
    rep(i, n){
        cin >> nums[i];
    }

    stack<pair<int, int>> s;
    vector<int> ans(n);
    for(int i = n - 1; i >= 0; i--){
        if(s.empty() || s.top().first < nums[i]){
            s.push({nums[i], i});
        } else if(nums[i] < s.top().first){
            while(!s.empty() && nums[i] < s.top().first){
                ans[s.top().second] = i + 1;
                s.pop();
            }
            s.push({nums[i], i});
        }
    }

    rep(i, n){
        cout << ans[i] << " ";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
}