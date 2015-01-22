#include<cstdio>
#include<iostream>
#include<vector>

using namespace std;

 vector <int> v;


int tarif(int sec, int cost){

    int total = 0;

    for(int i=0; i<v.size(); i++){
        int c = ( (v[i] / sec) + 1 ) * cost;
        total+=c;
    }

    return total;
}

int main()
{
    int tc, n, sec;

    scanf("%d", &tc);

    for(int kase=1; kase<=tc; kase++){

        scanf("%d", &n);

        for(int i=0; i<n; i++){
            scanf("%d", &sec);
            v.push_back(sec);
        }

        int mileCost = tarif(30, 10);
        int juiceCost = tarif(60, 15);

        if( mileCost == juiceCost){
            printf("Case %d: Mile Juice %d\n", kase, mileCost);
        }
        else if( mileCost < juiceCost){
             printf("Case %d: Mile %d\n", kase, mileCost);
        }
        else{
             printf("Case %d: Juice %d\n", kase, juiceCost);
        }

        v.clear();
    }

    return 0;
}
