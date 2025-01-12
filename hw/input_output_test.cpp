#include <iostream>
#include <string>
#include <vector>
using namespace  std;

int main() {
    string line;
    getline(cin,line);

    while (line.size()>0) {
        vector<int> nums;
        int begin=0;
        for (int i = 0; i < line.size(); ++i) {
            if (line[i]==',') {
                nums.push_back(stoi(line.substr(begin,i-begin)));
                begin= i+1;
            }
        }
        nums.push_back(stoi(line.substr(begin,line.size()-begin)));

        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); ++i) {
            cout<<nums[i];
            if (i!=nums.size()-1) {
                cout<<",";
            }
        }

        cout<<endl;
        getline(cin,line);
    }


}