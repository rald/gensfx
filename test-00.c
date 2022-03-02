#include <stdio.h>

int main() {
	for (int t=0, osc = 0; t < 8000; t++, osc = osc + 14) {
	  putchar(osc);
	}
}
