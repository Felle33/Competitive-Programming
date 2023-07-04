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

vector<int> haybales;
int n, m, c;

bool good(int time){
    int numBusses = 1;
    int size = 1;
    int waitingMax = 0;

    for(int i = 1; i < n;){
        if(waitingMax + (haybales[i] - haybales[i - 1]) <= time){
            waitingMax += haybales[i] - haybales[i - 1];
            size++;

            if(i < n - 1 && size == c){
                numBusses++;
                size = 1;
                waitingMax = 0;
                i += 2;
            }
            else{
                i++;
            }
        }
        else{
            numBusses++;
            size = 1;
            waitingMax = 0;
            i++;
        }
    }

    return numBusses <= m;
}

void solve(){
    
    cin >> n >> m >> c;

    haybales.resize(n);

    for(int i = 0; i < n; i++){
        cin >> haybales[i];
    }

    sort(all(haybales));
    int l = 0, r = 1;

    while(!good(r)) r *= 2;

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
    freopen("convention.in", "r", stdin);
	freopen("convention.out", "w", stdout);
    solve();
} 