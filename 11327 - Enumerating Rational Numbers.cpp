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
#define MAX 200000
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

int phi[MAX + 7];
I64 sum[MAX + 7];

void Euler_Phi()
{
    SET(phi, 0);
    phi[1] = 2;

    for (int i = 2; i <= MAX+1; i++) {
        if (!phi[i]) {
            phi[i] = i - 1;
            for (int j = i+i; j <= MAX+1; j += i) {
                if (!phi[j]) phi[j] = j;
                phi[j] = (phi[j] / i) * (i - 1);
            }
        }
    }
    return;
}

void set_sum ()
{
    sum[0] = 0;
    for (int i = 1; i <= MAX+1; i++) {
        sum[i] = sum[i-1] + phi[i];
    }
    return;
}

int GCD (int a, int b)
{
    if (b == 0) return a;
    else return GCD(b, a % b);
}

int main()
{
    //READ("in.txt");
    //WRITE("out.txt");
    int Case=1;
    I64 n;
    char dump[2];

    Euler_Phi();
    set_sum();

    while (scanf("%lld", &n) == 1) {

        if (n == 0) return 0;

        int nom;
        int cnt = 0;
        int denom = lower_bound(sum, sum + MAX + 1, n) - sum;
        int noms = n - sum[denom - 1];

        for (int i = 0; i <= denom; i++) {
            if(GCD(denom, i) == 1) {
                cnt++;
                if (cnt == noms) {
                    nom = i;
                    i = denom + 1;
                }
            }
        }

        printf("%d/%d\n", nom, denom);
    }
    return 0;
}

