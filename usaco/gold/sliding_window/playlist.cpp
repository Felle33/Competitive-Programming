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

    vector<int> nums(n);
    rep(i, n) {
        cin >> nums[i];
    }

    set<int> songs;
    int ans = 0;
    for(int l = 0, r = 0; r < n; r++) {
        if(songs.count(nums[r]) == 0) {
            songs.insert(nums[r]);
            ans = max(ans, r - l + 1);
        } else {
            int song_to_delete = nums[r];
            while(nums[l] != song_to_delete) {
                songs.erase(nums[l++]);
            }
            songs.erase(nums[l++]);
            songs.insert(nums[r]);
            ans = max(ans, r - l + 1);
        }
    }

    cout << ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    solve();
}