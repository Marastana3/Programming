/*1. String compare Implement your own versions of strcmp and strncmp.*/

#include<stdio.h>
#include<string.h>

/*
	int mycmpstr(char *s1, char*s2){

	int i =0;
	while(s1[i] == s2[i] && s1[i]*s2[i]){
	i++;
	}
	return s1[i]-s2[i];
	}

	*/

int StringCompare(char* str1, char* str2) {

	if (strlen(str1) != strlen(str2)) {

		if (strlen(str1) > strlen(str2)) {
			return -1;
		}
		if (strlen(str1) < strlen(str2)) {
			return 1;
		}
	}
	else {
		for (int i = 0; i < strlen(str1); i++) {
			if (str1[i] > str2[i]) {
				return -1;
			}
			if (str1[i] < str2[i]) {
				return 1;
			}
		}

	}
	return 0;
}

int main(void) {
	
	char str1[] = "ana are mere si pere";
	char str2[] = "ana are mere si pere";
	StringCompare(str1, str2);
	return 0;
}
