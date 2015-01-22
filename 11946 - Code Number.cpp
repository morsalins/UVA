#include<cstdio>
#include<iostream>
#include<string>
#include<ctype.h>

using namespace std;

char decode[11] = {'O', 'I', 'Z', 'E', 'A', 'S', 'G', 'T', 'B', 'P'};

int main()
{
    int tc;
    char ch;

    cin >> tc;
    getchar();

    while( (ch=getchar())!= EOF ){

        if( isdigit(ch) ){
            printf("%c", decode[ch-48]);
        }
        else {
            printf("%c", ch);
        }
    }

    return 0;
}
