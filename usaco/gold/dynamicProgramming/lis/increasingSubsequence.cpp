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

vector<vector<int>> muc;

void insert_muc(int x) {
    if(muc.empty()) {
        muc.push_back({x});
        return;
    }

    int n = muc.size();
    int l = -1, r = n;
    while(l + 1 < r) {
        int m = l + (r - l) / 2;

        if(muc[m].back() >= x) {
            r = m;
        } else {
            l = m;
        }
    }

    if(r == n) {
        muc.push_back({x});
    } else {
        muc[r].push_back(x);
    }
}

void solve(){
    int n;
    cin >> n;

    rep(i, n) {
        int x;
        cin >> x;
        insert_muc(x);
    }

    cout << muc.size();
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
}