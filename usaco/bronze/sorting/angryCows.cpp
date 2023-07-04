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

int getExplosions(int start, int dir, vector<int>& bales){
    int radius = 1;
    int prev = start;

    while(true){
        int next = prev;
        while(next + dir >= 0 && next + dir < (int) bales.size() && abs(bales[prev] - bales[next + dir]) <= radius){
            next += dir;
        }

        if(next == prev) break;
        prev = next;
        radius++;
    }

    return abs(prev - start);
}


void solve(){
    int n;
    cin >> n;

    vector<int> bales(n);

    for(int i = 0; i < n; i++){
        cin >> bales[i];
    }

    sort(all(bales));

    int ans = 0;

    for(int i = 0; i < n; i++){
        ans = max(ans, getExplosions(i, 1, bales) + getExplosions(i, -1, bales) + 1);
    }

    cout << ans << '\n';
}

int main(){
    freopen("angry.in", "r", stdin);
	freopen("angry.out", "w", stdout);
    solve();
} 