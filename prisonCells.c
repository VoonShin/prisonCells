#include <stdio.h>
#include <stdlib.h>

void prisonCells(int cells[8], int day);

int main(int argc, char const *argv[])
{
	int n, cells[8];

	printf("Enter prison(only 1 or 0): \n");
	for(int i=0; i<8; ++i){		
		scanf("%d", &cells[i]);
	}
	scanf("%d", &n);			// input days

	prisonCells(cells, n);

	return 0;
}

void prisonCells(int cells[8], int day){
	int left =2 ,right=2, current;		// set left&right > 1 to distinguish from 1, 0
	int tmp[8];					// store the intermediate prison cells
	int a=0;

	while(a<8){					
		tmp[a] = cells[a];
		a++;
	}

	for (int i = 0; i < day; ++i)
	{
		// printf("Day %d: ", i+1);

		for (int j = 0; j < 8; ++j)
		{	

			if(j==0 || j==7){	
				// when it is the first or the end current become 0
				current = 0;
			}
			else {				
				// left, right and current cells
				left = cells[j-1];
				right = cells[j+1];
				current = tmp[j];
			}

			// when left&right == 0 or both ==1, then current = 1, else current =0
			if(((left==0 && right == 0) || (left == 1 && right ==1)))
			{
				current = 1;
			}
			else current = 0;

			// record the current state
			tmp[j] = current;
			tmp[0] = 0;
			tmp[7] = 0;
			// printf("%d, ", tmp[j]);
		}
		// printf("\n");

		// save the current cells state
		int b=0;	
		while(b<8){
			cells[b] = tmp[b];
			b++;
		}

	}
	cells[0] = 0;
	cells[7] = 0;

	// print the cells
	for (int i = 0; i < 8; ++i)
	{
		printf("%d, ", cells[i]);
	}
	printf("\nend\n");

}