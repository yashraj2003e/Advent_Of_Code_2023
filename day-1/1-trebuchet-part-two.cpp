#include<bits/stdc++.h>
using namespace std;

/*
 * The solution can be optimized, but it took me a lot of time, im not updating it.
 */

int main() {
    freopen("output.txt","w",stdout);
    ifstream inputFile("input.txt");

    unordered_map<string,int> myMap = {{"one",1},{"two",2},{"three",3},{"four",4},{"five",5},{"six",6},{"seven",7},{"eight",8},{"nine",9}};
    vector<string> wordVec = {"one","two","three","four","five","six","seven","eight","nine"};
    vector<string> arr;

    string line;
    while(getline(inputFile,line)) {
        arr.push_back(line);
    }

    long long total = 0;
    vector<pair<string,int>> outputVec;

    for(int i=0;i<arr.size();i++) {
        int first = INT_MIN;
        int firstInd = 0;
        int secondInd = 0;
        int second = INT_MIN;
        string word = arr[i];

        for(int x=0;x<word.size();x++) {
            string threeWords = word.substr(x,3);
            string fourWords = word.substr(x,4);
            string fiveWords = word.substr(x,5);

            auto it = find(wordVec.begin(),wordVec.end(),threeWords);
            auto it1 = find(wordVec.begin(),wordVec.end(),fourWords);
            auto it2 = find(wordVec.begin(),wordVec.end(),fiveWords);

            if(it!=wordVec.end()) {
                if(first==INT_MIN) {
                    first = myMap[threeWords];
                    second = first;
                    firstInd = x;
                    secondInd = firstInd;
                }
                else {
                    if(x > secondInd) {
                        secondInd = x;
                        second = myMap[threeWords];
                    }
                }
            }

            if(it1!=wordVec.end()) {
                if(first==INT_MIN) {
                    first = myMap[fourWords];
                    firstInd = x;
                    second = first;
                    secondInd = firstInd;
                }
                else {
                    if(x > secondInd) {
                        secondInd = x;
                        second = myMap[fourWords];
                    }
                }
            }

            if(it2!=wordVec.end()) {
                if(first==INT_MIN) {
                    first = myMap[fiveWords];
                    firstInd = x;
                    second = first;
                    secondInd = firstInd;
                }
                else {
                    if(x > secondInd) {
                        secondInd = x;
                        second = myMap[fiveWords];
                    }
                }
            }
        }

        for(int ind = 0;ind<word.size();ind++) {
            if((int)word[ind]>=48 && (int)word[ind]<=57) {
                if(first==INT_MIN) {
                    first = word[ind]-'0';
                    second = word[ind]-'0';
                }
                else {
                    if(ind<firstInd) {
                        firstInd = ind;
                        first = word[ind]-'0';
                    }
                    else {
                        if(ind>secondInd) {
                            second = word[ind]-'0';
                            secondInd = ind;
                        }
                    }
                }
            }
        }
        total+=(first*10 + second);
    }
    cout<<total<<endl;
}