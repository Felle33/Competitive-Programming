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

const ll MOD1 = 1e9 + 7;
const ll MOD2 = 998244353;
const ll MOD3 = 99999999999999997;
const ll DIM = 1e6;
const ll INF = 1e15;
const int INF_INT = 1e9;
const ll LL_MAX = 9223372036854775807;
const int LOG = 22;
vector<int> DX = {0, 1, -1, 0};
vector<int> DY = {1, 0, 0, -1};
string DIR = "RDUL";

void solve(){
    int n; cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    sort(all(a));

    multiset<int> nums;
    for(int i = 0; i < n; ) {
        int num = a[i];
        int j = i;
        while(j < n && a[j] == num) j++;
        nums.insert(j - i);
        i = j;
    }

    int ans = 0;
    for(int start = 1; start <= 2e5; start++) {
        vector<int> buffer;
        int cnt = start;
        int curAns = 0;

        while(1) {
            auto it = nums.lower_bound(cnt);
            if(it == nums.end()) break;
            curAns += cnt;
            cnt *= 2;
            buffer.push_back(*it);
            nums.erase(it);
        }

        ans = max(ans, curAns);
        for(int x : buffer) nums.insert(x);
    }

    cout << ans << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    std::cout.precision(10);
    cout << std::fixed;

    solve();
}