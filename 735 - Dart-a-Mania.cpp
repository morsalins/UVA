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
#define MAX 610000
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

int flag[(MAX >> 5) + 10];
bool possibleScores[65];
vector <int> scores;

void init (void)
{
    SET(possibleScores, false);
    scores.push_back(0);
    possibleScores[0] = true;
    scores.push_back(50);
    possibleScores[50] = true;

    for (int i = 1; i <= 20; i++) {
        if(!possibleScores[i]) {
            scores.push_back(i);
            possibleScores[i] = true;
        }
        if(!possibleScores[i+i]) {
            scores.push_back(i+i);
            possibleScores[i+i] = true;
        }
       if(!possibleScores[i+i+i]) {
            scores.push_back(i+i+i);
            possibleScores[i+i+i] = true;
        }
    }

    sort(scores.begin(), scores.end());

    return;
}

int main()
{
    //READ("in.txt");
    //WRITE("out.txt");
    int Case=1;
    int score;
    char dump[2];

    init();

    while (scanf("%d", &score) && score > 0) {
        int permutations = 0;
        int combinations = 0;
        int len = scores.size();
        SET(flag, 0);

        if (score <= 180) {
            for (int i = len-1; i >= 0; i--) {
                for (int j = len-1; j >= 0; j--) {
                    int remain = score - (scores[i] + scores[j]);
                    if (possibleScores[remain] && 0 <= remain && remain <= 60) {
                        permutations++;
                        int a[3];
                        a[0] = scores[i]; a[1] = scores[j]; a[2] = remain;
                        sort(a, a + 3);
                        int idx = (a[0] * 10000) + (a[1] * 100) + a[2];
                        if (!(flag[idx >> 5] & (1 << (idx & 31)))) {
                            flag[idx >> 5] |= (1 << (idx & 31));
                            combinations++;
                        }
                    }
                }
            }
        }

        if (combinations > 0) {
            printf("NUMBER OF COMBINATIONS THAT SCORES %d IS %d.\n", score, combinations);
            printf("NUMBER OF PERMUTATIONS THAT SCORES %d IS %d.\n", score, permutations);
        }
        else {
            printf("THE SCORE OF %d CANNOT BE MADE WITH THREE DARTS.\n", score);
        }

        for (int i = 1; i <= 70; i++) {
            printf("*");
        }
        puts("");
    }
    puts("END OF OUTPUT");
    return 0;
}
