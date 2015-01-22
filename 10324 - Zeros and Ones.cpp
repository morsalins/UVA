#include<cstdio>
#include<iostream>
#include<string>
#include<cctype>

using namespace std;

int main()
{
    //freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);

    string s;
    int n, i, j;
    int cases = 1;

    while( cin >> s ){

        if( s.empty() ) break;

        cin >> n;
        printf("Case %d:\n", cases++);
        for(int loop=1; loop<=n; loop++){

            cin >> i >> j;
            bool flag = true;

            int mn = min(i, j), mx = max(i, j);

            for(int index=mn+1; index<=mx; index++){

                if( s[mn] != s[index]){
                    flag = false;
                    break;
                }
            }

            if( flag ){
                printf("Yes\n");
            }
            else printf("No\n");
        }
        //getchar();
    }

    return 0;
}
