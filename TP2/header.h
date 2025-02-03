#ifndef TP2
#define TP2

typedef struct {
	float frequence;
	int duree;
}Note;

Note** creerTableau(int nb_notes);
Note* creerNote(float frequence, int duree);
int trouverNote(Note** tableau_notes, int touche);
void librerNotes(Note** tableau_notes, int taille);

#endif