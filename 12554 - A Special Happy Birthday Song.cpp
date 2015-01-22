#include<cstdio>
#include<iostream>
#include<map>
#include<vector>
#include<string>
#include<cstring>

using namespace std;

int main()
{
    string s[] = {"Happy", "birthday", "to", "you", "Happy", "birthday", "to", "you", "Happy", "birthday", "to", "Rujia", "Happy", "birthday", "to", "you"};
    string s1[105];
    int n;

    while(cin >> n){
        getchar();
        for(int i=0; i<n; i++){
            cin >> s1[i];
        }

        int cnt=1;
        int w=0;
        int p=0;
        while( cnt<n || (w%16)!=15 ){

            cout << s1[p%n] << ": " << s[w%16] << "\n";
            cnt++;p++;w++;
        }
        cout << s1[p%n] << ": " << s[w%16] << "\n";
    }

    return 0;
}

