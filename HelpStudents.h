#ifndef CMPE250_ASSIGNMENT3_HELPSTUDENTS_H
#define CMPE250_ASSIGNMENT3_HELPSTUDENTS_H
#include <vector>
#include <iostream>
#include <fstream>
#include <list>

using namespace std;


class HelpStudents{

    struct Vertex {
        list<int> adj;
        int no;
        long long int dist;
        bool isKnown;
        bool operator<(const Vertex& other) const {
            if (dist == other.dist)
                return no>other.no;
            return dist > other.dist;
        }
    };


public:
    HelpStudents(int  N, int  M, int K, const vector < pair< pair <int,int> , int > >& ways);
    long long int firstStudent();
    long long int secondStudent();
    long long int thirdStudent();
    long long int fourthStudent();
    long long int fifthStudent();
    int numberOfNodes, numberOfEdges, destination;
    vector<Vertex> vertices;


    // YOU CAN ADD YOUR HELPER FUNCTIONS AND MEMBER FIELDS

};

#endif //CMPE250_ASSIGNMENT3_HELPSTUDENTS_H
