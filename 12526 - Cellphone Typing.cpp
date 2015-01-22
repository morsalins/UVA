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
#define SIZE 100000
#define MAX 1000000
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

class Trie{
public:
    int next[26], store[5];
    bool child[26];
    int childs, pos;
    bool flag, press;

    void init( ){
        SET( next, 0 ); SET( child, false );
        childs = 0; pos = 0; flag = false; press = false;
    }
} T[MAX+7];

char s[SIZE+7][100];
int ptr;

void Insert( char *s ){

    int cur = 0;

    for(int i=0; s[i]; i++){
        int k = s[i] - 97;
        if( T[cur].next[k] == 0 ){
            T[cur].next[k] = ptr;
            T[cur].store[ T[cur].pos++ ] = ptr;
            if( !T[cur].child[k] ){
                T[cur].child[k] = true;
                T[cur].childs++;
            }
            T[ptr].init();
            if( T[cur].flag || !cur ) T[ptr].press = true;
            else if( T[cur].childs > 1 ){
                while( T[cur].pos )
                    T[ T[cur].store[ --T[cur].pos ] ].press = true;
            }
            ptr++;
        }
        cur = T[cur].next[k];
    }

    T[cur].flag = true;
    for(int i=0; i<26; i++)
        if( T[cur].next[i] ){
            T[ T[cur].next[i] ].press = true;
        }

    return;
}

int Typing( char *s ){

    int cur = 0;
    int ret = 0;
    for(int i=0; s[i]; i++){
        int k = s[i] - 97;
        if( T[ T[cur].next[k] ].press ) ret++;
        cur = T[cur].next[k];
    }

    return ret;
}

int main()
{
    //READ("in.txt");
    int Case=1, n;
    char dump[2];

    while( scanf("%d", &n) == 1 ){

        gets(dump);
        T[0].init();
        ptr = 1;

        for(int i=0; i<n; i++)
            Insert( gets( s[i] ) );

        int a = 0;

        for(int i=0; i<n; i++){
            a += Typing( s[i] );
        }
        float ans = (float)(a);
        printf("%.2f\n", ans/n);
    }

    return 0;
}

