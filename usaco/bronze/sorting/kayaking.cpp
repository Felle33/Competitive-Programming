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
    int n;
    cin >> n;
    n = 2 * n;
    vector<int> weights(n);

    for(int i = 0; i < n; i++){
        cin >> weights[i];
    }

    sort(all(weights));
    int ans = INT_MAX;
    
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            vector<int> newWeights;

            for(int k = 0; k < n; k++){
                if(k != i && k != j){
                    newWeights.push_back(weights[k]);
                }
            }

            int instability = 0;
            for(int k = 0; k < n - 2; k += 2){
                instability += abs(newWeights[k] - newWeights[k + 1]);
            }

            ans = min(ans, instability);
        }
    }

    cout << ans << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;

    while(t--){
        solve();
    }
}