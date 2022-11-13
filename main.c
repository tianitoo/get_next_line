#include "get_next_line.h"

int main()
{
	int fd = open("test.txt", O_CREAT | O_RDWR);
	printf(get_next_line(fd));
	printf(get_next_line(fd));
	printf(get_next_line(fd));
	printf(get_next_line(fd));
	printf(get_next_line(fd));
	printf(get_next_line(fd));
}