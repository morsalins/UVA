#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
    vector <int> v;
    int tc, n, speed;

    scanf("%d", &tc);

    for(int kase=1; kase<=tc; kase++){

        scanf("%d", &n);

        for(int i=0; i<n; i++){
            scanf("%d", &speed);
            v.push_back(speed);
        }

        sort( v.begin(), v.end() );

        printf("Case %d: %d\n", kase, v.back());
        v.clear();
    }

    return 0;
}
