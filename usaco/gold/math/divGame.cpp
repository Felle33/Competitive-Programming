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

ll result(ll x){
    ll res = 0;

    for(ll i = 2; i * i <= x; i++){
        ll exp = 0;
        while(x % i == 0){
            exp++;
            x /= i;
        }

        for(int j = 1; exp - j >= 0; j++){
            exp -= j;
            res++;
        }
    }

    if(x > 1) res++;
    return res;
}

void solve(){
    ll n;
    cin >> n;

    cout << result(n);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    /* freopen("lifeguards.in", "r", stdin);
	freopen("lifeguards.out", "w", stdout); */
    solve();
} 