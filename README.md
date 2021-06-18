# Get Next Line (GNL)
The aim of this project is to make you code a function that returns a line ending with a newline, read from a file descriptor. Calling the function get_next_line in a loop will then allow you to read the text available on a file descriptor one line at a time until the EOF.

---

## How to use
This function has an undefined behavior if, between two calls, the same file descriptor switches to a different file before the EOF has been reached on the first fd.
The function gnl make the allocation of memory for the variable line. So its necessary call free after use the variable for avoid problems with leak.
The return of this function is:

> * 1 : A line has been read
> * 0 : EOF has been reached
> * -1 : An error happened

```c
#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

int	main(void)
{
	int		fd;
	int		gnl;
	char	*line;

	fd = open("file", O_RDONLY);
	gnl = get_next_line(fd, &line);
	while(gnl)
	{
		printf("%s\n", line);
		free(line);
		gnl = get_next_line(fd, &line);
	}
	free(line);
	close(fd);
	return (0);
}
```
---

If you need read multiple files without reached the EOF, use the function bonus. Its necessary just change the include of header used by get_next_line_bonus.h

```c
#include "get_next_line_bonus.h"
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

int	main(void)
{
	int		fd;
	int		gnl;
	char	*line;

	fd = open("file", O_RDONLY);
	gnl = get_next_line(fd, &line);
	while(gnl)
	{
		printf("%s\n", line);
		free(line);
		gnl = get_next_line(fd, &line);
	}
	free(line);
	close(fd);
	return (0);
}
```

# Compilation
### Mandatory party
Your program must compile with the flag -D BUFFER_SIZE=xx. which will be used as the buffer size for the read calls in your get_next_line.
`gcc -Wall -Wextra -Werror -D BUFFER_SIZE=32 get_next_line.c get_next_line_utils.c`  

### Bonus party
If you want use the bonus part to be able to use multiple files descriptor, you just need add `_bonus` at the end of the name, `gcc -Wall -Wextra -Werror -D BUFFER_SIZE=32 get_next_line_bonus.c get_next_line_utils_bonus.c`.

## Contributing
Everyone can contribute to libft. Just send me a email, I will add you to contributors.