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

    vector<int> vals(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> vals[i];
    }

    vector<int> mods(7, -1);
    mods[0] = 0;
    int ans = 0;
    int curSum = 0;
    for(int i = 1; i <= n; i++){
        curSum += vals[i];
        curSum %= 7;

        if(mods[curSum] == -1){
            mods[curSum] = i;
        }
        else{
            ans = max(ans, i - mods[curSum]);
        }
    }

    cout << ans << '\n';

}

int main(){
    freopen("div7.in", "r", stdin);
	freopen("div7.out", "w", stdout);
    solve();
} 