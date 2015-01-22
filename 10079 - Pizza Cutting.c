#include <stdio.h>

int main()
{
    long long int cuts;

    while( scanf("%lld", &cuts) == 1){

        if(cuts>=0)
            printf("%lld\n", (cuts*(cuts+1))/2 + 1 );
        else
           break;
    }

    return 0;
}

