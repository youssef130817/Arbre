#ifndef ARBRE_NOEUD_H
#define ARBRE_NOEUD_H

class Noeud {
    int val;
    Noeud* FG;
    Noeud* FD;
public:
    Noeud(int x) ;
    Noeud* insert(Noeud* racine, int val);
    // Méthode pour trouver le nœud le plus à droite d'un sous-arbre (utilisée pour la suppression)
    Noeud* Max(Noeud* racine);
// Méthode pour supprimer un nœud d'un ABB
    Noeud* supprimer(Noeud* racine, int val) ;
    void dfs(Noeud* racine);


    void bfs(Noeud* racine) ;

};



#endif //ARBRE_NOEUD_H
