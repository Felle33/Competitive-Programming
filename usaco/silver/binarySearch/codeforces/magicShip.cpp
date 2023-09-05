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

int startX, startY, finishX, finishY;
int daysWind;
string wind;
// 0 -> left
// 1 -> right
// 2 -> up
// 3 -> down
vector<int> windDirections(4);

bool good(int days){
    
}

void solve(){
    cin >> startX >> startY >> finishX >> finishY;
    cin >> daysWind >> wind;

    ll l = -1, r = 2e15;

    while(l + 1 < r) {
        ll mid = l + (r - l) / 2;

        if(good(mid)) {
            r = mid;
        } else {
            l = mid;
        }
    }

    if(r == 2e15) r = -1;
    cout << r << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    std::cout.precision(10);
    cout << std::fixed;

    solve();
} 