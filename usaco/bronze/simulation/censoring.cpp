#include <algorithm>
#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
#include <cstring>
#include <unordered_map>

typedef long long ll;
using namespace std;

void solve(){
    string s, t, newWord;
    cin >> s >> t;

    for(int i = 0; i < (int) s.size(); i++){
        newWord += s[i];

        if(newWord.size() >= t.size() && newWord.substr(newWord.size() - t.size()) == t){
            newWord.resize(newWord.size() - t.size());
        }
    }

    cout << newWord << '\n';
}

int main(){
    freopen("censor.in", "r", stdin);
	freopen("censor.out", "w", stdout);
    solve();
} 