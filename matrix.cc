/* 	Garrett Jennings | ZID: Z1927185
	Assignment 02 | Matrix Multiply
	CS340 - 1
	
	I certify that this is my own work and where appropriate an extension 
	of the starter code provided for the assignment.
*/

#include "matrix.h"
using namespace std;
/*
   This program opens two data files for reading. If either file can't
   be opened, it prints an error message on stderr and aborts the
   program. It generates two input matrices from the data in data
   files, then generates a new matrix by multiplying the numbers in
   two input matrices. Finally, it prints all three matrices on
   stdout.
*/

// to open two data files
void open_files(ifstream &is1, ifstream &is2){
    is1.open(FILE1);
    is2.open(FILE2);

    if (!is1.is_open()) exit(1);
    if (!is2.is_open()) exit(2);
}

// to read contents of two data files
void read_data(ifstream &is, vector <vector <int> > &m){
    for (unsigned int i = 0; i < m.size(); i++){
        for (unsigned int j = 0; j < m[i].size(); j++){
            is >> m[i][j];
        }
    }
}

// to print contents of all matrices
void print_data(const vector <vector<int> > &m){
    int i = 0;

    cout << m.size() << " x " << m[i].size() << endl << 
    "----------------------------------------------------------------------\n";

    for (unsigned int i = 0; i < m.size(); i++){
        for (unsigned int j = 0; j < m[i].size(); j++){
            cout << right << setw(ITEM_W) << m[i][j];
        }
        cout << "\n";
    }
}

// to generate a matrix by multiplying two input matrices
void gen_data(const vector <vector<int> > &A, 
                const vector <vector<int> > &B, 
                vector <vector<int> > &C){
                    // Row 1 by Col 1... n
                    // Row n by Col 1... n
            for (unsigned int i = 0; i < A.size(); i++){
                for (unsigned int j = 0; j < B[i].size(); j++){
                    for (unsigned int k = 0; k < A[i].size(); k++){
                        C[i][j] += A[i][k] * B[k][j];
                    }
                }
            }
}

int main ( )
{
    ifstream is1, is2;      // input file streams
    open_files(is1, is2);   // open input files

    // number of rows and colums in matrices A, B and C
    unsigned nrowsA, ncolsA, nrowsB, ncolsB, nrowsC, ncolsC;

    // read number of rows and colums for input matrices from data
    // files and assign number of rows and colums to resulting
    // matrix from values of input matrices; first two values in
    // data file are number rows and colums of a matrix
    is1 >> nrowsA >> ncolsA; 
    is2 >> nrowsB >> ncolsB;
    nrowsC = nrowsA; 
    ncolsC = ncolsB;

    // define matrices as two-dimensional vectors
    vector<vector<int> > A(nrowsA, vector<int>(ncolsA));
    vector<vector<int> > B(nrowsB, vector<int>(ncolsB));
    vector<vector<int> > C(nrowsC, vector<int>(ncolsC));
    
    // read input values from data files
    read_data(is1, A); 
    read_data(is2, B);

    // generate values for matrix C by multiplying values in
    // matrices A and B, where C = AB
    gen_data(A, B, C);

    // print contents of all matrices on stdout
    cout << "\nMatrix1: "; print_data(A);
    cout << "\nMatrix2: "; print_data(B);
    cout << "\nMatrix3: "; print_data(C);
    cout << endl;

    return 0;
}
