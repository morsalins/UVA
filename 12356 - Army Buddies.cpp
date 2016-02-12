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
#define MAX 100000
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

int Left[MAX + 7], Right[MAX + 7];

int main()
{
    //READ("in.txt");
    //WRITE("out.txt");
    int Case=1;
    int s, b;
    char dump[2];

    while (scanf("%d %d", &s, &b) == 2) {
        if (s == 0 && b == 0) return 0;

        for (int i = 1; i <= s; i++) {
            Left[i] = i - 1;
            Right[i] = i + 1;
        }

        for (int i = 1; i <= b; i++) {
            int l, r;
            scanf("%d %d", &l, &r);
            Left[Right[r]] = Left[l];
            Right[Left[l]] = Right[r];

            if (Left[l] >= 1) printf("%d", Left[l]);
            else printf("*");

            if (Right[r] <= s) printf(" %d\n", Right[r]);
            else printf(" *\n");
        }
        puts("-");
    }
    return 0;
}

