#include <algorithm>
#include <iostream>

#define endl "\n"
using namespace std;

void solve(){
    string pi = "31415926535897932384626433832795028841971";
    string s;
    cin >> s;
    int res = 0;

    for(int i = 0; i < (int)s.size(); i++){
        if(s[i] == pi[i]) res+= 1;
        else break;
    }

    cout << res << endl;

}

int main(){
    int t;
    cin >> t;

    while(t--){
        solve();
    }
}