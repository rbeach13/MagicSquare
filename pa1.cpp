/*cop3503 Magic Square: 

  Enter an odd number 3-15 into the command line after compiling
  and program will display magic square for that number and the sum of every column, 
  row, and diagonal.*/

//@uthor: ROBERT BEACH 

#include <iostream>
#include <vector>
using namespace std;


int main(){

	///giving instructions and requesting user input. 

	int numb;
	int row;
	int col;
	int sum;
	vector<int> diagonalSum(2);

	cout << "Enter the size of a Magic Square"; ///asking for size of magic square size
	cout << "(odd number between 3 and 15):";

	///taking user input
	
	cin >> numb;

	if(numb % 2 == 0 || numb < 3 || numb > 15){
		cout << "Sorry, that's not a valid input.";	//making sure input is odd	
		cin >> numb;
	}

	int array[numb][numb];				///initializing 2D array

	for(int i = 0; i < numb; i++){
		for(int j = 0; j < numb; j++){

			array[i][j] = 0;

		}
	}
	
		col = numb/2;			///setting the top middle square equal to 1
		row = 0;

		///creating wrap around effect for numbers that are outside square

		for(int input = 1; input <= numb*numb; input++){  
			array[row][col] = input;
			row--;
			col++;
			
			if(row < 0 && col == numb){		///numbers that fall of the top right corner return to the bottom right
				row++;
				col--;	
				row++;
			}

			else if(row < 0 ){			///numbers that fall off the top return to the bottom
				row = numb - 1;
			}

			else if(col == numb){		//numbers that fall off in blank spaces on the left return to the right 
				col = 0;
			}

			if(array[row][col] != 0){		///numbers that fall of the bottom return to top
				row++;
				col--;
				row++;
			}
		}

		///printing magic square alligning all outputs on the right to make square uniformed

		for(int i = 0; i < numb; i++){
			for(int j = 0; j < numb; j++){
				std::cout.width(3); std::cout << std::right << array[i][j] << " ";		//print square and include space between numbers so double digit numbers don't appear as one large number
			}
				cout << endl;
		}

		///calculating sum of the rows 

		cout << "The sum of all rows equals:       ";

		for(int i = 0; i < numb; i++){

			sum = 0;

			for(int j = 0; j < numb; j++){
				sum += array[i][j];
			}

			cout << sum << " ";
		}

		cout << endl;

		///calculating sums of the columns

		cout << "The sum of all columns equals:    ";

		for(int i = 0; i < numb; i++){

			sum = 0;

			for(int j = 0; j < numb; j++){
				sum += array[i][j];
			}

			cout << sum << " ";
		}

		cout << endl;

		///calculating the sums of the diagonals

		cout << "The sum of both diagonals equals: ";

		for(int i = 0; i < 2; i++){

			for(int j =0; j < numb; j++){
				diagonalSum[i] += array[j][j];
			}

			cout << diagonalSum[i] << " ";
		} 

		cout << endl;

	return 0;

}
