#include <algorithm>
#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
#include <cstring>

typedef long long ll;
using namespace std;

void solve(){
    int a, b;
    cin >> a >> b;
    string res = "";
    bool first = true;

    while(a + b > 0){
        if((first && a > 0) || b == 0){
            a--;
            res += "0";
        }
        else{
            b--;
            res += "1";
        }

        first = !first;
    }

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