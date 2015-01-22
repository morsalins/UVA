#include<cstdio>
#include<iostream>
#include<map>
#include<string>
#include<cstring>
#include<vector>
#include<algorithm>

using namespace std;

map <string, string> mapa;

void initial(void){

    mapa[".-"] = "A";mapa[".---"] = "J";mapa[".-."] = "R";mapa["--.."] = "Z";mapa["---.."] = "8";
    mapa["-..."] = "B";mapa["-.-"] = "K";mapa["..."] = "S";mapa["-----"] = "0";mapa["----."] = "9";
    mapa["-.-."] = "C";mapa[".-.."] = "L";mapa["-"] = "T";mapa[".----"] = "1";mapa[".-.-.-"] = ".";
    mapa["-.."] = "D";mapa["--"] = "M";mapa["..-"] = "U";mapa["..---"] = "2";mapa["--..--"] = ",";
    mapa["."] = "E";mapa["-."] = "N";mapa["...-"] = "V";mapa["...--"] = "3";mapa["..--.."] = "?";
    mapa["..-."] = "F";mapa["---"] = "O";mapa[".--"] = "W";mapa["....-"] = "4";mapa[".----."] = "'";
    mapa["--."] = "G";mapa[".--."] = "P";mapa["-..-"] = "X";mapa["....."] = "5";mapa["-.-.--"] = "!";
    mapa["...."] = "H";mapa["--.-"] = "Q";mapa["-.--"] = "Y";mapa["-...."] = "6";mapa["-..-."] = "/";
    mapa[".."] = "I";mapa["--.-"] = "Q";mapa["-.--.-"] = ")";mapa["--..."] = "7";mapa["-.--."] = "(";
    mapa[".-..."] = "&";mapa["---..."] = ":";mapa["-.-.-."] = ";";mapa["-...-"] = "=";mapa[".-.-."] = "+";
    mapa["-....-"] = "-";mapa["..--.-"] = "_";mapa[".-..-."] = "\"";mapa[".--.-."] = "@";mapa[""] = "";

return;
}

int main()
{
    //freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);

    initial();

    int tc, Case=1;
    string s;
    string::iterator it, prev, next;

    cin >> tc;
    getchar();

    while( tc-- ){

        getline(cin, s);

        prev = next = s.begin();
        cout << "Message #" << Case++ << "\n";
        while(next!=s.end()){
            next = find(prev, s.end(), ' ');
            string temp(prev, next);
            cout << mapa[temp];
            prev = next+1;
            while(*prev==' '){
                cout << " ";
                prev++;
			}
        }
        printf("\n");
        if(tc>0)
            printf("\n");
    }

    return 0;

}
