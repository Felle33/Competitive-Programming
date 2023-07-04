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
    int n;
    cin >> n;

    vector<int> s(n);
    vector<int> t(n);
    vector<int> b(n);

    for(int i = 0; i < n; i++){
        cin >> s[i] >> t[i] >> b[i];
    }

    int buckets = 0;
    for(int time = 0; time <= 1000; time++){
        int num = 0;
        for(int i = 0; i < n; i++){
            if(s[i] <= time && time <= t[i]){
                num += b[i];
            }
        }
        buckets = max(num, buckets);
    }

    cout << buckets << '\n';
}

int main(){
    freopen("blist.in", "r", stdin);
	freopen("blist.out", "w", stdout);
    solve();
} 