#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<cstring>
#include<map>
#include<algorithm>
#include<cctype>
#include<set>

using namespace std;

#define VI vector<int>
#define SI set<int>
#define MSS map<string, string>
#define MSI map<string, int>
#define MVI map<vector<int>, int>
#define VIIT vector<int>::iterator
#define MSSIT map<string, string>::iterator
#define MSIIT map<string, int>::iterator

int main(){

    //freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);

    int n, course;

    while(cin >> n){

        if(n==0) return 0;

        MVI m;
        int mx=0;
        for(int i=1; i<=n; i++){
            VI v;
            for(int j=1; j<=5; j++){
                cin >> course;
                v.push_back(course);
            }

            sort(v.begin(), v.end());
            m[v]++;
            if(m[v]>mx) mx=m[v];
        }

        int cnt = 0;
        for(MVI::iterator it=m.begin(); it!=m.end(); it++){
            if(it->second==mx)cnt++;
        }

        cout << mx*cnt << "\n";
    }

    return 0;
}
