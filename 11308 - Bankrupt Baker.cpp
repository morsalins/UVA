#include<cstdio>
#include<iostream>
#include<map>
#include<string>
#include<cstring>
#include<vector>
#include<set>
#include<algorithm>
#include<cctype>
#include<cmath>

using namespace std;

void print(string s){

    for(string::iterator it=s.begin(); it!=s.end(); it++){
        char ch = *it;
        if(isalpha(ch)) printf("%c", toupper(ch));
        else printf("%c", ch);
    }

    return;
}

int main()
{
    //freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);

    int m, n, c, u, k, tc;
    long long int budget, b;
    string binders, recip, s, s1;

    cin >> tc;

    while( tc-- ){
        getchar();
        map <string, int> cost, recipes;
        set <long int> st;

        getline(cin, binders);
        cin >> m >> n >> budget;

        for(int i=1; i<=m; i++){
            cin >> s >> c;
            cost[s]=c;
        }

        for(int i=1; i<=n; i++){
            getchar();
            getline(cin, recip);

            b=0;
            cin >> k;
            for(int j=1; j<=k; j++){
                cin >> s >> u;
                b += cost[s]*u;
            }

            if(b<=budget){
                recipes[recip]=b;
                st.insert(b);
            }
        }

        print(binders);
        cout << "\n";

        if(recipes.empty()) cout << "Too expensive!\n";

        else{
                for(set<long int>::iterator it=st.begin(); it!=st.end(); it++){
                    for(map<string, int>::iterator it1=recipes.begin(); it1!=recipes.end(); it1++){
                        if(*it==it1->second){
                            cout << it1->first << "\n";
                        }
                    }
                }
        }
        cout << "\n";
    }

    return 0;
}
