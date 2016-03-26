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
#define MAX 2000
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

char grid[110][110];

bool isValid (int r1, int r2, int c1, int c2, int R, int C)
{
    return r1 >= 0 && r2 < R && c1 >= 0 && c2 < C;
}

int main()
{
    //READ("in.txt");
    //WRITE("out.txt");
    int Case=1;
    char dump[2];

    int tc; scanf("%d", &tc);

    while (tc--) {
        int m, n, q;
        scanf("%d %d %d", &m, &n, &q);
        getchar();

        for (int i = 0; i < m; i++) {
            gets(grid[i]);
        }

        printf("%d %d %d\n", m, n, q);

        for (int query = 1; query <= q; query++) {
            int r, c;
            scanf("%d %d", &r, &c);
            char ch = grid[r][c];
            int ans = 1;
            bool Continue = true;

            for (int i = 1; Continue && isValid(r-i, r+i, c-i, c+i, m, n); i++) {
                for (int j = c-i; Continue && j <= c+i; j++) {
                    if (grid[r-i][j] != ch || grid[r+i][j] != ch) {
                        Continue = false;
                    }
                }
                for (int j = r-i; Continue && j <= r+i; j++) {
                    if (grid[j][c-i] != ch || grid[j][c+i] != ch) {
                        Continue = false;
                    }
                }
                if (Continue) ans += 2;
            }
            printf("%d\n", ans);
        }
    }
    return 0;
}
