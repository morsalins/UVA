#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>

using namespace std;

long int f(long int i) {

    long int cnt=0;

    if( i==1 ) return 3;

    while( i!=1 && i!=0 ){

        cnt++;

        if( i&1 ){
            i = 3*i + 1;
        }
        else {
            i/=2;
        }
    }

    return cnt;
}

int main()
{
    int l, h, largest;
    long int cnt, mx, mxnum;

    while( cin >> l >> h ){

        if(l==0||h==0)return 0;

        if( l>h ) swap(l, h);

        mx=0;
        mxnum=0;
        for(long int i=l; i<=h; i++){

            cnt = f(i);

           if( cnt>mx  ){
                mx=cnt;
                mxnum=i;
           }
        }

        printf("Between %d and %d, %ld generates the longest sequence of %ld values.\n", l, h, mxnum, mx);
    }

    return 0;
}
