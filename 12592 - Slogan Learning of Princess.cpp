#include<cstdio>
#include<iostream>
#include<map>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>

using namespace std;

int main()
{
    map <string, string> m;
    string s1, s2;
    int n;

    cin >> n;
    getchar();

    while( n-- ){

        getline(cin, s1);
        getline(cin, s2);
        m[s1]=s2;
    }

    cin >> n;
    getchar();

    while( n-- ){

        getline(cin, s1);
        cout << m[s1] << "\n";
    }

    return 0;
}
