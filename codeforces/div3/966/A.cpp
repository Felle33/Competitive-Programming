#include <algorithm>
#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
#include <cstring>
#include <map>
#include <set>
#include <iomanip>
#include <bitset>

#define all(x) (x).begin(), (x).end()
#define rep(X,Y) for (int (X) = 0;(X) < (Y);++(X))
#define reps(X,S,Y) for (int (X) = S;(X) < (Y);++(X))
#define FELLE ios_base::sync_with_stdio(false); cin.tie(NULL); std::cout.precision(10); cout << std::fixed;

using namespace std;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<unsigned long long> vull;
typedef vector<vector<int>> vvi;
typedef long long ll;
typedef pair<int,int> pii;

const ll MOD1 = 1e9 + 7;
const ll MOD2 = 998244353;
const ll DIM = 1e6;
const int INF = 1e9;
const ll LLINF = 1e15;
const ll LL_MAX = 9223372036854775807;
const int LOG = 22;
vector<int> DI = {0, 1, -1, 0};
vector<int> DJ = {1, 0, 0, -1};

void solve(){
    string s; cin >> s;
    if(s.size() < 3) {
        cout << "NO\n";
        return;
    }
    string first_num = s.substr(0, 2);
    string sec_num = s.substr(2, s.size() - 2);

    if(stoi(first_num) != 10 || (sec_num[0] == '0' && sec_num.size() > 1) || stoi(sec_num) < 2) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
    }
}

int main(){
    FELLE
    int t; cin >> t;
    while(t--){
        solve();
    }
}