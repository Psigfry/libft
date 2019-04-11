/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/05 02:35:16 by jguyet            #+#    #+#             */
/*   Updated: 2015/12/05 02:35:19 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>

#ifndef __COLOR__
#define __COLOR__

#define C_NO	"\033[00m"
#define C_OK	"\033[35m"
#define C_GOOD	"\033[32m"
#define C_ERROR	"\033[31m"

#endif

static void		txt_error_info(char *s)
{
	ft_putstr(" ");
	ft_putstr(C_ERROR);
	ft_putstr(s);
	ft_putstr(" ");
	ft_putstr(C_NO);
}

static int		test_memset(void)
{
	int		erreur = 0;
	int		reussi = 0;
	char	s1[9] = ".........";
	char	s2[15] = "......rgrgr...r";
	char	*ss1, *ss2;

	ss1 = ft_memset(s1, '-', 9);
	erreur = memcmp(ss1, "---------", 9);
	if (!erreur)
		reussi++;
	else
		txt_error_info("memcmp(ss1, \"---------\", 9)");
	ss2 = ft_memset(s2, '-', 5);
	erreur = memcmp(ss2, "-----.rgrgr...r", 14);
	if (!erreur)
		reussi++;
	else
		txt_error_info("memcmp(ss2, \"-----.rgrgr...r\", 14)");

	return (reussi);
}

static int		test_bzero(void)
{
	int		erreur = 0;
	int		reussi = 0;
	char	*s1 = malloc(sizeof(char) * 10);
	char	*s2 = malloc(sizeof(char) * 15);
	char	*st1 = malloc(sizeof(char) * 10);
	char	*st2 = malloc(sizeof(char) * 15);

	ft_bzero(s1, 9);
	bzero(st1, 9);
	erreur = memcmp(s1, st1, 9);
	if (!erreur)
		reussi++;
	else
		txt_error_info("bzero(st1, 9)");
	ft_bzero(s2, 9);
	bzero(st2, 9);
	erreur = memcmp(s2, st2, 14);
	if (!erreur)
		reussi++;
	else
		txt_error_info("bzero(st2, 9)");
	return (reussi);
}

static int		test_memcpy(void)
{
	int		erreur = 0;
	int		reussi = 0;
	char	*s1 = malloc(sizeof(char) * 10);
	char	*s2 = malloc(sizeof(char) * 15);
	char	st1[9] = "ijd\0kjdno";
	char	st2[14] = "";

	ft_memcpy(s1, st1, 9);
	erreur = memcmp(s1, st1, 9);
	if (!erreur)
		reussi++;
	else
		txt_error_info("ft_memcpy(s1, \"ijd\\0kjdno\", 9)");
	ft_memcpy(s2, st2, 0);
	erreur = memcmp(s2, st2, 0);
	if (!erreur)
		reussi++;
	else
		txt_error_info("ft_memcpy(s2, \"\", 0);");
	return (reussi);
}

static int		test_memccpy(void)
{
	int		erreur = 0;
	int		reussi = 0;
	char	*s1 = malloc(sizeof(char) * 10);
	char	*s2 = malloc(sizeof(char) * 15);
	char	st1[9] = "ijd\0t";
	char	st2[14] = "";

	ft_memccpy(s1, st1, 9, 5);
	erreur = memcmp(s1, st1, 5);
	if (!erreur)
		reussi++;
	else
		txt_error_info("ft_memccpy(s1, \"ijd\\0t\", 9, 5)");
	ft_memccpy(s2, st2, 14, 0);
	erreur = memcmp(s2, st2, 0);
	if (!erreur)
		reussi++;
	else
		txt_error_info("ft_memccpy(s2, \"\", 14, 0)");
	return (reussi);
}

static int		test_memmove(void)
{
	int		erreur = 0;
	int		reussi = 0;
	char dest[10] = "oldstring";
	char src[10]  = "newstring";
	char destn[] = "oldstring";
	char srcn[]  = "newstring";
	memmove(dest, src, 9);
	ft_memmove(destn, srcn, 9);
	erreur = memcmp(dest, destn, 9);
	if (!erreur)
		reussi++;
	else
		txt_error_info("ft_memmove(\"oldstring\", \"newstring\", 9);");
	memmove(dest, NULL, 0);
	ft_memmove(destn, NULL, 0);
	erreur = memcmp(dest, destn, 9);
	if (!erreur)
		reussi++;
	else
		txt_error_info("ft_memmove(\"oldstring\", NULL, 9);");
	return (reussi);
}

static int		test_memchr(void)
{
	int		erreur = 0;
	int		reussi = 0;

   char str[] = "http://www.tutorialspoint.com";
   char ch = '.';
   char *ret, *ret2, *ret3, *ret4;

   char str2[] = "http://www.tutorialspoint.com";
   char ch2 = '.';

   ret = memchr(str, ch, strlen(str));
   ret2 = ft_memchr(str2, ch2, strlen(str2));
   erreur = strcmp(ret, ret2);
	if (!erreur)
		reussi++;
	else
		txt_error_info("ft_memchr(str2, ch2, strlen(str2));");
   char stru[] = "http://www.tutorialspoint.com";
   char chu = 'h';

   char stri[] = "http://www.tutorialspoint.com";
   char chi = 'h';

   ret3 = memchr(stru, chu, strlen(stru));
   ret4 = ft_memchr(stri, chi, strlen(stri));
   erreur = strcmp(ret3, ret4);
	if (!erreur)
		reussi++;
	else
		txt_error_info("ft_memchr(stri, chi, strlen(stri));");
	return (reussi);
}

static int		test_memcmp(void)
{
	int		reussi = 0;

	if (ft_memcmp("_pp\0mm2", "_pp\0mm2", 5) == memcmp("_pp\0mm2", "_pp\0mm2", 5))
		reussi++;
	else
		txt_error_info("ft_memcmp(\"_pp\\0mm2\", \"_pp\\0mm2\", 5) == memcmp(\"_pp\\0mm2\", \"_pp\\0mm2\", 5)");
	if (ft_memcmp("\0\0\0", "\0\0\0", 3) == memcmp("\0\0\0", "\0\0\0", 3))
		reussi++;
	else
		txt_error_info("ft_memcmp(\"\\0\\0\\0\", \"\\0\\0\\0\", 3) == memcmp(\"\\0\\0\\0\", \"\\0\\0\\0\", 3)");
	if (ft_memcmp("", "", 0) == memcmp("", "", 0))
		reussi++;
	else
		txt_error_info("ft_memcmp(\"\", \"\", 0) == memcmp(\"\", \"\", 0)");
	if (ft_memcmp("testosterogne.", "testosterone.", 5) == memcmp("testosterogne.", "testosterone.", 5))
		reussi++;
	else
		txt_error_info("ft_memcmp(\"testosterogne.\", \"testosterone.\", 5) == memcmp(\"testosterogne.\", \"testosterone.\", 5)");
	return (reussi);
}

static int		test_strlen(void)
{
	int		reussi = 0;

	if (ft_strlen("") == strlen(""))
		reussi++;
	else
		txt_error_info("ft_strlen(\"\") == strlen(\"\")");
	if (ft_strlen("ppppefefefgeggdvsvs") == strlen("ppppefefefgeggdvsvs"))
		reussi++;
	else
		txt_error_info("ft_strlen(\"ppppefefefgeggdvsvs\") == strlen(\"ppppefefefgeggdvsvs\")");
	if (ft_strlen("ppppefe\0fefgeggdvsvs") == strlen("ppppefe\0fefgeggdvsvs"))
		reussi++;
	else
		txt_error_info("ft_strlen(\"ppppefe\\0fefgeggdvsvs\") == strlen(\"ppppefe\\0fefgeggdvsvs\")");
	if (ft_strlen("ppppefefefgeggdvsvs00jfrjgrgrgrjgjfdgdfgsdgjksjkdgksjhdghshdghsdgjsghsjkdbnvsdkjvkjdsgjdsjgfjdshvhdshgdsgjksdkghdshg") == strlen("ppppefefefgeggdvsvs00jfrjgrgrgrjgjfdgdfgsdgjksjkdgksjhdghshdghsdgjsghsjkdbnvsdkjvkjdsgjdsjgfjdshvhdshgdsgjksdkghdshg"))
		reussi++;
	else
		txt_error_info("ft_strlen(\"ppppefefefgeggdvsvs00jfrjgrgrgrjgjfdgdfgsdgjksjkdgksjhdghshdghsdgjsghsjkdbnvsdkjvkjdsgjdsjgfjdshvhdshgdsgjksdkghdshg\") == strlen(\"ppppefefefgeggdvsvs00jfrjgrgrgrjgjfdgdfgsdgjksjkdgksjhdghshdghsdgjsghsjkdbnvsdkjvkjdsgjdsjgfjdshvhdshgdsgjksdkghdshg\")");
	return (reussi);
}

static int		test_strdup(void)
{
	int		reussi = 0;

	if (!ft_strcmp(ft_strdup("lololo"), strdup("lololo")))
		reussi++;
	else
		txt_error_info("!ft_strcmp(ft_strdup(\"lololo\"), strdup(\"lololo\"))");
	if (!ft_strcmp(ft_strdup(""), strdup("")))
		reussi++;
	else
		txt_error_info("!ft_strcmp(ft_strdup(\"\"), strdup(\"\"))");
	if (!ft_strcmp(ft_strdup("."), strdup(".")))
		reussi++;
	else
		txt_error_info("!ft_strcmp(ft_strdup(\".\"), strdup(\".\"))");
	if (!ft_strcmp(ft_strdup(".egrgrhthtjdv\0"), strdup(".egrgrhthtjdv\0")))
		reussi++;
	else
		txt_error_info("!ft_strcmp(ft_strdup(\".egrgrhthtjdv\\0\"), strdup(\".egrgrhthtjdv\\0\"))");
	return (reussi);
}

static int		test_strcpy(void)
{
	int		reussi = 0;
	char *dst1 = malloc(sizeof(char) * 20);
	char *dst2 = malloc(sizeof(char) * 20);
	if (!ft_strcmp(ft_strcpy(dst1, "lololo"), strcpy(dst2, "lololo")))
		reussi++;
	else
		txt_error_info("!ft_strcmp(ft_strcpy(dst1, \"lololo\"), strcpy(dst2, \"lololo\"))");
	if (!ft_strcmp(ft_strcpy(dst1, "."), strcpy(dst2, ".")))
		reussi++;
	else
		txt_error_info("!ft_strcmp(ft_strcpy(dst1, \".\"), strcpy(dst2, \".\"))");
	if (!ft_strcmp(ft_strcpy(dst1, ".egrgrhthtjdv\0"), strcpy(dst2, ".egrgrhthtjdv\0")))
		reussi++;
	else
		txt_error_info("!ft_strcmp(ft_strcpy(dst1, \".egrgrhthtjdv\\0\"), strcpy(dst2, \".egrgrhthtjdv\\0\"))");
	return (reussi);
}

static int		test_strncpy(void)
{
	int		reussi = 0;
	char *dst1 = malloc(sizeof(char) * 20);
	char *dst2 = malloc(sizeof(char) * 20);
	if (!ft_strcmp(ft_strncpy(dst1, "lololo", 3), strncpy(dst2, "lololo", 3)))
		reussi++;
	else
		txt_error_info("!ft_strcmp(ft_strncpy(dst1, \"lololo\", 3), strncpy(dst2, \"lololo\", 3))");
	if (!ft_strcmp(ft_strncpy(dst1, ".", 0), strncpy(dst2, ".", 0)))
		reussi++;
	else
		txt_error_info("!ft_strcmp(ft_strncpy(dst1, \".\", 0), strncpy(dst2, \".\", 0))");
	if (!ft_strcmp(ft_strncpy(dst1, ".egrgrhthtjdv\0", 9), strncpy(dst2, ".egrgrhthtjdv\0", 9)))
		reussi++;
	else
		txt_error_info("!ft_strcmp(ft_strncpy(dst1, \".egrgrhthtjdv\\0\", 9), strncpy(dst2, \".egrgrhthtjdv\\0\", 9))");
	return (reussi);
}

static int		test_strncat(void)
{
	int		reussi = 0;
	char src[50], dest[50], src2[50], dest2[50];

	strcpy(src,  "This is source");
	strcpy(dest, "This is destination");
	strcpy(src2,  "This is source");
	strcpy(dest2, "This is destination");
	if (!ft_strcmp(strncat(dest, src, 15), strncat(dest2, src2, 15)))
		reussi++;
	else
		txt_error_info("!ft_strcmp(strncat(dest, src, 15), strncat(dest2, src2, 15))");
	strcpy(src,  "Ththth");
	strcpy(dest, "Ththth");
	strcpy(src2,  "Ththth");
	strcpy(dest2, "Ththth");
	if (!ft_strcmp(strncat(dest, src, 15), strncat(dest2, src2, 15)))
		reussi++;
	else
		txt_error_info("!ft_strcmp(strncat(dest, src, 15), strncat(dest2, src2, 15))");
	return (reussi);
}

static int		test_strlcat(void)
{
	int		reussi = 0;
	char src[50], dest[50], src2[50], dest2[50];

	strcpy(src,  "This is source");
	strcpy(dest, "This is destination");
	strcpy(src2,  "This is source");
	strcpy(dest2, "This is destination");
	if (strlcat(dest, src, 3) == strlcat(dest2, src2, 3))
		reussi++;
	else
		txt_error_info("strlcat(dest, src, 3) == strlcat(dest2, src2, 3)");
	strcpy(src,  "Ththth");
	strcpy(dest, "Ththth");
	strcpy(src2,  "Ththth");
	strcpy(dest2, "Ththth");
	if (strlcat(dest, src, 15) == strlcat(dest2, src2, 15))
		reussi++;
	else
		txt_error_info("strlcat(dest, src, 15) == strlcat(dest2, src2, 15)");
	return (reussi);
}

static int		test_strrchr(void)
{
	int		erreur = 0;
	int		reussi = 0;

   char str[] = "http://www.tutorialspoint.com";
   char ch = '.';
   char *ret, *ret2, *ret3, *ret4;

   char str2[] = "http://www.tutorialspoint.com";
   char ch2 = '.';

   ret = strrchr(str, ch);
   ret2 = ft_strrchr(str2, ch2);
   erreur = strcmp(ret, ret2);
	if (!erreur)
		reussi++;
	else
		txt_error_info("strcmp(ret, ret2)");
   char stru[] = "http://www.tutorialspoint.com";
   char chu = 'h';

   char stri[] = "http://www.tutorialspoint.com";
   char chi = 'h';

   ret3 = strrchr(stru, chu);
   ret4 = ft_strrchr(stri, chi);
   erreur = strcmp(ret3, ret4);
	if (!erreur)
		reussi++;
	else
		txt_error_info("strcmp(ret3, ret4)");
	return (reussi);
}

static int		test_strstr(void)
{
	int		reussi = 0;
	char haystack[20] = "TutorialsPoint";
	char needle[10] = "Point";
	char haystack2[20] = "TutorialsPoint";
	char needle2[10] = "Point";
	char *ret, *ret2, *ret3, *ret4;
	ret = ft_strstr(haystack, needle);
	ret2 = strstr(haystack2, needle2);
	if (!strcmp(ret, ret2))
		reussi++;
	else
		txt_error_info("ft_strstr(\"TutorialsPoint\", \"Point\");");
	char haystackq[20] = "TutorialsPoi";
	char needleq[10] = "Po\0intoo";
	char haystack2q[20] = "TutorialsPoi";
	char needle2q[10] = "Po\0intoo";
	ret3 = ft_strstr(haystackq, needleq);
	ret4 = strstr(haystack2q, needle2q);
	if (!strcmp(ret3, ret4))
		reussi++;
	else
		txt_error_info("ft_strstr(\"TutorialsPoi\", \"Po\\0intoo\");");
	return (reussi);
}

static int		test_strnstr(void)
{
	int		reussi = 0;
	char haystack[20] = "TutorialsPoint";
	char needle[10] = "Point";
	char haystack2[20] = "TutorialsPoint";
	char needle2[10] = "Point";
	char *ret, *ret2, *ret3, *ret4;
	ret = ft_strnstr(haystack, needle, 17);
	ret2 = strnstr(haystack2, needle2, 17);
	if (!strcmp(ret, ret2))
		reussi++;
	else
		txt_error_info("strnstr(\"TutorialsPoint\", \"Point\", 17)");
	char haystackq[20] = "TutorialsPoi";
	char needleq[10] = "Po\0intoo";
	char haystack2q[20] = "TutorialsPoi";
	char needle2q[10] = "Po\0intoo";
	ret3 = ft_strnstr(haystackq, needleq, 12);
	ret4 = strnstr(haystack2q, needle2q, 12);
	if (!strcmp(ret3, ret4))
		reussi++;
	else
		txt_error_info("ft_strnstr(\"TutorialsPoi\", \"Po\\0intoo\", 12);");
	return (reussi);
}

static int		test_strcmp(void)
{
	int		reussi = 0;
	if (strcmp("", "") == ft_strcmp("", ""))
		reussi++;
	else
		txt_error_info("if (strcmp(\"\", \"\") == ft_strcmp(\"\", \"\"))");
	if (strcmp("...", "...") == ft_strcmp("...", "..."))
		reussi++;
	else
		txt_error_info("if (strcmp(\"...\", \"...\") == ft_strcmp(\"...\", \"...\"))");
	if (strcmp(".", "...") == ft_strcmp(".", "..."))
		reussi++;
	else
		txt_error_info("if (strcmp(\".\", \"...\") == ft_strcmp(\".\", \"...\"))");
	if (strcmp("test de comparaison", "test de comparaison") == ft_strcmp("test de comparaison", "test de comparaison"))
		reussi++;
	else
		txt_error_info("if (strcmp(\"test de comparaison\", \"test de comparaison\") == ft_strcmp(\"test de comparaison\", \"test de comparaison\"))");
	if (strcmp(".", "") == ft_strcmp(".", ""))
		reussi++;
	else
		txt_error_info("if (strcmp(\".\", \"\") == ft_strcmp(\".\", \"\"))");
	if (strcmp("plp", "pl") == ft_strcmp("plp", "pl"))
		reussi++;
	else
		txt_error_info("if (strcmp(\"plp\", \"pl\") == ft_strcmp(\"plp\", \"pl\"))");
	if (strcmp("\200", "\0") == ft_strcmp("\200", "\0"))
		reussi++;
	else
		txt_error_info("if (strcmp(\"\\200\", \"\\0\") == ft_strcmp(\"\\200\", \"\\0\"))");
	if (strcmp("\0", "\200") == ft_strcmp("\0", "\200"))
		reussi++;
	else
		txt_error_info("if (strcmp(\"\\0\", \"\\200\") == ft_strcmp(\"\\0\", \"\\200\"))");
	return (reussi);
}

static int		test_atoi(void)
{
	int		reussi = 0;
	if (atoi("\n\t\v-898") == atoi("\n\t\v-898"))
		reussi++;
	else
		txt_error_info("if (atoi(\"\\n\\t\\v-898\") == atoi(\"\\n\\t\\v-898\"))");
	if (atoi("9475638") == atoi("9475638"))
		reussi++;
	else
		txt_error_info("if (atoi(\"9475638\") == atoi(\"9475638\"))");
	if (atoi("++9475638") == atoi("++9475638"))
		reussi++;
	else
		txt_error_info("if (atoi(\"++9475638\") == atoi(\"++9475638\"))");
	if (atoi("egeg845") == atoi("egeg845"))
		reussi++;
	else
		txt_error_info("if (atoi(\"egeg845\") == atoi(\"egeg845\"))");
	if (atoi("97465n45") == atoi("97465n45"))
		reussi++;
	else
		txt_error_info("if (atoi(\"97465n45\") == atoi(\"97465n45\"))");
	if (atoi("974645") == atoi("974645"))
		reussi++;
	else
		txt_error_info("if (atoi(\"974645\") == atoi(\"974645\"))");
	return (reussi);
}

static int		test_isalpha(void)
{
	int		reussi = 0;
	int		i = -100;
	while (i < 200)
	{
		if (isalpha(i) == ft_isalpha(i))
			reussi++;
		i++;
	}
	return (reussi);
}

static int		test_isdigit(void)
{
	int		reussi = 0;
	int		i = -100;
	while (i < 200)
	{
		if (isdigit(i) == ft_isdigit(i))
			reussi++;
		i++;
	}
	return (reussi);
}

static int		test_isalnum(void)
{
	int		reussi = 0;
	int		i = -100;
	while (i < 200)
	{
		if (isalnum(i) == ft_isalnum(i))
			reussi++;
		i++;
	}
	return (reussi);
}

static int		test_isascii(void)
{
	int		reussi = 0;
	int		i = -100;
	while (i < 200)
	{
		if (isascii(i) == ft_isascii(i))
			reussi++;
		i++;
	}
	return (reussi);
}

static int		test_isprint(void)
{
	int		reussi = 0;
	int		i = -100;
	while (i < 200)
	{
		if (isprint(i) == ft_isprint(i))
			reussi++;
		i++;
	}
	return (reussi);
}

static int		test_toupper(void)
{
	int		reussi = 0;
	int		i = -100;
	while (i < 200)
	{
		if (toupper(i) == ft_toupper(i))
			reussi++;
		i++;
	}
	return (reussi);
}

static int		test_tolower(void)
{
	int		reussi = 0;
	int		i = -100;
	while (i < 200)
	{
		if (tolower(i) == ft_tolower(i))
			reussi++;
		i++;
	}
	return (reussi);
}

static int		test_strsplit(void)
{
	int		reussi = 0;
	char	**tmp;
	tmp = ft_strsplit("..test.1.", '.');
	if (!strcmp(tmp[0], "test") && !strcmp(tmp[1], "1") && !tmp[2])
		reussi++;
	else
		txt_error_info("ft_strsplit(\"..test.1.\", '.');");
	tmp = ft_strsplit("...ee.test.1.oooo..", '.');
	if (!strcmp(tmp[0], "ee") && !strcmp(tmp[1], "test") && !strcmp(tmp[2], "1") && !strcmp(tmp[3], "oooo") && !tmp[4])
		reussi++;
	else
		txt_error_info("ft_strsplit(\"...ee.test.1.oooo..\", '.');");
		tmp = NULL;
	tmp = ft_strsplit(".", '.');
	if (!tmp[0])
		reussi++;
	else
		txt_error_info("ft_strsplit(\".\", '.');");
	tmp = ft_strsplit("***********Bonjour************comment*******tu********vas*b", '*');
	if (!strcmp(tmp[0], "Bonjour") && !strcmp(tmp[1], "comment") && !strcmp(tmp[2], "tu") && !strcmp(tmp[3], "vas") && !strcmp(tmp[4], "b") && !tmp[5])
		reussi++;
	else
		txt_error_info("ft_strsplit(\"***********Bonjour************comment*******tu********vas*b\", '*');");
	tmp = ft_strsplit("***********Bonjour************comment*******tu********vas*b*", '*');
	if (!strcmp(tmp[0], "Bonjour") && !strcmp(tmp[1], "comment") && !strcmp(tmp[2], "tu") && !strcmp(tmp[3], "vas") && !strcmp(tmp[4], "b") && !tmp[5])
		reussi++;
	else
		txt_error_info("ft_strsplit(\"***********Bonjour************comment*******tu********vas*b*\", '*');");
	tmp = ft_strsplit("***********Bonjour************comment*******tu********vas*b*k", '*');
	if (!strcmp(tmp[0], "Bonjour") && !strcmp(tmp[1], "comment") && !strcmp(tmp[2], "tu") && !strcmp(tmp[3], "vas") && !strcmp(tmp[4], "b") && !strcmp(tmp[5], "k") && !tmp[6])
		reussi++;
	else
		txt_error_info("ft_strsplit(\"***********Bonjour************comment*******tu********vas*b*k\", '*');");
	return (reussi);
}

static void		txt_good(char *s, int nbr, int max)
{
	ft_putstr(s);
	ft_putstr(C_GOOD);
	ft_putstr("  [");
	if (nbr < max)
		ft_putstr(C_OK);
	ft_putnbr(nbr);
	if (nbr < max)
		ft_putstr(C_GOOD);
	ft_putstr("/");
	ft_putnbr(max);
	ft_putstr("]  success");
	ft_putstr(C_NO);
	ft_putstr("\n");
}

static void		txt_error(char *s)
{
	ft_putstr(C_ERROR);
	ft_putstr(s);
	ft_putstr(C_NO);
	ft_putstr("\n");
}

static void		Start(void)
{
	int nbr = 0;
	ft_putstr("------Started Test Libft.a------\n");
	/*******memset*******/
	if ((nbr = test_memset()))
		txt_good("ft_memset...", nbr, 2);
	else
		txt_error("ft_memset...Total Error !");
	/*******bzero*******/
	if ((nbr = test_bzero()))
		txt_good("ft_bzero...", nbr, 2);
	else
		txt_error("ft_bzero...Total Error !");
	/*******memcpy*******/
	if ((nbr = test_memcpy()))
		txt_good("ft_memcpy...", nbr, 2);
	else
		txt_error("ft_memcpy...Total Error !");
	/*******memccpy*******/
	if ((nbr = test_memccpy()))
		txt_good("ft_memccpy...", nbr, 2);
	else
		txt_error("ft_memccpy...Total Error !");
	/*******memmove*******/
	if ((nbr = test_memmove()))
		txt_good("ft_memmove...", nbr, 2);
	else
		txt_error("ft_memmove...Total Error !");
	/*******memchr*******/
	if ((nbr = test_memchr()))
		txt_good("ft_memchr...", nbr, 2);
	else
		txt_error("ft_memchr...Total Error !");
	/*******memcmp*******/
	if ((nbr = test_memcmp()))
		txt_good("ft_memcmp...", nbr, 4);
	else
		txt_error("ft_memcmp...Total Error !");
	/*******strlen*******/
	if ((nbr = test_strlen()))
		txt_good("ft_strlen...", nbr, 4);
	else
		txt_error("ft_strlen...Total Error !");
	/*******strdup*******/
	if ((nbr = test_strdup()))
		txt_good("ft_strdup...", nbr, 4);
	else
		txt_error("ft_strdup...Total Error !");
	/*******strcpy*******/
	if ((nbr = test_strcpy()))
		txt_good("ft_strcpy...", nbr, 3);
	else
		txt_error("ft_strcpy...Total Error !");
		/*******strncpy*******/
	if ((nbr = test_strncpy()))
		txt_good("ft_strncpy...", nbr, 3);
	else
		txt_error("ft_strncpy...Total Error !");
		/*******strncat*******/
	if ((nbr = test_strncat()))
		txt_good("ft_strncat...", nbr, 2);
	else
		txt_error("ft_strncat...Total Error !");
		/*******strlcat*******/
	if ((nbr = test_strlcat()))
		txt_good("ft_strlcat...", nbr, 2);
	else
		txt_error("ft_strlcat...Total Error !");
		/*******strrchr*******/
	if ((nbr = test_strrchr()))
		txt_good("ft_strrchr...", nbr, 2);
	else
		txt_error("ft_strrchr...Total Error !");
		/*******strrstr*******/
	if ((nbr = test_strstr()))
		txt_good("ft_strstr...", nbr, 2);
	else
		txt_error("ft_strstr...Total Error !");
		/*******strnrstr*******/
	if ((nbr = test_strnstr()))
		txt_good("ft_strnstr...", nbr, 2);
	else
		txt_error("ft_strnstr...Total Error !");
		/*******strcmp*******/
	if ((nbr = test_strcmp()))
		txt_good("ft_strcmp...", nbr, 8);
	else
		txt_error("ft_strcmp...Total Error !");
		/*******atoi*******/
	if ((nbr = test_atoi()))
		txt_good("ft_atoi...", nbr, 6);
	else
		txt_error("ft_atoi...Total Error !");
		/*******isalpha*******/
	if ((nbr = test_isalpha()))
		txt_good("ft_isalpha...", nbr, 300);
	else
		txt_error("ft_isalpha...Total Error !");
		/*******isdigit*******/
	if ((nbr = test_isdigit()))
		txt_good("ft_isdigit...", nbr, 300);
	else
		txt_error("ft_isdigit...Total Error !");
		/*******isalnum*******/
	if ((nbr = test_isalnum()))
		txt_good("ft_isalnum...", nbr, 300);
	else
		txt_error("ft_isalnum...Total Error !");
		/*******isascii******/
	if ((nbr = test_isascii()))
		txt_good("ft_isascii..", nbr, 300);
	else
		txt_error("ft_isascii...Total Error !");
		/*******isprint******/
	if ((nbr = test_isprint()))
		txt_good("ft_isprint..", nbr, 300);
	else
		txt_error("ft_isprint...Total Error !");
		/*******toupper******/
	if ((nbr = test_toupper()))
		txt_good("ft_toupper..", nbr, 300);
	else
		txt_error("ft_toupper...Total Error !");
		/*******tolower******/
	if ((nbr = test_tolower()))
		txt_good("ft_tolower..", nbr, 300);
	else
		txt_error("ft_tolower...Total Error !");
/*
 *
 *
 *
 P
 A
 R
 T
 2
 *
 *
 *
*/
		/*******strsplit******/
	if ((nbr = test_strsplit()))
		txt_good("ft_strsplit..", nbr, 6);
	else
		txt_error("ft_strsplit...Total Error !");
}

int		main(void)
{
	Start();

	return (0);
}