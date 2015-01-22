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
#define SIZE 1000000
#define MAX 100000
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
    int occur, ttl;
    int next[26];

    void init(){
        SET( next, 0 );
        occur = 0;
        ttl = 0;
    }
} T[MAX+7];

char s[SIZE+7];
int ptr;

void Insert( void ){

    int cur = 0;
    stack <int> S;

    for(int i=0; s[i]; i++){
        int k = s[i] - 97;
        if( T[cur].next[k] == 0 ){
            T[cur].next[k] = ptr;
            T[ptr].init();
            ptr++;
        }

        cur = T[cur].next[k];
        T[cur].occur++;
        S.push(cur);
    }

    while( !S.empty() ) {

        int pos = S.top();
        int total = 0;

        if( T[pos].occur == 1 ) T[pos].ttl = 1;
        else {
            for(int i=0; i<26; i++){
                if( T[pos].next[i] )
                    total += T[ T[pos].next[i] ].ttl;
            }
            T[pos].ttl = total + T[pos].occur;
        }

        S.pop();
    }

    return;
}

int main()
{
    //READ("in.txt");
    int Case=1, n;
    char dump[2];

    int tc; scanf("%d", &tc);

    while( tc-- ){

        scanf("%d", &n); gets(dump);
        ptr = 1;
        T[0].init();

        while( n-- ){
            gets( s );
            Insert();
        }

        int ans = 0;
        for(int i=0; i<26; i++) ans += T[ T[0].next[i] ].ttl;

        printf("%d\n", ans);
    }

    return 0;
}

