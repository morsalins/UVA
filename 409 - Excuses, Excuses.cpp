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
#define MAX 10000
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

class Trie
{
public:
    int next[26];
    bool flag;

    void init () {
        flag = false;
        SET(next, 0);
    }
} T[MAX + 7];

int occur[50];
int ptr;
char S[100];
char excuses[25][100];

void Insert (char *s)
{
    int cur = 0;
    for (int i = 0; s[i]; i++) {
        int k = s[i] - 97;
        if (T[cur].next[k] == 0) {
            T[cur].next[k] = ptr;
            T[ptr].init();
            ptr++;
        }
        cur = T[cur].next[k];
    }
    T[cur].flag = true;
    return;
}

bool Search (char *s)
{
    int cur = 0;
    for (int i = 0; s[i]; i++) {
        int k = s[i] - 97;
        if (T[cur].next[k] == 0) return false;
        cur = T[cur].next[k];
    }
    return T[cur].flag;
}

int main()
{
    //READ("in.txt");
    //WRITE("out.txt");
    int Case=1, n, m;
    char dump[2];

    while (scanf("%d %d", &n, &m) == 2) {
        gets(dump);
        SET(occur, 0);
        T[0].init();
        ptr = 1;

        for (int i = 0; i < n; i++) {
            gets(S);
            Insert(S);
        }

        char tmp[100];
        int idx = 0;
        int mx = -1;

        for (int q = 0; q < m; q++) {
            gets(excuses[q]);
            int idx = 0, len = 0, cnt = 0, Length = strlen(excuses[q]);

            while (len < Length) {
                int ptr;
                for (ptr = len; isalpha(excuses[q][ptr]); ptr++) {
                    tmp[idx++] = tolower(excuses[q][ptr]);
                }
                tmp[idx] = '\0';
                if (Search(tmp)) {
                    cnt++;
                }
                len = ptr + 1;
                idx = 0;;
            }
            mx = max(mx, cnt);
            occur[q] = cnt;
        }

        printf("Excuse Set #%d\n", Case++);
        for (int i = 0; i < m; i++) {
            if (occur[i] == mx) {
                cout << excuses[i] << "\n";
            }
        }
        puts("");
    }
    return 0;
}

