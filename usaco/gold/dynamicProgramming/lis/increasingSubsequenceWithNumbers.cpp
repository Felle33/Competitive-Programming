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

struct Card_Pointer {
    int num;
    Card_Pointer* pointer;
};

vector<stack<Card_Pointer>> muc;

void insert_muc(int x) {
    if(muc.empty()) {
        stack<Card_Pointer> st;
        st.push({x, NULL});
        muc.push_back(st);
        return;
    }

    int n = muc.size();
    int l = -1, r = n;
    while(l + 1 < r) {
        int m = l + (r - l) / 2;

        if(muc[m].top().num >= x) {
            r = m;
        } else {
            l = m;
        }
    }

    if(r == n) {
        stack<Card_Pointer> st;
        st.push({x, &muc[n - 1].top()});
        muc.push_back(st);
    } else {
        if(r == 0) {
            muc[r].push({x, NULL});
        } else {
            muc[r].push({x, &muc[r - 1].top()});
        }
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

    cout << muc.size() << '\n';

    int s = muc.size();
    Card_Pointer it = muc[s - 1].top();
    vector<int> v;
    while(1) {
        if(it.pointer == NULL) {
            v.push_back(it.num);
            break;
        }
        v.push_back(it.num);
        it = *it.pointer;
    }

    int vsize = v.size();
    for(int i = vsize - 1; i >= 0; i--) {
        cout << v[i] << " ";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
}