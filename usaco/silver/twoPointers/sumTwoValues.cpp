#include <algorithm>
#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
#include <cstring>
#include <unordered_map>
#include <map>
#include <set>

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
    bool found = false;
    int l = 0, r = n - 1;
    for(; l < r;){
        if(nums[l].first + nums[r].first == x){
            found = true;
            break;
        }
        else if(nums[l].first + nums[r].first > x){
            r--;
        }
        else{
            l++;
        }
    }

    if(found){
        int p1 = nums[l].second, p2 = nums[r].second;
        cout << p1 << " " << p2 << '\n';
    }
    else{
        cout << "IMPOSSIBLE" << '\n';
    }
}

int main(){
    /* freopen("bcount.in", "r", stdin);
	freopen("bcount.out", "w", stdout); */
    solve();
} 