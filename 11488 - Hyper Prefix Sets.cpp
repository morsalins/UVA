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

    int next[2];
    int occur;

    void init(){
        SET( next, 0 );
        occur = 0;
    }

} T[MAX+7];

int ptr, ans;

void Insert( char *s ){

    int cur = 0;

    for(int i=0; s[i]; i++){

        int k = s[i] - 48;

        if( T[cur].next[k] == 0 ) {
            T[cur].next[k] = ptr;
            T[ptr].init();
            ptr++;
        }

        cur = T[cur].next[k];
        T[cur].occur++;
        ans = max( ans, (i+1)*T[cur].occur );
    }

    return;
}

int main()
{
    //READ("in.txt");
    int Case=1, n;
    char dump[2], s[210];

    int tc; scanf("%d", &tc);

    while( tc-- ){

        scanf("%d", &n);gets(dump);
        ptr = 1;
        ans = 0;
        T[0].init();

        while( n-- ){
            gets( s );
            Insert( s );
        }
        printf("%d\n", ans);
    }

    return 0;
}
