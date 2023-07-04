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
    int n, q;
    cin >> n >> q;

    vector<vector<int>> trees(n + 1, vector<int>(n + 1));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            char c;
            cin >> c;

            trees[i][j] = trees[i][j - 1] + trees[i - 1][j] - trees[i - 1][j - 1];

            if(c == '*'){
                trees[i][j]++;
            }
        }
    }


    for(int i = 0; i < q; i++){
        int y1, x1, y2, x2;
        cin >> y1 >> x1 >> y2 >> x2;

        int res = trees[y2][x2] - trees[y2][x1 - 1] - trees[y1 - 1][x2] + trees[y1 - 1][x1 - 1];
        cout << res << '\n';
    }

}

int main(){
    /* freopen("div7.in", "r", stdin);
	freopen("div7.out", "w", stdout); */
    solve();
} 