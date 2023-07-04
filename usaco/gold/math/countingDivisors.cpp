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

const int DIM = 1e5 + 1;
const ll inf = 1e12;

int numDivisors(int x){
    int i = 1;
    int res = 0;
    for(; i * i < x; i++){
        if(x % i == 0) res += 2;
    }

    return res + (i * i == x);
}

void solve(){
    int n;
    cin >> n;

    while(n--){
        int x;
        cin >> x;

        cout << numDivisors(x) << '\n';
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    /* freopen("lifeguards.in", "r", stdin);
	freopen("lifeguards.out", "w", stdout); */
    solve();
} 