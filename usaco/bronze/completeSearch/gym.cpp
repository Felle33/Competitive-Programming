#include <algorithm>
#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
#include <cstring>
#include <unordered_map>

typedef long long ll;
using namespace std;

void solve(){
    int n, k;
    cin >> k >> n;

    vector<vector<int>> cowsScore(n);
    
    for(int i = 0; i < k; i++){
        for(int j = n; j > 0; j--){
            int a;
            cin >> a;
            a--;

            cowsScore[a].push_back(j);
        }
    }

    int ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            bool consistent = true;

            if(cowsScore[i][0] > cowsScore[j][0]){
                int m = 0;
                while(m < k && cowsScore[i][m] > cowsScore[j][m]){
                    m++;
                }

                if(m != k) consistent = false;
            }
            else if(cowsScore[i][0] < cowsScore[j][0]){
                int m = 0;
                while(m < k && cowsScore[i][m] < cowsScore[j][m]){
                    m++;
                }

                if(m != k) consistent = false;
            }
            else{
                consistent = false;
            }

            if(consistent) ans++;
        }
    }

    cout << ans << '\n';
}

int main(){
    freopen("gymnastics.in", "r", stdin);
	freopen("gymnastics.out", "w", stdout);
    solve();
} 