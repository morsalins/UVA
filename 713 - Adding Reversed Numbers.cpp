#include<cstdio>
#include<iostream>
#include<string>
#include<vector>
#include<cmath>

using namespace std;

int main()
{
    string a, b;
    int tc;

    cin >> tc;

    while( tc-- ){

        cin >> a >> b;

        int lena = a.size(), lenb = b.size(), r, carry=0;
        string sum;

        for(int i=0; i<lena||i<lenb; i++){

            if(i<lena && i<lenb) r = a[i]-48 + b[i]-48 + carry;
            else if(i>=lena) r = 0 + b[i]-48 + carry;
            else if(i>=lenb) r = 0 + a[i]-48 + carry;

            if( !sum.empty() || (r%10)!=0 ) sum += ((r%10)+48);
            carry = r/10;
        }

        if (carry) sum += carry+48;

        cout << sum << "\n";
    }

    return 0;
}
