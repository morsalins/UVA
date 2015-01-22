#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include <queue>
#include<cstring>
#include<string>
#include <sstream>
#include<cctype>
#include<cmath>
#include<cstdlib>
#include <functional>

#define I64 long long int
#define SIZE 1000
#define INF 126
#define MAX 2500
#define pii pair <int, int>
#define pis pair <int, string>
#define VI vector <int>
#define VS vector <string>
#define MSI map <string, int>
#define MIS map <int, string>
#define MSS map <string, string>

using namespace std;

vector <pii> G[MAX+5];
int dist[MAX+5];
pii cnt;
int freq[MAX+100];

void dijk(int src){

    priority_queue <pii, vector <pii>, greater<pii> > Q;

    Q.push( pii(0, src) );
    dist[src] = 0;
    bool flag[MAX+5];
    memset(flag, false, sizeof flag);

    while( !Q.empty() ){

        int u = Q.top().second;

        for(int i=0; i<G[u].size(); i++){

            int v = G[u][i].first;
            int w = G[u][i].second;

            if( dist[v] > dist[u] + w ){

                if( flag[v] && freq[ dist[v] ]>0 ){
                    freq[ dist[v] ]--;
                }

                dist[v] = dist[u] + w;
                flag[v] = true;
                freq[ dist[v] ]++;

                if( cnt.first < freq[ dist[v] ] ){
                    cnt.first = freq[ dist[v] ];
                    cnt.second = dist[v];
                }

                Q.push( pii(dist[v], v) );
            }
        }

        Q.pop();
    }

    return;
}

int main()
{
    int E, tc, u, v;

    while( cin >> E ){

        int n;

        for(int i=0; i<E; i++){

            scanf("%d", &n);
            while(n--){
                //cout << "hmm";
                scanf("%d", &v);
                G[i].push_back( pii(v, 1) );
            }
        }

        scanf("%d", &tc);
        int src;


        while( tc-- ){

            scanf("%d", &src);

            cnt = pii(0, 0);

            if( G[src].empty() ) printf("0\n");

            else{
                memset(freq, 0, sizeof freq);
                memset(dist, INF, sizeof dist);
                dijk(src);
                printf("%d %d\n", cnt.first, cnt.second);
            }
        }

        for(int i=0; i<MAX+5; i++) G[i].clear();
    }

    return 0;
}

