#include<bits/stdc++.h>
using namespace std;

int main() {
    freopen("output.txt","w",stdout);
    ifstream inputFile("input.txt");

    vector<string> arr;

    string line;
    while(getline(inputFile,line)) {
        arr.push_back(line);
    }

    long long total = 0;
    for(auto & i : arr) {
        int num1 = INT_MIN;
        int num2 = INT_MIN;
        for(int j=0;j<i.size();j++) {
            if((int)i[j]>=48 && (int)i[j]<=57) {
                num1=i[j]-'0';
                break;
            }
        }
        for(int j=i.size()-1;j>=0;j--) {
            if((int)i[j]>=48 && (int)i[j]<=57) {
                num2=i[j]-'0';
                break;
            }
        }
        total+=(num1*10+num2);
    }

    cout<<total<<endl;

}