#include <stdio.h>

char *mystrstr(char *haystack, char *needle);

int main() {

    char haystack[100] = "In CS102, Janina is getting an A.";
    char needle[10] = "Janina";
    char *ret;

    ret = mystrstr(haystack, needle);

    printf("The substring is: %s\n", ret);
    printf("The substring is: %c\n", *ret);
   
	return 0;
}


char *mystrstr(char *haystack, char *needle) {
	char *nstart = needle;

	while (*needle != '\0' && *haystack != '\0') {
		printf("%c %c\n", *haystack, *needle);
		if (*haystack == *needle) {
			haystack++;
			needle++;
		}
		else {
			needle = nstart;
			haystack++;
		}
	}

	return haystack - (needle - nstart);
}
