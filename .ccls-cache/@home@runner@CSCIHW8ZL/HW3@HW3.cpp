#include <iostream>
#include <iomanip>

using namespace std;

// Prototype Functions
void printMatrix(char myMat[][6], int n_rows, int n_colum);

int main()
{
//Declare Variables;
char T = 1;
char F = 0;
int num;
int add = 1;
int tests = 1;
int sum = 0;

  // Used for testing purposes.
//cout << static_cast<int>(T) << endl;
//cout << static_cast<int>(F) << endl;

// User prompt.
cout << "Enter the number of tests." << endl;
cin >> num;
// Set Arrays for the T/F and the 
char test[num][6];
int result[num];
  
for (int r = 0; r < num; r++)
  {
  for (int c = 0; c < 1; c++)
    {
    test[r][c] = tests;
    tests++;
    } 
  }

  cout << "\nInput the results T for 5 pts F for 0 pts" << endl;
for (int r = 0; r < num; r++)
  {
  sum = 0;
  for (int c = 0; c < 5; c++)
    {
      cin >> test[r][c];
      if (test[r][c] == 'T')
      result[r] = 1;
      else if (test[r][c] == 'F')
      result[r] = 0;

      sum = result[r] + sum;
      result[r] = sum;
    }
  }
  
  // Print matrix out to show the choices once again.
  printMatrix(test, num, 6);

  // Almost forgot how to display an array!
  cout << "\nResults are: " << endl;
  for (int i = 0; i < num; i++)
  {
  cout << "test: " << add << " Results = " << result[i] * 5 << endl;
  add++;
  }

  
} // End of main

//Print matrix function does what you think it does.
void printMatrix(char myMat[][6], int n_rows, int n_colum)
  {
  int add = 1;
    
  for (int r = 0; r < n_rows; r++)
  {
  for (int c = 0; c < n_colum; c++)
    {
    cout << static_cast<int>(add);
    cout << " " << setw(5) <<myMat[r][c];
    }
  add++;
  cout << endl;
  } 
}