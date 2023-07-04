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

    vector<int> nums(n);
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }

    int l = 0, r = 0;
    ll ans = 0, curSum = 0;
    for(; r < n; r++){
        curSum += nums[r];

        while(curSum > x){
            curSum -= nums[l];
            l++;
        }

        if(curSum == x){
            ans++;
        }
    }

    cout << ans << '\n';
}

int main(){
    /* freopen("bcount.in", "r", stdin);
	freopen("bcount.out", "w", stdout); */
    solve();
} 