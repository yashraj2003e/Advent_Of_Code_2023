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
    vector<string> startingNode;
    while(getline(fileInput,line)) {
        if(count==0) {
            conditions = line;
        }
        else if(!line.empty()){
            string key = line.substr(0,3);
            if(key.back()=='A') startingNode.push_back(key);
            string valOne = line.substr((int)line.find('(')+1,3);
            string valTwo = line.substr((int)line.find(')')-3,3);
            myMap[key] = {valOne,valTwo};
        }
        count++;
    }

    vector<int> v;
    for(int x=0;x<startingNode.size();x++) {
        text = startingNode[x];
        count = 0;
        int i = 0;
        while(true) {
            if(text.back()=='Z') {
                v.push_back(count);
                break;
            }

            pair<string,string> p = myMap[text];

            if(conditions[i]=='L') {
                text = p.first;
            }
            else {
                text = p.second;
            }

            i=(i+1)%conditions.size();
            count++;
        }
    }

    long long first = (v[0]*v[1])/gcd(v[0],v[1]);
    for(int i=2;i<v.size();i++) {
        first = (first*v[i])/gcd(first,v[i]);
    }
    cout<<first<<endl;
    return 0;
}