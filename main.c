#define CTEST_MAIN
#include "ctest.h"
#include <stdio.h>
#include <string.h>

void passgen(int number, int special, int capital, int length, char *pass) {
	 int k = 0, j = 0;
	 for (j = 0; j < length; j++){
	 	 while (1) {
		 	   k = rand() % 4;
		 	   if (k == 0) break;
		 	   if (k == 1 && number == 1) break;
		 	   if (k == 2 && special == 1) break;
		 	   if (k == 3 && capital == 1) break;
			   }
	 	 switch (k) {
		 		case 0:
					 pass[j] = rand()%26 + 97;
					 break;
	 		    case 1:
					 pass[j] = rand()%10 + 48;
					 break;
			    case 2:
					 pass[j] = rand()%15 + 33;
					 break;
			    case 3:
					 pass[j] = rand()%26 + 65;
					 break;
					 }
			 }
	 }

// ÒÅÑÒ 13
CTEST(Does_your_password,) {
	// Given
	char pass[1000];
	passgen(0,0,0,1000, pass);
	int exp_result = 1, result = 1, i;
	// When
	for (i = 0; i < 1000; i++) {
		if (pass[i] == NULL ) {
			result = 0;
			break;
		}
	}
	// Then
	ASSERT_EQUAL(exp_result, result);
}
	 
// ÒÅÑÒ 12
CTEST(Check_for_extra_characters,_0_0_0) {
	// Given
	char pass[1000];
	passgen(0,0,0,1000, pass);
	int exp_result = 1, result = 1, i;
	// When
	for (i = 0; i < 1000; i++) {
		if (((pass[i] < 97) || (pass[i] > 122))) {
			result = 0;
			break;
		}
	}
	// Then
	ASSERT_EQUAL(exp_result, result);
}
	 
// ÒÅÑÒ 1
CTEST(Check_for_extra_characters,_1_1_1) {
	// Given
	char pass[1000];
	passgen(1,1,1,1000, pass);
	int exp_result = 1, result = 1, i;
	// When
	for (i = 0; i < 1000; i++) {
		if (((pass[i] > 57) || (pass[i] < 33)) && ((pass[i] < 97) || (pass[i] > 122))&& ((pass[i] < 65) || (pass[i] > 91))) {
			result = 0;
			break;
		}
	}
	// Then
	ASSERT_EQUAL(exp_result, result);
}

// ÒÅÑÒ 2
CTEST(Check_for_extra_characters,_1_0_0) {
	// Given
	char pass[1000];
	passgen(1,0,0,1000, pass);
	int exp_result = 1, result = 1, i;
	// When
	for (i = 0; i < 1000; i++) {
		if (((pass[i] < 97) || (pass[i] > 122))&&((pass[i] < 48) || (pass[i] > 57))) {
			result = 0;
			break;
		}
	}
	// Then
	ASSERT_EQUAL(exp_result, result);
}

// ÒÅÑÒ 3
CTEST(Check_for_extra_characters,_0_1_0) {
	// Given
	char pass[1000];
	passgen(0,1,0,1000, pass);
	int exp_result = 1, result = 1, i;
	// When
	for (i = 0; i < 1000; i++) {
		if (((pass[i] < 97) || (pass[i] > 122))&&((pass[i] < 33) || (pass[i] > 48))) {
			result = 0;
			break;
		}
	}
	// Then
	ASSERT_EQUAL(exp_result, result);
}

// ÒÅÑÒ 4
CTEST(Check_for_extra_characters,_0_0_1) {
	// Given
	char pass[1000];
	passgen(0,0,1,1000, pass);
	int exp_result = 1, result = 1, i;
	// When
	for (i = 0; i < 1000; i++) {
		if (((pass[i] < 97) || (pass[i] > 122))&&((pass[i] < 65) || (pass[i] > 91))) {
			result = 0;
			break;
		}
	}
	// Then
	ASSERT_EQUAL(exp_result, result);
}

// ÒÅÑÒ 5
CTEST(Check_for_extra_characters,_1_1_0) {
	// Given
	char pass[1000];
	passgen(1,1,0,1000, pass);
	int exp_result = 1, result = 1, i;
	// When
	for (i = 0; i < 1000; i++) {
		if (((pass[i] < 97) || (pass[i] > 122))&&((pass[i] < 33) || (pass[i] > 57))) {
			result = 0;
			break;
		}
	}
	// Then
	ASSERT_EQUAL(exp_result, result);
}

// ÒÅÑÒ 6
CTEST(Check_for_extra_characters,_1_0_1) {
	// Given
	char pass[1000];
	passgen(1,0,1,1000, pass);
	int exp_result = 1, result = 1, i;
	// When
	for (i = 0; i < 1000; i++) {
		if (((pass[i] < 97) || (pass[i] > 122))&&((pass[i] < 48) || (pass[i] > 57))&&((pass[i] < 65) || (pass[i] > 91))) {
			result = 0;
			break;
		}
	}
	// Then
	ASSERT_EQUAL(exp_result, result);
}

// ÒÅÑÒ 7
CTEST(Check_for_extra_characters,_0_1_1) {
	// Given
	char pass[1000];
	passgen(0,1,1,1000, pass);
	int exp_result = 1, result = 1, i;
	// When
	for (i = 0; i < 1000; i++) {
		if (((pass[i] < 97) || (pass[i] > 122))&&((pass[i] < 33) || (pass[i] > 48))&&((pass[i] < 65) || (pass[i] > 91))) {
			result = 0;
			break;
		}
	}
	// Then
	ASSERT_EQUAL(exp_result, result);
}

// ÒÅÑÒ 8
CTEST(Checking_on_the_values_of_the_area,_1_0_0) {
	// Given
	char pass[1000];
	passgen(1,0,0,1000, pass);
	int exp_result = 1, result = 0, i;
	// When
	for (i = 0; i < 1000; i++) {
		if (((pass[i] >= 48) || (pass[i] <= 57))) {
			result = 1;
			break;
		}
	}
	// Then
	ASSERT_EQUAL(exp_result, result);
}

// ÒÅÑÒ 9
CTEST(Checking_on_the_values_of_the_area,_0_1_0) {
	// Given
	char pass[1000];
	passgen(0,1,0,1000, pass);
	int exp_result = 1, result = 0, i;
	// When
	for (i = 0; i < 1000; i++) {
		if (((pass[i] >= 33) || (pass[i] <= 48))) {
			result = 1;
			break;
		}
	}
	// Then
	ASSERT_EQUAL(exp_result, result);
}

// ÒÅÑÒ 10
CTEST(Checking_on_the_values_of_the_area,_0_0_1) {
	// Given
	char pass[1000];
	passgen(0,0,1,1000, pass);
	int exp_result = 1, result = 0, i;
	// When
	for (i = 0; i < 1000; i++) {
		if (((pass[i] >= 65) || (pass[i] <= 91))) {
			result = 1;
			break;
		}
	}
	// Then
	ASSERT_EQUAL(exp_result, result);
}

// ÒÅÑÒ 11
CTEST(Checking_on_the_values_of_the_area,_1_1_1) {
	// Given
	char pass[1000];
	passgen(1,1,1,1000, pass);
	int exp_result = 1, result=0, result1 = 0, result2 = 0, result3 = 0, i;
	// When
	for (i = 0; i < 1000; i++) {
		if (((pass[i] >= 48) || (pass[i] <= 57))) {
			result1 = 1;
			break;
		}
	}
	for (i = 0; i < 1000; i++) {
		if (((pass[i] >= 33) || (pass[i] <= 48))) {
			result2 = 1;
			break;
		}
	}
	for (i = 0; i < 1000; i++) {
		if (((pass[i] >= 65) || (pass[i] <= 91))) {
			result3 = 1;
			break;
		}
	}
	if((result1=result2) && (result2=result3) && (result1=result3))
		result=1;
	// Then
	ASSERT_EQUAL(exp_result, result);
}

int main(int argc, const char** argv) {
    return ctest_main(argc, argv);
}
