#include<cstdio>
#include<iostream>
#include<map>
#include<vector>
#include<string>
#include<cstring>
#include<algorithm>

using namespace std;

int main()
{
    //freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);

    int n, m;
    long long int sum;
    long int value;
    map <string, long int> mp;
    string::iterator prev, next;
    string s;

    while( cin >> m >> n ){

        for(int i=1; i<=m; i++){
            cin >> s >> value;
            mp[s]=value;
        }
        getchar();
		sum = 0;
		int j=1;
		while(j<=n){

            getline(cin, s);

            if(s=="."){
                j++;
				cout << sum << "\n";
				sum = 0;
            }
            else{
                prev = next = s.begin();
                while( next!=s.end() ){
                    next = find(prev, s.end(), ' ');
                    string temp(prev, next);
                    sum += mp[ temp ];
                    if(next!=s.end())prev = next+1;
                }
            }
        }
    }
    //getch();
    return 0;
}
