#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>

using namespace std;

int main()
{
    long long int m, x, v;

    while( cin >> m >> x ){

        if(!m && !x) return 0;

        if( m==1 || x==0 || x==100 ){
            printf("Not found\n");
        }

        else{

            v = (100*(m-1)) / (100-x);

            if( (100*(m-1)) % (100-x) == 0 )v--;

            if(v<m)printf("Not found\n");
            else cout << v << "\n";
        }
    }

    return 0;
}
