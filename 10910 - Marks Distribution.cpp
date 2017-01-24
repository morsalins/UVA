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
#define PSS pair <string, string>

#define MII map <int, int>
#define MLL map <I64, I64>
#define MDD map <double, double>
#define MSI map <string, int>
#define MIS map <int, string>
#define MSS map <string, string>

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

int dp[2][100];

//int ways (int i,int m, int p)
//{
//	if (i == 1) {
//		if (m >= p) return 1;
//		return 0;
//	}
//
//	if (m < p) return 0;
//
//	if (dp[i][m] != -1) return dp[i][m];
//
//	int sum = 0;
//
//	for (int j = m - p; j >= p; j--) {
//		sum += ways(i - 1, j, p);
//	}
//
//	return dp[i][m] = sum;
//}

void ways (int n, int m, int p)
{
	SET(dp, 0);

	for (int i = p; i <= m; i++) {
		dp[1][i] = 1;
	}

	for (int i = 2; i <= n; i++) {
		for (int j = p; j <= m; j++) {
			int sum = 0;
			for (int k = j - p; k >= p; k--) {
				 sum += dp[!(i&1)][k];
			}
			dp[i&1][j] = sum;
		}
	}

	return;
}

int main()
{
    //READ("in.txt");
    //WRITE("out.txt");
    int Case=1;
    int n, m, p;
    char dump[2];

    int tc; scanf("%d", &tc);

    while (tc--) {
    	scanf("%d %d %d", &n, &m, &p);

    	ways(n, m, p);
    	printf("%d\n", dp[n&1][m]);

//		SET(dp, -1);
//		printf("%d\n", ways(n, m, p));
    }
    return 0;
}
