#include<cstdio>
#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<map>

using namespace std;

int main()
{
    int n, dist;
    vector <int> v;

    while(cin >> n){

        if(n==0)break;

        for(int i=1; i<=n; i++){
            cin >> dist;
            v.push_back(dist);
        }

        sort(v.begin(), v.end());

        bool flag = false;

        if(v[0]>200)flag = false;

        else if( 2*(1422 - *(v.end()-1)) > 200 ) flag = false;

        else {
            for(vector<int>::iterator it=v.begin(); it!=v.end(); it++){
                if(*it+200 >= 1422){
                    flag = true;
                    break;
                }

                if(it!=v.end()-1 && *it+200 < *(it+1)){
                    flag = false;
                    break;
                }
            }
        }

        if(flag)cout << "POSSIBLE\n";
        else cout << "IMPOSSIBLE\n";

        v.clear();
    }

    return 0;
}
