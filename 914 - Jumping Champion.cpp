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
#define MAX 1000000
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

bool notprime[MAX + 7];
const int maxDist = 1005;

void Sieve ()
{
    int limit = sqrt(MAX) + 2;
    notprime[0] = true;
    notprime[1] = true;

    for (int i = 3; i <= limit; i++) {
        if (!notprime[i]) {
            for (int j = i * i, k = i << 1; j <= MAX; j += k) {
                notprime[j] = true;
            }
        }
    }
    return;
}

int main()
{
    //READ("in.txt");
    //WRITE("out.txt");
    int Case=1;
    char dump[2];

    int tc; scanf("%d", &tc);

    Sieve();
    int l, u;
    int freq[maxDist];

    while (tc--) {

        scanf("%d %d", &l, &u);
        SET(freq, 0);
        int mx = 0, lastPrime = -1;

        if (l <= 2) {
            lastPrime = 2;
            l = 3;
        }

        if (u <= 2) {
            u = 1;
        }

        if (!(l & 1)) l++;
        if (!(u & 1)) u--;

        for (int i = l; i <= u; i += 2) {
            if (!notprime[i] && lastPrime == -1) {
                lastPrime = i;
            }
            else if (!notprime[i] && lastPrime != -1) {
                freq[i - lastPrime]++;
                mx = max(mx, freq[i - lastPrime]);
                lastPrime = i;
            }
        }

        int cnt = 0, ans;

        for (int i = 1; i < maxDist && cnt < 2; i++) {
            if (freq[i] == mx) {
                cnt++;
                ans = i;
            }
        }

        if (cnt < 2) printf("The jumping champion is %d\n", ans);
        else printf("No jumping champion\n");
    }
    return 0;
}

