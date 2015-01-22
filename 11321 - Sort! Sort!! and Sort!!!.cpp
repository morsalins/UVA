#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<string>
#include<map>
#include<functional>

using namespace std;

struct pairs{
    int v;
    int r;
} p;

bool comp (struct pairs left, struct pairs right){

    if(left.r == right.r){

        if( left.v&1 && right.v&1 ) return left.v>right.v;
        if( !(left.v&1) && !(right.v&1) ) return left.v<right.v;
        if( (left.v&1 && !(right.v&1)) && (left.v>right.v) ) return left.v>right.v;
        if( (left.v&1 && !(right.v&1)) && (left.v<right.v) ) return left.v<right.v;
        if( ((!left.v&1) && right.v&1) && (left.v>right.v) ) return right.v<left.v;
        if( ((!left.v&1) && right.v&1) && (left.v<right.v) ) return right.v>left.v;
    }

    return left.r<right.r;
}

int main()
{
    int n, m;
    vector <struct pairs> v;

    while(cin >> n >> m){

        if(n==0 || m==0){
            cout << n << " " << m << "\n";
            return 0;
        }

        for(int i=1; i<=n; i++){
            cin >> p.v;
            p.r = (p.v % m);
            v.push_back(p);
        }

        sort(v.begin(), v.end(), comp);

        int len = v.size();
        cout << n << " " << m << "\n";
        for(int i=0; i<len; i++){
            cout << v[i].v << "\n";
        }

        v.clear();
    }

    return 0;
}
