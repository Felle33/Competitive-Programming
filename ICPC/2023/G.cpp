#include <algorithm>
#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
#include <cstring>
#include <map>
#include <set>
#include <iomanip>
#include <bitset>

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
const ll LL_MAX = 9223372036854775807;
vector<int> DX = {0, 1, -1, 0};
vector<int> DY = {1, 0, 0, -1};
string DIR = "RDUL";

void solve(){
    ll row, col;
    cin >> col >> row;

    ll train_row, train_col, fil_row, fil_col;
    cin >> train_col >> train_row >> fil_col >> fil_row;

    // 0 -> left
    // 1 -> up
    // 2 -> right
    // 3 -> down
    vll time(4); //distanza di FILIPPO dal bordo

    time[0] = fil_col; //left
    time[1] = row - fil_row; //up
    time[2] = col - fil_col; //right
    time[3] = fil_row; //down

    ll ans = 0;

    ll train_time;//distanza del treno da ogni punto di intersezione di W

    if((train_col >= fil_col) && (train_row > fil_row)){ //settore in alto a dx

        train_time = (col - train_col) + (row - fil_row);
        if(time[2] <= train_time){ //se fa in tempo
            ans = train_time;
        }
        else
        {
            ans = train_time + fil_row + (col - fil_col);
        }

    } else if((train_col > fil_col) && (train_row <= fil_row)){ //settore in basso a dx
        train_time = train_row + (train_col - fil_col);

        if(time[3] <= train_time){ //se fa in tempo
            ans = train_time;
        }
        else
        {
            ans = train_time + fil_col + fil_row;
        }

    } else if((train_col <= fil_col) && (train_row < fil_row)){ //settore in basso a sx
        train_time = train_col + fil_row;

        if(time[0] <= train_time){ //se fa in tempo
            ans = train_time;
        }
        else
        {
            ans = train_time + (row - fil_row) + fil_col;
        }
    

    } else if((train_col < fil_col) && (train_row >= fil_row)){//settore in alto a sx
        train_time = (row - train_row) + fil_col;

        if(time[1] <= train_time){ //se fa in tempo
            ans = train_time;
        }
        else
        {
            ans = train_time + (col - fil_col) + (row - fil_row);
        }
    }
    
    cout << ans << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    std::cout.precision(10);
    cout << std::fixed;

    int t;
    cin >> t;

    while(t--){
        solve();
    }
}