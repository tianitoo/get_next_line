 #include "get_next_line.h"

char *get_next_line(int fd)
{
	char 
	int i;
	static int position = 0;
	static char rest_buffer[BUFFER_SIZE];

	i = 0;
	

	printf("\n%d\n", position);
	return (buff);
}

void	print_line(char *buff, int *position, char *rest_buffer, char *returnvalue)
{
	int	found_new_line;
	int i;
	char *buff;

	found_new_line = 0;
	i = 0;
	while (i < BUFFER_SIZE)
	{
		if (buff[i] != 0 && !found_new_line)
		{
			if (buff[i] == '\n')
			{
				found_new_line = 1;
				set_rest_buffer();
			}
			else
			{
				buff = malloc(sizeof(char) * BUFFER_SIZE);
				i = read(fd, buff, BUFFER_SIZE-1);
				print_line(&buff, &position, &rest_buffer);
				
			}
		}
	}
}