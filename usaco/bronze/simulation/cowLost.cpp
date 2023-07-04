#include <algorithm>
#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
#include <cstring>

typedef long long ll;
using namespace std;

void solve(){
    int x, y, increment = 1, res = 0, pos;
    cin >> x >> y;

    bool right = true;
    bool found = false;
    pos = x;
    
    while(!found){
        if(right){
            while(pos != x + increment){
                pos++;
                res++;
                if(pos == y){
                    found = true;
                    break;
                }
            }
        }
        else{
            while(pos != x - increment){
                pos--;
                res++;
                if(pos == y){
                    found = true;
                    break;
                }
            }
        }

        increment *= 2;
        right = !right;
    }

    cout << res << '\n';
}

int main(){
    freopen("lostcow.in", "r", stdin);
	freopen("lostcow.out", "w", stdout);
    solve();
} 