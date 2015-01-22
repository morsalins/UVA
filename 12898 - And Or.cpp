/*** Dhaka Regional 2014 ***/

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

I64 P[65];
int O[65];
int A[65];

void setP(void){
    P[0] = 1;
    for(int i=1; i<=60; i++){
        P[i] = P[i-1] * 2;
    }
    return;

}

VI toBinary( I64 n ){
    VI v;
    while( n>0 ){
        v.pb( n%2 );
        n /= 2;
    }
    return v;
}

int main()
{
    //READ("in.txt");
    int Case=1, n;
    char dump[2];
    I64 a, b;

    setP();
    int tc; scanf("%d", &tc);

    while( tc-- ){

        scanf("%lld %lld", &a, &b);

        I64 osum=0, asum=0;
        VI va = toBinary(a);
        VI vb = toBinary(b);
        SET(O, 0);
        SET(A, 0);
        bool flag = false;

        if( va.size() != vb.size() ){
            osum = P[vb.size()] - 1;
            asum = 0;
        }
        else {
            for(int i=vb.size()-1; i>=0; i--){
                if( vb[i] != va[i] ) flag = true;
                if( flag ){
                    O[i] = 1;
                    A[i] = 0;
                }
                else{
                    O[i] = vb[i];
                    A[i] = vb[i];
                }
            }
        }

        for(int i=0; i<vb.size(); i++){
            if( O[i] ) osum += P[ i ];
            if( A[i] ) asum += P[ i ];
        }

        printf("Case %d: %lld %lld\n", Case++, osum, asum);
    }

    return 0;
}
