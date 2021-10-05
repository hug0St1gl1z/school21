#include <stdio.h>  //Для printf
#include <string.h>   //Для memset

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;

	i = 0;
	if (!b)
		return (NULL);
	while (i < len)
	{
		*(unsigned char *)(b + i) = (unsigned char) c;
		i++;
	}
	return (b);
}

int	main(void)
{
	unsigned char	src[20] = "11111111111111111111";

	ft_memset (src, '1', 22);
	printf ("%s \n", src);
	return (0);
}
