#include <stdlib.h>
#include <stdio.h>

int main(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t r;

	while ((r = getline(&line, &len, stdin)) != -1)
		fputs(line, stderr);

	return EXIT_SUCCESS;
}
