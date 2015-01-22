#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
#include<cctype>

using namespace std;

string s;

bool isvowel(char ch){

    ch = tolower(ch);

    return ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u';
}

void encrypt(long int st, long int e){

    if( isvowel(s[st]) ){
        for(long int i=st ;i<=e; i++){
            printf("%c", s[i]);
        }
        printf("ay");
    }
    else{
       for(long int i=st+1 ;i<=e; i++){
            printf("%c", s[i]);
        }
        printf("%cay", s[st]);
    }
}

int main()
{
    long int i;

    while( getline(cin, s) ){

        long int len = s.size();

        for(i=0; i<len; i++){
            if( !isalpha(s[i]) )
               printf("%c", s[i]);

           else{

                long int pos = i;
                while( i<len && isalpha(s[i]) )
                    i++;

                encrypt(pos, i-1);
                if(i<len)printf("%c", s[i]);
            }
        }
        printf("\n");
    }

    return 0;
}
