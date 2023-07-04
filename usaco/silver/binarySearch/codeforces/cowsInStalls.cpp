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

int n, k;
vector<int> stalls;

bool good(int distance){
    int cowsArranged = 1;
    int lastCow = 0;

    for(int i = 1; i < n; i++){
        while(abs(stalls[i] - stalls[lastCow]) < distance){
            i++;
        }

        if(i < n){
            lastCow = i;
            cowsArranged++;
        }
    }

    return cowsArranged >= k;
}

void solve(){
    cin >> n >> k;
    stalls.resize(n);

    for(int i = 0; i < n; i++){
        cin >> stalls[i];
    }

    int l = 0, r = 1e9 + 1;

    while(l + 1 < r){
        int mid = l + (r - l) / 2;

        if(good(mid)){
            l = mid;
        }
        else{
            r = mid;
        }
    }

    cout << l << '\n';
}

int main(){
    /* freopen("lifeguards.in", "r", stdin);
	freopen("lifeguards.out", "w", stdout); */
    solve();
} 