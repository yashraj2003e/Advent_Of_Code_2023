#include<bits/stdc++.h>
//#include <fstream>
//#include <vector>
//#include <sstream>
using namespace std;

int main() {

    ifstream fileInput("input.txt");
    freopen("output.txt","w",stdout);

    string line;
    long long total = 0;
    while(getline(fileInput,line)) {
        istringstream iss(line);
        int number;

        vector<long long> val;
        while (iss >> number) {
            val.push_back(number);
        }

        vector<vector<long long>> totalArr;
        totalArr.push_back(val);
        while (true) {
            for (long long i = 0; i <= val.size() - 1; i++) {
                val[i] = val[i + 1] - val[i];
            }
            val.pop_back();

            totalArr.push_back(val);
            int c = 0;
            for(long long i : val) {
                if(i==0) c++;
            }
            if(c==val.size()) break;
        }

        for(long long i = totalArr.size()-2;i>=0;i--) {
            long long s = totalArr[i+1].back() + totalArr[i].back();
            totalArr[i].push_back(s);
        }
        total += totalArr[0].back();
    }
    cout << total << endl;
}