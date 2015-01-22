#include<cstdio>
#include<iostream>
#include<string>
#include<vector>
#include<cctype>

using namespace std;

int main()
{
    string s[4] = { "`1234567890-=",
                    "qwertyuiop[]\\",
                    "asdfghjkl;'",
                    "zxcvbnm,./",
                    };
    char ch;

    while( scanf("%c", &ch) == 1 ){

        if(ch=='\n') printf("\n");

        else if(ch==' ') printf(" ");

        else{
            ch = tolower(ch);
            for(int i=0; i<4; i++){
                for(int j=0; j<s[i].size(); j++){
                    if(ch==s[i][j]){
                        if(j-2>=0) printf("%c", s[i][j-2]);
                        else printf("%c", s[i][j]);
                        i=4; break;
                    }
                }
            }
        }
    }
    return 0;
}
