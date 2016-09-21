//Created by Alex Schrepfer
//CS151, University of Hawaii-Hilo
//April 5th, 2001
#include "knight.h"
Knights::Knights(int size) {
//	pre:
//		takes an int for the size of the board
//
//	post:
//		initializes the board to 0, attempts and board_size

	board_size = size;
	attempts = 0;

	for (int y = 0; y < board_size; y++) {
		for (int x = 0; x < board_size; x++) {
			used[x][y] = 0;
		}
	}
}

int Knights::size() const {
//	pre:
//		takes no paramets
//
//	post:
//		returns the size of the board

	return board_size;
}

bool Knights::valid(int x, int y) const {
//	pre:
//		takes the x and y coordinates for a square
//		on the board
//
//	post:
//		returns true if the move isn't taken and
//		is not off the board

	if ((y > board_size-1) || (x > board_size-1) ||
		(x < 0) || (y < 0) || (used[x][y] > 0))
		return false;
	else
		return true;
}

void Knights::insert(int x, int y, int move) {
//	pre:
//		takes the x and y coordinates as well as the
//		move number as paramets
//
//	post:
//		sets the x and y coordinate the move number
//	

	used[x][y] = move;
}

void Knights::remove(int x, int y) {
//	pre:
//		takes the x and y coordinates as a parameter
//
//	post:
//		sets the value of the current block to 0 (unused)

	used[x][y] = 0;
}

void Knights::print() const {
//	pre:
//		takes no parameters
//
//	post:
//		prints out the current board configuration

	for (int i = 0; i < board_size+1; i++)
		cout << "----";
	cout << endl << endl;

	for (int i = 0; i < board_size; i++) {
		for (int j = 0; j < board_size; j++) {
			cout.width(4);
			cout << used[i][j];
		}
		cout << endl << endl;
	}

	for (int i = 0; i < board_size+1; i++)
		cout << "----";
	cout << endl;

}
