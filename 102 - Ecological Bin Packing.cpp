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

int a[3][3];
int sum[3][3];
char col[] = {'B', 'C', 'G'};
char bin[3];

void func (int r, int c1, int c2, int c3)
{
    sum[r][c1] = a[r][c2] + a[r][c3];
    return;
}

int main()
{
    //READ("in.txt");
    //WRITE("out.txt");
    int Case=1;
    char dump[2];

    while (scanf("%d %d %d %d %d %d %d %d %d", &a[0][0], &a[1][0], &a[2][0], &a[0][1], &a[1][1], &a[2][1], &a[0][2], &a[1][2], &a[2][2]) == 9) {
        for (int i = 0; i < 3; i++) {
            swap(a[1][i], a[2][i]);
        }

        for (int i = 0; i < 3; i++) {
            func(i, 0, 1, 2);
            func(i, 1, 0, 2);
            func(i, 2, 1, 0);
        }

        int ans = INF;

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (j != i) {
                    for (int k = 0; k < 3; k++) {
                        if (k != j && k != i) {
                            if (sum[i][0] + sum[j][1] + sum[k][2] < ans) {
                                ans = sum[i][0] + sum[j][1] + sum[k][2];
                                bin[0] = col[i];
                                bin[1] = col[j];
                                bin[2] = col[k];
                            }
                        }
                    }
                }
            }
        }
        printf("%s %d\n", bin, ans);
    }
    return 0;
}

