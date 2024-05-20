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

Graph operator+(const Graph& g1, const Graph& g2) {
    if (g1.getNumVertices() != g2.getNumVertices()) {
        throw std::out_of_range("Error! The matrix are not of the same order of magnitude.");
    }

    Graph ans;
    std::vector<std::vector<int>> ansMat;
    std::vector<std::vector<int>> g1Mat = g1.getAdjMatrix();
    std::vector<std::vector<int>> g2Mat = g2.getAdjMatrix();
    int n = g1.getNumVertices();

    for(size_t i=0; i<n; i++){
        for(size_t j=0; j<n; j++){
            ansMat[i][j] = g1Mat[i][j] + g2Mat[i][j];
        }
    } 

    ans.loadGraph(ansMat);
    return ans;
}

void operator+=(Graph& g1, Graph& g2) { // addition operator
    if (g1.getNumVertices() != g2.getNumVertices()) {
        throw std::out_of_range("Error! The matrix are not of the same order of magnitude.");
    }

    Graph ans;
    std::vector<std::vector<int>> ansMat;
    std::vector<std::vector<int>> g1Mat = g1.getAdjMatrix();
    std::vector<std::vector<int>> g2Mat = g2.getAdjMatrix();
    int n = g1.getNumVertices();

    for(size_t i=0; i<n; i++){
        for(size_t j=0; j<n; j++){
            ansMat[i][j] = g1Mat[i][j] + g2Mat[i][j];
        }
    } 

    g1.loadGraph(ansMat);
}

void operator+(Graph& g) { // Unary plus operator
    Graph ans;
    std::vector<std::vector<int>> ansMat;
    std::vector<std::vector<int>> gMat = g.getAdjMatrix();
    int n = g.getNumVertices();

    for(size_t i=0; i<n; i++){
        for(size_t j=0; j<n; j++){
            if(gMat[i][j]<0){
                ansMat[i][j] = gMat[i][j]*(-1);
            }
        }
    } 

    g.loadGraph(ansMat);

}
Graph operator-(const Graph& g1, const Graph& g2) { // matrix subtraction operator
    if (g1.getNumVertices() != g2.getNumVertices()) {
        throw std::out_of_range("Error! The matrix are not of the same order of magnitude.");
    }

    Graph ans;
    std::vector<std::vector<int>> ansMat;
    std::vector<std::vector<int>> g1Mat = g1.getAdjMatrix();
    std::vector<std::vector<int>> g2Mat = g2.getAdjMatrix();
    int n = g1.getNumVertices();

    for(size_t i=0; i<n; i++){
        for(size_t j=0; j<n; j++){
            ansMat[i][j] = g1Mat[i][j] - g2Mat[i][j];
        }
    } 

    ans.loadGraph(ansMat);
    return ans;
} 
void operator-=(Graph& g1, Graph& g2) { // subtraction operator
    if (g1.getNumVertices() != g2.getNumVertices()) {
        throw std::out_of_range("Error! The matrix are not of the same order of magnitude.");
    }

    Graph ans;
    std::vector<std::vector<int>> ansMat;
    std::vector<std::vector<int>> g1Mat = g1.getAdjMatrix();
    std::vector<std::vector<int>> g2Mat = g2.getAdjMatrix();
    int n = g1.getNumVertices();

    for(size_t i=0; i<n; i++){
        for(size_t j=0; j<n; j++){
            ansMat[i][j] = g1Mat[i][j] - g2Mat[i][j];
        }
    } 

    g1.loadGraph(ansMat);
}

void operator-(Graph& g) { // Unary minus operator
    Graph ans;
    std::vector<std::vector<int>> ansMat;
    std::vector<std::vector<int>> gMat = g.getAdjMatrix();
    int n = g.getNumVertices();

    for(size_t i=0; i<n; i++){
        for(size_t j=0; j<n; j++){
            ansMat[i][j] = gMat[i][j]*(-1);
        }
    } 

    g.loadGraph(ansMat);
}

//---------------------------Comparison Operators---------------------------

bool operator>(Graph g1, Graph g2) { // g1>g2
    std::vector<std::vector<int>> g1Mat = g1.getAdjMatrix();
    std::vector<std::vector<int>> g2Mat = g2.getAdjMatrix();
    int n1 = g1.getNumVertices();
    int n2 = g2.getNumVertices(); // The smaller graph

    if(n2>n1){
        return false;
    }

    for(size_t i=0; i<n1; i++){ // The bigger graph
        for(size_t j=0; j<n1; j++){

            for(size_t k=0; k<n2; k++){ // The smaller graph
                for(size_t m=0; m<n2; m++){
                    if(g1Mat[i+k][j+m]!=g2Mat[k][m]){
                        return false;
                    }
                    else{
                        continue;
                    }
                }
            }   
        }
    }

    return false;
}

bool operator>=(Graph g1, Graph g2){ // g1<=g2
    return (g2 > g1) || (g1 == g2);
}

bool operator<(Graph g1, Graph g2){ // g2>g1
    return !(g1 >= g2);
}

bool operator<=(Graph g1, Graph g2){ // g1<=g2
    return !(g1 > g2);
}

bool operator==(const Graph& g1, const Graph& g2){ // g1==g2
    if (g1.getNumVertices() != g2.getNumVertices()) {
        throw std::out_of_range("Error! The matrix are not of the same order of magnitude.");
        return false;
    }

    // The graphs are of the same order of magnitude
    std::vector<std::vector<int>> g1Mat = g1.getAdjMatrix();
    std::vector<std::vector<int>> g2Mat = g2.getAdjMatrix();
    int n = g1.getNumVertices();

    for(size_t i=0; i<n; i++){
        for(size_t j=0; j<n; j++){
            if(g1Mat[i][j] != g2Mat[i][j]){
                throw std::out_of_range("Error! not equals weight");
                return false;
            }
        }
    } 

    return true;

}

bool operator!=(const Graph& g1, const Graph& g2){ // g1!=g2
    return !(g1==g2); // If the graphs are not equals so "!=" return true
}


//---------------------------Increase and Decrease with 1---------------------------

Graph& operator++(Graph &g){ //++n
    int n = g.getNumVertices();

    for(size_t i=0; i<n; i++){
        for(size_t j=0; j<n; j++){
            g.getAdjMatrix()[i][j]++;
        }
    }
    return g; 
}

Graph operator++(Graph &g, int) { // n++
    Graph cpy(*this); // Calling copy constructor
    int n = cpy.getNumVertices();

    for(size_t i=0; i<n; i++){
        for(size_t j=0; j<n; j++){
            cpy.getAdjMatrix()[i][j]++;
        }
    }
    return cpy;
}

Graph& operator--(Graph &g){ //--n
    int n = g.getNumVertices();

    for(size_t i=0; i<n; i++){
        for(size_t j=0; j<n; j++){
            g.getAdjMatrix()[i][j]--;
        }
    }
    return g; 
}

Graph operator--(Graph &g, int) {
    Graph cpy(*this); // Calling copy constructor
    int n = cpy.getNumVertices();

    for(size_t i=0; i<n; i++){
        for(size_t j=0; j<n; j++){
            cpy.getAdjMatrix()[i][j]--;
        }
    }
    return cpy;
}

//---------------------------Multiplication by a scalar---------------------------

Graph operator*(const Graph& g, int c) { 
    Graph ans;
    std::vector<std::vector<int>> ansMat;
    std::vector<std::vector<int>> gMat = g.getAdjMatrix();
    int n = g.getNumVertices();

    for(size_t i=0; i<n; i++){
        for(size_t j=0; j<n; j++){
            ansMat[i][j] = gMat[i][j]*c;
        }
    } 

    ans.loadGraph(ansMat);
    return ans;
}

//---------------------------Graph Multiplication---------------------------
// Function to display a matrix
void displayMatrix(const std::vector<std::vector<int>>& g) {
    for (const auto& row : g) {
        for (int val : row) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
}

Graph operator*(const Graph& g1, const Graph& g2) { 
    Graph ans;
    std::vector<std::vector<int>> ansMat;
    int sizeG1 = g1.getNumVertices();
    int sizeG2 = g2.getNumVertices();

    // Check if matrices can be multiplied
    if (sizeG1 != sizeG2) {
        std::cout << "Matrices cannot be multiplied!" << std::endl;
        return;
    }

    // Multiply matrices
    for (size_t i = 0; i < sizeG1; ++i) {
        for (size_t j = 0; j < sizeG2; ++j) {
            if(i == j){
                ansMat[i][j] = 0;
            }
            else{
                for (size_t k = 0; k < sizeG1; ++k) {
                    ansMat[i][j] += g1.getAdjMatrix()[i][k] * g2.getAdjMatrix()[k][j];
                }
            }
        }
    }
    ans.loadGraph(ansMat);

    return ans;
}


//---------------------------Graph Multiplication---------------------------
std::ostream& operator<<(std::ostream &os, const Graph& g) {
    int n = g.getNumVertices();

    for(size_t i=0; i<n; i++){
        for(size_t j=0; j<n; j++){
            std::cout << g.getAdjMatrix()[i][j];
        }
    }
}



