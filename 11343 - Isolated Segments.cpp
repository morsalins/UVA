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

class Point {
public:
    double x, y;
    Point() {}
    Point(double _x, double _y) {
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

vector <Line> lines;
vector <PPP> points;

bool isOverlap (Point s1, Point e1, Point s2, Point e2) {
    if (s1.x > e1.x) swap(s1.x, e1.x);
    if (s2.x > e2.x) swap(s2.x, e2.x);
    if (s1.y > e1.y) swap(s1.y, e1.y);
    if (s2.y > e2.y) swap(s2.y, e2.y);

    return max(s1.x, s2.x) <= min(e1.x, e2.x)
        && max(s1.y, s2.y) <= min(e1.y, e2.y);
}

bool inBetween (Point p1, double x, double y, Point p2) {
    return min(p1.x, p2.x) <= x+EPS && x-EPS <= max(p1.x, p2.x)
        && min(p1.y, p2.y) <= y+EPS && y-EPS <= max(p1.y, p2.y);
}

int main()
{
    //READ("in.txt");
    //WRITE("out.txt");
    int Case=1, n;

    int tc; scanf("%d", &tc);

    while( tc-- ) {

        scanf("%d", &n);
        Point Start, End;

        for (int i=1; i<=n; i++) {
            scanf("%lf %lf %lf %lf", &Start.x, &Start.y, &End.x, &End.y);
            points.pb( PPP(Start, End) );
            lines.pb( Line(Start, End) );
        }

        int totalIsolated = 0;

        for (int i=0; i<lines.size(); i++) {
            bool collide = false;
            for (int j=0; j<lines.size() && !collide; j++) {
                if (i != j) {
                    double det = lines[i].a*lines[j].b - lines[j].a*lines[i].b; //DEBUG("det", det);
                    if (det == 0.0) {
                        double det1 = lines[i].a*lines[j].c - lines[j].a*lines[i].c;
                        double det2 = lines[i].b*lines[j].c - lines[j].b*lines[i].c;
                        if ( det1 == 0 && det2 == 0 && isOverlap(points[i].ff, points[i].ss, points[j].ff, points[j].ss) ) {
                            collide = true;
                        }
                    }
                    else {
                        double X = -(lines[i].c*lines[j].b - lines[j].c*lines[i].b) / det;
                        double Y = -(lines[i].a*lines[j].c - lines[j].a*lines[i].c) / det;
                        if ( inBetween(points[i].ff, X, Y, points[i].ss) && inBetween(points[j].ff, X, Y, points[j].ss) ) {
                            collide = true;
                        }
                    }
                }
            }
            if (!collide) totalIsolated++;
        }
        printf("%d\n", totalIsolated);
        lines.clear();
        points.clear();
    }
    return 0;
}

