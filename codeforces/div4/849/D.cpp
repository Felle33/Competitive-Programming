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

    vector<int> h1(26), h2(26);
    int res = 1;

    for(int i = 0; i < n; i++){
        h2[s[i] - 'a']++;
    }

    for(int i = 0; i < n - 1; i++){
        int c = 0;
        h1[s[i] - 'a']++;
        h2[s[i] - 'a']--;

        for(int i = 0; i < 26; i++){
            if(h1[i] != 0){
                c++;
            }

            if(h2[i] != 0){
                c++;
            }
        }

        res = max(res, c);
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