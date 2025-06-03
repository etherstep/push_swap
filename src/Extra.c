static void normalize_array(t_stack *a)
{
	int i, j, count;
	int *normalized = malloc(a->size * sizeof(int));

	if (!normalized)
		ft_error(a, NULL);

	for (i = 0; i < a->size; i++)
	{
		count = 0;
		for (j = 0; j < a->size; j++)
		{
			if (a->arr[j] < a->arr[i])
				count++;
		}
		normalized[i] = count;
	}
	for (i = 0; i < a->size; i++)
		a->arr[i] = normalized[i];

	free(normalized);
}
