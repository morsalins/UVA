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

#define PPP pair <Point, Point>
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

class Point{
public:
    double x, y;
    Point () {}
    Point (double _x, double _y) {
        x = _x; y = _y;
    }
};

class Line{
public:
    double a, b, c;
    Line () {}
    Line (Point p1, Point p2) {
        a = p2.y - p1.y;
        b = p1.x - p2.x;
        c = (a*p1.x + b*p1.y) * -1;
    }
};

Point Start, End;
Point bottomLeft, bottomRight, topLeft, topRight;

vector <Line> lines;
vector <PPP> points;

void setPoints (double xleft, double ytop, double xright, double ybottom) {
    bottomLeft = Point(xleft, ybottom);
    bottomRight = Point(xright, ybottom);
    topLeft = Point(xleft, ytop);
    topRight = Point(xright, ytop);
}

bool isInRectangle (Point tl, Point bl, Point br, Point P) {
    return bl.x <= P.x && P.x <= br.x
        && bl.y <= P.y && P.y <= tl.y;
}

bool inBetween (Point p0, Point p, Point p1) {
    return  min(p0.x, p1.x) <= p.x+EPS && p.x-EPS <= max(p0.x, p1.x)
        &&  min(p0.y, p1.y) <= p.y+EPS && p.y-EPS <= max(p0.y, p1.y);
}

int main()
{
    //READ("in.txt");
    //WRITE("out.txt");
    int Case=1;
    char dump[2];

    int tc; scanf("%d", &tc);

    while( tc-- ){

        double xleft, ytop, xright, ybottom;
        scanf("%lf %lf %lf %lf %lf %lf %lf %lf", &Start.x, &Start.y , &End.x, &End.y, &xleft, &ytop, &xright, &ybottom);

        if (xright<xleft) swap(xright, xleft);
        if (ytop<ybottom) swap(ytop, ybottom);

        setPoints(xleft, ytop, xright, ybottom);
        bool intersect = false;

        if ( isInRectangle(topLeft, bottomLeft, bottomRight, Start) || isInRectangle(topLeft, bottomLeft, bottomRight, End) ) {
            intersect = true;
        }
        else {
            points.pb( PPP(bottomLeft, topLeft) ); lines.pb( Line(bottomLeft, topLeft) );
            points.pb( PPP(topLeft, topRight) ); lines.pb( Line(topLeft, topRight) );
            points.pb( PPP(topRight, bottomRight) ); lines.pb( Line(topRight, bottomRight) );
            points.pb( PPP(bottomRight, bottomLeft) ); lines.pb( Line(bottomRight, bottomLeft) );

            Line line = Line(Start, End);

            for (int i=0; i<4 && !intersect; i++) {
                double det = line.a*lines[i].b - lines[i].a*line.b;
                if (det == 0.0) continue;
                else {
                    double X = -(line.c*lines[i].b - lines[i].c*line.b) / det;
                    double Y = -(line.a*lines[i].c - lines[i].a*line.c) / det;
                    if ( inBetween(Start, Point(X, Y), End) && inBetween(points[i].ff, Point(X, Y), points[i].ss) ) {
                        intersect = true;
                    }
                }
            }
        }
        if (intersect) printf("T\n");
        else printf("F\n");

        lines.clear();
        points.clear();
    }
    return 0;
}

