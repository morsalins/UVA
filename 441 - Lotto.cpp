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

int main()
{
    //READ("in.txt");
    //WRITE("out.txt");
    int Case=1, n;
    char dump[2];

    while (scanf("%d", &n) == 1) {
        if (n == 0) return 0;

        int arr[10];

        for (int i = 1; i <= n; i++) {
            scanf("%d", &arr[i]);

        }

        if (Case > 1) puts("");
        Case++;

        for (int a = 1; a <= n - 5; a++) {
            for (int b = a + 1; b <= n - 4; b++) {
                for (int c = b + 1; c <= n - 3; c++) {
                    for (int d = c + 1; d <= n - 2; d++) {
                        for (int e = d + 1; e <= n - 1; e++) {
                            for (int f = e + 1; f <= n; f++) {
                                printf("%d %d %d %d %d %d\n", arr[a], arr[b], arr[c], arr[d], arr[e], arr[f]);
                            }
                        }
                    }
                }
            }
        }
    }
    return 0;
}

