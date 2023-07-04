#include <algorithm>
#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
#include <cstring>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include <stack>

#define all(x) (x).begin(), (x).end()

typedef long long ll;
using namespace std;

void solve(){
    int n, m;
    cin >> n >> m;
    multiset<int> tickets;

    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        tickets.insert(-x);
    }

    for(int i = 0; i < m; i++){
        int t;
        cin >> t;

        t = -t;
        auto it = tickets.lower_bound(t);

        if(it != tickets.end()){
            cout << -(*it) << " ";
            tickets.erase(it);
        }
        else{
            cout << -1 << " ";
        }
    }
}

int main(){
    /* freopen("bcount.in", "r", stdin);
	freopen("bcount.out", "w", stdout); */
    solve();
} 