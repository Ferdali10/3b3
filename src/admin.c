#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "admin.h"

enum
{
    ENM,
    EPRE,
    EUSN,
    EPASW,
    ECN,
    ESX,
    EDATE,
    ENTEL,
    EEML,
    Erol,
    COLUMNSSS,
};



enum
{ 
	ENOM,
	EPRENOM,
	ECIN,
	EJOUR,
	EMOIS,
	EANNEE,
	ETYPE,
	ESEXE,
	EETS,
	COLUMNSS,
};


enum
{ 
	ENOMM,
	EID,
	EADRESSE,
	ECONTACT,
	EREGION,
	ECAPACITE,
	EETAT,//local or international
	COLUMNS,
	
	
	
};


enum
{ 
	ENOMMM,
	EIDD,
	EQUANTITE,
	EJOURR,
	EMOISS,
	EANNEEE,
	ETYPEE,
	COLUMNSSSS,
};


void ajouter_user(user c, char *users)
{
    FILE *f;
    f = fopen(users, "a");

    if (f != NULL)
    {
        fprintf(f, "%s %s %s %s %s %s %d %d %d %s %s %s\n", c.nom, c.prenom, c.user, c.password, c.cin, c.sexe, c.date.j, c.date.m, c.date.a, c.numero, c.email, c.role);
        fclose(f);
    }
}




void role_user(user c, char msg[50])
{
    if (strcmp(c.role, "Medecin") == 0)
        strcpy(msg, "medecin");
    else if (strcmp(c.role, "Infermier") == 0)
        strcpy(msg, "infermier");
    else if (strcmp(c.role, "Responsable ETS") == 0)
        strcpy(msg, "Responsable ETS");
}

void modifier_user(user c1)
{
    user c;

    FILE *f;
    FILE *f2;
    f = fopen("user.txt", "r");
    f2 = fopen("userM.txt", "w");

    while (fscanf(f, "%s %s %s %s %s %s %d %d %d %s %s %s\n", c.nom, c.prenom, c.user,
                  c.password, c.cin, c.sexe, &(c.date.j), &(c.date.m), &(c.date.a), c.numero,
                  c.email, c.role) != EOF)
    {
        if (strcmp(c.nom, c1.nom) == 0)
        {
            fprintf(f2, "%s %s %s %s %s %s %d %d %d %s %s %s\n", c1.nom, c1.prenom,
                    c1.user, c1.password, c1.cin, c1.sexe, c1.date.j, c1.date.m, c1.date.a,
                    c1.numero, c1.email, c1.role);
        }
        else
        {
            fprintf(f2, "%s %s %s %s %s %s %d %d %d %s %s %s\n", c.nom, c.prenom, c.user,
                    c.password, c.cin, c.sexe, c.date.j, c.date.m, c.date.a, c.numero, c.email, c.role);
        }
    }
    fclose(f);
    fclose(f2);
    remove("user.txt");
    rename("userM.txt", "user.txt");
}
void supprimer_user(char cin[])
{
    
    FILE *f = fopen("user.txt", "r");
    FILE *f2 = fopen("tmp.txt", "a");
    user c2;

    while (fscanf(f, "%s %s %s %s %s %s %d %d %d %s %s %s\n", c2.nom, c2.prenom,
                  c2.user, c2.password, c2.cin, c2.sexe, &(c2.date.j), &(c2.date.m), &(c2.date.a),
                  c2.numero, c2.email, c2.role) != EOF)
    {
        if (strcmp(c2.cin, cin) != 0)
        {
            fprintf(f2, "%s %s %s %s %s %s %d %d %d %s %s %s\n", c2.nom, c2.prenom,
                    c2.user, c2.password, c2.cin, c2.sexe, c2.date.j, c2.date.m, c2.date.a,
                    c2.numero, c2.email, c2.role);
        }
    }
    fclose(f);
    fclose(f2);
    remove("user.txt");
    rename("tmp.txt", "user.txt");
}


void afficher_user(GtkWidget *liste)
{
    GtkCellRenderer *renderer;
    GtkTreeViewColumn *column;
    GtkTreeIter iter;
    GtkListStore *store;
    user c;

    char nom[20];
    char prenom[20];
    char user[20];
    char password[20];
    char cin[20];
    char sexe[10];
    char date[100];
    char numero[20];
    char email[50];
    char role[20];

    FILE *f;

    store = NULL;
    store = GTK_LIST_STORE(gtk_tree_view_get_model(GTK_TREE_VIEW(liste)));

    if (store == NULL)
    {
        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("nom", renderer, "text", ENM, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("prenom", renderer, "text", EPRE, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("user", renderer, "text", EUSN, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("password", renderer, "text", EPASW, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("cin", renderer, "text", ECN, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("sexe", renderer, "text", ESX, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Date", renderer, "text", EDATE, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("numero", renderer, "text", ENTEL, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("email", renderer, "text", EEML, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("role", renderer, "text", Erol, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
    }

    store = gtk_list_store_new(COLUMNSSS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING,
                               G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING,
                               G_TYPE_STRING);

    f = fopen("user.txt", "r");
    if (f == NULL)
    {
        return;
    }
    else
    {
        while (fscanf(f, "%s %s %s %s %s %s %d %d %d %s %s %s\n", c.nom, c.prenom, c.user, c.password,
                      c.cin, c.sexe, &(c.date.j), &(c.date.m), &(c.date.a), c.numero, c.email, c.role) != EOF)
        {
                 
                 sprintf(date,"%d/%d/%d",c.date.j,c.date.m,c.date.m);
			gtk_list_store_append(store,&iter);
            gtk_list_store_append(store, &iter);
            gtk_list_store_set(store, &iter, ENM, c.nom, EPRE, c.prenom, EUSN, c.user, EPASW, c.password,
                               ECN, c.cin, ESX, c.sexe, EDATE,date, ENTEL, c.numero, EEML, c.email, Erol,
                               c.role, -1);
        }
        gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
        g_object_unref(store);
        fclose(f);
    }
}

int userExist(char cin[])
{
    user c;
    FILE *f;
    f = fopen("user.txt", "r");
    if (f != NULL)
    {
        while (fscanf(f, "%s %s %s %s %s %s %d %d %d %s %s %s\n", c.nom, c.prenom, c.user, c.password,
                      c.cin, c.sexe, &(c.date.j), &(c.date.m), &(c.date.a), c.numero, c.email, c.role) != EOF)
        {
            if (strcmp(c.cin, cin) == 0)
            {
               
                return 1;
            }
        }
    }
    fclose(f);
    return 0;
}

user trouver_user(char cin[])
{
    user c;
    FILE *f;
  
    f = fopen("user.txt", "r");
    if (f != NULL)
    {
        while (fscanf(f, "%s %s %s %s %s %s %d %d %d %s %s %s\n", c.nom, c.prenom, c.user, c.password,
                      c.cin, c.sexe, &(c.date.j), &(c.date.m), &(c.date.a), c.numero, c.email, c.role) != EOF)
        {
            if (strcmp(c.cin, cin) == 0)
            {
               
                return c;
           
            }
        }
    }
    fclose(f);
    // Return an empty user if not found, modify the return type if needed
    return ;
}
///////////pourcentage/////////////////


void pourcentageuser(char user_file[], float *percentageHomme, float *percentageFemme) {
    FILE *f;
    user c ;

    f = fopen(user_file, "r");
    if (f == NULL) {
        perror("erreur");
       exit(EXIT_FAILURE);
    }

    int totalUsers = 0;
    int nbhomme = 0;
    int nbfemme = 0;

    while (fread(&c, sizeof(user), 1, f) == 1) {
        totalUsers++;

        if (strcmp(c.sexe, "homme") == 0) {
            nbhomme++;
        } else if (strcmp(c.sexe, "femme") == 0) {
            nbfemme++;
        }
    }

    fclose(f);

    if (totalUsers > 0) {
        *percentageHomme = ((float)nbhomme / totalUsers) * 100.0;
        *percentageFemme = ((float)nbfemme / totalUsers) * 100.0;
    } else {
        *percentageHomme = 0.0;
        *percentageFemme = 0.0;
    }
}


//////////////////////////fiche

//Ajouter fiche


void ajouter_don(donneur b,char *dons){
FILE * f;
f=fopen(dons,"a");

  fprintf(f,"%s %s  %s %d %s %d %s %s %s  \n ",b.nom,b.prenom,b.cin,b.jour,b.mois,b.annee,b.type,b.sexe,b.ets);
  fclose(f);
}


//Afficher fiche

void afficher_don(GtkWidget *liste){
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	
	GtkTreeIter iter;
	GtkListStore *store;
	char nom[30];
	char prenom[10];
	char cin[10];
	char jour[10];
	char mois[30];
	char annee[30];
	char type[30];
	char sexe[30];
	char ets[30];
	
	store=NULL;
	FILE *f;
	store=gtk_tree_view_get_model (liste);
	if (store==NULL)
	{
	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("nom", renderer, "text",ENOM,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("prenom", renderer, "text",EPRENOM,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("cin", renderer, "text",ECIN,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);


	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("jour", renderer, "text",EJOUR,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);


	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("mois", renderer, "text",EMOIS,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("annee", renderer, "text",EANNEE,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("type", renderer, "text",ETYPE,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);


	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("sexe", renderer, "text",ESEXE,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("ets", renderer, "text",EETS,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
	
	

	}
	store=gtk_list_store_new (COLUMNSS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING,  G_TYPE_STRING,   G_TYPE_STRING, G_TYPE_STRING,  G_TYPE_STRING,G_TYPE_STRING, G_TYPE_STRING);
	f=fopen("don.txt","r");
	if(f==NULL)
	{
		return;
	}
	else
	{
		f= fopen("don.txt","a+");
		while(fscanf(f,"%s %s %s %s %s %s %s %s %s   \n",nom,prenom,cin,jour,mois,annee,type,sexe,ets)!=EOF)
		{
			gtk_list_store_append(store, &iter);
			gtk_list_store_set(store,&iter, ENOM, nom, EPRENOM,prenom, ECIN, cin, EJOUR, jour, EMOIS, mois ,EANNEE ,annee,  ETYPE, type, ESEXE,sexe, EETS, ets,-1);
		}
		fclose(f);
		gtk_tree_view_set_model (GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
		g_object_unref (store);
	}
}

        
//supprimer fiche

void supprimer_don(char nom[],char *dons)
{
donneur b;     
FILE * f=fopen(dons,"r");
FILE * f2=fopen("donsupp.txt","w");

while (fscanf(f,"%s %s %s  %d %s %d %s %s %s\n  ",b.nom,b.prenom,b.cin,&b.jour,b.mois,&b.annee,b.type,b.sexe,b.ets)!=EOF)
{

if(strcmp(b.nom,nom)!=0)

  fprintf(f2,"%s %s %s  %d %s %d %s %s %s  ",b.nom,b.prenom,b.cin,b.jour,b.mois,b.annee,b.type,b.sexe,b.ets);
}
  fclose(f);

  fclose(f2);

remove(dons);
rename("donsupp.txt",dons);

 
}
        
//Modifier fiche

void modifier_don(char cin[],donneur b1,char *dons)
{
donneur b;
  FILE* f=fopen(dons, "r");
  FILE* f2=fopen("donmod.txt", "w");
  
  if((f!=NULL) ||( f2!=NULL))
 {
while(fscanf(f,"%s %s %s  %d %s %d %s %s %s ",b.nom,b.prenom,b.cin,&b.jour,b.mois,&b.annee,b.type,b.sexe,b.ets)!=EOF)
{
if(strcmp(b.cin,b1.cin)==0)
  fprintf(f2,"%s %s %s  %d %s %d %s %s %s \n ",b1.nom,b1.prenom,b1.cin,b1.jour,b1.mois,b1.annee,b1.type,b1.sexe,b1.ets);
else
 fprintf(f2,"%s %s %s  %d %s %d %s %s %s \n ",b.nom,b.prenom,b.cin,b.jour,b.mois,b.annee,b.type,b.sexe,b.ets);
}
   fclose(f);
   fclose(f2);
remove(dons);
rename("donmod.txt",dons);
 }
}

//fonction remplir tab fiche
int remplirtabRech (donneur tab[],int nb)
{
    char nom[20];
    int jour;
    int  annee;
    char prenom[20];
    char cin[20];
    char mois[20];
    char type[30];
    char sexe[30];
    char ets[30];
  
    FILE* fichier ;
    int i;

    fichier = fopen("don.txt", "a+");

        while (fscanf(fichier,"%s %s %s  %d %s %d %s %s %s  \n ",nom,prenom,cin,&jour,mois,&annee,type,sexe,ets)!=EOF)
        {
            
            strcpy(tab[i].nom,nom);
            strcpy(tab[i].prenom,prenom);
	    tab[i].jour=jour;
            strcpy(tab[i].mois,mois);
	    tab[i].annee=annee;
	    strcpy(tab[i].cin,cin);
	    strcpy(tab[i].type,type);
	    strcpy(tab[i].sexe,sexe);
	    strcpy(tab[i].ets,ets);	 
	    	
            nb++;
	    i++;    
        }
        fclose(fichier);
	return(nb);
}

//rechercher  fiche

int rechercher_don(char nom[])
{
donneur tab[100];
int nb;
int ce,i;
FILE*f;
ce=0;
nb=remplirtabRech (tab,nb);
for (i=0;i<nb;i++)
	{if ((strcmp(nom,tab[i].nom)==0) ||(strcmp(nom,tab[i].prenom)==0) || (strcmp(nom,tab[i].cin)==0))
		{
		ce=1;
		f=fopen("rechdon.txt", "a+");
		if("f!=NULL")			
	{fprintf(f,"%s %s %s  %d %s %d %s %s %s \n ",tab[i].nom,tab[i].prenom,tab[i].cin,tab[i].jour,tab[i].mois,tab[i].annee,tab[i].type,tab[i].sexe,tab[i].ets);}
		fclose(f);		
		}
	
	}
return(ce);		
}

//AFF RECH fiche
void afficher_rechercher_don(GtkWidget *liste)
{
GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	
	GtkTreeIter iter;
	GtkListStore *store;
	char nom[30];
	char prenom[10];
	char cin[10];
	char jour[10];
	char mois[30];
	char annee[30];
	char type[30];
	char sexe[30];
	char ets[30];
	
	store=NULL;
	FILE *f;
	store=gtk_tree_view_get_model (liste);
	if (store==NULL)
	{
	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("nom", renderer, "text",ENOM,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("prenom", renderer, "text",EPRENOM,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("cin", renderer, "text",ECIN,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("jour", renderer, "text",EJOUR,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);


	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("mois", renderer, "text",EMOIS,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("annee", renderer, "text",EANNEE,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("type", renderer, "text",ETYPE,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);


	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("sexe", renderer, "text",ESEXE,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("ets", renderer, "text",EETS,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
	

	}
	store=gtk_list_store_new (COLUMNSS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING,  G_TYPE_STRING,   G_TYPE_STRING, G_TYPE_STRING,  G_TYPE_STRING,  G_TYPE_STRING,  G_TYPE_STRING);
	f=fopen("rechdon.txt","r");
	if(f==NULL)
	{
		return;
	}
	else
	{
		f= fopen("rechdon.txt","a+");
		while(fscanf(f,"%s %s %s %s %s %s %s %s %s \n",nom,prenom,cin,jour,mois,annee,type,sexe,ets)!=EOF)
		{
			gtk_list_store_append(store, &iter);
			gtk_list_store_set(store,&iter, ENOM, nom, EPRENOM,prenom, ECIN, cin, EJOUR, jour, EMOIS,  mois,EANNEE ,annee,  ETYPE,type , ESEXE, sexe, EETS, ets,-1);
		}
		fclose(f);
		gtk_tree_view_set_model (GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
		g_object_unref (store);
	}
	
}


//fonction remplir tabrdv fiche
int remplirtabrdv (donneur tab[],int nb1)
{
    char nom[20];
    int jour;
    int  annee;
    char prenom[20];
    char cin[20];
    char mois[20];
    char type[30];
    char sexe[30];
    char ets[30];
  
    FILE* fichier ;
    int j;

    fichier = fopen("don.txt", "a+");

        while (fscanf(fichier,"%s %s %s  %d %s %d %s %s %s  \n ",nom,prenom,cin,&jour,mois,&annee,type,sexe,ets)!=EOF)
        {
            
            strcpy(tab[j].nom,nom);
            strcpy(tab[j].prenom,prenom);
	    tab[j].jour=jour;
            strcpy(tab[j].mois,mois);
	    tab[j].annee=annee;
	    strcpy(tab[j].cin,cin);
	    strcpy(tab[j].type,type);
	    strcpy(tab[j].sexe,sexe);
	    strcpy(tab[j].ets,ets);	 
	    	
            nb1++;
	    j++;    
        }
        fclose(fichier);
	return(nb1);
}


//RECH RDV fiche

int rechercher_rdv(char mois[])
{
donneur tab[100];
int nb1;
int ce1,j;
FILE*f;
ce1=0;
nb1=remplirtabrdv (tab,nb1);
for (j=0;j<nb1;j++)
	{if ((strcmp(mois,tab[j].mois)==0))
		{
		ce1=1;
		f=fopen("rechdon.txt", "a+");
		if("f!=NULL")			
	{fprintf(f,"%s %s %s  %d %s %d %s %s %s \n ",tab[j].nom,tab[j].prenom,tab[j].cin,tab[j].jour,tab[j].mois,tab[j].annee,tab[j].type,tab[j].sexe,tab[j].ets);}
		fclose(f);		
		}
	
	}
return(ce1);		
}


//AFF RECH RDV fiche
void afficher_rechercher_rdv(GtkWidget *liste)
{
GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	
	GtkTreeIter iter;
	GtkListStore *store;
	char nom[30];
	char prenom[10];
	char cin[10];
	char jour[10];
	char mois[30];
	char annee[30];
	char type[30];
	char sexe[30];
	char ets[30];
	
	store=NULL;
	FILE *f;
	store=gtk_tree_view_get_model (liste);
	if (store==NULL)
	{
	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("nom", renderer, "text",ENOM,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("prenom", renderer, "text",EPRENOM,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("cin", renderer, "text",ECIN,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("jour", renderer, "text",EJOUR,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);


	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("mois", renderer, "text",EMOIS,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("annee", renderer, "text",EANNEE,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("type", renderer, "text",ETYPE,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);


	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("sexe", renderer, "text",ESEXE,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("ets", renderer, "text",EETS,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
	

	}
	store=gtk_list_store_new (COLUMNSS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING,  G_TYPE_STRING,   G_TYPE_STRING, G_TYPE_STRING,  G_TYPE_STRING,  G_TYPE_STRING,  G_TYPE_STRING);
	f=fopen("rechdon.txt","a+");
	if(f==NULL)
	{
		return;
	}
	else
	{
		f= fopen("rechdon.txt","a+");
		while(fscanf(f,"%s %s %s %s %s %s %s %s %s \n",nom,prenom,cin,jour,mois,annee,type,sexe,ets)!=EOF)
		{
			gtk_list_store_append(store, &iter);
			gtk_list_store_set(store,&iter, ENOM, nom, EPRENOM,prenom, ECIN, cin, EJOUR, jour, EMOIS,  mois,EANNEE ,annee,  ETYPE,type , ESEXE, sexe, EETS, ets,-1);
		}
		fclose(f);
		gtk_tree_view_set_model (GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
		g_object_unref (store);
	}
	
}






//////ets

//ADD

void ajouter_etab(etabli b,char *ets){
FILE * f;
f=fopen(ets,"a");

  fprintf(f,"%s %s %s %s %s %d %s\n ",b.nom,b.id,b.adresse,b.contact,b.region,b.capacite,b.etat);
  fclose(f);
}
 // show

void afficher_etab(GtkWidget *liste){
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	
	GtkTreeIter iter;
	GtkListStore *store;
	char nom[30];
	char id[10];
	char adresse[10];
	char contact[10];
	char region[30];
	char capacite[30];
	char etat[30];
	
	
	store=NULL;
	FILE *f;
	store=gtk_tree_view_get_model (liste);
	if (store==NULL)
	{
	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("nom", renderer, "text",ENOMM,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("id", renderer, "text",EID,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("adresse", renderer, "text",EADRESSE,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);


	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("contact", renderer, "text",ECONTACT,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);


	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("region", renderer, "text",EREGION,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("capacite", renderer, "text",ECAPACITE,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("etat", renderer, "text",EETAT,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);


	
	
	

	}
	store=gtk_list_store_new (COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING,  G_TYPE_STRING,   G_TYPE_STRING, G_TYPE_STRING,  G_TYPE_STRING);
	f=fopen("ets.txt","r");
	if(f==NULL)
	{
		return;
	}
	else
	{
		f= fopen("ets.txt","a+");
		while(fscanf(f,"%s %s %s %s %s %s %s\n",nom,id,adresse,contact,region,capacite,etat)!=EOF)
		{
			gtk_list_store_append(store, &iter);
			gtk_list_store_set(store,&iter, ENOMM, nom, EID,id, EADRESSE, adresse, ECONTACT, contact, EREGION, region ,ECAPACITE ,capacite,  EETAT, etat,-1);
		}
		fclose(f);
		gtk_tree_view_set_model (GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
		g_object_unref (store);
	}
}

//supprimer

void supprimer_etab(char nom[],char *ets)
{
etabli b;     
FILE * f=fopen(ets,"r");
FILE * f2=fopen("etssupp.txt","w");

while (fscanf(f,"%s %s %s %s %s %d %s\n   ",b.nom,b.id,b.adresse,b.contact,b.region,&b.capacite,b.etat)!=EOF)
{

if(strcmp(b.nom,nom)!=0)

  fprintf(f2,"%s %s %s %s %s %d %s\n  ",b.nom,b.id,b.adresse,b.contact,b.region,b.capacite,b.etat);
}
  fclose(f);

  fclose(f2);

remove(ets);
rename("etssupp.txt",ets);

 
}
//Modifier

void modifier_etab(char id[],etabli b1,char *ets)
{
etabli b;
  FILE* f=fopen(ets, "r");
  FILE* f2=fopen("etsmod.txt", "w");
  
  if((f!=NULL) ||( f2!=NULL))
 {
while(fscanf(f,"%s %s %s %s %s %d %s\n  ",b.nom,b.id,b.adresse,b.contact,b.region,&b.capacite,b.etat)!=EOF)
{
if(strcmp(b.id,b1.id)==0)
  fprintf(f2,"%s %s %s %s %s %d %s\n ",b1.nom,b1.id,b1.adresse,b1.contact,b1.region,b1.capacite,b1.etat);
else
 fprintf(f2,"%s %s %s %s %s %d %s\n ",b.nom,b.id,b.adresse,b.contact,b.region,b.capacite,b.etat);
}
   fclose(f);
   fclose(f2);
remove(ets);
rename("etsmod.txt",ets);
 }
}

//fonction remplir tab
int remplirtabRechets (etabli tab[],int nb)
{
    char nom[20];
    char id[20];
    char adresse[20];
    char contact[20];
    char region[30];
    char capacite[30];
    char etat[30];
  
    FILE* fichier ;
    int i;

    fichier = fopen("ets.txt", "a+");

        while (fscanf(fichier,"%s %s %s %s %s %d %s\n",nom,id,adresse,contact,region,capacite,etat)!=EOF)
        {
            
            strcpy(tab[i].nom,nom);
            strcpy(tab[i].adresse,adresse);
	    tab[i].capacite=capacite;
            strcpy(tab[i].id,id);
	    strcpy(tab[i].contact,contact);
	    strcpy(tab[i].region,region);
	    strcpy(tab[i].etat,etat);
	 	 
	    	
            nb++;
	    i++;    
        }
        fclose(fichier);
	return(nb);
}

//rechercher 

int rechercher_etab(char id[])
{
etabli tab[100];
int nb;
int ce,i;
FILE*f;
ce=0;
nb=remplirtabRech (tab,nb);
for (i=0;i<nb;i++)
	{if ((strcmp(id,tab[i].nom)==0) ||(strcmp(id,tab[i].id)==0) || (strcmp(id,tab[i].contact)==0))
		{
		ce=1;
		f=fopen("rechets.txt", "a+");
		if("f!=NULL")			
	{fprintf(f,"%s %s %s %s %s %d %s\n ",tab[i].nom,tab[i].id,tab[i].adresse,tab[i].contact,tab[i].region,tab[i].capacite,tab[i].etat);}
		fclose(f);		
		}
	
	}
return(ce);		
}

//AFF RECH
void afficher_rechercher_etab(GtkWidget *liste)
{
GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	
	GtkTreeIter iter;
	GtkListStore *store;
	char nom[30];
	char adresse[10];
	char contact[10];
	char id[10];
	char region[30];
	char capacite[30];
	char etat[30];
	
	store=NULL;
	FILE *f;
	store=gtk_tree_view_get_model (liste);
	if (store==NULL)
	{
	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("nom", renderer, "text",ENOMM,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("id", renderer, "text",EID,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("contact", renderer, "text",ECONTACT,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("adresse", renderer, "text",EADRESSE,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);


	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("region", renderer, "text",EREGION,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("capacite", renderer, "text",ECAPACITE,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("etat", renderer, "text",EETAT,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);


	

	}
	store=gtk_list_store_new (COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING,  G_TYPE_STRING,   G_TYPE_STRING, G_TYPE_STRING,  G_TYPE_STRING);
	f=fopen("rechets.txt","r");
	if(f==NULL)
	{
		return;
	}
	else
	{
		f= fopen("rechets.txt","a+");
		while(fscanf(f,"%s %s %s %s %s %s %s  \n",nom,adresse,id,contact,region,capacite,etat)!=EOF)
		{
			gtk_list_store_append(store, &iter);
			gtk_list_store_set(store,&iter, ENOMM, nom, EADRESSE,adresse, EID, id, ECONTACT, contact, EREGION,  region,ECAPACITE ,capacite,  EETAT,etat ,-1);
		}
		fclose(f);
		gtk_tree_view_set_model (GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
		g_object_unref (store);
	}
	
}

/////////////////////////GEST DONS

//Ajouter


void ajouter_done(donss b,char *dons){
FILE * f;
f=fopen(dons,"a");

  fprintf(f,"%s %s %s %d %s %d %s \n ",b.nom,b.id,b.quantite,b.jour,b.mois,b.annee,b.type);
  fclose(f);
}


//Afficher

void afficher_done(GtkWidget *liste){
GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	
	GtkTreeIter iter;
	GtkListStore *store;
	char nom[30];
	char id[10];
	char quantite[10];
	char jour[10];
	char mois[30];
	char annee[30];
	char type[30];
	
	store=NULL;
	FILE *f;
	store=gtk_tree_view_get_model (liste);
	if (store==NULL)
	{
	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("nom", renderer, "text",ENOMMM,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("id", renderer, "text",EIDD,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("quantite", renderer, "text",EQUANTITE,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("jour", renderer, "text",EJOURR,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);


	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("mois", renderer, "text",EMOISS,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("annee", renderer, "text",EANNEEE,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("type", renderer, "text",ETYPEE,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
	
	

	}
	store=gtk_list_store_new (COLUMNSSSS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING,  G_TYPE_STRING,   G_TYPE_STRING, G_TYPE_STRING,  G_TYPE_STRING);
	f=fopen("dons.txt","r");
	if(f==NULL)
	{
		return;
	}
	else
	{
		f= fopen("dons.txt","a+");
		while(fscanf(f,"%s %s %s %s %s %s %s   \n",nom,id,quantite,jour,mois,annee,type)!=EOF)
		{
			gtk_list_store_append(store, &iter);
			gtk_list_store_set(store,&iter, ENOMMM, nom, EIDD,id, EQUANTITE, quantite, EJOURR, jour, EMOISS, mois ,EANNEEE ,annee,  ETYPEE, type,-1);
		}
		fclose(f);
		gtk_tree_view_set_model (GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
		g_object_unref (store);
	}
}

//Modifier

void modifier_done(char nom[],donss b1,char *dons)
{
donss b;
  FILE* f=fopen(dons, "r");
  FILE* f2=fopen("donsmod.txt", "w");
  
  if((f!=NULL) ||( f2!=NULL))
 {
while(fscanf(f,"%s %s %s %d %s %d %s \n ",b.nom,b.id,b.quantite,&b.jour,b.mois,&b.annee,b.type)!=EOF)
{
if(strcmp(b.nom,b1.nom)==0)
  fprintf(f2,"%s %s %s %d %s %d %s \n ",b1.nom,b1.id,b1.quantite,b1.jour,b1.mois,b1.annee,b1.type);
else
 fprintf(f2,"%s %s %s %d %s %d %s \n ",b.nom,b.id,b.quantite,b.jour,b.mois,b.annee,b.type);
}
   fclose(f);
   fclose(f2);
remove(dons);
rename("donsmod.txt",dons);
 }
}

//supprimer

void supprimer_done(char nom[],char *dons)
{
donss b;     
FILE * f=fopen(dons,"r");
FILE * f2=fopen("donssupp.txt","w");

while (fscanf(f,"%s %s %s %d %s %d %s \n  ",b.nom,b.id,b.quantite,&b.jour,b.mois,&b.annee,b.type)!=EOF)
{

if(strcmp(b.nom,nom)!=0)

  fprintf(f2,"%s %s %s %d %s %d %s \n  ",b.nom,b.id,b.quantite,b.jour,b.mois,b.annee,b.type);
}
  fclose(f);

  fclose(f2);

remove(dons);
rename("donsupp.txt",dons);

 
}
//fonction remplir tab
int remplirtabRechd (donss tab[],int nb)
{
    char nom[20];
    int jour;
    int  annee;
    char id[20];
    char quantite[20];
    char mois[20];
    char type[30]; 
  
    FILE* fichier ;
    int i;

    fichier = fopen("dons.txt", "a+");

        while (fscanf(fichier,"%s %s %s %d %s %d %s \n ",nom,id,quantite,&jour,mois,&annee,type)!=EOF)
        {
            
            strcpy(tab[i].nom,nom);
            strcpy(tab[i].id,id);
	    tab[i].jour=jour;
            strcpy(tab[i].mois,mois);
	    tab[i].annee=annee;
	    strcpy(tab[i].quantite,quantite);
	    strcpy(tab[i].type,type);
	    	
            nb++;
	    i++;    
        }
        fclose(fichier);
	return(nb);
}
//rechercher 

int rechercher_done(char nom[])
{
donss tab[100];
int nb;
int ce,i;
FILE*f;
ce=0;
nb=remplirtabRech (tab,nb);
for (i=0;i<nb;i++)
	{if ((strcmp(nom,tab[i].nom)==0) ||(strcmp(nom,tab[i].id)==0) || (strcmp(nom,tab[i].quantite)==0))
		{
		ce=1;
		f=fopen("rechdons.txt", "w+");
		if("f!=NULL")			
	{fprintf(f,"%s %s %s %d %s %d %s \n ",tab[i].nom,tab[i].id,tab[i].quantite,tab[i].jour,tab[i].mois,tab[i].annee,tab[i].type);}
		fclose(f);		
		}
	
	}
return(ce);		
}

//AFF RECH
void afficher_rechercher_done(GtkWidget *liste)
{
GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	
	GtkTreeIter iter;
	GtkListStore *store;
	char nom[30];
	char id[10];
	char quantite[10];
	char jour[10];
	char mois[30];
	char annee[30];
	char type[30];
	
	store=NULL;
	FILE *f;
	store=gtk_tree_view_get_model (liste);
	if (store==NULL)
	{
	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("nom", renderer, "text",ENOMMM,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("id", renderer, "text",EIDD,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("quantite", renderer, "text",EQUANTITE,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("jour", renderer, "text",EJOURR,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);


	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("mois", renderer, "text",EMOISS,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("annee", renderer, "text",EANNEEE,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("type", renderer, "text",ETYPEE,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	

	}
	store=gtk_list_store_new (COLUMNSSSS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING,  G_TYPE_STRING,   G_TYPE_STRING, G_TYPE_STRING,  G_TYPE_STRING);
	f=fopen("rechdons.txt","r");
	if(f==NULL)
	{
		return;
	}
	else
	{
		f= fopen("rechdons.txt","a+");
		while(fscanf(f,"%s %s %s %s %s %s %s  \n",nom,id,quantite,jour,mois,annee,type)!=EOF)
		{
			gtk_list_store_append(store, &iter);
			gtk_list_store_set(store,&iter, ENOMMM, nom, EIDD,id, EQUANTITE, quantite, EJOURR, jour, EMOISS,  mois,EANNEEE ,annee,  ETYPEE,type ,-1);
		}
		fclose(f);
		gtk_tree_view_set_model (GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
		g_object_unref (store);
	}
	
}
        
//fonction remplir tabrdv
int remplirtabrdvd (donss tab[],int nb1)
{
    char nom[20];
    int jour;
    int  annee;
    char id[20];
    char quantite[20];
    char mois[20];
    char type[30];
   
  
    FILE* fichier ;
    int j;

    fichier = fopen("dons.txt", "a+");

        while (fscanf(fichier,"%s %s %s %d %s %d %s \n  ",nom,id,quantite,&jour,mois,&annee,type)!=EOF)
        {
            
            strcpy(tab[j].nom,nom);
            strcpy(tab[j].id,id);
	    tab[j].jour=jour;
            strcpy(tab[j].mois,mois);
	    tab[j].annee=annee;
	    strcpy(tab[j].quantite,quantite);
	    strcpy(tab[j].type,type);
	    	 
	    	
            nb1++;
	    j++;    
        }
        fclose(fichier);
	return(nb1);
}


//RECH RDV

int rechercher_rdvd(char mois[])
{
donss tab[100];
int nb1;
int ce1,j;
FILE*f;
ce1=0;
nb1=remplirtabrdv (tab,nb1);
for (j=0;j<nb1;j++)
	{if ((strcmp(mois,tab[j].mois)==0))
		{
		ce1=1;
		f=fopen("rechdons.txt", "a+");
		if("f!=NULL")			
	{fprintf(f,"%s %s %s %d %s %d %s \n  ",tab[j].nom,tab[j].id,tab[j].quantite,tab[j].jour,tab[j].mois,tab[j].annee,tab[j].type);}
		fclose(f);		
		}
	
	}
return(ce1);		
}


//AFF RECH RDV
void afficher_rechercher_rdvd(GtkWidget *liste)
{
GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	
	GtkTreeIter iter;
	GtkListStore *store;
	char nom[30];
	char id[10];
	char quantite[10];
	char jour[10];
	char mois[30];
	char annee[30];
	char type[30];
	
	store=NULL;
	FILE *f;
	store=gtk_tree_view_get_model (liste);
	if (store==NULL)
	{
	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("nom", renderer, "text",ENOMMM,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("id", renderer, "text",EIDD,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("quantite", renderer, "text",EQUANTITE,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("jour", renderer, "text",EJOURR,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);


	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("mois", renderer, "text",EMOISS,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("annee", renderer, "text",EANNEEE,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("type", renderer, "text",ETYPEE,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);


	

	}
	store=gtk_list_store_new (COLUMNSSSS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING,  G_TYPE_STRING,   G_TYPE_STRING, G_TYPE_STRING,  G_TYPE_STRING);
	f=fopen("rechdons.txt","a+");
	if(f==NULL)
	{
		return;
	}
	else
	{
		f= fopen("rechdons.txt","a+");
		while(fscanf(f,"%s %s %s %s %s %s %s  \n",nom,id,quantite,jour,mois,annee,type)!=EOF)
		{
			gtk_list_store_append(store, &iter);
			gtk_list_store_set(store,&iter, ENOMMM, nom, EIDD,id, EQUANTITE, quantite, EJOURR, jour, EMOISS,  mois,EANNEEE ,annee,  ETYPEE,type,-1);
		}
		fclose(f);
		gtk_tree_view_set_model (GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
		g_object_unref (store);
	}
	
}






















