#include <algorithm>
#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
#include <cstring>
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

const ll INF = 1e15;

// nodes and arcs
int n, m;
int source;

vector<vector<pii>> adj;

// dis from 0 to other nodes
vll dis;

// Time complexity O(|N - 1| * |E|)
void bellman_ford() {
    dis[source] = 0;
    for(int k = 0; k < n - 1; k++) {
        for(int i = 0; i < n; i++) {
            for(pii& edge : adj[i]) {
                int to = edge.first;
                ll cost = edge.second;

                if(dis[to] > dis[i] + cost) {
                    dis[to] = dis[i] + cost;
                }
            }
        }
    }
    
}

void print() {
    for(int i = 0; i < n; i++) {
        cout << "The distance from 0 to " << i << " is: " << dis[i] << '\n';
    }
}

void solve(){
    n = 4, m = 6;
    source = 0;
    adj = vector<vector<pii>>(n);
    dis = vll(n, INF);

    adj[0].pb({1, 5});
    adj[0].pb({2, 7});
    
    adj[1].pb({2, 1});
    adj[1].pb({3, 20});
    
    adj[2].pb({3, 2});
    
    adj[3].pb({0, -1});

    bellman_ford();

    print();
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    std::cout.precision(10);
    cout << std::fixed;

    solve();
}