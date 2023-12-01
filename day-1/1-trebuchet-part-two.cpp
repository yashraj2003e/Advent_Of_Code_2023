#include<bits/stdc++.h>
using namespace std;

static bool cmp(pair<string,int> a,pair<string,int> b) {
    return a.second < b.second;
}

int main() {
    freopen("output.txt","w",stdout);
    ifstream inputFile("input.txt");

    unordered_map<string,int> myMap = {{"one",1},{"two",2},{"three",3},{"four",4},{"five",5},{"six",6},{"seven",7},{"eight",8},{"nine",9}};

    vector<string> arr;

    string line;
    while(getline(inputFile,line)) {
        arr.push_back(line);
    }

    long long total = 0;
    for(int i=0;i<arr.size();i++) {
        vector<pair<string,int>> outputVec;
        string currentStr = arr[i];

        for(auto& it:myMap) {
            string val = it.first;
            auto it1 = currentStr.find(val);
            if(it1!=string::npos) {
                outputVec.emplace_back(val,it1);
//                break;
            }
        }

        int num1 = INT_MIN;
        int num2 = INT_MIN;

        for(int j=0;j<arr[i].size();j++) {
            if((int)arr[i][j]>=48 && (int)arr[i][j]<=57) {
                num1=arr[i][j]-'0';
                outputVec.emplace_back(to_string(num1),j);
                break;
            }
        }

        for(int j=arr[i].size()-1;j>=0;j--) {
            if((int)arr[i][j]>=48 && (int)arr[i][j]<=57) {
                num2=arr[i][j]-'0';
                outputVec.emplace_back(to_string(num2),j);
                break;
            }
        }

        sort(outputVec.begin(),outputVec.end(),cmp);
//        for(auto it:outputVec) {
//            cout<<it.first<<" "<<it.second<<endl;
//        }
        int first = outputVec[0].first.size()==1 ? stoi(outputVec[0].first) : myMap[outputVec[0].first];
        int second = outputVec.back().first.size()==1 ? stoi(outputVec.back().first) : myMap[outputVec.back().first];
        first*=10;
        total += first;
        total+=second;
        cout<<first+second<<endl;
    }

    cout<<total<<endl;
}