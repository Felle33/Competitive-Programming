#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int &x: a){
        cin >> x;
    }

    int risposta = a[0];
    for(int i = 1; i < n; i++) {
        risposta = lcm(risposta, a[i]);
    }

    return risposta;
}

int main(){
    freopen("caramelle_input.txt", "r", stdin);
    freopen("caramelle_output.txt", "w", stdout);

    int T;
    cin >> T;
    for (int i = 0; i < T; i++){
        cout << "Case #" << i+1 << ": " << solve() << endl;
    }
    return 0;
}