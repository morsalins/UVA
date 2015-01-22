#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<cstring>
#include<string>
#include <sstream>
#include<set>
#include<stack>
#include<queue>
#include<cctype>
#include<math.h>
#include<cstdlib>

#define I64 long long int
#define SIZE 1000
#define MAX 30000
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

int parents[MAX+5], Size[MAX+5];

int findparent(int r){

    if( parents[r]==r ) return r;

    return parents[r] = findparent( parents[r] );
}

int main()
{
    int tc, n, m;

    scanf("%d", &tc);

    while( tc-- ){

        scanf("%d %d", &n, &m);

        for(int i=1; i<=n+5; i++){
            parents[i] = i;
            Size[i] = 1;
        }

        int u, v, parent_of_u, parent_of_v, largestgroup=1;

        for(int i=1; i<=m; i++){

             scanf("%d %d", &u, &v);

             parent_of_u = findparent(u);
             parent_of_v = findparent(v);

             if( parent_of_u!=parent_of_v ){

                if( Size[parent_of_u] < Size[parent_of_v]) swap(parent_of_u, parent_of_v);

                parents[parent_of_v] = parent_of_u;

                Size[ parent_of_u ] += Size[ parent_of_v ];

                largestgroup = max(largestgroup, Size[ parent_of_u ]);
             }
        }


        printf("%d\n", largestgroup);
    }
    return 0;
}

