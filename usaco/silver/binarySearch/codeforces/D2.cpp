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

ll m, n;
vector<ll> minutes;
vector<ll> balloons;
vector<ll> rest;

bool good(ll t){
    ll ans = 0;

    for(int i = 0; i < n; i++){
        ll period = minutes[i] * balloons[i] + rest[i];
        ll nballPeriod = t / period;
        ll ballPeriod = nballPeriod * balloons[i];
        
        ll tr = t % period;

        if(tr != 0) {
            if(minutes[i] * balloons[i] <= tr) {
                ballPeriod += balloons[i];
            } else {
                ballPeriod += (tr / minutes[i]);
            }
        }

        ans += ballPeriod;
    }

    return ans >= m;
}

void solve(){
    cin >> m >> n;
    
    minutes.resize(n);
    balloons.resize(n);
    rest.resize(n);

    for(int i = 0; i < n; i++){
        cin >> minutes[i] >> balloons[i] >> rest[i];
    }

    ll l = -1, r = 1;

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

    ll time = r;
    cout << time << '\n';

    ll contPallTotale = 0;
    vector<ll> inflate(n);
    for(int i = 0; i < n; i++){
        ll period = minutes[i] * balloons[i] + rest[i];
        ll nballPeriod = time / period;
        ll ballPeriod = nballPeriod * balloons[i];
        ll tr = time % period;

        if(tr != 0) {
            if(minutes[i] * balloons[i] <= tr) {
                ballPeriod += balloons[i];
            } else {
                ballPeriod += (tr / minutes[i]);
            }
        }

        if(contPallTotale + ballPeriod <= m) inflate[i] = ballPeriod;
        else if(contPallTotale <= m) inflate[i] = m - contPallTotale;
        else inflate[i] = 0;
        
        contPallTotale += ballPeriod;
    }

    for(ll x : inflate) {
        cout << x << ' ';
    }

    cout << '\n';
}

int main(){
    /* freopen("lifeguards.in", "r", stdin);
	freopen("lifeguards.out", "w", stdout); */
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
} 