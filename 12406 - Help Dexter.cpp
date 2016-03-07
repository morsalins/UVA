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

I64 tens[18];

void Set (void)
{
    tens[0] = 1;
    for (int i = 1; i < 18; i++) {
        tens[i] = 10 * tens[i-1];
    }
    return;
}

int main()
{
    //READ("in.txt");
    //WRITE("out.txt");
    int Case=1;
    int p, q;
    char dump[2];

    Set();

    int tc; scanf("%d", &tc);

    while (tc--) {
        scanf("%d %d", &p, &q);

        I64 ans[2] = {0, 0};

        for (int mask = 0; mask < (1 << p); mask++) {
            I64 num = 0;
            for (int j = 0; j < p; j++) {
                if (mask & (1 << j)) {
                    num += tens[j];
                }
                else {
                    num += tens[j] << 1;
                }
            }
            //DEBUG("num", num);
            if ((num & ((1 << q) - 1)) == 0) {
                if (ans[0] == 0) ans[0] = num;
                else ans[1] = num;
            }
        }

        if (ans[0] == 0) printf("Case %d: impossible\n", Case++);
        else if (ans[1] == 0) printf("Case %d: %lld\n", Case++, ans[0]);
        else printf("Case %d: %lld %lld\n", Case++, ans[1], ans[0]);
    }
    return 0;
}

