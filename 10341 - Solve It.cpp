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
#define EPS 1e-7

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

double p, q, r, s, t, u;

double solve(double x){
    return (p*exp(-x)) + (q*sin(x)) + (r*cos(x)) + (s*tan(x)) + (t*(x*x)) + u;
}

double BS ( ) {

    double lo = 0, hi = 1, mid;

    while (lo+EPS <= hi) {
        mid = (lo+hi) / 2;
        if (solve(lo) * solve(mid) <= 0) {
            hi = mid;
        }
        else {
            lo = mid;
        }
    }
    return (hi+lo)/2.0;
 }

int main()
{
    //READ("in.txt");
    //WRITE("out.txt");
    int Case=1;

    while( scanf("%lf %lf %lf %lf %lf %lf", &p, &q, &r, &s, &t, &u) == 6 ){
        if (solve(0) * solve(1) > 0) printf("No solution\n");
        else printf("%0.4lf\n", BS() );
    }

    return 0;
}

