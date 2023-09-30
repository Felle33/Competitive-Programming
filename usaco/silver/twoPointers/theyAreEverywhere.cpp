#include <algorithm>
#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
#include <cstring>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include <stack>

#define all(x) (x).begin(), (x).end()

typedef long long ll;
using namespace std;

// for every letters how many times it appears in the sliding window
map<char, int> mp;
// how different pokemons there are in the sl win
int currCounter = 0;

void insert(char c) {
    if(mp[c] == 0) {
        currCounter++;
    }
    mp[c]++;
}

void erase(char c) {
    if(mp[c] == 1) {
        currCounter--;
    }
    mp[c]--;
}

void solve(){
    int n;
    cin >> n;
    string pokemon;
    cin >> pokemon;

    unordered_set<char> types;
    for(char c : pokemon){
        types.insert(c);
    }

    int totalTypes = types.size();
    int ans = 1e9;
    
    for(int l = 0, r = 0; r < n; ){
        while(r < n && currCounter < totalTypes) {
            insert(pokemon[r]);
            r++;
        }

        while(mp[pokemon[l]] > 1) {
            erase(pokemon[l]);
            l++;
        }

        if(currCounter == totalTypes) {
            ans = min(ans, r - l);
        }
        
        erase(pokemon[l++]);
    }

    cout << ans << '\n';
}

int main(){
    /* freopen("bcount.in", "r", stdin);
	freopen("bcount.out", "w", stdout); */
    solve();
} 