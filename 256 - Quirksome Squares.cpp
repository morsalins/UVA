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

int len[] = {-1, -1, 99, -1, 9999, -1, 999999, -1, 99999999};

bool Check (int num, int product, int len)
{
    int num2 = 0, counter = 0;
    while (counter < len) {
        num2 += (product % 10) * (int)(ceil(pow(10, counter)));
        product /= 10;
        counter++;
    }
    return num == num2 + product;
}

int main()
{
    //READ("in.txt");
    //WRITE("out.txt");
    int Case=1;
    int digits;
    int n;
    char dump[2];

    //int tc; scanf("%d", &tc);

    while (scanf("%d", &digits) == 1) {
        for (int i = 0; i * i <= len[digits]; i++) {
            int product = i * i;
            if (digits == 2) {
                if (Check(i, product, 1)) {
                    printf("%.2d\n", product);
                }
            }
            else if (digits == 4) {
                if (Check(i, product, 2)) {
                    printf("%.4d\n", product);
                }
            }
            else if (digits == 6) {
                if (Check(i, product, 3)) {
                    printf("%.6d\n", product);
                }
            }
            else if (digits == 8) {
                if (Check(i, product, 4)) {
                    printf("%.8d\n", product);
                }
            }
        }
    }
    return 0;
}
