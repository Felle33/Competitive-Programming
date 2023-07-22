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
#define pii pair<int,int>

typedef long long ll;
using namespace std;

const ll MOD = 1e9 + 7;
const ll DIM = 1e6;
const int INF = 1e9;

vector<int> DX = {0, 1, -1, 0};
vector<int> DY = {1, 0, 0, -1};
string DIR = "RDUL";

ll area(vector<ll> rect) {
	ll width = rect[2] - rect[0];
	ll height = rect[3] - rect[1];
	return width * height;
}

// return 0 if it doesn't intersect
int inter_area(vector<ll> s1, vector<ll> s2) {
	int bl_a_x = s1[0], bl_a_y = s1[1], tr_a_x = s1[2], tr_a_y = s1[3];
	int bl_b_x = s2[0], bl_b_y = s2[1], tr_b_x = s2[2], tr_b_y = s2[3];

	ll l1 = min(tr_a_x, tr_b_x) - max(bl_a_x, bl_b_x);
	ll l2 = min(tr_a_y, tr_b_y) - max(bl_a_y, bl_b_y);

	if(l1 <= 0 || l2 <= 0) return 0;

	return l1 * l2;
}

// return true if x,y is covered by the rectangle s
bool covered(ll x, ll y, vector<ll> s){
	return x >= s[0] && x <= s[2] && y >= s[1] && y <= s[3];
}

ll exponentiation(ll b, ll e){
    ll res = 1;
    b %= MOD;
    while(e > 0){
        if(e & 1)
            res = res * b % MOD;
        
        b = b * b % MOD;
        e >>= 1;
    }

    return res;
}

void solve(){
    int n, m;
    cin >> n >> m;
    vector<vector<char>> graph(n, vector<char>(m));
    queue<pii> q;
    pii player;
    vector<vector<bool>> visited(n, vector<bool>(m));
    vector<vector<int>> distance(n, vector<int>(m, INF));
    vector<vector<int>> parents(n, vector<int>(m));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> graph[i][j];

            if(graph[i][j] == 'M'){
                q.push({i, j});
                visited[i][j] = true;
                distance[i][j] = 0;
            }

            if(graph[i][j] == 'A'){
                player.first = i;
                player.second = j;
            }
        }
    }

    if(player.first == n - 1 || player.second == m - 1){
        cout << "YES" << '\n' << 0;
        return;
    }

    int dis = 0;
    while(!q.empty()){
        int cycles = q.size();
        dis++;
        
        while(cycles--){
            pii u = q.front();
            q.pop();

            for(int i = 0; i < 4; i++){
                pii adj = make_pair(u.first + DX[i], u.second + DY[i]);

                if(adj.first < 0 || adj.second < 0 || adj.first == n || adj.second == m) continue;
                if(visited[adj.first][adj.second] || graph[adj.first][adj.second] == '#') continue;
                
                distance[adj.first][adj.second] = dis;
                visited[adj.first][adj.second] = true;
                q.push(adj);
            }
        }
    }

    dis = 0;
    visited = vector<vector<bool>>(n, vector<bool>(m));
    q.push(player);
    pii end = make_pair(-1, -1);
    parents[player.first][player.second] = -1;
    visited[player.first][player.second] = true;

    while(!q.empty()){
        int cycles = q.size();
        dis++;

        while(cycles--){
            pii u = q.front();
            q.pop();

            for(int i = 0; i < 4; i++){
                pii adj = make_pair(u.first + DX[i], u.second + DY[i]);

                if(adj.first < 0 || adj.second < 0 || adj.first == n || adj.second == m || distance[adj.first][adj.second] <= dis) continue;
                if(graph[adj.first][adj.second] == '#' || visited[adj.first][adj.second]) continue;
                
                parents[adj.first][adj.second] = i;
                visited[adj.first][adj.second] = true;
                q.push(adj);

                if((adj.first == n - 1 || adj.second == m - 1 || adj.first == 0 || adj.second == 0) && end.first == -1){
                    end.first = adj.first;
                    end.second = adj.second;
                }
            }
        }
    }

    if(end.first != -1){
        pii child = {end.first, end.second};
        vector<char> steps;
        while(parents[child.first][child.second] != -1){
            int p = parents[child.first][child.second];
            steps.push_back(DIR[p]);
            child = {child.first - DX[p], child.second - DY[p]};
        }

        reverse(all(steps));

        cout << "YES" << '\n' << steps.size() << '\n';
        for(char c : steps){
            cout << c;
        }
    }
    else{
        cout << "NO";
    }
    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    /* freopen("hps.in", "r", stdin);
	freopen("hps.out", "w", stdout); */

    solve();
}