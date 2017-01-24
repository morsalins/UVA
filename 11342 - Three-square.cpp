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
#define SIZE 50010
#define MAX 500
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

int squares[MAX];
int threesq[SIZE][3];

void PreCalc()
{
    for (int i = 0; i <= 224; i++) {
        squares[i] = i * i;
    }

    for (int i = 0; i <= 224; i++) {
        for (int j = i; j <= 224; j++) {
            for (int k = i; k <= 224; k++) {
                int idx = squares[i] + squares[j] + squares[k];
                if (idx <= 50000 && threesq[idx][0] == 0 && threesq[idx][1] == 0 & threesq[idx][2] == 0) {
                    threesq[idx][0] = i;
                    threesq[idx][1] = j;
                    threesq[idx][2] = k;
                }
            }
        }
    }
    return;
}

bool isImpossible (int idx)
{
    return threesq[idx][0] == 0 && threesq[idx][1] == 0 && threesq[idx][2] == 0;
}

int main()
{
    //READ("in.txt");
    //WRITE("out.txt");
    int Case=1;
    int n, k;
    char dump[2];

    PreCalc();

    int tc; scanf("%d", &tc);

    while (tc--) {
        scanf("%d", &k);
        if (isImpossible(k)) {
            printf("-1\n");
        }
        else {
            printf("%d %d %d\n", threesq[k][0], threesq[k][1], threesq[k][2]);
        }
    }
    return 0;
}
