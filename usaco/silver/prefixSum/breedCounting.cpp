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
    int n, q;
    cin >> n >> q;

    vector<int> h(n + 1), g(n + 1), j(n + 1);

    for(int i = 1; i <= n; i++){
        int a;
        cin >> a;

        if(a == 1){
            h[i] = h[i - 1] + 1;
            g[i] = g[i - 1];
            j[i] = j[i - 1];
        }
        else if(a == 2){
            h[i] = h[i - 1];
            g[i] = g[i - 1] + 1;
            j[i] = j[i - 1];
        }
        else{
            h[i] = h[i - 1];
            g[i] = g[i - 1];
            j[i] = j[i - 1] + 1;
        }
    }

    for(int i = 0; i < q; i++){
        int a, b;
        cin >> a >> b;

        cout << h[b] - h[a - 1] << " " << g[b] - g[a - 1] << " " << j[b] - j[a - 1] << '\n';
    }
}

int main(){
    freopen("bcount.in", "r", stdin);
	freopen("bcount.out", "w", stdout);
    solve();
} 