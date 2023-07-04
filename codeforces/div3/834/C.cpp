#include <algorithm>
#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

void solve(){
    int l, r, x, a, b;
    cin >> l >> r >> x >> a >> b;

    if(a == b){
        cout << 0 << '\n';
    }
    else if(abs(a - b) >= x){
        cout << 1 << '\n';
    }
    else if((r - max(a, b)) >= x || (min(a, b) - l) >= x){
        cout << 2 << '\n';
    }
    else if(((a - l) >= x && (r - b) >= x) || (r - a) >= x && (b - l) >= x){
        cout << 3 << '\n';
    }
    else{
        cout << -1 << '\n';
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--){
        solve();
    }
}