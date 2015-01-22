#include<stdio.h>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

int main(){

    int t, n, d, min_dist;
    vector <int> x;

    scanf("%d", &t);

    while(t--){

        scanf("%d", &n);

        min_dist = 0;

        for(int i=0; i<n; i++){
            scanf("%d", &d);
            x.push_back(d);
        }

       sort( x.begin(), x.end());

       for(int i=0; i<x.size()-1; i++){
            min_dist += abs(x[i]-x[i+1]);
       }

       printf("%ld\n", min_dist*2);

       x.clear();
    }

    return 0;
}

