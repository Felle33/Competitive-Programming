#include <algorithm>
#include <iostream>
#include <cmath>

using namespace std;

void solve(){
    int n, s, r;
    cin >> n >> s >> r;

    cout << s - r << " ";

    for(int i = n - 1; i >= 1; i--){
        int res = ceil((double) r / i);
        cout << res << " ";
        r -= res;
    }
    cout << endl;
}

int main(){
    int t;
    cin >> t;

    while(t--){
        solve();
    }
}