#include <algorithm>
#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

void solve(){
    int m, s;
    cin >> m >> s;

    vector<bool> used(55);
    int maximum = 0;

    for(int i = 0; i < m; i++){
        int num;
        cin >> num;
        maximum = max(num, maximum);
        used[num] = true;
    }

    for(int i = 1; i < maximum; i++){
        if(used[i]) continue;
        s -= i;
    }

    for(int i = maximum + 1; s > 0; i++){
        s -= i;
    }

    if(s < 0){
        cout << "NO" << '\n';
    }
    else{
        cout << "YES" << '\n';
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