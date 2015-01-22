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
    bool flag;
    int next[10];

    void init(){
        flag = false;
        SET( next, 0 );
    }

} T[MAX+7];

bool possible;
int ptr;

void Insert ( char *s ){

    int cur = 0;

    for(int i=0; s[i]; i++){

        int k = s[i] - 48;

        if( T[cur].next[k] == 0 ){
            T[cur].next[k] = ptr;
            T[ptr].init();
            ptr++;
        }
        else{
            if( T[ T[cur].next[k] ].flag || !s[i+1] ){
                possible = false;
                return;
            }
        }

        cur = T[cur].next[k];
    }

    T[cur].flag = true;
    return;
}

int main()
{
    //READ("in.txt");
    int Case=1, n;
    char dump[2];
    char data[15];

    int tc; scanf("%d", &tc);

    while( tc-- ){

        scanf("%d", &n); gets(dump);
        possible = true;
        ptr = 1;
        T[0].init();

        while( n-- ){
            gets(data);
            if( possible ) Insert( data );
        }
        if( possible ) printf("YES\n");
        else printf("NO\n");
    }

    return 0;
}

