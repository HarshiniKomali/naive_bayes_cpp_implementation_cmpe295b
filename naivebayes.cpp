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

vector<vector<string> > NaiveBayes:: transposeVector(vector<vector<string> > original) {
    vector<vector<string> > result(original[0].size(),vector<string>(original.size()));
        for(int i=0; i < original[0].size();i++) {
            for(int j=0; j < original.size(); j++) {
                result[i][j] = original[j][i];
            }
        }

        return result;
    }


void NaiveBayes::fit(map<string,vector<vector<string> > > classMap,int length,int columns) {
    map<string,float> yProbabilities;
    map<string,float> xProbabilities;
    map<string,int> xCounts;
    map<string,int> yCounts;
    map<int,int> columnCounts;

    

    //computing probability of each class Y = ym
    for(auto it = classMap.begin(); it != classMap.end(); it++) {
        string label = it->first;
        int labelCount = classMap[label].size();
        yCounts.insert({label,labelCount});
        yProbabilities.insert({label,float((labelCount*1.0)/length)});
        cout << label << endl;
        cout << labelCount << endl;
        cout << to_string(yProbabilities[label]) << endl;
    }

    //computing probability of X= xk and Y = ym
    // Step1: Transpose the vector of vectors in each label
    for(auto it = classMap.begin(); it != classMap.end(); it++) {
        string label = it->first;
        vector<vector<string > > transposedFeature = NaiveBayes::transposeVector(classMap[label]);
        //Step2: Find counts of X=Xk for every Y=ym. Simultaneously, find the value of k and store it in x_counts
        for(int i = 0; i < transposedFeature.size(); i++) {
            map<string,int> elementFreq;
            for(string &element: transposedFeature[i]) {
                string key = element+"_"+to_string(i)+"_"+label;
                elementFreq[key]++;
            }
            int featureCount = elementFreq.size();
            for(auto itr = elementFreq.begin(); itr != elementFreq.end(); itr++) {
                string key = itr->first;
                int value = elementFreq[key];
                int labelCount = yCounts[label];
                float prob = ((value+1)*1.0)/(labelCount+featureCount);
                xProbabilities[key]=prob;
                //cout << key+"- "+to_string(xProbabilities[key]) << endl;
            }
            
        }
    }
    

    



}

// void NaiveBayes::predict(vector<vector<string> > testData) {

// }

