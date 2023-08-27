#include "monty.h"

/**
 * lineTokenizer - tokenizes line
 * @line: line to be tokenized
 * @tokensNum: number of tokens
 * Return: tokens array or NULL when the memory allocation fails
 */
char **lineTokenizer(char *line, int *tokensNum)
{
	char *lineCopy, *token, **tokens;
	int j, i = 0;

	lineCopy = malloc(sizeof(char) * (_strlen(line) + 1));
	if (!lineCopy)
		return (NULL);
	_strcpy(lineCopy, line);
	token = strtok(lineCopy, DELIMS);
	while (token)
	{
		(*tokensNum)++;
		token = strtok(NULL, DELIMS);
	}

	tokens = malloc(sizeof(*tokens) * ((*tokensNum) + 1));
	if (!tokens)
	{
		free(lineCopy);
		return (NULL);
	}
	_strcpy(lineCopy, line);
	token = strtok(lineCopy, DELIMS);
	while (token)
	{
		tokens[i] = malloc(sizeof(char) * (_strlen(token) + 1));
		if (!tokens[i])
		{
			for (j = 0; j < i; j++)
				free(tokens[j]);
			free(tokens);
			free(lineCopy);
			return (NULL);
		}
		_strcpy(tokens[i], token);
		i++;
		token = strtok(NULL, DELIMS);
	}
	tokens[i] = NULL;
	free(lineCopy);
	return (tokens);
}

/**
 * splitLine - split a string into an array of words
 * @line: the string to split
 * Return: tokens or NULL
 */
char **splitLine(char *line)
{
	int tokensNum = 0;
	char **tokens;

	tokens = lineTokenizer(line, &tokensNum);
	if (!tokens)
	{
		free(line);
		return (NULL);
	}
	return (tokens);
}
