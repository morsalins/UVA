#include<cstdio>
#include<iostream>

using namespace std;

int main()
{
    int sq, animals, fe, result, sum;
    int tc, farmers;

    cin >> tc;

    while(tc--){

        cin >> farmers;
        sum = 0;

        for(int i=1; i<=farmers; i++){
            cin >> sq >> animals >> fe;

            result = sq * fe;

            sum += result;
        }

        cout << sum << "\n";
    }

    return 0;
}
