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

double sq(double x){
    double l = 0, r = x;
    for(int i = 0; i < 100; i++){
        double mid = l + (r - l) / 2;
        double res = mid * mid;

        if(abs(res - x) <= 1e-6){
            return mid;
        }
        else if(res > x){
            r = mid;
        }
        else{
            l = mid;
        }
    }

    return -1;
}

void solve(){
    double c;
    cin >> c;

    double l = 0, r = 1e11;

    for(int i = 0; i < 100; i++){
        double mid = l + (r - l) / 2;

        double res = mid * mid + sq(mid);
        if(abs(res - c) <= 1e-6){
            cout << setprecision(10) << mid << '\n';
            break;
        }
        else if(res > c){
            r = mid;
        }
        else{
            l = mid;
        }
    }

}

int main(){
    /* freopen("lifeguards.in", "r", stdin);
	freopen("lifeguards.out", "w", stdout); */
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
} 