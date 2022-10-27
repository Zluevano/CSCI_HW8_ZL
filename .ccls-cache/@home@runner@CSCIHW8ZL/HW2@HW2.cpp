#include <iostream>
#include <iomanip>

using namespace std;

// Prototypes
void printMatrix(int myMat[][8], int n_rows, int n_colum);
void Top(int myMat[][8], int n_row, int n_column);

int main()
{
//Declare Variables
int students;
int add = 1;
int sum = 0;
int add2 = 0;
int weight = 0;
int min = 0;

cout << "Input the number of students:" << endl;
cin >> students;

//Declare 2D Array
int grades[students][8];


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
//printMatrix(grades, students, 8);


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
//printMatrix(grades, students, 8);


//Try and find the average.
//cout << "The average:" << endl;
for (int r = 0; r < students; r++)
  {
   for (int c = 1; c < 5; c++)
     {
       sum = grades[r][c] + sum;
       grades[r][5] = sum/4;
     }
    sum = 0;
  }

//  cout << "The Weighted" << endl;
for (int r = 0; r < students; r++)
  {
  weight = 0;
  for (int c = 1; c < 5; c++)
    {
      if ((c == 1) or (c == 4))
       weight = (0.2 * grades[r][c] + weight);

      else if ((c == 2) or (c == 3))
       weight = (0.3 * grades[r][c] + weight);

//      cout << weight <<" ";
      grades[r][6] = weight;
    }
  }

cout << endl;
//printMatrix(grades, students, 8);

// Function for finding the top 3.
Top(grades, students, 8);


// Organize table with labels and output final array.
cout << setw(23) << "Student" << setw(19) << "Grade 1" << setw(19) << "Grade 2"
     << setw(20) << "Grade 3" << setw(22) << "Grade 4" << setw(19) << "Average"
     << setw(20) << "Weighted" << setw(19) << "Top 3" << endl;
printMatrix(grades, students, 8);
  }



// Function used to find the average of tge top 3.
void Top(int myMat[][8], int n_row, int n_column)
{
  for (int r = 0; r < n_row; r++)
    {
    int min = 0;
    for (int c = 1; c < 5; c++)
      {
        
        if (myMat[r][c] > min){
         min = min + myMat[r][c];
         myMat[r][7] = min/3; 
          }
// round for weighted.
        else if (myMat[r][c] > myMat[r][c+1]){
         min = (min + myMat[r][c]);
         myMat[r][7] = min/3; 
          }
          
        if (myMat[r][c] == myMat[r][c+1]){
         min = (min + myMat[r][c] - myMat[r][c]);
        myMat[r][7] = min;
          }
  } 
  }
cout << endl;
cout << endl;
return;
}

//Print matrix function does what you think it does.
void printMatrix(int myMat[][8], int n_rows, int n_colum)
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