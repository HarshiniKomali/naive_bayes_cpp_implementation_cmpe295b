#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<numeric>
#include<cmath>
#include<set>
#include "prepareData.h"

vector<vector<string> > prepareData::separateWriteData(vector<vector<string> > dataset) {
    set<int> index;
    for(int i = 0; i < dataset.size(); i++) {
        if(dataset[i][1] == "read") {
            index.insert(i);
            //cout << i << endl;
        }
    }
    for(auto& i: index) {
        dataset.erase(dataset.begin()+i);
    }
    return dataset;

}
map<string,vector<vector<string> >> prepareData::separateByClass(vector<vector<string> > dataset) {
    map<string,vector<vector<string> > > separatedData;
    for(int i = 0; i < dataset.size(); i++) {
        string label = dataset[i].back();
        vector<string> row = dataset[i];
        if(separatedData.find(label) == separatedData.end()) {
            vector<vector<string> > rows;
            separatedData.insert({label,rows});
        }
        row.pop_back();
        separatedData[label].push_back(row);
    }
    return separatedData;


}

