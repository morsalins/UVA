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

void mark (int num, int *f)
{
    while (num > 0) {
        *f |= (1 << (num % 10));
        num = num / 10;
    }
    return;
}

int main()
{
    //READ("in.txt");
    //WRITE("out.txt");
    int Case=1;
    int n;
    char dump[2];

    //int tc; scanf("%d", &tc);

    while (scanf("%d", &n) == 1) {
        if (n == 0) return 0;

        bool solution = false;

        if (Case > 1) puts("");
        Case++;

        for (int i = 1234; i * n <= 98765; i++) {
            int j = i * n;
            int flag = 0;
            if (i < 10000 || j < 10000) flag = 1;
            mark(i, &flag);
            mark(j, &flag);

            if (flag == (1 << 10) - 1) {
                solution = true;
                printf("%.5d / %.5d = %d\n", j, i, n);
            }
        }
        if (!solution) printf("There are no solutions for %d.\n", n);
    }
    return 0;
}

