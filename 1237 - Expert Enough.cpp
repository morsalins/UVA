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
#define MAX 10000
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

char str[MAX + 7][25];
int low[MAX + 7], high[MAX + 7];

int main()
{
    //READ("in.txt");
    //WRITE("out.txt");
    int Case=1;
    char dump[2];

    int tc; scanf("%d", &tc);

    while (tc--) {
        int d;
        scanf("%d", &d);

        gets(dump);

        for (int i = 0; i < d; i++) {
            scanf("%s %d %d\n", str[i], &low[i], &high[i]);
        }

        if (Case > 1) puts("");
        Case++;

        int ans;
        int q, cnt = 0;
        scanf("%d", &q);

        for (int query = 1; query <= q; query++) {
            int price;
            scanf("%d", &price);
            cnt = 0;
            for (int i = 0; i < d && cnt <= 1; i++) {
                if (price >= low[i] && price <= high[i]) {
                    cnt++;
                    ans = i;
                }
            }
            if (cnt == 1) {
                printf("%s\n", str[ans]);
            }
            else {
                printf("UNDETERMINED\n");
            }
        }
    }
    return 0;
}
