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

class type
{
public:
    int a, b, c;
    type () {}
    type (int _a, int _b,  int _c) {
        a = _a; b = _b; c = _c;
    }
};

int arr[10];

bool isValid (int a, int b, int c)
{
    if (c < 0) {
        return abs(arr[a] - arr[b]) >= abs(c);
    }
    else {
        return abs(arr[a] - arr[b]) <= abs(c);
    }
}

int main()
{
    //READ("in.txt");
    //WRITE("out.txt");
    int Case=1;
    int n, m;
    char dump[2];

    while (scanf("%d %d", &n, &m) == 2) {
        if (n == 0 && m == 0) return 0;

        for (int i = 0; i < n; i++) {
            arr[i] = i;
        }

        vector <type> v;

        for (int i = 1; i <= m; i++) {
            int a, b, c;
            scanf("%d %d %d", &a, &b, &c);
            v.push_back(type(a, b, c));
        }

        int cnt = 0;

        do {
            bool flag = true;
            for (int i = 0; i < v.size(); i++) {
                if (!isValid(v[i].a, v[i].b, v[i].c)) {
                    flag = false;
                }
            }
            if (flag) cnt++;
        } while (next_permutation(arr, arr + n));

        printf("%d\n", cnt);
    }
    return 0;
}

