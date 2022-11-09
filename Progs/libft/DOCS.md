# 1. LIBFT Documentation

- [1. LIBFT Documentation](#1-libft-documentation)
	- [1.1. ft_atoi()](#11-ft_atoi)
		- [1.1.1. Synopsis](#111-synopsis)
		- [1.1.2. Description](#112-description)
		- [1.1.3. Return value](#113-return-value)
		- [1.1.4. Exemples](#114-exemples)
	- [1.2. ft_bzero()](#12-ft_bzero)
		- [1.2.1. Synopsis](#121-synopsis)
		- [1.2.2. Description](#122-description)
		- [1.2.3. Return value](#123-return-value)
		- [1.2.4. Exemples](#124-exemples)
	- [1.3. ft_calloc()](#13-ft_calloc)
		- [1.3.1. Synopsis](#131-synopsis)
		- [1.3.2. Description](#132-description)
		- [1.3.3. Return value](#133-return-value)
		- [1.3.4. Exemples](#134-exemples)
	- [1.4. ft_isalnum()](#14-ft_isalnum)
		- [1.4.1. Synopsis](#141-synopsis)
		- [1.4.2. Description](#142-description)
		- [1.4.3. Return value](#143-return-value)
		- [1.4.4. Exemples](#144-exemples)
	- [1.5. ft_isalpha()](#15-ft_isalpha)
		- [1.5.1. Synopsis](#151-synopsis)
		- [1.5.2. Description](#152-description)
		- [1.5.3. Return value](#153-return-value)
		- [1.5.4. Exemples](#154-exemples)
	- [1.6. ft_isascii()](#16-ft_isascii)
		- [1.6.1. Synopsis](#161-synopsis)
		- [1.6.2. Description](#162-description)
		- [1.6.3. Return value](#163-return-value)
		- [1.6.4. Exemples](#164-exemples)
	- [1.7. ft_isdigit()](#17-ft_isdigit)
		- [1.7.1. Synopsis](#171-synopsis)
		- [1.7.2. Description](#172-description)
		- [1.7.3. Return value](#173-return-value)
		- [1.7.4. Exemples](#174-exemples)
	- [1.8. ft_isprint()](#18-ft_isprint)
		- [1.8.1. Synopsis](#181-synopsis)
		- [1.8.2. Description](#182-description)
		- [1.8.3. Return value](#183-return-value)
		- [1.8.4. Exemples](#184-exemples)
	- [1.9. ft_itoa()](#19-ft_itoa)
		- [1.9.1. Synopsis](#191-synopsis)
		- [1.9.2. Description](#192-description)
		- [1.9.3. Return value](#193-return-value)
		- [1.9.4. Exemples](#194-exemples)
	- [1.10. ft_lstadd_back()](#110-ft_lstadd_back)
		- [1.10.1. Synopsis](#1101-synopsis)
		- [1.10.2. Description](#1102-description)
		- [1.10.3. Return value](#1103-return-value)
		- [1.10.4. Exemple](#1104-exemple)
	- [1.11. ft_lstadd_front()](#111-ft_lstadd_front)
		- [1.11.1. Synopsis](#1111-synopsis)
		- [1.11.2. Description](#1112-description)
		- [1.11.3. Return value](#1113-return-value)
		- [1.11.4. Exemples](#1114-exemples)
	- [1.12. ft_lstclear()](#112-ft_lstclear)
		- [1.12.1. Synopsis](#1121-synopsis)
		- [1.12.2. Description](#1122-description)
		- [1.12.3. Return value](#1123-return-value)
	- [1.13. ft_lstdelone()](#113-ft_lstdelone)
		- [1.13.1. Synopsis](#1131-synopsis)
		- [1.13.2. Description](#1132-description)
		- [1.13.3. Return value](#1133-return-value)
		- [1.13.4. Exemples](#1134-exemples)
	- [1.14. ft_lstiter()](#114-ft_lstiter)
		- [1.14.1. Synopsis](#1141-synopsis)
		- [1.14.2. Description](#1142-description)
		- [1.14.3. Return value](#1143-return-value)
	- [1.15. ft_lstlast()](#115-ft_lstlast)
		- [1.15.1. Synopsis](#1151-synopsis)
		- [1.15.2. Description](#1152-description)
		- [1.15.3. Return value](#1153-return-value)
		- [1.15.4. Exemples](#1154-exemples)
	- [1.16. ft_lstmap()](#116-ft_lstmap)
		- [1.16.1. Synopsis](#1161-synopsis)
		- [1.16.2. Description](#1162-description)
		- [1.16.3. Return value](#1163-return-value)
	- [1.17. ft_lstnew()](#117-ft_lstnew)
		- [1.17.1. Synopsis](#1171-synopsis)
		- [1.17.2. Description](#1172-description)
		- [1.17.3. Return value](#1173-return-value)
		- [1.17.4. Exemple](#1174-exemple)
	- [1.18. ft_lstsize()](#118-ft_lstsize)
		- [1.18.1. Synopsis](#1181-synopsis)
		- [1.18.2. Description](#1182-description)
		- [1.18.3. Return value](#1183-return-value)
		- [1.18.4. Exemples](#1184-exemples)
	- [1.19. ft_memchr()](#119-ft_memchr)
		- [1.19.1. Synopsis](#1191-synopsis)
		- [1.19.2. Description](#1192-description)
		- [1.19.3. Return value](#1193-return-value)
	- [1.20. ft_memcmp()](#120-ft_memcmp)
		- [1.20.1. Synopsis](#1201-synopsis)
		- [1.20.2. Description](#1202-description)
		- [1.20.3. Return value](#1203-return-value)
	- [1.21. ft_memcpy()](#121-ft_memcpy)
		- [1.21.1. Synopsis](#1211-synopsis)
		- [1.21.2. Description](#1212-description)
		- [1.21.3. Return value](#1213-return-value)
	- [1.22. ft_memmove()](#122-ft_memmove)
		- [1.22.1. Synopsis](#1221-synopsis)
		- [1.22.2. Description](#1222-description)
		- [1.22.3. Return value](#1223-return-value)
	- [1.23. ft_memset()](#123-ft_memset)
		- [1.23.1. Synopsis](#1231-synopsis)
		- [1.23.2. Description](#1232-description)
		- [1.23.3. Return value](#1233-return-value)
	- [1.24. ft_putchar_fd()](#124-ft_putchar_fd)
		- [1.24.1. Synopsis](#1241-synopsis)
		- [1.24.2. Description](#1242-description)
		- [1.24.3. Return value](#1243-return-value)
	- [1.25. ft_putendl_fd()](#125-ft_putendl_fd)
		- [1.25.1. Synopsis](#1251-synopsis)
		- [1.25.2. Description](#1252-description)
		- [1.25.3. Return value](#1253-return-value)
	- [1.26. ft_putnbr_fd()](#126-ft_putnbr_fd)
		- [1.26.1. Synopsis](#1261-synopsis)
		- [1.26.2. Description](#1262-description)
		- [1.26.3. Return value](#1263-return-value)
	- [1.27. ft_putstr_fd()](#127-ft_putstr_fd)
		- [1.27.1. Synopsis](#1271-synopsis)
		- [1.27.2. Description](#1272-description)
		- [1.27.3. Return value](#1273-return-value)
	- [1.28. ft_split()](#128-ft_split)
		- [1.28.1. Synopsis](#1281-synopsis)
		- [1.28.2. Description](#1282-description)
		- [1.28.3. Return value](#1283-return-value)
	- [1.29. ft_strchr()](#129-ft_strchr)
		- [1.29.1. Synopsis](#1291-synopsis)
		- [1.29.2. Description](#1292-description)
		- [1.29.3. Return value](#1293-return-value)
	- [1.30. ft_strdup()](#130-ft_strdup)
		- [1.30.1. Synopsis](#1301-synopsis)
		- [1.30.2. Description](#1302-description)
		- [1.30.3. Return value](#1303-return-value)
	- [1.31. ft_striteri()](#131-ft_striteri)
		- [1.31.1. Synopsis](#1311-synopsis)
		- [1.31.2. Description](#1312-description)
		- [1.31.3. Return value](#1313-return-value)
	- [1.32. ft_strjoin()](#132-ft_strjoin)
		- [1.32.1. Synopsis](#1321-synopsis)
		- [1.32.2. Description](#1322-description)
		- [1.32.3. Return value](#1323-return-value)
	- [1.33. ft_strlcat()](#133-ft_strlcat)
		- [1.33.1. Synopsis](#1331-synopsis)
		- [1.33.2. Description](#1332-description)
		- [1.33.3. Return value](#1333-return-value)
	- [1.34. ft_strlcpy()](#134-ft_strlcpy)
		- [1.34.1. Synopsis](#1341-synopsis)
		- [1.34.2. Description](#1342-description)
		- [1.34.3. Return value](#1343-return-value)
	- [1.35. ft_strlen()](#135-ft_strlen)
		- [1.35.1. Synopsis](#1351-synopsis)
		- [1.35.2. Description](#1352-description)
		- [1.35.3. Return value](#1353-return-value)
	- [1.36. ft_strmapi()](#136-ft_strmapi)
		- [1.36.1. Synopsis](#1361-synopsis)
		- [1.36.2. Description](#1362-description)
		- [1.36.3. Return value](#1363-return-value)
	- [1.37. strncmp()](#137-strncmp)
		- [1.37.1. Synopsis](#1371-synopsis)
		- [1.37.2. Description](#1372-description)
		- [1.37.3. Return value](#1373-return-value)
	- [1.38. strnstr()](#138-strnstr)
		- [1.38.1. Synopsis](#1381-synopsis)
		- [1.38.2. Description](#1382-description)
		- [1.38.3. Return value](#1383-return-value)
	- [1.39. ft_strrchr()](#139-ft_strrchr)
		- [1.39.1. Synopsis](#1391-synopsis)
		- [1.39.2. Description](#1392-description)
		- [1.39.3. Return value](#1393-return-value)
	- [1.40. ft_strtrim()](#140-ft_strtrim)
		- [1.40.1. Synopsis](#1401-synopsis)
		- [1.40.2. Description](#1402-description)
		- [1.40.3. Return value](#1403-return-value)
	- [1.41. ft_substr()](#141-ft_substr)
		- [1.41.1. Synopsis](#1411-synopsis)
		- [1.41.2. Description](#1412-description)
		- [1.41.3. Return value](#1413-return-value)
	- [1.42. ft_tolower()](#142-ft_tolower)
		- [1.42.1. Synopsis](#1421-synopsis)
		- [1.42.2. Description](#1422-description)
		- [1.42.3. Return value](#1423-return-value)
	- [1.43. ft_toupper()](#143-ft_toupper)
		- [1.43.1. Synopsis](#1431-synopsis)
		- [1.43.2. Description](#1432-description)
		- [1.43.3. Return value](#1433-return-value)

## 1.1. ft_atoi()

### 1.1.1. Synopsis

`int ft_atoi(const char *nptr);`.

### 1.1.2. Description

The function `ft_atoi()` converts the beginning of the string pointed by `nptr` into an integer of type `int`.

### 1.1.3. Return value

The result of the conversion or 0 in case of error.

### 1.1.4. Exemples

```c
char *str1 = "12345";
char *str2 = "-42";
char *str3 = "+2222";
int resp;

resp = ft_atoi(str1);
printf("str \"%s\" = int %d\n", str1, resp);
resp = ft_atoi(str2);
printf("str \"%s\" = int %d\n", str2, resp);
resp = ft_atoi(str3);
printf("str \"%s\" = int %d\n", str3, resp);
```

```bash
str "12345" = int 12345
str "-42" = int -42
str "+2222" = int 2222
```

## 1.2. ft_bzero()

### 1.2.1. Synopsis

`void ft_bzero(void *s, size_t n);`.

### 1.2.2. Description

The `ft_bzero()` function erases the data in the `n` bytes of the memory starting at the location pointed to by `s`, by writing zeros (bytes containing '\0') to that area.

### 1.2.3. Return value

None.

### 1.2.4. Exemples

```c
char buf[10];
int i;

ft_bzero(buf, sizeof(buf));
i = 0;
while (i != sizeof(buf))
{
	printf("buf[%d] (char) : %c | (int) : %d\n", i, buf[i], buf[i]);
	i++;
}
```

```bash
buf[0] (char) :  | (int) : 0
buf[1] (char) :  | (int) : 0
buf[2] (char) :  | (int) : 0
buf[3] (char) :  | (int) : 0
buf[4] (char) :  | (int) : 0
buf[5] (char) :  | (int) : 0
buf[6] (char) :  | (int) : 0
buf[7] (char) :  | (int) : 0
buf[8] (char) :  | (int) : 0
buf[9] (char) :  | (int) : 0
```

## 1.3. ft_calloc()

### 1.3.1. Synopsis

`void *ft_calloc(size_t nmemb, size_t size);`.

### 1.3.2. Description

The `ft_calloc()` function allocates memory for an array of `nmemb` elements. The memory is set to zero. If `nmemb` or `size` is 0, then `ft_calloc()` returns either NULL, or a unique pointer value that can later be sucessfully passed to free(). If the multiplication of `nmemb`and `size` would result in integer overflow, then `ft_calloc()` return an error. By contrast, an integer overflow would not be detected in the following call to malloc(), with the result that an incorrectly sized block of memory would be allocated : `malloc(nmemb * size);`.

### 1.3.3. Return value

The `ft_calloc()` function return a pointer to the allocated memory, which is suitably aligned for any build-in type. On error, these function return NULL. NULL may also be returned by a successful call to `ft_calloc()` with `nmemb` or `size` equal to zero.

### 1.3.4. Exemples

```c
int *ptri;
int i;

ptri = (int *)ft_calloc(10, sizeof(int));
i = 0;
while (i < 10)
{
	printf("ptri[%d] = (char) : %c | (int) : %d\n", i, ptri[i], ptri[i]);
	i++;
}
free(ptri);
```

```bash
ptri[0] = (char) :  | (int) : 0
ptri[1] = (char) :  | (int) : 0
ptri[2] = (char) :  | (int) : 0
ptri[3] = (char) :  | (int) : 0
ptri[4] = (char) :  | (int) : 0
ptri[5] = (char) :  | (int) : 0
ptri[6] = (char) :  | (int) : 0
ptri[7] = (char) :  | (int) : 0
ptri[8] = (char) :  | (int) : 0
ptri[9] = (char) :  | (int) : 0
```

## 1.4. ft_isalnum()

### 1.4.1. Synopsis

`int ft_isalnum(int c);`.

### 1.4.2. Description

The `ft_isalnum()` function checks for an alphanumeric character. It's equivalent to `(ft_isalpha(c) || isdigit(c))`.

### 1.4.3. Return value

The values returned are nonzero if the character `c` falls into the tested class, and zero if not.

### 1.4.4. Exemples

```c
int resp;

resp = ft_isalnum('a');
printf("ft_isalnum('a') = %d\n", resp);
resp = ft_isalnum('9');
printf("ft_isalnum('9') = %d\n", resp);
resp = ft_isalnum('+');
printf("ft_isalnum('+') = %d\n", resp);
```

```bash
ft_isalnum('a') = 8
ft_isalnum('9') = 8
ft_isalnum('+') = 0
```

## 1.5. ft_isalpha()

### 1.5.1. Synopsis

`int ft_isalpha(int c);`.

### 1.5.2. Description

The `ft_isalpha()` function checks for an alphabetic character, It's equivalent to `(ft_isupper(c) || ft_islower(c))`.

### 1.5.3. Return value

The values returned are nonzero if the character `c` falls into the tested class, and zero if not.

### 1.5.4. Exemples

```c
int resp;

resp = ft_isalpha('a');
printf("ft_isalpha('a') = %d\n", resp);
resp = ft_isalpha('9');
printf("ft_isalpha('9') = %d\n", resp);
```

```bash
ft_isalpha('a') = 1024
ft_isalpha('9') = 0
```

## 1.6. ft_isascii()

### 1.6.1. Synopsis

`int ft_isascii(int c);`.

### 1.6.2. Description

The `ft_isascii()` function checks whether `c` is a 7-bit `unsigned char` value that fits into the ASCII character set.

### 1.6.3. Return value

The values returned are nonzero if the character `c` falls into the tested class, and zero if not.

### 1.6.4. Exemples

```c
int resp;

resp = ft_isascii('a');
printf("ft_isascii('a') = %d\n", resp);
resp = ft_isascii('+');
printf("ft_isascii('+') = %d\n", resp);
resp = ft_isascii(128);
printf("ft_isascii(128) = %d\n", resp);
```

```bash
ft_isascii('a') = 1
ft_isascii('+') = 1
ft_isascii(128) = 0
```

## 1.7. ft_isdigit()

### 1.7.1. Synopsis

`int ft_isdigit(int c);`.

### 1.7.2. Description

The `ft_isdigit()` function checks for a digit (0 through 9).

### 1.7.3. Return value

The values returned are nonzero if the character `c` falls into the tested class, and zero if not.

### 1.7.4. Exemples

```c
int resp;

resp = ft_isdigit('2');
printf("ft_isdigit('2') = %d\n", resp);
resp = ft_isdigit('a');
printf("ft_isdigit('a') = %d\n", resp);
```

```bash
ft_isdigit('2') = 2048
ft_isdigit('a') = 0
```

## 1.8. ft_isprint()

### 1.8.1. Synopsis

`int ft_isprint(int c);`.

### 1.8.2. Description

The `ft_isprint()` function checks for any printable character including space.

### 1.8.3. Return value

The values returned are nonzero if the character `c` falls into the tested class, and zero if not.

### 1.8.4. Exemples

```c
int resp;

resp = ft_isprint('a');
printf("ft_isprint('a') = %d\n", resp);
resp = ft_isprint(' ');
printf("ft_isprint('a') = %d\n", resp);
resp = ft_isprint(22);
printf("ft_isprint(22) = %d\n", resp);
```

```bash
ft_isprint('a') = 16384
ft_isprint('a') = 16384
ft_isprint(22) = 0
```

## 1.9. ft_itoa()

### 1.9.1. Synopsis

`char *ft_itoa(int n);`.

### 1.9.2. Description

Allocate with malloc and return a string representing the integer `n` received as an argument. Negative numbers are handled.

### 1.9.3. Return value

The string representing the integer. NULL if the allaction fails.

### 1.9.4. Exemples

```c
char *resp;
int positive = 12345;
int negative = -12345;

resp = ft_itoa(positive);
printf("int %d = str \"%s\"\n", positive, resp);
resp = ft_itoa(negative);
printf("int %d = str \"%s\"\n", negative, resp);
```

```bash
int 12345 = str "12345"
int -12345 = str "-12345"
```

## 1.10. ft_lstadd_back()

### 1.10.1. Synopsis

`void ft_lstadd_back(t_list **lst, t_list *new);`.

### 1.10.2. Description

Adds the element `new` at the end of the list.

### 1.10.3. Return value

None.

### 1.10.4. Exemple

```c
t_list *el;
t_list *first_el;
int cint;
int cint2;
char cchar;

el = NULL;
cint = 42;
cint2 = 21;
cchar = 'a';
ft_lstadd_front(&el, ft_lstnew((void *)&cint));
ft_lstadd_front(&el, ft_lstnew((void *)&cchar));
ft_lstadd_back(&el, ft_lstnew((void *)&cint2));
printf("el->content = %c | el->next = %p\n", *(char *)el->content, el->next);
first_el = el;
el = ft_lstlast(el);
printf("el->content = %d | el->next = %p\n", *(int *)el->content, el->next);
ft_lstclear(&first_el, del);
```

```bash
el->content = a | el->next = 0xf412a0
el->content = 21 | el->next = (nil)
```

## 1.11. ft_lstadd_front()

### 1.11.1. Synopsis

`void ft_lstadd_front(t_list **lst, t_list *new);`.

### 1.11.2. Description

Add the `new` element at the beginning of the list.

### 1.11.3. Return value

None.

### 1.11.4. Exemples

```c
t_list *el;
t_list *first_el;
int cint;
char cchar;

el = NULL;
cint = 42;
cchar = 'a';
ft_lstadd_front(&el, ft_lstnew((void *)&cint));
ft_lstadd_front(&el, ft_lstnew((void *)&cchar));
printf("el->content = %c | el->next = %p\n", *(char *)el->content, el->next);
first_el = el;
el = el->next;
printf("el->content = %d | el->next = %p\n", *(char *)el->content, el->next);
ft_lstclear(&first_el, del);
```

```bash
el->content = a | el->next = 0x172f2a0
el->content = 42 | el->next = (nil)
```

## 1.12. ft_lstclear()

### 1.12.1. Synopsis

### 1.12.2. Description

### 1.12.3. Return value

## 1.13. ft_lstdelone()

### 1.13.1. Synopsis

`void ft_lstdelone(t_list *lst, void (*del)(void *));`.

### 1.13.2. Description

Free the memory of the element passed as argument by using the `del` function then with free. The memory of `next` must not be free.

### 1.13.3. Return value

None.

### 1.13.4. Exemples

```c
t_list *el;
int cint;

el = NULL;
cint = 42;
ft_lstadd_front(&el, ft_lstnew((void *)&cint));	ft_lstdelone(el, del);
```

## 1.14. ft_lstiter()

### 1.14.1. Synopsis

### 1.14.2. Description

### 1.14.3. Return value

## 1.15. ft_lstlast()

### 1.15.1. Synopsis

`t_list *ft_lstlast(t_list *lst);`.

### 1.15.2. Description

Returns the last element of the list.

### 1.15.3. Return value

Last item in the list

### 1.15.4. Exemples

```c
t_list *el;
t_list *first_el;
int cint;
int cint2;
char cchar;

el = NULL;
cint = 42;
cint2 = 21;
cchar = 'a';
ft_lstadd_front(&el, ft_lstnew((void *)&cint));
ft_lstadd_front(&el, ft_lstnew((void *)&cchar));
ft_lstadd_front(&el, ft_lstnew((void *)&cint2));
printf("el->content = %d | el->next = %p\n", *(int *)el->content, el->next);
first_el = el;
el = ft_lstlast(el);
printf("el->content = %d | el->next = %p\n", *(int *)el->content, el->next);
ft_lstclear(&first_el, del);
```

```bash
el->content = 21 | el->next = 0x10b22c0
el->content = 42 | el->next = (nil)
```

## 1.16. ft_lstmap()

### 1.16.1. Synopsis

### 1.16.2. Description

### 1.16.3. Return value

## 1.17. ft_lstnew()

### 1.17.1. Synopsis

`t_list *ft_lstnew(void *content);`.

### 1.17.2. Description

Allocate with malloc() and returns a new element. The member variable `content` is initialized with the value of the `content` parameter. The variable `next` is initialized to NULL.

### 1.17.3. Return value

The new element.

### 1.17.4. Exemple

```c
int cint;
int cchar;
t_list *el1;
t_list *el2;

cint = 42;
cchar = 'a';
el1 = ft_lstnew((void *)&cint);
el2 = ft_lstnew((void *)&cchar);
printf("el1->content = %d | el1->next = %p\n", *(int *)el1->content, el1->next);
printf("el2->content = %d | el2->next = %p\n", *(int *)el2->content, el2->next);
ft_lstclear(&el1, del);
ft_lstclear(&el2, del);
```

```bash
el1->content = 42 | el1->next = (nil)
el2->content = 97 | el2->next = (nil)
```

## 1.18. ft_lstsize()

### 1.18.1. Synopsis

`int ft_lstsize(t_list *lst);`.

### 1.18.2. Description

Count the number of items in the list.

### 1.18.3. Return value

Size of the list.

### 1.18.4. Exemples

```c
t_list *el;
int cint;
char cchar;

el = NULL;
cint = 42;
cchar = 'a';
ft_lstadd_front(&el, ft_lstnew((void *)&cint));
ft_lstadd_front(&el, ft_lstnew((void *)&cchar));
printf("List size : %d\n", ft_lstsize(el));
```

```bash
List size : 2
```

## 1.19. ft_memchr()

### 1.19.1. Synopsis

### 1.19.2. Description

### 1.19.3. Return value

## 1.20. ft_memcmp()

### 1.20.1. Synopsis

### 1.20.2. Description

### 1.20.3. Return value

## 1.21. ft_memcpy()

### 1.21.1. Synopsis

### 1.21.2. Description

### 1.21.3. Return value

## 1.22. ft_memmove()

### 1.22.1. Synopsis

### 1.22.2. Description

### 1.22.3. Return value

## 1.23. ft_memset()

### 1.23.1. Synopsis

### 1.23.2. Description

### 1.23.3. Return value

## 1.24. ft_putchar_fd()

### 1.24.1. Synopsis

### 1.24.2. Description

### 1.24.3. Return value

## 1.25. ft_putendl_fd()

### 1.25.1. Synopsis

### 1.25.2. Description

### 1.25.3. Return value

## 1.26. ft_putnbr_fd()

### 1.26.1. Synopsis

### 1.26.2. Description

### 1.26.3. Return value

## 1.27. ft_putstr_fd()

### 1.27.1. Synopsis

### 1.27.2. Description

### 1.27.3. Return value

## 1.28. ft_split()

### 1.28.1. Synopsis

### 1.28.2. Description

### 1.28.3. Return value

## 1.29. ft_strchr()

### 1.29.1. Synopsis

### 1.29.2. Description

### 1.29.3. Return value

## 1.30. ft_strdup()

### 1.30.1. Synopsis

### 1.30.2. Description

### 1.30.3. Return value

## 1.31. ft_striteri()

### 1.31.1. Synopsis

### 1.31.2. Description

### 1.31.3. Return value

## 1.32. ft_strjoin()

### 1.32.1. Synopsis

### 1.32.2. Description

### 1.32.3. Return value

## 1.33. ft_strlcat()

### 1.33.1. Synopsis

### 1.33.2. Description

### 1.33.3. Return value

## 1.34. ft_strlcpy()

### 1.34.1. Synopsis

### 1.34.2. Description

### 1.34.3. Return value

## 1.35. ft_strlen()

### 1.35.1. Synopsis

### 1.35.2. Description

### 1.35.3. Return value

## 1.36. ft_strmapi()

### 1.36.1. Synopsis

### 1.36.2. Description

### 1.36.3. Return value

## 1.37. strncmp()

### 1.37.1. Synopsis

### 1.37.2. Description

### 1.37.3. Return value

## 1.38. strnstr()

### 1.38.1. Synopsis

### 1.38.2. Description

### 1.38.3. Return value

## 1.39. ft_strrchr()

### 1.39.1. Synopsis

### 1.39.2. Description

### 1.39.3. Return value

## 1.40. ft_strtrim()

### 1.40.1. Synopsis

### 1.40.2. Description

### 1.40.3. Return value

## 1.41. ft_substr()

### 1.41.1. Synopsis

### 1.41.2. Description

### 1.41.3. Return value

## 1.42. ft_tolower()

### 1.42.1. Synopsis

### 1.42.2. Description

### 1.42.3. Return value

## 1.43. ft_toupper()

### 1.43.1. Synopsis

### 1.43.2. Description

### 1.43.3. Return value
