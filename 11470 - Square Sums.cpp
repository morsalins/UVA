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
#define pii pair<int, int>
#define SIZE 1000
#define MAX 20000
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

using namespace std;

int main()
{
    int n, data, Case=1;
    int arr[15][15];

    while( scanf("%d", &n)==1 ){

        if( n==0 ) return 0;

        SET( arr, 0 );

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                scanf("%d", &data);
                arr[i][j] = data;
            }
        }

         /*for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cout << arr[i][j] << " ";
            }
            puts("");
        }*/

        vector <int> v;
        int fr=0, fc=0, lr=n-1, lc=n-1;
        int loops, loop=1;

        if( n%2==0 ) loops = (n/2);
        else loops = (n/2) + 1;

        while( loop<=loops ){

            int sum = 0;

            for(int i=fc; i<=lc; i++){
                sum += arr[fr][i];
            }

            for(int i=fr+1; i<=lr; i++){
                sum += arr[i][fc];
            }

            for(int i=fc+1; i<=lc; i++){
                sum += arr[lr][i];
            }

            for(int i=fr+1; i<lr; i++){
                sum += arr[i][lc];
            }

            v.push_back(sum);

            fr++; fc++; lr--; lc--;
            loop++;

        }

        printf("Case %d:", Case++);
        for(int i=0; i<v.size(); i++){
            cout << " " << v[i];
        }
        puts("");
    }
    return 0;
}

