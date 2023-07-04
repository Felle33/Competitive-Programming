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
    int n, m;
    cin >> n >> m;

    int totalCows = 2 * n;
    vector<string> cows(totalCows);
    for(int i = 0; i < totalCows; i++){
        cin >> cows[i];
    }

    map<int, set<char>> locGen;
    for(int l = 0; l < m; l++){
        for(int i = n; i < totalCows; i++){
            locGen[l].insert(cows[i][l]);
        }
    }
    
    int ans = 0;
    for(int i = 0; i < m; i++){
        bool possible = true;
        for(int j = 0; j < n; j++){
            if(locGen[i].count(cows[j][i]) != 0){
                possible = false;
                break;
            }
        }

        if(possible) ans++;
    }

    cout << ans << '\n';
}

int main(){
    freopen("cownomics.in", "r", stdin);
	freopen("cownomics.out", "w", stdout);
    solve();
} 