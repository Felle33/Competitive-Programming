#include <algorithm>
#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
#include <cstring>

typedef long long ll;
using namespace std;

void solve(){
    int a1, a2, a3, a4;
    cin >> a1 >> a2 >> a3 >> a4;

    if(a1 == 0){
        cout << 1 << '\n';
    }
    else{
        int res = a1;
        int mod1 = a1, mod2 = a1;
        int midSpet = min(a2, a3);
        res += midSpet * 2;

        a2 -= midSpet;
        a3 -= midSpet;

        if(a2 == 0 && a3 == 0){
            if(mod1 < a4){
                cout << res + mod1 + 1 << '\n';
            }
            else{
                cout << res + a4 << '\n';
            }
        }
        else if(a2 != 0){
            if(mod2 < a2){
                cout << res + mod2 + 1 << '\n';
            }
            else{
                res += a2;
                mod2 -= a2;

                if(mod2 < a4){
                    cout << res + mod2 + 1 << '\n';
                }
                else{
                    cout << res + a4 << '\n';
                }
            }
        }
        else{
            if(mod1 < a3){
                cout << res + mod1 + 1 << '\n';
            }
            else{
                res += a3;
                mod1 -= a3;

                if(mod1 < a4){
                    cout << res + mod1 + 1 << '\n';
                }
                else{
                    cout << res + a4 << '\n';
                }
            }
        }
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