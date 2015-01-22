#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

string bigIntSum(string a, string b){

    int lena = a.size();
    int lenb = b.size();
    int carry = 0;
    int r=0;
    string sum;

    reverse( a.begin(), a.end() );
    reverse( b.begin(), b.end() );

    for(int i=0; i<lena||i<lenb; i++){

        if(i<lena && i<lenb){
            r = (a[i]-48) + (b[i]-48) + carry;
        }

        else if( i>=lena ){
            r = 0 + (b[i]-48) + carry;
        }
        else if( i>=lenb ){
            r = (a[i]-48) + 0 + carry;
        }
        sum += (r%10)+48;
        carry = r/10;
    }
    if(carry)sum += carry+48;
	reverse(sum.begin(), sum.end());
    //cout << sum<<"\n" ;
    return sum;
}

int main()
{
    int n;
    vector <string> v;

    v.push_back("1");v.push_back("2");

    for(int i=2; i<=1001; i++){

		v.push_back( bigIntSum(v[i-1], v[i-2]) );
    }

    while(cin >> n){

        //printf("The Fibonacci number for %d is ", n);
        cout << v[n] << "\n";
    }

    return 0;
}
