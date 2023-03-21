# Brainstorm

## But

Le but est de faire une application qui simule la commande bash `< file1 cmd1 | cmd2 > file2`. Le programme doit être appeler comme suite : `./pipex file1 cmd1 cmd2 file2`.

## < file1 cmd1 | cmd2 > file2

- `< file1` - Il s'agit de la redirection d'entrée, cela signifie que le contenu du fichier `file1` sera utilisé comme entrée pour la commande suivante `cmd1`.
- `cmd1` - Il s'agit de la première commande qui sera exécutée. Elle prendra l'entrée de `file1` et effectuera une opération sur celle-ci.
- `|` - C'est le symbole pipe, cela signifie que la sortie de `cmd1` sera utilisée comme entrée pour la commande suivante `cmd2`.
- `cmd2` - Il s'agit de la deuxième commande qui sera exécutée. Elle prendra la sortie de `cmd1` et effectuera une opération sur celle-ci.
- `> file2` - Il s'agit de la redirection de sortie, cela signifie que la sortie de `cmd2` sera enregistrée dans le fichier `file2`.

En résumé, cette commande prend le contenu de `file1` et le fait passer par deux commandes `cmd1` et `cmd2`, avant de sauvegarder la sortie finale dans `file2`.

## Opérateurs de redirection

- `>` : Redirection de sortie standard vers un fichier.
    >Exemple : `ls > fichier.txt` permet de stocker la liste des fichiers du répertoire courant dans un fichier nommé `fichier.txt`.

- `>>` : Ajout de la sortie standard à la fin d'un fichier existant.
    >Exemple : `echo "Hello World" >> fichier.txt` permet d'ajouter la chaîne de caractères "Hello World" à la fin du fichier `fichier.txt`.

- `<` : Redirection d'un fichier vers l'entrée standard d'une commande.
    >Exemple : `sort < fichier.txt` permet de trier le contenu du fichier `fichier.txt`.

- `2>` : Redirection de la sortie d'erreur standard vers un fichier.
    >Exemple : `ls fakefile 2> erreur.txt` permet de stocker l'erreur "No such file or directory" dans un fichier nommé `erreur.txt`.

- `2>>` : Ajout de la sortie d'erreur standard à la fin d'un fichier existant.
    >Exemple : `commande_inconnue 2>> erreurs.txt` permet d'ajouter le message d'erreur "commande_inconnue : command not found" à la fin du fichier `erreurs.txt`.

- `&>` ou `>&` : Redirection de la sortie standard et d'erreur standard vers un fichier.
    >Exemple : `commande &> log.txt` permet de stocker à la fois la sortie standard et d'erreur standard de la commande `commande` dans un fichier nommé `log.txt`.

- `|` : Redirection de la sortie d'une commande vers l'entrée d'une autre commande.
    >Exemple : `ls | grep "fichier"` permet de rechercher tous les fichiers contenant "fichier" dans le répertoire courant.

## Fonctions externes autorisées

- open()
- close()
- read()
- write()
- malloc()
- free()
- *perror()
- *strerror()
- *access()
- *dup()
- *dup2()
- *execve()
- exit()
- *fork()
- *pipe()
- *unlink()
- *wait()
- *waitpid()
- ft_printf()

>`*` = fonctions que je ne connais pas et que je n'ai jamais utiliser
