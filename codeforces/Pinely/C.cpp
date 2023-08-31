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

void solve(){
    int n, k; cin >> n >> k;
    vector<int> a(n);
    vector<bool> present(n + 1);
    rep(i, n) {
        cin >> a[i];
        present[a[i]] = 1;
    }

    int firstMissing;
    rep(i, n + 1) {
        if(!present[i]) {
            firstMissing = i;
            break;
        }
    }

    k = k % (n + 1);
    if(k == 0) {
        for(int x : a) {
            cout << x << ' ';
        }
        cout << '\n';
    } else {
        vector<int> ans(n, -1);
        int index = ((k - 1) % n);
        ans[index] = firstMissing;
        
        for(int i = 0; i < n; i++) {
            int x = a[i];
            index = (i + k);
            
            if(index >= n) {
                index = index - n - 1;
                if(index != -1) {
                    ans[index] = x;
                }
            } else {
                ans[index] = x;
            }       
        }

        for(int x : ans) {
            cout << x << ' ';
        }
        cout << '\n';
    }
    
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