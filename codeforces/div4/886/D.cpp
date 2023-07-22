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

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

const ll MOD = 1e9 + 7;
const ll DIM = 1e6;
const ll INF = 1e9;
vector<int> DX = {0, 1, -1, 0};
vector<int> DY = {1, 0, 0, -1};
string DIR = "RDUL";

bool already_ok(vector<int>& diff, int k) {
    int n = diff.size();
    rep(i, n - 1) {
        if(diff[i + 1] - diff[i] > k) return false;
    }
    return true;
}

void solve(){
    int n, k;
    cin >> n >> k;

    vector<int> diff(n);
    rep(i, n) {
        cin >> diff[i];
    }

    sort(all(diff));
    vector<int> lenghts;
    for(int i = 1; i < n; i++) {
        int count = 1;
        while(i < n && (diff[i] - diff[i - 1]) <= k) {
            i++;
            count++;
        }
        lenghts.push_back(count);
    }

    sort(all(lenghts));
    int m = lenghts.size();
    

    if(m == 0) {
        cout << 0 << '\n';
    } else {
        int max_length = lenghts[m - 1];
        cout << (n - max_length) << '\n';
    }
    
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