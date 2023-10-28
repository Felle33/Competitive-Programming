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
const ll LL_MAX = 9223372036854775807;
vector<int> DX = {0, 1, -1, 0};
vector<int> DY = {1, 0, 0, -1};
string DIR = "RDUL";

struct SegmentTree {
    int size;
    vector<ll> tree, op;

    ll NEUTRAL_ELEMENT = 0;
    ll NOP = LL_MAX;

    SegmentTree(int n) {
        size = 1;
        while(size < n) size *= 2;
        tree.resize(2 * size, NEUTRAL_ELEMENT);
        op.resize(2 * size, NOP);
    }

    void propagate(int x, int lx, int rx) {
        if(op[x] == NOP || rx - lx == 1) return;
        int mid = (rx + lx) / 2;
        tree[2 * x + 1] += op[x];
        tree[2 * x + 2] += op[x];
        op[2 * x + 1] = (op[2 * x + 1] == NOP ? op[x] : op[2 * x + 1] + op[x]);
        op[2 * x + 2] = (op[2 * x + 2] == NOP ? op[x] : op[2 * x + 2] + op[x]);
        op[x] = NOP;
    }

    void add(int l_query, int r_query, ll v, int x, int lx, int rx) {
        propagate(x, lx, rx);
        if(l_query >= rx || r_query <= lx) return;
        if(l_query <= lx && rx <= r_query){
            tree[x] += v;
            op[x] = (op[x] == NOP ? v : op[x] + v);
            return;
        }

        int m = (lx + rx) / 2;
        add(l_query, r_query, v, 2 * x + 1, lx, m);
        add(l_query, r_query, v, 2 * x + 2, m, rx);
        tree[x] = max(tree[2 * x + 1], tree[2 * x + 2]);
    }

    void add(int l_query, int r_query, ll v) {
        add(l_query, r_query, v, 0, 0, size);
    }

    ll maxi(int l_query, int r_query, int x, int lx, int rx) {
        propagate(x, lx, rx);
        if(l_query >= rx || r_query <= lx) return NEUTRAL_ELEMENT;
        if(l_query <= lx && rx <= r_query) return tree[x];
        int mid = (lx + rx) / 2;
        ll s1 = maxi(l_query, r_query, 2 * x + 1, lx, mid);
        ll s2 = maxi(l_query, r_query, 2 * x + 2, mid, rx);
        return max(s1, s2);
    }

    ll maxi(int l, int r) {
        return maxi(l, r, 0, 0, size);
    }
};

void solve(){
    int q; cin >> q;
    vector<vector<int>> op(q, vector<int>(3));
    vi nums;
    rep(i, q) {
        char a;
        int b, c;
        cin >> a >> b >> c;
        c++;
        op[i][0] = a;
        op[i][1] = b;
        op[i][2] = c;
        nums.push_back(b);
        nums.push_back(c);
    }

    sort(all(nums));
    nums.resize(unique(all(nums)) - nums.begin());

    map<int, int> cmp;
    int m = nums.size();
    for(int i = 0; i < m; i++) {
        cmp[nums[i]] = i + 1;
    }

    int numSeg = 0;
    SegmentTree sgt(m + 1);
    rep(i, q) {
        char ope = op[i][0];
        int l = op[i][1], r = op[i][2];
        if(ope == '+') {
            numSeg++;
            sgt.add(cmp[l], cmp[r], 1);
            if(sgt.maxi(0, cmp[nums[m - 1]] + 1) == numSeg) {
                cout << "NO\n";
            } else {
                cout << "YES\n";
            }
        } else {
            numSeg--;
            sgt.add(cmp[l], cmp[r], -1);
            if(sgt.maxi(0, cmp[nums[m - 1]] + 1) == numSeg) {
                cout << "NO\n";
            } else {
                cout << "YES\n";
            }
        }
    }


}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    std::cout.precision(10);
    cout << std::fixed;

    solve();
}