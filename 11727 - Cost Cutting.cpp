#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
    int test, f, s, t;
    vector < int > salary;

    scanf("%d", &test);

    for(int kase=1; kase<=test; kase++){

        scanf("%d%d%d", &f, &s, &t);

        salary.push_back(f);
        salary.push_back(s);
        salary.push_back(t);

        sort( salary.begin(), salary.end());

        printf("Case %d: %d\n", kase, salary[1]);
        salary.clear();
    }

    return 0;
}
