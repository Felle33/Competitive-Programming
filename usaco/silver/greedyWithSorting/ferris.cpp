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
    int n, w;
    cin >> n >> w;

    vector<int> weights(n);
    
    for(int i = 0; i < n; i++){
        cin >> weights[i];
    }

    sort(all(weights));
    int ans = 0;
    for(int i = 0, j = n - 1; i <= j; ){
        if(i == j){
            ans++;
            i++;
        } else if((weights[i] + weights[j]) <= w){
            i++, j--, ans++;
        } else {
            ans++;
            j--;
        }
    }

    cout << ans << '\n';
    
}

int main(){
    /* freopen("div7.in", "r", stdin);
	freopen("div7.out", "w", stdout); */
    solve();
} 