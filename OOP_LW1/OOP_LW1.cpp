#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>

using namespace std;

int const ROWS = 4, COLS = 4;

void fillArray(int [][COLS]);
void printArray(int [][COLS]);
int countOfRowsWithoutNulls(int [][COLS]);
void twiceMaxElement(int [][COLS], int&);
int findMaxElement(int [][COLS]);
void printSpiral(int [][COLS]);

//////////////////////////////   Вариант 1   ////////////////////////////////////

int main() {
    int array[ROWS][COLS]; //   создание массива
    int max;

    fillArray(array);      //   заполнение массива
    printArray(array);     //   печать массива  

    //  задание 2 (1 + 9 = 10 задание в списке)
    cout << "Outputting an array while traversing it in a spiral : "; // by Google Translate
    printSpiral(array);    //   печать в виде спирали массива 

    //  задание 1 [1.1) задание в списке]
    int c = countOfRowsWithoutNulls(array);    
    cout << "\nCount of rows without nulls : " << c;
   
    //  задание 1 [1.2) задание в списке]
    twiceMaxElement(array, max);  //    max - ссылка 

    if (max != 0) cout << "\nThe max value of an element that occurs more than once : " << max <<"\n";
    else  cout << "\nThe max value of an element that occurs more than once does not exist\n";
     
    return 0;
}


void fillArray(int array[][COLS]) {
    srand(time(0));

    for (int r = 0; r < ROWS; r++) 
        for (int c = 0; c < COLS; c++) 
            array[r][c] = (rand() % 11) + 0;
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

int findMaxElement(int array[][COLS]) {
    int max = array[0][0];
    if (COLS < 2) return max;
    else {
        for (int r = 0; r < ROWS; r++)
            for (int c = 0; c < COLS; c++)
                if (array[r][c] > max) max = array[r][c];
    }

    return max;
}

void twiceMaxElement(int array[][COLS], int& max) {
    int counter = 0;
   
    max = findMaxElement(array);
   
    for (int r = 0; r < ROWS; r++)
        for (int c = 0; c < COLS; c++)
            if (array[r][c] == max) {
                array[r][c] = 0;
                counter++;
            }

    if (counter < 2)  twiceMaxElement(array, max);
}

void printSpiral(int array[][COLS]) {
    int size = COLS,
        x,       //   позиция x
        y,       //   позиция y
        d = 0,   //   начальное направление; 0 = ВПРАВО, 1 = ВНИЗ, 2 = ВЛЕВО, 3 = ВВЕРХ
        c = 1;   //   количество звеней в цепи - 1 элемент

    // определение начальной точки
    if (size % 2 == 0) {
        x = ((int)floor(size / 2.0)) - 1;
        y = ((int)floor(size / 2.0)) - 1;
    } else {
        // для массива с непарныи количеством элементов (например, 25) точка будет в центре
        x = ((int)floor(size / 2.0));
        y = ((int)floor(size / 2.0));
    }

    if (size == 1)  cout << array[x][y] << " ";
    else {
        cout << array[x][y] << " "; 

        // k - количество количества действий (сдвигов координат) одинакового характера (например, [3][3]: → ↓ ← ← ↑ ↑ → →   =>
        // => (→ ↓) - 1 (два, одинаковых по количеству, сдвига); 
        // (← ← ↑ ↑ → →) - 2 (три, одинаковых по количеству, сдвига (неважно, что делается по два сдаига, когда направление одно));)
        for (int k = 1; k < size; k++)  { 
            //  все действия одинакового характера выполняються по 2 раза ((→ ↓) или (← ← ↑ ↑)), кроме последних ((← ← ↑ ↑ → →) или (← ← ← ← ↑ ↑ ↑ ↑ → → → →))
            //  для этого есть проверка (k < (size - 1) ? 2 : 3) на предпоследнее действие
            for (int j = 0; j < (k < (size - 1) ? 2 : 3); j++)  {
                for (int i = 0; i < c; i++)   {
                    //  выбор направления движения
                    switch (d) {
                        case 0: y = y + 1; break;
                        case 1: x = x + 1; break;
                        case 2: y = y - 1; break;
                        case 3: x = x - 1; break;
                    }
                    cout << array[x][y] << " ";
                }
                d = (d + 1) % 4;  //  меняем направление, когда прошли звенья с одинаковым направлением
            }
            c++; // kek
        }
    }
   
}