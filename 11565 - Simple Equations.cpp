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

bool equalA (int a, int i, int j, int k)
{
    return a == i + j + k;
}

bool equalB (int b, int i, int j, int k)
{
    return b == i * j * k;
}

bool equalC (int c, int i, int j, int k)
{
    return c == i*i + j*j + k*k;
}

bool isDistinct (int i, int j, int k)
{
    return i != j && j != k && k != i;
}

int main()
{
    //READ("in.txt");
    //WRITE("out.txt");
    int Case=1;
    char dump[2];

    int tc; scanf("%d", &tc);

    while (tc--) {
        int a, b, c;
        int x, y, z;

        scanf("%d %d %d", &a, &b, &c);
        bool possible = false;

        for (int i = -100; i <= 100; i++) {
            for (int j = -100; j <= 100; j++) {
                for (int k = -100; k <= 100; k++) {
                    if (isDistinct(i, j, k) && equalA(a, i, j, k) && equalB(b, i, j, k) && equalC(c, i, j, k)) {
                        if (!possible) {
                            printf("%d %d %d\n", i, j, k);
                            possible = true;
                        }
                    }
                }
            }
        }
        if (!possible) {
            printf("No solution.\n");
        }
    }
    return 0;
}

