#include<cstdio>
#include<iostream>
#include<map>
#include<string>
#include<vector>
#include<cmath>
#include<algorithm>

using namespace std;

int main()
{
    //freopen("o.txt", "w", stdout);

    map <char, int> m;

    m['A'] = 0;
    m['B'] = 1;
    m['C'] = 2;
    m['D'] = 3;
    m['E'] = 0;
    m['F'] = 1;
    m['G'] = 2;
    m['H'] = 0;
    m['I'] = 0;
    m['J'] = 2;
    m['K'] = 2;
    m['L'] = 4;
    m['M'] = 5;
    m['N'] = 5;
    m['O'] = 0;
    m['P'] = 1;
    m['Q'] = 2;
    m['R'] = 6;
    m['S'] = 2;
    m['T'] = 3;
    m['U'] = 0;
    m['V'] = 1;
    m['W'] = 0;
    m['X'] = 2;
    m['Y'] = 0;
    m['Z'] = 2;

    string s;

    while( cin >> s ){

        if(m[ s[0] ])cout << m[s[0]];

        int l = s.size();
        for(int i=1; i<l; i++){

            if( m[ s[i] ] && m[ s[i-1] ] != m[ s[i] ] )
                cout << m[s[i]];
        }

        printf("\n");
    }

    return 0;
}
