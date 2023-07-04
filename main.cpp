#include <iostream>
#include <algorithm>
#include <vector>
#include <bitset>
using namespace std;

#define all(x) (x).begin(), x.end()

int nxt(){
    int x;
    cin >> x;
    return x;
}

int main(){
    vector<int> a, b, c;

    for(int i = 0; i < 8; i++){
        a.push_back(nxt());
    }

    for(int i = 0; i < 5; i++){
        b.push_back(nxt());
    }

    c.resize(a.size() + b.size());
    sort(all(a));
    sort(all(b));
    merge(all(a), all(b), c.begin());
    c.resize(unique(all(c)) - c.begin());

    for(int i = 0; i < (int) c.size(); i++){
        cout << c[i] << " ";
    }

}