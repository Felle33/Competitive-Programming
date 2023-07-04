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

int n;
vector<int> machines;
int rL, rR;

bool good(double mean){
    vector<double> copy(n - 2);

    for(int i = 1; i < n - 1; i++){
        copy[i - 1] = (double) machines[i] - mean;
    }

    vector<double> pref(n - 1);
    pref[0] = 0;
    for(int i = 1; i < n - 1; i++){
        pref[i] = pref[i - 1] + copy[i - 1];
    }

    for(int i = 0; i < n; i++){

    }
}

void solve(){
    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> machines[i];
    }

    double l = 0, r = 1e9 + 1;

    for(int i = 0; i < 100; i++){
        double mid = l + (r - l) / 2;
        if(good(mid)){
            l = mid;
        }
        else{
            r = mid;
        }
    }
    
}

int main(){
    /* freopen("sabotage.in", "r", stdin);
	freopen("sabotage.out", "w", stdout); */
    solve();
} 