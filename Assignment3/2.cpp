#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

bool passable(vector<vector<int>> planks, int start_row, int start_column, int row_size, int column_size) {
    if (0 <= start_row && start_row <= row_size-1 &&
        0 <= start_column && start_column <= column_size-1) {
        if (planks[start_row][start_column]) {
            if (start_column == column_size-1) {
                return true;
            }
            else {
                /*  To prevent infinite recursion, we need to prevent the code from trying to
                    make a path of (1,1)->(2,1)->(1,1)->... (within same column looping)
                    and also (1,1)->(1,2)->(1,1)->... (within same row looping)
                    Solution: mark walked */

                planks[start_row][start_column] = 0;

                bool result = (
                    passable(planks, start_row, start_column + 1, row_size, column_size) ||
                    passable(planks, start_row + 1, start_column, row_size, column_size) ||
                    passable(planks, start_row - 1, start_column, row_size, column_size) ||
                    passable(planks, start_row, start_column - 1, row_size, column_size));

                planks[start_row][start_column] = 1;

                return result;
            }
        }
    }
    // else
    return false;
}

int main() {
    ifstream file_input;
    string file_path;
    cin >> file_path;
    file_input.open(file_path.c_str());
    if (file_input.fail()) {
        exit(1);
    }
    string row_column;
    getline(file_input, row_column);
    istringstream line_row_column(row_column);
    int num_row, num_column;
    line_row_column >> num_row >> num_column;
    // vector of vector
    vector<vector<int>> row(num_row, vector<int>(num_column));
    for (int i = 0; i < num_row; i++) {
        string line;
        getline(file_input, line);
        istringstream line_in(line);
        for (int j = 0; j < num_column; j++) {
            line_in >> row[i][j];
        }
    }
    for (int first_row = 0; first_row < num_row; first_row++) {
        if (passable(row, first_row, 0, num_row, num_column)) {
            cout << "1" << endl;
            return 0;
        }
    }
    cout << "0" << endl;
    return 0;
}
