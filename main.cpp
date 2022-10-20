#include <iostream>
#include <iomanip>

using namespace std;

// Prototypes
void printMatrix(int myMat[][3], int n_rows, int n_colum);
int CountUnhealthySensitive (int myMat [10][3], int n_rows, int n_colum);

// Main Function
int main()
{
int AirQuality_Index[10][3] = 
{
  {50, 68, 58},
  {58, 115, 78},
  {62, 110, 81},
  {66, 124, 110},
  {64, 152, 121},
  {46, 143, 90},
  {46, 143, 90},
  {25, 91, 91},
  {27, 19, 59},
  {17, 13, 27}
                 };

cout << "Displaying Air Quality Index for Seperate Regions." << endl;
printMatrix(AirQuality_Index, 10, 3);
cout << endl;

cout << "Grand Junction: ";
CountUnhealthySensitive (AirQuality_Index, 10, 0);
cout << endl;

cout << "Fort Collins: ";
CountUnhealthySensitive (AirQuality_Index, 10, 1);
cout << endl;

cout << "Denver/Boulder: ";
CountUnhealthySensitive (AirQuality_Index, 10, 2);
cout << endl;

cout << "Denver/Boulder: ";
CountUnhealthySensitive (AirQuality_Index, 10, 3);  
}

// Outside Function
void printMatrix(int myMat[][3], int n_rows, int n_colum)
  {
  for (int r = 0; r < n_rows; r++)
  {
  for (int c = 0; c < n_colum; c++)
    {
    cout << setw(5) <<myMat[r][c];
    }
  cout << endl;
  }
}




int CountUnhealthySensitive (int myMat [10][3], int n_rows, int n_colum)
{
int count = 0;
  
int row;
int unhealthy_level = 101;
int max = 150;
for (int c = 0; c < n_colum; c++)
  {
for (row = 0; row < n_rows; row++)
    {
    if (myMat[row][c] >= (unhealthy_level)) //&& (myMat[r][c] <= max))
    count++; 
    }
  }  
 cout << count;
return count;
}

  
/*
for (row = 0; row < n_rows; row++)
  {
  for (int c = 0; c < n_colum; c++)
    {
    if (myMat[row][c] >= (unhealthy_level)) //&& (myMat[r][c] <= max))
    count++; 
    }
  }  
 cout << count;
return count;
}
*/