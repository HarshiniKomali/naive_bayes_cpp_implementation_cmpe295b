#ifndef prepareData_H
#define prepareData_H
#include<vector>
#include<string>
#include<map>

using namespace std;

class prepareData {
    public:
        vector<vector<string> > separateWriteData(vector<vector<string> > dataset);
        map<string,vector<vector<string> >> separateByClass(vector<vector<string> > dataset);

};

#endif