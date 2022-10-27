/*
Programmer: Zachary Luevano
Description: Extension of HW1, has a matrix at which you enter the amount of
students and proceed to enter 4 grades, this could easily be expanded to have
another input for amount of grades making this more versatile but anyhow the
main difference between this and the first is the addition of taking the top 3
grades and finding the average I decided to weigh them all the same, took quite
a little to figure this out as the 64 74 84 94 case wasn't working the current
implementation however makes sense and is more logical compared to what I had
before. 

Also a little more detailed as far as the graph goes, I used a round function for the weighted,
I wasn't sure on why the weighted mattered as it provides the same result as the average. If I
managed to do the math wrong I can correct the program very easily.

Date Finished: 10/26/2022
*/

#include <cmath>
#include <iomanip>
#include <iostream>

using namespace std;

// Prototypes
void printMatrix(int myMat[][8], int n_rows, int n_colum);
void Top(int myMat[][8], int n_row, int n_column);

int main() {
  // Declare Variables
  int students;
  int add = 1;
  int sum = 0;
  int add2 = 0;
  int weight = 0;
  int min = 100;
  int sum2 = 0;

  cout << "Input the number of students:" << endl;
  cin >> students;

  // Declare 2D Array
  int grades[students][8];

  // Set the first column to 1 - students.
  for (int r = 0; r < students; r++) {
    for (int c = 0; c < 1; c++) {
      grades[r][c] = add;
      add++;
    }
  }

  // Test print to verify the prior.
  // printMatrix(grades, students, 8);

  // This starts at column 2 as column 1 was used for the student.
  cout << "input the 4 grades." << endl;
  for (int r = 0; r < students; r++) {
    for (int c = 1; c < 5; c++) {
      cin >> grades[r][c];
    }
  }

  cout << endl;
  // printMatrix(grades, students, 8);

  // Try and find the average.
  // cout << "The average:" << endl;
  for (int r = 0; r < students; r++) {
    for (int c = 1; c < 5; c++) {
      sum = grades[r][c] + sum;
      grades[r][5] = sum / 4;
    }
    sum = 0;
  }

  //  cout << "The Weighted" << endl;
  for (int r = 0; r < students; r++) {
    weight = 0;
    for (int c = 1; c < 5; c++) {
      if ((c == 1) or (c == 4))
        weight = round(0.2 * grades[r][c] + weight);

      else if ((c == 2) or (c == 3))
        weight = round(0.3 * grades[r][c] + weight);

      //      cout << weight <<" ";
      grades[r][6] = weight;
    }
  }

  cout << endl;
  // printMatrix(grades, students, 8);

  // Function for finding the top 3.
  Top(grades, students, 8);

  // Organize table with labels and output final array.
  cout << setw(23) << "Student" << setw(19) << "Grade 1" << setw(19)
       << "Grade 2" << setw(20) << "Grade 3" << setw(22) << "Grade 4"
       << setw(19) << "Average" << setw(20) << "Weighted" << setw(19) << "Top 3"
       << endl;
  printMatrix(grades, students, 8);
}

// Function used to find the average of the top 3.
void Top(int myMat[][8], int n_row, int n_column) {
  int sum2 = 0;
  int min = 100;
  for (int r = 0; r < n_row; r++) {
    int sum2 = 0;
    int min = 100;
    for (int c = 1; c < 5; c++) {

      if (myMat[r][c] < min) {
        min = myMat[r][c];
        sum2 = sum2 + min;
      } else if (myMat[r][c] > min) {
        sum2 = sum2 + myMat[r][c];
      }
      // round for weighted.
      else if (myMat[r][c] > myMat[r][c + 1]) {
        sum2 = sum2 + min;
      }

      else if (myMat[r][c] == min) {
        sum2 = sum2 + min;
        myMat[r][7] = min;
      }
      myMat[r][7] = abs(sum2 - min) / 3;
      // cout << sum2 << " " << min << endl; Used to verifying results.
    }
  }
  cout << endl;
  cout << endl;
  return;
}

// Print matrix function does what you think it does.
void printMatrix(int myMat[][8], int n_rows, int n_colum) {
  for (int r = 0; r < n_rows; r++) {
    for (int c = 0; c < n_colum; c++) {
      cout << setw(20) << myMat[r][c];
    }
    cout << endl;
  }
}