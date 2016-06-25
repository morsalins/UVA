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
#define MAX 1010
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

int W[MAX], C[MAX];
int dp[MAX][50];

//int KnapSack(int i, int weight)
//{
//	if (i > n) {
//		return 0;
//	}
//	if (dp[i][weight] != -1) {
//		return dp[i][weight];
//	}
//
//	int prf1 = 0, prf2 = 0;
//
//	if (W[i] + weight <= cap) {
//		prf1 = C[i] + KnapSack(i+1, W[i]+weight);
//	}
//	prf2 = KnapSack(i+1, weight);
//
//	return dp[i][weight] = max(prf1, prf2);
//}

void init(int n)
{
	for (int i = 0; i <= n; i++) {
		dp[i][0] = 0;
	}

	for (int i = 0; i < 50; i++) {
		dp[0][i] = 0;
	}
	return;
}

void Knapsack(int n, int cap)
{
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= cap; j++) {
			if (W[i] <= j) {
				dp[i][j] = max(C[i] + dp[i-1][j-W[i]], dp[i-1][j]);
			}
			else {
				dp[i][j] = dp[i-1][j];
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
    int n, q, cap;
    char dump[2];

    int tc; scanf("%d", &tc);

    while (tc--) {
    	scanf("%d", &n);

    	for (int i = 1; i <= n; i++) {
    		scanf("%d %d", &C[i], &W[i]);
    	}

    	init(n);
    	Knapsack(n, 35);

    	scanf("%d", &q);
    	int ans = 0;

    	for (int i = 1; i <= q; i++) {
    		scanf("%d", &cap);
    		ans += dp[n][cap];
    	}
    	printf("%d\n", ans);
    }
    return 0;
}
