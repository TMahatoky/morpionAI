# morpion

Jeu de réfléxion et de stratégie 

## Règles
**Le but**

Le but du jeu est d’aligner avant son adversaire 3 symboles identiques horizontalement, verticalement ou en diagonale. Chaque joueur a donc son propre symbole, généralement une croix pour l’un et un rond pour l’autre.

**Déroulement d'une partie**

Pour démarrer une partie, il suffit de tracer sur une feuille blanche une grille de 3 cases sur 3 (selon les variantes, il est possible d’augmenter le nombre de cases). Vous pouvez également le retrouver dans des formes diverses.

Un premier joueur déssine ( ou pose ) son symbole sur une case. Puis c'est au tour de l'autre joueur de dessiner ( ou de poser ) son symbole sur la case vide de son choix. Et ainsi de suite.

**Fin de partie**

Le premier joueur à aligner 3 symboles identiques gagne la partie et marque 1 point. Si la grille est completée sans vainqueur, la partie est finie et il y a égalité.

Pour plus d'informations: 
[Learn the rules](https://en.wikipedia.org/wiki/Tic-tac-toe) 
[Apprend les regles ](https://fr.wikipedia.org/wiki/Morpion_(jeu)) 


## Compilation

g++ -Wall *.cpp -o *nom de l'éxécutable*
ou
g++ *.cpp -o *nom de l'éxécutable*


## Comment jouer 

Chaque case du plateau de jeu est attribué un chiffre entre 1 à 9. Le jeu se joue en entrant des nombres et à d'autres moments des lettres au clavier. Le jeu guide l'utilisateur dans ce qu'il doit entrer et quand il doit les entrer. 


## Référence

Voici le site dans lequel j'ai appris l'algorithme minimax pour le morpion:
https://fearyourself.developpez.com/tutoriel/sdl/morpion/part6
