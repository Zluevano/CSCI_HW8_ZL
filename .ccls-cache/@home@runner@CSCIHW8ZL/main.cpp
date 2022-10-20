#include <iostream>
#include <iomanip>

using namespace std;

// Prototypes
void printMatrix(int myMat[][3], int n_rows, int n_colum);
int CountUnhealthySensitive (int myMat [10][3], int n_rows, int n_colum);
int meanAirQuality (int myMat [10][3], int n_rows, int n_colum);

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

cout << setw(65) << "Displaying Air Quality Index for Seperate Regions." << endl;
cout << endl;
cout << setw(21) << "GJ:" << setw(25) <<"Fort Collins:" << setw(22) << "Denver/Boulder:" << endl;
printMatrix(AirQuality_Index, 10, 3);
cout << endl;

cout << "From 10/4/2020 - 10/13/2020 The air quality was unhealthy for sensitive groups in:" << endl;
  
cout << "Grand Junction: ";
CountUnhealthySensitive (AirQuality_Index, 10, 0);
cout << endl;

cout << "Fort Collins: ";
CountUnhealthySensitive (AirQuality_Index, 10, 1);
cout << endl;

cout << "Denver/Boulder: ";
CountUnhealthySensitive (AirQuality_Index, 10, 2);
cout << endl; 

cout << endl;
cout << "From 10/4/2020 - 10/13/2020 the average air quality in:" << endl;
cout << "Grand Junction was ";
meanAirQuality(AirQuality_Index, 10, 0);
cout << endl << "Fort Collins was ";
meanAirQuality(AirQuality_Index, 10, 1); 
cout << endl << "Denver/Boulder was ";
meanAirQuality(AirQuality_Index, 10, 2);
}


// Outside Functions
void printMatrix(int myMat[][3], int n_rows, int n_colum)
  {
  for (int r = 0; r < n_rows; r++)
  {
  for (int c = 0; c < n_colum; c++)
    {
    cout << setw(20) <<myMat[r][c];
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
for (row = 0; row < n_rows; row++)
    {
    if (myMat[row][n_colum] >= (unhealthy_level)) //&& (myMat[r][c] <= max))
    count++; 
    }
 cout << count << " Times";
return count;
}

int meanAirQuality (int myMat [][3], int n_rows, int n_colum)
{
int sum = 0;
int avg;

for (int row = 0; row < n_rows; row++)
  sum = sum + myMat[row][n_colum];

  avg = sum / n_rows;

  cout << avg;
  return avg;
  
}