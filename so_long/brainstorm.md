# Brainstorm

## Flow

1. Vérifié les arguments
   1. nombre d'arguments
   2. si le chemin est valide
2. Vérifier la carte en mémoire.
   1. GNL sur le fichier dans une string
   2. Vérifié que la carte soit rectangle
   3. Vérifié que la carte soit entourée de mur
   4. Vérifié qu'il y ai le bon nombre de joueur, collectible et sortie.
   5. Vérifié que tous les collectible et sortie soit accésible par le joueur.
3. Traiter la carte en mémoire
   1. Remplacer dans la string les position du joueur, des collectible et de la sortie par du vide.
   2. Mettre la position du joueur, des collectible et de la sortie dans une structure.

## Arguments

Le programme doit prendre un seul argument. Cet argument est le chemin vers un fichier qui se termine par l extention `.ber`. Il faut donc que je check le nombre d'arguments, que je vérifié si l'argument ce termine par `.ber`, que le fichier existe et qu'il soit lisible.

Je veux faire deux fonctions, `parse_args()` qui dois traiter les arguments et `valide_path()` qui vérifie si le chemin passer en argument est valide.

```
int parse_args(argc, argv)
{
	argv--
	argv++
	si argc n'est pas 1
		return error
	sinon
		return ok
}
```

```
int	valide_path(path)
{
	Si path ne fini pas par .ber
		return error
	Si le fichier n'est pas lisible
		return error
	Sinon
		return ok
}
```

## Carte

La carte est composée de 5 éléments :

- `0` pour un espace vide.
- `1` pour un mur.
- `C` pour un collectible.
- `E` pour la sortie.
- `P` pour le joueur.

Pour que la carte soit valide, il y a plusieurs critères :

- Elle doit posséder 1 sortie, 1 joueur et au moins 1 collectible.
- Elle doit être entourée par des murs.
- Elle doit être rectangle (toutes les lignes doivent faire la même longeurs et toute les colonnes aussi).
- Il faut que le player puisse atteidre tous les collectible ainsi que la sortie.

Je veux utiliser une structure pour la carte :

- `char *map` - une string qui contient la maps.
- `int nbrs_rows` - le nombre de lignes.
- `int nbrs_col` - le nombre de colonnes.
- `int player[2]` - un tableau d'int qui représente les coordonées du joueur.
- `int exit[2]` - un tableau d'int qui représente les coordonnées de la sortie.
- `int items[][2]` - un tableau qui des tableaux d'int. Chaque tableau d'int représente les coordonées d'un item.

## Jeux
