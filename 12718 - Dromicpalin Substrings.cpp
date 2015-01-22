/*** Dhaka Regional 2013 ***/

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

int occur[27];

int main()
{
    //READ("in.txt");
    //WRITE("out.txt");
    int Case=1;
    char dump[2];
    char str[1000+10];

    int tc; scanf("%d", &tc);
    gets(dump);

    while( tc-- ){

        gets( str );
        int odd=0, even=0, cnt=0, len=1;
        int occur[27];

        for(int i=0; str[i+1]; i++, len++){

            SET(occur, 0); occur[ str[i]-97 ]++;
            odd=1; even=0;

            for(int j=i+1; str[j]; j++){

                if( !occur[ str[j]-97 ] || ( occur[ str[j]-97 ] && !(occur[ str[j]-97 ]&1) ) ){
                    odd++;
                    if( even > 0 ) even--;
                }
                else if( occur[ str[j]-97 ] && (occur[ str[j]-97 ]&1) ){
                    even++;
                    if( odd > 0 ) odd--;
                }

                occur[ str[j]-97 ]++;

                if( odd <= 1 ) cnt++;
            }
        }
        printf("Case %d: %d\n", Case++, cnt+len);
    }

    return 0;
}

