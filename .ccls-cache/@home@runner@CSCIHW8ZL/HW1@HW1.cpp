#include <iostream>
#include <iomanip>

using namespace std;

// Prototypes
void printMatrix(int myMat[][7], int n_rows, int n_colum);
void gradeinput(int myMat[][7], int n_row, int n_colunm);

int main()
{
//Declare Variables
int students;
int add = 1;
int sum = 0;
int add2 = 0;

cout << "Input the number of students:" << endl;
cin >> students;

//Declare 2D Array
int grades[students][7];


//Set the first column to 1 - students.
for (int r = 0; r < students; r++)
  {
  for (int c = 0; c <1; c++)
    {
  grades[r][c] = add;
  add++;
      }
  }

//Test print to verify the prior.
printMatrix(grades, students, 7);


//This starts at column 2 as column 1 was used for the student.
cout << "input the 4 grades." << endl;
for (int r = 0; r < students; r++)
  {
   for (int c = 1; c < 5; c++)
     {
        cin >> grades[r][c];
      // sum = grades[r][c] + sum;
      // grades[r][5] = sum;
     }
  }

//cout << sum;
cout << endl;
printMatrix(grades, students, 7);


//Try and find the average.
cout << "The average:" << endl;
for (int r = 0; r < students; r++)
  {
   for (int c = 1; c < 5; c++)
     {
       sum = grades[r][c] + sum;
       grades[r][5] = sum/4;
     }
    sum = 0;
  }

cout << endl;
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