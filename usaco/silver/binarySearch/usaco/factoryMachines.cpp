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

vector<ll> machines;
int n, k;

bool good(ll t){
    ll products = 0;

    for(int i = 0; i < n; i++){
        products += t / machines[i];
    }

    return products >= k;
}

void solve(){
    cin >> n >> k;

    machines.resize(n);

    for(int i = 0; i < n; i++){
        cin >> machines[i];
    }

    sort(all(machines));
    ll l = 0, r = 1;

    while(!good(r)) r *= 2;

    while(l + 1 < r){
        ll mid = l + (r - l) / 2;

        if(good(mid)){
            r = mid;
        }
        else{
            l = mid;
        }
    }

    cout << r << '\n';
}

int main(){
    /* freopen("angry.in", "r", stdin);
	freopen("angry.out", "w", stdout); */
    solve();
} 