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
#define MAX 110
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

int C[MAX], dp[2][50010];

//int Subset(int i, int cost)
//{
//	if (i > n) return cost;
//	if (dp[i][cost] != -1) return dp[i][cost];
//
//	int p1 = Subset(i+1, C[i]+cost);
//	int p2 = Subset(i+1, cost);
//
//	int dif1 = abs(p1-(total-p1));
//	int dif2 = abs(p2-(total-p2));
//
//	if (dif1 <= dif2) dp[i][cost] = p1;
//	else dp[i][cost] = p2;
//
//	return dp[i][cost];
//}

int Subset(int n, int len)
{
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= len; j++) {
			if (C[i] <= j) {
				dp[i&1][j] = max(dp[!(i&1)][j-C[i]] + C[i], dp[!(i&1)][j]);
			}
			else {
				dp[i&1][j] = dp[!(i&1)][j];
			}
		}
	}
	return dp[n&1][len];
}

int main()
{
    //READ("in.txt");
    //WRITE("out.txt");
    int Case=1;
    int n, total;
    char dump[2];

    int tc; scanf("%d", &tc);

    while (tc--) {
    	scanf("%d", &n);

    	total = 0;
    	SET(dp[0], 0);

    	for (int i = 1; i <= n; i++) {
    		scanf("%d", &C[i]);
    		total += C[i];
    	}

    	int res = Subset(n, total/2);

    	printf("%d\n", abs(res+res-total));
    }
    return 0;
}
