#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<cstring>
#include<string>
#include <sstream>
#include<cctype>
#include<cmath>
#include<cstdlib>

#define I64 long long int
#define SIZE 1000
#define VI vector <int>
#define VS vector <string>
#define MSI map <string, int>
#define MIS map <int, string>


using namespace std;

vector <long long int> v;

int main()
{
    long long int n, m;

    while( cin >> n >> m ){

        if( n<2 || m<2 || n<m){
            cout << "Boring!\n";
            continue;
        }

        //f(n, m);
        bool flag = true;
        while (flag && n>1){

            if(n%m!=0){
                flag = false;
            }

            else{
                v.push_back(n);
                n = n/m;
            }
        }

        if( flag ){
           int len = v.size();
           for(int i=0; i<len; i++){
                cout << v[i] << " ";
            }
            cout << "1\n";
        }

        else cout << "Boring!\n";

        v.clear();
    }

    return 0;
}

