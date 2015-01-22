#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>

using namespace std;

int main()
{
    int a, b;

    while( cin >> a >> b ){

        printf("[%d;", a/b);

        int r = a%b;
        bool flag = false;
        a = b;
        b = r;

        while( a!=1 && b !=0 ){

            if(flag)printf(",");
            printf("%d", a/b);

            flag = true;
            r = a%b;
            a = b;
            b = r;
        }

        printf("]\n");
    }

    return 0;
}
