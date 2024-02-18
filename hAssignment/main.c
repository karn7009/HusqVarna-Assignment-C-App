
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
uint8_t uInputsBitPositions[TOTAL_COUNT_OF_USER_INPUTS] = {0};
time_t timetamp_v = 0;

/*!
   \brief   It is used for taking user inputs and do the time activities;
   \param   no params
   \return  no values
 */
void takeUserInputs();

/*!
   \brief       It is used for taking user inputs and do the time activities;
   \param[in]   uint32_t arr[]
   \param[in]   int length
   \return      true or false
 */
bool findDuplicateElements(uint32_t arr[], int length);

int main(){
	while(true){
		if(time(NULL) > USER_INPUT_INTERVAL_TIME_IN_SECONDS + timetamp_v){
			timetamp_v = time(NULL);
			printf("Seconds :: %d \n", time);
		}
	}

	return 0;
}

void takeUserInputs(){
	for(auto i=0; i<TOTAL_COUNT_OF_USER_INPUTS; i++){

		if(time(NULL) > USER_INPUT_INTERVAL_TIME_IN_SECONDS + timetamp_v){
			timetamp_v = time(NULL);

			printf("Enter number : %d -> ", i+1);
			scanf("%d", &uInputs[i]);

			while(true){
				if(((uInputs[i]%2) == 1) && (!findDuplicateElements(uInputs, i+1))){
					printf("Input Accepted : %d \n", uInputs[i]);
					uInputsBitPositions[i] = 1;
					break;
				} else{
					printf("Input Not Accepted. Please enter only odd integer values. Restart the App \n");
					return;
				}
			}
		}
	}
}

bool findDuplicateElements(uint32_t arr[], int length){
	bool isDuplicateAvailable = false;
	uint32_t userInput = arr[length-1];

	for (int i = 0; i < length-1; i++) {
		if ((userInput == arr[i]) && (length > 1)) {
			isDuplicateAvailable = true;  // Set the flag to indicate a duplicate is found
			printf("Duplicate number entered. Program will stop.\n");
			break;
		}
	}
	return isDuplicateAvailable;
}
