/*	***************************************************************	*/
/*																	*/
/*	make															*/
/*	cc -Wall -Wextra -Werror main.c -L. -lbsd -lftprintf -o test	*/
/*	./test															*/
/*																	*/
/*	***************************************************************	*/

#include "ft_printf.h"
#include <limits.h>
#include <stdio.h>

void	test_character_string(int *count, char *p)
{
	*count = printf("[+] %%%%: %%%%%%%%%%%%");
	printf("\t\t\t\t%d\n", *count);
	*count = ft_printf("[-] %%%%: %%%%%%%%%%%%");
	printf("\t\t\t\t%d\n\n", *count);
	*count = printf("[+] %%c: %c%c%c%c%c%c%c%c%c", \
		'C', 'h', '@', 'r', '4', 'c', 't', 'e', 'r');
	printf("\t\t\t%d\n", *count);
	*count = ft_printf("[-] %%c: %c%c%c%c%c%c%c%c%c", \
		'C', 'h', '@', 'r', '4', 'c', 't', 'e', 'r');
	printf("\t\t\t%d\n\n", *count);
	*count = printf("[+] %%s: %s %s", "$trin9", p);
	printf("\t\t\t%d\n", *count);
	*count = ft_printf("[-] %%s: %s %s", "$trin9", p);
	printf("\t\t\t%d\n\n", *count);
}

void	test_number(int *count, char *p)
{
	*count = printf("[+] %%d: %d %d %d", INT_MIN, 0, INT_MAX);
	printf("\t%d\n", *count);
	*count = ft_printf("[-] %%d: %d %d %d", INT_MIN, 0, INT_MAX);
	printf("\t%d\n\n", *count);
	*count = printf("[+] %%i: %i %i %i", INT_MIN, 0, INT_MAX);
	printf("\t%d\n", *count);
	*count = ft_printf("[-] %%i: %i %i %i", INT_MIN, 0, INT_MAX);
	printf("\t%d\n\n", *count);
	*count = printf("[+] %%u: %u %u %u", -42, 0, UINT_MAX);
	printf("\t\t%d\n", *count);
	*count = ft_printf("[-] %%u: %u %u %u", -42, 0, UINT_MAX);
	printf("\t\t%d\n\n", *count);
	*count = printf("[+] %%x: %x %x %x", -42, 0, 999999999);
	printf("\t\t%d\n", *count);
	*count = ft_printf("[-] %%x: %x %x %x", -42, 0, 999999999);
	printf("\t\t%d\n\n", *count);
	*count = printf("[+] %%X: %X %X %X", -42, 0, 666666666);
	printf("\t\t%d\n", *count);
	*count = ft_printf("[-] %%X: %X %X %X", -42, 0, 666666666);
	printf("\t\t%d\n\n", *count);
	*count = printf("[+] %%p: %p %p", &count, p);
	printf("\t\t%d\n", *count);
	*count = ft_printf("[-] %%p: %p %p", &count, p);
	printf("\t\t%d\n\n", *count);
}

int	main(void)
{
	int		count;
	char	*p;

	count = 0;
	p = NULL;
	test_character_string(&count, p);
	test_number(&count, p);
	return (0);
}