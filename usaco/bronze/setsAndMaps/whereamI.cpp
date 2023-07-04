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
    int n;
    cin >> n;
    
    string mailBoxes;
    cin >> mailBoxes;


    for(int length = 1; length <= n; length++){
        bool sol = true;
        unordered_map<string, int> mp;
        for(int i = 0; i < n - length + 1; i++){
            string sotBoxes = mailBoxes.substr(i, length);

            mp[sotBoxes]++;
            if(mp[sotBoxes] > 1){
                sol = false;
                break;
            }
        }

        if(sol){
            cout << length << '\n';
            break;
        }
    }
}

int main(){
    freopen("whereami.in", "r", stdin);
	freopen("whereami.out", "w", stdout);
    solve();
} 