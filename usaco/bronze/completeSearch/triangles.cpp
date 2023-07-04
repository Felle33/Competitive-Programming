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

    vector<pair<int, int>> coord(n);
    ll ans = 0;

    for(int i = 0; i < n; i++){
        cin >> coord[i].first >> coord[i].second;
    }

    for(int i = 0; i < n; i++){
        int x = coord[i].first;
        int y = coord[i].second;

        int yMax = 0;

        for(int j = 0; j < n; j++){
            if(coord[j].first == x){
                yMax = max(yMax, abs(y - coord[j].second));
            }
        }

        int xMax = 0;

        for(int j = 0; j < n; j++){
            if(coord[j].second == y){
                xMax = max(xMax, abs(x - coord[j].first));
            }
        }

        ans = max(ans,(ll) (yMax * xMax));
    }

    cout << ans << '\n';
}

int main(){
    freopen("triangles.in", "r", stdin);
	freopen("triangles.out", "w", stdout);
    solve();
} 