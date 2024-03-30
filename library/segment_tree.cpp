#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define vll vector<long long>
#define pi pair<int,int>

/*
    Tested with F.Lorax in basics tree gym SecondThread
*/
template <typename T>
struct SegmentTree {
    int size;
    vector<T> tree;

    T NEUTRAL_ELEMENT = 0;

    SegmentTree(int n) {
        size = 1;
        while(size < n) size *= 2;
        tree.resize(2 * size, NEUTRAL_ELEMENT);
    }

    void add(int i, T v, int x, int lx, int rx) {
        if(rx - lx == 1) {
            tree[x] += v;
            return;
        }

        int m = (lx + rx) / 2;
        if(i < m) {
            add(i, v, 2 * x + 1, lx, m);
        } else {
            add(i, v, 2 * x + 2, m, rx);
        }
        tree[x] = tree[2 * x + 1] + tree[2 * x + 2];
    }

    void add(int i, T v) {
        add(i, v, 0, 0, size);
    }

    // l_query = da dove inizia la query
    // r_query = dove finisce la query non compresa
    // x = nodo
    // lx = dove inizia la zona di competenza del nodo
    // rx = dove finisce la zona di competenza del nodo non compreso
    T sum(int l_query, int r_query, int x, int lx, int rx) {
        if(l_query >= rx || r_query <= lx) return NEUTRAL_ELEMENT;
        if(l_query <= lx && rx <= r_query) return tree[x];
        int mid = (lx + rx) / 2;
        T s1 = sum(l_query, r_query, 2 * x + 1, lx, mid);
        T s2 = sum(l_query, r_query, 2 * x + 2, mid, rx);
        return s1 + s2;
    }

    T sum(int l, int r) {
        return sum(l, r, 0, 0, size);
    }
};
