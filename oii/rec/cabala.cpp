#include <stdio.h>
#include <assert.h>
#include <iostream>

using namespace std;

long long rec(int i, int n, int m, long long num) {
    if(i == n) return num;
    long long lastDigit = (num % 10);
    long long ans = num;
    for(int x = 3; x <= 9; x += 3) {
        if(lastDigit != x) {
            long long res = rec(i + 1, n, m, num * 10 + x);
            if((ans % m) < (res % m)) {
                ans = res;
            }
        }
    }
    return ans;
}

long long occulta(int n, int m) {
    long long ans = 0;
    for(int i = 3; i <= 9; i += 3) {
        long long res = rec(1, n, m, i);
        if((ans % m) < (res % m)) {
            ans = res;
        }
    }

    return ans % m;
}


int main() {
    FILE *fr, *fw;
    int T, N, M, i;

    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
    fscanf(fr, "%d\n", &T);
    for (i=0; i<T; i++) {
        fscanf(fr, "%d %d\n", &N, &M);
        fprintf(fw, "%lld ", occulta(N, M));
    }

    fprintf(fw, "\n");
    fclose(fr);
    fclose(fw);
    return 0;
}