#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>
#include <functional>
#include <map>
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
#define pii pair<int, int>
#define SIZE 1000
#define MAX 1000
#define VI vector <int>
#define VS vector <string>
#define MSI map <string, int>
#define MIS map <int, string>
#define MSS map <string, string>
#define pb push_back
#define pob pop_back
#define mp make_pair
#define IT iterator
#define ff first
#define ss second
#define SET(a, b) memset( a, b, sizeof (a) )
#define READ(f) freopen(f, "r", stdin);
#define WRITE(f) freopen(f, "w", stdout);

int dp[MAX+7][MAX+7];

int main()
{
    //READ("in.txt");
    int Case=1;
    char dump[2], s1[MAX+7], s2[MAX+7];

    while( gets(s1) ){
        gets(s2);

        string X = string(s1); //cout << X << endl;
        string Y = string(s2); //cout << Y << endl;

        SET( dp, 0 );

        for(int i=1; i<=X.size(); i++){
            for(int j=1; j<=Y.size(); j++){

                if( X[i-1] == Y[j-1] ) dp[i][j] = dp[i-1][j-1] + 1;
                else dp[i][j] = max( dp[i-1][j], dp[i][j-1] );
            }
        }

        printf("%d\n", dp[ X.size() ][ Y.size() ] );
    }

    return 0;
}

