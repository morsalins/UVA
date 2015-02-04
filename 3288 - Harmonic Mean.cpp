// Dhaka Regional 2005

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

int a[100];

I64 GCD(I64 a, I64 b){
    if( b==0 ) return a;
    else  return GCD(b, a%b);
}

I64 LCM(I64 a,I64 b){
    return ( max(a, b)/GCD(max(a, b), min(a, b)) ) * min(a, b);
}

int main()
{
    //READ("in.txt");
    //WRITE("out.txt");
    int n, Case = 1;
    I64 m;

    int tc; scanf("%d", &tc);

    while( tc-- ){

        scanf("%d", &n);
        for(int i=0; i<n; i++){
            scanf("%d", &a[i]);
        }

        I64 lcm = 1;
        for(int i=0; i<n; i++){
            lcm = LCM(lcm, a[i]);
        }

        I64 sum = 0;
        for(int i=0; i<n; i++){
            sum += (lcm/a[i]);
        }

        I64 N = n;
        N = N * lcm;
        I64 gcd = GCD(max(sum, N), min(sum, N) );
        sum = sum/gcd;
        N = N/gcd;

        printf("Case %d: %lld/%lld\n", Case++, N, sum);

    }

    return 0;
}
