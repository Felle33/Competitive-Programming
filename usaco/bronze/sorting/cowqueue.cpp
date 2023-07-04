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

    vector<pair<ll, ll>> cows(n);
    for(int i = 0; i < n; i++){
        cin >> cows[i].first >> cows[i].second;
    }

    sort(all(cows));

    ll ans = cows[0].first + cows[0].second;

    for(int i = 1; i < n; i++){
        if(ans < cows[i].first){
            ans = cows[i].first;
            ans += cows[i].second;
        }
        else{
            ans += cows[i].second;
        }
    }

    cout << ans << '\n';
}

int main(){
    freopen("cowqueue.in", "r", stdin);
	freopen("cowqueue.out", "w", stdout);
    solve();
} 