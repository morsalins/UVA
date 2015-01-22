#include<cstdio>
#include<iostream>
#include<map>
#include<string>
#include<cstring>
#include<algorithm>
#include<cctype>
#include<vector>

using namespace std;

int main()
{
    map <string, int> m;
    map <string, int>::iterator mIt;
    string alpha = "abcdefghijklmnopqrstuvwxyz";
    string::iterator it, it1, it2, it3, it4;
    long int cnt=1;

    for(it=alpha.begin(); it!=alpha.end(); it++){
       string s;
       s+=*it;
       m[s]=cnt;
       cnt++;
    }

    for(it=alpha.begin(); it!=alpha.end()-1; it++){
        for(it1=it+1; it1!=alpha.end(); it1++){
            string s;
            s+=*it;
            s+=*it1;
            m[s]=cnt;
            cnt++;
        }
    }


    for(it=alpha.begin(); it!=alpha.end()-2; it++){
        for(it1=it+1; it1!=alpha.end()-1; it1++){
            for(it2=it1+1; it2!=alpha.end(); it2++){
                string s;
                s+=*it;
                s+=*it1;
                s+=*it2;
                m[s]=cnt;
                cnt++;
            }
        }
    }

    for(it=alpha.begin(); it!=alpha.end()-3; it++){
        for(it1=it+1; it1!=alpha.end()-2; it1++){
            for(it2=it1+1; it2!=alpha.end()-1; it2++){
                for(it3=it2+1; it3!=alpha.end(); it3++){
                    string s;
                    s+=*it;
                    s+=*it1;
                    s+=*it2;
                    s+=*it3;
                    m[s]=cnt;
                    cnt++;
                }
            }
        }
    }

     for(it=alpha.begin(); it!=alpha.end()-4; it++){
        for(it1=it+1; it1!=alpha.end()-3; it1++){
            for(it2=it1+1; it2!=alpha.end()-2; it2++){
                for(it3=it2+1; it3!=alpha.end()-1; it3++){
                    for(it4=it3+1; it4!=alpha.end(); it4++){
                        string s;
                        s+=*it;
                        s+=*it1;
                        s+=*it2;
                        s+=*it3;
                        s+=*it4;
                        m[s]=cnt;
                        cnt++;
                    }
                }
            }
        }
    }

    string s1;
    while(cin >> s1)
        cout << m[s1] << "\n";


    return 0;
}
