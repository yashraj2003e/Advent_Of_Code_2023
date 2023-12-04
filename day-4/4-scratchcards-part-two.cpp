#include<bits/stdc++.h>
using namespace std;

int main() {
    ifstream inputFile("input.txt");
    freopen("output.txt","w",stdout);

    string line;
    vector<int> winningList;
    vector<int> totalList;
    vector<int> instance(221,1);
    long long total = 0;
    int lineNum = 0;
    while(getline(inputFile,line)) {
        lineNum++;
        int x = 0;

        while (line[x] != ':') {
            x++;
        }

        x++;

        line = line.substr(x, line.size());

        int i = 0;

        while (line[i] != '|') {

            int curNum = 0;
            int base = 0;
            int flag = 0;

            while ((int) line[i] >= 48 && (int) line[i] <= 57) {
                curNum = curNum * base + line[i] - '0';
                flag = 1;
                if (base == 0) {
                    base += 1;
                    base *= 10;
                }
                i++;
            }

            if (flag == 1) {
                winningList.push_back(curNum);
            }
            i++;
        }

        i++;

        while (i < line.size()) {

            int curNum = 0;
            int base = 0;
            int flag = 0;

            while ((int) line[i] >= 48 && (int) line[i] <= 57) {
                curNum = curNum * base + line[i] - '0';
                flag = 1;
                if (base == 0) {
                    base += 1;
                    base *= 10;
                }
                i++;
            }

            if (flag == 1) {
                totalList.push_back(curNum);
            }
            i++;
        }

        int present = 0;

        for (auto it: winningList) {
            if (find(totalList.begin(), totalList.end(), it) != totalList.end()) {
                present++;
            }
        }

        for (int repeat = 0; repeat < instance[lineNum];repeat++) {
            for (int ff = lineNum + 1; ff < instance.size() && ff < lineNum + present+1; ff++) {
                instance[ff]++;
            }
        }

        winningList.clear();
        totalList.clear();
    }

    for(int i=1;i<=lineNum;i++) {
        total+=instance[i];
    }

    cout<<total<<endl;



}