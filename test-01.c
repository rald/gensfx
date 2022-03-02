#include <stdio.h>
 int
main () {
	int osc = 0;
	int melody[8] = { 21, 16, 19, 21, 19, 16, 14, 16 };
	for (int step = 0;; step = (step + 1) % 8) {
		int increment = melody[step];
		for (int t = 0; t < 2000; t++) {
			osc = osc + increment;
			putchar (osc);
		} 
	} 
} 
