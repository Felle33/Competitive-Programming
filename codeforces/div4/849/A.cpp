#include <algorithm>
#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
#include <cstring>

typedef long long ll;
using namespace std;

void solve(){
    char c;
    string s = "codeforces";
    cin >> c;
    if(s.find(c) != string::npos){
        cout << "YES" << '\n';
    }
    else{
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