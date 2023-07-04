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

struct Edge {
	int a, b, w;
};

/* alternatively,
class Edge {
	public:
		int a,b,w;
};
*/

bool cmp(const Edge& x, const Edge &y){
    return x.w > y.w;
}

void solve(){
    int M = 4;
	vector<Edge> v;
	for (int i = 0; i < M; ++i) {
		int a, b, w;
		cin >> a >> b >> w;
		v.push_back({a, b, w});
	}
    sort(all(v), cmp);
	for (Edge e : v) cout << e.a << " " << e.b << " " << e.w << "\n";

}

int main(){
    /* freopen("div7.in", "r", stdin);
	freopen("div7.out", "w", stdout); */
    solve();
} 