#include<cstdio>
#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<cstring>
#include<cctype>
#include<algorithm>
#include<functional>

using namespace std;

struct information{
    string dept, addrs, home, work, box;
};

typedef struct information info;

int main()
{
    info temp;
    vector <info> v;
    map <string, int> faculty;
    map <string, string> lastName;
    string name, profile, d;
    char space = ' ';
    int department, cnt=0;

    cin >> department;
    getchar();

    while( department-- ){

        getline(cin, d);
        while(getline(cin, profile) && profile[0]!='\0'){

            temp.dept = d;

            string::iterator it=profile.begin(), it1=profile.begin(), End = profile.end();

            it1 = find(it, End, ',');
            name.append(it, it1);
            name += ' ';
            it = it1+1;

            it1 = find(it, End, ',');
            name.append(it, it1);
            name += ' ';
            it = it1+1;

            it1 = find(it, End, ',');
            name.append(it, it1);
            string t;
            t.assign(it, it1);
            it = it1+1;

            lastName[t] = name;
            faculty[name] = cnt;
            cnt++;

            it1 = find(it, End, ',');
            temp.addrs.append(it, it1);
            it = it1+1;

            it1 = find(it, End, ',');
            temp.home.append(it, it1);
            it = it1+1;

            it1 = find(it, End, ',');
            temp.work.append(it, it1);
            it = it1+1;

            temp.box.append(it, End);

            v.push_back(temp);
            name.clear();
            temp.addrs.clear();
            temp.home.clear();
            temp.work.clear();
            temp.box.clear();
        }
    }

    for(map<string, string>::iterator iter=lastName.begin(); iter!=lastName.end(); iter++){

        string s = iter->second;
        int index = faculty[s];

        printf("----------------------------------------\n");
        cout << s << "\n";
        cout << v[index].addrs << "\n";
        cout << "Department: " << v[index].dept << "\n";
        cout << "Home Phone: " << v[index].home << "\n";
        cout << "Work Phone: " << v[index].work << "\n";
        cout << "Campus Box: " << v[index].box << "\n";
    }

    return 0;
}
