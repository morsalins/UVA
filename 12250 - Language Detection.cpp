#include<cstdio>
#include<iostream>
#include<string>

using namespace std;

int main()
{
    string s;
    int kase = 1;

    while( getline(cin,s) ){

        if( s=="#") break;

        else if ( s=="HELLO" ) printf("Case %d: ENGLISH\n", kase++);
        else if ( s=="HOLA" ) printf("Case %d: SPANISH\n", kase++);
        else if ( s=="HALLO" ) printf("Case %d: GERMAN\n", kase++);
        else if ( s=="BONJOUR" ) printf("Case %d: FRENCH\n", kase++);
        else if ( s=="CIAO" ) printf("Case %d: ITALIAN\n", kase++);
        else if ( s=="ZDRAVSTVUJTE" ) printf("Case %d: RUSSIAN\n", kase++);

        else printf("Case %d: UNKNOWN\n", kase++);
    }
}
