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
#define MAX 20010
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

int main()
{
    //READ("in.txt");
    //WRITE("out.txt");
    int Case=1, s, d;
    char dump[2];

    int tc; scanf("%d", &tc);

    while (tc--) {
    	scanf("%d", &s);
    	int last  = 1, l = 1, r = 1, ans = 0, sum = 0;

    	for (int i = 1; i < s; i++) {
    		scanf("%d", &d);
    		sum += d;

    		if (ans < sum) {
    		    ans = sum;
    		    l = last;
    		    r = i + 1;
    		}
    		else if (ans == sum) {
    		    if ((r - l) < (i + 1 - last)) {
    		    	l = last;
    		    	r = i + 1;
    		    }
    		}

    		if (sum < 0) {
    		    sum = 0;
    		    last = i + 1;
    		}
    	}

    	if (ans == 0) {
    		printf("Route %d has no nice parts\n", Case++);
    	}
    	else {
    		printf("The nicest part of route %d is between stops %d and %d\n", Case++, l, r);
    	}
    }
    return 0;
}
