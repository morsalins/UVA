#include<cstdio>
#include<iostream>
#include<cmath>

using namespace std;

int main()
{
    int m, n, knights;

    while( cin >> m >>n ){

        if(m==0 && n==0) break;

        knights = 0;
        int maximum = max(m, n);
        int minimum = min(m, n);

        if(m==1 || n==1){
           knights = maximum;
        }

        else if( (m==2 || n==2) ){
            if(maximum%4==3)
                knights = (4*(maximum/4)) + (2* ((maximum-1) %4) );

            else knights = (4*(maximum/4)) + (2* ((maximum) %4) );
        }

        else{
            float f = (float)(maximum*minimum) / 2.0;
            knights = ceil(f);
        }

        printf("%d knights may be placed on a %d row %d column board.\n", knights, m, n);
    }
    return 0;
}

