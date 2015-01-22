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
#define MAX 10000
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

int l[MAX+7], w[MAX+7];

int main()
{
    //READ("in.txt");
    int Case=1, n;
    char dump[2];

    int tc; scanf("%d", &tc);

    while( tc-- ){

        scanf("%d", &n);

        for(int i=0; i<n; i++) scanf("%d", &l[i]);
        for(int i=0; i<n; i++) scanf("%d", &w[i]);

        int lis[n+7], lds[n+7];
        int mlis = 0, mlds = 0;

        for(int i=0; i<n; i++){

            lis[i] = w[i]; lds[i] = w[i]; //cout << lis[i] << " " << lds[i] << endl;

            for(int j=0; j<i; j++){

                if( l[j] < l[i] ){
                    lis[i] = max( lis[i], lis[j] + w[i] ); //cout << lis[i] << endl;
                }

                else if( l[j] > l[i] ){
                    lds[i] = max( lds[i], lds[j] + w[i] ); //cout << lds[i] << endl;
                }
            }

            mlis = max( mlis, lis[i] ); //cout << mlis << endl;
            mlds = max( mlds, lds[i] ); //cout << mlds << endl;
        }

        if( mlis >= mlds ) printf("Case %d. Increasing (%d). Decreasing (%d).\n", Case++, mlis, mlds);
        else printf("Case %d. Decreasing (%d). Increasing (%d).\n", Case++, mlds, mlis);
    }

    return 0;
}

