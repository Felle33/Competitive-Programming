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

vector<double> ropes;
int n, k;

bool good(double x){
    ll res = 0;
    for(int i = 0; i < n; i++){
        res += floor(ropes[i] / x);
    }

    return res >= k;
}

void solve(){
    cin >> n >> k;

    ropes.resize(n);

    for(int i = 0; i < n; i++){
        cin >> ropes[i];
    }

    double l = 0, r = 1;

    while(good(r)) r *= 2;

    for(int i = 0; i < 100; i++){
        double mid = l + (r - l) / 2;

        if(good(mid)){
            l = mid;
        }
        else{
            r = mid;
        }
    }

    cout << setprecision(10) << l << '\n';
}

int main(){
    /* freopen("lifeguards.in", "r", stdin);
	freopen("lifeguards.out", "w", stdout); */
    solve();
} 