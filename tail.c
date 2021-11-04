#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINE 1000

int mygetline(char s[], int lim);

int main(int argc, char *argv[]) {

	int n;
	if (argc == 1) {
		n = 10;
	}
	else if (argc == 2) {
		n = -1*atoi(argv[1]);
	} else {
		printf("tail [-n]\n");
		return 0;
	}

	printf("n=%d\n", n);

	char *lastLinesPtr[n];

	for (int i=0; i<n; i++) {
		lastLinesPtr[i] = NULL;
	}

	int last = 0;
	char line[MAXLINE];
	while (mygetline(line, MAXLINE) > 0) {
		char *copyOfLine = (char *) malloc(strlen(line)+1);
		strcpy(copyOfLine, line);
		if (last < n) {
			lastLinesPtr[last] = copyOfLine;
			last++;
		} else {
			for(int i=0; i<n-1; i++) {
				lastLinesPtr[i] = lastLinesPtr[i+1];
			}
			lastLinesPtr[last-1] = copyOfLine;
		}

	}

	for (int i=0; i<n; i++) {
		printf("%s", lastLinesPtr[i]);
	}

	return 0;
}

int mygetline(char s[], int lim)
{
    int c, i;
    i = 0;

    while(--lim > 0 && (c=getchar()) != EOF && c != '\n') {
        s[i++] = c;
	}

    if (c == '\n') {
        s[i++] = c;
	}

    s[i] = '\0';
    return i;
}
