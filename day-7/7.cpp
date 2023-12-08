#include<bits/stdc++.h>
using namespace std;

int main() {

    ifstream fileinput("input.txt");
    freopen("output.txt","w",stdout);

    string line;
    long long total = 0;
    while(getline(fileinput,line)) {

        unordered_map<char,int> myMap;

        string text = line.substr(0,5);

        string val = line.substr(5,line.size()-1);

        int x = 0;
        while(isspace(val[x])) {
            x++;
        }

        val = val.substr(x,val.size()-1);

        text.erase(remove(text.begin(),text.end(),' '),text.end());

        for(auto it:line) {
            myMap[it]++;
        }

        if(myMap.size()==1) {

        }


    }





}