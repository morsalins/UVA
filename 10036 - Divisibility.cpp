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
#define MAX 10001
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

int arr[MAX];
bool dp[2][105];

//bool isDivisible(int i, int sum)
//{
//	sum = sum % k;
//	if (sum < 0) sum = (sum + k) % k;
//
//	if (i > n) {
//		if (sum == 0) return true;
//		return false;
//	}
//
//	if (dp[i][sum] != -1) return dp[i][sum];
//
//	bool plus = isDivisible(i + 1, arr[i] + sum);
//	bool minus = isDivisible(i + 1, arr[i] - sum);
//
//	return dp[i][sum] = plus || minus;
//}

void isDivisible(int n, int k)
{
	int sum = arr[1] % k;
	if (sum < 0) sum += k;

	SET(dp[1], false);
	dp[1][sum] = true;

	for (int i = 2; i <= n; i++) {
		for (int j = 0; j <= k; j++) {
			int sum1 = (j + arr[i]) % k;
			int sum2 = (j - arr[i]) % k;

			if (sum1 < 0) sum1 += k;
			if (sum2 < 0) sum2 += k;

			dp[i&1][j] = dp[!(i&1)][sum1] || dp[!(i&1)][sum2];
		}
	}

	return;
}

int main()
{
    //READ("in.txt");
    //WRITE("out.txt");
    int Case=1;
    int n, k;
    char dump[2];

    int tc; scanf("%d", &tc);

    while (tc--) {
    	scanf("%d %d", &n, &k);

    	for (int i = 1; i <= n; i++) {
    		scanf("%d", &arr[i]);
    	}

    	isDivisible(n, k);

    	if (dp[n&1][0]) {
    		puts("Divisible");
    	}
    	else {
    		puts("Not divisible");
    	}

    }
    return 0;
}
