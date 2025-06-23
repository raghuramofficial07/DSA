#include<iostream>
using namespace std;

int main(void) {
    int j;
    int val;
    int row, col;

    cout << "Enter The Number of Row(s): ";
    cin >> row;
    cout << "Enter Number of Column(s): ";
    cin >> col;

    int mat[row][col];

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << "Enter number for position [" << i << "][" << j << "]: ";
            cin >> mat[i][j];
        }
    }

    cout << "\nPerforming the Diagonal Sum on the Matrix ...!" << endl;

    int sum = 0;

    for (int i = 0; i < row; i++) {
        int count = 0;
        j = count + i;

        if (j < col) {
            val = mat[i][j];
            cout << "mat[" << i << "][" << j << "] = " << val << endl;
            sum += val;
        }
    }

    cout << "\nFinal Diagonal Sum: " << sum << endl;

    return 0;
}
