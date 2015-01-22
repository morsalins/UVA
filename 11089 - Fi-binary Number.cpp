#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;

int main()
{
    long long int f[51] = {0, 1, 2};
    long long int n, i, t;

    for( i=3; i<51; i++){

        f[i] = f[i-1]+ f[i-2];
        //cout << f[i] << " ";
    }

    cin >> t;
    while( t-- ){

        cin >> n;
        i = 50;
        while( f[i]>n) i--;

        for(int j=i; j>=1; j--){
            if( f[j]<=n){
                printf("1");
                n = n-f[j];
            }

            else printf("0");
        }
        printf("\n");
    }

    return 0;
}
