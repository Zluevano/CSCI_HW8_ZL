/*
Programmer: Zachary Luevano
Instructor: Dr. Mellenthin
Description: Realtively simple program that allows an input of students into an
array and then entering 4 grades (numbers) into the said arrray. It takes these
and does some multiplication, divsion or both and proceeds to output these to
other columns of the same matrix. before. 
Date Finished: 10/23/2022
*/

#include <iomanip>
#include <iostream>

using namespace std;

// Prototypes
void printMatrix(int myMat[][7], int n_rows, int n_colum);
void gradeinput(int myMat[][7], int n_row, int n_colunm);

int main() {
  // Declare Variables
  int students;
  int add = 1;
  int sum = 0;
  int add2 = 0;
  int weight = 0;

  cout << "Input the number of students:" << endl;
  cin >> students;

  // Declare 2D Array
  int grades[students][7];

  // Set the first column to 1 - students.
  for (int r = 0; r < students; r++) {
    for (int c = 0; c < 1; c++) {
      grades[r][c] = add;
      add++;
    }
  }

  // Test print to verify the prior.
  printMatrix(grades, students, 7);

  // This starts at column 2 as column 1 was used for the student.
  cout << "input the 4 grades." << endl;
  for (int r = 0; r < students; r++) {
    for (int c = 1; c < 5; c++) {
      cin >> grades[r][c];
      // sum = grades[r][c] + sum;
      // grades[r][5] = sum;
    }
  }

  // cout << sum;
  cout << endl;
  printMatrix(grades, students, 7);

  // Try and find the average.
  cout << "The average:" << endl;
  for (int r = 0; r < students; r++) {
    for (int c = 1; c < 5; c++) {
      sum = grades[r][c] + sum;
      grades[r][5] = sum / 4;
    }
    sum = 0;
  }

  cout << endl;
  printMatrix(grades, students, 7);

  cout << "The Weighted" << endl;
  for (int r = 0; r < students; r++) {
    weight = 0;
    for (int c = 1; c < 5; c++) {
      if ((c == 1) or (c == 4))
        weight = (0.2 * grades[r][c] + weight);

      else if ((c == 2) or (c == 3))
        weight = (0.3 * grades[r][c] + weight);

      cout << weight << " ";
      grades[r][6] = weight;
    }
  }

  cout << endl;
   cout << setw(23) << "Student" << setw(19) << "Grade 1" << setw(19)
       << "Grade 2" << setw(20) << "Grade 3" << setw(22) << "Grade 4"
       << setw(19) << "Average" << setw(20) << "Weighted"
       << endl;
  printMatrix(grades, students, 7);
}

void printMatrix(int myMat[][7], int n_rows, int n_colum) {
  for (int r = 0; r < n_rows; r++) {
    for (int c = 0; c < n_colum; c++) {
      cout << setw(20) << myMat[r][c];
    }
    cout << endl;
  }
}