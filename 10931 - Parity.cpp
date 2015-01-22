#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

string s;

int binary(long int n){

    int p = 0;
    s = "";

    while( n>0 ){
        int b = n%2;
        s += b+48;
        if(b==1)p++;
        n = n/2;
    }

    return p;
}

int main()
{
    long int n;
    int p;

    while( cin >> n ){

        if(n==0)break;

        p = binary(n);

        reverse(s.begin(), s.end());
        printf("The parity of ");
        cout << s;
        printf(" is %d (mod 2).\n", p);
    }

    return 0;
}
