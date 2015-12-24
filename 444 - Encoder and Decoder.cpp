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

char ascii[130];
string otpt;

void setAscii()
{
    for (int i = 0; i < 130; i++) {
        ascii[i] = '\0';
    }

    for (int i = 65; i < 91; i++) {
        ascii[i] = i;
    }

    for (int i = 97; i < 123; i++) {
        ascii[i] = i;
    }

    ascii[32] = ' ';
    ascii[33] = '!';
    ascii[44] = ',';
    ascii[46] = '.';
    ascii[58] = ':';
    ascii[59] = ';';
    ascii[63] = '?';
    return;
}

void Encode (string &S)
{
    for (int i = 0; i < S.size(); i++) {
        int num = S[i];
        string temp;
        while (num > 0) {
            temp += (num % 10) + 48;
            num = num / 10;
        }
        otpt = temp + otpt;
    }
    return;
}

void Decode (string &S)
{
    int num = 0;
    int len = S.size();
    for (int i = len - 1; i >= 0; i--) {
        num = (num * 10) + (S[i]-48);
        if (ascii[num] != '\0') {
            otpt += ascii[num];
            num = 0;
        }
    }
    return;
}

int main()
{
    //READ("in.txt");
    //WRITE("out.txt");
    int Case=1;
    char dump[2];
    string S;

    setAscii();

    while (getline(cin, S)) {
        if (isdigit(S[0])) {
            Decode(S);
        }
        else {
            Encode(S);
        }
        printf("%s\n", otpt.c_str());
        otpt.clear();
    }
    return 0;
}

