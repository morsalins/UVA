#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>

#define PII pair <int, int>
#define I64 long long int
#define INF 0x7f7f7f7f

using namespace std;

int flow[30], cost[30];

int main ()
{
    //freopen("in.txt", "r", stdin);

    int n, tc, Case = 1;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &flow[i], &cost[i]);
    }

    scanf("%d", &tc);

    while (tc--) {
        int f, t;
        scanf("%d %d", &f, &t);
        I64 minCost = INF;
        for (int mask = 0; mask < (1 << n); mask++) {
            I64 cst = 0, flw = 0;
            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    cst += cost[i];
                    flw += flow[i];
                }
            }
            if (flw * t >= f) {
                minCost = min(minCost, cst);
            }
        }
        if (minCost == INF) printf("Case %d: IMPOSSIBLE\n", Case++);
        else printf("Case %d: %lld\n", Case++, minCost);
    }

    return 0;
}
