#include <algorithm>
#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
#include <cstring>

typedef long long ll;
using namespace std;

void solve(){
    string dir;
    bool found = false;
    int n;
    cin >> n;
    cin >> dir;
    int x = 0, y = 0;

    for(char c : dir){
        if(c == 'U'){
            y += 1;
        }
        else if(c == 'D'){
            y -= 1;
        }
        else if(c == 'R'){
            x += 1;
        }
        else{
            x -= 1;
        }

        if(x == 1 && y == 1){
            cout << "YES" << '\n';
            found = true;
            break;
        }
    }

    if(!found){
        cout << "NO" << '\n';
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