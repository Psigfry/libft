# libft
libft

Библиотека языка Си, содержащая libc и другие полезные функции. Разработан в рамках учебной программы 42 Силиконовой долины.

## Installation
Clone the repository to a directory.</br>
```
https://github.com/Psigfry/libft2.git
```
</br>
Run make to compile the library.</br>

```
cd libft2 && make && make clean
```
</br>
Это скомпилирует библиотеку libft, и вы получите файл libft.a, содержащий все перечисленные функции.
## Libc functions descriptions
</br>

| Function | Description |
| -------- | ----------- |
| ft_memset | Fill a byte string with a byte value |
| ft_bzero | Write zeroes to a byte string |
| ft_memcpy | Copy memory area |
| ft_memccpy | Copy string until character found |
| ft_memmove | Copy byte string |
| ft_memchr | Locate byte in byte string |
| ft_memcmp | Compare byte string |
| ft_strlen | Find length of string |
| ft_strdup | Save a copy of a string |
| ft_strcpy | Copy strings |
| ft_strncpy | Copy strings |
| ft_strcat | Concatenate strings |
| ft_strncat | Concatenate strings |
| ft_strlcat | Size-bounded string copying and concatenation |
| ft_strchr | Locate character in string |
| ft_strrchr | Locate character in string |
| ft_strstr | Locate substring in a string |
| ft_strnstr | Locate substring in a string |
| ft_strcmp | Compare strings |
| ft_strncmp | Compare strings |
| ft_atoi | Converts ASCII string to integer |
| ft_isalpha | Alphabetic character test |
| ft_isdigit | Decimal-digital character test |
| ft_isalnum | Alphanumeric character test |
| ft_isascii | Test for ASCII character |
| ft_isprint | Printing character test (space character inclusive) |
| ft_toupper | Lower case to upper case letter conversion |
| ft_tolower | Upper case to lower case letter conversion |

## Bonus functions descriptions

| Function | Description |
| -------- | ----------- |
| ft_lstnew | Allocates and returns "fresh" link |
| ft_lstdelone | Deallocates link's content and address |
| ft_lstdel | Deallocates pointed link's and following link's contents and addresses |
| ft_lstadd | Adds new element at the beginning of the list |
| ft_lstiter | Iterates and applies function to every element of the list |
| ft_lstmap | Iterates and applies function to every element of the list and stores the result of function to new list |

## Extra functions descriptions

| Function | Description |
| -------- | ----------- |
| ft_islower | Checks if a given character is in lowercase |
| ft_isspace | Checks if a given character is a space character |
| ft_isuppper | Checks if a given character is in upppercase |
| ft_lstfold | Applies a particular function passed in its argument to all of the list elements |
| ft_strconcat | Joins the array of strings with the given delimeter |
| get_next_line | Reads one line from the given file descriptor |
