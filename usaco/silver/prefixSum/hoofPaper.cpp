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

    vector<int> h(n + 1), p(n + 1), s(n + 1);
    for(int i = 1; i <= n; i++){
        h[i] = h[i - 1];
        p[i] = p[i - 1];
        s[i] = s[i - 1];

        char c;
        cin >> c;

        if(c == 'P'){
            s[i] += 1;
        }
        else if(c == 'H'){
            p[i] += 1;
        }
        else{
            h[i] += 1;
        }
    }

    int ans = 0;

    for(int i = 1; i <= n; i++){
        int winsBefore = max({h[i], p[i], s[i]});
        int winsAfter = max({h[n] - h[i],
        p[n] - p[i], s[n] - s[i]});

        ans = max(ans, winsBefore + winsAfter);
    }

    cout << ans << '\n';
}

int main(){
    freopen("hps.in", "r", stdin);
	freopen("hps.out", "w", stdout);
    solve();
} 