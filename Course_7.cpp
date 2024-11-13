/// ======================= ( Algorithms & Problem Solving #3 ) ============================
/// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

/// Problem #1 ( 3x3 Random Matrix )
// write a program to fill a 3x3 matrix with random numbers.
/*
#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>

using namespace std;

int Randint(int From, int To){
    int Num = rand() % (To - From + 1) + From;
    return Num;
}

void FillMatrixWithRandomNumber(int arr[3][3], short rows, short cols){

    for(int i = 0; i < rows; i++){

        for(int j = 0; j < cols; j++){

            arr[i][j] = Randint(1, 100);

        }

    }

}

void PrintMatrix(int arr[3][3], int rows, int cols){

    for ( int i = 0; i < rows; i++){

        for (int j = 0; j < cols; j++){

            cout << setw(3) << arr[i][j] << "     ";

        }
        cout << endl;

    }
}

int main(){

    srand((unsigned)time(NULL));

    int arr[3][3];
    short rows = 3, cols = 3;

    FillMatrixWithRandomNumber(arr, rows, cols);

    cout << "\n\nThe following is a 3x3 random matrix: " << endl;
    PrintMatrix(arr, rows, cols);

    system("Pause>0");
    return 0;
}
 */

/// Problem #2 ( Sum Each Row in Matrix )
// Write a Program to fill a 3x3 matrix with random numbers, then print each row sum:
/*
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>

using namespace std;

int Randint(int From, int To){
    int Num = rand() & (To - From + 1) + From;
    return Num;
}

void FillMatrixWithRandomNumber(int arr[3][3], short Rows, short Cols){

    for (int i = 0; i < Rows; i++){
        for (int j = 0; j < Cols; j++){
            arr[i][j] = Randint(1, 100);
        }
    }

}

void PrintMatrix(int arr[3][3], short Rows, short Cols){

    for (int i = 0; i < Rows; i++){
        for (int j = 0; j < Cols; j++){
            cout << setw(3) << arr[i][j] << "    ";
        }
        cout << endl;
    }
}

int GetRowSum(int arr[3][3], short Row, short Cols){
    int Sum = 0;
    for (int Col = 0; Col < Cols; Col++){
        Sum += arr[Row][Col];
    }
    return Sum;
}

void PrintRowsSum(int arr[3][3], short Rows, short Cols){
    for (short Row = 0; Row < Rows; Row++){
        cout << "Row " << Row+1 << " Sum = " << GetRowSum(arr, Row, Cols) << endl;
    }
}

int main(){
    srand((unsigned)time(NULL));

    int arr[3][3];
    short Rows = 3, Cols = 3;
    FillMatrixWithRandomNumber(arr, Rows, Cols);

    cout << "\n\nThe following is a 3x3 random matrix : " << endl;
    PrintMatrix(arr, Rows, Cols);

    cout << "\n\nThe following are the sum of each row in the matrix : " << endl;
    PrintRowsSum(arr, Rows, Cols);

    system("pause > 0");

    return 0;
}
*/

/// Problem #3 ( Sum Each Row in Matrix in Array )
// Wrint a Program to fill a 3x3 matrix with random with random numbers,
// then sum each each row ini separate array and print the results.
/*
#include <iostream>
#include <cstdlib>
#include <string>
#include <iomanip>
using namespace std;

int Randint(int From, int To) {
    int Num = rand() % (To - From + 1) + From;
    return Num;
}

void FillMatrixWithRandomNumbers(int arr[3][3], short Rows, short Cols) {
    for (short Row = 0; Row < Rows; Row++) {
        for (short Col = 0; Col < Cols; Col++) {
            arr[Row][Col] = Randint(1, 100);
        }
    }
}

void PrintMatrix(int arr[3][3], short Rows, short Cols) {
    for (short Row = 0; Row < Rows; Row++) {
        for (short Col = 0; Col < Cols; Col++) {
            cout << setw(3) << arr[Row][Col] << "    ";
        }
        cout << endl;
    }
}

int GetRowSum(int arr[3][3], short Row, short Cols){
    int Sum = 0;
    for (int Col = 0; Col < Cols; Col++){
        Sum += arr[Row][Col];
    }
    return Sum;
}


void FillArrayWithRowSum(int RowSum[3], int arr[3][3], short Rows, short Cols) {
    for (short Row = 0; Row < Rows; Row++) {
        RowSum[Row] = GetRowSum(arr, Row, Cols);
    }
}

void PrintRowSum(int RowSum[3], short Rows ){

    for (short Row = 0; Row < Rows; Row++) {
        cout << "Row " << Row+1 << " Sum = " << RowSum[Row] << endl;
    }
}

int main() {
    srand((unsigned)time(NULL));

    int arr[3][3], RowSum[3];
    short Rows = 3, Cols = 3;
    FillMatrixWithRandomNumbers(arr, Rows, Cols);


    cout << "The Following is a 3x3 random matrix: " << endl;
    PrintMatrix(arr, Rows, Cols);

    FillArrayWithRowSum(RowSum, arr, Rows, Cols);

    cout << "\n\nThe following are the sum of each row in the matrix : " << endl;
    PrintRowSum(RowSum, Rows);

    system("pause>0");
}
*/

/// Problem #4 ( Sum Each Col in Matrix )
// Write Program to fill a 3x3 matrix with random numbers, then print each Col Sum:
/*
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <string>

using namespace std;

int Randint(int From, int To){
    int Num = rand() & (To - From + 1) + From;
    return Num;
}

void FillMatrixWithRandomNumber(int arr[3][3], short Rows, short Cols){

    for (int i = 0; i < Rows; i++){
        for (int j = 0; j < Cols; j++){
            arr[i][j] = Randint(1, 100);
        }
    }

}

void PrintMatrix(int arr[3][3], short Rows, short Cols){

    for (int i = 0; i < Rows; i++){
        for (int j = 0; j < Cols; j++){
            cout << setw(3) << arr[i][j] << "    ";
        }
        cout << endl;
    }
}

int GetColsSum(int arr[3][3], short Rows, short Col) {
    int Sum = 0;
    for (short Row = 0; Row < Rows; Row++) {
        Sum += arr[Row][Col];
    }
    return Sum;
}

void PrintColSum(int arr[3][3], short Rows, short Cols) {
    for (short Col = 0; Col < Cols; Col++) {
        cout << "Col " << Col+1 << " Sum = " << GetColsSum(arr, Rows, Col) << endl;
    }
}

int main() {
    srand((unsigned)time(NULL));

    int arr[3][3];
    short Rows = 3, Cols = 3;

    FillMatrixWithRandomNumber(arr, Rows, Cols);

    cout << "\nThe following is a 3x3 random matrix: " << endl;
    PrintMatrix(arr, Rows, Cols);

    cout << "\n\nThe following are the sum of each col in the matrix : " << endl;
    PrintColSum(arr, Rows, Cols);

    system("pause > 0");
}
*/

/// Problem #5 ( Sum Each Col in Matrix In Another Array )
// Write a program to fill a 3x3 matrix with random numbers,
// then sum each Col in another array and print them:
/*
#include <iostream>
#include <cstdlib>
#include <string>
#include <iomanip>

using namespace std;

int Randint(int From, int To) {
    int Num = rand() % (To - From + 1) + From;
    return Num;
}

void FillMatrixWithRandomNumbers(int arr[3][3], short Rows, short Cols) {
    for (short Row = 0; Row < Rows; Row++) {
        for (short Col = 0; Col < Cols; Col++) {
            arr[Row][Col] = Randint(1, 100);
        }
    }
}

void PrintMatrix(int arr[3][3], short Rows, short Cols) {
    for (short Row = 0; Row < Rows; Row++) {
        for (short Col = 0; Col < Cols; Col++) {
            cout << setw(3) << arr[Row][Col] << "    ";
        }
        cout << endl;
    }
}

int GetColSum(int arr[3][3], short Rows, short Col){
    int Sum = 0;
    for (int Row = 0; Row < Rows; Row++){
        Sum += arr[Row][Col];
    }
    return Sum;
}

void FillArrayWithColSum(int ColSum[3], int arr[3][3], short Rows, short Cols) {
    for (short Col = 0; Col < Cols; Col++) {
        ColSum[Col] = GetColSum(arr, Rows, Col);
    }
}

void PrintColSum(int ColSum[3], short Cols ){

    for (short Col = 0; Col < Cols; Col++) {
        cout << "Col " << Col+1 << " Sum = " << ColSum[Col] << endl;
    }
}

int main() {
    srand((unsigned)time(NULL));

    int arr[3][3], ColSum[3];
    short Rows = 3, Cols = 3;
    FillMatrixWithRandomNumbers(arr, Rows, Cols);


    cout << "The Following is a 3x3 random matrix: " << endl;
    PrintMatrix(arr, Rows, Cols);

    FillArrayWithColSum(ColSum, arr, Rows, Cols);

    cout << "\n\nThe following are the sum of each Col in the matrix : " << endl;
    PrintColSum(ColSum, Cols);

    system("pause>0");
}
*/

/// Problem #6 ( 3x3 Ordered Matrix )
// Write a program to fill a 3x3 matrix with ordered numbers.
/*
#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;

int Randint(int From, int To) {
    int Num = rand() % (To - From + 1) + From;
    return Num;
}

void FillMatrixWithOrdredNumbers(int arr[3][3], short Rows, short Cols) {
    short Counter = 0;
    for (short Row = 0; Row < Rows; Row++) {
        for (short Col = 0; Col < Cols; Col++) {
            arr[Row][Col] = ++Counter;
        }
    }
}

void PrintMatrix(int arr[3][3], short Rows, short Cols) {
    for (short Row = 0; Row < Rows; Row++) {
        for (short Col = 0; Col < Cols; Col++) {
            cout << setw(3) << arr[Row][Col] << "    ";
        }
        cout << endl;
    }
}

int main() {
    srand((unsigned)time(NULL));

    int arr[3][3];
    short Rows = 3, Cols = 3;
    FillMatrixWithOrdredNumbers(arr, Rows, Cols);

    cout << "The Following is a 3x3 ordered matrix : " << endl;
    PrintMatrix(arr, Rows, Cols);

    system("pause > 0");
}
*/

/// Problem #7 ( Traspose Matrix )
// Write a program to fill a 3x3 matrix with ordered numbers
// and print it, then transpose matrix and print it.
/*
#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;

int Randint(int From, int To) {
    int Num = rand() % (To - From + 1) + From;
    return Num;
}

void FillMatrixWithOrdredNumbers(int arr[3][3], short Rows, short Cols) {
    short Counter = 0;
    for (short Row = 0; Row < Rows; Row++) {
        for (short Col = 0; Col < Cols; Col++) {
            arr[Row][Col] = ++Counter;
        }
    }
}

void PrintMatrix(int arr[3][3], short Rows, short Cols) {
    for (short Row = 0; Row < Rows; Row++) {
        for (short Col = 0; Col < Cols; Col++) {
            cout << setw(3) << arr[Row][Col] << "    ";
        }
        cout << endl;
    }
}

void TransposeMatrix(int arr[3][3], int TransposedMatrix[3][3], short Rows, short Cols) {
    for (int Row = 0; Row < Rows; Row++) {
        for(int Col = 0; Col < Cols; Col++) {
            TransposedMatrix[Row][Col] = arr[Col][Row];
        }
    }
}

int main() {
    srand((unsigned)time(NULL));

    int arr[3][3], TransposedMatrix[3][3];
    short Rows = 3, Cols = 3;
    FillMatrixWithOrdredNumbers(arr, Rows, Cols);

    cout << "The Following is a 3x3 ordered matrix : " << endl;
    PrintMatrix(arr, Rows, Cols);

    TransposeMatrix(arr, TransposedMatrix, Rows, Cols);

    cout << "\n\nThe following is the transposed matrix: " << endl;
    PrintMatrix(TransposedMatrix, Rows, Cols);

    system("pause > 0");
}
*/

/// Problem #8 ( Multiply Two Matrices )
// Write a Program to fill two 3x3 matrix with random numbers and them,
// then multiply them into a 3rd matrix and print it.
/*
#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;

int Randint(int From, int To) {
    int Num = rand() % (To - From + 1) + From;
    return Num;
}

void FillMatrixWithRandomNumbers(int arr[3][3], short Rows, short Cols) {

    for (short Row = 0; Row < Rows; Row++) {
        for (short Col = 0; Col < Cols; Col++) {
            arr[Row][Col] = Randint(1, 9);
        }
    }
}

void FillMatrixWithTwoMatrixesMultiplied(int Matrix1[3][3], int Matrix2[3][3], int Matrix3[3][3], short Rows, short Cols){
    for (short Row = 0; Row < Rows; Row++) {
        for (short Col = 0; Col < Cols; Col++) {
            Matrix3[Row][Col] = Matrix1[Row][Col] * Matrix2[Row][Col];
        }
    }
}

void PrintMatrix(int arr[3][3], short Rows, short Cols) {
    for (short Row = 0; Row < Rows; Row++) {
        for (short Col = 0; Col < Cols; Col++) {
            printf(" %02d   ", arr[Row][Col]);
        }
        cout << endl;
    }
}

int main() {
    srand((unsigned)time(NULL));

    int Matrix1[3][3], Matrix2[3][3], Matrix3[3][3];
    short Rows = 3, Cols = 3;

    FillMatrixWithRandomNumbers(Matrix1, Rows, Cols);
    FillMatrixWithRandomNumbers(Matrix2, Rows, Cols);

    cout << "Matrix1 : " << endl;
    PrintMatrix(Matrix1, Rows, Cols);

    cout << "\nMatrix2 : " << endl;
    PrintMatrix(Matrix2, Rows, Cols);

    FillMatrixWithTwoMatrixesMultiplied(Matrix1, Matrix2, Matrix3, Rows, Cols);

    cout << "\nResults : " << endl;
    PrintMatrix(Matrix3, Rows, Cols);

    system("pause > 0");
}
*/
/// Problem #9 ( Print Middle Row and Col of Matrix )
// Write a program to fill a 3x3 matrix with random numbers,
// print it, then print the middle row and middle col.
/*
#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;

int Randint(int From, int To) {
    int Num = rand() % (To - From + 1) + From;
    return Num;
}

void FillMatrixWithRandomNumbers(int arr[3][3], short Rows, short Cols) {

    for (short Row = 0; Row < Rows; Row++) {
        for (short Col = 0; Col < Cols; Col++) {
            arr[Row][Col] = Randint(1, 100);
        }
    }
}

void PrintMiddleRowInMatrix(int arr[3][3], short Rows, short Cols) {
    int MiddleRow = Rows/2;

    for (short Col = 0; Col < Cols; Col++) {
        printf(" %02d   ", arr[MiddleRow][Col]);
    }
    cout << endl;

}

void PrintMiddleColMatrix(int arr[3][3], short Rows, short Cols) {
    int MiddleCol = Cols/2;
    for (short Row = 0; Row < Rows; Row++) {
        printf(" %02d   ", arr[Row][MiddleCol]);
    }
}

void PrintMatrix(int arr[3][3], short Rows, short Cols) {
    for (short Row = 0; Row < Rows; Row++) {
        for (short Col = 0; Col < Cols; Col++) {
            printf(" %02d   ", arr[Row][Col]);
        }
        cout << endl;
    }
}

int main() {
    srand((unsigned)time(NULL));

    int arr[3][3];
    short Rows = 3, Cols = 3;
    FillMatrixWithRandomNumbers(arr, Rows, Cols);

    cout << "Matrix1 : " << endl;
    PrintMatrix(arr, Rows, Cols);

    cout << "\n\nMiddle Row of Matrix1 is: " << endl;
    PrintMiddleRowInMatrix(arr, Rows, Cols);

    cout << "\n\nMiddle Col of Matrix1 is: " << endl;
    PrintMiddleColMatrix(arr, Rows, Cols);
    cout << endl;

    system("pause > 0");
}
*/

/// Problem #10 ( Sum of Matrix )
// Write a program to fill two 3x3 matrix with random numbers,
// then write a function to sum all numbers in this matrix and print it.
/*
#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;

int Randint(int From, int To) {
    int Num = rand() % (To - From + 1) + From;
    return Num;
}

void FillMatrixWithRandomNumbers(int arr[3][3], short Rows, short Cols) {

    for (short Row = 0; Row < Rows; Row++) {
        for (short Col = 0; Col < Cols; Col++) {
            arr[Row][Col] = Randint(1, 9);
        }
    }
}

int SumOfMatrix(int arr[3][3], short Rows, short Cols) {
    int Sum = 0;
    for (short Row = 0; Row < Rows; Row++) {
        for (short Col = 0; Col < Cols; Col++) {
            Sum += arr[Row][Col];
        }
    }
    return Sum;
}

void PrintMatrix(int arr[3][3], short Rows, short Cols) {
    for (short Row = 0; Row < Rows; Row++) {
        for (short Col = 0; Col < Cols; Col++) {
            printf(" %02d   ", arr[Row][Col]);
        }
        cout << endl;
    }
}

int main() {
    srand((unsigned)time(NULL));

    int Matrix1[3][3];
    short Rows = 3, Cols = 3;

    FillMatrixWithRandomNumbers(Matrix1, Rows, Cols);

    cout << "Matrix1 : " << endl;
    PrintMatrix(Matrix1, Rows, Cols);

    cout << "\n\nSum of Matrix1 is: " << SumOfMatrix(Matrix1, Rows, Cols) << endl;


    system("pause > 0");
}
*/

/// Problem #11 ( Check Matrices Equality )
// Write a program to compare two matrices and check if they are equal or not.
/*
#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;

int Randint(int From, int To) {
	int Num = rand() % (To - From + 1) + From;
	return Num;
}

void FillMatrixWithRandomNumber(int arr[3][3], short Rows, short Cols) {
	for (short Row = 0; Row < Rows; Row++) {
		for (short Col = 0; Col < Cols; Col++) {
			arr[Row][Col] = Randint(1, 9);
		}
	}
}

void PrintMatrix(int arr[3][3], short Rows, short Cols) {
	for (short Row = 0; Row < Rows; Row++) {
		for (short Col = 0; Col < Cols; Col++) {
			printf(" %02d   ", arr[Row][Col]);
		}
		cout << endl;
	}
}

int SumOfMatrix(int Matrix[3][3], short Rows, short Cols) {
	int Sum = 0;
	for (short Row = 0; Row < Rows; Row++) {
		for (short Col = 0; Col < Cols; Col++) {
			Sum += Matrix[Row][Col];
		}
	}
	return Sum;
}

bool isMatrixSumEqual(int arr1[3][3], int arr2[3][3], short Rows, short Cols) {
	return (SumOfMatrix(arr1, Rows, Cols) == SumOfMatrix(arr2, Rows, Cols));
}

int main() {
	srand((unsigned)time(NULL));

	int arr1[3][3], arr2[3][3];
	short Rows = 3, Cols = 3;

	FillMatrixWithRandomNumber(arr1, Rows, Cols);
	FillMatrixWithRandomNumber(arr2, Rows, Cols);

	cout << "\nMatrix1: \n";
	PrintMatrix(arr1, Rows, Cols);

	cout << "\n\n\Matrix2: \n";
	PrintMatrix(arr2, Rows, Cols);

	if (!isMatrixSumEqual(arr1, arr2, Rows, Cols)) {
		cout << "\nNo: martrices are NOT equal. \n";
	}
	else {
		cout << "\nYes: matricies are equal. \n";
	}
	system("pause > 0");
}
*/

/// Problem #12 ( Check Typical Matrices )
// Write a program to compare two matrices and check if they are typical or not.
/*
#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;

int Randint(int From, int To) {
	int Num = rand() % (To - From + 1) + From;
	return Num;
}

void FillMatrixWithRandomNumber(int arr[3][3], short Rows, short Cols) {
	for (short Row = 0; Row < Rows; Row++) {
		for (short Col = 0; Col < Cols; Col++) {
			arr[Row][Col] = Randint(1, 9);
		}
	}
}

void PrintMatrix(int arr[3][3], short Rows, short Cols) {
	for (short Row = 0; Row < Rows; Row++) {
		for (short Col = 0; Col < Cols; Col++) {
			printf(" %02d   ", arr[Row][Col]);
		}
		cout << endl;
	}
}

bool AreTypicalEqual(int Matrix1[3][3], int Matrix2[3][3], short Rows, short Cols) {
	for (short Row = 0; Row < Rows; Row++) {
		for (short Col = 0; Col < Cols; Col++) {
			if (Matrix1[Row][Col] != Matrix2[Row][Col]) {
				return false;
			}
		}
	}
	return true;
}

int main() {
	srand((unsigned)time(NULL));

	int Matrix1[3][3], Matrix2[3][3];
	short Rows = 3, Cols = 3;

	FillMatrixWithRandomNumber(Matrix1, Rows, Cols);
	cout << "\nMatrix1: \n";
	PrintMatrix(Matrix1, Rows, Cols);

	FillMatrixWithRandomNumber(Matrix2, Rows, Cols);
	cout << "\n\n Matrix2: \n";
	PrintMatrix(Matrix2, Rows, Cols);

	if (!AreTypicalEqual(Matrix1, Matrix2, Rows, Cols)) {
		cout << "\nNo: matrices are NOT equal. " << endl;
	}
	else {
		cout << "\nYes: Both Matrices are Equal. " << endl;
	}

	system("pause > 0");
}
*/

/// Problem #13 ( Check Identity Matrix )
// Write a program to check if the matrix is identity or not
/*
#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;

void PrintMatrix(int arr[3][3], short Rows, short Cols) {
	for (short Row = 0; Row < Rows; Row++) {
		for (short Col = 0; Col < Cols; Col++) {
			printf(" %02d   ", arr[Row][Col]);
		}
		cout << endl;
	}
}

bool isIdentityMatrix(int Matrix[3][3], short Rows, short Cols) {
	for (short Row = 0; Row < Rows; Row++) {
		for (short Col = 0; Col < Cols; Col++) {
			if (Row == Col && Matrix[Row][Col] != 1) {
				return false;
			}
			else if (Row != Col && Matrix[Row][Col] != 0) {
				return false;
			}
		}
	}
	return true;
}

int main() {
	int Matrix[3][3] = {
		{1, 0, 0},
		{0, 1, 0},
		{0, 0, 1}
	};
	short Rows = 3, Cols = 3;

	cout << "\nMatrix: \n";
	PrintMatrix(Matrix, Rows, Cols);

	if (isIdentityMatrix(Matrix, Rows, Cols)) {
		cout << "Yes: Matrix is identity. " << endl;
	}
	else {
		cout << "No: Matrix is not identity. " << endl;
	}

	system("Pause > 0");
}
*/

/// Problem #14 ( Check Scalar Matrix )
// Write a program to check if the matrix is Scalar or not.
/*
#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;

void PrintMatrix(int arr[3][3], short Rows, short Cols) {
	for (short Row = 0; Row < Rows; Row++) {
		for (short Col = 0; Col < Cols; Col++) {
			printf(" %02d   ", arr[Row][Col]);
		}
		cout << endl;
	}
}

bool isScalarMatrix(int Matrix[3][3], short Rows, short Cols) {

	int FirstNumber = Matrix[0][0];

	for (short Row = 0; Row < Rows; Row++) {

		for (short Col = 0; Col < Cols; Col++) {


			if (Row == Col && Matrix[Row][Col] != FirstNumber) {
				return false;
			}
			else if (Row != Col && Matrix[Row][Col] != 0) {
				return false;
			}

		}

	}

	return true;
}

int main() {
	int Matrix[3][3] = {
		{5, 0, 0},
		{0, 5, 0},
		{0, 0, 5}
	};
	short Rows = 3, Cols = 3;

	cout << "\nMatrix: \n";
	PrintMatrix(Matrix, Rows, Cols);

	if (isScalarMatrix(Matrix, Rows, Cols)) {
		cout << "Yes: Matrix is Scalar. " << endl;
	}
	else {
		cout << "No: Matrix is not Scalar. " << endl;
	}

	system("Pause > 0");
}
*/

/// Problem #15 ( Count Number in Matrix )
// Write a program to count given number in matrix.
/*
#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;

int Randint(int From, int To) {
	int Num = rand() % (To - From + 1) + From;
	return Num;
}

void FillMatrixWithRandomNumber(int arr[3][3], short Rows, short Cols) {
	for (short Row = 0; Row < Rows; Row++) {
		for (short Col = 0; Col < Cols; Col++) {
			arr[Row][Col] = Randint(1, 9);
		}
	}
}

void PrintMatrix(int arr[3][3], short Rows, short Cols) {
	for (short Row = 0; Row < Rows; Row++) {
		for (short Col = 0; Col < Cols; Col++) {
			printf(" %02d   ", arr[Row][Col]);
		}
		cout << endl;
	}
}

short GetNumberCountInMatrix(int Matrix[3][3], short Number, short Rows, short Cols) {

	short Counter = 0;

	for (short Row = 0; Row < Rows; Row++) {

		for (short Col = 0; Col < Cols; Col++) {

			if (Number == Matrix[Row][Col]) {
				Counter++;
			}

		}

	}

	return Counter;
}

int main() {
	int Matrix[3][3];
	short Rows = 3, Cols = 3;
	short Num;

	FillMatrixWithRandomNumber(Matrix, Rows, Cols);
	cout << "\nMatrix: \n";
	PrintMatrix(Matrix, Rows, Cols);


	cout << "\nEnter the number to count in matrix? ";
	cin >> Num;

	cout << "\nNumber " << Num << " count in matrix is " << GetNumberCountInMatrix(Matrix, Num, Rows, Cols) << endl;

	system("Pause > 0");
}
*/
/*
#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;

void PrintMatrix(int arr[3][3], short Rows, short Cols) {
	for (short Row = 0; Row < Rows; Row++) {
		for (short Col = 0; Col < Cols; Col++) {
			printf(" %02d   ", arr[Row][Col]);
		}
		cout << endl;
	}
}

bool isSparceMatrix(int Matrix[3][3], short Rows, short Cols) {

	short ZeroNumber = 0;

	for (short Row = 0; Row < Rows; Row++) {

		for (short Col = 0; Col < Cols; Col++) {

			if (Matrix[Row][Col] == 0) {
				ZeroNumber++;
				if (ZeroNumber > Rows * Cols / 2) {
					return true;
				}
			}

		}

	}
	return false;
}

int main() {
	int Matrix[3][3] = {
		{0, 0, 12},
		{0, 0, 1},
		{0, 0, 9}
	};
	short Rows = 3, Cols = 3;

	cout << "\nMatrix: \n";
	PrintMatrix(Matrix, Rows, Cols);

	if (isSparceMatrix(Matrix, Rows, Cols)) {
		cout << "Yes: It is Sparse. " << endl;
	}
	else {
		cout << "No: It's NOT Sparce. " << endl;
	}

	system("Pause > 0");
}
*/
/*
#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;

void PrintMatrix(int arr[3][3], short Rows, short Cols) {
	for (short Row = 0; Row < Rows; Row++) {
		for (short Col = 0; Col < Cols; Col++) {
			printf(" %02d   ", arr[Row][Col]);
		}
		cout << endl;
	}
}

short GetNumberCountInMatrix(int Matrix[3][3], short Number, short Rows, short Cols) {

	short Counter = 0;

	for (short Row = 0; Row < Rows; Row++) {

		for (short Col = 0; Col < Cols; Col++) {

			if (Number == Matrix[Row][Col]) {
				Counter++;
			}

		}

	}

	return Counter;
}

bool isSparceMatrix(int Matrix[3][3], short Rows, short Cols) {

	short MatrixSize = Rows * Cols;

	return (GetNumberCountInMatrix(Matrix, 0, Rows, Cols) >= (MatrixSize / 2));
}

int main() {
	int Matrix[3][3] = {
		{0, 0, 12},
		{0, 6, 1},
		{0, 9, 9}
	};
	short Rows = 3, Cols = 3;

	cout << "\nMatrix: \n";
	PrintMatrix(Matrix, Rows, Cols);

	if (isSparceMatrix(Matrix, Rows, Cols)) {
		cout << "\nYes: It is Sparse. " << endl;
	}
	else {
		cout << "\nNo: It's NOT Sparce. " << endl;
	}

	system("Pause > 0");
}
*/

/// Problem #17 ( Number Exists In Matrix )
// Write a program to check if a given number exists in matrix or not.
/*
#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;

void PrintMatrix(int arr[3][3], short Rows, short Cols) {
	for (short Row = 0; Row < Rows; Row++) {
		for (short Col = 0; Col < Cols; Col++) {
			printf(" %02d   ", arr[Row][Col]);
		}
		cout << endl;
	}
}

bool isInMatrix(int Matrix[3][3], short Number, short Rows, short Cols) {

	for (short Row = 0; Row < Rows; Row++) {

		for (short Col = 0; Col < Cols; Col++) {

			if (Number == Matrix[Row][Col]) {
				return true;
			}

		}

	}
	return false;
}

int main() {
	int Matrix[3][3] = {
		{0, 0, 12},
		{0, 6, 1},
		{0, 9, 9}
	};
	short Rows = 3, Cols = 3;
	short Number;

	cout << "\nMatrix: \n";
	PrintMatrix(Matrix, Rows, Cols);

	cout << "\n\nPlease Enter the Number to look for in matrix? ";
	cin >> Number;

	if (isInMatrix(Matrix, Number, Rows, Cols)) {
		cout << "\nYes: It is There. " << endl;
	}
	else {
		cout << "\nNo: It's NOT There. " << endl;
	}

	system("Pause > 0");
}
*/

/// Problem #18 ( Intersected Numbers in Matrics )
// Write a program to print the intersected numbers in two given matrices.
/*
#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;

void PrintMatrix(int arr[3][3], short Rows, short Cols) {
	for (short Row = 0; Row < Rows; Row++) {
		for (short Col = 0; Col < Cols; Col++) {
			printf(" %02d   ", arr[Row][Col]);
		}
		cout << endl;
	}
}

bool isInMatrix(int Matrix[3][3], short Number, short Rows, short Cols) {

	for (short Row = 0; Row < Rows; Row++) {

		for (short Col = 0; Col < Cols; Col++) {

			if (Number == Matrix[Row][Col]) {
				return true;
			}

		}

	}
	return false;
}

void PrintIntersectedNumbers(int Matrix1[3][3], int Matrix2[3][3], short Rows, short Cols) {

	for (short Row = 0; Row < Rows; Row++) {

		for (short Col = 0; Col < Cols; Col++) {

			if (isInMatrix(Matrix1, Matrix2[Row][Col], Rows, Cols)) {

				cout << Matrix2[Row][Col] << "     ";

			}

		}

	}

}

int main() {
	int Matrix[3][3] = {
		{77,5,12},
		{22,20,1},
		{1,0,9}
	};
	int Matrix2[3][3] = {
		{5,80,90},
		{22,77,1},
		{10,8,33}
	};

	short Rows = 3, Cols = 3;

	cout << "\nMatrix1: \n";
	PrintMatrix(Matrix, Rows, Cols);

	cout << "\nMatrix2: \n";
	PrintMatrix(Matrix2, Rows, Cols);

	cout << "\nIntersected Numbers are: \n";
	PrintIntersectedNumbers(Matrix, Matrix2, Rows, Cols);

	system("Pause > 0");
}
*/

/// Problem #19 ( Min/Max Number in Matrix )
// Write a program to print the Minimum and Maximum Numbers in Matrix.
/*
#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;

void PrintMatrix(int arr[3][3], short Rows, short Cols) {
	for (short Row = 0; Row < Rows; Row++) {
		for (short Col = 0; Col < Cols; Col++) {
			printf(" %02d   ", arr[Row][Col]);
		}
		cout << endl;
	}
}

short MaximumNumberInMatrix(int Matrix[3][3], short Rows, short Cols) {
	short MaxNum = Matrix[0][0];
	for (short Row = 0; Row < Rows; Row++) {

		for (short Col = 0; Col < Cols; Col++) {

			if (Matrix[Row][Col] > MaxNum) {
				MaxNum = Matrix[Row][Col];
			}

		}

	}
	return MaxNum;
}

short MinimumNumberInMatrix(int Matrix[3][3], short Rows, short Cols) {

	short MinNum = Matrix[0][0];

	for (short Row = 0; Row < Rows; Row++) {

		for (short Col = 0; Col < Cols; Col++) {

			if (Matrix[Row][Col] < MinNum) {
				MinNum = Matrix[Row][Col];
			}

		}

	}
	return MinNum;
}

int main() {
	int Matrix[3][3] = {
		{77,5,12},
		{22,20,1},
		{1,0,9}
	};

	short Rows = 3, Cols = 3;

	cout << "\nMatrix1: \n";
	PrintMatrix(Matrix, Rows, Cols);

	cout << "\nMinimum Number is: " << MinimumNumberInMatrix(Matrix, Rows, Cols) << endl;
	cout << "\nMaximum Number is: " << MaximumNumberInMatrix(Matrix, Rows, Cols) << endl;

	system("Pause > 0");
}
*/

/// Prroblem #20 ( Palindrome Matrix )
// Write a program to check it the matrix is Palindrome or not.
/*
#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;

void PrintMatrix(int arr[3][3], short Rows, short Cols) {
	for (short Row = 0; Row < Rows; Row++) {
		for (short Col = 0; Col < Cols; Col++) {
			printf(" %02d   ", arr[Row][Col]);
		}
		cout << endl;
	}
}

short isPalindromeMatrix(int Matrix[3][3], short Rows, short Cols) {

	for (short Row = 0; Row < Rows; Row++) {

		for (short Col = 0; Col < Cols/2; Col++) {

			if (Matrix[Row][Col] != Matrix[Row][Cols - 1 - Col]) {
				return false;
			}

		}

	}
	return true;
}

int main() {
	int Matrix[3][3] = {
		{13,5 ,13},
		{22,20,22},
		{9 ,0 , 9}
	};

	short Rows = 3, Cols = 3;

	cout << "\nMatrix1: \n";
	PrintMatrix(Matrix, Rows, Cols);

	if (isPalindromeMatrix(Matrix, Rows, Cols)) {
		cout << "\nYes: Matrix is Palindrome. " << endl;
	}
	else {
		cout << "\nNo: Matrix is NOT Palindrome. " << endl;
	}

	system("Pause > 0");
}
*/

/// Problem #21 ( Fibonacci Series )
// Write a program to print Fibonacci Series of 10.
/*
#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;

void PrintFibonacciSeriesOfN(short N) {
	unsigned long long FibNumber = 0;
	unsigned long long Prev2 = 0, Prev1 = 1;
	cout << "1";

	for (short i = 1; i < N; i++) {

		FibNumber = Prev2 + Prev1;
		cout << setw(6) << FibNumber;
		Prev2 = Prev1;
		Prev1 = FibNumber;
		if (i % 10 == 0) {
			cout << endl;
		}

	}

}

int main() {

	PrintFibonacciSeriesOfN(10);

	return 0;
}
*/

/// Problem #22 ( Fibonacci Series With Recursion )
// Write a program to print Fibonacci Series of 10.
/*
#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;

void PrintFibonacciSeriesOfN(short N, long FibNumber, long Prev1, long Prev2) {



	if (N > 0) {

		FibNumber = Prev2 + Prev1;
		cout << setw(4) << FibNumber;
		Prev2 = Prev1;
		Prev1 = FibNumber;
		PrintFibonacciSeriesOfN(N - 1, FibNumber, Prev1, Prev2);
	}

}

int main() {

	cout << setw(4) << "1";
	PrintFibonacciSeriesOfN(10, 0, 1, 0);

	return 0;
}
*/

/// Problem #23 ( Print First Letter of Each Word )
// Write a program to read a string then print the first letter or each word in that string
/*
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

string ReadString(string Message) {
	string Sentence;
	cout << Message << endl;
	getline(cin, Sentence);
	return Sentence;
}

void PrintFirstStringOfEveryWord(string Sentence) {

	bool isFirstLetter = true;

	for (short i = 0; i < Sentence.length(); i++) {

		if (Sentence[i] != ' ' && isFirstLetter) {
			cout << Sentence[i] << "   ";
		}

		isFirstLetter = (Sentence[i] == ' ' ? true : false);
	}
}

int main() {

	PrintFirstStringOfEveryWord(ReadString("Please Enter Your String? : "));

	system("pause > 0");

}
*/

/// Problem #24 ( Upper First Letter of Each Word )
// Write a program to read a string then uppercase the first letter
// of each word in that string
/*
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

string ReadString(string Message) {
	string Sentence;
	cout << Message << endl;
	getline(cin, Sentence);
	return Sentence;
}

void MakeEveryWordsFirstLetterCapital(string Sentence) {
	bool isFirstLetter = true;

	for (short i = 0; i < Sentence.length(); i++) {
		if (Sentence[i] != ' ' && isFirstLetter) {
			Sentence[i] = toupper(Sentence[i]);
		}

		isFirstLetter = (Sentence[i] == ' ') ? true : false;
	}
	cout << "\nString after conversion: " << endl;
	cout << Sentence << endl;
}

int main() {
	MakeEveryWordsFirstLetterCapital(ReadString("Enter The String : "));

	return 0;
}
*/

/// Problem #25 ( Lower First Letter of Each Word )
// Write a program to read a string then lowercase the first letter of each word in that string
/*
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

string ReadString(string Message) {
	string Sentence;
	cout << Message << endl;
	getline(cin, Sentence);
	return Sentence;
}

void MakeEveryWordsFirstLetterSmall(string Sentence) {
	bool isFirstLetter = true;

	for (short i = 0; i < Sentence.length(); i++) {
		if (Sentence[i] != ' ' && isFirstLetter) {
			Sentence[i] = tolower(Sentence[i]);
		}

		isFirstLetter = (Sentence[i] == ' ') ? true : false;
	}
	cout << "\nString after conversion: " << endl;
	cout << Sentence << endl;
}

int main() {
	MakeEveryWordsFirstLetterSmall(ReadString("Enter Your String? : "));
}
*/
/*
#include <iostream>
#include <string>

using namespace std;

string ReadString(string Message) {
	string Sentence;
	cout << Message << endl;
	getline(cin, Sentence);
	return Sentence;
}

string MakeEveryLetterCapital(string Sentence) {
	for (short i = 0; i < Sentence.length(); i++) {
		Sentence[i] = toupper(Sentence[i]);
	}
	return Sentence;
}

string MakeEveryLetterSmall(string Sentence) {
	for (short i = 0; i < Sentence.length(); i++) {
		Sentence[i] = tolower(Sentence[i]);
	}
	return Sentence;
}

int main() {
	string Sentence = ReadString("Please Enter Your String? : ");

	cout << "\nString after Upper: \n";
	cout << MakeEveryLetterCapital(Sentence) << endl;

	cout << "\nString after Lower: \n";
	cout << MakeEveryLetterSmall(Sentence) << endl;

	return 0;
}
*/

/// Problem #27 ( Invert Character Case )
// Write a program to read a character then inverr it's case and print it.
/*
#include <iostream>
#include <string>

using namespace std;

char ReadLetter(string Message) {
	char Letter;
	cout << Message << endl;
	cin >> Letter;
	return Letter;
}

void InvertLetterCase(char& Letter) {
	Letter =  isupper(Letter) ? tolower(Letter) : toupper(Letter);
}

int main() {
	char Letter = ReadLetter("Please Enter a Character? ");

	InvertLetterCase(Letter);
	cout << "\nChar after inverting Case : \n";
	cout << Letter << endl;

}
*/

/// Problem #28 ( Invert All Letters Case )
// Write a program to read a string then invert all its letter's case and print it.
/*
#include <iostream>
#include <string>

using namespace std;

string ReadString(string Message) {
	string Sentence;
	cout << Message << endl;
	getline(cin, Sentence);
	return Sentence;
}

char InvertLetterCase(char Letter) {
	return (isupper(Letter) ? tolower(Letter) : toupper(Letter));
}

string InvertAllString(string Sentence) {
	for (short i = 0; i < Sentence.length(); i++) {
		Sentence[i] = InvertLetterCase(Sentence[i]);
	}
	return Sentence;
}

int main() {
	string Sentence = ReadString("Please Enter Your String? ");

	cout << "\nString after Inverting All Letters Case: " << endl;
	cout << InvertAllString(Sentence) << endl;

	return 0;
}
*/

/// Problem #29 ( Count Small/Capital Letters )
// Write a program to read string then count small/capital letters in that string
/*
#include <iostream>
#include <string>

using namespace std;

enum enWhatToCount { CapitalLetter, SmallLetter, All };

string ReadString(string Message) {
	string Sentence;
	cout << Message << endl;
	getline(cin, Sentence);
	return Sentence;
}

short CountLetter(string Sentence, enWhatToCount WhatToCount = enWhatToCount::All) {
	short Counter = 0;
	for (short i = 0; i < Sentence.length(); i++) {

		if (WhatToCount == enWhatToCount::CapitalLetter && isupper(Sentence[i])) {
			Counter++;
		}

		if (WhatToCount == enWhatToCount::SmallLetter && islower(Sentence[i])) {
			Counter++;
		}

		if (WhatToCount == enWhatToCount::All) {
			Counter++;
		}

	}
	return Counter;
}

int main() {
	string Sentence = ReadString("Please Enter Your String? ");

	cout << "\nString Length = " << CountLetter(Sentence) << endl;
	cout << "Capital Letters Count = " << CountLetter(Sentence, enWhatToCount::CapitalLetter) << endl;
	cout << "Small Letters Count = " << CountLetter(Sentence, enWhatToCount::SmallLetter) << endl;

	return 0;
}
*/

/// Problem #30 ( Count Letter )
// Write a program to read a string and read a character then count the character in that string
/*
#include <iostream>
#include <string>

using namespace std;

char ReadLetter(string Message) {
	char Letter;
	cout << Message << endl;
	cin >> Letter;
	return Letter;
}

string ReadString(string Message) {
	string Sentence;
	cout << Message << endl;
	getline(cin, Sentence);
	return Sentence;
}

short GetLetterCount(string Sentence, char Letter) {
	short Counter = 0;
	for (short i = 0; i < Sentence.length(); i++) {
		if (Sentence[i] == Letter) {
			Counter++;
		}
	}
	return Counter;
}

int main() {
	string Sentence = ReadString("Please Enter Your String? ");
	cout << '\n';
	char Character = ReadLetter("Please Enter a Character? ");

	cout << "\nLetter '" << Character << "' Count = " << GetLetterCount(Sentence, Character) << endl;

	return 0;
}
*/

/// Problem #31 ( Count Letters (Match Case) )
// Write a program to read a string and read a character then count the character in that string (Match Case or Not)
/*
#include <iostream>
#include <string>

using namespace std;

string ReadString(string Message) {
	string Sentence;
	cout << Message << endl;
	getline(cin, Sentence);
	return Sentence;
}

char ReadCharacter(string Message) {
	char Character;
	cout << Message << endl;
	cin >> Character;
	return Character;
}

short GetCharacterCount(string Sentence, char Character, bool MatchCase = true) {
	short Counter = 0;
	for (short i = 0; i < Sentence.length(); i++) {

		if (MatchCase) {

			if (Sentence[i] == Character) {
				Counter++;
			}

		}
		else {

			if (islower(Sentence[i]) == islower(Character)) {
				Counter++;
			}

		}

	}
	return Counter;
}

char InvertMatchCase(char Character) {
	return (isupper(Character) ? tolower(Character) : toupper(Character));
}

int main() {
	string Sentence = ReadString("Please Enter Your String? ");
	cout << endl;
	char Character = ReadCharacter("Please Enter a Character? ");

	cout << "\nLetter '" << Character << "' Count = ";
	cout << GetCharacterCount(Sentence, Character) << endl;
	cout << "Letter '" << Character << "' Or '" << InvertMatchCase(Character) << "'  Count = ";
	cout << GetCharacterCount(Sentence, Character, false) << endl;

	return 0;
}
*/

/// Problem #32 ( Is Vowel? )
// Write a program to read character the check if it is a vowel or not ( Vowels are: a, e, i, o, u )
/*
#include <iostream>
#include <string>
#include <iomanip>
#include <vector>

using namespace std;

char ReadCharacter(string Message) {
	char Character;
	cout << Message << endl;
	cin >> Character;
	return Character;
}

bool isVowel(char Character) {
    char ch = tolower(Character);

	//vector <char> vVowels = { 'a', 'e', 'i', 'o', 'u'};
	//
	//for (char& i : vVowels) {
	//	if (Character == i) {
	//		return true;
	//	}
	//}
	//return false;


	return ((ch == 'a') || (ch == 'e') || (ch == 'i') || (ch == 'o') || (ch == 'u'));

}

int main() {
	char Character = ReadCharacter("Enter a Character ? ");


	if (isVowel(Character)) {
		cout << "\nYes Letter \'" << Character << "\' is vowel" << endl;
	}
	else {
		cout << "\nNo Letter \'" << Character << "\' is Not vowel" << endl;
	}

	return 0;
}
*/

/// Problem #33 ( Count Vowels )
// Write a program to read string then count all vowels in that string (Vowels are: a, e, i, o, u)
/*
#include <iostream>
#include <string>

using namespace std;

string ReadString(string Message) {
    string Sentence;
    cout << Message << endl;
    getline(cin, Sentence);
    return Sentence;
}

bool isVowel(char ch) {
    ch = tolower(ch);
    return ((ch == 'a') || (ch == 'e') || (ch == 'i') || (ch == 'o') || (ch == 'u'));
}

short CountVowels(string Sentence){
    short Counter = 0;
    for (short i = 0; i < Sentence.length(); i++) {
        if (isVowel(Sentence[i])) {
            Counter++;
        }
    }
    return Counter;
}

int main() {
    string Sentence = ReadString("Please Enter Your String? ");

    cout << "\nNumber of vowels is: " << CountVowels(Sentence) << endl;

    return 0;
}
 */

/// Problem #34 ( Print All Vowels In String )
// Write a program to read a string then print all vowels in that string (Vowels are: a, e, i, o, u)
/*
#include <iostream>
#include <string>

using namespace std;

string ReadString(string Message){
    string Sentence;
    cout << Message << endl;
    getline(cin, Sentence);
    return Sentence;
}

bool isVowel(char ch) {
    ch = tolower(ch);
    return ((ch == 'a') || (ch == 'e') || (ch == 'i') || (ch == 'o') || (ch == 'u'));
}

void PrintVowels(string Sentence){
    cout << "\nVowels in string are: ";
    for (short i = 0; i < Sentence.length(); i++){

        if (isVowel(Sentence[i])){
            cout << Sentence[i] << "    ";
        }
    }
}

int main(){
    string Sentence = ReadString("Please Enter Your String? ");

    PrintVowels(Sentence);

    return 0;
}
 */

/// Problem #35 ( Print Each Word In String )
// Write a program to read a string then print each word in that string.
/*
#include <iostream>
#include <string>

using namespace std;

string ReadString(string Message){
    string Sentence;
    cout << Message << endl;
    getline(cin, Sentence);
    return Sentence;
}

void PrintEveryWord(string Sentence){
//    for (short i = 0; i < Sentence.length(); i++){
//        if (Sentence[i] == ' '){
//            cout << "\n";
//        } else {
//            cout << Sentence[i];
//        }
//    }
    string delim = " ";
    cout << "\nPrinting Every Word : " << endl;
    short pos = 0;
    string sword = "";
    while ((pos = Sentence.find(delim)) != std::string::npos){
        sword = Sentence.substr(0, pos);
        if (sword != ""){
            cout << sword << endl;
        }
        Sentence.erase(0, pos + delim.length());
    }
    if (Sentence != ""){
        cout << Sentence << endl;
    }
}

int main(){

    string Sentence = ReadString("Please Enter Your String? ");

    PrintEveryWord(Sentence);

    return 0;
}
 */

/// Problem #36 ( Count Each Word In String )
// Write a program to read a string then count each word in that string.
/*
#include <iostream>
#include <string>

using namespace std;

string ReadString(string Message){
    string Sentence;
    cout << Message << endl;
    getline(cin, Sentence);
    return Sentence;
}

short CountWords(string Sentence){
    string delim = " ";
    short pos = 0;
    string sword = "";
    short Counter = 0;
    while ((pos = Sentence.find(delim)) != std::string::npos){
        sword = Sentence.substr(0, pos);
        if (sword != ""){
            Counter++;
        }
        Sentence.erase(0, pos + delim.length());
    }
    if (Sentence != ""){
        Counter++;
    }
    return Counter;
}

int main(){
    string Sentence = ReadString("Please Enter Your String? ");
    cout << "The Number of words in your string is: ";
    cout << CountWords(Sentence) << endl;
    return 0;
}
 */

/// Problem #37 ( Split String )
// Write a program to read string then make a function to split each word in vector.
/*
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string ReadString(string Message){
    string Sentence;
    cout << Message << endl;
    getline(cin, Sentence);
    return Sentence;
}

vector<string> SplitString(string Sentence, string delim){

    vector <string> vWord;

    short pos = 0;
    string sWord;

    while ((pos = Sentence.find(delim)) != std::string::npos){
        sWord = Sentence.substr(0, pos);
        if (sWord != ""){
            vWord.push_back(sWord);
        }
        Sentence.erase(0, pos + delim.length());
    }
    if (Sentence != ""){
        vWord.push_back(Sentence);
    }
    return vWord;
}

int main(){
    vector <string> vWord;

    vWord = SplitString(ReadString("Please Enter YOur String? "), " ");

    cout << "\nTokens = " << vWord.size() << endl;

    for (string& s : vWord){
        cout << s << endl;
    }

    system("pause > 0");
}
*/

/// Problem #38 ( TrimLeft, TrimRight, Trim )
// Write a program to read a string then Trim Left, Right, All
/*
#include <iostream>
#include <string>

using namespace std;

string TrimLeft(string S1) {
	for (short i = 0; i < S1.length(); i++) {

		if (S1[i] != ' ') {
			return S1.substr(i, S1.length() - i);
		}

	}
	return "";
}

string TrimRight(string S1) {
	for (short i = S1.length()-1; i >= 0; i--) {
		if (S1[i] != ' ') {
			return S1.substr(0, i+1);
		}
	}
	return "";
}

string Trim(string S1) {
	return TrimRight(TrimLeft(S1));
}

int main() {
	string Sentence = "          My Name Is Ammar Alaee          ";

	cout << "\nString     = " << Sentence;
	cout << "\n\nTrim Left  = " << TrimLeft(Sentence);
	cout << "\nTrim Right = " << TrimRight(Sentence);
	cout << "\nTrim       = " << Trim(Sentence);

	return 0;
}
*/

/// Problem #39 ( Join String )
// Write a program to join vector of strings into a one string with separators
/*
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string JoinStringVector(vector<string> vString, string Delim = " ") {
	string Sentence = "";
	for (string& sWord : vString) {
		Sentence += sWord + Delim;

	}
	return Sentence.substr(0, Sentence.length() - Delim.length());
}

int main() {
	vector <string> vString = { "Ammar", "Hussein", "Mohammed", "Alaee" };

	cout << "Vector after join: " << endl;
	cout << JoinStringVector(vString, "-_-") << endl;

	return 0;
}
*/

/// Problem #40 ( Join String (Overloading) )
// Write a program to join array of strings into a one string with separator
/*
#include <iostream>
#include <vector>
#include <string>

using namespace std;

string JoinString(vector<string> vString, string Delim = " ") {
	string Sentence = "";
	for (string& sWord : vString) {
		Sentence += sWord + Delim;

	}
	return Sentence.substr(0, Sentence.length() - Delim.length());
}

string JoinString(string arr[], short Length, string Delim) {
	string Sentence = "";
	for (short i = 0; i < Length; i++) {
		Sentence += arr[i] + Delim;
	}
	return Sentence.substr(0, Sentence.length() - Delim.length());
}

int main() {
	vector <string> vString = { "Ammar", "Hussein", "Mohammed", "Alaee" };
	string arrString[] = { "Ammar", "Hussein", "Mohammed", "Alaee" };
	short arrLength = 4;

	cout << "Vector after join: " << endl;
	cout << JoinString(vString, "-_-") << endl;

	cout << "\nArray after join: " << endl;
	cout << JoinString(arrString, arrLength, "-_-") << endl;

	return 0;
}
*/

/// Problem #41 ( Reverse Words )
// Write a program to read string and reverse its words. 
/*
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> SplitString(string Sentence, string Delim) {
	vector<string> vString;
	string sWord = "";
	short Pos = 0;
	while ((Pos = Sentence.find(Delim)) != std::string::npos) {
		sWord = Sentence.substr(0, Pos);
		if (sWord != "") {
			vString.push_back(sWord);
		}
		Sentence.erase(0, Pos + Delim.length());
	}
	if (sWord != "") {
		vString.push_back(Sentence);
	}
	return vString;
}

string ReadString(string Message) {
	string Sentence;
	cout << Message << endl;
	getline(cin, Sentence);
	return Sentence;
}

string ReverseWordsInString(string S1) {
	
	vector <string> vString;
	string S2 = "";
	string delim = " ";

	vString = SplitString(S1, delim);

	vector<string>::iterator iter;
	iter = vString.end();

	while (iter > vString.begin()) {
		iter--;
		S2 += *iter + delim;
	}

	return S2.substr(0, S2.length() - delim.length());
}

int main() {
	string Sentence = ReadString("Please Enter Your String? ");

	cout << "\n\nString after reversing words: " << endl;
	cout << ReverseWordsInString(Sentence) << endl;

	return 0;
}
*/

/// Problem #42 ( Replace Words )
// Write a program to replace words in string: 
/*
#include <iostream>
#include <string>

using namespace std;

string ReplaceWordInStringUsingBuiltInFunction(string Sentence, string From, string To) {

	short Pos = 0;
	Pos = Sentence.find(From);
	while (Pos != std::string::npos) {
		Sentence.replace(Pos, From.length(), To);
		Pos = Sentence.find(From);
	}
	return Sentence;
}

int main() {
	
	string Sentence = "Welcome to Yemen , Yemen is a nice Country";
	string From = "Yemen";
	string To = "USA";

	cout << "\nOriginal String\n" << Sentence;
	cout << "\n\nString After Replace\n" << ReplaceWordInStringUsingBuiltInFunction(Sentence, From, To) << endl;

	system("pause > 0");

}
*/

/// Problem #43 ( Replace Words (Custom) )
// Write a program to replace words in string using custom function: 
/*
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> SplitString(string Sentence, string Delim) {
	vector<string> vString;
	string sWord = "";
	short Pos = 0;
	while ((Pos = Sentence.find(Delim)) != std::string::npos) {
		sWord = Sentence.substr(0, Pos);
		if (sWord != "") {
			vString.push_back(sWord);
		}
		Sentence.erase(0, Pos + Delim.length());
	}
	if (sWord != "") {
		vString.push_back(Sentence);
	}
	return vString;
}

string JoinString(vector<string> vString, string Delim = " ") {
	string Sentence = "";
	for (string& sWord : vString) {
		Sentence += sWord + Delim;

	}
	return Sentence.substr(0, Sentence.length() - Delim.length());
}

string ReadString(string Message) {
	string Sentence;
	cout << Message << endl;
	getline(cin, Sentence);
	return Sentence;
}

string LowerAllString(string Sentence) {
	for (short i = 0; i < Sentence.length(); i++) {
		Sentence[i] = tolower(Sentence[i]);
	}
	return Sentence;
}

string ReplaceString(string Sentence, string From, string To, bool MatchCase = true) {
	vector<string> vString;
	vString = SplitString(Sentence, " ");


	// iterator
	vector<string>::iterator iter;

	for (iter = vString.begin(); iter < vString.end(); iter++) {
		if (MatchCase) {
			if (*iter == From) {
				*iter = To;
			}
		}
		else {
			if (LowerAllString(*iter) == LowerAllString(From)) {
				*iter = To;
			}
		}
	}
	
	return JoinString(vString, " ");

}

int main() {

	string Sentence = "Welcome to Turkey , Turkey is a nice Country! , TUrkey , turkey , TURKEY , turkey , Turkey";

	cout << "Orignal String : " << endl;
	cout << Sentence << endl;

	cout << "\nReplace with match case: " << endl;
	cout << ReplaceString(Sentence, "Turkey", "Russia", true) << endl;

	cout << "\nReplace with dont match case: " << endl;
	cout << ReplaceString(Sentence, "Turkey", "Russia", false) << endl;

	return 0;
}
*/

/// Problem #44 ( Remove Punctuations )
// Write a program to remove all punctuations from string:
/*
#include <iostream>
#include <string>

using namespace std;

string RemovePunctuations(string Sentence) {
	
	//for (short i = 0; i < Sentence.length(); i++) {
	//	if (ispunct(Sentence[i])) {
	//		Sentence.erase(i, 1);
	//		i--;
	//	}
	//}
	//return Sentence;
	
	string Sentence2;
	for (short i = 0; i < Sentence.length(); i++) {
		if (!ispunct(Sentence[i])) {
			Sentence2 = Sentence[i];
		}
	}
	return Sentence2;
}

int main() {
	string Sentence = "Welcome to Jo,;:rda()n, Jo;'rdan i()s a n//ice country; it's amaz)ing. ";

	cout << "Original String: " << endl;
	cout << Sentence << endl;

	cout << "\nPuncuations Removed: " << endl;
	cout << RemovePunctuations(Sentence) << endl;

	return 0;
}
*/

/// Problem #45 ( Convert Record to Line )
// Write a program to read bank client data record and convert it to one line: 
/*
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct stData {
	string AccountNumber;
	short PinCode;
	string Name;
	string Phone;
	int AccountBalance;
};

stData ReadData() {
	stData Data;

	cout << "Enter Account Number? ";
	cin >> Data.AccountNumber;
	cout << "Enter PinCode? ";
	cin >> Data.PinCode;
	cout << "Enter Name? ";
	cin >> Data.Name;
	cout << "Enter Phone? ";
	cin >> Data.Phone;
	cout << "Enter Account Balance? ";
	cin >> Data.AccountBalance;

	return Data;
}

string ConvertRecordToLine(stData Data, string Seperator) {
	string Sentence = "";
	Sentence += Data.AccountNumber + Seperator;
	Sentence += to_string(Data.PinCode) + Seperator;
	Sentence += Data.Name + Seperator;
	Sentence += Data.Phone + Seperator;
	Sentence += to_string(Data.AccountBalance);
	return Sentence;
}

int main() {
	cout << "Please Enter Client Data: \n\n";
	stData Data = ReadData();

	cout << "\n\nClient Record for Saving is: \n";
	cout << ConvertRecordToLine(Data, "#//#");

	system("pause > 0");
}
*/

/// Problem #46 ( Convert Line Data To Record )
// Write a program to convert line data to record and print it. 
/*
#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct stClient {
	string AccountNumber;
	short PinCode;
	string Name;
	string Phone;
	int AccountBalance;
};

vector<string> SplitString(string Line, string Seperator) {
	vector <string> vString;
	short Pos = 0;
	string sWord = "";
	while ((Pos = Line.find(Seperator)) != std::string::npos) {
		sWord = Line.substr(0, Pos);
		if (sWord != "") {
			vString.push_back(sWord);
		}
		Line.erase(0, Pos + Seperator.length());
	}
	if (Line != "") {
		vString.push_back(Line);
	}
	return vString;
}

stClient ConvertLineToRecord(string Line, string Seperator) {
	vector<string> vString = SplitString(Line, Seperator);
	stClient Client;

	Client.AccountNumber = vString[0];
	Client.PinCode = stoi(vString[1]);
	Client.Name = vString[2];
	Client.Phone = vString[3];
	Client.AccountBalance = stoi(vString[4]);

	return Client;
}

void PrintRecord(stClient Client) {
	cout << "Account Number : " << Client.AccountNumber << endl;
	cout << "Pin Code       : " << Client.PinCode << endl;
	cout << "Name           : " << Client.Name << endl;
	cout << "Phone          : " << Client.Phone << endl;
	cout << "Account Balance: " << Client.AccountBalance << endl;
}

int main() {
	string Sentence = "A150#//#1234#//#Mohammed Abu-Hadhoud#//#05488775#//#5270";

	cout << "Line Record is: " << endl;
	cout << Sentence << endl;
	cout << "\nThe following is the extracted client record: \n\n";
	PrintRecord(ConvertLineToRecord(Sentence, "#//#"));
	return 0;
}
*/

/// Problem #47 ( Add Clients To File )
// Write a program to ask you to enter clients and save them to file: 
/*
#include <iostream>
#include <string>
#include <fstream>

using namespace std;
const string CilentsFileName = "MyFile.txt";

struct stData {
	string AccountNumber;
	short PinCode;
	string Name;
	string Phone;
	int AccountBalance;
};

stData ReadData() {
	stData Data;

	cout << "Adding New Client : \n\n";

	cout << "Enter Account Number? ";
	// Usage of std::ws will extract all the whitespaces character
	getline(cin >> ws, Data.AccountNumber);
	cout << "Enter PinCode? ";
	cin >> Data.PinCode;
	cout << "Enter Name? ";
	getline(cin >> ws, Data.Name);
	cout << "Enter Phone? ";
	getline(cin, Data.Phone);
	cout << "Enter Account Balance? ";
	cin >> Data.AccountBalance;

	return Data;
}

string ConvertRecordToLine(stData Data, string Seperator) {
	string Sentence = "";

	Sentence += Data.AccountNumber + Seperator;
	Sentence += to_string(Data.PinCode) + Seperator;
	Sentence += Data.Name + Seperator;
	Sentence += Data.Phone + Seperator;
	Sentence += to_string(Data.AccountBalance);

	return Sentence;
}

void AddLineToFile(string FileName, string Line) {
	fstream MyFile;

	MyFile.open(FileName, ios::out | ios::app); //append Mode

	if (MyFile.is_open()) {
		MyFile << Line << endl;
		MyFile.close();
	}
}

void AddNewClient() {
	stData Data = ReadData();
	AddLineToFile(CilentsFileName, ConvertRecordToLine(Data, "#//#"));
}

void AddClients() {
	bool AskAgain = true;

	while (AskAgain) {
		system("cls");
		AddNewClient();

		cout << "Client Added Successfully, do you want to add more clients? (1, 0) ";
		cin >> AskAgain;
	}
}

int main() {
	
	AddClients();

	return 0;
}
*/



/// Problem #48 ( Show All Clients )
// Write a program to read clients file and show then on the screen as follows:
/*
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <iomanip>

using namespace std;

struct stClients {
	string AccountNumber;
	int PinCode;
	string Name;
	string Phone;
	double AccountBalance;
};

vector <string> SplitString(string Sentence, string Delim) {
	vector <string> vString;
	short pos = 0;
	string sWord;

	while ((pos = Sentence.find(Delim)) != std::string::npos) {
		sWord = Sentence.substr(0, pos);
		if (sWord != "") {
			vString.push_back(sWord);
		}
		Sentence.erase(0,pos + Delim.length());
	}
	if (Sentence != "") {
		vString.push_back(Sentence);
	}
	return vString;
}

stClients ConvertLineToRecord(string Line, string Seperator) {
	stClients Client;
	vector <string> vClientData = SplitString(Line, Seperator);

	Client.AccountNumber = vClientData[0];
	Client.PinCode = stoi(vClientData[1]);
	Client.Name = vClientData[2];
	Client.Phone = vClientData[3];
	Client.AccountBalance = stod(vClientData[4]);

	return Client;
}

vector <stClients> LoadDataFromFileToVector(string FileName) {
	fstream MyClient;
	vector <stClients> vClient;
	string Line = "";
	stClients Client;

	MyClient.open(FileName, ios::in);

	if (MyClient.is_open()) {
		while (getline(MyClient, Line)) {
			Client = ConvertLineToRecord(Line, "#//#");
			vClient.push_back(Client);
		}
		MyClient.close();
	}
	return vClient;
}

void PrintClientRecord(stClients Client) {
	cout << "|" << setw(25) << left << Client.AccountNumber;
	cout << "|" << setw(15) << left << Client.PinCode;
	cout << "|" << setw(30) << left << Client.Name;
	cout << "|" << setw(15) << left << Client.Phone;
	cout << "|" << setw(20) << left << Client.AccountBalance;
	cout << "|";
}

void PrintList(vector<stClients>& vClients) {
	cout << "\n                                    Client List (" << vClients.size() << ") Clients(s).                      \n";
	cout << "_______________________________________________________________________________________________________________\n";
	cout << "|" << setw(25) << left << " Account Number ";
	cout << "|" << setw(15) << left << " Pin Code ";
	cout << "|" << setw(30) << left << " Client Name ";
	cout << "|" << setw(15) << left << " Phone ";
	cout << "|" << setw(20) << left << " Balance ";
	cout << "|";
	cout << "\n_______________________________________________________________________________________________________________\n";

	for (stClients& Client : vClients) {
		PrintClientRecord(Client);
		cout << endl;
	}

	cout << "|_____________________________________________________________________________________________________________|\n";
}

int main() {
	vector <stClients> vClients = LoadDataFromFileToVector("MyFile.txt");

	PrintList(vClients);

	system("pause > 0");
}
*/

/// Problem #49 ( Find Client By Account Number )
// Write a program to find client by AccountNumber and print it to the screen:
/*
#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <fstream>

using namespace std;

struct stClients {
	string AccountNumber;
	int PinCode;
	string Name;
	string Phone;
	double AccountBalance;
};

string ReadString(string Message) {
	string Sentence;
	cout << Message << endl;
	getline(cin, Sentence);
	return Sentence;
}

vector <string> SplitString(string Sentence, string Delim) {
	vector <string> vString;
	short pos = 0;
	string sWord;

	while ((pos = Sentence.find(Delim)) != std::string::npos) {
		sWord = Sentence.substr(0, pos);
		if (sWord != "") {
			vString.push_back(sWord);
		}
		Sentence.erase(0, pos + Delim.length());
	}
	if (Sentence != "") {
		vString.push_back(Sentence);
	}
	return vString;
}

stClients ConvertLineToRecord(string Line, string Seperator) {
	stClients Client;
	vector <string> vClientData = SplitString(Line, Seperator);

	Client.AccountNumber = vClientData[0];
	Client.PinCode = stoi(vClientData[1]);
	Client.Name = vClientData[2];
	Client.Phone = vClientData[3];
	Client.AccountBalance = stod(vClientData[4]);

	return Client;
}

vector <stClients> LoadDataFromFileToVector(string FileName) {
	fstream MyClient;
	vector <stClients> vClient;
	string Line = "";
	stClients Client;

	MyClient.open(FileName, ios::in);

	if (MyClient.is_open()) {
		while (getline(MyClient, Line)) {
			Client = ConvertLineToRecord(Line, "#//#");
			vClient.push_back(Client);
		}
		MyClient.close();
	}
	return vClient;
}

void PrintClientCard(stClients Clients) {
	cout << "The following are the client details: \n";

	cout << "\nAccount Number : " << Clients.AccountNumber;
	cout << "\nPin Code       : " << Clients.PinCode;
	cout << "\nName           : " << Clients.Name;
	cout << "\nPhone          : " << Clients.Phone;
	cout << "\nAccount Balance: " << Clients.AccountBalance;
	cout << endl;
}

bool FindClientByAccountNumber(stClients &Client, string AccountNumber) {

	vector<stClients> vClients = LoadDataFromFileToVector("MyFile.txt");

	for (stClients& C : vClients) {
		if (C.AccountNumber == AccountNumber) {

			Client = C;
			return true;
		}
	}
	return false;
}

int main() {
	stClients Client;
	string AccountNumber = ReadString("Please enter Account Number : ");

	if (FindClientByAccountNumber(Client, AccountNumber)) {
		PrintClientCard(Client);
	}
	else {
		cout << "Client with Account Number (" << AccountNumber << ") NOT Found! " << endl;
	}

	return 0;
}
*/

/// Problem #50 ( Delete Client By Account Number )
// Write a program to delete client by AccountNumber : 
/*
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;
const string ClientFileName = "MyFile.txt";

struct stClients {
	string AccountNumber;
	int PinCode;
	string Name;
	string Phone;
	double AccountBalance;
	bool MarkForDelete = false;
};

string ReadString(string Message) {
	string S;
	cout << Message << endl;
	cin >> S;
	return S;
}

vector<string> SplitString(string Sentence, string delim) {
	vector<string> vString;
	short pos = 0;
	string sWord = "";

	while ((pos = Sentence.find(delim)) != std::string::npos) {
		sWord = Sentence.substr(0, pos);
		if (sWord != "") {
			vString.push_back(sWord);
		}
		Sentence.erase(0, pos + delim.length());
	}
	if (Sentence != "") {
		vString.push_back(Sentence);
	}
	return vString;
}

stClients ConvertLineToRecord(string Line, string Seperator) {
	vector<string> vString;
	stClients Client;

	vString = SplitString(Line, Seperator);

	Client.AccountNumber = vString[0];
	Client.PinCode = stoi(vString[1]);
	Client.Name = vString[2];
	Client.Phone = vString[3];
	Client.AccountBalance = stod(vString[4]);

	return Client;
}

string ConvertRecordToLine(stClients Client, string Seperator) {
	string Sentence = "";
	
	Sentence += Client.AccountNumber + Seperator;
	Sentence += to_string(Client.PinCode) + Seperator;
	Sentence += Client.Name + Seperator;
	Sentence += Client.Phone + Seperator;
	Sentence += to_string(Client.AccountBalance) + Seperator;

	return Sentence;
}

void FillFileWithRecords(vector<stClients>& vClients, string FileName) {
	fstream MyFile;
	string Line;

	MyFile.open(FileName, ios::out);
	if (MyFile.is_open()) {

		for (stClients& C : vClients) {

			if (!C.MarkForDelete) {
				Line = ConvertRecordToLine(C, "#//#");
				MyFile << Line << endl;
			}

		}

		MyFile.close();
	}
}

vector<stClients> LoadClientsDataFromFile(string FileName) {
	fstream MyFile;
	string Line;
	stClients Client;
	vector<stClients> vClients;


	MyFile.open(FileName, ios::in);

	if (MyFile.is_open()) {
		while (getline(MyFile, Line)) {
			Client = ConvertLineToRecord(Line, "#//#");
			vClients.push_back(Client);
		}
		MyFile.close();
	}

	return vClients;
}

bool SearchClientByAccountNumber(vector<stClients> vClients, string AccountNumber, stClients &Client) {
	for (stClients& C : vClients) {
		if (C.AccountNumber == AccountNumber) {
			Client = C;
			return true;
		}
	}
	return false;
}

void MarkClientToDelete(vector<stClients> &vClient, string AccountNumber) {
	for (stClients& C : vClient) {
		if (C.AccountNumber == AccountNumber) {
			C.MarkForDelete = true;
			return;
		}
	}
}

void PrintClientCard(stClients Client) {
	cout << "The following are the client details: \n";
	cout << "\nAccount Number: " << Client.AccountNumber;
	cout << "\nPin Code: " << Client.PinCode;
	cout << "\nName: " << Client.Name;
	cout << "\nPhone: " << Client.Phone;
	cout << "\nAccount Balance: " << Client.AccountBalance;
}

void DeleteClientByAccountNumber(vector<stClients>& vClients, string AccountNumber) {
	char Choice = 'N';
	stClients Client;

	if (SearchClientByAccountNumber(vClients, AccountNumber, Client)) {

		PrintClientCard(Client);

		cout << "\n\nAre you sure you want delete this client? y/n ? ";
		cin >> Choice;
		if (tolower(Choice) == 'y') {
			
			MarkClientToDelete(vClients, AccountNumber);

			FillFileWithRecords(vClients, ClientFileName);

			//Refresh Clients
			vClients = LoadClientsDataFromFile(ClientFileName);

			cout << "\n\n\nClient Deleted Successfully. " << endl;
		}
	}

	else {
		cout << "Client With Account Number (" << AccountNumber << ") Not Found! " << endl;
	}
}

int main() {
	string AccountNumber = ReadString("Please enter Account Number? ");
	vector<stClients> vClients = LoadClientsDataFromFile(ClientFileName);

	DeleteClientByAccountNumber(vClients, AccountNumber);

	return 0;
}
*/

/// Problem #51 ( Update Client By AccountNumber )
// Write a program to Update client by AccountNumber :
/*
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

const string ClientFileName = "MyFile.txt";

struct stClients {
	string AccountNumber;
	int PinCode;
	string Name;
	string Phone;
	double AccountBalance;
	bool MarkForDelete = false;
};

string ReadString(string Message) {
	string S;
	cout << Message << endl;
	getline(cin >> ws, S);
	return S;
}

vector<string> SplitString(string Sentence, string delim) {
	vector<string> vString;
	short pos = 0;
	string sWord = "";

	while ((pos = Sentence.find(delim)) != std::string::npos) {
		sWord = Sentence.substr(0, pos);
		if (sWord != "") {
			vString.push_back(sWord);
		}
		Sentence.erase(0, pos + delim.length());
	}
	if (Sentence != "") {
		vString.push_back(Sentence);
	}
	return vString;
}

stClients ConvertLineToRecord(string Line, string Seperator) {
	vector<string> vString;
	stClients Client;

	vString = SplitString(Line, Seperator);

	Client.AccountNumber = vString[0];
	Client.PinCode = stoi(vString[1]);
	Client.Name = vString[2];
	Client.Phone = vString[3];
	Client.AccountBalance = stod(vString[4]);

	return Client;
}

string ConvertRecordToLine(stClients Client, string Seperator) {
	string Sentence = "";

	Sentence += Client.AccountNumber + Seperator;
	Sentence += to_string(Client.PinCode) + Seperator;
	Sentence += Client.Name + Seperator;
	Sentence += Client.Phone + Seperator;
	Sentence += to_string(Client.AccountBalance);

	return Sentence;
}

void FillFileWithRecords(vector<stClients>& vClients, string FileName) {
	fstream MyFile;
	string Line;

	MyFile.open(FileName, ios::out);
	if (MyFile.is_open()) {

		for (stClients& C : vClients) {

			if (!C.MarkForDelete) {
				Line = ConvertRecordToLine(C, "#//#");
				MyFile << Line << endl;
			}

		}

		MyFile.close();
	}
}

vector<stClients> LoadClientsDataFromFile(string FileName) {
	fstream MyFile;
	string Line;
	stClients Client;
	vector<stClients> vClients;


	MyFile.open(FileName, ios::in);

	if (MyFile.is_open()) {
		while (getline(MyFile, Line)) {
			Client = ConvertLineToRecord(Line, "#//#");
			vClients.push_back(Client);
		}
		MyFile.close();
	}

	return vClients;
}

bool SearchClientByAccountNumber(vector<stClients> vClients, string AccountNumber, stClients& Client) {
	for (stClients& C : vClients) {
		if (C.AccountNumber == AccountNumber) {
			Client = C;
			return true;
		}
	}
	return false;
}

stClients ReadUpdatedInformations(string AccountNumber) {
	stClients Client;
	

	cout << "\n\n";
	Client.AccountNumber = AccountNumber;
	Client.PinCode =  stoi(ReadString("Enter PinCode? "));
	Client.Name = ReadString("Enter Name? ");
	Client.Phone = ReadString("Enter Phone? ");
	Client.AccountBalance = stod(ReadString("Enter Account Balance? "));

	return Client;
}

void UpdateClient(vector<stClients>& vClient, string AccountNumber) {
	for (stClients& C : vClient) {
		if (C.AccountNumber == AccountNumber) {
			C = ReadUpdatedInformations(AccountNumber);
			break;
		}
	}
}

void PrintClientCard(stClients Client) {
	cout << "The following are the client details: \n";
	cout << "\nAccount Number: " << Client.AccountNumber;
	cout << "\nPin Code: " << Client.PinCode;
	cout << "\nName: " << Client.Name;
	cout << "\nPhone: " << Client.Phone;
	cout << "\nAccount Balance: " << Client.AccountBalance;
}

void UpdateClientByAccountNumber(vector<stClients>& vClients, string AccountNumber) {
	char Choice = 'N';
	stClients Client;

	if (SearchClientByAccountNumber(vClients, AccountNumber, Client)) {

		PrintClientCard(Client);

		cout << "\n\nAre you sure you want to Update this client? y/n ? ";
		cin >> Choice;
		if (tolower(Choice) == 'y') {

			UpdateClient(vClients, AccountNumber);

			FillFileWithRecords(vClients, ClientFileName);

			//Refresh Clients
			vClients = LoadClientsDataFromFile(ClientFileName);

			cout << "\n\n\nClient Updated Successfully. " << endl;
		}
	}

	else {
		cout << "Client With Account Number (" << AccountNumber << ") Not Found! " << endl;
	}
}

int main() {
	string AccountNumber = ReadString("Please enter Account Number? ");
	vector<stClients> vClients = LoadClientsDataFromFile(ClientFileName);

	UpdateClientByAccountNumber(vClients, AccountNumber);

	return 0;
}
*/

