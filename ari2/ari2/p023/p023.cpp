//
//  p023.cpp
//  ari2
//
//  Created by Hiraku Ohno on 2020/05/27.
//  Copyright © 2020 hira. All rights reserved.
//

#include "p021.hpp"
#include <algorithm>
#define max std::max
#define min std::min

void solve(int L, int n, int x[]) {

    int minT = 0;
    for (int i = 0; i < n; i++) {
        minT = max(minT, min(x[i], L - x[i]));
    }

    int maxT = 0;
    for (int i = 0; i < n; i++) {
        maxT = max(maxT, max(x[i], L - x[i]));
    }

    printf("%d %d\n", minT, maxT);
}

void solveP023() {
    int x[] = { 2, 6, 7};
    solve(10, 3, x);
}

