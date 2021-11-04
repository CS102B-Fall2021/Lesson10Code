#include <stdio.h>

struct Employee {
	char *name;
	char *company;
	char *title;
	char *education;
	float salary;
	int tenure;
};

struct Employee giveRaise(struct Employee e) {
	e.salary += 5000;
	return e;
}

struct Employee giveDemotion(struct Employee e) {
	e.salary /= 2;
	//e.title = "Grunt";
	printf("%s\n", e.title);
	printf("%c\n", *e.title);
	//char c = 'F';
	//*(e.title) = c;
	printf("%c\n", *e.title);
	return e;
}

int main() {
	struct Employee george = {
		"George", "Tesla", "BSE", "BE", 125000, 1
	};
	printf("%s makes $%f\n", george.name, george.salary);
	
	george = giveRaise(george);

	printf("%s makes $%f\n", george.name, george.salary);

	george = giveDemotion(george);
	printf("%s [%s] makes $%f\n", george.name, george.title, george.salary);

	struct Employee *georgePtr = &george;
	printf("%s\n", (*georgePtr).name); 
	printf("%s\n", georgePtr->name); 
	
	struct Employee teslaEmp[10];

	return 0;
}
