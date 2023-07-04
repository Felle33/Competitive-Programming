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
    int a, b, c;
    cin >> a >> b >> c;

    int n;
    cin >> n;
    vector<pair<int, string>> pc(n);
    for(int i = 0; i < n; i++){
        cin >> pc[i].first >> pc[i].second;
    }

    sort(all(pc));
    ll ans = 0;
    int num = 0;
    for(int i = 0; i < n && !(a == 0 && b == 0 && c == 0); i++){
        if(pc[i].second == "USB"){
            if(a > 0){
                a--;
                num++;
                ans += pc[i].first;
            } else if(c > 0){
                c--;
                num++;
                ans += pc[i].first;
            }
        } else {
            if(b > 0){
                b--;
                num++;
                ans += pc[i].first;
            } else if(c > 0){
                c--;
                num++;
                ans += pc[i].first;
            }
        }
    }

    cout << num << " " << ans << '\n';
}

int main(){
    /* freopen("div7.in", "r", stdin);
	freopen("div7.out", "w", stdout); */
    solve();
} 