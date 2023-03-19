# GNU Debugger

## Introduction

GDB est un debeggeur libre développé par GNU. Il va être très utile pour debugger nos programme C/C++. Afin de pouvoir l'utiliser, il faut compiler le programme avec le flag `-g`.

Une fois que le binaire est prêt, nous pouvons lancer GDB avec la commande `gdb <path_binary>`. C'est un outils en ligne de commande interactive. Pour pouvoir le controler il faut donc utiliser des commandes. Je vais en lister une partie ici.

## Break

Break permet d'ajouter des points d'arret lors de l'exécution de notre programme. Afin d'indiquer a break ou il doit aretter le prgramme, nous devons lui donner un nom de fonction ou un numéro de ligne. Nous pouvons ajouter plusieurs point d'arret à notre programme. Souvant, une des première nous que nous faisons an lancant GDB c'est de mettre un point d'arret un début du programme.

```bash
break main
```

Ici, nous vennons d'ajouter un point d'arret au début de notre programme (l'appel de la fonction main).

## Clear

Clear permet de supprimer des points d'arret que nous avons ajouter. Pour ce faire, il suffit de donner a clear le nom de la fonction ou le numéro de la ligne du point d arret que nous voulons supprimer.

```bash
clear main
```

Nous supprimons le points d'arret que nous avons ajouté plus haut.

## Watch

La commande watch permet de suivre l'état d'une variable. Une fois qu'une variable est suivie, GDB va vous afficher sa nouvelle valeur chaque fois que cette dernière est modifiée.

```bash
watch tmp
```

Chaque fois que la variable tmp sera modifiée, GDB affichera sa valeur.

## Run

Run permet de lancer l'exécution du programme. Une fois que le prgramme est lancé, son n'exécution s'arretera lors d'un point d'arret ou quand l exécution est terminée.

```bash
run
```

## Print

La commande print permet d'afficher la valeur d'une variable.

```bash
print tmp
```

Affiche le contenu de la variable tmp.

## Step

Step demande au debugger d'entré dans la fonction sur la ligne active et donc de voir le déroullement de l'appel à la fonction.

```bash
step
```

## Next

Next demande au débuggeur de passer à la ligne suivant sans entrée dans la fonction et donc de ne pas afficher le détail de l exécution de la fonction.

```bash
next
```

## Continue

Continue le programme jusqu'au prochain point d'arret.

```bash
continue
```

## List

La commande list permet d'afficher le code que nous somme entrain de debugger. Il faut lui donner un numéro de ligne.

```bash
list 35
```

Affiche le code à la ligne 35 est le quelque lignes qui suivent.

## Quit

Permt de quitter GDB.

```bash
quit
```
