//
// Created by aleafall on 16-11-27.
//

#include <iostream>

using namespace std;

int main() {
    int g1, s1, k1, g2, s2, k2;
    scanf("%d.%d.%d %d.%d.%d", &g1, &s1, &k1, &g2, &s2, &k2);
    s1 += (k1 + k2) / 29;
    k1 = (k1 + k2) % 29;
    g1 += (g2 + (s1 + s2) / 17);
    s1 = (s1 + s2) % 17;
    printf("%d.%d.%d\n", g1, s1, k1);
    return 0;
}

