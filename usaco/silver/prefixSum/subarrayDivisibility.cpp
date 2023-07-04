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
    int n;
    cin >> n;

    vector<ll> nums(n);
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }

    unordered_map<ll, ll> mp;
    mp[0] = 1;
    ll curSum = 0;
    ll ans = 0;

    for(ll x : nums){
        curSum += x;
        curSum = (curSum % n + n) % n;

        if(mp.count(curSum) != 0){
            ans += mp[curSum];
        }

        mp[curSum]++;
    }
    
    cout << ans << '\n';
}

int main(){
    /* freopen("hps.in", "r", stdin);
	freopen("hps.out", "w", stdout); */
    solve();
} 