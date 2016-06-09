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
// ÒÅÑÒ 1
CTEST(number_suite, number_test) {
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
CTEST(number_suite2, number_test2) {
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
CTEST(number_suite3, number_test3) {
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
CTEST(number_suite4, number_test4) {
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
CTEST(number_suite5, number_test5) {
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
CTEST(number_suite6, number_test6) {
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
CTEST(number_suite7, number_test7) {
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
CTEST(number_suite8, number_test8) {
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
CTEST(number_suite9, number_test9) {
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
CTEST(number_suite10, number_test10) {
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
CTEST(number_suite11, number_test11) {
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
