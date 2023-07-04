#include <algorithm>
#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
#include <cstring>
#include <unordered_map>
#include <map>
#include <set>
#include <iomanip>

#define all(x) (x).begin(), (x).end()

typedef long long ll;
using namespace std;

int n, x, y;

bool good(int t){
    return t / x + t / y >= n;
}

void solve(){
    cin >> n >> x >> y;
    int ans = min(x, y);
    n--;

    int l = -1, r = 1;
    while(!good(r)) r *= 2;

    while(l + 1 < r){
        int mid = l + (r - l) / 2;

        if(good(mid)){
            r = mid;
        }
        else{
            l = mid;
        }
    }

    cout << ans + r << '\n';
    
}

int main(){
    /* freopen("lifeguards.in", "r", stdin);
	freopen("lifeguards.out", "w", stdout); */
    solve();
} 