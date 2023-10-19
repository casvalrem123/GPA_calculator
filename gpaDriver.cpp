#include<iostream>
#include "gpa.hpp"
#include <string>
#include<fstream>
using namespace std;

 int main(){
//set assesment weighing 
    Subject english = Subject(0.1f, 0.55f, 0.35f);
    Subject apcsp = Subject(0.2f, 0.1f, 0.35f, 0.35f);
    Subject apecon = Subject(0.2f, 0.1f, 0.3f, 0.4f);
    Subject trig = Subject(0.2f, 0.15f, 0.25f, 0.4f);
    Subject worldh = Subject(0.2f, 0.1f, 0.3f, 0.4f); 

//set ifstream for each class
ifstream eng("English_grade.csv");
ifstream csp("CSP_grade.csv");
ifstream econ("Econ_grade.csv");
ifstream trigo("Trig_grade.csv");
ifstream world("WorldH_grade.csv");

//pass in ifstream to get average letter
    string englishLetter = english.averageLetter(english.averageInClass(eng));
    string apcspLetter = apcsp.averageLetter(apcsp.averageInClass(csp));
    string apeconLetter = apecon.averageLetter(apecon.averageInClass(econ));
    string trigLetter = trig.averageLetter(trig.averageInClass(trigo));
    string worldhLetter = worldh.averageLetter(worldh.averageInClass(world));

//print gpa
    cout << gpa(englishLetter, apcspLetter, apeconLetter, trigLetter, worldhLetter) << "\n"; 
 }
