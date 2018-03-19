#include <iostream>
#include <string>
using namespace std;
int main()
{
 // Initialize the board to 0
   int q[8][8] = {0};
   // Start in the 1st row, 1st column, and place a queen there
   int r = 0, c = 0;
   q[r][c] = 1;

nextCol:
   // Move to the next column
   c++;
   if (c == 8)
      goto print;
   // Move to one before the first row
   r = -1;

nextRow:
   // Move to the next row
   r++;
   if (r == 8)
      goto backtrack;

   // If there is a queen in the same row (to the left), goto nextRow
   //for each square to the left of the current square
    for(int i = 1; (c - i) >= 0; i++)
        if (q[r][c - i] == 1)
         goto nextRow;

   // If there is a queen in the upper-left diagonal, goto nextRow
   for (int i = 1; (r -i) >= 0 && (c - i) >= 0; i++) // End the loop when you are above or left of the chessboard
      if(q[r - i][c - i] == 1)// (there is a queen i spots above and left of the current square)
         goto nextRow;

   // If there is a queen in the lower-left diagonal, goto nextRow
   for (int i = 1; r+i <= 7 && c - 1 >= 0; i++) // End the loop when you are below or left of the chessboard
      if(q[r + i][c - i] == 1) //(there is a queen i spots below and left of the current square)
         goto nextRow;

   // Place a queen in the current square (2D version only)
q[r][c] = 1;
   goto nextCol;

backtrack:
    c--;
    if(c == -1) return 0;
   // Move to the previous column
  //(you have moved to the left of the chessboard)
 //exit the program
 r = -1;
 // Find the square in the column with a queen in it and set r to the row number of that square
  while(q[r][c] != 1) r++;

    // Remove the queen from the current square
   q[r][c] = 0;
   goto nextRow;

print:
   static int numSolutions = 0;
   cout << "Solution #" << ++numSolutions << ":\n";
   // Use a nested loop to print the chessboard
   for(r = 0; r < 8; r++)
   {

       	for(c = 0; c < 8; c++)
       {
          cout << q[r][c];
           }
       	cout<<endl;
       }
   goto backtrack;
}
