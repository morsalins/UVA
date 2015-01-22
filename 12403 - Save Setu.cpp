#include<iostream>
#include<string>

using namespace std;

int main()
{
    int t;
    long long int total=0, donat;
    string s;

   cin >> t;

    while(t--){

        cin >> s;

        if( s == "donate"){
           cin >> donat;
           total = total+donat;
        }

        else if ( s == "report"){
            cout << total << endl;
        }
    }

    return 0;
}
