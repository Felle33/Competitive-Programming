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

    multiset<int> setTowers;
    int ans = 0;
    for(int i = 0; i < n; i++){
        int t;
        cin >> t;

        auto it = setTowers.upper_bound(t);
        if(it == setTowers.end()){
            ans++;
            if(t != 1){
                setTowers.insert(t);
            }
        } else {
            setTowers.erase(it);
            if(t != 1){
                setTowers.insert(t);
            }
        }
    }

    cout << ans << '\n';
}

int main(){
    /* freopen("div7.in", "r", stdin);
	freopen("div7.out", "w", stdout); */
    solve();
} 