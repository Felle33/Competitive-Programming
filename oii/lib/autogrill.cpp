#include <set>
#include <math.h>

using namespace std;

set<long long> andata, ritorno;

void inizia() {
    
}

void apri(long long p) {
    andata.insert(p);
    ritorno.insert(-p);
}

void chiudi(long long p) {
    andata.erase(p);
    ritorno.erase(-p);
}

long long chiedi(long long p) {
    auto it_a = andata.lower_bound(p);
    auto it_b = ritorno.lower_bound(-p);
    if(it_a == andata.end() && it_b == ritorno.end()) return -1;
    if(it_a == andata.end()) return -(*it_b);
    if(it_b == ritorno.end()) return (*it_a);

    long long ans1 = *it_a;
    long long ans2 = -(*it_b);
    return abs(p - ans1) <= abs(p - ans2) ? ans1 : ans2;
}
