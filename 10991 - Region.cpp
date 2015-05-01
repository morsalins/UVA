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
#define PI 3.141592653589793

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

double getValue (double a, double b, double c) {
    return ( (a*a) + (b*b) - (c*c) ) / (2 * a * b);
}

int main()
{
    //READ("in.txt");
    //WRITE("out.txt");
    int Case=1;
    char dump[2];
    double r1, r2, r3;

    int tc; scanf("%d", &tc);

    while( tc-- ){
        scanf("%lf %lf %lf", &r1, &r2, &r3);

        double a = r1 + r3;
        double b = r1 + r2;
        double c = r3 + r2;

        double s = (a+b+c) / 2;
        double triangleArea = sqrt( fabs(s * (s-a) * (s-b) * (s-c)) );

        double alpha = acos( getValue(b, c, a) );
        double beta = acos( getValue(a, c, b) );
        double gama = acos( getValue(a, b, c) );

        double area1 = (alpha * r2 * r2 * 0.5);
        double area2 = (beta * r3 * r3 * 0.5);
        double area3 = (gama * r1 * r1 * 0.5);

        double res = triangleArea - (area1 + area2 + area3);
        printf("%0.6lf\n", res);
    }

    return 0;
}


