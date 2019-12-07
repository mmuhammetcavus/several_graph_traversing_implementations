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
#include <set>

using namespace std;
const long long int INF = numeric_limits<long long int>::max();
typedef pair<long long int, int> pi;
typedef pair<long long int , pair <long long int,long long int> >  p;

HelpStudents::HelpStudents(int  N, int  M, int K, const vector < pair< pair <int,int> , int > >& ways) {
    this->numberOfNodes=N; this->destination=K;
    this->adj=new list<pair<int ,int>>[numberOfNodes+1];
    /*this->edges=new int * [numberOfNodes+1];
    for(int i=0; i<numberOfNodes+1; i++) {
        edges[i]=new int[numberOfNodes+1];
    }*/
    for(auto & x : ways) {
        adj[x.first.first].emplace_back(x.first.second,x.second);
        adj[x.first.second].emplace_back(x.first.first,x.second);
        //edges[x.first.first][x.first.second]=x.second;
        //edges[x.first.second][x.first.first]=x.second;
    }


    // IMPLEMENT ME!
}

long long int HelpStudents::firstStudent() {
    vector<long long int> dist(numberOfNodes+1,INF);
    vector<bool> isOK(numberOfNodes+1, false);
    priority_queue<pi, vector<pi>, greater<> > pq; /*first is dist , sec is node number*/
    dist[1]=0;
    pq.push(make_pair(0,1));
    while(!pq.empty() && destination!=1) {
        pair<int, int> temp=pq.top();
        pq.pop();
        int u=temp.second;
        isOK[u]=true;
        if(u==destination)
            return dist[u];
        for(auto it=adj[u].begin(); it!=adj[u].end(); it++) {
            int v=it->first;
            int weight=it->second;
            if(!isOK[v] && dist[v]>dist[u]+weight) {
                dist[v]=dist[u]+weight;
                pq.push(make_pair(dist[v],v));
            }

        }
    }
    return 0;
}
long long int HelpStudents::secondStudent() {
    auto * parent = new long long int[100001];
    auto * key = new long long int [100001] ;
    for(int i=1; i<=numberOfNodes; i++)
        key[i]=INF;
    bool * isOK = new bool[100001];
    parent[1]=-1;
    key[1]=0;
    auto * pq = new priority_queue <p ,vector<p>, greater<> >; //first is dist, sec.first is from, sec.sec is to
    pq->push(make_pair(0,make_pair(-1,1)));
    while(!pq->empty()) {
        auto x=pq->top(); pq->pop();
        long long int u=x.second.second;
        isOK[u]=true;
        if(u==destination) {
            long long int x=0;
            while(parent[u]!=-1) {
                if(key[u]>x)
                    x=key[u];
                u=parent[u];
            }
            cout<<"@@@@@@@@@@@@@@@@@@ "<<x;
            return x;
        }
        for(auto & a:adj[u]) {
            long long int neigh=a.first;
            long long int weight=a.second;
            if(!isOK[neigh] && weight<key[neigh]) {
                key[neigh]=weight;
                parent[neigh]=u;
                pq->push(make_pair(weight,make_pair(u,neigh)));
            }
        }
    }
    delete[] parent;
    delete[] key;
    delete[] isOK;
    delete pq;


    return -1;

    // IMPLEMENT ME!
}
long long int HelpStudents::thirdStudent() {
    vector<long long int> dist(numberOfNodes+1,INF);
    queue<pair<long long int, int>> q;
    dist[1]=0;
    q.emplace(0,1);
    while(!q.empty() && destination!=1 ) {
        pair<long long int ,int> temp=q.front();
        q.pop();
        int u=temp.second;
        for(auto it=adj[u].begin(); it!=adj[u].end(); it++) {
            int v=it->first;
            if(dist[v]==INF) {
                dist[v]=dist[u]+1;
                if(destination==v)
                    return dist[v];
                q.emplace(dist[v],v);
            }
        }
    }
    return 0;
    // IMPLEMENT ME!
}
long long int HelpStudents::fourthStudent() {
    vector<long long int> dist(numberOfNodes+1,INF);
    dist[1]=0;
    long long int u=1;
    while(true) {
        if(u==destination) {
            return dist[u];
        }
        long long int min=INF;
        long long int next=INF;
        for(auto it=adj[u].begin(); it!=adj[u].end(); it++) {
            int d=it->second;
            if(d<min) {
                min=d;
                next=it->first;
            } else if(d==min && it->first<next)
                next=it->first;
        }if(min<INF) {
            for(auto it =adj[u].begin(); it!=adj[u].end(); it++) {
                if(it->first==next) {
                    adj[u].erase(it);
                    break;
                }
            }
            for(auto it =adj[next].begin(); it!=adj[next].end(); it++) {
                if(it->first==u) {
                    adj[next].erase(it);
                    break;
                }
            }
            dist[next]=dist[u]+min;
            u=next;

        } else {
            break;
        }
    }
    return -1;
    // IMPLEMENT ME!
}
long long int HelpStudents::fifthStudent() {
    // IMPLEMENT ME!
    return -1;
}






// YOU CAN ADD YOUR HELPER FUNCTIONS