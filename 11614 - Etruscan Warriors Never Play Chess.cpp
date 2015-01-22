#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>

using namespace std;

int main()
{
    long long int n;
    int tc;

    cin >> tc;

    while( tc-- ){

        cin >> n;

        long result = (long)((sqrt(1+8*n)-1))/2;

        cout << result << "\n";
    }

    return 0;
}
