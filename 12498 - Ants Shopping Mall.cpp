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
#define MAX 55
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

int a[MAX][MAX];
bool flag[MAX];

int main()
{
    //READ("in.txt");
    //WRITE("out.txt");
    int Case=1;
    int R, C;
    char dump[2], line[MAX];

    int tc; scanf("%d", &tc);

    while (tc--) {
        bool possible = true;
        vector <int> zeros;
        SET(flag, false);

        scanf("%d %d", &R, &C);
        gets(dump);

        for (int i = 0; i < R; i++) {
            bool noZero = true;
            gets(line);
            for (int j = 0; line[j] != '\0'; j++) {
                a[i][j] = line[j] - '0';
                if (a[i][j] == 0) {
                    noZero = false;
                    if (!flag[j]) {
                        flag[j] = true;
                        zeros.push_back(j);
                    }
                }
            }
            if (noZero) possible = false;
        }

        int ans = INF;
        sort(zeros.begin(), zeros.end());

        if (possible) {
            for (int pos = 0; pos < zeros.size(); pos++) {
                int cost = 0;
                for (int i = 0; i < R; i++) {
                    int nearest = INF;
                    for (int j = 0; j < C; j++) {
                        if (a[i][j] == 0) {
                            nearest = min(nearest, abs(zeros[pos]-j));
                        }
                    }
                    cost += nearest;
                }
                ans = min(ans, cost);
            }
        }

        if (!possible) ans = -1;
        printf("Case %d: %d\n", Case++, ans);
    }
    return 0;
}
