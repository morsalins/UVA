#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
#include<map>

using namespace std;

int main()
{
    vector<int> v;
    map<int, int> m;
    int n;

    while( cin >> n ){
        m[n]++;
        v.push_back(n);
    }

    for(vector<int>::iterator it=v.begin(); it!=v.end(); it++){

        if(m[*it]!=0){
            cout << *it << " " << m[*it] << "\n";
            m[*it]=0;
        }
    }
    return 0;
}
