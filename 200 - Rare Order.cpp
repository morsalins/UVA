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

map <char, vector <char> > MP;
map <char, int> in;
queue <char> Q;
vector <char> ans;

void toposort(void){

    while( !Q.empty() ){

        char u = Q.front();
        Q.pop();

        ans.push_back(u);

        for(int i=0; i<MP[u].size(); i++){
            char v = MP[u][i];
            in[v]--;
            if( in[v]==0 ) Q.push(v);
        }
    }
}

int main()
{
    //READ("in.txt");

    int tc, Case=1;
    VS vs;
    string s;
    int cnt = 0;

    while( cin >> s ){

        if( s=="#" ) break;
        else{
            vs.push_back(s);
            cnt++;
        }
    }

    for(int i=0; i<cnt-1; i++){

        int len = min( vs[i].size(), vs[i+1].size() );

        for(int j=0; j<len; j++){
            if( vs[i][j] != vs[i+1][j] ){
                MP[ vs[i][j] ].push_back( vs[i+1][j] );
                in[ vs[i+1][j] ]++;
                break;
            }
        }
    }

    for(map <char, vector <char> > :: IT it = MP.begin(); it!=MP.end(); it++){

        if( in[ it->first ] == 0 )
            Q.push( it->first );
    }

    toposort();

    for(int i=0; i<ans.size(); i++){

        cout << ans[i];
    }

    puts("");

    return 0;
}

