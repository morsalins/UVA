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
#define pci pair<char, int>
#define pic pair<int, char>
#define SIZE 1000
#define MAX 1000
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

bool comp(const pair <I64, char> &l, const pair <I64, char> &r){
    if(l.first==r.first)
        return l.second<r.second;
    return l.first<r.first;
}

int main()
{
    //READ("in.txt");

    int Case=1, n, w;
    char u, v, srcS, srcM, type, dir;
    char dump[2];

    while(  scanf("%d", &n) ){

        if( n==0 ) return 0;

        map <char, bool> occur;
        map <char, vector < pci > > gs, gm;
        map <char, I64> ds,dm;
        char nodes[MAX+5];
        int idx = 0;

        for(int i=1; i<=n; i++){

            gets(dump);
            scanf("%c %c %c %c %d", &type, &dir, &u, &v, &w);
            //printf("%c %c %c %c %d\n", type, dir, u, v, w);
            if( type=='Y' ){
                if( dir=='B' ){
                    gs[u].pb( make_pair(v, w) );
                    gs[v].pb( make_pair(u, w) );
                }
                else gs[u].pb( make_pair(v, w) );
            }

            else if( type=='M' ){
                if( dir=='B' ){
                    gm[u].pb( make_pair(v, w) );
                    gm[v].pb( make_pair(u, w) );
                }
                else gm[u].pb( make_pair(v, w) );
            }

            if( !occur[u] ){
                occur[u] = true;
                nodes[idx++] = u;
                ds[u] = INF;
                dm[u] = INF;
            }
            if( !occur[v] ){
                occur[v] = true;
                nodes[idx++] = v;
                ds[v] = INF;
                dm[v] = INF;
            }
        }
        gets(dump);
        scanf("%c %c", &srcS, &srcM);

        priority_queue <pic, vector<pic>, greater<pic> > PQ;

        PQ.push( pii(0, srcS) );
        ds[srcS] = 0;
        while( !PQ.empty() ){
            char u = PQ.top().second;
            for(int i=0; i<gs[u].size(); i++){
                char v = gs[u][i].first;
                int w = gs[u][i].second;
                if( ds[v] > ds[u]+w ){
                    ds[v] = ds[u]+w;
                    PQ.push( pii(ds[v], v ) );
                }
            }
            PQ.pop();
        }

        PQ.push( pii(0, srcM) );
        dm[srcM] = 0;
        while( !PQ.empty() ){
            char u = PQ.top().second;
            for(int i=0; i<gm[u].size(); i++){
                char v = gm[u][i].first;
                int w = gm[u][i].second;
                if( dm[v] > dm[u]+w ){
                    dm[v] = dm[u]+w;
                    PQ.push( pii(dm[v], v ) );
                }
            }
            PQ.pop();
        }

        I64 min_energy = INF;
        vector < pair <I64, char> > ans;
        for(int i=0; i<idx; i++){
            if( dm[nodes[i]]<INF && ds[nodes[i]]<INF ){
                if( dm[nodes[i]] + ds[nodes[i]] <= min_energy ){
                    min_energy = dm[nodes[i]] + ds[nodes[i]];
                    ans.pb( make_pair( min_energy, nodes[i] ) );
                }
            }
        }

        sort( ans.begin(), ans.end(), comp );

        if( ans.empty() ) printf("You will never meet.\n");
        else{
            printf("%lld", min_energy);
            for(int i=0; i<ans.size() && ans[i].first==min_energy; i++){
                cout << " " << ans[i].second;
            }
            puts("");
        }
    }

    return 0;
}


