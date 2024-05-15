/*  ID: 212051007
    Mail: mayrozen45@gmail.com
*/

#include <iostream>
#include <vector>
#include "Graph.hpp"
using namespace ariel;

// getter to numVertices
int Graph::getNumVertices() const{
    return numVertices;
}

// getter to adjMatrix
std::vector<std::vector<int>> Graph::getAdjMatrix() const{
    return adjMatrix;
}

// setter to adjMatrix
void Graph::loadGraph(const std::vector<std::vector<int>>& adjMat) {
    this->adjMatrix = adjMat;
    this->numVertices = adjMat.size();
}

void Graph::printGraph(){
    int edges = 0;
    for (IndexType i = 0; i < numVertices; i++) {
        for (IndexType j = 0; j < numVertices; j++) {
            if(adjMatrix[i][j]!=0){ // Assuming the lack of an edge is expressed by 0
                edges++;
            }
        }
    }
    std::cout << "Graph with "<<numVertices<<" vertices and "<<edges<<" edges." << std::endl;
}

//---------------------------------Operators---------------------------------

//---------------------------Arithmetic Operators---------------------------

Graph& operator+(Graph g1, Graph g2) {
    if (g1.getNumVertices() != g2.getNumVertices()) {
        throw std::out_of_range("Error! The matrix are not of the same order of magnitude.");
    }

    Graph ans;
    std::vector<std::vector<int>> ansMat;
    std::vector<std::vector<int>> g1Mat = g1.getAdjMatrix();
    std::vector<std::vector<int>> g2Mat = g2.getAdjMatrix();
    int n = g1.getNumVertices();

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            ansMat[i][j] = g1Mat[i][j] + g2Mat[i][j];
        }
    } 

    ans.loadGraph(ansMat);
    return ans;
}

Graph& operator+=(Graph g1, Graph g2){ // addition operator
    if (g1.getNumVertices() != g2.getNumVertices()) {
        throw std::out_of_range("Error! The matrix are not of the same order of magnitude.");
    }

    Graph ans;
    std::vector<std::vector<int>> ansMat;
    std::vector<std::vector<int>> g1Mat = g1.getAdjMatrix();
    std::vector<std::vector<int>> g2Mat = g2.getAdjMatrix();
    int n = g1.getNumVertices();

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            ansMat[i][j] = g1Mat[i][j] + g2Mat[i][j];
        }
    } 

    ans.loadGraph(ansMat);
    return ans;
}

Graph& operator+(Graph g){ // Unary plus operator
    Graph ans;
    std::vector<std::vector<int>> ansMat;
    std::vector<std::vector<int>> gMat = g.getAdjMatrix();
    int n = g.getNumVertices();

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(gMat[i][j]<0){
                ansMat[i][j] = gMat[i][j]*(-1);
            }
        }
    } 

    ans.loadGraph(ansMat);
    return ans;

}
Graph& operator-(Graph g1, Graph g2){ // matrix subtraction operator
    if (g1.getNumVertices() != g2.getNumVertices()) {
        throw std::out_of_range("Error! The matrix are not of the same order of magnitude.");
    }

    Graph ans;
    std::vector<std::vector<int>> ansMat;
    std::vector<std::vector<int>> g1Mat = g1.getAdjMatrix();
    std::vector<std::vector<int>> g2Mat = g2.getAdjMatrix();
    int n = g1.getNumVertices();

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            ansMat[i][j] = g1Mat[i][j] - g2Mat[i][j];
        }
    } 

    ans.loadGraph(ansMat);
    return ans;
} 
Graph& operator-=(Graph g1, Graph g2){ // subtraction operator
    if (g1.getNumVertices() != g2.getNumVertices()) {
        throw std::out_of_range("Error! The matrix are not of the same order of magnitude.");
    }

    Graph ans;
    std::vector<std::vector<int>> ansMat;
    std::vector<std::vector<int>> g1Mat = g1.getAdjMatrix();
    std::vector<std::vector<int>> g2Mat = g2.getAdjMatrix();
    int n = g1.getNumVertices();

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            ansMat[i][j] = g1Mat[i][j] - g2Mat[i][j];
        }
    } 

    ans.loadGraph(ansMat);
    return ans;
}

Graph& operator-(Graph g){ // Unary minus operator
    Graph ans;
    std::vector<std::vector<int>> ansMat;
    std::vector<std::vector<int>> gMat = g.getAdjMatrix();
    int n = g.getNumVertices();

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            ansMat[i][j] = gMat[i][j]*(-1);
        }
    } 

    ans.loadGraph(ansMat);
    return ans;
}

//---------------------------Comparison Operators---------------------------

bool operator>(Graph g1, Graph g2){
    
}

bool operator>=(Graph g1, Graph g2){

}

bool operator<(Graph g1, Graph g2){

}

bool operator<=(Graph g1, Graph g2){

}

bool operator==(Graph g1, Graph g2){
    if (g1.getNumVertices() != g2.getNumVertices()) {
        throw std::out_of_range("Error! The matrix are not of the same order of magnitude.");
        return false;
    }

    if(g1>=g2 && g2>=g1){
        return true;
    }
    
    // The graphs are of the same order of magnitude
    std::vector<std::vector<int>> g1Mat = g1.getAdjMatrix();
    std::vector<std::vector<int>> g2Mat = g2.getAdjMatrix();
    int n = g1.getNumVertices();

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(g1Mat[i][j] != g2Mat[i][j]){
                throw std::out_of_range("Error! not equals weight");
                return false;
            }
        }
    } 

    return true;

}

bool operator!=(Graph g1, Graph g2){
    if(!(g1==g2)){
        return true; // If the graphs are not equals so "!=" return true
    }
    return false;
}

//---------------------------Increase and Decrease with 1---------------------------

Graph& operator++(Graph &g){ //++n
    int n = g.getNumVertices();

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            g.getAdjMatrix()[i][j]++;
        }
    }
    return g; 
}

Graph& operator++(Graph &g, int){ // n++
    int n = g.getNumVertices();
}

Graph& operator--(Graph &g){ //--n
    int n = g.getNumVertices();

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            g.getAdjMatrix()[i][j]--;
        }
    }
    return g; 
}

Graph& operator--(Graph &g, int){
    int n = g.getNumVertices();
}


