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
#define EPS 0.0

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

double rec[1000][5];

bool inBetween (double x1, double y1, double x2, double y2, double x, double y) {
    return (min(x1, x2) < x+EPS && x-EPS < max(x1, x2))
        && (min(y1, y2) < y+EPS && y-EPS < max(y1, y2));
}

int main()
{
    //READ("in.txt");
    //WRITE("out.txt");
    int Case=1;
    char dump[2], ch;

    ch  = getchar();

    while (ch != '*') {

        int rectangles = 0;
        while (ch != '*') {
            scanf("%lf %lf %lf %lf", &rec[rectangles][0], &rec[rectangles][1], &rec[rectangles][2], &rec[rectangles][3]);
            rectangles++;
            gets(dump);
            ch = getchar();
        }

        double x=0.0, y=0.0;
        bool flag = true;
        int points = 0;

        while (flag) {
            scanf("%lf %lf", &x, &y);
            if (x == 9999.9 && y == 9999.9) flag = false;
            points++;
            bool contained = false;
            for (int i=0; i<rectangles; i++) {
                if ( inBetween(rec[i][0], rec[i][1], rec[i][2], rec[i][3], x, y) ){
                    printf("Point %d is contained in figure %d\n", points, i+1);
                    contained = true;
                }
            }
            if (!contained && flag) printf("Point %d is not contained in any figure\n", points);
        }
        gets(dump);
        if (scanf("%c", &ch) == EOF) break;
    }
    return 0;
}

