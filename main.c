// lolcat : c version, fullcolor text

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void print_in_color(const char *str){
	int i = 0;
	for (const char *p = str; *p ; p++, i++) {
		double r = (sin(i * 0.1) / 2) + 0.5;
		double g = (sin(i * 0.1 + 2) / 2) + 0.5;
		double b = (sin(i * 0.1 + 4) / 2) + 0.5;
		int red = (int)(r * 255);
		int green = (int)(g * 255);
		int blue = (int)(b * 255);
		printf("\033[38;2;%d;%d;%dm%c\033[0m", red, green, blue, *p);
	}
}

int main(int argc, char *argv[]) {

	if (argc < 2){
		char *buffer = NULL;
		size_t len = 0;
		ssize_t read = 0;
		while ((read = getline(&buffer, &len, stdin)) != -1) {
			print_in_color(buffer);
		}
		free(buffer);
		return 0;
	}
	print_in_color(argv[1]);
	printf("\n");
	return 0;
}
