#include<cstdio>
#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main(){

    string s;

    while(1){

        cin >> s;

        if(s=="0") break;

        int len = s.size();
        int r=0, sum=0;

        for(int i=0; i<len; i++){

            sum = r*10 + (s[i]-48);
            r = sum%17;
        }

        if(r==0) cout << "1\n";
        else cout << "0\n";
    }
    return 0;
}
