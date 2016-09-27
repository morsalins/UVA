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
#define MAX 20001
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

int dp[2][MAX], coins[101];

PII knapSack(int n, int price)
{
	dp[0][0] = dp[1][0] = 0;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j < MAX; j++) {
			if (coins[i] <= j) {
				dp[i&1][j] = min(dp[!(i&1)][j], dp[!(i&1)][j - coins[i]] + 1);
			}
			else {
				dp[i&1][j] = dp[!(i&1)][j];
			}
		}
	}

	for (int i = price; i < MAX; i++) {
		if (dp[n&1][i] != INF) {
			return PII (i, dp[n&1][i]);
		}
	}

	return PII(0, 0);
}

int main()
{
    //READ("in.txt");
    //WRITE("out.txt");
    int Case=1;
    int price, n;
    char dump[2];

    int tc; scanf("%d", &tc);

    while (tc--) {
    	scanf("%d", &price);
    	scanf("%d", &n);

    	for (int i = 1; i <= n; i++) {
    		scanf("%d", &coins[i]);
    	}

    	sort (coins + 1, coins + 1 + n);
    	SET(dp[0], INF);

    	PII ans = knapSack(n, price);
    	printf("%d %d\n", ans.first, ans.second);
    }
    return 0;
}
