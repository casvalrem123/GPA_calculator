#include <iostream>
#include "gpa.hpp"
#include <string> 
#include <map>
#include <fstream>
#include <vector> 
#include <sstream>

using namespace std; 

//subject classification setter
Subject::Subject(float Aclassification1, float Aclassification2, float Aclassification3, float Aclassification4): 
classification1(Aclassification1), classification2(Aclassification2), classification3(Aclassification3), classification4(Aclassification4){}

//subject classification getter 
float Subject::getClassifi1(){return classification1;}
float Subject::getClassifi2(){return classification2;}
float Subject::getClassifi3(){return classification3;}
float Subject::getClassifi4(){return classification4;}

//subject class--calculate letter average, returns "N/A" by default
string Subject::averageLetter(const float& averageNum){
    int lowerBound[] = {97, 93, 90, 87, 83, 80, 77, 73, 70, 67, 65, 0};
    string letterGrade[] = {"A+", "A", "A-","B+", "B", "B-","C+", "C", "C-","D+", "D", "F"};
        
        for(int i = 0; i < 12; i++){
            if(averageNum >= lowerBound[i]){
                return letterGrade[i];
            } 
        }
        return "N/A"; 
    }

//calculate average in one category 
float Subject::averageInClass(ifstream &fileName){
    vector<GradesClassifi> gradeVec;

    if (fileName.is_open()){
        GradesClassifi readGrade; 
        char delimiter;

        fileName.ignore(1000, '\n'); 

       while(fileName >> readGrade.classifi1 >> delimiter >> readGrade.classifi2 >> delimiter >> readGrade.classifi3 >> delimiter >> readGrade.classifi4){
          fileName >> readGrade.classifi1 >> delimiter >> readGrade.classifi2 >> delimiter  >> readGrade.classifi3 >> delimiter >> readGrade.classifi4; 
            if (fileName.eof()){ 
                break;
            }

            gradeVec.push_back(readGrade);
        }

        // cout << gradeVec[0].classifi1 << gradeVec[0].classifi2 << gradeVec[0].classifi3 << endl; 

    } else {
        cerr << "Error in opening file" << endl; 
        return 1; 
    }
    
    /* FIX HERE */
    float classifi1sum = 0, classifi2sum = 0, classifi3sum = 0, classifi4sum = 0;
    int gradeVecSize = gradeVec.size(); 

    for (int i = 0; i < gradeVecSize; i++){
        classifi1sum += gradeVec[i].classifi1; 
        classifi2sum += gradeVec[i].classifi2; 
        classifi3sum += gradeVec[i].classifi3; 
        classifi4sum += gradeVec[i].classifi4;
    }

    float avgGrade = ((classifi1sum / gradeVecSize) * getClassifi1() + (classifi2sum / gradeVecSize) * getClassifi2() + (classifi3sum / gradeVecSize) * getClassifi3() + (classifi4sum / gradeVecSize) * getClassifi4()) * 100;
    
    return avgGrade;
}

//calculate gpa(in float) based on letter grades 
float gpa(const string& engGrade, const string& apcspGrade, const string& apeconGrade, const string& trigGrade, const string& worldGrade){
    
    map<string, float> gradeAndNum; 
    gradeAndNum["A+"] = 4.0f;
    gradeAndNum["A"] = 4.0f;
    gradeAndNum["A-"] = 3.7f;
    gradeAndNum["B+"] = 3.3f;
    gradeAndNum["B"] = 3.0f;
    gradeAndNum["B-"] = 2.7f;
    gradeAndNum["C+"] = 2.3f;
    gradeAndNum["C"] = 2.0f;
    gradeAndNum["C-"] = 1.7f;
    gradeAndNum["D+"] = 1.3f;
    gradeAndNum["D"] = 1.0f;
    gradeAndNum["F"] = 0.0f;
     
    float averageGrade = 0.0f;
    averageGrade = gradeAndNum[engGrade] + gradeAndNum[apcspGrade] + gradeAndNum[apeconGrade] + gradeAndNum[trigGrade] + gradeAndNum[worldGrade];
    return averageGrade / 5.0f; 
}





