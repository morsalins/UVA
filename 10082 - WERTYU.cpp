#include<cstdio>
#include<string>

using namespace std;

int main()
{
    char ch;

    string s[4]= { {"1234567890-="},
                   {"QWERTYUIOP[]\\"},
                   {"ASDFGHJKL;'"},
                   {"ZXCVBNM,./"}
                 };

    while( scanf("%c", &ch) == 1){

        if( ch == '\n' ) printf("\n");

        else if( ch == 32 ) printf(" ");

        else{
            for(int i=0; i<4; i++){
                int len = s[i].size();
                for(int j=1; j<len; j++){
                    if( s[i][j] == ch ){
                        printf("%c", s[i][j-1]);
                        i=4;break;
                    }
                }
            }
        }
    }

    return 0;
}
