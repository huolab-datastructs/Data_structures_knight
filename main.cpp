//Created by Alex Schrepfer
//CS151, University of Hawaii-Hilo
//April 5th, 2001
//
//	This program will start a knight at the given point
// and try all possible solutions so that the knight
// will cover all the spots on the grid w/o going over
//	a space twice..

#include <iostream>
#include "knight.h"

//these are arrays of possible moves for the piece
//there are eight possible moves so array of 8
const int x_move[8] = {-2,-2,-1,-1,1,1,2,2};
const int y_move[8] = {1,-1,2,-2,2,-2,1,-1};


int possible_moves(Knights &board, int x, int y) {
//	pre:
//		takes board as call by reference, x and y coordinate
//		for where the piece is currently located
//
//	post:
//		the function checks for all possible moves the piece
//		can make and returns the total number of moves, returns 0
//		if the move where your asking is invalid

	int count = 0;
	if (board.valid(x, y)) {
		for (int i = 0; i < 8; i++) {
			if (board.valid(x+x_move[i], y+y_move[i]))
				count++;
		}
	}

	return count;
}

bool solve_from(Knights &board, int x, int y, int move) {
//	pre:
//		takes board as call by reference, x and y coordinate
//		for where the piece is currently located and the move#
//
//	post:
//		the function checks for all possible moves the piece
//		can make and returns either true or false depending if
//		it successfully made it to the end or not


	//inserts piece with the number
	board.insert(x, y, move);
	board.attempts++;

	//since the board size is just the length of one side
	//we take the square of it to find all blocks
	//if the moves cover all the lots, it's done
	if (move == board.size()*board.size()) {
		board.print();
		return true;
	}
	else {

		int i, j, n, temp1, temp2, order[8] = {-1,-1,-1,-1,-1,-1,-1,-1};

		//scans through all of the possible ways the knight can move
		for (i = 0; i < 8; i++)
			//scans through the array which holds the order of moves
			//goes as long as it's a valid move and less then array number
			for (j = 0; j < 8 && board.valid(x+x_move[i], y+y_move[i]); j++)
				//if the order number i -1, it means that nothing is there and proceeds
				//also proceeds if the current piece has less moves to make then the nth item in list
				if ((order[j] == -1) || (possible_moves(board, x+x_move[i], y+y_move[i]) < possible_moves(board, x+x_move[order[j]], y+y_move[order[j]]))) {
					//inserts the nth item in the list at the spot and moves all items
					//after it one move to the right
					temp1 = i;
					for (n = j; n < 8; n++) {
						temp2 = order[n];
						order[n] = temp1;
						temp1 = temp2;
					}
					break;
				}

		//loops though both of the arrays and tries to do all
		//of the possible moves of the knight.. also checks
		//for legal and illegal moves (off screen/knight already there)
		//and it makes sure that the space in order != -1 because
		//-1 means that there is no move there
		for (i = 0; i < 8 && order[i] != -1; i++) {
			if (board.valid(x+x_move[order[i]], y+y_move[order[i]]))
				if (solve_from(board, x+x_move[order[i]], y+y_move[order[i]], move+1))
					return true;
		}

		//removes the piece, since if it comes here it means it was a bad move
		board.remove(x, y);
		return false;
	}
}

void main() {

	cout << "Welcome to the knight algorithym..." << endl
		  << "   created by Alex Schrepfer" << endl << endl;

	int board_size, x, y;

	do {
		cout << "What is the size of the board [1 to " << max_board << "]? ";
		cin >> board_size;
	} while ((board_size < 1) || (board_size > max_board));

	cout << endl
		  << "    0 1 2 3 .." << endl
		  << "  0 x x x x   " << endl
		  << "  1 x x x x   " << endl
		  << "  2 x x x x   " << endl
		  << "  3 x x x x   " << endl
		  << "  .           " << endl
		  << endl;

	do {
		cout << "Start on which Row [1 to " << board_size << "]? ";
		cin >> x;
	} while ((x < 1) || (x > board_size));
	//fixes the program to work in computer terms (start at 0)
	x--;

	do {
		cout << "Start on which Col [1 to " << board_size << "]? ";
		cin >> y;
	} while ((y < 1) || (y > board_size));
	//fixes the program to work in computer terms (start at 0)
	y--;

	//initialize the board with the given size
	Knights board(board_size);

	//begins the functions
	if (!solve_from(board, x, y, 1))
		cout << "No solutions were found, completed " << board.attempts << " attempts!" << endl;
	else
		cout << "Completed in " << board.attempts << " attempts!" << endl;

}