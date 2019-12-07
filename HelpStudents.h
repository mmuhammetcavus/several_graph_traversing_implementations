#ifndef CMPE250_ASSIGNMENT3_HELPSTUDENTS_H
#define CMPE250_ASSIGNMENT3_HELPSTUDENTS_H
#include <vector>
#include <iostream>
#include <fstream>
#include <list>

using namespace std;




class HelpStudents{


public:
    HelpStudents(int  N, int  M, int K, const vector < pair< pair <int,int> , int > >& ways);
    long long int firstStudent();
    long long int secondStudent();
    long long int thirdStudent();
    long long int fourthStudent();
    long long int fifthStudent();
    int numberOfNodes, destination;
    list<pair<int ,int>> * adj;
    //int ** edges;


    // YOU CAN ADD YOUR HELPER FUNCTIONS AND MEMBER FIELDS

};

#endif //CMPE250_ASSIGNMENT3_HELPSTUDENTS_H
