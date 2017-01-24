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

int burger_time[MAX], burgers[MAX], cost[3];
int n, m, t;

//int maximum_burger(int i, int time)
//{
//	if (i > 2)
//		return 1;
//
//	if (dp[i][time] != -1) {
//		return dp[i][time];
//	}
//
//	int p1 = 0, p2 = 0;
//
//	if (time + cost[i] <= t)
//		p1 = maximum_burger(i , time + cost[i]);
//	p2 = maximum_burger(i + 1, time);
//
//	return dp[i][time] = p1 + p2;
//}

void maximum_burger()
{
	for (int i = 1; i <= 2; i++) {
		for (int j = 1; j <= t; j++) {
			int x = 0, y = burger_time[j];
			if (j >= cost[i]) {
				x = burger_time[j - cost[i]] + cost[i];
			}

			if (x > y) {
				burger_time[j] = x;
				burgers[j] = burgers[j - cost[i]] + 1;
			}
			else if (x == y) {
				burger_time[j] = x;
				if (j >= cost[i]) burgers[j] = max(burgers[j], burgers[j - cost[i]] + 1);
			}
		}
	}
}

int main()
{
    //READ("in.txt");
    //WRITE("out.txt");
    int Case=1;
    char dump[2];

    while (scanf("%d %d %d", &m, &n, &t) == 3) {
    	SET(burger_time, 0);
    	SET(burgers, 0);
    	cost[1] = m; cost[2] = n;

    	maximum_burger();

    	int burger = burgers[t], beer_time = t - burger_time[t];

//    	for (int i = 0; i <= t; i++) {
//    		burger_time = max(burger_time, dp[i]);
//    	}

    	printf("%d", burger);
    	if (beer_time > 0)
    		printf(" %d", beer_time);
    	puts("");
    }
    return 0;
}
