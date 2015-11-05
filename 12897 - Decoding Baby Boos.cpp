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

char Map[30];

int main()
{
    //READ("in.txt");
    //WRITE("out.txt");
    int Case=1;
    string S;
    int r;
    char u, v;
    char dump[2];

    int tc; scanf("%d", &tc);
    gets(dump);

    while (tc--) {
        getline(cin, S);
        scanf("%d", &r);
        gets(dump);

        for (int i = 0; i < 30; i++) {
            Map[i] = '\0';
        }

        for (int i = 0; i < r; i++) {
            scanf("%c %c", &u, &v);
            gets(dump);
            for (int j = 0; j < 26; j++) {
                if (Map[j] == v) {
                    Map[j] = u;
                }
            }
            if (Map[v-65] == '\0') {
                Map[v-65] = u;
            }
        }

        for (int i = 0; i < S.size(); i++) {
            if (Map[S[i]-65] != '\0')
                S[i] = Map[S[i]-65];
        }

        cout << S << "\n";
    }
    return 0;
}

