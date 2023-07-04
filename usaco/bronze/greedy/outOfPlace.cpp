#include <algorithm>
#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
#include <cstring>
#include <unordered_map>
#include <map>
#include <set>

typedef long long ll;
using namespace std;

void solve(){
    int n;
    cin >> n;

    vector<int> cows(n);

    for(int i = 0; i < n; i++){
        cin >> cows[i];
    }

    vector<int> cowsSorted(cows);
    sort(cowsSorted.begin(), cowsSorted.end());

    int diff = 0;
    for(int i = 0; i < n; i++){
        if(cows[i] != cowsSorted[i]){
            diff++;
        }
    }

    if(diff != 0){
        cout << diff - 1 << '\n';
    }
    else{
        cout << 0 << '\n';
    }
}

int main(){
    freopen("outofplace.in", "r", stdin);
	freopen("outofplace.out", "w", stdout);
    solve();
} 