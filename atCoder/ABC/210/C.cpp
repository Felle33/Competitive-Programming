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
#define mp make_pair
#define rep(X,Y) for (int (X) = 0;(X) < (Y);++(X))
#define reps(X,S,Y) for (int (X) = S;(X) < (Y);++(X))

using namespace std;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<unsigned long long> vull;
typedef long long ll;
typedef pair<int,int> pii;

const ll MOD = 1e9 + 7;
const ll DIM = 1e6;
const ll INF = 1e9;
vector<int> DX = {0, 1, -1, 0};
vector<int> DY = {1, 0, 0, -1};
string DIR = "RDUL";

void solve(){
    int n, k;
    cin >> n >> k;
    vi candies(n);
    rep(i, n) {
        cin >> candies[i];
    }

    map<int, int> mapVariety;
    int ans = 0;
    int variety = 0;
    rep(i, n) {
        if(i >= k) {
            ans = max(ans, variety);
            // erase
            mapVariety[candies[i - k]]--;
            if(mapVariety[candies[i - k]] == 0) {
                variety--;
            }
        }

        if(mapVariety[candies[i]] == 0) {
            variety++;
        }
        mapVariety[candies[i]]++;
    }
    ans = max(ans, variety);

    cout << ans << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
}