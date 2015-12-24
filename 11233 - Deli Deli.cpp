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

bool isVowel (char ch)
{
    return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
}

int main()
{
    //READ("in.txt");
    //WRITE("out.txt");
    int Case=1;
    int n, l;
    string u, v;
    char dump[2];

    //int tc; scanf("%d", &tc);

    while (scanf("%d %d", &l, &n) == 2) {
        getchar();
        map <string, string> mp;

        for (int i = 1; i <= l; i++) {
            cin >> u >> v;//DEBUG(u, v);
            mp[u] = v;
        }

        for (int i = 1; i <= n; i++) {
            cin >> u;//DEBUG('u', u);
            if (mp[u] != "") {
                printf("%s\n", mp[u].c_str());
            }
            else {
                char ch1 = u[u.size()-1], ch2 = u[u.size()-2];
                if (ch1 == 'y' && !isVowel(ch2)) {
                    for (int i = 0; i < u.size()-1; i++) {
                        printf("%c", u[i]);
                    }
                    printf("ies\n");
                }
                else if ((ch1 == 'h' && ch2 == 'c') || (ch1 == 'h' && ch2 == 's') || ch1 == 'o' || ch1 == 's' || ch1 == 'x') {
                    printf("%ses\n", u.c_str());
                }
                else {
                    printf("%ss\n", u.c_str());
                }
            }
        }
    }
    return 0;
}

