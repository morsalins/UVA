#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<cstring>
#include<string>
#include <sstream>
#include<stack>
#include<set>
#include<queue>
#include<cctype>
#include<math.h>
#include<cstdlib>

#define I64 long long int
#define SIZE 1000
#define MAX 128
#define VI vector <int>
#define VS vector <string>
#define MSI map <string, int>
#define MIS map <int, string>
#define MSS map <string, string>
#define pb push_back
#define pob pop_back
#define IT iterator
#define SET(a, b) memset( a, b, sizeof (a) )

using namespace std;

bool visited[MAX];
bool graph[MAX][MAX];
int R, C, cnt, len;

void DFS(int u){

    visited[u] = true;

    for(int v=0; v<len; v++){
        if( graph[u][v] ){
            if( !visited[v] )
                DFS(v);
        }
    }

    return;
}

int main()
{
    //freopen("i.txt", "r", stdin);

    int tc, largestNode;
    VI nodes;
    char s[3];
    char str;

    //cin >> tc;
    scanf("%d\n\n", &tc);

    while( tc-- ){

        gets( s );
        largestNode = s[0] - 65;

        for(int i=0; i<=largestNode; i++){
            nodes.pb(i);
        }

        for(int i=0; i<30; i++){
			SET( graph[i], false );
		}

        while( gets( s ) && s[0] ){
            //cout << s << "\n";
            graph[ s[0]-65 ][ s[1]-65 ] = true;
            graph[ s[1]-65 ][ s[0]-65 ] = true;
        }

        SET(visited, false);
        cnt= 0;

        /*for(set<char>::iterator it=nodes.begin(); it!=nodes.end(); it++)
            cout << *it << " ";
        cout << "\n";*/

        len = nodes.size();
        for(int i=0; i<len; i++){
            //cout << *it << " ";
            if( !visited[i] ){
                //cout << *it << " ";
                cnt++,
                DFS(i);
            }
        }
        cout << cnt << "\n";
        if( tc )printf("\n");
        nodes.clear();
    }

    return 0;
}

