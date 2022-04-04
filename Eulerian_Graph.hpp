#include <queue>
#include <sstream>
using namespace std;

class EulerianGraph
{
    int nodes;
    int **V;

    // Calculate Degree
    int findDegree(int k) const {
        if(k >= this->nodes || k < 0) return 0;

        int count = 0;
        for(int i=0; i<this->nodes; i++) count += this->V[k][i];

        return count;
    }

    // Checking for connection between 2 nodes
    bool isGraphConnected() const {
        if(this->nodes <= 0) return true;

        bool *visited = new bool[this->nodes];
        for(int i=0; i<this->nodes; i++) visited[i] = false;

        queue<int> q;

        visited[0] = true;
        q.push(0);

        while(!q.empty()) {
            int tmp = q.front();
            q.pop();
            for(int i=0; i<this->nodes; i++) {
                if(this->V[tmp][i] >= 1) {
                    if(!visited[i]) {
                        visited[i] = true;
                        q.push(i);
                    }
                }
            }
        }

        for(int i=0; i<this->nodes; i++) {
            if(!visited[i]) {
                delete[] visited;
                return false;
            }
        }

        delete[] visited;
        return true;
    }

    // Checking for connection between 2 nodes
    bool isConnected(int node1, int node2) {
        if(node1 < 0 || node1 >= this->nodes) return false;
        if(node2 < 0 || node2 >= this->nodes) return false;

        bool *visited = new bool[this->nodes];
        for(int i=0; i<this->nodes; i++) visited[i] = false;

        queue<int> q;

        visited[node1] = true;
        q.push(node1);

        while(!q.empty()) {
            int tmp = q.front();
            q.pop();
            for(int i=0; i<this->nodes; i++) {
                if(this->V[tmp][i] >= 1) {
                    if(i == node2) {
                        delete[] visited;
                        return false;
                    }
                    if(!visited[i]) {
                        visited[i] = true;
                        q.push(i);
                    }
                }
            }
        }

        delete[] visited;
        return false;
    }

public:
    // Constructor
    EulerianGraph(int n) : nodes(n) {
        if(n <= 0) throw runtime_error("Minimum number of nodes must be 1");
        this->V = new int *[n];
        for(int i=0; i<n; i++) this->V[i] = new int[n];
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) this->V[i][j] = 0;
        }
    }

    // Destructor
    ~EulerianGraph() {
        for(int i=0; i<this->nodes; i++) delete[] this->V[i];
        delete[] this->V;
    }

    // Create a new edge
    void makeEdge(int i, int j) {
        if(i < this->nodes && i >= 0) {
            if(j < this->nodes && j >= 0) {
                if(i != j) {
                    this->V[i][j]++;
                    this->V[j][i] = this->V[i][j];
                }
                else this->V[i][j] += 2;
            }
        }
    }

    // Remove an existing edge
    void removeEdge(int i, int j) {
        if(i < this->nodes && i >= 0) {
            if(j < this->nodes && j >= 0) {
                if(i != j) {
                    if(this->V[i][j] >= 1) {
                        this->V[i][j]--;
                        this->V[j][i] = this->V[i][j];
                    }
                }
                else {
                    if(this->V[i][j] >= 2) this->V[i][j] -= 2;
                }
            }
        }
    }

    // Print Graph
    void print() const {
        for(int i=0; i<this->nodes; i++) {
            for(int j=0; j<this->nodes; j++) {
                if(i == j) cout << ((this->V[i][j] > 0) ? 1 : 0) << " ";
                else cout << this->V[i][j] << " ";
            }
            cout << endl;
        }
    }

    // Checking for Eulerian
    bool isEulerian() const {
        for(int i=0; i<this->nodes; i++) {
            if(this->findDegree(i) % 2 != 0) return false;
        }
        return this->isGraphConnected();
    }

    // Fleury's Algorithm to construct an Eulerian Cycle
    pair<int, int *> constructCycleByFleury() {
        if(this->nodes <= 0 || !this->isEulerian()) {
            int *ans = new int[0];
            return {0, ans};
        }

        int size = 0;
        for(int i=1; i<this->nodes; i++) size += this->findDegree(i);
        size  = (size + this->findDegree(0) + 2) / 2;
        int *ans = new int[size];

        int ptr = 0, currVertex = 0;
        ans[ptr++] = 0;
        while(ptr < size) {
            int currEdge = -1;
            for(int i=0; i<this->nodes; i++) {
                if(this->V[currVertex][i] >= 1) {
                    if(currVertex == i) {
                        currEdge = i;
                        break;
                    }
                    else {
                        this->removeEdge(currVertex, i);
                        currEdge = i;
                        if(this->isConnected(currVertex, i)) {
                            this->makeEdge(currVertex, i);
                            break;
                        }
                        else this->makeEdge(currVertex, i);
                    }
                }
            }
            if(currEdge > -1) {
                this->removeEdge(currVertex, currEdge);
                currVertex = currEdge;
                ans[ptr++] = currVertex;
            } else break;
        }

        return {size, ans};
    }
};