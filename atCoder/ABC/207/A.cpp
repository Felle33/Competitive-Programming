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
#define f first
#define s second
#define mp make_pair
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

struct interval{
    int a, b, type;
};

bool cmp(interval& i1, interval& i2) {
    return i1.a < i2.a;
}

void solve(){
    int n;
    cin >> n;
    vector<interval> intervals;
    rep(i, n)  {
        int a, b, t;
        cin >> t >> a >> b;
        intervals.push_back({a, b, t});
    }

    sort(all(intervals), cmp);
    int ans = 0;
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if(intervals[i].type == 1 || intervals[i].type == 3) {
                if((intervals[j].type == 1 || intervals[j].type == 2) && intervals[i].b >= intervals[j].a) {
                    ans++;
                } else if((intervals[j].type == 3 || intervals[j].type == 4) && intervals[i].b > intervals[j].a) {
                    ans++;
                }
            } else {
                if(intervals[i].b > intervals[j].a) {
                    ans++;
                }
            }
        }
    }

    cout << ans << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
}