#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>
#include <functional>
#include <iterator>
#include <map>
#include <numeric>
#include <cstring>
#include <string>
#include <sstream>
#include <set>
#include <stack>
#include <queue>
#include <cctype>
#include <math.h>
#include <cstdlib>

using namespace std;

#define I64 long long int
#define INF 0x7f7f7f7f
#define SIZE 1000
#define MAX 20
#define EPS 1e-9
#define PI 2*acos(0.0)

#define PII pair <int, int>
#define PLL pair <I64, I64>
#define PDD pair <double, double>
#define PSI pair <string, int>
#define PIS pair <int, string>
#define PSS pair <string string>

#define MII map <int, int>
#define MLL map <I64, I64>
#define MDD map <double, double>
#define MSI map <string, int>
#define MIS map <int, string>
#define MSS map <string string>

#define VI vector <int>
#define VS vector <string>
#define QI queue <int>
#define QS queue <string>
#define SI stack <int>
#define SS stack <string>

#define pb push_back
#define pob pop_back
#define mp make_pair

#define IT iterator
#define ff first
#define ss second

#define SET(a, b) memset( a, b, sizeof (a) )
#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)

#define IAMHERE cout << "YES\n";
#define DEBUG(a, b) cout << a << ": " << b << "\n";

int costT[MAX + 5], costR[MAX + 5], costH[MAX + 5];

int main()
{
    //READ("in.txt");
    //WRITE("out.txt");
    int Case=1;
    int t, r, h;
    char dump[2];

    //int tc; scanf("%d", &tc);

    while (scanf("%d %d %d", &t, &r, &h) == 3) {
        vector <int> travel[MAX + 5], rest[MAX + 5];
        bool hotel[MAX + 5][MAX + 5];
        int combined;

        for (int i = 0; i < t; i++) {
            scanf("%d", &costT[i]);
            for (int j = 0; j < r; j++) {
                scanf("%d", &combined);
                if (combined == 0) {
                    travel[i].push_back(j);
                }
            }
        }

        for (int i = 0; i < r; i++) {
            scanf("%d", &costR[i]);
            for (int j = 0; j < h; j++) {
                scanf("%d", &combined);
                if (combined == 0) {
                    rest[i].push_back(j);
                }
            }
        }

        for (int i = 0; i < h; i++) {
            scanf("%d", &costH[i]);
            for (int j = 0; j < t; j++) {
                scanf("%d", &combined);
                hotel[i][j] = (combined == 0);
            }
        }

        bool possible = false;
        int minCost = (1 << 31) - 1;
        int _t, _r, _h;

        for (int i = 0; i < t; i++) {
            for (int j = 0; j < travel[i].size(); j++) {
                for (int k = 0; k < rest[travel[i][j]].size(); k++) {
                    if (hotel[rest[travel[i][j]][k]][i]) {
                        if (minCost > costT[i] + costR[travel[i][j]] + costH[rest[travel[i][j]][k]]) {
                            minCost = costT[i] + costR[travel[i][j]] + costH[rest[travel[i][j]][k]];
                            _t = i;
                            _r = travel[i][j];
                            _h = rest[travel[i][j]][k];
                            possible = true;
                        }
                    }
                }
            }
        }
        if (possible) printf("%d %d %d:%d\n", _t, _r, _h, minCost);
        else printf("Don't get married!\n");
    }
    return 0;
}
