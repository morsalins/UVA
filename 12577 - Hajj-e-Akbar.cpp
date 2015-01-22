#include<iostream>
#include<string>

using namespace std;

int main()
{
    string s;
    int kase=1;

    while(1){

        cin >> s;

        if( s=="*") break;

        else {

            if( s == "Hajj" ) cout << "Case "<<kase++<<": Hajj-e-Akbar" <<endl;
            else if ( s == "Umrah") cout << "Case "<<kase++<<": Hajj-e-Asghar" <<endl;
        }
    }

    return 0;
}
