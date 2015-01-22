#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>

using namespace std;

int main()
{
    int tc, x, y, d;

    cin >> tc;

    while( tc-- ){

        cin >> x >> y >> d;

        int result = d*(x+(x-y))/(x+y);;

        result<=0 ? cout << "0\n" : cout << result << "\n";
    }

    return 0;
}
