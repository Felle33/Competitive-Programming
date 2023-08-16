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

struct client {
	int arrive, departure;
};

bool cmp(client& c1, client& c2) {
	return c1.arrive < c2.arrive;
}

void solve(){
    int n;
	cin >> n;

	vector<client> clients(n);
	for(int i = 0; i < n; i++) {
		cin >> clients[i].arrive >> clients[i].departure;
	}

	priority_queue<int> minQueue;
	sort(all(clients), cmp);
	ll ans = 0;
	minQueue.push(clients[0].departure);
	int cnt = 1;
	for(int i = 1; i < n; i++) {
		while(i < n && clients[i].arrive <= minQueue.top()) {
			i++;
			cnt++;
		}



	}
}

int main(){
    /* freopen("bcount.in", "r", stdin);
	freopen("bcount.out", "w", stdout); */
	ios::sync_with_stdio(false);
	cin.tie(NULL);
    solve();
} 