*This project has been created as part of the 42 curriculum by klenesle.*

# ft_printf

## Description

**ft_printf** is a re-implementation of the C standard library function `printf`. The goal of the project is to learn how variadic functions work in C (`<stdarg.h>`) and how to build a small, extensible program that parses a format string and dispatches work to dedicated handlers.

The function has the following prototype:

```c
int ft_printf(const char *str, ...);
```

It writes the formatted output to the standard output and returns the number of characters printed, like the original `printf`.

### Supported conversions

| Conversion | Description                                         |
|------------|-----------------------------------------------------|
| `%c`       | A single character                                  |
| `%s`       | A string (prints `(null)` if the pointer is `NULL`) |
| `%p`       | A pointer address in hexadecimal                    |
| `%d`       | A signed decimal integer                            |
| `%i`       | A signed decimal integer                            |
| `%u`       | An unsigned decimal integer                         |
| `%x`       | An unsigned integer in lowercase hexadecimal        |
| `%X`       | An unsigned integer in uppercase hexadecimal        |
| `%%`       | A literal percent sign                              |

### Project structure

| File               | Role                                              |
|--------------------|---------------------------------------------------|
| `ft_printf.c`      | Entry point: parses the format string, dispatches |
| `ft_print_c.c`     | Handles `%c`                                      |
| `ft_print_s.c`     | Handles `%s`                                      |
| `ft_print_p.c`     | Handles `%p`                                      |
| `ft_print_d_i.c`   | Handles `%d` and `%i`                             |
| `ft_print_u.c`     | Handles `%u`                                      |
| `ft_print_x.c`     | Handles `%x` and `%X`                             |
| `ft_print_percent.c` | Handles `%%`                                    |
| `ft_printf.h`      | Header with the prototypes                        |
| `Makefile`         | Builds `libftprintf.a`                            |

## Instructions

### Compilation

From the root of the repository:

```bash
make        # builds libftprintf.a
make clean  # removes object files
make fclean # removes object files and libftprintf.a
make re     # rebuilds everything
```

### Usage

Include the header and link against the library:

```c
#include "ft_printf.h"

int main(void)
{
	int ret;

	ret = ft_printf("Hello %s, number %d, hex %x\n", "world", 42, 255);
	ft_printf("%d characters printed\n", ret);
	return (0);
}
```

```bash
cc -Wall -Wextra -Werror main.c -L. -lftprintf -o test
./test
```

## Algorithm and data structure

**Approach: a single pass over the format string with a dispatcher.**

`ft_printf` initializes a `va_list` with `va_start`, then walks through the format string one character at a time:

- A regular character is written directly to the standard output.
- When a `%` is found, the next character is read as the conversion specifier. A dispatch function (a chain of comparisons) calls the matching handler (`ft_print_c`, `ft_print_s`, ...) and passes it the next argument taken with `va_arg`.
- Every handler returns the number of characters it wrote. `ft_printf` adds these values to a running counter, which is returned at the end after `va_end`.

**Why this design:**

- **One handler per conversion** keeps each function short, readable and easy to test on its own (and fits the Norm's function size limits).
- **Counting in the return value of each handler** avoids any global variable and avoids building the whole string in memory first. Output is written right away, so the memory usage stays constant, and no dynamic allocation is needed.
- **No intermediate data structure** is required, because the project only has to support a fixed, small set of conversions. A dispatch on a single character is simple and fast, and adding a new conversion only means adding a handler and one case.
- **Numbers** (`%d`, `%i`, `%u`, `%x`, `%X`, `%p`) are converted by successive division by the base (10 or 16), which handles every value including `INT_MIN`, `UINT_MAX` and pointers on 64 bits. Unsigned and `long` types are used where needed so that negative values and the minimum integer do not overflow.
- **Edge cases** follow the behavior of the original function: `%s` with `NULL` prints `(null)`, and `%c` with `0` still prints a null byte and counts as one character.

## Resources

### References

- `man printf.3` and `man stdarg.3`
- [C reference: `printf`](https://en.cppreference.com/w/c/io/fprintf)
- [C reference: variadic arguments (`va_list`)](https://en.cppreference.com/w/c/variadic)
- [GNU C Library manual: Formatted Output](https://www.gnu.org/software/libc/manual/html_node/Formatted-Output.html)

### Testing

- Test main comparing `printf` and `ft_printf` (output and return value).
- A [test main gist](https://gist.github.com/cezelot/1f2123fa3ddc1c71b5ca4c9c66a5e15d), used only after the code was written and tested with my own tests, as an extra check.
- Community testers such as [printfTester](https://github.com/Tripouille/printfTester) and [ftprintf-tester](https://github.com/paulo-santana/ft_printf_tester).

### Use of AI

AI (Claude) was used as a helper, not to write the project's core code:

- To write test `main.c` files that compare `ft_printf` against the real `printf` for each conversion.
- To find existing community testers.
- To draft this README, which was then reviewed and adapted.

The implementation of `ft_printf` itself was written and understood by the author.