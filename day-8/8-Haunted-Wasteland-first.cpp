#include<bits/stdc++.h>
using namespace std;

int main() {

    ifstream fileInput("input.txt");
    freopen("output.txt","w",stdout);

    string conditions;
    string line;
    map<string,pair<string,string>> myMap;

    int count = 0;
    string text;
    while(getline(fileInput,line)) {
        if(count==0) {
            conditions = line;
        }
        else if(!line.empty()){
            string key = line.substr(0,3);
            int val1 = (int)line.find('(');
            string valOne = line.substr(val1+1,3);
            int val2 = (int)line.find(')');
            string valTwo = line.substr(val2-3,3);
            myMap[key] = {valOne,valTwo};
        }
        count++;
    }

    count = 0;
    int i = 0;
    while(true) {
        if(text=="ZZZ") break;
        if(count==0) {
            pair<string,string> p = myMap["AAA"];
            if(conditions[i] == 'L') {
                text = p.first;
            }
            else {
                text = p.second;
            }
        }
        else {
            pair<string,string> p = myMap[text];
            if(conditions[i] == 'L') {
                text = p.first;
            }
            else {
                text = p.second;
            }
        }
        count++;
        i = (int)(i+1)%conditions.size();
    }
//    for(auto it:myMap) {
//        cout<<it.first<<" "<<it.second.first<<" "<<it.second.second<<endl;
//    }
    cout<<count;



    return 0;
}