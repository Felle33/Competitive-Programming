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
const int INF = 1e9;
const ll LLINF = 1e15;
const int INF_INT = 1e9;
const ll LL_MAX = 9223372036854775807;
const int LOG = 22;
vector<int> DX = {0, 1, -1, 0};
vector<int> DY = {1, 0, 0, -1};

int findIndex(vector<int>& lis, int num) {
    int l = -1, r = lis.size();

    while(l + 1 < r) {
        int m = l + (r - l) / 2;

        if(lis[m] < num) l = m;
        else r = m;
    }

    return r;
}

int main(){
    //freopen("catch.in", "r", stdin);
	//freopen("catch.out", "w", stdout);
    string line; getline(cin, line);
    int t = stoi(line);
    getline(cin, line);
    int startT = t;
    while(t) {
        vi a;
        while(1) {
            string line;
            getline(cin, line);

            if (!line.empty()){
                a.pb(stoi(line));
            } else break;
        }

        int n = a.size();
        vi lis, idxLis, parents(n);

        for(int i = 0; i < n; i++) {
            int x = a[i];
            if(lis.empty() || lis.back() < x) {
                if(lis.empty()) {
                    parents[i] = -1;
                } else {
                    parents[i] = idxLis.back();
                }

                lis.pb(x);
                idxLis.pb(i);
            } else {
                int idx = findIndex(lis, x);
                lis[idx] = x;
                idxLis[idx] = i;
                parents[i] = (idx == 0 ? -1 : idxLis[idx - 1]);
            }
        }

        if(t < startT) cout << '\n';
        cout << "Max hits: " << lis.size() << '\n';
        vi ans;

        int p = idxLis[idxLis.size() - 1];
        while(p != -1) {
            ans.pb(a[p]);
            p = parents[p];
        }
        
        for(int i = ans.size() - 1; i >= 0; i--) {
            cout << ans[i] << '\n';
        }

        t--;
    }
}