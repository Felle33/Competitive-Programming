#include <algorithm>
#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
#include <cstring>
#include <unordered_map>
#include <map>
#include <set>

typedef long long ll;
using namespace std;

void solve(){
    int n;
    cin >> n;

    string a, b;
    cin >> a >> b;
    int ans = 0;

    for(int i = 0; i < n; i++){
        if(a[i] == b[i]) continue;
        ans++;
        while(i < n && a[i] != b[i]){
            i++;
        }
    }

    cout << ans << '\n';
}

int main(){
    freopen("breedflip.in", "r", stdin);
	freopen("breedflip.out", "w", stdout);
    solve();
} 