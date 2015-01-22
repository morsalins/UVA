#include<iostream>
#include<cstdio>
#include<cmath>

using namespace std;

int main()
{
    int n, sum;

    printf("PERFECTION OUTPUT\n");
    while( cin >> n ){

        if(n==0){
            break;
        }

        float rootn = sqrt(n);
        sum = 0;
        for(int i=2; i*i<=n; i++){

            if(n%i==0){
                if(n/i!=rootn) sum = sum + i + (n/i);
                else sum = sum + i;
            }

        }
        if(n!=1) sum++;

        if(sum==n) printf("%5d  PERFECT\n", n);
        else if(sum<n) printf("%5d  DEFICIENT\n", n);
        else if(sum>n) printf("%5d  ABUNDANT\n", n);
    }

    cout << "END OF OUTPUT\n";
    return 0;
}
