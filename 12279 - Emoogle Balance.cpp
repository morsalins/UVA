#include<cstdio>
#include<vector>

using namespace std;

int main()
{
    int n, number, cnt, kase = 1;
    vector <int> v;

    while( scanf("%d", &n) == 1 ){

        if(n==0) break;

        cnt = 0;

        for(int i=0; i<n; i++){
            scanf("%d", &number);
            v.push_back(number);
        }

        for(int i=0; i<v.size(); i++){
            if(v[i]==0)cnt++;
        }

        printf("Case %d: %d\n", kase++, (n-cnt)-cnt);
        v.clear();
    }
    return 0;
}
