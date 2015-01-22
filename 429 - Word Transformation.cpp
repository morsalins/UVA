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
#define ff first
#define ss second
#define SET(a, b) memset( a, b, sizeof (a) )
#define READ(f) freopen(f, "r", stdin);
#define WRITE(f) freopen(f, "w", stdout);

queue <string> Q;

bool isOneDiffer (string a, string b){

    if( a.size()!=b.size() ) return false;

    int cnt = 0;
    for(int i=0; i<a.size(); i++){
        if( a[i]!=b[i] )
            cnt++;
    }

    if(cnt == 1) return true;
    else return false;
}

int main()
{
    //READ("in.txt");
    int Case=1;
    char dump[2];
    string node;

    int tc; scanf("%d", &tc);
    gets(dump); gets(dump);

    while( tc-- ){

        VS nodes;
        map <string, VS> G;

        while( getline(cin, node) ){
            if( node == "*" ) break;
            nodes.pb(node);
        }

        for(int i=0; i<nodes.size()-1; i++){
            for(int j=i+1; j<nodes.size(); j++){

                if( isOneDiffer( nodes[i], nodes[j] ) ){
                    G[ nodes[i] ].pb( nodes[j] );
                    G[ nodes[j] ].pb( nodes[i] );
                }
            }
        }

        string line, s1, s2;

        while( getline(cin, line) ){
            if( line.size()==0 ) break;

            string :: IT ptr = find(line.begin(), line.end(), ' ');
            s1.assign(line.begin(), ptr);
            s2.assign(ptr+1, line.end());

            map <string, int> dist;
            map <string, bool> visited;

            Q.push(s1);
            dist[s1] = 0;
            visited[s1] = true;

            while( !Q.empty() ){
                string u = Q.front();
                for(int i=0; i<G[u].size(); i++){
                    string v = G[u][i];
                    if( !visited[v] ){
                        visited[v] = true;
                        dist[v] = dist[u] + 1;
                        Q.push(v);
                    }
                }
                Q.pop();
            }

            cout << s1 << " " << s2 << " " << dist[s2] << "\n";
        }
        if(tc) puts("");
    }

    return 0;
}

