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
#define MAX 1010
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

class _type
{
    public:
        int a, b, c;

        _type () { }
        _type (int _a, int _b, int _c) {
            a = _a; b = _b; c = _c;
        }

        bool operator < (const _type &obj) const {
            return a < obj.a;
        }
};

int a[MAX + 7];

bool allDistinct (int a, int b, int c, int d)
{
    return (a != b) && (a != c) && (a != d) && (b != c) && (b !=d) && (c != d);
}

int main()
{
    //READ("in.txt");
    //WRITE("out.txt");
    int Case=1;
    int n;
    char dump[2];

    while (scanf("%d", &n) == 1 && n != 0) {
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }

        vector <_type> sum, sub;

        sort(a, a + n);

        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                sum.push_back(_type(a[i] + a[j], a[i], a[j]));
            }
        }

        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                sub.push_back(_type(a[j] - a[i], a[i], a[j]));
            }
        }

        sort (sub.begin(), sub.end());
        int ans = -1;
        bool possible = false;

        for (int i = 0; i < sum.size(); i++) {
            if (binary_search(sub.begin(), sub.end(), sum[i])) {
                int pos = lower_bound(sub.begin(), sub.end(), sum[i]) - sub.begin();
                if (allDistinct(sum[i].b, sum[i].c, sub[pos].b, sub[pos].c)) {
                    ans = max(ans, sub[pos].c);
                    possible = true;
                }
            }
        }

        if (possible) printf("%d\n", ans);
        else printf("no solution\n");
    }
    return 0;
}
