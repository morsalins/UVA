#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
    string num1, num2;

    while(1){

        cin >> num1;
        cin >> num2;

        if(num1[0]==48  &&  num2[0]==48) break;

        reverse( num1.begin(), num1.end());
        reverse( num2.begin(), num2.end());

        int mx = max( num1.size(), num2.size() );
        int mn = min( num1.size(), num2.size() );

        if(mx!=mn){
            for(int i=1; i<=mx-mn; i++)
               if(num1.size()<num2.size())
                    num1 += "0";
                else num2 += "0";
        }

        int carry = 0, cnt = 0;
        int len = max( num1.size(), num2.size() );

        for(int i=0; i<len; i++){
            int sum = (num1[i]-48) + (num2[i]-48) + carry;
            carry = sum/10;

            if(carry) cnt++;
        }

        if( cnt==0 ) printf("No carry operation.\n");
        else if( cnt>1 ) printf("%d carry operations.\n", cnt);
        else printf("%d carry operation.\n", cnt);
    }

    return 0;
}
