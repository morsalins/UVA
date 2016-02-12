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

class Pilot
{
public:
    int time;
    string name, Name;

    Pilot () {}
    Pilot (int t, string &n, string &N) {
        time = t; name = n; Name = N;
    }
};

bool comp (const Pilot &l, const Pilot &r)
{
    if (l.time == r.time) return l.name < r.name;
    else return l.time < r.time;
}

bool isNum (char ch)
{
    return '0' <= ch && ch <= '9';
}

Pilot parseInput (const string &S)
{
    string Name, name;

    for (int i = 0; i < S.size() && S[i+1] != ':'; i++) {
        Name += S[i];
        name += tolower(S[i]);
    }

    int a[3];
    int num = 0;
    bool flag = false;
    int idx = 0;

    for (int i = 0; i < S.size(); i++) {
        if (isNum(S[i])) {
            flag = true;
            num = (num * 10) + (S[i] - '0');
        }
        else {
            if (flag) a[idx++] = num;
            num = 0;
            flag = false;
        }
    }

    int time = (((a[0] * 60) + a[1]) * 1000) + a[2];

    return Pilot(time, name, Name);
}

int main()
{
    //READ("in.txt");
    //WRITE("out.txt");
    int Case=1, n;
    char dump[2];
    string S;

    while (scanf("%d", &n) == 1) {
        gets(dump);
        vector <Pilot> V;

        for (int i = 0; i < n; i++) {
            getline(cin, S);
            V.push_back(parseInput(S));
        }

		sort(V.begin(), V.end(), comp);

        int row = (n / 2) + (n % 2);
        int idx = 0;

        for (int i = 0; i < row; i++) {
            printf("Row %d\n", i + 1);
            if (idx < V.size()) cout << V[idx++].Name << "\n";
			if (idx < V.size()) cout << V[idx++].Name << "\n";
        }
        puts("");
    }
    return 0;
}

