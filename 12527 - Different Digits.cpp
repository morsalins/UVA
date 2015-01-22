#include<cstdio>
#include<iostream>
#include<cmath>

using namespace std;

int a[10];

bool isRepeated(int i){

    int n = i;

     for(int i=0; i<=9; i++){
            a[i]=0;
     }

    while( n>0 ){
        int r = n%10;
        a[r]++;
        if( a[r]>1 )
            return true;
        n = n/10;
    }

    return false;
}

int main()
{
    int n, m, cnt;

    while( cin >> n >> m ){

        cnt = 0;

        for(int i=n; i<=m; i++){

            if( !isRepeated(i) )cnt++;
        }

        cout << cnt << "\n";
    }

    return 0;
}
