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
    map<string, int> mp;
    mp["Bessie"] = 0;
    mp["Elsie"] = 0;
    mp["Daisy"] = 0;
    mp["Gertie"] = 0;
    mp["Annabelle"] = 0;
    mp["Maggie"] = 0;
    mp["Henrietta"] = 0;

    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
        string s;
        int x;

        cin >> s >> x;
        int value = mp[s] + x;
        mp[s] = value;
    }

    set<pair<int, string>> s;

    s.insert({mp["Bessie"], "Bessie"});
    s.insert({mp["Elsie"], "Elsie"});
    s.insert({mp["Daisy"], "Daisy"});
    s.insert({mp["Gertie"], "Gertie"});
    s.insert({mp["Annabelle"], "Annabelle"});
    s.insert({mp["Maggie"], "Maggie"});
    s.insert({mp["Henrietta"], "Henrietta"});

    int m = s.begin()->first;
    bool found = false, tie = false;
    int milk;
    string cow;
    for(auto& it : s){
        if(it.first != m && !found){
            milk = it.first;
            found = true;
            cow = it.second;
        } else if(found && milk == it.first){
            tie = true;
        }
    }

    if(tie || !found){
        cout << "Tie" << '\n';
    } else {
        cout << cow << '\n';
    }
}

int main(){
    freopen("notlast.in", "r", stdin);
	freopen("notlast.out", "w", stdout);
    solve();
} 