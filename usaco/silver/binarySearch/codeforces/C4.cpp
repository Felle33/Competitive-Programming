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

int n, k;
vector<pair<double, double>> pairs;

bool cmp(double d1, double d2) {
    return d1 > d2;
}

bool good(double mid) {
    vector<double> diff(n);
    rep(i, n) {
        diff[i] = pairs[i].first - mid * pairs[i].second;
    }

    sort(all(diff), cmp);
    double sum = 0;
    rep(i, k) {
        sum += diff[i];
    }

    return sum >= 0;
}

void solve(){
    cin >> n >> k;
    pairs = vector<pair<double, double>>(n);
    rep(i, n) {
        cin >> pairs[i].first >> pairs[i].second;
    }

    double l = -1, r = 1e6;

    rep(i, 60) {
        double mid = l + (r - l) / 2;

        if(good(mid)) {
            l = mid;
        } else {
            r = mid;
        }
    }

    cout << l << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    std::cout.precision(10);
    cout << std::fixed;

    solve();
}