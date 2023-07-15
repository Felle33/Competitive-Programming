#include <algorithm>
#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
#include <cstring>
#include <unordered_map>
#include <map>
#include <set>
#include <unordered_set>
#include <iomanip>

#define all(x) (x).begin(), (x).end()
#define rep(X,Y) for (int (X) = 0;(X) < (Y);++(X))
#define reps(X,S,Y) for (int (X) = S;(X) < (Y);++(X))

typedef long long ll;
using namespace std;

const ll MOD = 1e9 + 7;
const ll DIM = 1e6;
const ll INF = 1e9;
vector<int> DX = {0, 1, -1, 0};
vector<int> DY = {1, 0, 0, -1};
string DIR = "RDUL";

void solve(){
    unordered_set<ll> possible;

    for (long long k = 2; k <= 1000000; ++k) {
        long long val = 1 + k;
        long long p = k*k;
        for (int cnt = 3; cnt <= 63; ++cnt) {
            val += p;
            if (val > 1e18) break;
            possible.insert(val);
            if (p > (long long)(1e18) / k) break;
            p *= k;
        }
    }

    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        double goal;
        cin >> goal;

        if (n < 3){
            cout << "NO" << endl;
            continue;
        }

        if(possible.count(goal) >= 1) {
            cout << "YES" << '\n';
        } else {
            bool found = false;
            for(ll l = 0, r = goal; l <= r;) {
                ll mid = l + (r - l) / 2;

                ll eq = mid * mid + mid + 1;

                if(eq == goal) {
                    found = true;
                    break;
                } else if(eq > goal) {
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }

            if(found) {
                cout << "YES" << '\n';
            } else {
                cout << "NO\n";
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
}