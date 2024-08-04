#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define vll vector<long long>
#define pi pair<int,int>

/*
IMPORTANT: the first position of BIT is 1 because otherwise the update won't work
if I start from 0
*/
struct BIT {
    int n;
    vector<int> fenwick;

    BIT(int _n) {
        n = _n + lsb(_n) + 1;
        fenwick = vector<int>(n);
    }

    int lsb(int pos) {
        return pos & -pos;
    }

    // ATTENTION if pos == 0 => it won't work
    void update(int pos, int val) {
        while(pos <= n) {
            fenwick[pos] += val;
            pos += lsb(pos);
        }
    }

    // SUM [1, pos]
    int query(int pos) {
        int sum = 0;
        while(pos > 0) {
            sum += fenwick[pos];
            pos -= lsb(pos);
        }
        return sum;
    }

    // SUM [left, right]
    int interval_query(int left, int right) {
        int right_sum = query(right);
        int left_sum = (left - 1 == 0 ? 0 : query(left - 1));
        return right_sum - left_sum;
    }
};
