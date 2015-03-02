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

#define PI 3.141592653589793

class Point {
public:
    double x, y;
    Point () { }
    Point (double _x, double _y) {
        x = _x; y = _y;
    }
};

class Line {
public:
    double a, b, c;
    Line () { }
    Line (Point p1, Point p2){
        a = p2.y - p1.y;
        b = p1.x - p2.x;
        c = -(a*p1.x + b*p1.y);
    }
};

double dist (double x, double y) {
    return sqrt(x*x + y*y);
}

Line getPerpendicularEquation (Line l, Point a, Point b) {
    Line perpendicularline;
    Point midPoint = Point( (a.x+b.x)/2, (a.y+b.y)/2 );
    perpendicularline.a = -l.b;
    perpendicularline.b = l.a;
    perpendicularline.c  = -(perpendicularline.a*midPoint.x + perpendicularline.b*midPoint.y);
    return perpendicularline;
}

Point getIntersectionPoint (Line l1, Line l2) {
    double det = l1.a*l2.b - l2.a*l1.b;
    double X = -(l1.c*l2.b - l2.c*l1.b) / det;
    double Y = -(l1.a*l2.c - l2.a*l1.c) / det;
    return Point(X, Y);
}

double getRadius (Point a, Point b) {
    return dist(a.x-b.x, a.y-b.y);
}

void printEquaions (Point center, double radius) {

    char signh = '-', signk = '-', signc = '+', signd = '+', signe = '+';
    double h = center.x, k = center.y;

    if (h < 0.0) {signh = '+'; h = -h;}
    if (k < 0.0) {signk = '+'; k = -k;}
    printf("(x %c %0.3lf)^2 + (y %c %0.3lf)^2 = %0.3lf^2\n", signh, h, signk, k, radius);

    h = center.x, k = center.y;
    double c = -2*h, d = -2*k, e = -((radius*radius) - (h*h + k*k));
    if (c < 0.0) {signc = '-'; c = -c;}
    if (d < 0.0) {signd = '-'; d = -d;}
    if (e < 0.0) {signe = '-'; e = -e;}
    printf("x^2 + y^2 %c %0.3lfx %c %0.3lfy %c %0.3lf = 0\n", signc, c, signd, d, signe, e);
    return;
}

int main()
{
    //READ("in.txt");
    //WRITE("out.txt");
    int Case=1;
    char dump[2];
    Point A, B, C;

    while (scanf("%lf %lf %lf %lf %lf %lf", &A.x, &A.y, &B.x, &B.y, &C.x, &C.y) == 6) {
        Line line1 = Line(A, B);
        Line line2 = Line(A, C);
        Line perpendicular_of_line1 = getPerpendicularEquation(line1, A, B);
        Line perpendicular_of_line2 = getPerpendicularEquation(line2, A, C);
        Point Center = getIntersectionPoint(perpendicular_of_line1, perpendicular_of_line2);
        double radius = getRadius(Center, A);
        printEquaions(Center, radius);
        puts("");
    }
    return 0;
}


