# 1. Header file

- [1. Header file](#1-header-file)
	- [1.1. Création d'un header file](#11-création-dun-header-file)
	- [1.2. Inclure le header file](#12-inclure-le-header-file)
	- [1.3. Compilation](#13-compilation)

## 1.1. Création d'un header file

Le *header* est un fichier (*.h*) qui peut être inclus dans nos programmes. Nous mettons dans le fichier header les prototypes de fonctions que nous voulons inclure. Une fois qu'une fonction est présente dans le *header*, elle sera disponible à tous les programmes qui l'inclus.

```c
#ifndef LIBFT_H
#define LIBFT_H

#include <stddef.h>

void    ft_bzero(void *s, size_t n);
int     ft_isalnum(int c);
int     ft_isalpha(int c);
int     ft_isascii(int c);
int     ft_isdigit(int c);
int     ft_isprint(int c);
void    *ft_memcpy(void *dest, const void *src, size_t n);
void    *ft_memset(void *s, int c, size_t n);
size_t  ft_strlen(const char *s);
int     ft_tolower(int c);
int     ft_toupper(int c);

#endif
```

Voici un exemple de fichier *.h*. Nous voyons ici que j'ai listé les prototypes de mes fonctions que je veux rendre accessible.

Les lignes `#ifndef LIBFT_H`, `#define LIBFT_H` et  `endif` sont une protection. Elles disent au préprocesseur que si la bibliothèque est déjà incluse, il ne faut pas la re-inclure. Cela évite les boucles infinie d'include.

La ligne `#include <stddef.h>` est là pour permettre l'utilisation du type *size_t* dans les prototypes de fonction. Il faut faire le strict minimum d'include dans le fichier *.h*. Il ne faut qu'inclure les bibliothèques utile dans le fichier *header*. Ici j'inclus *stddef.h*, car j'en ai besoin pour les prototypes de fonction directement dans le même fichier. Je ne dois, par contre, inclure ici des bibliothèques qui sont utiles dans les fonctions, comme *stdlib.h* par exemple. Il faut inclure ce genre de bibliothèque directement dans les fichiers ou nous en avons besoin. Cela permet de ne pas inclure les bibliothèques par défaut dans tous les fichiers qui utilise notre *.h*. Le faire dans chaque fichier ou cela est utile réduit le temps de compilations et le code inutile dans le binaire final.

## 1.2. Inclure le header file

Maintenant que nous avons créé le fichier *header* avec les prototypes des fonctions que nous voulons utiliser, nous devons adapter les fonctions ainsi que notre main pour utiliser notre *header*. Pour inclure notre *header*, nous devons procéder comme pour les bibliothèques de la libraire standard. Sauf que nous n'allons pas utiliser les caractères `<>` mais les `"`.

```c
#include "libft.h"
#include <stdio.h>

int main(void)
{
    printf("%c\n", ft_toupper('x'));
    return (0);
}
```

```bash
X
```

## 1.3. Compilation

Maintenant que nous avons créé un fichier *header* et que nous avons adapté notre programme afin de l'utiliser, nous allons pouvoir compiler notre projet.

Il nous suffit maintenant de compiler tous les fichiers `.c` que nous avons mis dans notre *header* ainsi que le fichier main.

```bash
gcc -Wall -Werro -Wextra *.c
```

```bash
./a.out > X
```

Nous pouvons constater que notre compilation a bien fonctionneé et que notre fichier main a bien pu utiliser la fonction `ft_toupper()` que nous avons inclus via le fichier *header*.
