#include <algorithm>
#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
#include <cstring>
#include <unordered_map>
#include <map>
#include <set>
#include <stack>

#define all(x) (x).begin(), (x).end()

typedef long long ll;
using namespace std;

void solve(){
    int n, x;
    cin >> n >> x;

    vector<pair<int, int>> nums(n);
    for(int i = 0; i < n; i++){
        cin >> nums[i].first;
        nums[i].second = i + 1;
    }

    sort(all(nums));
    for(int i = 0; i < n; i++){
        int l = 0, r = n - 1;

        while(l < r){
            if(i != l && i != r && (nums[i].first + nums[l].first + nums[r].first) == x){
                cout << nums[i].second << " " << nums[l].second << " " << nums[r].second;
                return;
            }

            if(nums[i].first + nums[l].first + nums[r].first > x){
                r--;
            }
            else{
                l++;
            }
        }
    }

    cout << "IMPOSSIBLE";
}

int main(){
    /* freopen("bcount.in", "r", stdin);
	freopen("bcount.out", "w", stdout); */
    solve();
} 