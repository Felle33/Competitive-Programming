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

struct Person {
    ll pos;
    ll speed;
};

vector<Person> people;

bool good(double time){
    double l = people[0].pos - time * people[0].speed;
    double r = people[0].pos + time * people[0].speed;

    for(int i = 1; i < (int) people.size() && l <= r; i++){
        l = max(l, people[i].pos - time * people[i].speed);
        r = min(r, people[i].pos + time * people[i].speed);
    }

    return l <= r;
}

void solve(){
    int n;
    cin >> n;

    people.resize(n);

    for(int i = 0; i < n; i++){
        cin >> people[i].pos >> people[i].speed;
    }

    double l = 0, r = 1;

    while(!good(r)) r *= 2;

    for(int i = 0; i < 100; i++){
        double mid = l + (r - l) / 2;

        bool res = good(mid);
        if(abs(r - l) <= 1e-6 && res){
            break;
        }
        else if(res){
            r = mid;
        }
        else{
            l = mid;
        }
    }
    
    cout << setprecision(10) << r << '\n';
}

int main(){
    /* freopen("lifeguards.in", "r", stdin);
	freopen("lifeguards.out", "w", stdout); */
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
} 