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
#define MAX 50000
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

int divisors[MAX + 10];

int GCD (int a, int b)
{
    if (b == 0) return a;
    else return GCD(b, a%b);
}

int LCM (int a, int b) {
    return (a / GCD(a, b)) * b;
}

int main()
{
    //READ("in.txt");
    //WRITE("out.txt");
    int Case=1, n;
    char dump[2];

    //int tc; scanf("%d", &tc);

    while (scanf("%d", &n) == 1) {
        if (n == 0) return 0;

        int idx = 0;

        for (int i = 1; i * i <= n; i++) {
            if (n % i == 0) {
                divisors[idx++] = i;
                if (i != (n / i)) divisors[idx++] = n / i;
            }
        }

        int cnt = 0;

        for (int i = 0; i < idx; i++) {
            for (int j = i; j < idx; j++) {
                if (LCM( max(divisors[i], divisors[j]), min(divisors[i], divisors[j]) ) == n) {
                    //DEBUG(divisors[i], divisors[j]);
                    cnt++;
                }
            }
        }
        printf("%d %d\n", n, cnt);
    }
    return 0;
}
