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

const int DIM = 1e5 + 1;
const ll mod = 1e9 + 7;
const ll inf = 1e12;

ll exponentiation(ll b, ll e){
    ll res = 1;
    b %= mod;
    while(e > 0){
        if(e & 1)
            res = res * b % mod;
        
        b = b * b % mod;
        e >>= 1;
    }

    return res;
}

void solve(){
    ll n;
    cin >> n;

    while(n--){
        ll b, e;
        cin >> b >> e;
        cout << exponentiation(b, e) << '\n';
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    /* freopen("lifeguards.in", "r", stdin);
	freopen("lifeguards.out", "w", stdout); */
    solve();
} 