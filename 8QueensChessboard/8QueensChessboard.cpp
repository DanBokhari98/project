#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

typedef char box[5][7];
box blackbox, whitebox, *board[8][8], whitequeen, blackqueen;

void print(int q[], box *board[8][8]);
void backtrack(int &col);
bool ok(int q[], int col);

int main(int argc, char** argv) {

	//fill in blackbox and whitebox
	for(int i = 0; i < 5; i++)
	{
		for(int j = 0; j < 7; j++)
		{
			whitebox[i][j] = ' ';
			blackbox[i][j] = char(219);
		}
	}

	//fill board with pointers to blackbox and whitebox in alternate positions
	for(int i = 0; i < 8; i++)
	{
		for(int j = 0; j < 8; j++)
		{
			if((i + j) % 2 == 1)
			{
				board[i][j] = &blackbox;
			}
			else
			{
				board[i][j] = &whitebox;
			}
		}
	}


	for (int w = 0; w < 7; w++)
	{

		whitequeen[0][w] = char(219);
		whitequeen[4][w] = char(219);

		if (w % 2 == 0)
		{
			whitequeen[1][w] = char(219);
			whitequeen[2][w] = char(219);
		}
		else
		{
			whitequeen[1][w] = ' ';
			whitequeen[2][w] = ' ';
		}

		if (w == 0 || w == 6)
		{
			whitequeen[3][w] = char(219);
		}
		else
		{
			whitequeen[3][w] = ' ';
		}
	}


	for (int w = 0; w < 7; w++){
		blackqueen[0][w] =  ' ';
		blackqueen[4][w] =  ' ';
		if (w % 2 != 0){
			blackqueen[1][w] = char(219);
			blackqueen[2][w] = char(219);
		}
		else{
			blackqueen[1][w] = ' ';
			blackqueen[2][w] = ' ';
		}
		if (w != 0 && w != 6){
			blackqueen[3][w] = char(219);
		}
		else{
			blackqueen[3][w] = ' ';
		}
	}
	int q[8] = {0}, c;
	bool from_backtrack = false;
	q[0] = 0;
	c = 1;
	while (true){
		while (c < 8){
			if(from_backtrack == false){
				q[c] = -1;
			}
			from_backtrack = false;
			while (q[c] < 8){
			q[c]++;
			if( q[c] == 8 ) {
				backtrack(c);
				}
				else if (ok(q,c) == true){
				break;
				}
			}
			c++;
		}
		print(q, board);
		backtrack(c);
		from_backtrack = true;
	}
	return 0;
}
bool ok(int q[], int col){
	for(int i = 0; i < col; i++) {
		if(q[i] == q[col] || (col - i) == abs(q[col] - q[i])){
			return false;
		}
	}
	return true;
}
void backtrack(int &col){
	col--;
	if (col == -1){
		exit(0);
	}
}
void print(int q[],	box *board[8][8]){
	static int count = 0;
	cout << endl << ++count << endl << endl;
	for (int z = 0; z < 8; z++){
		if ((z + q[z]) % 2 == 0){
			board[z][q[z]] = &blackqueen;
		}
		else{
			board[z][q[z]] = &whitequeen;
		}
	}
	// print the board via the pointers in array board
	// first print upper border
	cout << " ";
	for(int i = 0; i < 7*8; i++){
		cout << '_';
	}
	cout << endl;
	// now print the board
	for(int i = 0; i < 8; i++){
		for(int k = 0; k < 5; k++){
			cout << " " << char(179); //print left border
			for(int j = 0; j < 8; j++){
				for(int l = 0; l < 7; l++){
					cout << (*board[i][j])[k][l];
				}
			}
			cout << char(179) << endl; // at end of line print bar and then newline
		}
	}

	//before exiting print lower border
	cout << " ";
	for(int i = 0; i < 7*8; i++){
		cout << char(196);
	}
	cout << endl;
	//reset board
	for(int i = 0; i < 8; i++){
		for(int j = 0; j < 8; j++){
			if((i + j) % 2 == 0){
				board[i][j] = &whitebox;
			}
			else{
				board[i][j] = &blackbox;
			}
		}
	}
}
