#include<cstdio>
#include<iostream>
#include<vector>

using namespace std;

int main()
{
    int n, tc;
    int freq[10];

    scanf("%d", &tc);

    while( tc-- ){

        scanf("%d", &n);

        for(int i=0; i<=9; i++){
            freq[i] = 0;
        }

        for(int i=1; i<=n; i++){
            int j=i;
            while(j>0){
                int index = j%10;
                freq[index]++;
                j /= 10;
            }
        }

        for(int i=0; i<9; i++){
            printf("%d ", freq[i]);
        }
         printf("%d\n", freq[9]);
    }

    return 0;
}
