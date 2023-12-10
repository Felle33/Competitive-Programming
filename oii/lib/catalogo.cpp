#include <set>

using namespace std;

multiset<long long> multi;

void aggiungi(long long int id) {
     multi.insert(id);
}

void togli(long long int id) {
    multi.erase(multi.find(id));
}

int conta(long long int id) {
    return multi.count(id);
}

