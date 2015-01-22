#include<cstdio>
#include<iostream>
#include<string>
#include<vector>
#include<cctype>
#include<cmath>

using namespace std;

int main()
{
    string name, name1;
    int sum, sum1;

    while( getline(cin, name) ){

        //getchar();
        getline(cin, name1);

        int len = name.size();
        int len1 = name1.size();
        sum = sum1 = 0;

        for(int i=0; i<len; i++){
            if( isalpha(name[i]) )
                sum = sum + (toupper(name[i]) - 64);
        }

        for(int i=0; i<len1; i++){
            if( isalpha(name1[i]) )
                sum1 = sum1 + (toupper(name1[i]) - 64);
        }

        if( sum%9==0 ) sum = 9;
        else sum = sum%9;

        if( sum1%9==0 ) sum1 = 9;
        else sum1 = sum1%9;

        if( sum>=sum1 ) printf("%.2f %c\n", (float(sum1)/float(sum))*100.0, '%');
        else printf("%.2f %c\n", (float(sum)/float(sum1))*100.0, '%');
    }

    return 0;
}
