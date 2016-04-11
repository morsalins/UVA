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
#define MAX 201
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
    int a, b, c, d;

    _type () { }

    _type (int _a, int _b ,int _c, int _d) {
        a = _a; b = _b, c = _c, d = _d;
    }
};

int cubes[MAX * MAX * MAX];
vector <_type> ans;

bool comp (const _type &l, const _type &r)
{
    if (l.a == r.a) {
        if (l.b == r.b) {
            if (l.c == r.c) {
                return l.d < r.d;
            }
            return l.c < r.c;
        }
        return l.b < r.b;
    }
    return l.a < r.a;
}

int main()
{
    //READ("in.txt");
    //WRITE("out.txt");
    int Case=1;
    char dump[2];

    for (int i = 2; i <= 200; i++) {
        cubes[i] = i * i * i;
    }

    for (int i = 2; i <= 200; i++) {
        for (int j = i; j <= 200; j++) {
            for (int k = j; k <= 200; k++) {
                int idx = cubes[i] + cubes[j] + cubes[k];
                int pos = lower_bound(cubes, cubes + 201, idx) - cubes;
                if (cubes[pos] == idx) {
                    ans.push_back(_type(pos, i, j, k));
                }
            }
        }
    }

    sort(ans.begin(), ans.end(), comp);

    for (int i = 0; i < ans.size(); i++) {
        printf("Cube = %d, Triple = (%d,%d,%d)\n", ans[i].a, ans[i].b, ans[i].c, ans[i].d);
    }

    return 0;
}
