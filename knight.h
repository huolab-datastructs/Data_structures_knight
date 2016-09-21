//Created by Alex Schrepfer
//CS151, University of Hawaii-Hilo
//April 5th, 2001
#include <iostream>
using namespace std;
const int max_board = 18;

class Knights {
public:
	Knights(int size);
	int size() const;
	bool valid(int x, int y) const;
	void insert(int x, int y, int move);
	void remove(int x, int y);
	void print() const;
	int attempts;

private:
	int count;
	int board_size;
	int used[max_board][max_board];
};
