
/*!
 * library includes
 */
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

/*!
   \brief it is used for calculating other variable value..
 */
#define SECONDS_IN_SINGLE_MINUTE                                     60

/*!
   \brief It is used for updating .
 */
#define USER_INPUT_INTERVAL_TIME_IN_SECONDS                          5

/*!
   \brief It is used for updating .
 */
#define TIME_GIVEN_FOR_TAKING_USER_INPUTS_IN_MINUTES                 1

/*!
   \brief It is used for updating .
 */
#define TIME_GIVEN_FOR_TAKING_USER_INPUTS_IN_SECONDS                 (TIME_GIVEN_FOR_TAKING_USER_INPUTS_IN_MINUTES*SECONDS_IN_SINGLE_MINUTE)

/*!
   \brief It is used for updating .
 */
#define TOTAL_COUNT_OF_USER_INPUTS                                   (TIME_GIVEN_FOR_TAKING_USER_INPUTS_IN_SECONDS/USER_INPUT_INTERVAL_TIME_IN_SECONDS)

/* User input variable */
uint32_t uInputs[TOTAL_COUNT_OF_USER_INPUTS] = {0};
uint8_t uInputsBitPositions[TOTAL_COUNT_OF_USER_INPUTS] = {0}, uCount = 0;
time_t timetamp_v = 0, cur_time = 0;

/*!
   \brief       It is used for taking user inputs and do the time activities;
   \param[in]   uint32_t arr[]
   \param[in]   int length
   \return      true or false
 */
bool findDuplicateElements(uint32_t arr[], int length);

int main(){
	while(true){
		if((time(NULL) > USER_INPUT_INTERVAL_TIME_IN_SECONDS + timetamp_v) && (uCount < TOTAL_COUNT_OF_USER_INPUTS)){
			timetamp_v = time(NULL);
			uCount++;

			printf("Enter number : %d -> ", uCount);
			scanf("%d", &uInputs[uCount-1]);

			if(((uInputs[uCount-1]%2) == 1) && (!findDuplicateElements(uInputs, uCount))){
				printf("Input Accepted. \n");
				uInputsBitPositions[uCount-1] = 1;
			} else {
				printf("Input Not Accepted. \n");
				uInputsBitPositions[uCount-1] = 0;
			}
		}

		if(uCount == TOTAL_COUNT_OF_USER_INPUTS){
			break;
		}
	}

	printf("\n");
	printf(" ******************************** \n");

	for(int i = 0; i<uCount; i++ ){
		printf("uInputs             - %d is %d \n",i,uInputs[i]);
		printf("uInputsBitPositions - %d is %d \n",i,uInputsBitPositions[i]);
		printf("\n");
	}
	printf("............Program Done............");

	return 0;
}

bool findDuplicateElements(uint32_t arr[], int length){
	bool isDuplicateAvailable = false;

	for(int i = 0; i < length; i++) {
		for(int j = i + 1; j < length; j++) {
			if(arr[i] == arr[j]){
				isDuplicateAvailable = true;  // Set the flag to indicate a duplicate is found
				printf("Duplicate number entered. \n");
			}
		}
	}

	return isDuplicateAvailable;
}
