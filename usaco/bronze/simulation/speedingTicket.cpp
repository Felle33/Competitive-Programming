#include <algorithm>
#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
#include <cstring>

typedef long long ll;
using namespace std;

void solve(){
    int n, m;
    cin >> n >> m;

    vector<int> speed(100);

    int pos = 0;
    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;

        for(int j = pos; j < pos + a; j++){
            speed[j] = b;
        }

        pos += a;
    }

    vector<int> bessie(100);

    pos = 0;
    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;

        for(int j = pos; j < pos + a; j++){
            bessie[j] = b;
        }

        pos += a;
    }

    int maxInfraction = 0;

    for(int i = 0; i < 100; i++){
        maxInfraction = max(bessie[i] - speed[i], maxInfraction);
    }

    cout << maxInfraction << '\n';
}

int main(){
    freopen("speeding.in", "r", stdin);
	freopen("speeding.out", "w", stdout);

    /* int t;
    cin >> t;

    while(t--){
    }*/
    solve();
} 