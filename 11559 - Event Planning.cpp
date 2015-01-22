#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
   // freopen("i.txt" , "r" , stdin);
	//freopen("o.txt" , "w" , stdout);

    long long int n, b, h, w, p, a, total;
    vector <long long int> cost;

    while( scanf("%lld%lld%lld%lld", &n, &b, &h, &w) == 4 ){

        for(int hotel=1; hotel<=h; hotel++){

            cin >> p;
            total = n*p;
            for(int week=1; week<=w; week++){
                cin >> a;
                if(a>=n && total<=b) {
                    cost.push_back(total);
                }
            }
        }

        sort( cost.begin(), cost.end());
        if(!cost.empty())
            cout << cost.front() << "\n";
        else cout << "stay home\n";

        cost.clear();
    }

    return 0;
}
