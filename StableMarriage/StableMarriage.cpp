#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

void print(int q[]);
void backtrack(int &c);
bool ok(int q[], int c);

int main(int argc, char** argv) {
	int q[8] = {0}, c;
	bool from_backtrack = false;

	q[0] = 0;
	c = 1;

	while (true){	// While Loop 1
		while (c < 3){	// While Loop 2

			if(from_backtrack == false){
				q[c] = -1;
			}

			from_backtrack = false;

			while (q[c] < 3){	// while Loop 3

				q[c]++;

				if( q[c] == 3 ) {
					backtrack(c);
				}
				else if (ok(q,c) == true){
					break;
				}

			}	//While Loop 3 END

			c++;

		}   //While Loop 2 END

		print(q);
		backtrack(c);
		from_backtrack = true;

	} /// While Loop 1 End

	return 0;
}

void print(int q[]){

	cout << endl << "Solutions: "<< endl;
	for (int i = 0; i < 3; i++){
		cout<<" "<<i<<" "<<q[i]<<endl;
	}
}

bool ok(int q[], int c){

	int mp[3][3] = {	{0, 2, 1},
						{0, 2, 1},
						{1, 2, 0}};

	int wp[3][3] = {	{2, 1, 0},
						{0, 1, 2},
						{2, 0, 1}};


	for (int i = 0; i < c; i++){
		if (q[i] == q[c]){
			return false;
		}
	}

	for (int i = 0; i < c; i++){
 		if( ( mp[c][q[i]] < mp[c][q[c]] ) && ( wp[q[i]][c] < wp[q[i]][i]) ){
		 	return false;
		}
		if( ( wp[q[c]][i] < wp[q[c]][c] ) && ( mp[i][q[c]] < mp[i][q[i]] ) )
		{
			return false;
		}
	}

	return true;
}

void backtrack(int &c){
	c--;
	if (c == -1){
		exit(0);
	}
}
