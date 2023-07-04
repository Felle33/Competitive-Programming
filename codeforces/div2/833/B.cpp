#include <algorithm>
#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
#include <cstring>
#include <unordered_map>
#include <map>
#include <set>

#define all(x) (x).begin(), (x).end()

typedef long long ll;
using namespace std;

void solve(){
    int length;
    string s;

    cin >> length >> s;

    unordered_map<char, int> mp;
    ll ans = length * (length + 1) / 2;
    int letters = 0;

    for(int l = 0, r = 0; r < length; r++){
        mp[s[r]]++;
        letters++;

        while(mp.size() < letters){
            ans--;
            mp[s[l]]--;
            letters--;

            if(mp.count(s[l]) == 0){
                mp.erase(s[l]);
            }

            l++;
        }
    }

    cout << ans << '\n';
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