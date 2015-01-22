#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>

using namespace std;

void rev(char *p){

    char s[100];
    strcpy(s,p);
    int len = strlen(s);

    for(int i=len-1; i>=0 ; i--){
        printf("%c", s[i]);
    }

    return ;
}

int main()
{
    char s[1000];
    char *p;

    while( gets(s) ){

        p = strtok(s, " ");
        rev(p);

        while( (p = strtok(NULL, " ")) != NULL ){
            printf(" ");
            rev(p);
        }

        printf("\n");
    }

    return 0;
}
