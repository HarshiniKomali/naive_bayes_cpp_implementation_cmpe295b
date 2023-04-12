#ifndef naiveBayes_H
#define naiveBayes_H
#include<iostream>
#include<vector>
#include<string>
#include<map>

using namespace std;


class NaiveBayes {
    public:
        vector<vector<string> > transposeVector(vector<vector<string> > original);
        void fit(map<string,vector<vector<string> > > traindata,int length,int columns);
    //void predict(vector<vector<string> > testData);
};

#endif