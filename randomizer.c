#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <string.h>

#define ITERATIONS 268435456
#define BUFF_SIZE 32

/**
  *
  * @version: 1.0.0
  * @date: 2019/12/11
  * @author: Gabriele Lavorato
  * This program randomly takes a decision between two given options.
  */

/**
* Generates a pseudorandom number between 0 and the value of options_num.
* @param options_num: the upper bound value of the drawing
* @returns the generated number
*/
static int randomizer(int options_num);

int main(int argc, char *argv[])
{
	int options_num = 0;
	if (argc == 1) {
		printf("Usage: insert the number of options as inline argument.\n");
		exit(EXIT_FAILURE);
	} else if (argc == 2 && atoi(argv[1]) > 0) {

		options_num = atoi(argv[1]);
		char options[options_num][BUFF_SIZE];

		// Fetching the options from the user
		for (int i = 0, j = i; i < options_num; i++) {
			printf("Option %d: ", ++j);
			fgets(options[i], BUFF_SIZE, stdin);
			strtok(options[i], "\n");
		}

		printf("Computing...\n");

		int results[options_num];
		int choice = 0, i = 0, index_max = 0;

		// Setting every option to zero
		for (i = 0; i < options_num; i++) {
			results[i] = 0;
		}

		// Doing the drawings ITERATIONS times
		for (i = 0; i < ITERATIONS; i++) {
			choice = (randomizer(options_num));
			results[choice]++;
		}

		printf("I ran this drawing %d times.\n", i);

		for (i = 0; i < options_num; i++) {
			printf("%s won %d times.\n", options[i], results[i]);
			if (results[i] > results[index_max]) {
				index_max = i;
			}
		}

		printf("So I'd say %s won.", options[index_max]);
		exit(EXIT_SUCCESS);
		
	} else {
		printf("ERROR: Too many arguments or invalid argument in input.\n");
		exit(EXIT_FAILURE);
	}
}

static int randomizer(int max_value) {
	srand(time(NULL) ^ (getpid() << 16));
	int r = rand() % max_value;
	return r;
}