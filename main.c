#include <fcntl.h>
#include "get_next_line.h"


int main()
{
	int		fd;
	char	*s;

	fd = open("tst.txt", O_RDONLY);
	while (1)
	{
		s = get_next_line(fd);
		printf("%s", s);
		if (s == NULL)
			break;
		free(s);
	}
	close(fd);
	return (0);
}
