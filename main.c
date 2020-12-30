/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpunet <rpunet@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 16:49:39 by rpunet            #+#    #+#             */
/*   Updated: 2020/12/30 03:13:49 by rpunet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>
#include <fcntl.h>
#include <stdlib.h>

//#define	STRLEN(x)

int		ft_strlen(char *str);
char	*ft_strcpy(char *dest, char *src);
int		ft_strcmp(char *s1, char *s2);
int		ft_write(int fd, char *str, int byte);
int		ft_read(int fd, char *str, int byte);
char	*ft_strdup(const char *s);

// Funcion MALLOC para probar el error de memoria no alocada
/* void	*malloc(size_t size)
{
	size++;
	return (NULL);
} */

int			main(int argc, char **argv)
{
	if (argc != 2)
		printf("Choose an appropiate option to test:\n\tft_strlen: strlen\n\tft_strcpy: strcpy\n\tft_strcmp: strcmp\n\tft_write:  write\n\tft_read:   read\n\tft_strdup: strdup\n");
	else if (!strcmp(argv[1], "strlen"))
	{
		char *str;

		str = "hOLa";
		printf("%s = %d (%d)\n", str, ft_strlen(str), (int)strlen(str));
		str = "";
		printf("%s = %d (%d)\n", str, ft_strlen(str), (int)strlen(str));
		str = "\t3por1";
		printf("%s = %d (%d)\n", str, ft_strlen(str), (int)strlen(str));
		str = "1234567890";
		printf("%s = %d (%d)\n", str, ft_strlen(str), (int)strlen(str));
		// str = NULL;
		// printf("%s : %d (%d)\n", str, ft_strlen(str), (int)strlen(str));
	}
	else if (!strcmp(argv[1], "strcpy"))
	{
		char	dest[64];
		char	*src;

		src = "hola";
		printf("src = '%s'; dest = '%s' ('%s')\n", src, ft_strcpy(dest, src), strcpy(dest, src));
		src = "";
		printf("src = '%s'; dest = '%s' ('%s')\n", src, ft_strcpy(dest, src), strcpy(dest, src));
		src = "0123456789abcedef";
		printf("src = '%s'; dest = '%s' ('%s')\n", src, ft_strcpy(dest, src), strcpy(dest, src));
		// src = NULL;
		// printf("src: '%s'; dest: '%s' ('%s')\n", src, ft_strcpy(dest, src), ft_strcpy(dest, src));
	}
	else if (!strcmp(argv[1], "strcmp"))
	{
		char	*s1;
		char	*s2;

		s1 = "hola";
		s2 = "hola";
		printf("'%s' : '%s' = %d (%d)\n", s1, s2, ft_strcmp(s1, s2), strcmp(s1, s2));
		s1 = "hol";
		s2 = "hola";
		printf("'%s' : '%s' = %d (%d)\n", s1, s2, ft_strcmp(s1, s2), strcmp(s1, s2));
		s1 = "hola";
		s2 = "hol";
		printf("'%s' : '%s' = %d (%d)\n", s1, s2, ft_strcmp(s1, s2), strcmp(s1, s2));
		s1 = "hola";
		s2 = "holb";
		printf("'%s' : '%s' = %d (%d)\n", s1, s2, ft_strcmp(s1, s2), strcmp(s1, s2));
		s1 = "";
		s2 = "holb";
		printf("'%s' : '%s' = %d (%d)\n", s1, s2, ft_strcmp(s1, s2), strcmp(s1, s2));
		s1 = "";
		s2 = "hola";
		printf("'%s' : '%s' = %d (%d)\n", s1, s2, ft_strcmp(s1, s2), strcmp(s1, s2));
		s1 = "hola";
		s2 = "";
		printf("'%s' : '%s' = %d (%d)\n", s1, s2, ft_strcmp(s1, s2), strcmp(s1, s2));
		s1 = "";
		s2 = "";
		printf("'%s' : '%s' = %d (%d)\n", s1, s2, ft_strcmp(s1, s2), strcmp(s1, s2));
		//s1 = "hola";
		// s2 = NULL;
		// printf("'%s' : '%s' = %d (%d)\n", s1, s2, ft_strcmp(s1, s2), strcmp(s1, s2));
	}
	else if (!strcmp(argv[1], "write"))
	{
		int	i,j;

		i = ft_write(1, "hola\n", 5);
		j = write(1, "hola\n", 5);
		printf ("num bytes = %d (%d)\n", i, j);
		perror("errno");

		i = ft_write(-1, "hola\n", 5);
		j = write(1, "hola\n", 5);
		printf ("num bytes = %d (%d)\n", i, j);
		perror("errno");

		i = ft_write(1, "hola\n", 5);
		j = write(-1, "hola\n", 5);
		printf ("num bytes = %d (%d)\n", i, j);
		perror("errno");

		i = ft_write(-1, "hola\n", 5);
		j = write(-1, "hola\n", 5);
		printf ("num bytes = %d (%d)\n", i, j);
		perror("errno");

		i = ft_write(1, NULL, 5);
		j = write(1, "hola\n", 5);
		printf ("num bytes = %d (%d)\n", i, j);
		perror("errno");

		i = ft_write(1, "hola\n", 5);
		j = write(1, NULL, 5);
		printf ("num bytes = %d (%d)\n", i, j);
		perror("errno");

		i = ft_write(1, NULL, 5);
		j = write(1, NULL, 5);
		printf ("num bytes = %d (%d)\n", i, j);
		perror("errno");
	}
	else if (!strcmp(argv[1], "read"))
	{
		int	fd = open("main.c", O_RDONLY);
		char	buffer[100] = {0};
		char	buffer2[100] = {0};
		char	buffer3[100] = {0};
		int	i;

		i = ft_read(fd, buffer, 99);
		buffer[i] = 0;
		printf("%d\n", i);
		printf("%s\n", buffer);
		perror("errno");

		i = ft_read(fd, NULL, 99);
		buffer2[i] = 0;
		printf("%d\n", i);
		printf("%s\n", buffer2);
		perror("errno");

		i = ft_read(-1, buffer3, 99);
		buffer3[i] = 0;
		printf("%d\n", i);
		printf("%s\n", buffer3);
		perror("errno");
	}
	else if (!strcmp(argv[1], "strdup"))
	{
		char	 *d, *str;

		str = "buenos dias";
		d = ft_strdup(str);
		perror("errno");
		printf("duplicated:         %s\n", d);
		printf("allocation address: %p\n", d);
		//printf("bytes printed:      %d\n", (int)strlen(d));  -----  si malloc = NULL; strlen(NULL) = segfault
		free(d);
	}
	else
	{
		printf("Invalid option. ");
		printf("Choose an appropiate option to test:\n\tft_strlen: strlen\n\tft_strcpy: strcpy\n\tft_strcmp: strcmp\n\tft_write:  write\n\tft_read:   read\n\tft_strdup: strdup\n");
	}

	return (0);
}
