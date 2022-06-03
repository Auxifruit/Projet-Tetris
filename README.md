# PROJET TÉTRIS PRÉ_ING 1

![alt text](https://github.com/Auxifruit/tetris-projet/blob/image/LOGO.png "Logo tetris CYtech")

## Table des matières
1. [INFORMATIONS GÉNÉRALES](#informations-générales)
2. [UTILISATION](#utilisation)
3. [CRÉATEURS](#créateurs)

## INFORMATIONS GÉNÉRALES

Le but de ce projet est de réaliser un programme permettant de jouer au jeu TETRIS classique depuis le terminal. La particularité de cette version est que le jeu est plus statique que l'original. Nous avons donc écrit le code dans le langage de programmation C sur linux.

## UTILISATION

Pour compilier le programme:
```c
  $ make
```
Pour lancer le programme:
```c
  $ ./tetris
```
### JOUABILITÉ

Vous devez saisir la colonne sur laquelle vous voulez placer votre bloc et son orientation grâce à la fonction:
```c
  void place(tab[TAILLE][TAILLE]);
```
Le bloc est ensuite placer automatiquement dans le tableau, voici un aperçu du tétromino S placé dans la colonne B avec comme orientation 0:

![alt text](https://github.com/Auxifruit/tetris-projet/blob/image/GRID1.png "Exemple tableau")

Le but du jeu est donc de compléter des lignes pour augmenter son score jusqu'à qu'on ne puisse plus placer de blocs par faute de place, c'est-à-dire qu'on ne peut plus rien placer.

À la fin de la partie le score du joueur est enregistré dans un fichier texte avec les scores des autres joueurs, exemple ci-dessous:

![alt text](https://github.com/Auxifruit/tetris-projet/blob/image/GAMEOVER.png "Exemple game over")

## CRÉATEURS

Binôme composé de Tom ALLAGUILLEMETTE et Guillaume BARRÉ en PRÉING 1 GROUPE 7
