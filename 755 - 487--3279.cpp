#include<cstdio>
#include<iostream>
#include<map>
#include<algorithm>
#include<string>
#include<cstring>
#include<cctype>
#include<vector>

using namespace std;

map <char, char> m;
map< string, int> out;

void initialize(void){

    m['A'] = '2';m['B'] = '2';m['C'] = '2';
    m['D'] = '3';m['E'] = '3';m['F'] = '3';
    m['G'] = '4';m['H'] = '4';m['I'] = '4';
    m['J'] = '5';m['K'] = '5';m['L'] = '5';
    m['M'] = '6';m['N'] = '6';m['O'] = '6';
    m['P'] = '7';m['R'] = '7';m['S'] = '7';
    m['T'] = '8';m['U'] = '8';m['V'] = '8';
    m['W'] = '9';m['X'] = '9';m['Y'] = '9';

    return ;
}

int main()
{
    freopen("i.txt", "r", stdin);
    freopen("o.txt", "w", stdout);

    int tc;
    long int lines;
    string s, output;

	initialize();

    cin >> tc;

	while( tc-- ){
        getchar();
        cin >> lines;
        getchar();
        bool flag = false;
        while( lines-- ){
            cin >> s;

            int len = s.size();
            for(int i=0, j=1; i<len; i++){
                if(j==4){
					output+='-';
					j++;
					if(s[i]!='-'){
                        if(isalpha(s[i])){
                            output+=m[ s[i] ] ;
                            j++;
                        }
                        else{
                            output+=s[i];
                            j++;
                        }
					}
				}
                else{
                    if(s[i]!='-'){
                        if(isalpha(s[i])){
                            output+=m[ s[i] ] ;
                            j++;
                        }
                        else{
                            output+=s[i];
                            j++;
                        }
                    }
                }
            }
            out[output]++;
            if( !flag && out[output]>1 )flag = true;
            output.clear();
        }

        if(flag){
            for(map<string,int>::iterator it=out.begin(); it!=out.end(); it++){
                if(it->second>1)
                    cout << it->first << " " << it->second << "\n";
            }
        }

        else cout << "No duplicates.\n";

        out.clear();
        if(tc>0)printf("\n");
    }

    return 0;
}
