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

multiset<ll> lower, upper;
ll prefix_low = 0, prefix_up = 0;

void control() {
    if(lower.size() != upper.size() && lower.size() != upper.size() + 1) {
        if(lower.size() > upper.size()) {
            ll x = *lower.rbegin();
            upper.insert(x);
            prefix_up += x;
            lower.erase(--lower.end());
            prefix_low -= x;
        } else {
            ll x = *upper.begin();
            lower.insert(x);
            prefix_low += x;
            upper.erase(upper.begin());
            prefix_up -= x;
        }
    }
}

void insert(int x) {
    if(lower.empty() && upper.empty()) {
        lower.insert(x);
        prefix_low += x;
        return;
    }

    // max di lower è minore di x
    if(*lower.rbegin() < x) {
        upper.insert(x);
        prefix_up += x;
    } else {
        // max di lower è maggiore di x
        lower.insert(x);
        prefix_low += x;
    }

    control();
}

void erase(int x) {
    // max di lower è minore di x
    if(x <= *lower.rbegin()) {
        lower.erase(lower.find(x));
        prefix_low -= x;
    } else {
        // max di lower è maggiore di x
        upper.erase(upper.find(x));
        prefix_up -= x;
    }

    control();
}

void solve(){
    int n, k;
    cin >> n >> k;

    vector<ll> nums(n);
    rep(i, n) {
        cin >> nums[i];
    }

    for(int r = 0, l = 0; r <= n; r++) {
        if(r >= k) {
            ll res;
            if(k % 2 == 0) {
                res = prefix_up - prefix_low;
            } else {
                res = prefix_up - prefix_low + *lower.rbegin();
            }

            cout << res << " ";
            erase(nums[l++]);
        }
        
        if(r < n)
            insert(nums[r]);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    solve();
}