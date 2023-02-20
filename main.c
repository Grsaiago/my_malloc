#include "my_malloc.h"

int	main(void)
{
	char			**test_mat;

	print_header();
	test_mat = test_matrix_create();
	for (int i = 0;test_mat[i]; i++)
	{
		printf("%s\n", test_mat[i]);
		ft_free(test_mat[i]);
	}
	ft_free(test_mat);
	for (int i = 0; i < 10; i++)
		printf("Só criando lixo aqui namoral mesmo\n");
	for (int i = 0;test_mat[i]; i++)
		printf("%s\n", test_mat[i]);
	return (0);
}

void	ft_free(void *ptr)
{
	t_malloc	*header;

	if (!ptr)
		return ;
	header = ptr - sizeof(t_malloc);
	munmap(header, header->alloc_size + sizeof(t_malloc));
	return ;
}

void	*my_malloc(size_t size)
{
	void		*ptr;
	t_malloc	*header;

	ptr = mmap(NULL, sizeof(t_malloc) + size, PROT_READ | PROT_WRITE,
			MAP_PRIVATE | MAP_ANONYMOUS, 0, 0);
	if (ptr == (void *) -1)
		return(NULL);
	header = ptr;
	header->alloc_size = size;
	ptr += sizeof(t_malloc);
	return (ptr);
}

char	**test_matrix_create(void)
{
	char	**test_mat;

	test_mat = my_malloc(sizeof(char *) * 4);
	test_mat[0] = my_malloc(6);
	memmove(test_mat[0], "cinco", 5);
	test_mat[1] = my_malloc(6);
	memmove(test_mat[1], "cinco", 5);
	test_mat[2] = my_malloc(6);
	memmove(test_mat[2], "cinco", 5);
	test_mat[3] = NULL; 
	return (test_mat);
}

void	print_header(void)
{
	struct rlimit	limits;

	getrlimit(RLIMIT_DATA, &limits);
	printf("\tPROCESS INFO\n");
	printf("DATA SEGMENT:\n");
	printf(" - data soft limit: %lu\n", limits.rlim_cur); 
	printf(" - data hard limit: %lu\n", limits.rlim_max); 
	printf("PAGE SIZE:\n");
	printf(" - page size: %d\n", getpagesize());
	printf("\tTEST OUTPUT\n");
	return ;
}
