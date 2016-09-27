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
#define MAX 301
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

I64 dp[MAX][MAX];

void preCalc()
{
	dp[0][0] = 1;

	for (int i = 1; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			if (j >= i)
				dp[i][j] = dp[i][j - i] + dp[i - 1][j];
			else
				dp[i][j] = dp[i - 1][j];
		}
	}

	return;
}

int main()
{
    //READ("in.txt");
    //WRITE("out.txt");
    int Case=1;
    string s;
    char dump[2];

    preCalc();

    while (getline(cin, s)) {
    	stringstream S(s);
    	int a[] = {-1, -1, -1};
    	int id = 0;

    	while(S >> a[id++]);

    	int n = a[0];
    	int l = a[1];
    	int u = a[2];
    	I64 ans = 0;

    	if (n == 0) {
    		if (u == -1 || (u >= 0 && l == 0)) ans = 1;
    	}
    	else if (l == -1) {
    		ans = dp[n][n];
    	}
    	else if (u == -1) {
    		if (l > n) {
    			l = n;
    		}

    		ans = dp[l][n];
    	}
    	else {
    		if (l > u) swap(l, u);

    		if (l > 0 && l <= n) {
    			l--;
    		}
    		if (l > n) {
    			l = n;
    		}
    		if (u > n) {
    			u = n;
    		}

    		ans = dp[u][n] - dp[l][n];
    	}

    	printf("%lld\n", ans);
    }
    return 0;
}
