#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<cstring>
#include<string>
#include <sstream>
#include<cctype>
#include<cmath>
#include<cstdlib>

#define I64 long long int
#define SIZE 1000
#define VI vector <int>
#define VS vector <string>
#define MSI map <string, int>
#define MIS map <int, string>

using namespace std;

int main()
{
    VI lady, luchu;
    int n, q;

        scanf("%d", &n);

        int data;
        for(int i=0; i<n; i++){
            scanf("%d", &data);
            lady.push_back(data);
        }

        scanf("%d", &q);
        for(int i=0; i<q; i++){
            scanf("%d", &data);
            luchu.push_back(data);
        }

        int len = luchu.size();
        int len1 = lady.size();

        for(int i=0; i<len; i++){
            if( len1==1 && luchu[i]==lady[0]) printf("X X");

            else if( luchu[i]<lady[0] ) printf("X %d", lady[0]);

            else if( luchu[i]==lady[0] ){
                int upper = upper_bound( lady.begin(), lady.end(), luchu[i]) - lady.begin();
                printf("X %d", lady[upper]);
            }

            else if( luchu[i]>lady[len1-1] ) printf("%d X", lady[len1-1]);

            else if( luchu[i]==lady[len1-1] ){
                int lower = lower_bound( lady.begin(), lady.end(), luchu[i]) - lady.begin();
                printf("%d X", lady[lower-1]);
            }

            else{
                int lower = lower_bound( lady.begin(), lady.end(), luchu[i]) - lady.begin();
                int upper = upper_bound( lady.begin(), lady.end(), luchu[i]) - lady.begin();
                printf("%d %d", lady[lower-1], lady[upper]);
            }

            printf("\n");
        }

    return 0;
}
