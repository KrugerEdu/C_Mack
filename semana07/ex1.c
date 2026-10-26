#include <stdio.h>

int busca(int x, int v[], int i, int f) {
    while (i <= f) {
    
        int m = i + (f - i) / 2; 

        if (v[m] == x) {
            return m;
        }

        if (v[m] < x) {
            i = m + 1;
        } else {
            f = m - 1;
        }
    }

    return -1;
}