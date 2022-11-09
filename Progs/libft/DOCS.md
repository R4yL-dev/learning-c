# 1. LIBFT Documentation

## 1.1. TOC

- [1. LIBFT Documentation](#1-libft-documentation)
	- [1.1. TOC](#11-toc)
	- [1.2. ft_atoi()](#12-ft_atoi)
		- [1.2.1. Synopsis](#121-synopsis)
		- [1.2.2. Description](#122-description)
		- [1.2.3. Return value](#123-return-value)
	- [1.3. ft_bzero()](#13-ft_bzero)
		- [1.3.1. Synopsis](#131-synopsis)
		- [1.3.2. Description](#132-description)
		- [1.3.3. Return value](#133-return-value)
	- [1.4. ft_calloc()](#14-ft_calloc)
		- [1.4.1. Synopsis](#141-synopsis)
		- [1.4.2. Description](#142-description)
		- [1.4.3. Return value](#143-return-value)
	- [1.5. ft_isalnum()](#15-ft_isalnum)
		- [1.5.1. Synopsis](#151-synopsis)
		- [1.5.2. Description](#152-description)
		- [1.5.3. Return value](#153-return-value)
	- [1.6. ft_isalpha()](#16-ft_isalpha)
		- [1.6.1. Synopsis](#161-synopsis)
		- [1.6.2. Description](#162-description)
		- [1.6.3. Return value](#163-return-value)
	- [1.7. ft_isascii()](#17-ft_isascii)
		- [1.7.1. Synopsis](#171-synopsis)
		- [1.7.2. Description](#172-description)
		- [1.7.3. Return value](#173-return-value)
	- [1.8. ft_isdigit()](#18-ft_isdigit)
		- [1.8.1. Synopsis](#181-synopsis)
		- [1.8.2. Description](#182-description)
		- [1.8.3. Return value](#183-return-value)
	- [1.9. ft_isprint()](#19-ft_isprint)
		- [1.9.1. Synopsis](#191-synopsis)
		- [1.9.2. Description](#192-description)
		- [1.9.3. Return value](#193-return-value)
	- [1.10. ft_itoa()](#110-ft_itoa)
		- [1.10.1. Synopsis](#1101-synopsis)
		- [1.10.2. Description](#1102-description)
		- [1.10.3. Return value](#1103-return-value)
	- [1.11. ft_lstadd_back()](#111-ft_lstadd_back)
		- [1.11.1. Synopsis](#1111-synopsis)
		- [1.11.2. Description](#1112-description)
		- [1.11.3. Return value](#1113-return-value)
	- [1.12. ft_lstadd_front()](#112-ft_lstadd_front)
		- [1.12.1. Synopsis](#1121-synopsis)
		- [1.12.2. Description](#1122-description)
		- [1.12.3. Return value](#1123-return-value)
	- [1.13. ft_lstclear()](#113-ft_lstclear)
		- [1.13.1. Synopsis](#1131-synopsis)
		- [1.13.2. Description](#1132-description)
		- [1.13.3. Return value](#1133-return-value)
	- [1.14. ft_lstdelone()](#114-ft_lstdelone)
		- [1.14.1. Synopsis](#1141-synopsis)
		- [1.14.2. Description](#1142-description)
		- [1.14.3. Return value](#1143-return-value)
	- [1.15. ft_lstiter()](#115-ft_lstiter)
		- [1.15.1. Synopsis](#1151-synopsis)
		- [1.15.2. Description](#1152-description)
		- [1.15.3. Return value](#1153-return-value)
	- [1.16. ft_lstlast()](#116-ft_lstlast)
		- [1.16.1. Synopsis](#1161-synopsis)
		- [1.16.2. Description](#1162-description)
		- [1.16.3. Return value](#1163-return-value)
	- [1.17. ft_lstmap()](#117-ft_lstmap)
		- [1.17.1. Synopsis](#1171-synopsis)
		- [1.17.2. Description](#1172-description)
		- [1.17.3. Return value](#1173-return-value)
	- [1.18. ft_lstnew()](#118-ft_lstnew)
		- [1.18.1. Synopsis](#1181-synopsis)
		- [1.18.2. Description](#1182-description)
		- [1.18.3. Return value](#1183-return-value)
	- [1.19. ft_lstsize()](#119-ft_lstsize)
		- [1.19.1. Synopsis](#1191-synopsis)
		- [1.19.2. Description](#1192-description)
		- [1.19.3. Return value](#1193-return-value)
	- [1.20. ft_memchr()](#120-ft_memchr)
		- [1.20.1. Synopsis](#1201-synopsis)
		- [1.20.2. Description](#1202-description)
		- [1.20.3. Return value](#1203-return-value)
	- [1.21. ft_memcmp()](#121-ft_memcmp)
		- [1.21.1. Synopsis](#1211-synopsis)
		- [1.21.2. Description](#1212-description)
		- [1.21.3. Return value](#1213-return-value)
	- [1.22. ft_memcpy()](#122-ft_memcpy)
		- [1.22.1. Synopsis](#1221-synopsis)
		- [1.22.2. Description](#1222-description)
		- [1.22.3. Return value](#1223-return-value)
	- [1.23. ft_memmove()](#123-ft_memmove)
		- [1.23.1. Synopsis](#1231-synopsis)
		- [1.23.2. Description](#1232-description)
		- [1.23.3. Return value](#1233-return-value)
	- [1.24. ft_memset()](#124-ft_memset)
		- [1.24.1. Synopsis](#1241-synopsis)
		- [1.24.2. Description](#1242-description)
		- [1.24.3. Return value](#1243-return-value)
	- [1.25. ft_putchar_fd()](#125-ft_putchar_fd)
		- [1.25.1. Synopsis](#1251-synopsis)
		- [1.25.2. Description](#1252-description)
		- [1.25.3. Return value](#1253-return-value)
	- [1.26. ft_putendl_fd()](#126-ft_putendl_fd)
		- [1.26.1. Synopsis](#1261-synopsis)
		- [1.26.2. Description](#1262-description)
		- [1.26.3. Return value](#1263-return-value)
	- [1.27. ft_putnbr_fd()](#127-ft_putnbr_fd)
		- [1.27.1. Synopsis](#1271-synopsis)
		- [1.27.2. Description](#1272-description)
		- [1.27.3. Return value](#1273-return-value)
	- [1.28. ft_putstr_fd()](#128-ft_putstr_fd)
		- [1.28.1. Synopsis](#1281-synopsis)
		- [1.28.2. Description](#1282-description)
		- [1.28.3. Return value](#1283-return-value)
	- [1.29. ft_split()](#129-ft_split)
		- [1.29.1. Synopsis](#1291-synopsis)
		- [1.29.2. Description](#1292-description)
		- [1.29.3. Return value](#1293-return-value)
	- [1.30. ft_strchr()](#130-ft_strchr)
		- [1.30.1. Synopsis](#1301-synopsis)
		- [1.30.2. Description](#1302-description)
		- [1.30.3. Return value](#1303-return-value)
	- [1.31. ft_strdup()](#131-ft_strdup)
		- [1.31.1. Synopsis](#1311-synopsis)
		- [1.31.2. Description](#1312-description)
		- [1.31.3. Return value](#1313-return-value)
	- [1.32. ft_striteri()](#132-ft_striteri)
		- [1.32.1. Synopsis](#1321-synopsis)
		- [1.32.2. Description](#1322-description)
		- [1.32.3. Return value](#1323-return-value)
	- [1.33. ft_strjoin()](#133-ft_strjoin)
		- [1.33.1. Synopsis](#1331-synopsis)
		- [1.33.2. Description](#1332-description)
		- [1.33.3. Return value](#1333-return-value)
	- [1.34. ft_strlcat()](#134-ft_strlcat)
		- [1.34.1. Synopsis](#1341-synopsis)
		- [1.34.2. Description](#1342-description)
		- [1.34.3. Return value](#1343-return-value)
	- [1.35. ft_strlcpy()](#135-ft_strlcpy)
		- [1.35.1. Synopsis](#1351-synopsis)
		- [1.35.2. Description](#1352-description)
		- [1.35.3. Return value](#1353-return-value)
	- [1.36. ft_strlen()](#136-ft_strlen)
		- [1.36.1. Synopsis](#1361-synopsis)
		- [1.36.2. Description](#1362-description)
		- [1.36.3. Return value](#1363-return-value)
	- [1.37. ft_strmapi()](#137-ft_strmapi)
		- [1.37.1. Synopsis](#1371-synopsis)
		- [1.37.2. Description](#1372-description)
		- [1.37.3. Return value](#1373-return-value)
	- [1.38. strncmp()](#138-strncmp)
		- [1.38.1. Synopsis](#1381-synopsis)
		- [1.38.2. Description](#1382-description)
		- [1.38.3. Return value](#1383-return-value)
	- [1.39. strnstr()](#139-strnstr)
		- [1.39.1. Synopsis](#1391-synopsis)
		- [1.39.2. Description](#1392-description)
		- [1.39.3. Return value](#1393-return-value)
	- [1.40. ft_strrchr()](#140-ft_strrchr)
		- [1.40.1. Synopsis](#1401-synopsis)
		- [1.40.2. Description](#1402-description)
		- [1.40.3. Return value](#1403-return-value)
	- [1.41. ft_strtrim()](#141-ft_strtrim)
		- [1.41.1. Synopsis](#1411-synopsis)
		- [1.41.2. Description](#1412-description)
		- [1.41.3. Return value](#1413-return-value)
	- [1.42. ft_substr()](#142-ft_substr)
		- [1.42.1. Synopsis](#1421-synopsis)
		- [1.42.2. Description](#1422-description)
		- [1.42.3. Return value](#1423-return-value)
	- [1.43. ft_tolower()](#143-ft_tolower)
		- [1.43.1. Synopsis](#1431-synopsis)
		- [1.43.2. Description](#1432-description)
		- [1.43.3. Return value](#1433-return-value)
	- [1.44. ft_toupper()](#144-ft_toupper)
		- [1.44.1. Synopsis](#1441-synopsis)
		- [1.44.2. Description](#1442-description)
		- [1.44.3. Return value](#1443-return-value)

## 1.2. ft_atoi()

### 1.2.1. Synopsis

`int ft_atoi(const char *nptr);`

### 1.2.2. Description

### 1.2.3. Return value

## 1.3. ft_bzero()

### 1.3.1. Synopsis

### 1.3.2. Description

### 1.3.3. Return value

## 1.4. ft_calloc()

### 1.4.1. Synopsis

### 1.4.2. Description

### 1.4.3. Return value

## 1.5. ft_isalnum()

### 1.5.1. Synopsis

### 1.5.2. Description

### 1.5.3. Return value

## 1.6. ft_isalpha()

### 1.6.1. Synopsis

### 1.6.2. Description

### 1.6.3. Return value

## 1.7. ft_isascii()

### 1.7.1. Synopsis

### 1.7.2. Description

### 1.7.3. Return value

## 1.8. ft_isdigit()

### 1.8.1. Synopsis

### 1.8.2. Description

### 1.8.3. Return value

## 1.9. ft_isprint()

### 1.9.1. Synopsis

### 1.9.2. Description

### 1.9.3. Return value

## 1.10. ft_itoa()

### 1.10.1. Synopsis

### 1.10.2. Description

### 1.10.3. Return value

## 1.11. ft_lstadd_back()

### 1.11.1. Synopsis

### 1.11.2. Description

### 1.11.3. Return value

## 1.12. ft_lstadd_front()

### 1.12.1. Synopsis

### 1.12.2. Description

### 1.12.3. Return value

## 1.13. ft_lstclear()

### 1.13.1. Synopsis

### 1.13.2. Description

### 1.13.3. Return value

## 1.14. ft_lstdelone()

### 1.14.1. Synopsis

### 1.14.2. Description

### 1.14.3. Return value

## 1.15. ft_lstiter()

### 1.15.1. Synopsis

### 1.15.2. Description

### 1.15.3. Return value

## 1.16. ft_lstlast()

### 1.16.1. Synopsis

### 1.16.2. Description

### 1.16.3. Return value

## 1.17. ft_lstmap()

### 1.17.1. Synopsis

### 1.17.2. Description

### 1.17.3. Return value

## 1.18. ft_lstnew()

### 1.18.1. Synopsis

### 1.18.2. Description

### 1.18.3. Return value

## 1.19. ft_lstsize()

### 1.19.1. Synopsis

### 1.19.2. Description

### 1.19.3. Return value

## 1.20. ft_memchr()

### 1.20.1. Synopsis

### 1.20.2. Description

### 1.20.3. Return value

## 1.21. ft_memcmp()

### 1.21.1. Synopsis

### 1.21.2. Description

### 1.21.3. Return value

## 1.22. ft_memcpy()

### 1.22.1. Synopsis

### 1.22.2. Description

### 1.22.3. Return value

## 1.23. ft_memmove()

### 1.23.1. Synopsis

### 1.23.2. Description

### 1.23.3. Return value

## 1.24. ft_memset()

### 1.24.1. Synopsis

### 1.24.2. Description

### 1.24.3. Return value

## 1.25. ft_putchar_fd()

### 1.25.1. Synopsis

### 1.25.2. Description

### 1.25.3. Return value

## 1.26. ft_putendl_fd()

### 1.26.1. Synopsis

### 1.26.2. Description

### 1.26.3. Return value

## 1.27. ft_putnbr_fd()

### 1.27.1. Synopsis

### 1.27.2. Description

### 1.27.3. Return value

## 1.28. ft_putstr_fd()

### 1.28.1. Synopsis

### 1.28.2. Description

### 1.28.3. Return value

## 1.29. ft_split()

### 1.29.1. Synopsis

### 1.29.2. Description

### 1.29.3. Return value

## 1.30. ft_strchr()

### 1.30.1. Synopsis

### 1.30.2. Description

### 1.30.3. Return value

## 1.31. ft_strdup()

### 1.31.1. Synopsis

### 1.31.2. Description

### 1.31.3. Return value

## 1.32. ft_striteri()

### 1.32.1. Synopsis

### 1.32.2. Description

### 1.32.3. Return value

## 1.33. ft_strjoin()

### 1.33.1. Synopsis

### 1.33.2. Description

### 1.33.3. Return value

## 1.34. ft_strlcat()

### 1.34.1. Synopsis

### 1.34.2. Description

### 1.34.3. Return value

## 1.35. ft_strlcpy()

### 1.35.1. Synopsis

### 1.35.2. Description

### 1.35.3. Return value

## 1.36. ft_strlen()

### 1.36.1. Synopsis

### 1.36.2. Description

### 1.36.3. Return value

## 1.37. ft_strmapi()

### 1.37.1. Synopsis

### 1.37.2. Description

### 1.37.3. Return value

## 1.38. strncmp()

### 1.38.1. Synopsis

### 1.38.2. Description

### 1.38.3. Return value

## 1.39. strnstr()

### 1.39.1. Synopsis

### 1.39.2. Description

### 1.39.3. Return value

## 1.40. ft_strrchr()

### 1.40.1. Synopsis

### 1.40.2. Description

### 1.40.3. Return value

## 1.41. ft_strtrim()

### 1.41.1. Synopsis

### 1.41.2. Description

### 1.41.3. Return value

## 1.42. ft_substr()

### 1.42.1. Synopsis

### 1.42.2. Description

### 1.42.3. Return value

## 1.43. ft_tolower()

### 1.43.1. Synopsis

### 1.43.2. Description

### 1.43.3. Return value

## 1.44. ft_toupper()

### 1.44.1. Synopsis

### 1.44.2. Description

### 1.44.3. Return value
