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
    Point() {}
    Point(int _x, int _y) {
        x = _x; y = _y;
    }
};

class Line {
public:
    double a, b, c;
    Line() {}
    Line(Point p1, Point p2) {
        a = p2.y - p1.y;
        b = p1.x - p2.x;
        c = -(a*p1.x + b*p1.y);
    }
};

Point P1, P2, P3, P4;
Line line1, line2;

bool onLine (Line l, Point p) {
    double r = l.a*p.x + l.b*p.y + l.c;
    return r == 0;
}

int main()
{
    //READ("in.txt");
    //WRITE("out.txt");
    int Case=1;
    char dump[2];

    int tc; scanf("%d", &tc);
    printf("INTERSECTING LINES OUTPUT\n");

    while( tc-- ){

        double x1, y1, x2, y2, x3, y3, x4, y4;
        scanf("%lf %lf %lf %lf %lf %lf %lf %lf", &x1, &y1, &x2, &y2, &x3, &y3, &x4, &y4);

        P1 = Point (x1, y1); P2 = Point (x2, y2); P3 = Point (x3, y3); P4 = Point (x4, y4);
        line1 = Line(P1, P2);
        line2 = Line(P3, P4);

        if (onLine(line1, P3) && onLine(line1, P4)) {
            printf("LINE\n");
        }
        else {
            double det = line1.a*line2.b - line2.a*line1.b;
            if (det == 0.0) {
                printf("NONE\n");
            }
            else {
                double X = -(line1.c*line2.b - line2.c*line1.b) / det;
                double Y = -(line1.a*line2.c - line2.a*line1.c) / det;
                printf("POINT %.2lf %.2lf\n", X, Y);
            }
        }
    }
    printf("END OF OUTPUT\n");
    return 0;
}

