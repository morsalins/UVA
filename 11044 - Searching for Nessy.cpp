#include<iostream>

using namespace std;

int main()
{
    int t, n, m, row, col;

    cin >> t;

    while(t--){

        cin >> n >> m;

        cout << (n/3)* (m/3) << "\n";
    }

    return 0;
}
