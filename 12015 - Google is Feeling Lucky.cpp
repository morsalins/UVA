#include<iostream>
#include<cstdio>
#include<string>
#include<vector>

using namespace std;

int main()
{
    string url;
    int r, tc, maximum;
    vector <string> w;

    cin >> tc;

    for(int kase=1; kase<=tc; kase++){

        maximum = 0;

        for(int i=1; i<=10; i++){
            cin >> url >> r;

            if(r>maximum){
                maximum = r;
                w.clear();
                w.push_back(url);
            }

            else if(r==maximum)
                w.push_back(url);
        }

        cout << "Case #" << kase << ":\n";
        for(int i=0; i<w.size(); i++){
            cout << w[i] << "\n";
        }

        w.clear();
    }

    return 0;
}
