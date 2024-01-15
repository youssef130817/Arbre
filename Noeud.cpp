#include <iostream>
#include <list>
#include "Noeud.h"
using namespace std;




Noeud::Noeud(int x) : val(x), FG(nullptr), FD(nullptr) {}

    Noeud* Noeud::insert(Noeud* racine, int val) {
        if (!racine) return new Noeud(val);

        if (val < racine->val)
            racine->FG = insert(racine->FG, val);
        else
            racine->FD = insert(racine->FD, val);

        return racine;
    }

Noeud* Noeud::Max(Noeud* racine) {
        while (racine->FD) {
            racine = racine->FD;
        }
        return racine;
    }

Noeud* Noeud::supprimer(Noeud* racine, int val) {
        if (!racine) return racine;

        if (val < racine->val) {
            racine->FG = supprimer(racine->FG, val);
        } else if (val > racine->val) {
            racine->FD = supprimer(racine->FD, val);
        } else {
            if (!racine->FG && !racine->FD) {
                delete racine;
                return nullptr;
            } else if (!racine->FG || !racine->FD) {
                Noeud* temp = racine->FG ? racine->FG : racine->FD;
                delete racine;
                return temp;
            } else {
                Noeud* temp = Max(racine->FG);
                racine->val = temp->val;
                racine->FG = supprimer(racine->FG, temp->val);
            }
        }

        return racine;
    }
void Noeud:: dfs(Noeud* racine) {
        if (!racine) return;
        dfs(racine->FG);
        cout << racine->val << " ";
        dfs(racine->FD);
    }



    void Noeud::bfs(Noeud* racine) {
        if (!racine) return;

        list<Noeud*> queue;
        queue.push_back(racine);

        while (!queue.empty()) {
            Noeud* NoeudCourant = queue.front();
            queue.pop_front();

            cout << NoeudCourant->val << " ";

            if (NoeudCourant->FG) {
                queue.push_back(NoeudCourant->FG);
            }
            if (NoeudCourant->FD) {
                queue.push_back(NoeudCourant->FD);
            }
        }
    }


