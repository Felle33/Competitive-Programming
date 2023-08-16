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

double ppow(int launc) {
    int res = 1;
    rep(i, launc) {
        res *= 2;
    }
    return (double) 1 / (double) res;
}

void solve(){
    double n;
    int k;
    cin >> n >> k;

    double res = 0;
    double frac = 1 / n;
    for(int i = 1; i <= n; i++) {
        if(i >= k) {
            res += frac;
        } else {
            int launc = 0;
            int tmp = i;

            while(tmp < k) {
                tmp = tmp * 2;
                launc++;
            }

            res += (frac * ppow(launc));
        }
    }

    cout << res << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    std::cout.precision(10);
    cout << std::fixed;

    solve();
}