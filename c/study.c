#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define O_TMPFILE (__O_TMPFILE | O_DIRECTORY)

struct question {
	char query[4096];
	char answer[4096];
};

struct test {
	struct question questions[500];
	int size;
};

struct test tests[50];
int n;

void menu() {
	printf("[1] Create New Test\n");
	printf("[2] Take Test\n");
}

int read_stdin() {
	int nchar;
	int newfd;

	newfd = open("/tmp", O_TMPFILE | O_RDWR, 0666);
	char buffer[1];
	while((nchar = read(0, buffer, 1)) > 0) {
		nchar = write(newfd, buffer, nchar);
		if(buffer[0] == '\n') {
			break;
		}
	}

	printf("buffer in function is: %s\n", buffer);

	return newfd;
}

void create() {
	char filename[50];
	printf("What is the name of the file?: \n");
	scanf("%s", filename);
	printf("Filename is: %s\n", filename);

	FILE * fp;
	fp = fopen(filename, "w");
	char buffer[4096];


	//need to keep track of size of test
	struct test t;
	struct question q;
	int num;

	while(1) {
		printf("What is the question?\n");
		//scanf("%s", buffer);
		//getline(&buffer, 4096, stdin);
		int fd = read_stdin();
		//q.query = buffer;
		printf("fd: %d\n", fd);
		int nchar;
		while( (nchar = read(fd, buffer, 4096)) > 0) {
			nchar = write(1, buffer, nchar);
		}
		printf("Question is: %s\n", buffer);
		strcpy(q.query, buffer);
		printf("Question is: %s\n", buffer);
		printf("Question is: %s\n", q.query);
		strncpy(buffer, "", 4096);

		printf("Question is: %s\n", q.query);
		printf("What is the answer?\n");
		fd = read_stdin();
		//q.answer = buffer;
		strcpy(q.answer, buffer);
		strncpy(buffer, "", 4096);

		t.questions[t.size++] = q;
				
	}

	tests[n++] = t;
	fclose(fp); 
	
}

int main() {
	menu();
	
	int c;
	printf("Select a command: \n");
	scanf("%d", &c);
	
	switch(c) {
		case(1): 
			create();
			break;
		default:
			printf("Exiting program!\n");
	}

	return 0;

}