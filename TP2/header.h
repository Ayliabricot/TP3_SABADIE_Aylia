#ifndef TP2
#define TP2

typedef struct {
	int frequence;
	int duree;
}Note;

Note** creerTableau(int nb_notes);
Note* creerNote(Note** tableau_notes, int* taille,int frequence, int duree);
void librerNotes(Note** tableau_notes, int* taille);

#endif