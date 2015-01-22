#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<cstring>
#include<string>
#include <sstream>
#include<cctype>
#include<cmath>
#include<cstdlib>

#define I64 long long int
#define SIZE 1000
#define VI vector <int>
#define VS vector <string>
#define MSI map <string, int>
#define MIS map <int, string>
#define MSS map <string, string>

using namespace std;

bool primes[] = {0,0,1,1,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,0,0,0,0,1,0,1,0,0,0,0};
int seq[20], isUsed[20], n;

bool isPrime( int p ){
    return primes[p]==1;
}

void primeRing( int pos ){

    if( pos==n ){
        //if( isPrime( seq[0]+seq[n-1] ) ){
        printf("%d", seq[0]);
        for(int i=1; i<n; i++)
            printf(" %d", seq[i]);
        //}
        printf("\n");
        return;
    }

    for(int i=2; i<=n; i++){

        bool possible = false;
        if( !isUsed[i] ){

            if( pos==n-1 ){

                if( isPrime( seq[pos-1]+i ) && isPrime( seq[0]+i ) )
                    possible = true;
            }

            else if( isPrime( seq[pos-1]+i ) )
                possible = true;

            if( possible ){
                //primeRing( pos+1 );
                seq[pos] = i;
                isUsed[i] = 1;
                primeRing( pos+1 );
                //printf("%d\n", i);
                isUsed[i] = 0;
            }
        }
    }

    return;
}

int main()
{
    int Case = 1;
    bool blankLine = false;
    while( cin >> n){

        memset( isUsed, 0, sizeof(isUsed) );

        if( blankLine )  printf("\n");
        blankLine = true;

        seq[0] = 1;

        printf("Case %d:\n", Case++);
        primeRing( 1 );
    }
    return 0;
}

