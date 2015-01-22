#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

long long int a[51];

long long int f(int n){

    if(n==0 || n==1)return 1;
    else if(a[n]==0)
        return a[n] = f(n-1)+f(n-2);
    return a[n];
}

int main()
{
    a[0]=1; a[1]=1;
    f(50);

    int n;

    while(1){
        cin >> n;
        if(n==0)break;
       // printf("The Fibonacci number for %d is ", n);
        cout << a[n] << "\n";
    }

    return 0;
}
