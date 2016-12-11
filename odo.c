// Odometer-style counter. ADS, December 2016.
// License: If it's useful to you, help yourself. 

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	if(argc != 2) 																//argument parser
	{
		printf("Use: odo [number of digits in odometer]\n");
		return 0;
	}
	
	char odometer[strtol(argv[1],NULL,10)];									//init key array of length supplied by argv
		
					 						
	int arrLength = (sizeof(odometer)/sizeof(odometer[0])-1);					//Dynamically assign length of array.
	int arrPos = arrLength-1;													//init variable for array index
	
	for(int i=0;i<arrLength;i++) 												//loop to populate array with 0s
	{
		odometer[i]=48;
	}
	
	printf("Count: %s arrLength: %d arrPos:%d argv: %s\n ",odometer,arrLength,arrPos,argv[1]);						
	
	while(odometer[0]<=57)
	{
	printf("%s\n",odometer);
	
	
	if(odometer[arrPos] < 57)													//if value at index is less than 9, increment.
		{	
			odometer[arrPos]++;
					
		}
	
	else
		{	
			while(odometer[arrPos] == 57)							//if value at index is 9...
			{

				arrPos--;											//move index back until we hit a number that's less than 9.
			}
			
			odometer[arrPos]++;									//increment value at that index.
			
			for(int i=arrPos;i<arrLength;i++)						//loop to move back through the array, zeroing the values we confirmed as 9s in the while loop
			{
				arrPos++;
				odometer[arrPos] = 48;
			}
		}
	}
}	
		
		
			
			
		
		


	




