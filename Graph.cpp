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

bool operator>(const Graph& g1, const Graph& g2){ // g1>g2
    
}

bool operator>=(const Graph& g1, const Graph& g2){ // g1<=g2

}

bool operator<(const Graph& g1,const Graph& g2){ // g2>g1
 if(isSubMatrix(g2,g1))

}

bool operator<=(const Graph& g1, const Graph& g2){ // g1<=g2

}

bool operator==(const Graph& g1, const Graph& g2){ // g1==g2
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

bool operator!=(const Graph& g1, const Graph& g2){ // g1!=g2
    if(!(g1==g2)){
        return true; // If the graphs are not equals so "!=" return true
    }
    return false;
}

// Auxiliary function for finding if smallMatrix is a sub-matrix of bigMatrix
bool isSubMatrix(const std::vector<std::vector<int>>& bigMatrix, const std::vector<std::vector<int>>& smallMatrix) {
    int bigRows = bigMatrix.size();
    int bigCols = bigMatrix[0].size();
    int smallRows = smallMatrix.size();
    int smallCols = smallMatrix[0].size();

    // Iterate over each element in the big matrix
    for (int i = 0; i <= bigRows - smallRows; ++i) {
        for (int j = 0; j <= bigCols - smallCols; ++j) {
            // Check if the small matrix is contained within the big matrix at the current position
            bool isMatch = true;
            for (int k = 0; k < smallRows; ++k) {
                for (int l = 0; l < smallCols; ++l) {
                    if (bigMatrix[i + k][j + l] != smallMatrix[k][l]) {
                        isMatch = false;
                        break;
                    }
                }
                if (!isMatch) break;
            }
            if (isMatch) return true;
        }
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

const Graph& operator++(Graph &g, int){ // n++
    Graph cpy(*this); // Calling copy constructor
    int n = cpy.getNumVertices();

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cpy.getAdjMatrix()[i][j]++;
        }
    }
    return cpy;
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

const Graph& operator--(Graph &g, int){
    Graph cpy(*this); // Calling copy constructor
    int n = cpy.getNumVertices();

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cpy.getAdjMatrix()[i][j]--;
        }
    }
    return cpy;
}

//---------------------------Multiplication by a scalar---------------------------

Graph& operator*(Graph g, int c){ 
    Graph ans;
    std::vector<std::vector<int>> ansMat;
    std::vector<std::vector<int>> gMat = g.getAdjMatrix();
    int n = g.getNumVertices();

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
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

Graph& operator*(Graph g1, Graph g2){ 
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
    for (int i = 0; i < sizeG1; ++i) {
        for (int j = 0; j < sizeG2; ++j) {
            for (int k = 0; k < sizeG1; ++k) {
                ansMat[i][j] += g1.getAdjMatrix()[i][k] * g2.getAdjMatrix()[k][j];
            }
        }
    }
    ans.loadGraph(ansMat);

    return ans;
}



