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

typedef long long ll;
using namespace std;

const ll MOD = 1e9 + 7;
const ll DIM = 1e6;
const ll INF = 1e9;
vector<int> DX = {0, 1, -1, 0};
vector<int> DY = {1, 0, 0, -1};
string DIR = "RDUL";

vector<int> heights;
vector<int> parent;
int maximum = 1;

ll area(vector<ll> rect) {
	ll width = rect[2] - rect[0];
	ll height = rect[3] - rect[1];
	return width * height;
}

// return 0 if it doesn't intersect
int inter_area(vector<ll> s1, vector<ll> s2) {
	int bl_a_x = s1[0], bl_a_y = s1[1], tr_a_x = s1[2], tr_a_y = s1[3];
	int bl_b_x = s2[0], bl_b_y = s2[1], tr_b_x = s2[2], tr_b_y = s2[3];

	ll l1 = min(tr_a_x, tr_b_x) - max(bl_a_x, bl_b_x);
	ll l2 = min(tr_a_y, tr_b_y) - max(bl_a_y, bl_b_y);

	if(l1 <= 0 || l2 <= 0) return 0;

	return l1 * l2;
}

// return true if x,y is covered by the rectangle s
bool covered(ll x, ll y, vector<ll> s){
	return x >= s[0] && x <= s[2] && y >= s[1] && y <= s[3];
}

ll exponentiation(ll b, ll e){
    ll res = 1;
    b %= MOD;
    while(e > 0){
        if(e & 1)
            res = res * b % MOD;
        
        b = b * b % MOD;
        e >>= 1;
    }

    return res;
}

int find(int x){
    if(parent[x] != x){
        int res = find(parent[x]);
        return parent[x] = res;
    }
    return x;
}

bool unionD(int a, int b){
    int x = find(a), y = find(b);
    
    if(x == y) return false;

    if(heights[x] > heights[y]){
        parent[y] = x;
        maximum = max(maximum, heights[x] + heights[y]);
        heights[x] = heights[x] + heights[y];
    } else {
        parent[x] = y;
        maximum = max(maximum, heights[x] + heights[y]);
        heights[y] = heights[x] + heights[y];
    }
    return true;
}

void solve(){
    int n, m;
    cin >> n >> m;

    parent.resize(n);
    heights.resize(n);

    for(int i = 0; i < n; i++){
        parent[i] = i;
        heights[i] = 1;
    }

    int numComp = n;
    while(m--){
        int a, b;
        cin >> a >> b;
        a--, b--;

        if(unionD(a, b)){
            numComp--;
        }

        cout << numComp << " " << maximum << '\n';
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
}