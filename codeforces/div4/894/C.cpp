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
    vector<string> grid(10);
    rep(i, 10) cin >> grid[i];

    ll sum = 0;
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            if(grid[i][j] == 'X') {
                ll sum_i = 0;
                ll sum_j = 0;
                if(i < 5) {
                    sum_i = i + 1;
                } else {
                    sum_i = 10 - i;
                }

                if(j < 5) {
                    sum_j = j + 1;
                } else {
                    sum_j = 10 - j;
                }

                sum += min(sum_i, sum_j);
            }
        }
    }

    cout << sum << '\n';
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