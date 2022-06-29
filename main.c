#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include "get_next_line.h"
#include "get_next_line_utils.c"
#include "get_next_line.c"

int main(void)
{
	int fd;
	char *line;

	fd = open("alphabet", O_RDONLY);
	line = get_next_line(fd);
	printf("%s\n\n", line);
	free(line);
	line = get_next_line(fd);
	printf("%s\n\n", line);
	free(line);
	line = get_next_line(fd);
	printf("%s\n\n", line);
	free(line);
	line = get_next_line(fd);
	printf("%s\n\n", line);
	free(line);
	line = get_next_line(fd);
	printf("%s\n\n", line);
	free(line);
	line = get_next_line(fd);
	printf("%s\n\n", line);
	free(line);
	line = get_next_line(fd);
	printf("%s\n\n", line);
	free(line);
	line = get_next_line(fd);
	printf("%s\n\n", line);
	free(line);
	line = get_next_line(fd);
	printf("%s\n\n", line);
	free(line);
	line = get_next_line(fd);
	printf("%s\n\n", line);
	free(line);
	line = get_next_line(fd);
	printf("%s\n\n", line);
	free(line);
	line = get_next_line(fd);
	printf("%s\n\n", line);
	free(line);
	return (0);
}
