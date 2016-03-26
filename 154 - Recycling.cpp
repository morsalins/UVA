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

char cities[107][6];
int differ[107];

int getIndex (char ch)
{
    if (ch == 'r') return 0;
    if (ch == 'o') return 1;
    if (ch == 'y') return 2;
    if (ch == 'g') return 3;
    if (ch == 'b') return 4;
}

int main()
{
    //READ("in.txt");
    //WRITE("out.txt");
    int Case=1;
    char str[30];
    char dump[2];

    while (gets(str)) {
        if (str[0] == '#') return 0;

        int idx = 0;

        do {
            if (str[0] == 'e') break;

            for (int i = 0; str[i] != '\0'; i++) {
                if (islower(str[i])) {
                    cities[idx][getIndex(str[i])] = str[i+2];
                }
            }
            idx++;
        } while (gets(str));

        SET(differ, 0);
        int Min = INF;
        int ans = 0;

        for (int i = 0; i < idx-1; i++) {
            for (int j = i+1; j < idx; j++) {
                int diff = 0;
                for (int k = 0; k < 5; k++) {
                    if (cities[i][k] != cities[j][k]) {
                        diff++;
                    }
                }
                differ[i] += diff;
                differ[j] += diff;
            }
            if (Min > differ[i]) {
                Min = differ[i];
                ans = i + 1;
            }
        }

        if (Min > differ[idx-1]) {
            Min = differ[idx-1];
            ans = idx;
        }

        printf("%d\n", ans);
    }
    return 0;
}

