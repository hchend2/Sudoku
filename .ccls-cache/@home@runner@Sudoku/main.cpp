#include <ctime>
#include <iostream>
#include <stdlib.h>
#include <string>
#define N 9
#define rows 9
#define cols 9

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::to_string;

string sudoGrid[N][N] = {

    {"3", "0", "6", "5", "0", "8", "4", "0", "0"},
    {"5", "2", "0", "0", "0", "0", "0", "0", "0"},
    {"0", "8", "7", "0", "0", "0", "0", "3", "1"},
    {"0", "0", "3", "0", "1", "0", "0", "8", "0"},
    {"9", "0", "0", "8", "6", "3", "0", "0", "5"},
    {"0", "5", "0", "0", "9", "0", "6", "0", "0"},
    {"1", "3", "0", "0", "0", "0", "2", "5", "0"},
    {"0", "0", "0", "0", "0", "0", "0", "7", "4"},
    {"0", "0", "5", "2", "0", "6", "3", "0", "0"}
};

// print sudoku grid...
string tempGrid[N][N] = {""};

void printsudoGrid() {
  int count1 = 1;
  int count2 = 1;
  cout << "********************************************************************"
          "****"
       << std::endl;
  for (int i = 0; i < N; i++) {
    cout << "*      |       |       *       |       |       *       |       |  "
            "     *\n"
         << "* ";
    for (int j = 0; j < N; j++) {
      if (sudoGrid[i][j] == "0") {
        sudoGrid[i][j] = " ";
      }
      std::cout << " " << sudoGrid[i][j] << " ";
      if (count1 % 3 == 0) {
        std::cout << "  *  ";
      } else {
        std::cout << "  |  ";
      }
      count1++;
    }
    cout << endl
         << "*      |       |       *       |       |       *       |       |  "
            "     *"
         << endl;
    if (count2 % 3 == 0) {
      cout << endl
           << "****************************************************************"
              "********"
           << endl;
    } else {
      cout << endl
           << "----------------------------------------------------------------"
              "--------"
           << endl;
    }
    count2++;
  }
}
// start menu...
void starterInfo() {
    cout << endl << endl << "Welcom to our sudoku game, select an option below: \n"
         << "    Enter 'p' if you want play manualy \n"
         << "    Enter 's' if you want to auto solve the pezzul \n"
         << "    Enter 'a' for animated solution \n"
         << "    enter 'x' to exit game " << endl << endl;
}
// swap two rows...
void swapRows(string tempGrid[rows][cols], int row1, int row2) {
  tempGrid = sudoGrid;
  string tmp = "";
  for (int i = 0; i < cols; i++) {
    tmp = tempGrid[row1][i];
    tempGrid[row1][i] = tempGrid[row2][i];
    tempGrid[row2][i] = tmp;
  }
}
// swap two cols...
void swapCols(string tempGrid[rows][cols], int col1, int col2) {
  tempGrid = sudoGrid;
  string tmp = "";
  for (int j = 0; j < rows; j++) {
    tmp = tempGrid[j][col1];
    tempGrid[j][col1] = tempGrid[j][col2];
    tempGrid[j][col2] = tmp;
  }
}
// check if item in row...
bool isInRow(string tempGrid[N][N], string str) {
  tempGrid = sudoGrid;
  for (int i = 0; i < N; i++) {
    if (tempGrid[N][i] == str) {
      return true; // present in row...
    }
  }
  return false; // not present in row...
}
// check if item in col...
bool isInCol(string tempGrid[N][N], string str) {
  tempGrid = sudoGrid;
  for (int j = 0; j < N; j++) {
    if (tempGrid[j][N - 1] == str) {
      return true; // present in col...
    }
  }
  return false; // not present in col... 
}

int main() {
    starterInfo();
    printsudoGrid();
}