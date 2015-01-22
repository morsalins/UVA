#include<iostream>
#include<string>

using namespace std;

int main()
{
    string s, num[3] = {"one", "two", "three"};
    int t, cnt;

    cin >> t;

    while(t--){

        cin >> s;

        for(int i=0; i<3; i++){
            cnt = 0;
            for(int j=0; j<num[i].size(); j++){
                if(s[j]==num[i][j])cnt++;
            }

            if(num[i].size()-cnt==1 || num[i].size()-cnt==0){
                cout << i+1 << "\n";
                break;
            }
        }
    }
    return 0;
}
