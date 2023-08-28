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

bool increasing(vector<int>& a) {
    int n = a.size();
    for(int i = 1; i < n; i++) {
        if(a[i] <= a[i - 1]) return false;
    }
    return true;
}

void solve(){
    int n, x, y; cin >> x >> y >> n;
    vector<int> a;
    a.push_back(y);
    for(int i = 1, dif = 1; i < n; i++, dif++) {
        int j = a.back();
        if(i == n - 1) {
            if(x > j - dif) a.push_back(1e9);
            else a.push_back(x);
        } else {
            
            a.push_back(j - dif);
        }
    }

    reverse(all(a));

    if(increasing(a)) {
        for(int x : a) {
            cout << x << ' ';
        }
    } else {
        cout << -1;
    }

    cout << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--){
        solve();
    }
}