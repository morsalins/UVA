#include<cstdio>
#include<iostream>
#include<vector>

using namespace std;

int main(){

    int n, s[60], cases=0;

    while( cin >> n ){

        int sum=0;

        if(n==0) break;

        for(int i=0; i<n; i++){

            cin >> s[i];
            sum = sum + s[i];
        }

        int avg = sum/n;
        int step=0;

        for(int i=0; i<n; i++){

            if(s[i]>avg){
                step = step + (s[i]-avg);
            }
        }

        printf("Set #%d\n", ++cases);
        printf("The minimum number of moves is %d.\n\n", step);
    }

    return 0;
}
