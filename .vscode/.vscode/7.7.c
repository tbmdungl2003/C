#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h> 
char *article[] = {"the", "a", "one", "some", "any"};
char *noun[] = {"boy", "girl", "dog", "town", "car"};
char *verb[] = {"drove", "jumped", "ran", "walked", "skipped"};
char *preposition[] = {"to", "from", "over", "under", "on"};

int random(int n) {
  return rand() % n;
}


int main() {
	srand(time(NULL));
  	for (int i = 0; i < 10; i++) {
    	char *a1 = article[random(5)];
  		char *n1 = noun[random(5)];
		char *v = verb[random(5)];
		char *a2 = article[random(5)];
		char *n2 = noun[random(5)];
		char *p = preposition[random(5)];
		printf("%c%s %s %s %s %s.\n", toupper(a1[0]), a1 + 1, n1, v, a2, n2, p);
	}


	return 0;
}

