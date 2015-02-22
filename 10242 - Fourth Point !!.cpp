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

class Point {
public:
    double x, y;
    Point () { }
    Point (double _x, double _y) {
        x = _x; y = _y;
    }

    Point operator - (const Point& p) {
        return Point(x-p.x, y-p.y);
    }
    Point operator + (const Point& p) {
        return Point(x+p.x, y+p.y);
    }
    bool operator == (const Point& p) {
        return (x == p.x) && (y == p.y);
    }
};

Point p1, p2, p3, p4;

void adjust( ) {
    if (p1 == p3) swap(p1, p2);
    else if (p1 == p4) {
        swap(p1, p2); swap(p3, p4);
    }
    else if (p2 == p4) swap(p3, p4);
    return;
}

int main()
{
    //READ("in.txt");
    //WRITE("out.txt");
    int Case=1;
    char dump[2];

    while( scanf("%lf %lf %lf %lf %lf %lf %lf %lf", &p1.x, &p1.y, &p2.x, &p2.y, &p3.x, &p3.y, &p4.x, &p4.y) == 8 ){
        adjust();
        Point vec = p4-p3; // vetcor from p3 to p4;
        Point fourthPoint = p1 + vec;
        printf("%0.3lf %0.3lf\n", fourthPoint.x, fourthPoint.y);
    }

    return 0;
}

