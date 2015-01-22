#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

int main()
{
    int m[13], r[12];
    int s, cases=0;

    while( cin >> s ){

        if(s<0) return 0;

        for(int i=0; i<12; i++){
            cin >> m[i];
        }

        for(int i=0; i<12; i++){
            cin >> r[i];
        }

        printf ("Case %d:\n", ++cases);

        for(int i=0; i<12; i++){

            if( s>=r[i] ){
                s = s-r[i];
                printf("No problem! :D\n");
            }

            else printf("No problem. :(\n");

            s = s + m[i];
        }
    }

    return 0;
}
