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
    string s;
    cin >> s;

    vector<int> nums(n);
    for(int i = 0; i < n; i++){
        nums[i] = s[i] - '0';
    }

    vector<int> pref(n + 1);
    for(int i = 1; i <= n; i++){
        pref[i] = pref[i - 1] + nums[i - 1];
    }

    unordered_map<ll, int> mp;
    mp[0] = 1;
    ll ans = 0;
    for(int i = 1; i <= n; i++){
        if(mp.count(pref[i] - i) != 0){
            ans += mp[pref[i] - i];
        }

        mp[pref[i] - i]++;
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