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

void solve(){
    int n, q;
    cin >> n >> q;

    vector<int> haybales(n);

    for(int i = 0; i < n; i++){
        cin >> haybales[i];
    }

    sort(all(haybales));

    for(int i = 0; i < q; i++){
        int a, b;
        cin >> a >> b;

        int left = lower_bound(
			haybales.begin(), haybales.end(), a
		) - haybales.begin();
		
		int right = upper_bound(
			haybales.begin(), haybales.end(), b
		) - haybales.begin();
		
		cout << right - left << '\n';
    }
}

int main(){
    freopen("haybales.in", "r", stdin);
	freopen("haybales.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
} 