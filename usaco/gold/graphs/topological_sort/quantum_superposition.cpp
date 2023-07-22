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

void bfs(vector<vector<int>>& adj, vector<int>& path, int n) {
    queue<int> q;
    q.push(0);

    int d = 0;
    while(!q.empty()) {
        // SIZE
        int cycles = q.size();
        while(cycles--) {
            bool already_put = false;
            int node = q.front();
            q.pop();

            for(int ed : adj[node]) {
                // OCCHIO DOPPIONI
                if(ed == n - 1 && !already_put) {
                    path.push_back(d + 1);
                    already_put = true;
                } else {
                    q.push(ed);
                }
            }
        }
        
        d++;
    }
}

bool binarySearch(int initial_number, vector<int>& path2, int goal) {
    int l = 0, r = path2.size() - 1;

    while(l <= r) {
        int mid = l + (r - l) / 2;

        if(initial_number + path2[mid] == goal) {
            return true;
        } else if(initial_number + path2[mid] < goal) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    return false;
}

void solve(){
    int n1, n2, m1, m2, q;
    cin >> n1 >> n2 >> m1 >> m2;

    vector<vector<int>> adj1(n1);
    vector<vector<int>> adj2(n2);
    rep(i, m1) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        adj1[a].push_back(b);
    }

    rep(i, m2) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        adj2[a].push_back(b);
    }

    vector<int> path1, path2;
    set<int> answers;
    bfs(adj1, path1, n1);
    bfs(adj2, path2, n2);

    for(int i = 0; i < (int)path1.size(); i++) {
        for(int j = 0; j < (int)path2.size(); j++) {
            answers.insert(path1[i] + path2[j]);
        }
    }

    cin >> q;

    int sum;
    rep(i, q) {
        cin >> sum;

        if(answers.count(sum) > 0) cout << "Yes\n";
        else cout << "No\n";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
}