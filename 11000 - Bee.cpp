#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>

#define SIZE 51

using namespace std;

long long int f[SIZE], m[SIZE+1];

long long int fibo( int n){

    if( n==0 || n==1 ) return 1;
    else if( f[n] == 0 )
        return f[n] = fibo(n-1) + fibo(n-2);

    else return f[n];
}

int main()
{
    unsigned long int sum, n;

    m[0]=0; f[0]=1; f[1]=1;
    fibo(SIZE-1);

    for(int i=1; i<=SIZE; i++){

        m[i] = f[i-1] + m[i-1];
        //cout << m[i] << " ";
    }

    while( cin >> n ){

        if( n==-1 ) return 0;
        cout << m[n] << " " << m[n]+f[n] << "\n";
    }
    return 0;
}
