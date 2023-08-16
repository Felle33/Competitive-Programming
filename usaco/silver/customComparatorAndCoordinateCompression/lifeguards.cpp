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
#define rep(X,Y) for (int (X) = 0;(X) < (Y);++(X))
#define reps(X,S,Y) for (int (X) = S;(X) < (Y);++(X))

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

const ll MOD = 1e9 + 7;
const ll DIM = 1e6;
const ll INF = 1e9;
vector<int> DX = {0, 1, -1, 0};
vector<int> DY = {1, 0, 0, -1};
string DIR = "RDUL";

struct event {
    int time, cow_index;
    bool is_starting;
};

bool cmp (event& e1, event& e2) {
    return e1.time < e2.time;
}

void solve(){
    int n;
	cin >> n;

    vector<event> events;
    rep(i, n) {
        int l, r;
        cin >> l >> r;
        events.push_back({l, i, true});
        events.push_back({r, i, false});
    }
	
    sort(all(events), cmp);
    set<int> active;
    vector<int> alone_time(n);
    int prev_time = 0;
    int total_time = 0;
    for(event e : events) {
        int curr_time = e.time;

        if(active.size() > 0) {total_time += curr_time - prev_time;}

        if (active.size() == 1) {
            alone_time[*active.begin()] += curr_time - prev_time;
        }

        if(e.is_starting) {
            active.insert(e.cow_index);
        } else {
            active.erase(e.cow_index);
        }

        prev_time = curr_time;
    }

    int min_alone_time = *min_element(all(alone_time));
    cout << (total_time - min_alone_time) << '\n';
}

int main(){
    freopen("lifeguards.in", "r", stdin);
	freopen("lifeguards.out", "w", stdout);
    solve();
} 