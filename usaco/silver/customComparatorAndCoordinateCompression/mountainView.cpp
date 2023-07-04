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

struct mountain{
	int left, right;
};

bool cmp(const mountain& m1, const mountain& m2){
	if(m1.left != m2.left) return m1.left < m2.left;
	return m1.right > m2.right;
}

void solve(){
	int n;
	cin >> n;

	vector<mountain> mountains(n);
	for(int i = 0; i < n; i++){
		int x, y;
		cin >> x >> y;

		mountains[i].left = x - y;
		mountains[i].right = x + y;
	}

	sort(all(mountains), cmp);

	int ans = 1;
	int rightMost = mountains[0].right;

	for(int i = 1; i < n; i++){
		if(rightMost < mountains[i].right){
			rightMost = mountains[i].right;
			ans++;
		}
	}

	cout << ans << '\n';
}

int main(){
    freopen("mountains.in", "r", stdin);
	freopen("mountains.out", "w", stdout);
    solve();
} 