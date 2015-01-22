#include<cstdio>
#include<iostream>
#include<map>
#include<string>
#include<cstring>
#include<vector>

using namespace std;

int Case=1;

void print(int n, int days){

    if( n>0 && n<=days ) printf("Case %d: Yesss\n", Case++);
    else if( n>0 && n<=(days+5) ) printf("Case %d: Late\n", Case++);
    else if( n==0 || n>(days+5) ) printf("Case %d: Do your own homework!\n", Case++);

    return;
}

int main()
{
    //freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);

    int tc, n, d, days;
    string s;

    cin >> tc;

    while( tc-- ){
        map <string, int> m;
        cin >> n;
        getchar();
        for(int i=1; i<=n; i++){
            cin >> s;
            cin >> d;
            m[s] = d;
        }

        cin >> days;
        getchar();
        cin >> s;
        print(m[s], days);
        //m.clear();
    }

    return 0;
}
