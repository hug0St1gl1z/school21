#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

static int	ft_nlen(int n)
{
	int	len;

	len = 1;
	if (n < 0)
		len = 2;
	while (n / 10)
	{
		n /= 10;
		++len;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;
	int		i;

	i = 0;
	len = ft_nlen(n);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	if (n < 0)
	{
		str[0] = '-';
		i = 1;
	}
	str[len] = 0;
	while (len - 1 >= i)
	{
		if (n < 0)
			str[len - 1] = -1 * (n % 10) + '0';
		else
			str[len - 1] = (n % 10) + '0';
		n = n / 10;
		--len;
	}
	return (str);
}

int	main(void)
{
	int	s;

	s = 0;
	printf("%s\n", ft_itoa(s));
	return (0);
}
