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

int main()
{
    //READ("in.txt");
    int Case=1;
    char dump[2];
    int books[MAX+7];
    int n;
    I64 money;

    while( scanf("%d", &n) == 1 ){

        for(int i=0; i<n; i++){
            scanf("%d", &books[i]);
        }

        sort( books, books+n );

        scanf("%lld", &money);
        int value, min_differ = INF;
        pii ans;

        for(int i=0; i<n; i++){

            if( books[i] >= money ) continue;

            value = money - books[i];

            if( i==0 ){
                if( binary_search( books+1, books+n, value) ){
                    if( min_differ > abs(books[i]-value) ){
                        min_differ = abs(books[i]-value);
                        ans.ff = min( books[i], value );
                        ans.ss = max( books[i], value );
                    }
                }
            }

            else if( i==n-1 ){
                if( binary_search( books, books+n-1, value) ){
                    if( min_differ > abs(books[i]-value) ){
                        min_differ = abs(books[i]-value);
                        ans.ff = min( books[i], value );
                        ans.ss = max( books[i], value );
                    }
                }
            }

            else{

                if( binary_search( books, books+i, value) ){
                    if( min_differ > abs(books[i]-value) ){
                        min_differ = abs(books[i]-value);
                        ans.ff = min( books[i], value );
                        ans.ss = max( books[i], value );
                    }
                }
                else if( binary_search(books+i+1, books+n, value) ){
                    if( min_differ > abs(books[i]-value) ){
                        min_differ = abs(books[i]-value);
                        ans.ff = min( books[i], value );
                        ans.ss = max( books[i], value );
                    }
                }
            }
        }

        printf("Peter should buy books whose prices are %d and %d.\n\n", ans.ff, ans.ss);
    }

    return 0;
}

