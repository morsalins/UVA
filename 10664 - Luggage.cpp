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
#include <strstream>
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

int dp[2][210];
int C[30];

int subsetSum (int n, int w)
{
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= w; j++) {
			if (C[i] <= j) {
				dp[i&1][j] = max(dp[!(i&1)][j], dp[!(i&1)][j - C[i]] + C[i]);
			}
			else {
				dp[i&1][j] = dp[!(i&1)][j];
			}
		}
	}

	return dp[n&1][w];
}

int main()
{
    //READ("in.txt");
    //WRITE("out.txt");
    int Case=1;
    char dump[2];

    int tc; scanf("%d", &tc);
    gets(dump);

    while (tc--) {
    	string s;
    	int data, idx = 1, sum = 0;
    	SET(dp[0], 0);

    	getline(cin, s);
    	stringstream S(s);

    	while (S >> data) {
    		C[idx++] = data;
    		sum += data;
    	}

    	if (sum & 1) puts("NO");
    	else {
			int res = subsetSum(idx - 1, sum >> 1);
			if (res == sum >> 1) puts("YES");
			else puts("NO");
    	}
    }
    return 0;
}
