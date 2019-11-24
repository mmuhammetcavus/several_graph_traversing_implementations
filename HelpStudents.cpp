/*
Student Name:
Student Number:
Project Number: 4
Compile Status: [SUCCESS/FAIL]
Running Status: [SUCCESS/FAIL]
Notes: Anything you want to say about your code that will be helpful in the grading process.
*/
#include <limits>
#include <queue>
#include "HelpStudents.h"
#include <list>

using namespace std;

HelpStudents::HelpStudents(int  N, int  M, int K, vector < pair< pair <int,int> , int > > ways) {
    this->numberOfNodes=N; this->numberOfEdges=M; this->destination=K;
    vertices.resize(numberOfNodes);
    int i=1;
    for(auto & a: vertices) {
        a.dist=numeric_limits<long long int>::infinity();
        a.isKnown=false;
        a.no=i;
        i++;
    }
    for(auto & pair : ways) {
        Vertex & v=vertices[pair.first.first-1];
        Vertex & w=vertices[pair.first.second-1];
        v.adj.push_front(w.no);
        w.adj.push_front(v.no);
    }


    // IMPLEMENT ME!
}

long long int HelpStudents::firstStudent() {
    // IMPLEMENT ME!
}
long long int HelpStudents::secondStudent() {
    // IMPLEMENT ME!
}
long long int HelpStudents::thirdStudent() {
    queue<Vertex> q;
    Vertex & first=vertices[0];
    first.isKnown=true;
    first.dist=0;
    q.push(first);
    while(!q.empty()) {
        Vertex  & v=vertices[q.front().no-1];
        q.pop();
        for(auto & x : v.adj) {
            Vertex & w=vertices[x-1];
            if(!w.isKnown) {
                w.isKnown =true;
                w.dist =v.dist+1;
                if(w.no==destination) {
                    cout<<"sfggag : "<<w.dist;
                    return  w.dist;
                }
                q.push(w);
            }
        }
    }
        return vertices[0].dist;
    // IMPLEMENT ME!
}
long long int HelpStudents::fourthStudent() {
    // IMPLEMENT ME!
}
long long int HelpStudents::fifthStudent() {
    // IMPLEMENT ME!
}

// YOU CAN ADD YOUR HELPER FUNCTIONS