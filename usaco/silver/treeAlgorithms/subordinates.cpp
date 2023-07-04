#include <algorithm>
#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
#include <cstring>
#include <unordered_map>
#include <map>
#include <set>
#include <stack>

#define all(x) (x).begin(), (x).end()

typedef long long ll;
using namespace std;
const int DIM = 2e5 + 1;

vector<int> ans(DIM);
vector<int> graph[DIM];

int numSub(int node){
    int res = 0;

    for(int s : graph[node]){
        res += numSub(s);
    }

    ans[node] = res;
    return res + 1;
}

void solve(){
    int n;
    cin >> n;

    for(int i = 2; i <= n; i++){
        int a;
        cin >> a;
        graph[a].push_back(i);
    }

    numSub(1);

    for(int i = 1; i <= n; i++){
        cout << ans[i] << " ";
    }
}

int main(){
    /* freopen("bcount.in", "r", stdin);
	freopen("bcount.out", "w", stdout); */
    solve();
} 