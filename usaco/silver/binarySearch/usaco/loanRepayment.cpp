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

typedef long long ll;
using namespace std;

ll n, k, m;

bool good(ll x){
    ll g = 0;
    ll days = k;

    while(g < n && days > 0){
        ll y = (n - g) / x;

        if(y < m){
            ll left = ((n - g) + (m - 1)) / m;
            return left <= days;
        }

        ll dayCostantY = (n - y * x - g) / y + 1;
        days -= dayCostantY;
        g += dayCostantY * y;
    }
    
    return g >= n;
}

void solve(){
    cin >> n >> k >> m;

    ll l = 1, r = 1;

    while(good(r)) r *= 2;

    while(l + 1 < r){
        ll mid = l + (r - l) / 2;

        if(good(mid)){
            l = mid;
        }
        else{
            r = mid;
        }
    }

    cout << l << '\n';
}

int main(){
    freopen("loan.in", "r", stdin);
	freopen("loan.out", "w", stdout);
    solve();
} 