#include<bits/stdc++.h>
using namespace std;

int main() {
    vector<vector<char>> data;

    ifstream fileInput("input.txt");
    freopen("output.txt","w",stdout);

    string line;
    vector<char> curData;
    while(getline(fileInput,line)) {
        for(int i=0;i<line.size();i++){
            curData.push_back(line[i]);
        }
        data.push_back(curData);
        curData.clear();
    }

    vector<vector<int>> vis(data[0].size(),vector<int>(data[0].size(),0));
    long long total = 0;
    map<pair<int,int>,vector<int>> myMap;

    for(int i=0;i<data.size();i++) {
        for(int j=0;j<data[i].size();j++) {
            int curVal = 0,tenbase=0,flag=0;
            char x = data[i][j];
            int y=i,z=j;
            int startIndex = INT_MIN,endIndex=INT_MIN;
            while(y<data.size() && z<data[0].size()) {
                x=data[y][z];
                if(((int)x>=48 && (int)x<=57)) {
                    flag = 1;
                    if(startIndex==INT_MIN) {
                        startIndex = z;
                        endIndex = z;
                    }
                    curVal = curVal*tenbase + (x-'0');
                    if(tenbase==0) {
                        tenbase++;
                        tenbase*=10;
                    }
                    endIndex = z;
                }
                else {
                    break;
                }
                z++;
            }

            if(startIndex!=INT_MIN && endIndex!=INT_MIN) {
                for(int k=startIndex;k<=endIndex;k++) {
                    if(vis[i][startIndex] && vis[i][endIndex]) break;
                    for(int l=-1;l<=1;l++) {
                        for(int o=-1;o<=1;o++) {
                            if(vis[i][startIndex] && vis[i][endIndex]) break;
                            int nrow = i+l;
                            int ncol = k+o;
                            if(nrow>=0 && nrow<data.size() && ncol>=0 && ncol<data[0].size() && data[nrow][ncol]=='*' && !vis[i][startIndex] && !vis[i][endIndex]) {
                                vector<int> gears = myMap[{nrow,ncol}];
                                if(gears.size()<2) {
                                    gears.push_back(curVal);
                                }
                                myMap[{nrow,ncol}] = gears;
                                vis[i][startIndex] = 1;
                                vis[i][endIndex] = 1;
                            }
                        }
                    }

                }
            }

            if(flag==1) {
                j+=(z-j-1);
            }
        }
    }

    for(auto it:myMap) {
        if(it.second.size()!=2) continue;
        total+=(it.second[0] * it.second[1]);
    }

    cout<<total<<endl;

    return 0;
}