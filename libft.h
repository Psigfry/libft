/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psigfry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 16:25:06 by psigfry           #+#    #+#             */
/*   Updated: 2019/04/10 14:15:08 by psigfry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

int				ft_atoi(const char *str);
void			ft_putchar(char c);
void			ft_putchar_fd(char c, int fd);
void			ft_putnbr_fd(int nb, int fd);
void			ft_putnbr(int nb);
int				ft_strcmp(const char *s1, const char *s2);
char			*ft_strcpy(char *dest, const char *src);
char			*ft_strdup(const char *src);
size_t			ft_strlen(const char *str);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_strncpy(char *dest, const char *src, size_t n);
char			*ft_strstr(const char *str, const char *find);
void			ft_putstr(const char *str);
void			ft_putstr_fd(const char *str, int fd);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putendl(char const *s);
int				ft_tolower(int c);
int				ft_toupper(int c);
int				ft_isprint(int c);
int				ft_isascii(int c);
int				ft_isalnum(int c);
int				ft_isdigit(int c);
int				ft_isalpha(int c);
char			*ft_strnstr(const char *str, const char *find, size_t len);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
char			*ft_strcat(char *s, const char *c);
char			*ft_strncat(char *s, const char *c, size_t z);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
void			*ft_memset(void *dest, int val, size_t len);
void			*ft_memcpy(void *dst, const void *src,
size_t n);
void			ft_bzero(void *s, size_t len);
void			*ft_memccpy(void *dst, const void *src,
int c, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			ft_strclr(char *s);
void			ft_strdel(char **as);
void			ft_memdel(void **ap);
void			ft_striter(char *s, void (*f)(char *));
void			*ft_memalloc(size_t size);
char			*ft_strnew(size_t size);
int				ft_strequ(char const *s1, char const *s2);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
void			ft_striteri(char *s, void (*f)(unsigned int, char*));
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char			**ft_strsplit(char const *s, char c);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s);
char			*ft_itoa(int n);
char			**ft_strsplit(char const *s, char c);

#endif
