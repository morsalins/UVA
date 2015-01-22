#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>

using namespace std;

bool isSeven(unsigned long int num){

    while( num>0 ){

        int digit = num%10;
        if( digit==7 ) return true;
        num/=10;
    }

    return false;
}

int main()
{
    int n, m, k, cnt;
    unsigned long int last, result;

    while( cin >> n >> m >> k ){

        if( n==0 && m==0 && k==0 ) break;

        last = m;
        cnt = 0;
        if( last%7==0 || isSeven(last) ){
            cnt++;
            result = last;
        }
        char ch = 'r';

        while( 1 ){

            if(cnt==k) break;

            if(n==m){
                last = last+(m-1)*2;
                if( last%7==0 || isSeven(last) ){
                    cnt++;
                    result = last;
                }
            }

            else if(m==1){
                last = last+(n-m)*2;
                if( last%7==0 || isSeven(last) ){
                    cnt++;
                    result = last;
                }
            }

            else{

                if(ch=='r'){
                    last = last+(n-m)*2;
                    if( last%7==0 || isSeven(last) ){
                        cnt++;
                        result = last;
                    }
                    ch='l';
                }
                else if(ch=='l'){
                    last = last+(m-1)*2;
                    if( last%7==0 || isSeven(last) ){
                        cnt++;
                        result = last;
                    }
                    ch='r';
                }
            }
        }

        if(cnt==k)cout << result << "\n";
        else cout << "-1\n";
    }

    return 0;
}
