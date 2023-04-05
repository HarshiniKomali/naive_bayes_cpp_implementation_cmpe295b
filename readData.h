#ifndef readData_H
#define readData_H
#include<vector>
#include<string>

using namespace std;

class readData {
    private:
        vector<vector<string> > dataset;
    public:
        vector<vector<string> > readFile(string filename);
        void displayDataset();

};

#endif