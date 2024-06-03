/*  ID: 212051007
    Mail: mayrozen45@gmail.com
*/

#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <iostream>
#include <vector>
#include <string>

namespace ariel {
    using IndexType = typename std::vector<int>::size_type; // Define a type alias for vector index type
    class Graph { // our namespace
    private:
        int numVertices;
        std::vector<std::vector<int>> adjMatrix;

    public:

        Graph(){
            this->numVertices = 0;
        }
        // Constructor taking the adjacency matrix
        Graph(const std::vector<std::vector<int>>& Mat) : numVertices(Mat.size()), adjMatrix(Mat) {}

        // Copy constructor
        Graph(const Graph& other);

        // Destructor
        ~Graph(){
            this->adjMatrix.clear();
        }

        int getNumVertices() const;
        std::vector<std::vector<int>> getAdjMatrix() const;
        void loadGraph(const std::vector<std::vector<int>>& adjMat);
        std::string printGraph();

        // Overload subscript operator to access elements of adjacency matrix
        const std::vector<int>& operator[](size_t index) const {
            return adjMatrix[index];
        }

        std::vector<int>& operator[](size_t index) {
            return adjMatrix[index];
        }

//---------------------------operators---------------------------

        friend Graph operator+(const Graph& g1, const Graph& g2); // plus operator
        friend void operator+=(Graph& g1, Graph& g2); // addition operator
        friend void operator+(Graph& g); // Unary plus operator
        friend Graph operator-(const Graph& g1, const Graph& g2); // matrix subtraction operator
        friend void operator-=(Graph& g1, Graph& g2); // subtraction operator
        friend void operator-(Graph& g); // Unary minus operator

        bool operator>(Graph g1);
        friend bool operator>=(Graph g1, Graph g2);
        friend bool operator<(Graph g1, Graph g2);
        friend bool operator<=(Graph g1, Graph g2);
        friend bool operator==(const Graph& g1, const Graph& g2);
        friend bool operator!=(const Graph& g1, const Graph& g2);

        friend Graph& operator++(Graph &g); //++n
        friend const Graph operator++(Graph &g, int); // n++
        friend Graph& operator--(Graph &g); //--n
        friend const Graph operator--(Graph &g, int); // n--

        friend void operator*(Graph& g, int c); // Multiplication by a scalar
        friend void operator*=(Graph &g, int c); // Multiply the graph by int
        friend void operator/=(Graph &g, int c); // Dividing the graph by int

        friend Graph operator*(const Graph& g1, const Graph& g2); // Graph Multiplication

        friend std::ostream& operator<<(std::ostream &os, const Graph& g); // Print Graph

    };
}

#endif // GRAPH_HPP
