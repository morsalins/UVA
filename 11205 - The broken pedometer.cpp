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
#define MAX 100
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

int P[20];
int a[MAX + 7];
int ones[(1 << 15) + 7];
unsigned int flag[(1 << 10) + 7];

void Set (void)
{
    P[0] = 1;
    for (int i = 1; i <= 16; i++) {
        P[i] = P[i-1] << 1;
    }

    for (int i = 0; i <= (1 << 15); i++) {
        for (int j = 0; j < 16; j++) {
            if (i & (1 << j)) ones[i]++;
        }
    }
    return;
}

bool isON (int tmp)
{
    return flag[tmp >> 5] & (1 << (tmp & 31));
}

int main()
{
    //READ("in.txt");
    //WRITE("out.txt");
    int Case=1;
    int n, m, p, k;
    char dump[2];

    Set();

    int tc; scanf("%d", &tc);

    while (tc--) {
        scanf("%d %d", &p, &n);

        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = 0; j < p; j++) {
                scanf("%d", &k);
                if (k) sum += P[j];
            }
            a[i] = sum;
        }

        int len = P[p];
        int deactive = 0;

        for (unsigned int i = 0; i < len; i++) {
            unsigned int mask = i;
            bool Continue = true;
            SET(flag, 0);
            for (int j = 0; Continue && j < n; j++) {
                int tmp = a[j] & (~mask);
                if (isON(tmp)) {
                    Continue = false;
                }
                flag[tmp >> 5] |= (1 << (tmp & 31));
            }
            if (Continue) {
                deactive = max(deactive, ones[mask]);
            }
        }
        printf("%d\n", p - deactive);
    }
    return 0;
}

