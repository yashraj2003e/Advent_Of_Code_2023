#include <bits/stdc++.h>
using namespace std;

int main() {

    ifstream inputFile("input.txt");
    freopen("output.txt","w",stdout);
    string f;
    int total = 0;
    int x = 0;
    while(getline(inputFile,f)) {
        x++;
        int red = 0,blue = 0,green = 0;

        f.erase(remove(f.begin(),f.end(),' '),f.end());
        f.erase(remove(f.begin(),f.end(),','),f.end());

        int ind = 0;

        for(int ff=0;ff<f.size();ff++) {
            if(f[ff]==':') {
                ind = ff;
                break;
            }
        }

        string remainingvalue = f.substr(ind,f.size()-1);

        int i = 0;
        int dontCount = 0,count=0;
        while(i<remainingvalue.size()) {
            if(remainingvalue[i]==';') {
                if(red<=12 &&  green<=13  && blue<=14) {
                    count=1;
                }
                if(red>12 || green>13 || blue>14) {
                    dontCount = 1;
                    break;
                }
                red=0;green=0;blue=0;
            }

            int curval = 0;
            int flag = 0;
            while((int)remainingvalue[i]>=48 && (int)remainingvalue[i]<=57) {
                curval=curval*10 + remainingvalue[i]-'0';
                i++;flag=1;
            }

            if(flag) {
                if(remainingvalue[i] == 'r') {
                    red+=curval;
                }
                else if(remainingvalue[i]=='g') {
                    green+=curval;
                }
                else if(remainingvalue[i]=='b') {
                    blue+=curval;
                }
            }
            i++;
        }

        if(red>12 || green>13 || blue>14) continue;


        if(dontCount==0 && count==1) {
            total+=x;
        }
    }
    cout<<total<<endl;
    return 0;
}