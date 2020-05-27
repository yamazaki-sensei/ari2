#include "p026.hpp"
//
//  template.cpp
//  ari2
//
//  Created by Hiraku Ohno on 2020/05/27.
//  Copyright © 2020 hira. All rights reserved.
//

#include <algorithm>
#define max std::max
#define min std::min
#define sort std::sort

int n, m, *k;

bool binary_search(int x) {
    int l = 0, r = n;

    while (r - l >= 1) {
        int i = (l + r) / 2;
        if (k[i] == x) return true;
        else if (k[i] < x) l = i + 1;
        else r = i;
    }

    return false;
}

void _solveP026(int _n, int _m, int _k[]) {
    n = _n;
    m = _m;
    k = _k;
    sort(k, k + n);

    bool f = false;

    for (int a = 0; a < n; a++) {
        for (int b = 0; b < n; b++) {
            for (int c = 0; c < n; c++) {
                if (binary_search(m - k[a] - k[b] - k[c])) {
                    f = true;
                }
            }
        }
    }

    if (f) puts("Yes");
    else puts("No");
}

void solveP026() {
    int n1 = 3;
    int m1 = 10;
    int k1[] = {1, 3, 5};
    _solveP026(n1, m1, k1);

    int n2 = 3;
    int m2 = 9;
    int k2[] = {1, 3, 5};
    _solveP026(n2, m2, k2);
}

#include <stdio.h>
