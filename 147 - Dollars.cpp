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

int coins[] = {0, 5, 10, 20, 50, 100, 200, 500, 1000, 2000, 5000, 10000};
I64 dp[12][MAX];

void coinChange()
{
	for (int i = 0; i <= 11; i++) {
		dp[i][0] = 1;
	}

	for (int i = 1; i <= 11; i++) {
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
    int Case=1;
    string s;
    char dump[2];

    coinChange();

    while (getline(cin, s)) {
    	if (s == "0.00") break;

    	char n[15];

    	for (int i = 0, id = 0; i < s.size(); i++) {
    		if (s[i] != '.')
    			n[id++] = s[i];
    	}

    	I64 N = atoll(n);
    	printf("%6s%17lld\n", s.c_str(), dp[11][N]);
    }
    return 0;
}
