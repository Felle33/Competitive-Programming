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

	vector<pair<int, int>> specialIndexes;

	for(int i = 0; i < n; i++){
		int a, b;
		cin >> a >> b;

		specialIndexes.push_back({a, 1});
		specialIndexes.push_back({b, -1});
	}

	sort(all(specialIndexes));
	ll ans = 0;
	ll curPeople = 0;
	for(const pair<int, int>& p : specialIndexes){
		curPeople += p.second;
		ans = max(ans, curPeople);
	}
	
	cout << ans << '\n';
}

int main(){
    /* freopen("div7.in", "r", stdin);
	freopen("div7.out", "w", stdout); */
    solve();
} 