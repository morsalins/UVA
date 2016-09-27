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
#define MAX 30010
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

int coins[] = {0, 1, 5, 10, 25, 50};
I64 dp[6][MAX];

void coinChange()
{
	for (int i = 0; i <= 5; i++) {
		dp[i][0] = 1;
	}

	for (int i = 1; i <= 5; i++) {
		for (int j = 1; j < MAX; j++) {
			I64 taken = 0;
			if (coins[i] <= j) {
				taken = dp[i][j - coins[i]];
			}
			dp[i][j] = taken + dp[i-1][j];
		}
	}

	return;
}

int main()
{
    //READ("in.txt");
    //WRITE("out.txt");
    int Case=1, n;
    char dump[2];

    coinChange();

    while (scanf("%d", &n) == 1) {
    	I64 ans = dp[5][n];
    	if (ans > 1)
    		printf("There are %lld ways to produce %d cents change.\n", ans, n);
    	else
    		printf("There is only %lld way to produce %d cents change.\n", ans, n);
    }
    return 0;
}
