#include <algorithm>
#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
#include <cstring>
#include <unordered_map>
#include <map>
#include <stack>
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

vector<vector<pii>> muc;
vector<int> nums;

void insert_muc(int x, int index) {
    if(muc.empty()) {
        muc.push_back({{index, -1}});
        return;
    }

    int n = muc.size();
    int l = -1, r = n;
    while(l + 1 < r) {
        int m = l + (r - l) / 2;

        if(nums[muc[m].back().first] >= x) {
            r = m;
        } else {
            l = m;
        }
    }

    if(r == n) {
        int l_vec_back = muc[r - 1].size() - 1;
        muc.push_back({{index, l_vec_back}});
    } else {
        if(r == 0) {
            muc[r].push_back({index, -1});
        } else {
            int l_vec_back = muc[r - 1].size() - 1;
            muc[r].push_back({index, l_vec_back});
        }
    }
}

void solve(){
    int n;
    cin >> n;

    rep(i, n) {
        int x;
        cin >> x;
        nums.push_back(x);
        insert_muc(x, i);
    }

    cout << muc.size() << '\n';

    int s = muc.size();
    vector<int> v;
    pii it = muc[s - 1][0];

    while(1) {
        if(it.second == -1) {
            v.push_back(it.first);
            break;
        }
        v.push_back(it.first);
        it = muc[s - 2][it.second];
        s--;
    }

    int vsize = v.size();
    for(int i = vsize - 1; i >= 0; i--) {
        cout << v[i] + 1 << " ";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
}