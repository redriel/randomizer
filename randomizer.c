#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <string.h>

/* Higly suggested not to increase this constant too much, 
as numbers tend to group together with great values (billions) */
#define ITERATIONS 26840
#define BUFF_SIZE 32
/* #define PBSTR "####################"
#define PBWIDTH 20 */

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
	srand(time(NULL));
	int options_num = 0; //progressDividend = PBWIDTH + 1
	//double percentage = 0;
	if (argc == 1) {
		printf("Usage: insert the number of options as inline argument.\n");
		exit(EXIT_FAILURE);
	} else if (argc == 2 && atoi(argv[1]) > 0) {

		options_num = atoi(argv[1]);
		char options[options_num][BUFF_SIZE];
		float options_percentage[options_num];

		// Fetching the options from the user
		for (int i = 0, j = i; i < options_num; i++) {
			printf("Option %d: ", ++j);
			fflush(stdout);
			fgets(options[i], BUFF_SIZE, stdin);
			strtok(options[i], "\n");
		}

		printf("Computing...\n");

		int results[options_num];
		int choice = 0, i = 0, k = 0, index_max = 0, temp = 0;

		// Setting every option to zero
		memset(results, 0, sizeof results);

		// Doing the drawings ITERATIONS times
		for (i = 0; i < ITERATIONS; i++) {
			choice = (randomizer(options_num));
			results[choice]++;
			
			/* Please read the comment at the end about the printProgress function */
			/* if(i >= ITERATIONS / progressDividend) {
				progressDividend--;
				percentage = percentage + 5;
				printProgress(percentage);
			} */
		}

		printf("I ran this drawing %d times.\n", ITERATIONS);
		
		for (i = 0; i < options_num; i++) {
			options_percentage[i] = ((float)results[i] * 100) / (float)ITERATIONS;
		}

		for (i = 0; i < options_num; i++) {
			printf("%s was drawn %0.4f%% of the time. ", options[i], options_percentage[i]);
			printf("(Precisely, %d times).\n", results[i], ITERATIONS);
			if (results[i] > results[index_max]) {
				index_max = i;
			}
		}

		printf("The winner is %s.", options[index_max]);
		exit(EXIT_SUCCESS);
		
	} else {
		printf("ERROR: Too many arguments or invalid argument in input.\n");
		exit(EXIT_FAILURE);
	}
}

static int randomizer(int max_value) {
	int r = rand() % max_value;
	return r;
}

/* This was a nice graphic function to display a progress bar.
As computation times were decreased, it serves no use no more,
still could be useful in the future. */

/* void printProgress(double percentage); */

/* void printProgress(double percentage) {
    int lpad = (int) (percentage * PBWIDTH)/100;
    int rpad = PBWIDTH - lpad;
    printf("\r[%.*s%*s]", lpad, PBSTR, rpad, "");
    fflush(stdout);
} */