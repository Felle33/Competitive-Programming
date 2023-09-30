#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define vll vector<long long>
#define pi pair<int,int>

struct SegmentTree {
    int size;
    vector<ll> tree, op;

    ll NEUTRAL_ELEMENT = 0;
    ll NOP = LLONG_MAX;

    SegmentTree(int n) {
        size = 1;
        while(size < n) size *= 2;
        tree.resize(2 * size, NEUTRAL_ELEMENT);
        op.resize(2 * size, NOP);
    }

    void build(vector<ll>& numbers){
        build(numbers, 0, 0, size);
    }

    void build(vector<ll>& numbers, int x, int lx, int rx) {
        if(rx - lx == 1) {
            if(lx < (int) numbers.size()) {
                tree[x] = numbers[lx];
            }
            return;
        }

        int mid = (lx + rx) / 2;
        build(numbers, 2 * x + 1, lx, mid);
        build(numbers, 2 * x + 2, mid, rx);
        tree[x] = tree[2 * x + 1] + tree[2 * x + 2];
    }

    void propagate(int x, int lx, int rx) {
        if(op[x] == NOP || rx - lx == 1) return;
        int mid = (rx + lx) / 2;
        tree[2 * x + 1] += op[x] * (mid - lx);
        tree[2 * x + 2] += op[x] * (rx - mid);
        op[2 * x + 1] = (op[2 * x + 1] == NOP ? op[x] : op[2 * x + 1] + op[x]);
        op[2 * x + 2] = (op[2 * x + 2] == NOP ? op[x] : op[2 * x + 2] + op[x]);
        op[x] = NOP;
    }

    void add(int l_query, int r_query, ll v, int x, int lx, int rx) {
        propagate(x, lx, rx);
        if(l_query >= rx || r_query <= lx) return;
        if(l_query <= lx && rx <= r_query){
            tree[x] += (rx - lx) * v;
            op[x] = (op[x] == NOP ? v : op[x] + v);
            return;
        }

        int m = (lx + rx) / 2;
        add(l_query, r_query, v, 2 * x + 1, lx, m);
        add(l_query, r_query, v, 2 * x + 2, m, rx);
        tree[x] = tree[2 * x + 1] + tree[2 * x + 2];
    }

    void add(int l_query, int r_query, ll v) {
        add(l_query, r_query, v, 0, 0, size);
    }

    ll sum(int l_query, int r_query, int x, int lx, int rx) {
        propagate(x, lx, rx);
        if(l_query >= rx || r_query <= lx) return NEUTRAL_ELEMENT;
        if(l_query <= lx && rx <= r_query) return tree[x];
        int mid = (lx + rx) / 2;
        ll s1 = sum(l_query, r_query, 2 * x + 1, lx, mid);
        ll s2 = sum(l_query, r_query, 2 * x + 2, mid, rx);
        return s1 + s2;
    }

    ll sum(int l, int r) {
        return sum(l, r, 0, 0, size);
    }
};
 
int main(){

}