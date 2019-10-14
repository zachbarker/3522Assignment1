//
// Created by Zach Barker on 2019-10-04.
//

#include<math.h>
#include <iostream>
#include "matrix.h"

using namespace std;

class Matrix{

    public:

    int rows;
    int columns;
    vector<vector<double>> matrix;

    // constructor for no paramaeter 1 x 1 matrix
   Matrix() {
        rows = 1;
        columns = 1;
        matrix[0][0] = 0.0;
    }

    // constructor for square n x n matrix
    Matrix(int num) {
        rows = num;
        columns = num;
        for (int i = 0; i < num; i++) {
            for (int j = 0; j < num; j++) {
                matrix[i][j] = 0.0;
            }
        }
    }

    // constructor for a matrix of size r x c
    Matrix(int r, int c) {
        rows = r;
        columns = c;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                matrix[i][j] = 0.0;
            }
        }
    }

    // constructor that accepts a vector and populates
    // a matrix with the values from that vector if the vectors size
    // is a perfect square
    Matrix(vector<double> vect) {
        int size = vect.size();
        int n = sqrt(size);
        if (!sqrt(size))
            throw "input vector size must be a perfect square";
        else {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    matrix[i][j] = 0.0;
                }
            }
        }
    }

    // takes a double x and sets the value at row x col to the value of x
    void set_value(double x, int row, int col) {
        matrix[row][col] = x;
    }

    // returns the value at the given coordinates
    double get_value(int r, int c){
       return matrix[r][c];
   }

   // sets all values in the given matrix to 0.0
    void clear(Matrix theMatrix){
       for (int i = 0; i < theMatrix.rows; i++){
           for(int j = 0; j < theMatrix.columns; j++){
               theMatrix.matrix[i][j] = 0.0;
           }
       }
   }

   // destructor for Matrix class
   ~Matrix(){

   }

   // Overloaded << operator to print out the matrix
    friend ostream &operator <<(ostream &os, const Matrix &m){
        for(int i = 0; i < m.rows; i++){
            for(int j = 0; j<m.columns; j++){
                double x = m.matrix[i][j];
                os << m.matrix[i][j] << " ";
            }
        }
        return os;
    }

    //Overloaded == operator to compare 2 matrices
    friend bool operator== (Matrix &m1, Matrix &m2){
       if (m1.rows == m2.rows && m1.columns == m2.columns && compareMatrix(m1, m2))
           return true;

   }

   //helper method to compare values in 2 matrices
   static bool compareMatrix(Matrix &m1, Matrix &m2){
       int n = m1.rows * m1.columns - 1;
       int count = 0;

       for(int i = 0; i < m1.rows; i++){
           for(int j = 0; j<m1.columns; j++){
               if(m1.matrix[i][j] == m2.matrix[i][j]){
                   count++;
               }
           }
       }
       if(n == count)
           return true;
   }


};



