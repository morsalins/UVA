#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int parseInt( string s){

    int num=0;
    for(int i=0; i<s.size(); i++){
        num = num*10 + (s[i]-48);
    }

    return num;
}


int gcd(int a, int b){

    if(b==0)return a;
    else return gcd(b, a%b);
}

int main()
{
    string s;
    int tc, num;
    vector <int> v;

    cin >> tc;
	getchar();

    while(tc--){

        char ch;
        while( scanf("%c", &ch) ){

            if(ch=='\n'){
				if(!s.empty()){
                    num = parseInt(s);
                    v.push_back(num);
					s.clear();
                }
				break;
			}

            else if(ch>='0' && ch<='9'){
                s += ch;
            }

            else if(ch==' '){
                if(!s.empty()){
                    num = parseInt(s);
                    v.push_back(num);
					s.clear();
                }
            }
        }

        sort( v.begin(), v.end() );
        //reverse( v.begin(), v.end() );
        int mg=0;
        for(int i=0; i<v.size()-1; i++){
            for(int j=i+1; j<v.size(); j++){

                int g = gcd(v[j], v[i]);
                mg = max(g, mg);
            }
        }

        cout << mg << "\n";
        v.clear();
    }

    return 0;
}
