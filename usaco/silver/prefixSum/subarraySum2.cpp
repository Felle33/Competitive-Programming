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
    ll n, x;
    cin >> n >> x;

    vector<ll> nums(n);

    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }

    unordered_map<ll, int> mp;

    mp[0] = 1;
    ll ans = 0;
    ll curSum = 0;

    for(ll v : nums){
        curSum += v;
        ll search = curSum - x;
        if(mp.count(search) != 0){
            ans += mp[search];
        }

        mp[curSum]++;
    }

    cout << ans << '\n';
}

int main(){
    /* freopen("div7.in", "r", stdin);
	freopen("div7.out", "w", stdout); */
    solve();
} 