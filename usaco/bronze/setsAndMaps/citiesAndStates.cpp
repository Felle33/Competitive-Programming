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

void solve(){
    // state -> initial2 of the city -> number of city with the same initial2
    map<string, map<string, int>> mp;
    
    int n;
    cin >> n;

    ll ans = 0;
    for(int i = 0; i < n; i++){
        string city, state;
        cin >> city >> state;

        string semiCity = city.substr(0, 2);

        if(semiCity != state && mp.count(semiCity) != 0 && mp[semiCity].count(state) != 0){
            ans += mp[semiCity][state];
        }

        if(mp[state].count(semiCity) != 0){
            mp[state][semiCity] += 1;
        } else {
            mp[state][semiCity] = 1;
        }
        
    }

    cout << ans << '\n';
}

int main(){
    freopen("citystate.in", "r", stdin);
	freopen("citystate.out", "w", stdout);
    solve();
} 