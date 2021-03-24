#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define true 1
#define false 0


char* tail(char *string){
	return string+1;
}


int min(int list[], int len){
	int cm = list[0];
	for (int i = 1; i<len;i++){
		cm = cm<list[i] ? cm : list[i];
	}
	return cm;
}

int levenshtein_(char *string1, int len1, char *string2, int len2){
	if (len2 == 0){
		return len1;
	} else if (len1 ==0){
		return len2;
	} else if (string1[0]==string2[0]){
		return levenshtein_(tail(string1),len1-1,tail(string2),len2-1);
	} else{
		int list[] = {levenshtein_(tail(string1),len1-1,string2,len2),0,0};
		list[1]=levenshtein_(string1,len1,tail(string2),len2-1);
		list[2]=levenshtein_(tail(string1),len1-1,tail(string2),len2-1);
		return 1+min(list,3);
	}
}

int levenshtein(char *string1, char *string2){
	return levenshtein_(string1,strlen(string1),string2,strlen(string2));
}

int main(int argc, char *argv[]){
	char string[100];
	if (argc<3){
		int len = strlen(argv[1]);
		printf("%d",len);
		return 0;
	}
	printf("%d",levenshtein(argv[1],argv[2]));
	return 0;
}



