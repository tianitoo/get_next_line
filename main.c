#include "get_next_line.h"

int main()
{
	int fd = open("test.txt", O_CREAT | O_RDWR);
	printf("%s\n", get_next_line(fd));
}