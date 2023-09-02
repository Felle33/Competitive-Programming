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
#define mp make_pair
#define pb push_back
#define rep(X,Y) for (int (X) = 0;(X) < (Y);++(X))
#define reps(X,S,Y) for (int (X) = S;(X) < (Y);++(X))

using namespace std;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<unsigned long long> vull;
typedef vector<vector<int>> vvi;
typedef long long ll;
typedef pair<int,int> pii;

const ll MOD = 1e9 + 7;
const ll DIM = 1e6;
const ll INF = 1e15;
vector<int> DX = {0, 1, -1, 0};
vector<int> DY = {1, 0, 0, -1};
string DIR = "RDUL";

ll breadIn, sausageIn, cheeseIn;
ll priceBread, priceSaus, priceCheese;
ll money;
ll breadToMakeHam = 0, sausToMakeHam = 0, cheeseToMakeHam = 0;

bool good(ll hamToMake) {
    ll totalBread = breadToMakeHam * hamToMake;
    ll totalSaus = sausToMakeHam * hamToMake;
    ll totalCheese = cheeseToMakeHam * hamToMake;

    ll breadToBuy = totalBread - breadIn;
    ll sausToBuy = totalSaus - sausageIn;
    ll cheeseToBuy = totalCheese - cheeseIn;

    ll cost = 0;
    if(breadToBuy > 0) cost += priceBread * breadToBuy;
    if(sausToBuy > 0) cost += priceSaus * sausToBuy;
    if(cheeseToBuy > 0) cost += priceCheese * cheeseToBuy;

    return cost <= money;
}

void solve(){
    string recipe;
    cin >> recipe;
    cin >> breadIn >> sausageIn >> cheeseIn >> priceBread >> priceSaus >> priceCheese >> money;

    for(char c : recipe) {
        if(c == 'B') breadToMakeHam++;
        else if(c == 'S') sausToMakeHam++;
        else cheeseToMakeHam++;
    }

    ll l = 0, r = 1;
    while(good(r)) r *= 2;
    
    while(l + 1 < r) {
        ll mid = l + (r - l) / 2;

        if(good(mid)) {
            l = mid;
        } else {
            r = mid;
        }
    }

    cout << l << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    std::cout.precision(10);
    cout << std::fixed;

    solve();
}