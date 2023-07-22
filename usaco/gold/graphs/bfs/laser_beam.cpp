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

typedef long long ll;
using namespace std;

const ll MOD = 1e9 + 7;
const ll DIM = 1e6;

void solve(){
    int n;
    cin >> n;

    vector<pair<int, int>> points(n + 2);
    unordered_map<int, vector<int>> hor;
    unordered_map<int, vector<int>> ver;

    for(int i = 0; i < n + 2; i++) {
        int x, y;
        cin >> x >> y;
        points[i] = {x, y};
        hor[x].push_back(i);
        ver[y].push_back(i);
    }

    // index of the fence post and bool for the direction of the incoming
    // beam (true = hor, false = ver)
    queue<pair<int, bool>> q;
    vector<int> distance(n + 2, 1e9);
    q.push({0, true});
    q.push({0, false});
    distance[0] = 0;

    while(!q.empty()) {
        int cur_ind = q.front().first;
        int beam_dir = q.front().second;
        q.pop();

        if(beam_dir) {
            int ver_coord = points[cur_ind].second;

            for(int point : ver[ver_coord]) {
                if(distance[point] == 1e9) {
                    q.push({point, false});
                    distance[point] = distance[cur_ind] + 1;
                }
            }
        } else {
            int hor_coord = points[cur_ind].first;

            for(int point : hor[hor_coord]) {
                if(distance[point] == 1e9) {
                    q.push({point, true});
                    distance[point] = distance[cur_ind] + 1;
                }
            }
        }
    }

    cout << (distance[1] == 1e9 ? -1 : (distance[1] - 1)) << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("lasers.in", "r", stdin);
	freopen("lasers.out", "w", stdout);

    solve();
}