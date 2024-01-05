#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "ferryload.h"

int main()
{	
	//opening input and output files
	FILE* input = fopen("input.txt", "r");
	if (input == NULL)
	{
		LOG_CRITICAL("Error opening file\n");
		exit(1);
	}
	FILE* output = fopen("output.txt", "w");
	if (output == NULL)
	{
		LOG_CRITICAL("Error opening file\n");
		exit(1);
	}

	//Enter the number of test cases
	int num_test_case = 0;
	fscanf(input, "%d", &num_test_case);
	//scanf("%d", &num_test_case);

	int len_ferry = 0, num_of_car = 0, len_car = 0, current_len_left = 0, current_len_right = 0;
	int i,y,z, result = 0;
	char side = 'a', position = 'l';
	char side_string[20];
	for (i = 0; i < num_test_case; i++)
	{
		//Enter the test case 
		fscanf(input,"%d %d", &len_ferry, &num_of_car);
		//scanf("%d %d", &len_ferry, &num_of_car);

		QUEUE hQueueLeft = queue_init_default();
		current_len_left = 0;

		QUEUE hQueueRight = queue_init_default();
		current_len_right = 0;

		for (y = 0; y < num_of_car; y++)
		{
			//Enter the length of car and its side
			fscanf(input,"%d %s", &len_car, &side_string);
			side = side_string[0]; //after read the whole string, we just need the first character
			//scanf("%d %c", &len_car, &side); - this is to enter manually
			//clear_keyboard_buffer();
			/*
			The clear_keyboard_buffer cannot prevent in case of reading a file. If we use fscanf to read
			a character, then the next thing it will read is the remaining character of the string. That
			is why we need to read a whole string and then use only the first character, because comparing 
			two string is more expensive than comparing two characters.
			*/
			if (side == 'l')
			{
				current_len_left += len_car;
				if (current_len_left >= len_ferry*100)
				{
					while(queue_is_empty(hQueueLeft) == FALSE)
						queue_dequeue(hQueueLeft);
					result++; //from left to right
					if (queue_is_empty(hQueueRight) == FALSE)
					{
						while (queue_is_empty(hQueueRight) == FALSE)
							queue_dequeue(hQueueRight);
					}
					result++; //from right to left
					queue_enqueue(hQueueLeft, len_car);
					current_len_left = len_car; //set it to the length of the car that cant fit in
				}
				else
					queue_enqueue(hQueueLeft, len_car);
			}
			else
			{
				if (y == 0 && position == 'l') //for the first car on the right
					result++;
				current_len_right += len_car;
				if (current_len_right >= len_ferry*100)
				{
					while(queue_is_empty(hQueueRight) == FALSE)
						queue_dequeue(hQueueRight);
					result++; //from right to left
					if (queue_is_empty(hQueueLeft) == FALSE)
					{
						while (queue_is_empty(hQueueLeft) == FALSE)
							queue_dequeue(hQueueLeft);
					}
					result++; //from left to right
					queue_enqueue(hQueueRight, len_car);
					current_len_right = len_car;
				}
				else
					queue_enqueue(hQueueRight, len_car);
			}
		}
		if (queue_is_empty(hQueueLeft) == FALSE)
			result++;
		if (queue_is_empty(hQueueRight) == FALSE)
			result++;

		fprintf(output, "%d\n", result);
		//printf("%d\n", result); //- this is to print manually

		queue_destroy(&hQueueLeft);
		queue_destroy(&hQueueRight);
		result = 0;
	}
	fclose(input);
	fclose(output);
	return 0;
}
