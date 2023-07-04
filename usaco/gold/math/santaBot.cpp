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
const ll inf = 1e12;
const ll mod = 998244353;

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

    vector<vector<ll>> objectsOfChild(n);
    map<ll, ll> numberOfObjects;
    for(int i = 0; i < n; i++){
        int k;
        cin >> k;

        objectsOfChild[i].resize(k);
        for(int j = 0; j < k; j++){
            int a;
            cin >> a;

            objectsOfChild[i][j] = a;
            numberOfObjects[a]++;
        }
    }

    ll prob = 0;
    for(vector<ll>& child : objectsOfChild){
        for(ll item : child){
            ll num = numberOfObjects[item];
            ll den = (n * n % mod) * (ll) child.size();
            prob += ((num % mod) * exponentiation(den, mod - 2)) % mod;
        }
        prob %= mod;
    }

    cout << prob;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    /* freopen("lifeguards.in", "r", stdin);
	freopen("lifeguards.out", "w", stdout); */
    solve();
} 