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

string firstWord, secondWord;
vi deletions;
int n;
int m;

bool good(ll mid) {
    vi lettersAv;

    for(int i = mid + 1; i < n; i++) {
        lettersAv.push_back(deletions[i]);
    }

    sort(all(lettersAv));
    string firstWordMod;

    for(int x : lettersAv) {
        firstWordMod += firstWord[x - 1];
    }

    // i = pointer of the firstWordMod
    // j = pointer of the second word
    int k = firstWordMod.size();
    int i = 0, j = 0;
    for(; i < k && j < m;) {
        if(firstWordMod[i] == secondWord[j]) {
            i++, j++;
        } else {
            i++;
        }
    }

    return j == m;
}

void solve(){
    cin >> firstWord >> secondWord;
    n = firstWord.size();
    m = secondWord.size();
    deletions = vi(n);
    rep(i, n) cin >> deletions[i];

    ll l = -1, r = n - 1;

    while(l + 1 < r) {
        ll mid = l + (r - l) / 2;

        if(good(mid)) {
            l = mid;
        } else {
            r = mid;
        }
    }

    cout << r << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    std::cout.precision(10);
    cout << std::fixed;

    solve();
}