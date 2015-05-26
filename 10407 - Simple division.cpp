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

I64 a[MAX + 7], dist[MAX + 7];

I64 GCD (I64 a, I64 b)
{
    if (b == 0) return a;
    else return GCD(b, a%b);
}

int main()
{
    //READ("in.txt");
    //WRITE("out.txt");
    int Case=1;
    int m, n;
    I64 sum;
    char dump[2];

    while (scanf("%d", &n) == 1) {

        if (n == 0) return 0;

        a[0] = n;
        int idx = 0;

        scanf("%d", &n);

        for (int i = 1; n != 0; i++) {
            a[i] = n;
            dist[idx++] = abs(a[i] - a[i-1]);
            scanf("%d", &n);
        }
        //for (int i = 0; i< idx; i++) cout << dist[i] << " "; cout << "\n";
        I64 ans = dist[0];

        for (int i = 1; i < idx; i++) {
            ans  = GCD( max(dist[i], ans), min(dist[i], ans) ); //DEBUG("ans", ans);
        }

        printf("%d\n", ans);
    }
    return 0;
}
