#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;





int main()
{
    int n;
    unsigned long sum;

    while( cin >> n ){

        if(n==0) break;

        if(n>1)sum = 1+(n*n);
        else sum = 1;

        for(int i=n-1; i>=2; i--){

            sum += (i*i);
        }
        cout << sum << "\n";
    }

    return 0;
}

