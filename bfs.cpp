#include <iostream>
#include <queue>
#include <algorithm>
#include <list>

using namespace std;
// time complexity O(N^2) this is reality but in analatical point is O(N)
// This code is simply written by Ala Alhaj ( ScarDeath ) GitHub: https://github.com/scardeath
class BFS{
private:
    // Protect the properaties
    int nV;
    deque<int> *adjList; // two-D array [][]
    bool *visited;
    static const int initNV = 0;
    deque<int> *initAdjList = new deque<int>[0];

public:
    // we have to initialize the graph
    BFS(): nV(initNV),adjList(new deque<int>[0]){
        cout << "No values given to search for"<<endl<<"Program is end at this Point"<<endl;
        exit(1);
    }
    // If we got an value after that
    BFS(int entryVs): nV(entryVs),adjList(new deque<int>[entryVs]){};
    //Time to clear out the graph after searching
    ~BFS(){
        delete [] adjList;
        delete [] visited;
    }
    //Get the number of Vs and then assign it to our nVl
    void getNVS(int n){
        nV = n;
        adjList = new deque<int>[n];
    }
    // The idea of edge is telling where the vertix ( node ) is connected to. X -> Y
    void addEdge(int x, int y){
        adjList[x].push_back(y);
        adjList[y].push_back(x);
    }

    void BFSoperation(int startV){
        visited = new bool[nV];
        // Fill the visited arrays false since we start from the starting point
        for(int i =0;i < nV;++i){
            visited[i] = false;
        }
        deque<int> q;
        /*
         * For sure we will start where the given startV is. so if it is 2 so we will start from V and we mark true
         * which means we visited.
        */
        visited[startV] = true;
        q.push_back(startV);
        // to loop through
        deque<int>::iterator i;
        // Go through all V(s)
        while(!q.empty()){
            // First value which is the front and this is the current value we are dealing with so far
            int currentGivenV = q.front();
            cout << currentGivenV << " -> ";
            q.pop_front();
            // Search through the unvisited Vs
            for(i = adjList[currentGivenV].begin();i != adjList[currentGivenV].end();++i){
                // point at i
                int adjV= *i;
                if(!visited[adjV]){
                    visited[adjV] = true;
                    q.push_back(adjV);
                }
            }

        }
    }
};

int main(){


    BFS g(7); 
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 1); 
    g.addEdge(2, 4);
    g.addEdge(3, 1);
    g.addEdge(3, 4);
    g.addEdge(4, 2);
    g.addEdge(4, 3);
    g.addEdge(4, 5);
    g.addEdge(4, 6);
    g.addEdge(5, 4);
    g.addEdge(6, 4);
    // It should display this: 4,2,3,5,6,1 if all Graph is undirected means each nodes are reaching to each other
    g.BFSoperation(4);
    cout << endl;
}
