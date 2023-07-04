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

vector<ll> haybales;
int n, k;

bool good(ll r){
    int lhaybale = 0;
    int ncows = 1;

    for(int i = 1; i < n; i++){
        if(abs(haybales[lhaybale] - haybales[i]) > 2 * r){
            lhaybale = i;
            ncows++;
        }
    }

    return ncows <= k;
}

void solve(){
    cin >> n >> k;

    haybales.resize(n);

    for(int i = 0; i < n; i++){
        cin >> haybales[i];
    }

    sort(all(haybales));
    ll l = 1, r = haybales[n - 1];

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
    freopen("angry.in", "r", stdin);
	freopen("angry.out", "w", stdout);
    solve();
} 