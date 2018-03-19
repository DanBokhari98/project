#include <cstdlib>
#include <iostream>
using namespace std;

	void sort(int num[], int size ){
		bool flag = true; // set flag to true to start first pass
		int temp;
		for(int i = 1; (i <= size) && flag; i++)
		{
			flag = false;
			for (int j=0; j < (size -1); j++)
			{
				if (num[j+1]>num[j])
				{
					temp = num[j]; // swap elements
					num[j] = num[j+1];
					num[j+1] = temp;
					flag = true; // indicates that a swap occurred.
				}
			}
		}
 return;
}
int values[] = { 40, 10, 100, 90, 20, 25 };
int main()
{
 sort (values, 6 );
 for (int n=0; n<6; n++)
 cout<<values[n]<<" ";
 cout<<endl;
 system("PAUSE");
 return EXIT_SUCCESS;
}
