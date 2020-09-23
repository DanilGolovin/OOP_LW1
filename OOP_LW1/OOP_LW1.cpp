#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>

using namespace std;

int const ROWS = 4, COLS = 4;

void fillArray(int array[][COLS]);
void printArray(int array[][COLS]);
int countOfRowsWithoutNulls(int array[][COLS]);
void doubleMaxElement(int array[][COLS], int &);
void print_spiral(int array[][COLS]);

int main() {
   int array[ROWS][COLS];
    int max;
    fillArray(array);

    printArray(array);
    print_spiral(array);
    /*
    int c = countOfRowsWithoutNulls(array);
    cout << "\nCount of rows without nulls : " << c;
   
    doubleMaxElement(array, max);

    if (max != 0) cout << "\nThe max value of an element that occurs more than once : " << max <<"\n";
    else  cout << "\nThe max value of an element that occurs more than once does not exist\n";
   
   */
    return 0;
}


void fillArray(int array[][COLS]) {
    srand(time(0));

    for (int r = 0; r < ROWS; r++) {
        for (int c = 0; c < COLS; c++) {
            array[r][c] = (rand() % 11) + 0;
        }
    }
}

void printArray(int array[][COLS]) {
    for (int r = 0; r < ROWS; r++) {
        for (int c = 0; c < COLS; c++) {
            cout << setw(5) << array[r][c] << ' ';
        }
        cout << endl;
    }
    cout << endl;
}

int countOfRowsWithoutNulls(int array[][COLS]) {
    int counter = 0, withoutNulls = 0;

    for (int r = 0; r < ROWS; r++) {
        for (int c = 0; c < COLS; c++) {
            if (array[r][c] == 0) counter++;
        }

        if (counter == 0)   withoutNulls++;
        else counter = 0;

    }
    return withoutNulls;
}


void doubleMaxElement(int array[][COLS], int& max) {
    int counter = 0;
    max = array[0][0];

    for (int r = 0; r < ROWS; r++)
        for (int c = 0; c < COLS; c++)
            if (array[r][c] > max) max = array[r][c];

   
    for (int r = 0; r < ROWS; r++)
        for (int c = 0; c < COLS; c++)
            if (array[r][c] == max) {
                array[r][c] = 0;
                counter++;
            }

    if (counter < 2)  doubleMaxElement(array, max);
}

void print_spiral(int array[][COLS]) {
    int size = COLS;
    int x = 0; // current position; x
    int y = 0; // current position; y
    int d = 0; // current direction; 0=RIGHT, 1=DOWN, 2=LEFT, 3=UP
    int s = 1; // chain size
    // starting point
    if (size % 2 == 0) {
        x = ((int)floor(size / 2.0)) - 1;
        y = ((int)floor(size / 2.0)) - 1;
    } else {
        x = ((int)floor(size / 2.0));
        y = ((int)floor(size / 2.0));
    }

    for (int k = 1; k < size; k++)  {
        for (int j = 0; j < (k < (size - 1) ? 2 : 3); j++)  {
            for (int i = 0; i < s; i++)   {
                cout << array[x][y] << " ";

                switch (d) {
                    case 0: y = y + 1; break;
                    case 1: x = x + 1; break;
                    case 2: y = y - 1; break;
                    case 3: x = x - 1; break;
                }
            }
            d = (d + 1) % 4;
        }
     
        s = s + 1;
    }

    if (size != 1)  cout << array[x][y] << " ";
}