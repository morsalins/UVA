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

int GCD (int a, int b)
{
    if (b == 0) return a;
    return GCD (b, a%b);
}

int LCM (int a, int b)
{
    return (a / GCD(a, b)) * b;
}

int main()
{
    //READ("in.txt");
    //WRITE("out.txt");
    int Case=1;
    int k;
    char dump[2];

    //int tc; scanf("%d", &tc);

    while (scanf("%d", &k) == 1) {
        vector <PII> ans;

        for (int i = k + 1; i <= k * 2; i++) {
            int denominator = LCM(i, k);
            int numerator = (denominator / k) - (denominator / i);
            int gcd = GCD (denominator, numerator);
            if (numerator == gcd) {
                ans.push_back(PII(denominator / gcd, i));
            }
        }

        printf("%d\n", ans.size());
        for (int i = 0; i < ans.size(); i++) {
            printf("1/%d = 1/%d + 1/%d\n", k, ans[i].first, ans[i].second);
        }
    }
    return 0;
}

