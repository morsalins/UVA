#include<cstdio>
#include<iostream>
#include<string>
#include<cctype>

using namespace std;

int main()
{
    char ch;
    string s[10] = {"0", "1", "ABC", "DEF", "GHI", "JKL", "MNO", "PQRS", "TUV", "WXYZ" };

    while( scanf("%c", &ch) == 1 ){

        if(ch=='\n')printf("\n");
        else if(ch=='-')printf("-");
        else{
            for(int i=0; i<10; i++){
                for(int j=0; j<s[i].size(); j++){
                    if(ch==s[i][j]){
                        printf("%d", i);
                    }
                }
            }
        }

    }

    return 0;
}
