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
    vector<int> res(26);
    int n;

    cin >> n;
    vector<int> p1(26), p2(26);
    for(int j = 0; j < n; j++){
        fill(p1.begin(), p1.end(), 0);
        fill(p2.begin(), p2.end(), 0);
        string s1, s2;
        cin >> s1 >> s2;

        for(int i = 0; i < (int)s1.size(); i++){
            p1[s1[i] - 'a']++;
        }

        for(int i = 0; i < (int)s2.size(); i++){
            p2[s2[i] - 'a']++;
        }

        for(int i = 0; i < 26; i++){
            res[i] += max(p1[i], p2[i]);
        }
    }

    for(int i = 0; i < 26; i++){
        cout << res[i] << '\n';
    }
}

int main(){
    freopen("blocks.in", "r", stdin);
	freopen("blocks.out", "w", stdout);
    solve();
} 