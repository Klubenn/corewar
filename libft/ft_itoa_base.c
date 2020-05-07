
char	*calc_num(int num, )

char	*ft_itoa_base(int num, int base)
{
	char *s;
	int i;
	int num0;

	i = 0;
	num0 = num;
	if (base <=0)
		return (NULL);
	while (num0 != 0)
	{
		num /= base;
		i++;
	}
	if (num < 0)
		i++;
	return (calc_num(num, base, i))
}
