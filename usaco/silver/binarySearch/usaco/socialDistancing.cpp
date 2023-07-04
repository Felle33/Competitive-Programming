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

struct Interval{
    ll start, end;
};

int n, m;
vector<Interval> intervals;

bool cmp(const Interval& x, const Interval& y){
    return x.start < y.start;
}

bool good(ll distance){
    ll lastCow = intervals[0].start;
    int indexInterval = 0;

    for(int i = 1; i < n; i++){
        while(indexInterval < m && lastCow + distance > intervals[indexInterval].end){
            indexInterval++;
        }

        if(indexInterval < m){
            lastCow = max(lastCow + distance, intervals[indexInterval].start);
        }
        else{
            return false;
        }
    }

    return true;
}

void solve(){
    cin >> n >> m;

    intervals.resize(m);

    for(int i = 0; i < m; i++){
        cin >> intervals[i].start >> intervals[i].end;
    }

    sort(all(intervals), cmp);

    ll l = 1, r = intervals[m - 1].end - intervals[0].start + 1;

    while(l + 1 < r){
        ll mid = l + (r - l) / 2;

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
    freopen("socdist.in", "r", stdin);
	freopen("socdist.out", "w", stdout);
    solve();
} 