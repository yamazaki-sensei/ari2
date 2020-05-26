//
//  p021.cpp
//  ari2
//
//  Created by Hiraku Ohno on 2020/05/25.
//  Copyright © 2020 hira. All rights reserved.
//

using namespace std;
#include "p021.hpp"
#include <algorithm>

int solve(int n, int a[]) {
    int ans = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                int len = a[i] + a[j] + a[k];
                int ma = max(a[i], max(a[j], a[k]));

                int rest = len - ma;

                if (ma < rest) {
                    ans = max(ans, len);
                }
            }
        }
    }

    return ans;
}

void solveP021() {
    printf("***** Begin p021 *****\n");
    int a1[] = { 2, 3, 4, 5, 10 };
    int ans1 = solve(5, a1);

    assert(ans1 == 12);
    printf("ans1 = %d\n", ans1);

    int a2[] = { 4, 5, 10, 20 };
    int ans2 = solve(4, a2);
    assert(ans2 == 0);
    printf("ans2 = %d\n", ans2);
    
    printf("***** End p021 *****\n");
}

