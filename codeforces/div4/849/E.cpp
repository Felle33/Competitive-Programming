#include <algorithm>
#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
#include <cstring>
#include <numeric>

typedef long long ll;
using namespace std;

void solve(){
    ll res = 0;
    int n;
    cin >> n;
    vector<ll> a(n);
    bool even = true;

    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(a[i] < 0) even = !even;
    }

    vector<ll> absolute(n);
    for(int i = 0; i < n; i++){
        absolute[i] = abs(a[i]);
    }

    ll min_el = 0;
    
    if(!even){
        min_el = *min_element(absolute.begin(), absolute.end());
    }
    
    for(ll x : absolute){
        res += x;
    }
    res -= 2 * min_el;

    cout << res << '\n';
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