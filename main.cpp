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
// check if in 3x3 square...
bool isInSquare(string tempGrid[N][N], int row, int col, string str) {

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (tempGrid[row][col] == str) {
        return true; // present in square...
      }
    }
  }
  return false; // not present in square...
}
// some error messages if in row, col, or square ...
void errorMessage(string sudoGrid[N][N], string str, int r, int c) {
    if (isInRow(sudoGrid, str)) {
         cout << "Is present in row, please try again " << endl;   
    }
    if (isInCol(sudoGrid, str)) {
        cout << "Is present in col, please try again " << endl;
    }
    if (isInSquare(sudoGrid, r, c, str)) {
        cout << "Is present in square, please try again " << endl;
    }
        
}
// more error messages...
void edgeCheck(int r, int c) {
    if (r < 0 || r > 8) {
        cout << "Invalid row... try again " << endl;
        cout << "Enter row and col between 0 and 8 ";
    }
    if (c < 0 || c > 8) {
        cout << "Invalid column... try again " << endl;
        cout << "Enter row and col between 0 and 8 ";
    }
}
// game logic...
void play() {
    int r, c, num;
    cout << "Enter row and col between 0 and 8 ";
    cin >> r >> c;
    edgeCheck(r, c);
    cout << "Enter number between 0 and 9 ";
    cin >> num;
    string str = to_string(num);
    errorMessage(sudoGrid, str, r, c);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            sudoGrid[r][c] = to_string(num);
        }
    }
}

int main() {
    starterInfo();
    printsudoGrid();
}