#include <iostream>
#include <iomanip>

using namespace std;

// Prototypes
void printMatrix(int myMat[][7], int n_rows, int n_colum);

int main()
{
int students;
cout << "Input the number of students:" << endl;
cin >> students;
int grades[students][7];
int add = 1;

for (int r = 0; r < students; r++)
  {
  for (int c = 0; c <1; c++)
    {
  grades[r][c] = add;
  add++;
      }
  }

printMatrix(grades, students, 7);
}



void printMatrix(int myMat[][7], int n_rows, int n_colum)
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