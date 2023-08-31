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
#include <stack>

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
const ll INF = 2e18;
vector<int> DX = {0, 1, -1, 0};
vector<int> DY = {1, 0, 0, -1};
string DIR = "RDUL";

struct stackStruct{
    stack<ll> sMax, sMin, s;

    void push(int x) {
        s.push(x);
        if(sMax.empty() || sMax.top() < x) {
            sMax.push(x);
        } else {
            sMax.push(sMax.top());
        }

        if(sMin.empty() || sMin.top() > x) {
            sMin.push(x);
        } else {
            sMin.push(sMin.top());
        }
    }

    void pop(stackStruct& s2) {
        if(s.empty()) {
            transfer(s2);
        }

        s.pop();
        sMin.pop();
        sMax.pop();
    }

    bool empty() {
        return s.empty();
    }

    void transfer(stackStruct& s2) {
        while(!s2.empty()) {
            s.push(s2.s.top());
            s2.s.pop();
            sMax.push(s2.sMax.top());
            s2.sMax.pop();
            sMin.push(s2.sMin.top());
            s2.sMin.pop();
        }
    }

    ll max() {
        if(empty()) return -1;
        return sMax.top();
    }

    ll min() {
        if(empty()) return INF;
        return sMax.top();
    }
};

void solve(){
    ll n, k; cin >> n >> k;
    vll a(n);
    rep(i, n) cin >> a[i];

    stackStruct s1, s2;
    ll mi = INF, ma = -1, lastIndex = -1;
    ll ans = 0;
    ll l = 0, r = 0;
    for(; r < n; r++) {
        mi = min(mi, a[r]);
        ma = max(ma, a[r]);
        s2.push(a[r]);

        if(ma - mi > k) {
            if(lastIndex < l) {
                ll numIntervalRight = r - l;
                ans += (numIntervalRight + 1) * numIntervalRight / 2;
                lastIndex = r - 1;
            } else {
                ll numbersAdded = r - lastIndex - 1;
                ll numIntervalRight = r - l;
                ll oldNum = numIntervalRight - numbersAdded;
                ans += (numIntervalRight + 1) * numIntervalRight / 2 - (oldNum + 1) * oldNum / 2;
                lastIndex = r - 1;
            }

            while(ma - mi > k) {
                s1.pop(s2);
                ma = max(s1.max(), s2.max());
                mi = max(s1.min(), s2.max());
                l++;
            }
        }
    }

    if(lastIndex < l) {
        ll numIntervalRight = r - l;
        ans += (numIntervalRight + 1) * numIntervalRight / 2;
    } else {
        ll numbersAdded = r - lastIndex - 1;
        ll numIntervalRight = r - l;
        ll oldNum = numIntervalRight - numbersAdded;
        ans += (numIntervalRight + 1) * numIntervalRight / 2 - (oldNum + 1) * oldNum / 2;
    }

    cout << ans << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    std::cout.precision(10);
    cout << std::fixed;

    solve();
}