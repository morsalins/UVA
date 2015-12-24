
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

map <char, int> symbol;
int freq[27];

void setSymbol ()
{
    symbol['B'] = 1;
    symbol['U'] = 10;
    symbol['S'] = 100;
    symbol['P'] = 1000;
    symbol['F'] = 10000;
    symbol['T'] = 100000;
    symbol['M'] = 1000000;
}

bool valid (string &s)
{
    int negative = 0, positive = 0;
    freq[s[0]-65]++;

    for (int i = 1; i < s.size(); i++) {
        freq[s[i]-65]++;
        if (freq[s[i]-65] > 9) return false;
        if (symbol[s[i]] - symbol[s[i-1]] < 0) negative++;
        else if (symbol[s[i]] - symbol[s[i-1]] > 0) positive++;
    }
    return positive == 0 || negative == 0;
}

int main()
{
    //READ("in.txt");
    //WRITE("out.txt");
    int Case=1;
    string s;
    char dump[2];

    setSymbol();
    int tc; scanf("%d", &tc);
    gets(dump);

    while (getline(cin, s)) {
        SET(freq, 0);
        if (valid(s)){
            int val = 0;
            for (int i = 0; i < s.size(); i++) {
                val += symbol[s[i]];
            }
            printf("%d\n", val);
        }
        else {
            printf("error\n");
        }
    }
    return 0;
}
