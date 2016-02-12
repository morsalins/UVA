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

class Trie {
public:
    int next[2];
    int counter;
    bool flag;

    void init () {
        SET(next, 0);
        counter = 0;
        flag = false;
    }
} T[MAX];

bool possible;
int ptr;

void Reset ()
{
    ptr = 1;
    possible = true;
    T[0].init();
    return;
}

void Insert (string &s)
{
    int cur = 0;

    for (int i = 0; i < s.size(); i++) {
        int k = s[i] - 48;
        if (T[cur].next[k] == 0) {
            T[cur].next[k] = ptr;
            T[ptr].init();
            ptr++;
        }
        cur = T[cur].next[k];
        T[cur].counter++;

        if (T[cur].flag) {
            possible = false;
            return;
        }
    }
    T[cur].flag = true;
    if (T[cur].counter > 1) {
        possible = false;
    }
    return;
}

int main()
{
    //READ("in.txt");
    //WRITE("out.txt");
    int Case=1;
    string s;
    char dump[2];

    Reset();

    while (getline(cin, s)) {
        if (s[0] == '9') {
            if (possible) printf("Set %d is immediately decodable\n", Case++);
            else printf("Set %d is not immediately decodable\n", Case++);
            Reset();
        }
        else {
            if (possible) {
                Insert(s);
            }
        }
    }
    return 0;
}

