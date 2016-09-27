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
#define MAX 10010
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

vector <int> coins;
I64 dp[MAX];

void preCalc()
{
	coins.push_back(0);
	for (int i = 1; i <= 21; i++) {
		coins.push_back(i * i * i);
	}
	return;
}

void coinChange()
{
	dp[0] = 1;

	for (int i = 1; i <= 21; i++) {
		for (int j = coins[i]; j < MAX; j++) {
			dp[j] += dp[j - coins[i]];
		}
	}

	return;
}

int main()
{
    //READ("in.txt");
    //WRITE("out.txt");
    int Case=1;
    int n;
    char dump[2];

    preCalc();
    coinChange();

    while (scanf("%d", &n) == 1) {
    	printf("%lld\n", dp[n]);
    }
    return 0;
}
