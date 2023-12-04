#include<bits/stdc++.h>
using namespace std;

int main() {
    ifstream inputFile("input.txt");
    freopen("output.txt","w",stdout);

    string line;
    vector<int> winningList;
    vector<int> totalList;
    long long total = 0;
    while(getline(inputFile,line)) {

        int x = 0;

        while(line[x]!=':') {
            x++;
        }

        x++;

        line = line.substr(x,line.size());

        int i = 0;

        while(line[i]!='|') {

            int curNum = 0;
            int base = 0;
            int flag = 0;

            while((int)line[i]>=48 && (int)line[i]<=57) {
                curNum = curNum*base + line[i]-'0';
                flag = 1;
                if(base==0) {
                    base+=1;
                    base*=10;
                }
                i++;
            }

            if(flag==1) {
                winningList.push_back(curNum);
            }
            i++;
        }

        i++;

        while(i<line.size()) {

            int curNum = 0;
            int base = 0;
            int flag = 0;

            while((int)line[i]>=48 && (int)line[i]<=57) {
                curNum = curNum*base + line[i]-'0';
                flag = 1;
                if(base==0) {
                    base+=1;
                    base*=10;
                }
                i++;
            }

            if(flag==1) {
                totalList.push_back(curNum);
            }
            i++;
        }

        int present = 0;

        for(auto it:winningList) {
            if(find(totalList.begin(),totalList.end(),it)!=totalList.end()) {
                present++;
            }
        }
        cout<<present<<endl;
        total += (pow(2,present-1));
        winningList.clear();
        totalList.clear();
    }

    cout<<total<<endl;



}