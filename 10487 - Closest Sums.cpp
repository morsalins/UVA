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
#define MAX 1000
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

int a[MAX + 7];
int v[(MAX / 2) * MAX];

int main()
{
    //READ("in.txt");
    //WRITE("out.txt");
    int Case=1;
    int n, m, k;
    char dump[2];

    //int tc; scanf("%d", &tc);

    while (scanf("%d", &n) == 1 && n != 0) {
        int len = 0;

        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
            for (int j = 0; j < i; j++) {
                v[len++] = a[i] + a[j];
            }
        }

        sort(v, v + len);
        scanf("%d", &m);
        int ans;

        printf("Case %d:\n", Case++);

        for (int q = 1; q <= m; q++) {
            scanf("%d", &k);
            int pos = lower_bound(v, v + len, k) - v;
            if (pos == len) {
                ans = v[len - 1];
            }
            else if (pos == 0) {
                ans = v[0];
            }
            else {
                if (abs(v[pos] - k) <= abs(v[pos-1] - k)) ans = v[pos];
                else ans = v[pos - 1];
            }
            printf("Closest sum to %d is %d.\n", k, ans);
        }
    }

    return 0;
}

