#include <iostream>

using namespace std;

int main()
{
    long long int n;

       while( cin >> n ){

        if(n==0) break;

        n = n%9;

        if(n==0) n = 9;

        cout << n << "\n";
    }

    return 0;
}
