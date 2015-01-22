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
#define MAX 200
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

int cor[MAX], stu[MAX], dp[MAX];

int LIS(int n){

    SET( dp, INF );
    dp[1] = -INF;
    int ans = 0;

    for(int i=1; i<=n; i++){

        int j = upper_bound( dp+1, dp+n+1, stu[i] ) - dp;
        if( dp[j-1] < stu[i] && stu[i] < dp[j] ){
            dp[j] = stu[i];
            ans = max( ans, j);
        }
    }

    return ans-1;
}

int main()
{
    //READ("in.txt");
    int Case=1, n, data;
    char dump[2];
    string s;

    while( getline(cin, s) ){

        if( s.size() < 3 ){

            stringstream S(s);
            S >> n;

            for(int i=1; i<=n; i++){
                scanf("%d", &data);
                cor[i] = data;
            }
            gets(dump);
        }

        else{

            stringstream S(s);

            for(int i=1; i<=n; i++){
                S >> data;
                stu[data] = cor[i];
            }
            //for(int i=1; i<=n; i++) cout << stu[i]<< " ";
            //cout << endl;
            printf("%d\n", LIS(n) );
        }
    }

    return 0;
}

