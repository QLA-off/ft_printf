*This project has been created as part of the 42 curriculum by klenesle.*

# Libft

## Description

**Libft** is the first project of the 42 common core. The goal is to re-implement, from scratch, a set of standard C library functions, add a few extra utility functions, and package everything into a static library (`libft.a`) that will be reused in all later 42 projects.

The project teaches the fundamentals of C programming: pointers, memory management (`malloc` / `free`), string and memory manipulation, edge-case handling, the use of a `Makefile`, and writing clean code that respects the 42 Norm. It also teaches why standard functions behave the way they do, since each one must match the behaviour of its libc counterpart.

### The library

`libft.a` is split into three parts:

#### Part 1 - Libc functions
Re-implementations of standard functions, with the same prototypes and behaviour (prefixed with `ft_`).

| Category | Functions |
|---|---|
| Character checks | `ft_isalpha`, `ft_isdigit`, `ft_isalnum`, `ft_isascii`, `ft_isprint` |
| Character conversion | `ft_toupper`, `ft_tolower` |
| String handling | `ft_strlen`, `ft_strlcpy`, `ft_strlcat`, `ft_strchr`, `ft_strrchr`, `ft_strncmp`, `ft_strnstr`, `ft_strdup` |
| Memory handling | `ft_memset`, `ft_bzero`, `ft_memcpy`, `ft_memmove`, `ft_memchr`, `ft_memcmp`, `ft_calloc` |
| Conversion | `ft_atoi` |

#### Part 2 - Additional functions
Functions that are not in libc or that are part of other libraries in a different form.

| Function | Description |
|---|---|
| `ft_substr` | Allocates and returns a substring of a string. |
| `ft_strjoin` | Allocates and returns the concatenation of two strings. |
| `ft_strtrim` | Trims a set of characters from the start and end of a string. |
| `ft_split` | Splits a string into an array of strings using a delimiter character. |
| `ft_itoa` | Converts an integer to a string. |
| `ft_strmapi` | Applies a function to each character, returning a new string. |
| `ft_striteri` | Applies a function to each character of a string (in place, with index). |
| `ft_putchar_fd` | Writes a character to a file descriptor. |
| `ft_putstr_fd` | Writes a string to a file descriptor. |
| `ft_putendl_fd` | Writes a string followed by a newline to a file descriptor. |
| `ft_putnbr_fd` | Writes an integer to a file descriptor. |

#### Part 3 - Linked lists
Functions to manipulate singly linked lists, based on the following structure:

```c
typedef struct s_list
{
    void            *content;
    struct s_list   *next;
}   t_list;
```

| Function | Description |
|---|---|
| `ft_lstnew` | Creates a new node. |
| `ft_lstadd_front` | Adds a node at the beginning of the list. |
| `ft_lstsize` | Counts the nodes in the list. |
| `ft_lstlast` | Returns the last node of the list. |
| `ft_lstadd_back` | Adds a node at the end of the list. |
| `ft_lstdelone` | Deletes one node, freeing its content with a given function. |
| `ft_lstclear` | Deletes and frees a node and all the nodes after it. |
| `ft_lstiter` | Applies a function to the content of each node. |
| `ft_lstmap` | Creates a new list by applying a function to each node's content. |

## Instructions

### Requirements
- A C compiler (`cc`, `gcc` or `clang`)
- `make`
- `ar` (to build the static library)

### Compilation

The library is compiled with `-Wall -Wextra -Werror`.

```bash
# Build libft.a (mandatory part)
make

# Remove object files
make clean

# Remove object files and libft.a
make fclean

# Rebuild everything from scratch
make re
```

### Usage

Include the header in your source file:

```c
#include "libft.h"
```

Then compile your program by linking it against the library:

```bash
cc -Wall -Wextra -Werror main.c -L. -lft -o my_program
```

or directly with the archive:

```bash
cc -Wall -Wextra -Werror main.c libft.a -o my_program
```

### Example

```c
#include "libft.h"

int main(void)
{
    char    *str = ft_strjoin("Hello, ", "42!");
    char    **words = ft_split("libft is fun", ' ');

    ft_putendl_fd(str, 1);
    ft_putendl_fd(words[0], 1);
    /* free str and words after use */
    return (0);
}
```

## Resources

### References
- `man 3 <function>` - manual pages for the libc functions being re-implemented (`man 3 strlcpy`, `man 3 memmove`, ...)
- [The C Programming Language](https://en.wikipedia.org/wiki/The_C_Programming_Language) - Kernighan & Ritchie
- [GeeksForGeeks](https://www.geeksforgeeks.org) - libc functions behavior and hints
- [cppreference - C standard library](https://en.cppreference.com/w/c) - reference for the C standard library
- [GNU Make Manual](https://www.gnu.org/software/make/manual/make.html) - writing Makefiles
- [42 Norm](https://github.com/42School/norminette) - coding standard enforced by `norminette`

### Use of AI

- AI was used to help write and structure this `README.md`.
- AI was used to understand edge cases of certain functions.
- All the code of the library was written, tested and understood by the author.
