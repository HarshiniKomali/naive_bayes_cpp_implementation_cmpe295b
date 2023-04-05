
#include<iostream>
#include<vector>
#include<string>
#include<numeric>
#include<cmath>
#include<map>
#include "readData.h"
#include "prepareData.h"
#include "NaiveBayes.h"

using namespace std;


int main() {
    readData rd;
    prepareData pd;
    NaiveBayes nb;
    vector<vector<string> > dataset;
    map<string,vector<vector<string> > > separatedData;
    dataset = rd.readFile("sample.csv");
    dataset = pd.separateWriteData(dataset);
    separatedData = pd.separateByClass(dataset);
    nb.fit(separatedData,dataset.size(),dataset[0].size());
    

    return 0;
}