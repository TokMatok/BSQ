
#include "ft_atoi.h"

bool	is_digit(char c)
{
	return ('0' <= c && c <= '9');
}

bool	ft_isspace(char c)
{
	return (c == ' ' || c == '\f' || c == '\n' ||
		c == '\r' || c == '\t' || c == '\v');
}

bool	ft_atoi(char *str, int *num)
{
	char	sign;
	int		ans;
	bool	was;

	sign = 0;
	ans = 0;
	was = false;
	if (str[0] == '\0')
		return (false);
	while (ft_isspace(*str))
		++str;
	while (*str >= '0' && *str <= '9')
	{
		was = true;
		ans *= 10;
		ans += *str - '0';
		++str;
	}
	if (!was || *str != '\0')
		return (false);
	*num = ans;
	return (true);
}
