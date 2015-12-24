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

int Base[] = {1, 16, 256, 4096, 65536};

int count1 (int n)
{
    int cnt = 0;

    while (n > 0) {
        if (n & 1) cnt++;
        n = n / 2;
    }
    return cnt;
}

int toDEC (int n)
{
    int dec = 0;
    int idx = 0;
    while (n > 0) {
        int t = n % 10;
        dec += (t * Base[idx++]);
        n = n / 10;
    }
    return dec;
}

int main()
{
    //READ("in.txt");
    //WRITE("out.txt");
    int Case=1;
    int n;
    char dump[2];

    int tc; scanf("%d", &tc);

    while (tc--) {
        scanf("%d", &n);
        int b1 = count1(n);
        int decN = toDEC(n);
        int b2 = count1(decN);
        printf("%d %d\n", b1, b2);
    }
    return 0;
}

