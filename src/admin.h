

#include <gtk/gtk.h>
//admin
typedef struct {
    int j;
    int m;
    int a;
} date;

typedef struct {
    char nom[20];
    char prenom[20];
    char user[20];
    char password[20];
    char cin[52];
    char sexe[20];
    date date;
    char numero[20];
    char email[50];
    char role[50];
}user;

//fiche
typedef struct
{ 
    char nom[20];
    char prenom[20];
    char cin[20];	
    int  jour;
    char mois[20];
    int  annee;
    char type[30];
    char sexe[30];
    char ets[30] ;
    
}donneur;



//ets

typedef struct
{ 
char  nom[30];
char id[50];//id
char adresse[50];
char contact[50];
char region[50];
int capacite;//capacity
char etat[50]//local or international
}etabli;



//gest dons

typedef struct
{ 
    char id[20];
    char quantite[20];
    char nom[20];
    int  jour;
    char mois[20];
    int  annee;
    char type[30];
}donss;


/* ADMIN_H */
void ajouter_user(user c, char *users);
void modifier_user(user c1);
void afficher_user(GtkWidget *liste);
void supprimer_user(char cin[]);
void inscription(user c, int y);
void Modifier(user c1, int n);
int userExist(char cin[]);
user trouver_user(char cin[]);
void pourcentageuser(char user_file[], float *percentageHomme, float *percentageFemme);
//fiche
void ajouter_don(donneur b,char *dons);
void afficher_don(GtkWidget *liste);
void modifier_don(char cin[],donneur b,char *dons);
void supprimer_don(char nom[],char *dons);
int rechercher_don(char nom[]);
void afficher_rechercher_don(GtkWidget *liste);
int remplirtabRech (donneur tab[],int nb) ;

//rdv
int rechercher_rdv(char mois[]);
int remplirtabrdv (donneur tab[],int nb1) ;
void afficher_rechercher_rdv(GtkWidget *liste);

//ets
void ajouter_etab(etabli b,char *ets);//add
void afficher_etab(GtkWidget *liste);//show
void modifier_etab(char id[],etabli b,char *ets);//modify
void supprimer_etab(char nom[],char *ets);//delete
int rechercher_etab(char id[]);//search
void afficher_rechercher_etab(GtkWidget *liste);//show_search
int remplirtabRechets (etabli tab[],int nb);


//gestdons
void ajouter_done(donss b,char *dons);
void afficher_done(GtkWidget *liste);
void modifier_done(char nom[],donss b,char *dons);
void supprimer_done(char nom[],char *dons);
int rechercher_done(char nom[]);
void afficher_rechercher_done(GtkWidget *liste);
int remplirtabRechd (donss tab[],int nb) ;



//rdvdons
int rechercher_rdvd(char mois[]);
int remplirtabrdvd (donss tab[],int nb1) ;
void afficher_rechercher_rdvd(GtkWidget *liste);
