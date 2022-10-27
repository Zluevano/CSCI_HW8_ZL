#include <cmath>
#include <iomanip>
#include <iostream>

using namespace std;

void printMatrix(int myMat[][2], int n_rows, int n_colum);
void findadj(int mymat[0][2], int n_rows, int n_colum);

int main() {
  int det;
  int mat[2][2];
  int inv[2][2];

  cout << "Input a 2 x 2 matrix by row." << endl;
  for (int r = 0; r < 2; r++) {
    for (int c = 0; c < 2; c++) {
      cin >> mat[r][c];
    }
  }
  printMatrix(mat, 2, 2);
  cout << endl;


//Save the Det for later in the inverse matrix.
det = (((mat[0][0]) * (mat[1][1])) - ((mat[0][1]) * (mat[1][0])));
  
cout << "Determinent = ";
if (((mat[0][0]) * (mat[1][1])) - ((mat[0][1]) * (mat[1][0])) != 0)
cout << ((mat[0][0]) * (mat[1][1])) - ((mat[0][1]) * (mat[1][0])) << endl;
else
cout << "Cannot take inverse with 0 being determinent" << endl;


cout << endl;
cout << "Changing principle and flipping signs on other diagonal.";
  
//Change the signs of the others.
mat[0][1] = -mat[0][1];
mat[1][0] = -mat[1][0];

int adj[2][2] = {mat[1][1], mat[0][1], 
                 mat[1][0], mat[0][0]};
  
cout << endl;
cout << "Now Verifying new matrix." << endl;
findadj(mat, 2, 2);
cout << endl;

cout << "Displaying the inverse matrix now." << endl;
for (int r = 0; r < 2; r++)
  {
    for (int c = 0; c < 2; c++)
      {
        inv[r][c] = findadj(mat, 2, 2)
      }
  }


  return 0;
}

// Print matrix function does what you think it does.
void printMatrix(int myMat[][2], int n_rows, int n_colum) {
  for (int r = 0; r < n_rows; r++) {
    for (int c = 0; c < n_colum; c++) {
      cout << setw(5) << myMat[r][c];
    }
    cout << endl;
  }
}

// Find the adj of the matrix.
void findadj(int mymat[0][2], int n_rows, int n_colum)
{
int adj[2][2] = {mymat[1][1], mymat[0][1], 
                 mymat[1][0], mymat[0][0]};
for (int r = 0; r < n_rows; r++) {
    for (int c = 0; c < n_colum; c++) {
      cout << setw(5) << adj[r][c];
    }
    cout << endl;
  }
return;
}

//find the inverse of the matrix;
void findInv(int mymat[0][2], int n_rows, int n_colum, int det;
{
int adj[2][2] = {mymat[1][1]/det, mymat[0][1]/det, 
                 mymat[1][0]/det, mymat[0][0]/det};
for (int r = 0; r < n_rows; r++) {
    for (int c = 0; c < n_colum; c++) {
      cout << setw(5) << adj[r][c];
    }
    cout << endl;
  }
return;
}