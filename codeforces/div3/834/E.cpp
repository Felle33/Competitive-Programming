#include <algorithm>
#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
#include <cstring>

#define MAXN 200005

typedef long long ll;
using namespace std;

ll eatAstronauts(vector<ll>& astronautsLife, ll alienHealth, int index, int green, int blue){
    if(index == astronautsLife.size()) return 0;
    if(alienHealth < astronautsLife[index] && green == 0 && blue == 0) return 0;
    ll res = 0;

    if(alienHealth > astronautsLife[index]){
        res = 1 + eatAstronauts(astronautsLife, alienHealth + astronautsLife[index] / 2, index + 1, green, blue);
    }
    else{
        if(green > 0){
            res = max(res, eatAstronauts(astronautsLife, alienHealth * 2, index, green - 1, blue));
        }

        if(blue > 0){
            res = max(res, eatAstronauts(astronautsLife, alienHealth * 3, index, green, blue - 1));
        }
    }
    
    return res;
}

void solve(){
    ll n, h;
    cin >> n >> h;

    vector<ll> astronautsLife(n);

    for(int i = 0; i < n; i++){
        cin >> astronautsLife[i];
    }

    sort(astronautsLife.begin(), astronautsLife.end());
    
    cout << eatAstronauts(astronautsLife, h, 0, 2, 1) << '\n';
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