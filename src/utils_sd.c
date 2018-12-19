#include <stdio.h>
#include <stdlib.h>
#include "../head/squelette.h"


/**
 * @brief Alloue l'espace pour un tableau de dim entier
 *
 * @param dim
 *
 * @return l'espace alloué
 */
int* creer_tab_int (int dim) {
  int* mem = malloc(dim * sizeof(int));

  if (mem == NULL) {
    perror("Erreur : l'allocation pour int* s'est mal passée\n");
    exit(2);
  }

  return mem;
}

/**
 * @brief Initialise un tableau d'entier de dimension dim avec la valeur passé en paramètre
 *
 * @param tab
 * @param dim
 * @param valeur
 */
void init_tab_int (int* tab, int dim, int valeur) {
  for (int i = 0; i < dim; i ++) {
    tab[i] = valeur;
  }
}

/**
 * @brief Affiche le tableau passé en paramètres
 *
 * @param tab
 * @param dim
 * @param logfp
 */
void affiche_tab_int (int* tab, int dim, FILE* logfp) {
  printf("[ ");
  
  for (int i = 0; i < dim - 1; i ++) {
    printf("%d\t| ", tab[i]);
  }

  printf("%d\t]\n", tab[dim - 1]);
}


/**
 * @brief Alloue l'espace pour une matrice de nbRows lignes et nbCol colonnes
 *
 * @param nbRows
 * @param nbCol
 *
 * @return l'espace alloué
 */
int** creer_mat_int (int nbRows, int nbCol) {
  int** mem = malloc(nbRows * sizeof (int*));

  if (mem == NULL) {
    perror("Erreur : l'allocation pour int** s'est mal passée\n");
    exit(2);
  }

  for (int i = 0; i < nbRows; i ++) {
    mem[i] = creer_tab_int(nbCol);
  }

  return mem;
}

/**
 * @brief Initialise une matrice d'entier de nbRows lignes et nbCol colonnes avec la valeur passé en paramètre
 *
 * @param mat
 * @param nbRows
 * @param nbCol
 * @param valeur
 */
void init_mat_int (int** mat, int nbRows, int nbCol, int valeur) {
  for(int l = 0; l < nbRows; l ++) {
    for(int c = 0; c < nbCol; c ++) {
      mat[l][c] = valeur;
    }
  }
}


/**
 * @brief Initialise une structure t_tab_int_dyn et alloue l'espace nécessaire
 *
 * @param stTab
 * @param dim
 */
void creer_t_tab_int_dyn (t_tab_int_dyn* stTab, int dim) {
  stTab->dim = dim;
  stTab->tab = creer_tab_int(dim);
}

/**
 * @brief Initialise une structure t_mat_int_dyn et alloue l'espace nécessaire
 *
 * @param stTab
 * @param nbRows
 * @param nbCol
 */
void creer_t_mat_int_dyn (t_mat_int_dyn* stTab, int nbRows, int nbCol) {
  stTab->nbRows = nbRows;
  stTab->nbCol = nbCol;
  stTab->tab = creer_mat_int(nbRows, nbCol);
}

/**
 * @brief Initialise une structure t_mat_char_dyn et alloue l'espace nécessaire
 *
 * @param s_tabmot
 */
void creer_t_mat_char_dyn (t_mat_char_star_dyn* s_tabmot) {
  s_tabmot->nbRows = STR_MAT_ROW;
  s_tabmot->nbCol = STR_MAT_COL;
  s_tabmot->offset = 0;
  
  s_tabmot->tab = malloc(STR_MAT_ROW * sizeof(char**));

  if (s_tabmot->tab == NULL) {
    perror("Erreur : l'allocation pour char*** s'est mal passée\n");
    exit(2);
  }
  
  for (int i = 0; i < STR_MAT_ROW; i ++) {
    s_tabmot->tab[i] = malloc(STR_MAT_COL * sizeof(char*));

    if (s_tabmot->tab[i] == NULL) {
      perror("Erreur : l'allocation pour char** s'est mal passée\n");
      exit(2);
    }
    
    for (int j = 0; j < STR_MAT_COL; j ++) {
      s_tabmot->tab[i][j] = malloc(STR_LEN * sizeof(char));

      if (s_tabmot->tab[i][j] == NULL) {
        perror("Erreur : l'allocation pour char* s'est mal passée\n");
        exit(2);
      }
    }
  }
}
