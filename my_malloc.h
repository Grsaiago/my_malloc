#ifndef FT_MALLOC_H
# define FT_MALLOC_H
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <sys/time.h>
# include <sys/resource.h>
# include <sys/mman.h>

typedef struct s_malloc
{
	size_t	alloc_size;
} t_malloc;

__attribute((malloc))
void	*ft_malloc(size_t size);
void	ft_free(void *ptr);
void	print_header(void);
char	**test_matrix_create(void);

#endif
