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
    int n;
    double d, h;
    cin >> n >> d >> h;

    vector<double> heights(n);
    rep(i, n) {
        cin >> heights[i];
    }

    double res = d * h / 2;
    for(int i = 0; i < n - 1; i++) {
        if(heights[i] + h <= heights[i + 1]) {
            res += d * h / 2;
        } else {
            double base_minore = abs(d * (heights[i + 1] - heights[i] - h) / h);
            res += (base_minore + d) * (heights[i + 1] - heights[i]) / 2;
        }
    }

    cout << res << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    std::cout << std::fixed << std::setprecision(7);

    int t;
    cin >> t;

    while(t--){
        solve();
    }
}