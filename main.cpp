#include <iostream>
#include "Noeud.h"
using namespace std;


int main() {
    Noeud* racine = new Noeud(50);
    racine->insert(racine, 30);
    racine->insert(racine, 20);
    racine->insert(racine, 40);
    racine->insert(racine, 70);
    racine->insert(racine, 60);
    racine->insert(racine, 80);

    cout << "Affichage DFS: ";
    racine->dfs(racine);
    cout << endl;

    cout << "Affichage BFS: ";
    //50 30 70 20 40 60 80
    racine->bfs(racine);
    cout << endl;


    return 0;
}
