#include <cmath>
#include <iomanip>
#include <iostream>

using namespace std;

// Prototype Functions
void prdoubleMatrix(double myMat[][2], double n_rows, double n_colum);
void findadj(double mymat[0][2], double n_rows, double n_colum);
void findInv(double mymat[0][2], double n_rows, double n_colum, double det);

int main() {
  double det;
  double mat[2][2];
  double inv[2][2];

  cout << "Input a 2 x 2 matrix by row." << endl;
  for (int r = 0; r < 2; r++) {
    for (int c = 0; c < 2; c++) {
      cin >> mat[r][c];
    }
  }
  prdoubleMatrix(mat, 2, 2);
  cout << endl;


//Save the Det for later in the inverse matrix.
det = (((mat[0][0]) * (mat[1][1])) - ((mat[0][1]) * (mat[1][0])));


//Message Display for deteriment and case for if it's 0 as  you can't divide by 0 aswell as terminate program.
cout << "Determinent = ";
if (((mat[0][0]) * (mat[1][1])) - ((mat[0][1]) * (mat[1][0])) != 0)
cout << ((mat[0][0]) * (mat[1][1])) - ((mat[0][1]) * (mat[1][0])) << endl;
else{
cout << "Cannot take inverse with 0 being determinent as inverse will divide adj by 0." << endl;
return 0;
}
  
cout << endl;
cout << "Changing principle and flipping signs on other diagonal.";
  
//Change the signs of the others and account for a -0 as appearntly that's a thing with doubles.
if (mat[0][1] == 0)
  mat[0][1] = mat[0][1];
else
  mat[0][1] = -mat[0][1];
  
if (mat[1][0] == 0)
  mat[1][0] = mat[1][0];
else
  mat[1][0] = -mat[1][0];


double adj[2][2] = {mat[1][1], mat[0][1], 
                 mat[1][0], mat[0][0]};
  
cout << endl;
cout << "Now Verifying new matrix." << endl;
findadj(mat, 2, 2);
cout << endl;


findInv(mat, 2, 2, det);
  
  return 0;
}

// Prdouble matrix function does what you think it does.
void prdoubleMatrix(double myMat[][2], double n_rows, double n_colum) {
  for (int r = 0; r < n_rows; r++) {
    for (int c = 0; c < n_colum; c++) {
      cout << setw(5) << myMat[r][c];
    }
    cout << endl;
  }
}

// Find the adj of the matrix.
void findadj(double mymat[0][2], double n_rows, double n_colum)
{
double adj[2][2] = {mymat[1][1], mymat[0][1], 
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
void findInv(double mymat[0][2], double n_rows, double n_colum, double det)
{
double inv[2][2] = {mymat[1][1]/det, mymat[0][1]/det, 
                 mymat[1][0]/det, mymat[0][0]/det};
for (int r = 0; r < n_rows; r++) {
    for (int c = 0; c < n_colum; c++) {
      cout << setw(5) << inv[r][c];
    }
    cout << endl;
  }
return;
}