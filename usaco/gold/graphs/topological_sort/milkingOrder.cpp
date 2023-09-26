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
#include <bitset>

#define all(x) (x).begin(), (x).end()
#define mp make_pair
#define pb push_back
#define rep(X,Y) for (int (X) = 0;(X) < (Y);++(X))
#define reps(X,S,Y) for (int (X) = S;(X) < (Y);++(X))

using namespace std;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<unsigned long long> vull;
typedef vector<vector<int>> vvi;
typedef long long ll;
typedef pair<int,int> pii;

const ll MOD = 1e9 + 7;
const ll DIM = 1e6;
const ll INF = 1e15;
vector<int> DX = {0, 1, -1, 0};
vector<int> DY = {1, 0, 0, -1};
string DIR = "RDUL";

vvi adj;
vi order;
int n, m;

// return true if there is a cycle
bool topSortCycle(vi arcIn) {
    int cnt = 0;
    queue<int> q;
    rep(i, n) {
        if(arcIn[i] == 0) {
            cnt++;
            q.push(i);
        }
    }

    while(!q.empty()) {
        int node = q.front();
        q.pop();

        for(int to : adj[node]) {
            arcIn[to]--;
            if(arcIn[to] == 0) {
                q.push(to);
                cnt++;
            }
        }
    }

    return cnt != n;
}

void topSort(vi& arcIn) {
    priority_queue<int, vi, greater<int>> pq;
    rep(i, n) {
        if(arcIn[i] == 0) {
            pq.push(i);
        }
    }

    while(!pq.empty()) {
        int node = pq.top();
        pq.pop();
        order.push_back(node);

        for(int to : adj[node]) {
            arcIn[to]--;
            if(arcIn[to] == 0) {
                pq.push(to);
            }
        }
    }
}

void solve(){
    cin >> n >> m;
    adj = vvi(n);
    vi arcIn(n);
    vvi obs(m);
    rep(i, m) {
        int s; cin >> s;
        rep(j, s) {
            int a; cin >> a;
            a--;
            obs[i].push_back(a);
        }
    }

    int l = -1, r = m;
    bool fromLeft = 1;
    while(l + 1 < r) {
        int mid = l + (r - l) / 2;

        if(fromLeft) {
            for(int i = l + 1; i <= mid; i++) {
                // take the obs[i] and process it adding to the adjacent list
                int s = obs[i].size();
                for(int j = 0; j < s - 1; j++) {
                    adj[obs[i][j]].push_back(obs[i][j + 1]);
                    arcIn[obs[i][j + 1]]++;
                }
            }
        } else {
            for(int i = r; i > mid; i--) {
                // take the obs[i] and process it popping from the adjacent list
                int s = obs[i].size();
                for(int j = s - 2; j >= 0; j--) {
                    adj[obs[i][j]].pop_back();
                    arcIn[obs[i][j + 1]]--;
                }
            }
        }

        if(topSortCycle(arcIn)) {
            r = mid;
            fromLeft = 0;
        } else {
            l = mid;
            fromLeft = 1;
        }
    }

    adj = vvi(n);
    arcIn = vi(n);
    for(int i = 0; i <= l; i++) {
        // take the obs[i] and process it adding to the adjacent list
        int s = obs[i].size();
        for(int j = 0; j < s - 1; j++) {
            adj[obs[i][j]].push_back(obs[i][j + 1]);
            arcIn[obs[i][j + 1]]++;
        }
    }

    topSort(arcIn);

    for(int i = 0; i < n; i++) {
        if(i != n - 1) {
            cout << (order[i] + 1) << ' ';
        } else {
            cout << (order[i] + 1);
        }
        
    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    std::cout.precision(10);
    cout << std::fixed;

    freopen("milkorder.in", "r", stdin);
	freopen("milkorder.out", "w", stdout);

    solve();
}