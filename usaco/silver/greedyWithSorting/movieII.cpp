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

struct movie{
    int start;
    int finish;
};

bool cmp(const movie& m1, const movie& m2){
    return m1.finish < m2.finish;
}

// bisogna usare un multiset in modo tale che se un film lo riescono a vedere più di 1 persona
// devo scegliere che lo veda la persona che ha finito di vedere il film al più tardi così dò la possibilità di guardare un film
// anche alla persona che ha finito prima aumentando la possibilità che riesca a vedere un altro film
void solve(){
    int n, k;
    cin >> n >> k;

    vector<movie> movies(n);

    for(int i = 0; i < n; i++){
        cin >> movies[i].start >> movies[i].finish;
    }

    sort(all(movies), cmp);

    int ans = k;
    queue<movie> q;
    for(int i = 0; i < k; i++){
        q.push(movies[i]);
    }

    for(int i = k; i < n; i++){
        movie m = q.front();
        if(movies[i].start >= m.finish){
            ans++;
            q.pop();
            q.push(movies[i]);
        }
    }

    cout << ans << '\n';
}

int main(){
    /* freopen("div7.in", "r", stdin);
	freopen("div7.out", "w", stdout); */
    solve();
} 