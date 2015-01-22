#include<cstdio>
#include<iostream>
#include<string>
#include<cmath>

using namespace std;

int main()
{
    string s;
    int tc;

    cin >> tc;
    getchar();

    while( tc-- ){

        getline(cin, s);

        int len = s.size();
        int root = sqrt(len);

        if( root*root == len ){

            for(int i=0; i<root; i++){
                for(int j=i; j<len; j+=root){
                    printf("%c", s[j]);
                }
            }
        }
        else printf("INVALID");

        printf("\n");
    }
}
