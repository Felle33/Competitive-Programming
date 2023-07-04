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

int m, n;
vector<int> minutes;
vector<int> balloons;
vector<int> rest;

bool good(int t){
    ll ans = 0;

    for(int i = 0; i < n; i++){
        int period = minutes[i] * balloons[i] + rest[i];
        ans += (t / period) * balloons[i] + min(balloons[i], (t % period) / minutes[i]);
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

    int time = r;
    cout << time << '\n';

    for(int i = 0; i < n; i++){
        int period = minutes[i] * balloons[i] + rest[i];
        int nPer = time / period;
        int tr = time % period;

        int count = nPer * balloons[i];
        count = min(m, count + min(balloons[i], tr / minutes[i]));
        m -= count;
        cout << count << " ";
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