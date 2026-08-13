*This project has been created as part of the 42 curriculum by yakumar.*

# libft

## Description

**libft** is a custom C library built from scratch as part of the 42 school curriculum. The goal of this project is to re-implement a selection of standard C library functions, as well as create additional utility functions that will be reused throughout the rest of the 42 curriculum.

By building these functions manually, the project reinforces a deep understanding of how low-level C programming works — including memory management, pointers, linked lists, and string manipulation — without relying on the standard library.

The library is divided into three parts:

- **Libc functions** — re-implementations of standard C functions (e.g. `strlen`, `memcpy`, `atoi`)
- **Additional functions** — utility functions not in the standard library but useful for future projects (e.g. `ft_split`, `ft_itoa`, `ft_substr`)
- **Bonus functions** — linked list manipulation functions using a `t_list` struct

---

## Library Reference

### Character Check Functions

| Function | Description |
|---|---|
| `ft_isalpha(int c)` | Returns non-zero if `c` is an alphabetic character |
| `ft_isdigit(int c)` | Returns non-zero if `c` is a decimal digit |
| `ft_isalnum(int c)` | Returns non-zero if `c` is alphanumeric |
| `ft_isascii(int c)` | Returns non-zero if `c` is a valid ASCII character (0–127) |
| `ft_isprint(int c)` | Returns non-zero if `c` is a printable character |
| `ft_toupper(int c)` | Converts a lowercase letter to uppercase |
| `ft_tolower(int c)` | Converts an uppercase letter to lowercase |

### String Functions

| Function | Description |
|---|---|
| `ft_strlen(const char *s)` | Returns the length of string `s` |
| `ft_strlcpy(char *dst, const char *src, size_t size)` | Copies `src` into `dst`, ensuring null-termination, returns length of `src` |
| `ft_strlcat(char *dst, const char *src, size_t size)` | Appends `src` to `dst` safely, returns total length |
| `ft_strchr(const char *s, int c)` | Returns pointer to first occurrence of `c` in `s` |
| `ft_strrchr(const char *s, int c)` | Returns pointer to last occurrence of `c` in `s` |
| `ft_strncmp(const char *s1, const char *s2, size_t n)` | Compares up to `n` characters of `s1` and `s2` |
| `ft_strnstr(const char *big, const char *little, size_t len)` | Finds `little` inside `big`, searching at most `len` characters |
| `ft_strdup(const char *s)` | Allocates and returns a duplicate of string `s` |
| `ft_substr(char const *s, unsigned int start, size_t len)` | Returns a substring of `s` starting at `start` with length `len` |
| `ft_strjoin(char const *s1, char const *s2)` | Allocates and returns the concatenation of `s1` and `s2` |
| `ft_strtrim(char const *s1, char const *set)` | Trims characters in `set` from the beginning and end of `s1` |
| `ft_split(char const *s, char c)` | Splits `s` by delimiter `c`, returns a null-terminated array of strings |
| `ft_strmapi(char const *s, char (*f)(unsigned int, char))` | Applies function `f` to each character of `s`, returns new string |
| `ft_striteri(char *s, void (*f)(unsigned int, char *))` | Applies function `f` to each character of `s` in place |
| `ft_atoi(const char *nptr)` | Converts string `nptr` to an integer |
| `ft_itoa(int n)` | Converts integer `n` to a string |

### Memory Functions

| Function | Description |
|---|---|
| `ft_memset(void *s, int c, size_t n)` | Fills `n` bytes of memory at `s` with byte value `c` |
| `ft_bzero(void *s, size_t n)` | Sets `n` bytes of memory at `s` to zero |
| `ft_memcpy(void *dest, const void *src, size_t n)` | Copies `n` bytes from `src` to `dest` (no overlap) |
| `ft_memmove(void *dest, const void *src, size_t n)` | Copies `n` bytes from `src` to `dest` (handles overlap) |
| `ft_memchr(const void *s, int c, size_t n)` | Searches first `n` bytes of `s` for byte `c`, returns pointer or NULL |
| `ft_memcmp(const void *s1, const void *s2, size_t n)` | Compares first `n` bytes of `s1` and `s2` |
| `ft_calloc(size_t nmemb, size_t size)` | Allocates memory for `nmemb` elements of `size` bytes, zero-initialized |

### Output Functions

| Function | Description |
|---|---|
| `ft_putchar_fd(char c, int fd)` | Writes character `c` to file descriptor `fd` |
| `ft_putstr_fd(char *s, int fd)` | Writes string `s` to file descriptor `fd` |
| `ft_putendl_fd(char *s, int fd)` | Writes string `s` followed by a newline to `fd` |
| `ft_putnbr_fd(int n, int fd)` | Writes integer `n` to file descriptor `fd` |

### Linked List Functions (Bonus)

These functions operate on a singly linked list using the following struct:

```c
typedef struct s_list
{
    void            *content;
    struct s_list   *next;
}   t_list;
```

| Function | Description |
|---|---|
| `ft_lstnew(void *content)` | Creates and returns a new list node with the given `content` |
| `ft_lstadd_front(t_list **lst, t_list *new)` | Adds `new` node at the front of the list |
| `ft_lstadd_back(t_list **lst, t_list *new)` | Adds `new` node at the back of the list |
| `ft_lstsize(t_list *lst)` | Returns the number of nodes in the list |
| `ft_lstlast(t_list *lst)` | Returns the last node of the list |
| `ft_lstdelone(t_list *lst, void (*del)(void*))` | Deletes a single node using `del` to free its content |
| `ft_lstclear(t_list **lst, void (*del)(void*))` | Deletes and frees all nodes in the list |
| `ft_lstiter(t_list *lst, void (*f)(void *))` | Applies function `f` to the content of every node |
| `ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))` | Creates a new list by applying `f` to each node's content; uses `del` on failure |

---

## Instructions

### Compilation

Clone the repository and run `make` at the root:

```bash
git clone <your-repo-url>
cd libft
make
```

This produces `libft.a`, the static library file.

### Available Make Rules

```bash
make        # Compile the library (libft.a)
make clean  # Remove object files
make fclean # Remove object files and libft.a
make re     # fclean + make
```

### Using the Library in Your Project

Include the header and link against the library when compiling:

```bash
#include "libft.h"
```

```bash
gcc main.c -L. -lft -o my_program
```

---

## Resources

### Documentation & References

- [C Standard Library Reference — cppreference.com](https://en.cppreference.com/w/c)
- [GNU C Library Manual](https://www.gnu.org/software/libc/manual/)
- [Makefile Tutorial](https://makefiletutorial.com/)
- [Beej's Guide to C Programming](https://beej.us/guide/bgc/)
- [42 Norm — the coding standard enforced at 42 school](https://github.com/42School/norminette)




- **Concept clarification** — understanding how functions like `ft_memmove` differ from `ft_memcpy`, and how pointer-to-pointer (`**`) works in linked list operations
- **Debugging assistance** — identifying edge cases and memory leak patterns (e.g. proper cleanup in `ft_lstmap` on allocation failure)
- **README writing** — drafting and structuring this README file

AI was used strictly as a learning and documentation tool. All code was written and understood independently, in compliance with the 42 academic integrity policy.
