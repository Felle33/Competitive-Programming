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
    string s;
    cin >> n >> s;

    int i;
    for(i = 0; i < n / 2;){
        if((s[i] == '0' && s[n - 1 - i] == '1') || (s[i] == '1' && s[n - 1 - i] == '0')){
            i++;
        }
        else{
            break;
        }
    }

    cout << n - 2 * i << '\n';
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