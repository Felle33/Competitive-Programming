#include <algorithm>
#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
#include <cstring>

typedef long long ll;
using namespace std;

void solve(){
    ll n, c, ans = 0;
    cin >> n >> c;

    vector<ll> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
        a[i] += i + 1;
    }

    sort(a.begin(), a.end());

    for(ll x : a){
        if(c >= x){
            c -= x;
            ans++;
        }
        else{
            break;
        }
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