#include <algorithm>
#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
#include <cstring>

#define endl '\n'

using namespace std;

void solve(){
    int a1, a2, b1, b2;
    bool yes = false;
    cin >> a1 >> a2 >> b1 >> b2;

    for(int i = 0; i < 4; i++){
        if(a1 < a2 && b1 < b2 && a1 < b1 && a2 < b2){
            yes = true;
            break;
        }

        int tmp = a1;
        a1 = b1;
        b1 = b2;
        b2 = a2;
        a2 = tmp;
    }

    cout << (yes ? "YES" : "NO") << endl;
}

int main(){
    int t;
    cin >> t;

    while(t--){
        solve();
    }
}