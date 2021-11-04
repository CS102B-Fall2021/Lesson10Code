#include <stdio.h>

struct point {
	int x;
	int y;
};
void f();

int main() {

	struct point pt = {1, 2};
	printf("%d %d", pt.x, pt.y);
	return 0;
}

void f() {
	struct point fpt;
}
