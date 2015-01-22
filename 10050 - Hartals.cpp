#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
    vector <bool> days;
    int cnt, d, p, h, tc;

    scanf("%d", &tc);

    while(tc--){

        scanf("%d %d", &d, &p);

        cnt = 0;
        days.push_back(true);
        for(int i=1; i<=d; i++){
            days.push_back(true);
        }

        for(int i=1; i<=p; i++){
            scanf("%d", &h);
            for(int j=h; j<=d; j+=h){
                days[j] = false;
            }
        }

        for(int i=1; i<=d; i++){
            if( days[i]==false && i%7!=0 && i%7!=6 )
                cnt++;
        }

        printf("%d\n", cnt);

        days.clear();
    }

    return 0;
}
