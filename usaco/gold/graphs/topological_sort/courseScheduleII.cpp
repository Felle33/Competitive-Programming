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

vvi adj_rev;
vi order;
vector<pii> labels;
int n, m;

void topSort(vi& arcOut) {
    priority_queue<int> pq;
    int cnt = n;
    for(int i = 1; i <= n; i++) {
        if(arcOut[i] == 0) {
            pq.push(i);
        }
    }

    while(!pq.empty()) {
        int node = pq.top();
        pq.pop();
        order.push_back(node);

        for(int back : adj_rev[node]) {
            arcOut[back]--;

            if(arcOut[back] == 0) {
                pq.push(back);
            }
        }
    }
}

void solve(){
    cin >> n >> m;
    adj_rev = vvi(n + 1);
    vi arcOut(n + 1);
    labels = vector<pii>(n + 1);

    for(int i = 1; i <= n; i++) {
        labels[i] = mp(i, 0);
    }

    rep(i, m) {
        int a, b;
        cin >> a >> b;
        adj_rev[b].push_back(a);
        arcOut[a]++;
    }

    topSort(arcOut);

    reverse(all(order));
    for(int i = 0; i < n; i++) {
        if(i < n - 1) {
            cout << order[i] << " ";
        } else {
            cout << order[i];
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    std::cout.precision(10);
    cout << std::fixed;

    //freopen("milkorder.in", "r", stdin);
	//freopen("milkorder.out", "w", stdout);

    solve();
}