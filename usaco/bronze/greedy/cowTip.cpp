#include <algorithm>
#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
#include <cstring>
#include <unordered_map>
#include <map>
#include <set>

typedef long long ll;
using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<string> grid(n);

    for(int i = 0; i < n; i++){
        cin >> grid[i];
    }

    int ans = 0;
    vector<int> countFlip(n);

    for(int i = n - 1; i >= 0; i--){
        for(int j = n - 1; j >= 0; j--){
            if(grid[i][j] == '1' && countFlip[j] % 2 == 0){
                ans++;

                for(int k = 0; k <= j; k++) countFlip[k]++;
            }
            else if(grid[i][j] == '0' && countFlip[j] % 2 == 1){
                ans++;

                for(int k = 0; k <= j; k++) countFlip[k]++;
            }
        }
    }

    cout << ans << '\n';
}

int main(){
    freopen("cowtip.in", "r", stdin);
	freopen("cowtip.out", "w", stdout);
    solve();
} 