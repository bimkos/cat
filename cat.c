#include <stdio.h>
#include <inttypes.h>
#include <string.h>

void cat(char name[1024]) {
	FILE *file;
	unsigned char buffer[1024]; // Big file size protection 
	size_t bytesRead = 0;
	memset(buffer, 0, sizeof(buffer));
	
	file = fopen(name, "rb");
	if (file != NULL) {
		while ((bytesRead = fread(buffer, 1, sizeof(buffer), file)) > 0) {
			printf("%s", buffer);
			memset(buffer, 0, sizeof(buffer));
		}
	}
}

int main(int argc, char *argv[]) {
	if (argc < 2 || argc > 254) {
		printf("Usage: cat [file1] [file2] ...");
		return 0;
	}
	for(uint8_t i = 1; i < argc; i++) {
		cat(argv[i]);
	}
	return 0;
}
