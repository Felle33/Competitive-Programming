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

struct Particle {
    int id, x, y;
};

bool cmp(Particle p1, Particle p2) {
    if(p1.x == p2.x) return p1.y < p2.y;
    return p1.x < p2.x;
}

void solve(){
    int n; cin >> n;
    vector<Particle> a(n);
    rep(i, n) {
        int x, y; cin >> x >> y;
        a[i].id = i;
        a[i].x = x;
        a[i].y = y;
    }

    sort(all(a));
    vector<int> maximum(n);
    maximum[n - 1] = a[n - 1].y;
    for(int i = n - 2; i >= 0; i--) {
        maximum[i] = max(maximum[i + 1], a[i].y);
    }

    int minimum = -2e9;
    for(int i = 0; i < n; i++) {
        minimum = min(minimum, a[i].y);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    std::cout.precision(10);
    cout << std::fixed;

    solve();
}