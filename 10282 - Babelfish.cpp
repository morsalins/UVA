#include<cstdio>
#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<cmath>
#include<algorithm>

using namespace std;

int main()
{
    //freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);

    string s1, s2;
    string::iterator it, it2;
    map <string , string> m;

    while(1){

        getline(cin, s1);

		if(s1.empty()) break;

		it = find(s1.begin(), s1.end(), ' ' );
		it2 = s1.end();

		s2.assign(it+1, it2);

		m[s2].assign(s1.begin(), it);
    }

    while( cin >> s1 ){

        if( !m[s1].empty() )cout << m[s1] << "\n";
        else cout << "eh\n";
    }

    return 0;
}
