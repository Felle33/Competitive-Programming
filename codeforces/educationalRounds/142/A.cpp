#include <algorithm>
#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
#include <cstring>

typedef long long ll;
using namespace std;

void solve(){
    int n;
    cin >> n;

    int numberOfOne = 0;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        if(a == 1){
            numberOfOne++;
        }
    }

    int res = numberOfOne / 2 + (n - numberOfOne) + numberOfOne % 2;
    cout << res << '\n';
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