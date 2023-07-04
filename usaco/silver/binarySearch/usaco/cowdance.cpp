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

vector<int> cows;
int n, t;

bool good(int k){
    priority_queue<int, vector<int>, greater<int>> priorityCow;

    for(int i = 0; i < k; i++){
        priorityCow.push(cows[i]);
    }

    int j = k;
    int time = 0;

    while(!priorityCow.empty()){
        time = priorityCow.top();
        priorityCow.pop();
        
        if(j < n) priorityCow.push(cows[j++] + time);
    }

    return time <= t;
}

void solve(){
    
    cin >> n >> t;

    cows.resize(n);

    for(int i = 0; i < n; i++){
        cin >> cows[i];
    }

    int l = 0, r = n;
    while(l + 1 < r){
        int mid = l + (r - l) / 2;

        if(good(mid)){
            r = mid;
        }
        else{
            l = mid;
        }
    }

    cout << r << '\n';
}

int main(){
    freopen("cowdance.in", "r", stdin);
	freopen("cowdance.out", "w", stdout);
    solve();
} 