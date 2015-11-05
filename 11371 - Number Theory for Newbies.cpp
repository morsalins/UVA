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

I64 toInt (string n)
{
    I64 d = 0;
    for (int i = 0; i < n.size(); i++) {
        d = (d * 10) + (n[i] - 48);
    }
    return d;
}

int main()
{
    //READ("in.txt");
    //WRITE("out.txt");
    int Case=1;
    string s;
    char dump[2];

    //int tc; scanf("%d", &tc);

    while (cin >> s) {

        sort(s.begin(), s.end());
        string t = s;
        reverse(t.begin(), t.end());

        if (s[0] == '0') {
            for (int i = 0; i < s.size(); i++) {
                if (s[i] != '0') {
                    swap(s[i], s[0]);
                    break;
                }
            }
        }

        I64 a = toInt(t);
        I64 b = toInt(s);
        if (a < b) swap(a, b);
        I64 ans = a - b;
        printf("%lld - %lld = %lld = 9 * %lld\n", a, b, ans, ans/9);
    }
    return 0;
}
