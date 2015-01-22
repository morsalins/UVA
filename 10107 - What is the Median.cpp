#include<cstdio>
#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<cmath>
#include<algorithm>

using namespace std;

int main()
{
    vector <unsigned int> v;
    unsigned int n;

    while( scanf("%u", &n) != EOF ){

        v.push_back(n);

        sort(v.begin(), v.end());

        int len = v.size();

        if( len&1 ){
            cout << v[len/2] << "\n";
        }
        else{
            cout << (v[len/2] + v[(len/2)-1]) / 2 << "\n";
        }
    }

    return 0;
}
