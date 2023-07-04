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

    int odd = 0, even = 0;

    for(int i = 0; i < n; i++){
        int a;
        cin >> a;

        if(a % 2 == 0){
            even++;
        }
        else{
            odd++;
        }
    }

    while(odd > even){
        odd -= 2;
        even++;
    }

    if(even == odd) cout << even + odd << '\n';
    else cout << 2 * odd + 1 << '\n';
}

int main(){
    /* freopen("cowtip.in", "r", stdin);
	freopen("cowtip.out", "w", stdout); */
    solve();
} 