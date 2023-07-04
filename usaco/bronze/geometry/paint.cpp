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
    int a, b, c, d;
	cin >> a >> b >> c >> d;

	int total = (b - a) + (d - c);  // the sum of the two intervals
	int intersection = max(min(b, d) - max(a, c), 0);  // subtract the intersection
	int ans = total - intersection;

	cout << ans << "\n";
   

}

int main(){
    freopen("paint.in", "r", stdin);
	freopen("paint.out", "w", stdout);
    solve();
} 