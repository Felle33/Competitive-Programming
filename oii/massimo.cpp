#include <vector>
using namespace std;

int trova_massimo(int n, vector<int> a) {
    int m = -1e9;
    for(int i = 0; i < n; i++) {
        m = std::max(m, a[i]);
    }

    return m;
}
