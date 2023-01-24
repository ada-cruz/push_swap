int	ifitsorganized(int *stacka,int sizea)
{
	int i;

	i = 0;
	while(stacka)
	{
		if (stacka[i] > stacka[i + 1])
			return (0);
		i++
	}
	return (1);
}