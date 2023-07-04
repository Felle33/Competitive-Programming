#include <algorithm>
#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
#include <cstring>
#include <unordered_map>

typedef long long ll;
using namespace std;

void solve(){
    int n;
    cin >> n;

    vector<pair<int, int>> times(n);
    for(int i = 0; i < n; i++){
        cin >> times[i].first >> times[i].second;
    }

    ll ans = 0;
    for(int i = 0; i < n; i++){
        ll cur = 0;
        vector<bool> covered(1001);
        for(int j = 0; j < n; j++){
            if(j == i) continue;

            int start = times[j].first;

            while(start < times[j].second){
                if(!covered[start]){
                    covered[start] = true;
                    cur++;
                }
                start++;
            }
        }

        ans = max(ans, cur);
    }


    cout << ans << '\n';
}

int main(){
    freopen("lifeguards.in", "r", stdin);
	freopen("lifeguards.out", "w", stdout);
    solve();
} 