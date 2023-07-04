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
    string s;
    cin >> s;
    int n = s.size();
    int res = 0;
    vector<bool> used(26);
    vector<int> cross(26);

    for(int i = 0; i < n; i++){
        char c = s[i];
        if(used[c - 'A']) continue;
        used[c - 'A'] = true;
        fill(cross.begin(), cross.end(), 0);

        for(int j = i + 1; j < n; j++){
            if(s[j] == c){
                for(int k = 0; k < 26; k++){
                    if(cross[k] == 1){
                        res++;
                    }
                }
                break;
            }

            if(used[s[j] - 'A']) continue;

            cross[s[j] - 'A']++;
        }
    }

    cout << res << '\n';
}

int main(){
    freopen("circlecross.in", "r", stdin);
	freopen("circlecross.out", "w", stdout);
    solve();
} 