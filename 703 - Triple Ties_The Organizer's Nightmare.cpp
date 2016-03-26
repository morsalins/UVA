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
#define MAX 110
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

    _type (int aa, int bb, int cc) {
        a = aa; b = bb; c = cc;
    }
};

bool flag[MAX][MAX];

bool isAllZero (int i, int j, int k)
{
    return (!flag[i][j] && !flag[j][i] && !flag[j][k] && !flag[k][j] && !flag[k][i] && !flag[i][k]);
}

bool isCycle (int i, int j, int k)
{
    return (flag[i][j] && flag[j][k] && flag[k][i]);
}

bool isSorted (int i, int j, int k)
{
    return (i > j && j > k) || (i < j && j < k);
}

int main()
{
    //READ("in.txt");
    //WRITE("out.txt");
    int Case=1;
    int n, state;
    char dump[2];

    //int tc; scanf("%d", &tc);

    while (scanf("%d", &n) == 1)
    {
        vector <_type> ans;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                scanf("%d", &state);
                flag[i][j] = (state == 1);
            }
        }

        int counter = 0;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                for (int k = 1; k <= n; k++)
                {
                    if (isCycle(i, j, k) && isSorted(i, j, k))
                    {
                        ans.push_back(_type(i, j, k));
                        counter++;
                    }
                    else if (isAllZero(i, j, k) && (i < j && j < k)) {
                        ans.push_back(_type(i, j, k));
                        counter++;
                    }
                }
            }
        }

        printf("%d\n", counter);
        for (int i = 0; i < ans.size(); i++)
        {
            printf("%d %d %d\n", ans[i].a, ans[i].b, ans[i].c);
        }
    }
    return 0;
}

