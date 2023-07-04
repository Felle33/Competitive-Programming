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

    vector<int> stick(n);
    for(int i = 0; i < n; i++){
        cin >> stick[i];
    }

    sort(all(stick));
    if(n % 2 == 1){
        int m = stick[n / 2];

        int ans = 0;
        for(int i = 0; i < n; i++){
            ans += abs(stick[i] - m);
        }

        cout << ans << '\n';
    } else {
        int m1 = stick[n / 2 - 1];
        int m2 = stick[n / 2];

        ll ans1 = 0, ans2 = 0;
        for(int i = 0; i < n; i++){
            ans1 += abs(stick[i] - m1);
            ans2 += abs(stick[i] - m2);
        }

        cout << min(ans1, ans2) << '\n';
    }
}

int main(){
    /* freopen("div7.in", "r", stdin);
	freopen("div7.out", "w", stdout); */
    solve();
} 