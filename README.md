# PROJET TÉTRIS PRÉ_ING 1

![alt text](https://github.com/Auxifruit/tetris-projet/blob/image/LOGO.png "Logo tetris CYtech")

## Table des matières
1. [INFORMATIONS GÉNÉRALES](#informations-générales)
2. [UTILISATION](#utilisation)
3. [CRÉATEURS](#créateurs)

## INFORMATIONS GÉNÉRALES

Le but de ce projet est de réaliser un programme permettant de jouer au jeu TETRIS classique depuis le terminal. La particularité de cette version est que le jeu est plus statique que l'original. Nous avons donc écrit le code dans le langage de programmation C sur linux.

Voici à quoi ressemblera l'interface du jeu:

![alt text](https://github.com/Auxifruit/tetris-projet/blob/image/GRID0.png "Exemple interface")

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

Au lancement du jeu, vous devrez choisir la difficulté du jeu entre le niveau 1 et 3. Le niveau déterminera le temps que vous aurez pour jouer, 7 secondes pour le niveau 1, 5 secondes pour le niveau 2 et 3 secondes pour le niveau 3. Ce choix est fait grâce à la fonction suivante:
```c
  int difficulty();
```

Vous devrez ensuite saisir la colonne sur laquelle vous voulez placer votre bloc et son orientation grâce à la fonction:
```c
  void place(int tab[TAILLE][TAILLE], Tetromoni* tetro, int score, int level);
```
Le bloc est enfin placer automatiquement dans le tableau, voici un aperçu du tétromino S placé dans la colonne B avec comme orientation 1:

![alt text](https://github.com/Auxifruit/tetris-projet/blob/image/GRID1.png "Exemple tableau")

Si une ligne est remplie entièrement, elle sera supprimé pour laisser sa place aux lignes superieur grâce à la fonction:
```c
  void linedelete(int tab[TAILLE][TAILLE], int n, int score);
```

Le but du jeu est donc de compléter des lignes pour augmenter son score, il y a game over quand une colonne est remplie entièrement.

À la fin de la partie le score du joueur est enregistré dans un fichier texte avec les scores des autres joueurs, grâce à la fonction:
```c
  void end_game(int score);
```

Exemple ci-dessous:

![alt text](https://github.com/Auxifruit/tetris-projet/blob/image/GAMEOVER.png "Exemple game over")

## CRÉATEURS

Binôme composé de Tom ALLAGUILLEMETTE(aka Moutsss) et Guillaume BARRÉ(aka Auxifruit) en PRÉING 1 GROUPE 7
