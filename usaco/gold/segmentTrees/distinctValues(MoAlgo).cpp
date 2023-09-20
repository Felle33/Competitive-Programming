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
#include <array>

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

struct Query {
    int id;
    int left, right;
};

int radn;
int distinct;
vi freq;

void computeRad(int n) {
    int l = 1, r = n;
    while(l + 1 < r) {
        int mid = l + (r - l) / 2;
        if(mid * mid < n) {
            l = mid;
        } else {
            r = mid;
        }
    }
    radn = l;
}

bool cmp(Query& a, Query& b) {
    if((a.left / radn != b.left / radn)) return (a.left / radn < b.left / radn);
    return a.right < b.right;
}

void insert(int x) {
    if(freq[x] == 0) distinct++;
    freq[x]++;
}

void erase(int x) {
    freq[x]--;
    if(freq[x] == 0) distinct--;
}

void solve(){
    int n, q; cin >> n >> q;
    vi a(n);
    rep(i, n) cin >> a[i];
    vector<Query> queries(q);
    rep(i, q) {
        int a, b;
        cin >> a >> b;
        a--;
        Query que = {i, a, b};
        queries[i] = que;
    }

    computeRad(n);
    sort(all(queries), cmp);

    vi copy = a;
    sort(all(copy));
    unordered_map<int, int> com;
    for(int i = 0, k = 1; i < n; i++) {
        if(com.count(a[i]) == 0) {
            com[a[i]] = k++;
        }
    }

    freq = vi(com.size() + 1);
    
    int left = 0, right = 0;
    vi ans(q);
    for(const Query& query : queries) {
        int leftQuery = query.left;
        int rightQuery = query.right;

        while(right < rightQuery) {
            insert(com[a[right]]);
            right++;
        }

        while(right > rightQuery) {
            right--;
            erase(com[a[right]]);
        }

        while(left < leftQuery) {
            erase(com[a[left]]);
            left++;
        }

        while(left > leftQuery) {
            left--;
            insert(com[a[left]]);
        }

        ans[query.id] = distinct;
    }

    for(int x : ans) cout << x << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    std::cout.precision(10);
    cout << std::fixed;

    //freopen("sleepy.in", "r", stdin);
	//freopen("sleepy.out", "w", stdout);

    solve();
    
}