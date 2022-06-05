# PROJET TÉTRIS PRÉ_ING 1

## INFORMATIONS GÉNÉRALES

Le but de ce projet est de réaliser un programme permettant de jouer au jeu TETRIS classique depuis le terminal. La particularité de cette version est que le jeu est plus statique que l'original. Nous avons donc écrit le code dans le langage de programmation C sur linux.

## UTILISATION

Pour compiler le programme, mettez tous les fichiers du github dans un même répertoire. Ensuite, utiliser la commande:

	$ make

Pour lancer le programme:

	$ ./tetris

### JOUABILITÉ

Au lancement du jeu, vous devrez choisir la difficulté du jeu entre le niveau 1 et 3. Le niveau déterminera le temps que vous aurez pour jouer, 10 secondes pour le niveau 1, 7 secondes pour le niveau 2 et 5 secondes pour le niveau 3. Si vous dépassez le temps limite, l'orientation du tétromino puis la colonne sera choisie aléatoirement. Ce choix est fait grâce à la fonction suivante:

	int difficulty();

ATTENTION: si vous sasissez une lettre à la place d'un chiffre, cela sera considéré comme une erreur majeure et mettra fin au programme

Vous devrez ensuite saisir la rotation du tétromino en saisissant une valeur entre 1 et 4 puis la colonne en saisissant une lettre entre A et J sur laquelle vous voulez le placer, sachant que l'origine du bloc est tout à gauche, le tout est fait grâce à la fonction:

	void place(int tab[TAILLE][TAILLE], Tetromino* tetro, int score, int level);

Le bloc est enfin placer automatiquement dans le tableau.

Si une ligne est remplie entièrement, elle sera supprimée pour laisser place aux lignes au-dessus grâce à la fonction:

	void linedelete(int tab[TAILLE][TAILLE], int n, int score);

Le but du jeu est donc de compléter le maximum de lignes pour augmenter son score, il y a game over quand une colonne est remplie entièrement.

À la fin de la partie, le score du joueur est enregistré dans un fichier texte avec les scores des autres joueurs, grâce à la fonction:

	void end_game(int score);

## CRÉATEURS

Binôme composé de Tom ALLAGUILLEMETTE(aka Moutsss) et Guillaume BARRÉ(aka Auxifruit) en PRÉING 1 GROUPE 7

