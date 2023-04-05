#include<iostream>
#include<fstream>
#include<vector>
#include "readData.h"

using namespace std;

    vector<vector<string> > readData::readFile(string filename) {
        ifstream fin;
        string line;
        fin.open(filename);
        while(!fin.eof()) {
            fin >> line;
            size_t pos = 0;
            string token;
            string delimiter = ",";
            vector<string> tempVector;
            while((pos=line.find(delimiter)) != string::npos) {
                token = line.substr(0,pos);
                    //cout << token << endl;
                tempVector.push_back(token);
                line.erase(0,pos+delimiter.length());
            }
                //cout << line << endl;
            tempVector.push_back(line);
            dataset.push_back(tempVector);


            }
            return dataset;
        }

    void readData::displayDataset() {
        for(int i = 0; i < dataset.size(); i++) {
            for(int j = 0; j < dataset[i].size();j++) {
                cout << dataset[i][j] << endl;
            }
        }
}
