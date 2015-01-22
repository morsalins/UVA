#include<cstdio>
#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

int main()
{
    unsigned long int n;
    int tc,cases=0,rootn;

    cin >> tc;

    while( tc-- ){
        vector <int> v;

        cin >> n;

        for(int i=2; i*i<=n; i++){

            if(n%i==0){
                v.push_back(i); v.push_back(n/i);
            }
            if(v.size()==4)break;
        }

        printf("Case #%d: %lu = %d * %d = %d * %d\n",
               ++cases, n, v[0], v[1], v[2], v[3]);
    }

    return 0;
}
