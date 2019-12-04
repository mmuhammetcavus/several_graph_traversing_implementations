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

HelpStudents::HelpStudents(int  N, int  M, int K, const vector < pair< pair <int,int> , int > >& ways) {
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
        int weight=pair.second;
        v.adj.push_front(weight);
        w.adj.push_front(weight);
        v.adj.push_front(w.no);
        w.adj.push_front(v.no);
    }


    // IMPLEMENT ME!
}

long long int HelpStudents::firstStudent() {
    priority_queue<Vertex> pq;
    vertices[0].dist=0;
    pq.push(vertices[0]);
    bool found=false;
    while(!found) {
        Vertex & first=vertices[pq.top().no-1];
        first.isKnown=true;
        if(first.no==destination) {
            found=true;
            return first.dist;
        }
        list<int> ::iterator it;
        for (it = first.adj.begin(); it != first.adj.end(); it++) {
            int x=*it;
            Vertex & w=vertices[x-1];
            if(!w.isKnown) {
                it++;
                long long int newDist=first.dist+*it;
                if(newDist<w.dist)
                    w.dist=newDist;
            }
        }
        pq=priority_queue<Vertex>();
        for(int i=0; i<vertices.size(); i++) {
            if(!vertices[i].isKnown)
                pq.push(vertices[i]);
        }
    }
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
        for(list<int> ::iterator it=v.adj.begin(); it!=v.adj.end(); it++) {
            int x=*it;
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
            it++;
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