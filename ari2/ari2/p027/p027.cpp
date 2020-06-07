//
//  p027.cpp
//  ari2
//
//  Created by Hiraku Ohno on 2020/06/08.
//  Copyright © 2020 hira. All rights reserved.
//

#include <stdio.h>
#include <algorithm>
#define max std::max
#define min std::min
#define sort std::sort

#include "p027.hpp"

#define MAX_N 1000

static bool binary_search(int);
static void _solveP027(int, int, int* );

static int n, m, *k;

static int kk[MAX_N * MAX_N];

void solveP027() {
    int n1 = 3;
    int m1 = 10;
    int k1[] = {1, 3, 5};

    _solveP027(n1, m1, k1);

    int n2 = 3;
    int m2 = 9;
    int k2[] = {1, 3, 5};

    _solveP027(n2, m2, k2);

}

void _solveP027(int _n, int _m, int *_k) {
    n = _n;
    m = _m;
    k = _k;
    for(int i = 0; i < MAX_N * MAX_N; i++) {
        kk[i] = 0;
    }

    for ( int c = 0; c < n; c++) {
        for (int d = 0; d < n; d++) {
            kk[c * n + d] = k[c] + k[d];
        }
    }

    sort(kk, kk + n * n);

    bool f = false;

    for ( int a = 0; a < n; a++) {
        for(int b = 0; b < n; b++) {
            if(binary_search(m - k[a] - k[b])) {
                f = true;
            }
        }
    }

    if (f) puts("Yes");
    else puts("No");
}

bool binary_search(int x) {

    int l = 0, r = n * n;

    while (r - l >= 1) {
        int i = (l + r) / 2;
        if (kk[i] == x) return true;
        else if (kk[i] < x) l = i + 1;
        else r = i;
    }

    return false;
}
