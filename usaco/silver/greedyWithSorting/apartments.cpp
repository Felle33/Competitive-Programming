#include <algorithm>
#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
#include <cstring>
#include <unordered_map>
#include <map>
#include <set>

#define all(x) (x).begin(), (x).end()

typedef long long ll;
using namespace std;

void solve(){
    int n, m, x;
    cin >> n >> m >> x;

    vector<int> desire(n), apart(m);
    for(int i = 0; i < n; i++){
        cin >> desire[i];
    }

    for(int i = 0; i < m; i++){
        cin >> apart[i];
    }

    sort(all(desire));
    sort(all(apart));

    int ans = 0;
    for(int i = 0, j = 0; i < n && j < m;){
        if(desire[i] - x <= apart[j] && apart[j] <= desire[i] + x){
            ans++;
            j++;
            i++;
        } else if(desire[i] > apart[j]){
            j++;
        } else {
            i++;
        }
    }

    cout << ans << '\n';
    
}

int main(){
    /* freopen("div7.in", "r", stdin);
	freopen("div7.out", "w", stdout); */
    solve();
} 