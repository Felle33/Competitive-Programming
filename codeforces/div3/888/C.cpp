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

    vector<int> nums(n);
    rep(i, n) {
        cin >> nums[i];
    }

    if(k == 1) {
        cout << "YES\n";
        return;
    }

    int l = 0, r = n - 1;
    if(nums[l] == nums[r]) {
        int col = nums[l];
        int count = 2;
        l = 1, r = n - 1;
        for(; l < r && count != k; l++) {
            count += nums[l] == col;
        }

        if(count >= k) {
            cout << "YES\n";
            return;
        } else {
            cout << "NO\n";
            return;
        }
    } else {
        int col1 = nums[l], col2 = nums[r];
        int count1 = 1, count2 = 1;
        vector<bool> counted(n);
        l = 1, r = n - 2;
        for(; l < r && (count1 < k || count2 < k);) {
            if(!counted[l]) {
                count1 += nums[l] == col1;
                counted[l] = true;
            }

            if(!counted[r]) {
                count2 += nums[r] == col2;
                counted[r] = true;
            }

            if(count1 < k) l++;
            if(count2 < k) r--;
        }

        if(count1 >= k && count2 >= k) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
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