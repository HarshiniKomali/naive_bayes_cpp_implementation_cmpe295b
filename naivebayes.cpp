#include <stdio.h>
#include <stdlib.h>
#include<iostream>
#include<vector>
#include<string>
#include<numeric>
#include<cmath>
#include<map>
#include "NaiveBayes.h"

using namespace std;

void NaiveBayes::fit(map<string,vector<vector<string> > > classMap,int length,int columns) {
    map<string,float> y_probabilities;
    map<string,float> x_probabilities;
    map<string,int> x_counts;
    map<string,int> y_counts;
    map<int,int> column_counts;
    

    //computing probability of each class
    for(auto it = classMap.begin(); it != classMap.end(); it++) {
        string label = it->first;
        int labelCount = classMap[label].size();
        y_counts.insert({label,labelCount});
        y_probabilities.insert({label,float((labelCount*1.0)/length)});
        cout << y_probabilities[label] << endl;
    }

    //computing probability of X= xk and Y = ym

    



}

// void NaiveBayes::predict(vector<vector<string> > testData) {

// }

