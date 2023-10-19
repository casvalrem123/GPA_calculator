#include <iostream>
using namespace std;


class Subject{
    public:
    Subject(float Aclassification1, float Aclassification2, float Aclassification3, float Aclassification4 = 0);

    float getClassifi1();
    float getClassifi2();
    float getClassifi3();
    float getClassifi4();
    
    string averageLetter(const float& gradeAverage);

    float averageInClass(ifstream &fileName); 

   private:
    float classification1, classification2, classification3, classification4;
};

//calculate gpa based on letter grade
float gpa(const string& engGrade, const string& apcspGrade, const string& apeconGrade, const string& trigGrade, const string& worldGrade);

//struct for making type for vector reading csv
struct GradesClassifi{
    float classifi1, classifi2, classifi3, classifi4;
}; 
