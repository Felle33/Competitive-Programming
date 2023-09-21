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
vector<int> DX = {0, 1, -1, 0};
vector<int> DY = {1, 0, 0, -1};
string DIR = "RDUL";

void solve(){
    string s; cin >> s;
    int n = s.size();

    bool tog = false;
    bool atleastoneb = false;
    int numA = 0;
    for(int i = 0; i < n - 1; i++) {
        if(s[i] == 'B' && s[i] == s[i + 1]) {
            tog = true;
        }
    }

    rep(i, n) {
        if(s[i] == 'A') numA++;
        else atleastoneb = 1;
    }

    if(!atleastoneb) {
        cout << 0 << '\n';
        return;
    }

    if(s[0] == 'B' || s[n - 1] == 'B' || tog) {
        cout << numA << '\n';
        return;
    }

    vi groups;
    int cur = 0;
    rep(i, n) {
        if(s[i] == 'B') {
            groups.push_back(cur);
            cur = 0;
        } else if(i == n - 1) {
            cur++;
            groups.push_back(cur);
        } else {
            cur++;
        }
    }

    sort(all(groups));
    int tot = 0;
    rep(i, groups.size()) tot += groups[i];
    cout << tot - groups[0] << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    std::cout.precision(10);
    cout << std::fixed;

    int t;
    cin >> t;

    while(t--){
        solve();
    }
}