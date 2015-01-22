#include<cstdio>
#include<iostream>
#include<map>
#include<algorithm>
#include<string>
#include<set>
#include<vector>
#include<cctype>

using namespace std;

int main()
{
    //freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);

    map <string, string> student;
    map <string, int> project;
    map <string, bool>  prev, present, flag;
    map <string, int>::iterator mIt;
    set <int> number;
    set <int>::iterator sIt;
    string temp, s;

    while( getline(cin, s) ){
        if(s[0]=='0') break;

        else if(s[0]=='1'){

            for(mIt=project.begin(); mIt!=project.end(); mIt++){
                int n = mIt->second;
                number.insert(n);
            }

            sIt = number.end();
            sIt--;
            while(sIt!=number.begin()){
                for(mIt=project.begin(); mIt!=project.end(); mIt++){
                    if(mIt->second==*sIt){
                        cout << mIt->first << " " << mIt->second << "\n";
                        //project.erase(mIt);
                        //mIt--;
                   }
                }
				sIt--;
            }
            for(mIt=project.begin(); mIt!=project.end(); mIt++){
                if(mIt->second==*sIt){
                    cout << mIt->first << " " << mIt->second << "\n";
                    //project.erase(mIt);
                    //mIt--;
                }
            }

			project.clear();
            prev.clear();
			student.clear();
			flag.clear();
			number.clear();
        }

		else if( !islower(s[0]) ){
            present.clear();
            project[s]=0;
            temp=s;
        }

		else if(islower(s[0])){
            if( !present[s] && !prev[s] ){
                project[temp]++;
                student[s] = temp;
                present[s] = true;
                prev[s] = true;
            }

			else if( !present[s] && prev[s] ){
                if(!flag[s]){
                    project[ student[s] ]--;
                    flag[s] = true;
                }
            }
		}
    }

    return 0;
}
