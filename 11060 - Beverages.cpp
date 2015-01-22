#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>
#include <functional>
#include <map>
#include <cstring>
#include <string>
#include <sstream>
#include <set>
#include <stack>
#include <queue>
#include <cctype>
#include <math.h>
#include <cstdlib>

using namespace std;

#define I64 long long int
#define INF 0x7f7f7f7f
#define pii pair<int, int>
#define pis pair<int, string>
#define SIZE 1000
#define MAX 200
#define VI vector <int>
#define VS vector <string>
#define MSI map <string, int>
#define MIS map <int, string>
#define MSS map <string, string>
#define pb push_back
#define pob pop_back
#define mp make_pair
#define IT iterator
#define SET(a, b) memset( a, b, sizeof (a) )
#define READ(f) freopen(f, "r", stdin);
#define WRITE(f) freopen(f, "w", stdout);

map <string, VS> MP;
map <string, int> in;
map <string, int> apr;
VS S;
VS ans;
priority_queue <pis, vector<pis>, greater<pis> > Q;

void toposort(){

    while( !Q.empty() ){

        string u = Q.top().second;
        //int apr = Q.top().first;
        Q.pop();

        ans.pb(u);

        for(int i=0; i<MP[u].size(); i++){

            string v = MP[u][i];
            in[ v ]--;
            if( in[v]==0 ) Q.push( pis(apr[v], v) );
        }
    }

    return;
}

int main()
{
   // READ("in.txt");
    //WRITE("out.txt");

    int tc, Case=1;
    string s1, s2;
    int n, m;
    char dump[2];

    while( scanf("%d", &n)==1 ){

        gets(dump);

        for(int i=1; i<=n; i++){
            cin >> s1;
            S.pb( s1 );
            apr[s1] = i;
        }

        scanf("%d", &m);
        gets(dump);

        for(int i=1; i<=m; i++){

            cin >> s1 >> s2;
            MP[ s1 ].pb(s2);
            in[ s2 ]++;
        }

        for(int i=0; i<S.size(); i++){

            if( in[ S[i] ] == 0 )
                Q.push( pis(apr[ S[i] ], S[i]) );
        }

        toposort();

        printf("Case #%d: Dilbert should drink beverages in this order: ", Case++);
        for(int i=0; i<ans.size(); i++){
            cout << ans[i];
            if(i<ans.size()-1) printf(" ");
        }

        printf(".\n\n");

        gets(dump);

        MP.clear();
        in.clear();
        apr.clear();
        S.clear();
        ans.clear();
    }

    return 0;
}

