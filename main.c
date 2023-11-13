#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**Exercice 1
int unites(int n){
    return n%10;
}

int dizaines (int n){
    return (n/10)%10;
}

int nbChiffres (int n) {
    int nb=0;
    while (n!=0){
        n=n/10;
        nb++;
    }
    return nb;
}

int sommeChiffres(int n){
    int s=0;
    while (n!=0){
        s += n % 10;
        n = n / 10;
    }
    return s;
}

int main()
{
    int nombre = 12345;
    int res1 = unites(nombre);
    printf("Le chiffre d'unite de %d est : %d\n", nombre, res1);
    int res2 = dizaines(nombre);
    printf("Le chiffre de dizaine de %d est : %d\n", nombre, res2);
    int res3 = nbChiffres(nombre);
    printf("Le nombre de chiffre de %d est : %d\n", nombre, res3);
    int resultat = sommeChiffres(nombre);
    printf("La somme des chiffres de %d est : %d\n", nombre, resultat);
    return 0;
}
**/
/**Exercice3
int sommeDiviseursStricts(int n) {
    int i;
    if (n == 0 || n == 1) {
        return 0;
    }

    int somme = 1;
    for (i = 2; i <= n / 2; i++) {
        if (n % i == 0) {
            somme += i;
        }
    }

    return somme;
}
int sontAmis(int a,int b){
    if ((sommeDiviseursStricts(a)==b)&&(sommeDiviseursStricts(b)==a))
        return 1;
    return 0;
}
int main()
{
    int nombre = 12;
    int resultat = sommeDiviseursStricts(nombre);
    printf("La somme des diviseurs stricts de %d est : %d\n", nombre, resultat);
    int a=220;
    int b=284;
    printf("a et b sont amis ? %d",sontAmis(a,b));
}**/

/**Exercice3
int somme (int T[], int n){
    int s=0,i;
    for (i=0;i<n;i++){
        s+=T[i];
    }
    return s;

}

int min(int T[], int n){
    int min=T[0],i;
    for (i=1;i<n;i++){
        if (T[i]<min)
            min=T[i];
    }
    return min;
}

int existe (int T[],int n,int k){
    int i=0;
    while(i<n){
        if (T[i]==k)
            return 1;
        i++;
    }
    return 0;
}

int sommePairs(int T[], int n){
    int i,s=0;
    for (i=0;i<n;i++){
        if (T[i]%2==0)
            s+=T[i];
    }
}
void permutation(int T[], int n) {
    int i;
    if (n <= 1) {
        return;
    }
    int temp = T[n - 1];
    for (i = n - 1; i > 0; i--) {
        T[i] = T[i - 1];
    }
    T[0] = temp;
}
void miroir(int T[], int n) {
    int debut = 0;
    int fin = n - 1;

    while (debut < fin) {
        int temp = T[debut];
        T[debut] = T[fin];
        T[fin] = temp;
        debut++;
        fin--;
    }
}
int main()
{
    int T[5],i;
    for (i=0;i<5;i++){
        scanf("%d",&T[i]);
    }
    miroir(T,5);
    for (i=0;i<5;i++){
        printf("%d\t",T[i]);
    }
}**/
/**Allocation dynamique**/
/**Exercice1
void afficheChaine(char s[]){
    int i;
    for (i = 0; s[i] != '\0'; i++) {
        putchar(s[i]);
    }
}
int longueur (char s[]){
    return strlen(s);
}
char extrait(char s[], int n) {
    if (n > 0 && s[n - 1] != '\0') {
        return s[n - 1];
    } else {
        return '\0';
    }
}
void subs(char s[], int n, char a) {
    if (n > 0 && s[n - 1] != '\0') {
        s[n - 1] = a;
    } else {
        printf("Indice invalide. Aucune modification effectuée.\n");
    }
}
int main()
{
    afficheChaine("Sabrine");
    printf("\nLongueur chaine %d\n",longueur("Sabrine"));
    char chaine[] = "Sabrine";
    int indice1 = 3;
    char resultat = extrait(chaine, indice1);
    if (resultat != '\0') {
        printf("Le caractère à la position %d est : %c\n", indice1, resultat);
    } else {
        printf("Indice invalide.\n");
    }
    char nouveauCaractere = 'a';
    int indice2 = 6;
     subs(chaine, indice2, nouveauCaractere);
    printf("Après la modification : %s\n", chaine);
}**/
/**Exercice2
float * saisieTableau(int taille) {
    double *tableau = (float *)malloc(taille * sizeof(float));
    int i;
    if (tableau == NULL) {
        printf("Erreur d'allocation mémoire.\n");
        return NULL;
    }
    printf("Veuillez saisir les éléments du tableau :\n");
    for (i = 0; i < taille; i++) {
        printf("Élément %d : ", i + 1);
        scanf("%f", tableau+i);
    }
    return tableau;
}

int main() {
    int taille,i;
    float *monTableau;
    scanf("%d", &taille);
    monTableau = saisieTableau(taille);
    if (monTableau != NULL) {
        printf("Éléments du tableau :\n");
        for (i = 0; i < taille; i++) {
            printf("%f\n", monTableau[i]);
        }
        free(monTableau);
    }

    return 0;
}**/
/**Exercice2
void afficheEtLibere(int *tableau, int taille) {
    int i;
    if (tableau != NULL) {
        printf("Éléments du tableau :\n");
        for (i = 0; i < taille; i++) {
            printf("%d\n", tableau[i]);
        }
        free(tableau);
    } else {
        printf("Pointeur NULL. La libération de mémoire n'est pas nécessaire.\n");
    }
}

int main() {
    int taille,i;
    int *monTableau;

    printf("Veuillez saisir la taille du tableau : ");
    scanf("%d", &taille);
    monTableau = (int *)malloc(taille * sizeof(int));

    if (monTableau == NULL) {
        printf("Erreur d'allocation mémoire.\n");
        return 1;
    }
    printf("Veuillez saisir les éléments du tableau :\n");
    for (i = 0; i < taille; i++) {
        printf("Élément %d : ", i + 1);
        scanf("%d", &monTableau[i]);
    }
    afficheEtLibere(monTableau, taille);
    return 0;
}
**/
/**Exercice 3**/
int **alloueEtInitMatrice(int lignes, int colonnes, int valeur) {
     int **matrice = (int **)malloc(lignes * sizeof(int *));
    if (matrice == NULL) {
        printf("Erreur d'allocation mémoire pour les pointeurs de lignes.\n");
    }
    int i,j;
    for (i = 0; i < lignes; i++) {
        matrice[i] = (int *)malloc(colonnes * sizeof(int));
        if (matrice[i] == NULL) {
            printf("Erreur d'allocation mémoire pour la ligne %d.\n");
            for (j = 0; j < i; j++) {
                free(matrice[j]);
            }
            free(matrice);
            return NULL;
        }
    for (j = 0; j < colonnes; j++) {
            matrice[i][j] = valeur;
        }
    }

    return matrice;
}

void libereMatrice(int **matrice, int lignes) {
    int i;
    if (matrice != NULL) {
        for (i = 0; i < lignes; i++) {
            free(matrice[i]);
        }
        free(matrice);
    } else {
        printf("Pointeur NULL. La libération de mémoire n'est pas nécessaire.\n");
    }
}
void afficheMatrice(int **matrice, int lignes, int colonnes) {
    int i,j;
    for (i = 0; i < lignes; i++) {
        for (j = 0; j < colonnes; j++) {
            printf("%d ", matrice[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int lignes = 3;
    int colonnes = 4;
    int valeurInitiale = 5;
    int **maMatrice = alloueEtInitMatrice(lignes, colonnes, valeurInitiale);
    if (maMatrice != NULL) {
        printf("Matrice :\n");
        afficheMatrice(maMatrice, lignes, colonnes);
        libereMatrice(maMatrice, lignes);
    }

    return 0;
}

