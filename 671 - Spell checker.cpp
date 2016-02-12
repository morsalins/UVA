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

int main()
{
    //READ("in.txt");
    //WRITE("out.txt");
    int Case=1;
    string S;
    char dump[2];

    int tc; scanf("%d", &tc);
    gets(dump);

    while (tc--) {
        getchar();
        vector <string> Dictionary;

        while (getline(cin, S) && S[0] != '#') {
            Dictionary.push_back(S);
        }

        if (Case > 1) puts("");
        Case++;

        while (getline(cin, S) && S[0] != '#') {
            bool flag = false;

            for (int i = 0; i < Dictionary.size(); i++) {
                if (S == Dictionary[i]) {
                    flag = true;
                    printf("%s is correct", S.c_str());
                    break;
                }
            }

            if (!flag) {
                printf("%s:", S.c_str());
                for (int i = 0; i < Dictionary.size(); i++) {
                    if (S.size() == Dictionary[i].size()) {
                        string tmp = S;
                        for (int j = 0; j < S.size(); j++) {
                            tmp[j] = Dictionary[i][j];
                            if (tmp == Dictionary[i]) {
                                printf(" %s", Dictionary[i].c_str());
                                break;
                            }
                            tmp = S;
                        }
                    }
                    else if (S.size() == Dictionary[i].size() - 1) {
                        string tmp = S;
                        for (int j = 0; j < Dictionary[i].size(); j++) {
                            tmp.insert(tmp.begin() + j, Dictionary[i][j]);
                            if (tmp == Dictionary[i]) {
                                printf(" %s", Dictionary[i].c_str());
                                break;
                            }
                            tmp = S;
                        }
                    }
                    else if (S.size() == Dictionary[i].size() + 1) {
                        string tmp = S;
                        for (int j = 0; j < S.size(); j++) {
                            tmp.erase(tmp.begin() + j);
                            if (tmp == Dictionary[i]) {
                                printf(" %s", Dictionary[i].c_str());
                                break;
                            }
                            tmp = S;
                        }
                    }
                }
            }
            puts("");
        }
    }
    return 0;
}

