#include <algorithm>
#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
#include <cstring>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include <stack>

#define all(x) (x).begin(), (x).end()

using namespace std;
typedef long long ll;

struct pointTime {
	int client;
	int time;
	bool arrive;
};

bool cmp(const pointTime p1, const pointTime p2) {
	if(p1.time != p2.time) return p1.time < p2.time;
	return p1.arrive > p2.arrive;
}

void solve(){
    int n;
	cin >> n;
	vector<pointTime> points;
	for(int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		points.push_back({i, a, true});
		points.push_back({i, b, false});
	}

	sort(all(points), cmp);
	vector<int> roomsAssigned(n);
	n = points.size();

	int numberClients = 0, ans = 0;
	set<int> s;
	for(int i = 0; i < n; i++) {
		pointTime point = points[i];
		if(point.arrive) {
			numberClients++;
			if(s.empty()) {
				roomsAssigned[point.client] = numberClients;
			} else {
				auto it = s.begin();
				roomsAssigned[point.client] = *it;
				s.erase(it);
			}
			ans = max(ans, numberClients);
		} else {
			s.insert(roomsAssigned[point.client]);
			numberClients--;
		}
	}

	cout << ans << '\n';
	for(int x : roomsAssigned) {
		cout << x << ' ';
	}
	cout << '\n';
}

int main(){
    /* freopen("bcount.in", "r", stdin);
	freopen("bcount.out", "w", stdout); */
	ios::sync_with_stdio(false);
	cin.tie(NULL);
    solve();
} 