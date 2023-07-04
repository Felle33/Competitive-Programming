#include <algorithm>
#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
#include <cstring>
#include <unordered_map>
#include <map>
#include <set>
#include <iomanip>

#define all(x) (x).begin(), (x).end()

typedef long long ll;
using namespace std;

const ll MOD = 1e9 + 7;
const ll DIM = 1e6;
const ll INF = 1e9;
vector<int> DX = {0, 1, -1, 0};
vector<int> DY = {1, 0, 0, -1};
string DIR = "RDUL";

ll exponentiation(ll b, ll e){
    ll res = 1;
    b %= MOD;
    while(e > 0){
        if(e & 1)
            res = res * b % MOD;
        
        b = b * b % MOD;
        e >>= 1;
    }

    return res;
}

void solve(){
	string s;
    cin >> s;

	int n = s.size();
	vector<int> counts(26);
	for (int i = 0; i < n; i++){
        if(n % 2 == 1 && i == n / 2) continue;
		counts[s[i] - 'a']++;
	}

	int c = 0;
	for(int i = 0; i < 26; i++){
		if(counts[i] != 0 && counts[i] % 2 == 0){
			c++;
		}
	}

	if(c >= 2){
		cout << "YES\n";
	} else{
		cout << "NO\n";
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