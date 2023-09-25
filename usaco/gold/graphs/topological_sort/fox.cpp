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

vector<pii> orderChars(26);

// return true if there is a cycle in the graph
bool topSort(vector<vector<int>>& adj, vector<int> arcIn) {
    queue<int> q;
    int cnt = 0;

    for(int i = 0; i < 26; i++) {
        if(arcIn[i] == 0) {
            q.push(i);
            cnt++;
            orderChars[i] = mp(cnt, i);
        }
    }

    while(!q.empty()) {
        int node = q.front();
        q.pop();

        for(int to : adj[node]) {
            arcIn[to]--;
            if(arcIn[to] == 0) {
                cnt++;
                orderChars[to] = mp(cnt, to);
                q.push(to);
            }
        }
    }

    return cnt == 26;
}

void solve(){
    int n; cin >> n;
    vector<string> names(n);
    rep(i, n) cin >> names[i];

    vector<vector<int>> adj(26);
    vector<int> arcIn(26);
    bool rightOrder = true;

    for(int i = 0; i < n - 1; i++) {
        string s1 = names[i], s2 = names[i + 1];
        if(s1 == s2) continue;

        int m = min(s1.size(), s2.size());
        int l = 0;
        bool added = false;
        for(; l < m && !added; l++) {
            if(s1[l] < s2[l]) {
                adj[s1[l] - 'a'].push_back(s2[l] - 'a');
                added = 1;
                arcIn[s2[l] - 'a']++;
            } else if(s1[l] > s2[l]) {
                adj[s2[l] - 'a'].push_back(s1[l] - 'a');
                added = 1;
                arcIn[s1[l] - 'a']++;
            }

            if(!added) {
                if(s1.size() > s2.size()) {
                    rightOrder = 0;
                }
            }
        }
    }


    if(!rightOrder || !topSort(adj, arcIn)) {
        cout << "Impossible\n";
        return;
    }

    sort(all(orderChars));
    for(int i = 0; i < 26; i++) {
        char c = orderChars[i].second + 'a';
        cout << c;
    }
    cout << '\n';

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    std::cout.precision(10);
    cout << std::fixed;

    solve();
}