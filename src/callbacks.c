
#  include <config.h>


#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "admin.h"
#include "string.h"
GtkBuilder *builder;

int x,z,j;
int y=0;
int l,m,h;
int n=0;

//////windowgestion///////////

void 
on_button90_Gestion_uti_clicked          (GtkButton       *button,
                                     gpointer         user_data)
{
GtkWidget *window1,*window2;
	window1 = lookup_widget(button,"window_gestion");
	window2 = create_window_ajoute ();
	
	gtk_widget_show(window2);
	gtk_widget_destroy(window1);
  }


void on_button_gestion_sipp_clicked         (GtkButton       *button,
                                        gpointer         user_data)
{    
GtkWidget *window1,*window2;
	window1 = lookup_widget(button,"window_gestion");
	window2 = create_window_afficher ();
	
	gtk_widget_show(window2);
	gtk_widget_destroy(window1);
}


void on_button_gestion_aff_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window1,*window2;
	window1 = lookup_widget(button,"window_gestion");
	window2 = create_window_afficher ();
	
	gtk_widget_show(window2);
	gtk_widget_destroy(window1);
}


void on_button_gestion_modi_clicked         (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window1,*window2;
	window1 = lookup_widget(button,"window_gestion");
	window2 = create_window_modifier ();
	
	gtk_widget_show(window2);
	gtk_widget_destroy(window1);
}

//////////////////////window_ajoute/////////////////////////
void
on_button_afficher_ajou_clicked        (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window1,*window2;
	window1 = lookup_widget(button,"window_ajoute");
	window2 = create_window_afficher ();
	
	gtk_widget_show(window2);
	gtk_widget_destroy(window1);
}


void
on_button_ajouter_ajou_clicked         (GtkButton       *button,
                                        gpointer         user_data)
{
user c;

GtkWidget *window_ajoute,*combobox10,*nm,*pre,*usr,*pwd,*jr,*ms,*ane,*num,*ml,*ci,*output,*output1 ,*rl;
window_ajoute=create_window_ajoute();
nm= lookup_widget(button,"entry10");
pre= lookup_widget(button,"entry11");
usr= lookup_widget(button,"entry12");
pwd= lookup_widget(button,"entry13");
ci= lookup_widget(button,"entry14");
num=lookup_widget(button,"entry15");
jr = lookup_widget(button,"spinbutton10");
ms = lookup_widget(button,"spinbutton11");
ane = lookup_widget(button,"spinbutton13");
ml= lookup_widget(button,"entry16");
strcpy(c.nom,gtk_entry_get_text(GTK_ENTRY(nm)));
strcpy(c.prenom,gtk_entry_get_text(GTK_ENTRY(pre)));
strcpy(c.user,gtk_entry_get_text(GTK_ENTRY(usr)));
strcpy(c.password,gtk_entry_get_text(GTK_ENTRY(pwd)));
strcpy(c.cin,gtk_entry_get_text(GTK_ENTRY(ci)));
c.date.j=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON (jr));
c.date.m=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON (ms));
c.date.a=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON (ane));
strcpy(c.numero,gtk_entry_get_text(GTK_ENTRY(num)));
strcpy(c.email,gtk_entry_get_text(GTK_ENTRY(ml)));
combobox10 = lookup_widget(button, "comboboxentry10");
if (combobox10 != NULL) {
        gchar *selected_text = gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox10));

        if (selected_text != NULL) {
            // Affiche le genre sélectionné dans la console (debug)
            g_print("Genre sélectionné : %s\n", selected_text);

            // Copie le genre sélectionné dans la structure c
            strcpy(c.sexe, selected_text);

            g_free(selected_text);
        } else {
            // Aucune option sélectionnée dans la combobox
            // Faites quelque chose en conséquence
           j=0;
        }
    }

////////////////////////radiobutton//////////////
        if (y == 1)
        strcpy(c.role, "Medecin");
    else if (y == 2)
        strcpy(c.role, "Infermier");
    else if (y == 3)
        strcpy(c.role, "ResponsableETS");

if ((strcmp(c.nom,"")==0) || (strcmp(c.prenom,"")==0) ||(strcmp(c.user,"")==0)  ||(strcmp(c.password,"")==0) ||(strcmp(c.cin,"")==0)  ||(strcmp(c.numero,"")==0) ||(strcmp(c.email,"")==0)     ) {
output1=lookup_widget(button,"label8");
gtk_label_set_text(GTK_LABEL(output1), "Données manquantes. \n Veuillez remplir tout les champs!");}
else{
output=lookup_widget(button,"label9");
gtk_label_set_text(GTK_LABEL(output), " Donnée validé ");
}
if(z==1){
 ajouter_user( c , "user.txt");
output1=lookup_widget(button,"label8");
gtk_label_set_text(GTK_LABEL(output1), "");

output=lookup_widget(button,"label9");
gtk_label_set_text(GTK_LABEL(output), "");

}

x=0;
y=0;
z=0;


}



void
on_radiobutton13_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{y=3;}
}


void
on_radiobutton12_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{y=2;}
}


void
on_radiobutton11_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{y=1;}
}


void
on_button12_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window1,*window2;
	window1 = lookup_widget(button,"window_ajoute");
	window2 = create_window_gestion ();
	
	gtk_widget_show(window2);
	gtk_widget_destroy(window1);
}

/////////////////////window_modifier/////////////////
void
on_button11_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window1,*window2;
	window1 = lookup_widget(button,"window_modifier");
	window2 = create_window_gestion ();
	
	gtk_widget_show(window2);
	gtk_widget_destroy(window1);
}


void
on_button_consulter_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *cin ,*output,*window_modifier;

	char cin_utilisateur[20], message[100];
       
	
	cin = lookup_widget(button,"entry_consulter");
	strcpy(cin_utilisateur,gtk_entry_get_text(GTK_ENTRY(cin)));

	output = lookup_widget(button,"label23");

	if(userExist(cin_utilisateur) == 0){
		sprintf(message,"CIN non existant ! ");
		gtk_label_set_text(GTK_LABEL(output),message);
	}else{

		GtkWidget *nom,*prenom,*user,*password,*sexe,*cin,*j,*m,*a,*numero,*email;

		nom = lookup_widget(button,"entry20");
		prenom = lookup_widget(button,"entry21");
		user = lookup_widget(button,"entry22");
		password = lookup_widget(button,"entry23");
                cin = lookup_widget(button,"entry24");
                sexe = lookup_widget(button,"comboboxentry20");
		j = lookup_widget(button,"spinbutton20");
		m = lookup_widget(button,"spinbutton21");
		a = lookup_widget(button,"spinbutton23");
		numero = lookup_widget(button,"entry25");
                email = lookup_widget(button,"entry26");

		gtk_entry_set_text(GTK_ENTRY(nom),trouver_user(cin_utilisateur).nom);
gtk_entry_set_text(GTK_ENTRY(prenom),trouver_user(cin_utilisateur).prenom);
		gtk_entry_set_text(GTK_ENTRY(user),trouver_user(cin_utilisateur).user);

		gtk_entry_set_text(GTK_ENTRY(password),trouver_user(cin_utilisateur).password);
gtk_entry_set_text(GTK_ENTRY(cin),trouver_user(cin_utilisateur).cin);
gtk_entry_set_text(GTK_ENTRY(email),trouver_user(cin_utilisateur).email);
gtk_entry_set_text(GTK_ENTRY(numero),trouver_user(cin_utilisateur).numero);

		gtk_spin_button_set_value(j,trouver_user(cin_utilisateur).date.j);
		gtk_spin_button_set_value(m,trouver_user(cin_utilisateur).date.m);
		gtk_spin_button_set_value(a,trouver_user(cin_utilisateur).date.a);

		char sexe_user[20];
		strcpy(sexe_user,trouver_user(cin_utilisateur).sexe);
		int comboIndex = 0 ;
		
		if(strcmp(sexe_user,"Homme") == 0){
			comboIndex = 1;
		}else if(strcmp(sexe_user,"Femme") == 0){
			comboIndex = 2;
		
		}

		gtk_combo_box_set_active(sexe,comboIndex);

		sprintf(message,"cin trouvé avec succser");
		gtk_label_set_text(GTK_LABEL(output),message);
	}
}


void
on_button_afficher_modi_clicked        (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window1,*window2;
	window1 = lookup_widget(button,"window_modifier");
	window2 = create_window_afficher ();
	
	gtk_widget_show(window2);
	gtk_widget_destroy(window1);
}


void
on_button_modif_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{

user c1;

GtkWidget *windowmodifier,*nm1,*combobox20,*pre1,*usr1,*pwd1,*jr1,*ms1,*ane1,*num1,*ml1,*ci1,*output2,*output3;
windowmodifier=create_window_modifier();
nm1= lookup_widget(button,"entry20");
pre1= lookup_widget(button,"entry21");
usr1= lookup_widget(button,"entry22");
pwd1= lookup_widget(button,"entry23");
ci1= lookup_widget(button,"entry24");

jr1 = lookup_widget(button,"spinbutton20");
ms1 = lookup_widget(button,"spinbutton21");
ane1 = lookup_widget(button,"spinbutton23");
num1=lookup_widget(button,"entry25");
ml1= lookup_widget(button,"entry26");
strcpy(c1.nom,gtk_entry_get_text(GTK_ENTRY(nm1)));
strcpy(c1.prenom,gtk_entry_get_text(GTK_ENTRY(pre1)));
strcpy(c1.user,gtk_entry_get_text(GTK_ENTRY(usr1)));
strcpy(c1.password,gtk_entry_get_text(GTK_ENTRY(pwd1)));
strcpy(c1.cin,gtk_entry_get_text(GTK_ENTRY(ci1)));
c1.date.j=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON (jr1));
c1.date.m=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON (ms1));
c1.date.a=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON (ane1));
strcpy(c1.numero,gtk_entry_get_text(GTK_ENTRY(num1)));
strcpy(c1.email,gtk_entry_get_text(GTK_ENTRY(ml1)));
combobox20 = lookup_widget(button, "comboboxentry20");



    if (combobox20 != NULL) {
        gchar *selected_text = gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox20));

        if (selected_text != NULL) {
            // Affiche le genre sélectionné dans la console (debug)
            g_print("Genre sélectionné : %s\n", selected_text);

            // Copie le genre sélectionné dans la structure c
            strcpy(c1.sexe, selected_text);

            g_free(selected_text);
        } else {
            // Aucune option sélectionnée dans la combobox
            // Faites quelque chose en conséquence
           h=1;
        }
    }


    if (n == 3)
        strcpy(c1.role, "Medecin");
    else if (n == 2)
        strcpy(c1.role, "Infermier");
    else if (n == 1)
        strcpy(c1.role, "ResponsableETS");

// appel de la fonction modifier


if ((strcmp(c1.nom,"")==0) || (strcmp(c1.prenom,"")==0) ||(strcmp(c1.user,"")==0)  ||(strcmp(c1.password,"")==0) ||(strcmp(c1.cin,"")==0)  ||(strcmp(c1.numero,"")==0) ||(strcmp(c1.email,"")==0)     ) {
output2=lookup_widget(button,"label23");
gtk_label_set_text(GTK_LABEL(output2), "Données manquantes. \n Veuillez remplir tout les champs!");}


if(l==1 && userExist(c1.cin)==1){
 modifier_user( c1);
 
output3=lookup_widget(button,"label24");
gtk_label_set_text(GTK_LABEL(output3), "Modifier avec succes");

}
l=0;
n=0;
m=0;
}


void
on_checkbutton20_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{l=1;}
}


void
on_radiobutton23_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{n=1;}
}


void
on_radiobutton22_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{n=2;}
}


void
on_radiobutton20_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{n=3;}
}

/////////////window_afficher/////////////////////
void
on_treeview10_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

	

GtkTreeIter iter;
gchar* ENM;
gchar* EPRE;
gchar* EUSN;
gchar* EPASW;
gchar* ECNN;
gchar* ESXH;
gchar* ESXF;
gchar* EJR;
gchar* EMS;
gchar* EANEE;
gchar* ENTEL;
gchar* EEML;
gchar* Erol;
user c ;
GtkTreeModel *model= gtk_tree_view_get_model(treeview);
GtkWidget* windowmodifier,*window_gestionuser, *tre,*ENMM,*EPREE,*EUSNN,*EPASWW,*ECN,*ESXHH,*ESXFF,*ENTELL,*EEMLL;

if (gtk_tree_model_get_iter(model, &iter,path))
{


gtk_tree_model_get(GTK_LIST_STORE(model),&iter,0,&ENM,1,&EPRE,2,&EUSN,3,&EPASW,-1);

windowmodifier=create_window_modifier();
window_gestionuser=create_window_afficher();
gtk_widget_hide(windowmodifier);
gtk_widget_show(window_gestionuser);

ENMM=lookup_widget(windowmodifier,"entry20");
gtk_entry_set_text(GTK_ENTRY(ENMM),ENM);

EPREE=lookup_widget(windowmodifier,"entry21");
gtk_entry_set_text(GTK_ENTRY(EPREE),EPRE);


EUSNN=lookup_widget(windowmodifier,"entry22");
gtk_entry_set_text(GTK_ENTRY(EUSNN),EUSN);


EPASWW=lookup_widget(windowmodifier,"entry23");
gtk_entry_set_text(GTK_ENTRY(EPASWW),EPASW);

}
}



void
on_button_afficher_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{

GtkWidget *tree,*window_afficher;
window_afficher=lookup_widget(button,"window_afficher");
gtk_widget_destroy(window_afficher);
window_afficher=create_window_afficher();
tree=lookup_widget(window_afficher,"treeview10");

afficher_user (tree);

gtk_widget_hide(window_afficher);
gtk_widget_show(window_afficher);
}
 

void
on_button_supp_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *cin,*output;
	char cin_supp[20], message[100];

	cin = lookup_widget(button,"entry16");
	output = lookup_widget(button,"label51");

	strcpy(cin_supp,gtk_entry_get_text(GTK_ENTRY(cin)));

	if(userExist(cin_supp) == 1 ){
		supprimer_user(cin_supp);	

		sprintf(message,"Votre Suppression à été effectuté avec succés !");
		gtk_label_set_text(GTK_LABEL(output),message);
	}else{
		sprintf(message,"cin non existant !");
		gtk_label_set_text(GTK_LABEL(output),message);
	}


}


void
on_button_ajouter_aff_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window1,*window2;
	window1 = lookup_widget(button,"window_afficher");
	window2 = create_window_ajoute ();
	
	gtk_widget_show(window2);
	gtk_widget_destroy(window1);
}


void
on_button_modif_aff_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window1,*window2;
	window1 = lookup_widget(button,"window_afficher");
	window2 = create_window_modifier ();
	
	gtk_widget_show(window2);
	gtk_widget_destroy(window1);
}


void
on_buttoncalculer_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *comboboxentry3 = GTK_WIDGET(user_data);
    
    if (!GTK_IS_COMBO_BOX(comboboxentry3)) {
        g_print("Error: user_data is not a valid GtkComboBox.\n");
        return;
    }

    const gchar *selected_gender = gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxentry3));

    if (selected_gender == NULL) {
    
        g_print("Veuillez sélectionner un genre.\n");
        return;
    }

    char user_file[] = "user.txt";
    float percentageHomme, percentageFemme;

   
    pourcentageuser(user_file, &percentageHomme, &percentageFemme);


    GtkWidget *label48 = GTK_WIDGET(gtk_builder_get_object(builder, "label48"));

    if (label48 == NULL) {
        g_print("Error: Could not find label48 in the GTK builder.\n");
        return;
    }

    if (strcmp(selected_gender, "Homme") == 0) {
       
        gtk_label_set_text(GTK_LABEL(label48), g_strdup_printf("Pourcentage d'hommes : %.2f%%", percentageHomme));
    } else if (strcmp(selected_gender, "Femme") == 0) {
       
        gtk_label_set_text(GTK_LABEL(label48), g_strdup_printf("Pourcentage de femmes : %.2f%%", percentageFemme));
    }

    g_free((gpointer)selected_gender);
}


void
on_button_home_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window1,*window2;
	window1 = lookup_widget(button,"window_afficher");
	window2 = create_window_gestion ();
	
	gtk_widget_show(window2);
	gtk_widget_destroy(window1);
}

/////////////////////////////////////////////////////////fiche

int a,r,c,d,e;
int f,g,w,p,o;


void
on_button1_wndmod_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowmodifier, *windowgestionfiche;
windowgestionfiche=lookup_widget(button,"window_gesionfiche");
gtk_widget_destroy(windowgestionfiche);
windowmodifier=create_window_modfiche ();
gtk_widget_show (windowmodifier);
}


void
on_button1_wndaj_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowajouter, *windowgestionfiche;
windowgestionfiche=lookup_widget(button,"window_gestionfiche");
gtk_widget_destroy(windowgestionfiche);
windowajouter=create_window_ajtfiche ();
gtk_widget_show (windowajouter);
}


void
on_button1_wndrech_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window_rechfiche, *windowgestionfiche;
windowgestionfiche=lookup_widget(button,"window_gestionfiche");
gtk_widget_destroy(windowgestionfiche);
window_rechfiche=create_window_rechfiche ();
gtk_widget_show (window_rechfiche);
}


void
on_button1_wndsupp_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
char noom[20];
GdkColor color;
GtkWidget *windowgestionfiche,*tree, *nmm,*output;
nmm = lookup_widget(button,"entry2_suppfiche");
strcpy(noom,gtk_entry_get_text(GTK_ENTRY(nmm)));
supprimer_don(noom,"don.txt");
windowgestionfiche=lookup_widget(button,"window_gestionfiche");
tree=lookup_widget(windowgestionfiche,"treeview1_afffiche");
afficher_don(tree);
output=lookup_widget(button,"label2_suppfiche");
	gdk_color_parse("green",&color);
	gtk_widget_modify_fg(output,GTK_STATE_NORMAL,&color);
gtk_label_set_text(GTK_LABEL(output), "Supprimer avec Succes");
gtk_widget_hide(windowgestionfiche);
gtk_widget_show(windowgestionfiche);
}


void
on_button2_afffiche_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{

GtkWidget *tree,*windowgestionfiche;
windowgestionfiche=lookup_widget(button,"window_gestionfiche");
gtk_widget_destroy(windowgestionfiche);
windowgestionfiche=create_window_gestionfiche();
tree=lookup_widget(windowgestionfiche,"treeview1_afffiche");

afficher_don(tree);

gtk_widget_hide(windowgestionfiche);
gtk_widget_show(windowgestionfiche);
}


void
on_radiobutton1_AP_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{a=1;}
}


void
on_radiobutton1_AM_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{a=2;}
}


void
on_radiobutton1_ABP_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{a=3;}
}


void
on_radiobutton1_ABM_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{a=4;}
}


void
on_radiobutton1_BP_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{a=5;}
}


void
on_radiobutton1_BM_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{a=6;}
}


void
on_radiobutton1_OP_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{a=7;}
}


void
on_radiobutton1_OM_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{a=8;}
}


void
on_checkbutton1_H_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{r=1;}
}


void
on_checkbutton1_F_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{r=2;}
}





void
on_button1_confaj_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
donneur b;
GdkColor color;
GtkWidget *windowajout,*nm,*pre,*cinn,*jr,*moi,*anne,*typ,*sex,*etts,*combobox1,*combobox2, *output, *output1;
windowajout=create_window_ajtfiche();
nm= lookup_widget(button,"entry1_nom");
pre= lookup_widget(button,"entry1_prenom");
cinn = lookup_widget(button,"entry1_cin");
jr = lookup_widget(button,"spinbutton1_jour");
anne = lookup_widget(button,"spinbutton1_annee");

combobox1=lookup_widget(button,"comboboxentry1_mois");
combobox2=lookup_widget(button,"comboboxentry1_ets");
strcpy(b.nom,gtk_entry_get_text(GTK_ENTRY(nm)));
strcpy(b.prenom,gtk_entry_get_text(GTK_ENTRY(pre)));
strcpy(b.cin,gtk_entry_get_text(GTK_ENTRY(cinn)));




b.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON (jr));
b.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON (anne));




if(a==1)
{strcpy(b.type,"A+");}
else if(a==2)
{strcpy(b.type,"A-");}
else if(a==3)
{strcpy(b.type,"AB+");}
else if(a==4)
{strcpy(b.type,"AB-");}
else if(a==5)
{strcpy(b.type,"B+");}
else if(a==6)
{strcpy(b.type,"B-");}
else if(a==7)
{strcpy(b.type,"O+");}
else if(a==8)
{strcpy(b.type,"O-");}
if(r==1)
{strcpy(b.sexe,"Homme");}
else if(r==2)
{strcpy(b.sexe,"Femme");}

if ((strcmp(b.nom,"")==0) || (strcmp(b.prenom,"")==0) ||(strcmp(b.cin,"")==0) ){
output1=lookup_widget(button,"label1_nnajtfiche");
	gdk_color_parse("red",&color);
	gtk_widget_modify_fg(output1,GTK_STATE_NORMAL,&color);
gtk_label_set_text(GTK_LABEL(output1), "Données manquantes. \n Veuillez remplir tout les champs!");
output=lookup_widget(button,"label1_ajtfichesucc");
gtk_label_set_text(GTK_LABEL(output), "");
}
if (combobox1 != NULL) {
        gchar *selected_text = gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox1));

        if (selected_text != NULL) {
            // Affiche le genre sélectionné dans la console (debug)
            g_print("Genre sélectionné : %s\n", selected_text);
            // Copie le genre sélectionné dans la structure c
            strcpy(b.mois, selected_text);
           g_free(selected_text);
        } else {
            // Aucune option sélectionnée dans la combobox
            // Faites quelque chose en conséquence
           c=0;
        }

if (combobox2 != NULL) {
        gchar *selected_text = gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox2));

        if (selected_text != NULL) {
            // Affiche le genre sélectionné dans la console (debug)
            g_print("Genre sélectionné : %s\n", selected_text);
            // Copie le genre sélectionné dans la structure c
            strcpy(b.ets, selected_text);
           g_free(selected_text);
        } else {
            // Aucune option sélectionnée dans la combobox
            // Faites quelque chose en conséquence
           d=0;
        }




if(e==1){
 ajouter_don(b,"don.txt");

	output1=lookup_widget(button,"label1_nnajtfiche");
	gtk_label_set_text(GTK_LABEL(output1), "");
output=lookup_widget(button,"label1_ajtfichesucc");
	gdk_color_parse("green",&color);
	gtk_widget_modify_fg(output1,GTK_STATE_NORMAL,&color);
gtk_label_set_text(GTK_LABEL(output1), "Ajouter avec Succes");
}
a=0;
r=0;
}
}	
}


void
on_button1_retaj_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowajouter, *windowgestionfiche;
windowajouter=lookup_widget(button,"window_ajtfiche");
gtk_widget_destroy(windowajouter);
windowgestionfiche=create_window_gestionfiche ();
gtk_widget_show (windowgestionfiche);
}


void
on_radiobutton2_AM_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{f=2;}
}


void
on_radiobutton2_BM_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{f=6;}
}


void
on_radiobutton2_AP_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{f=1;}
}


void
on_radiobutton2_BP_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{f=5;}
}


void
on_checkbutton2_H_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{g=1;}
}


void
on_checkbutton2_confmod_toggled        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{w=1;}
}


void
on_checkbutton2_F_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{g=2;}
}


void
on_radiobutton2_OM_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{f=8;}
}


void
on_radiobutton2_ABM_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{f=4;}
}


void
on_radiobutton2_OP_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{f=7;}
}


void
on_radiobutton2_ABP_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{f=3;}
}


void
on_button2_retmod_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowmodifier, *windowgestionfiche;
windowmodifier=lookup_widget(button,"window_modfiche");
gtk_widget_destroy(windowmodifier);
windowgestionfiche=create_window_gestionfiche ();
gtk_widget_show (windowgestionfiche);
}


void
on_button1_confmod_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
donneur b1;
GdkColor color;
GtkWidget *windowmodifier,*nm1,*pre1,*cinn1,*jr1,*moi1,*anne1,*typ1,*sex1,*etts1,*combobox11,*combobox21, *output2;
windowmodifier=create_window_modfiche();
nm1 = lookup_widget(button,"entry2_nom");
pre1 = lookup_widget(button,"entry2_prenom");
cinn1 = lookup_widget(button,"entry2_cin");
jr1 = lookup_widget(button,"spinbutton2_jour");
anne1 = lookup_widget(button,"spinbutton2_annee");

combobox11=lookup_widget(button,"combobox2_mois");
combobox21=lookup_widget(button,"combobox2_ets");
strcpy(b1.nom,gtk_entry_get_text(GTK_ENTRY(nm1)));
strcpy(b1.prenom,gtk_entry_get_text(GTK_ENTRY(pre1)));
strcpy(b1.cin,gtk_entry_get_text(GTK_ENTRY(cinn1)));




b1.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON (jr1));
b1.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON (anne1));




if(f==1)
{strcpy(b1.type,"A+");}
else if(f==2)
{strcpy(b1.type,"A-");}
else if(f==3)
{strcpy(b1.type,"AB+");}
else if(m==4)
{strcpy(b1.type,"AB-");}
else if(f==5)
{strcpy(b1.type,"B+");}
else if(f==6)
{strcpy(b1.type,"B-");}
else if(f==7)
{strcpy(b1.type,"O+");}
else if(f==8)
{strcpy(b1.type,"O-");}
if(g==1)
{strcpy(b1.sexe,"Homme");}
else if(g==2)
{strcpy(b1.sexe,"Femme");}


if (combobox11 != NULL) {
        gchar *selected_text = gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox11));

        if (selected_text != NULL) {
            // Affiche le genre sélectionné dans la console (debug)
            g_print("Genre sélectionné : %s\n", selected_text);
            // Copie le genre sélectionné dans la structure c
            strcpy(b1.mois, selected_text);
           g_free(selected_text);
        } else {
            // Aucune option sélectionnée dans la combobox
            // Faites quelque chose en conséquence
           p=0;
        }

if (combobox21 != NULL) {
        gchar *selected_text = gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox21));

        if (selected_text != NULL) {
            // Affiche le genre sélectionné dans la console (debug)
            g_print("Genre sélectionné : %s\n", selected_text);
            // Copie le genre sélectionné dans la structure c
            strcpy(b1.ets, selected_text);
           g_free(selected_text);
        } else {
            // Aucune option sélectionnée dans la combobox
            // Faites quelque chose en conséquence
           o=0;
        }




if(w==1){
modifier_don(b1.nom,b1,"don.txt");
	
	output2=lookup_widget(button,"label3_modsuufiche");
	gdk_color_parse("green",&color);
	gtk_widget_modify_fg(output2,GTK_STATE_NORMAL,&color);
gtk_label_set_text(GTK_LABEL(output2), "Modifier avec Succes");
}
x=0;
y=0;
}
}	
}


void
on_treeview4_recherche_row_activated   (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

}


void
on_button_rechfiche_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
GdkColor color;
char nom[20];
int c; 
GtkWidget *nm,*tree,*windowrech,*output;
windowrech=lookup_widget(button,"window_rechfiche");
nm = lookup_widget(button,"entry_rechfiche");
strcpy(nom,gtk_entry_get_text(GTK_ENTRY(nm)));
c=rechercher_don(nom);
if (c==0)
{
	output=lookup_widget(button,"label4_rechintrou");
	gdk_color_parse("red",&color);
	gtk_widget_modify_fg(output,GTK_STATE_NORMAL,&color);
	gtk_label_set_text(GTK_LABEL(output), "FICHE INTROUVABLE");
}
if (c==1)
{	
tree=lookup_widget(windowrech,"treeview4_recherche");
afficher_rechercher_don(tree);
}
}


void
on_button_rechret_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window_rechfiche, *windowgestionfiche;
window_rechfiche=lookup_widget(button,"window_rechfiche");
gtk_widget_destroy(window_rechfiche);
windowgestionfiche=create_window_gestionfiche();
gtk_widget_show (windowgestionfiche);
}

void
on_checkbutton1_confaj_toggled         (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{e=1;}
}


void
on_treeview1_afffiche_row_activated    (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkTreeIter iter;
gchar* nom;
gchar* prenom;
gchar* cin;
gchar* jour;
gchar* mois;
gchar* annee;
gchar* type;
gchar* sexe;
gchar* ets;


donneur b;
GtkTreeModel *model= gtk_tree_view_get_model(treeview);
GtkWidget* windowmodifier,*windowgestionfiche,*tre,*nomp,*prep,*cinp,*jp,*mp,*anp,*typ,*sexp,*etsp;

if (gtk_tree_model_get_iter(model, &iter,path))
{


gtk_tree_model_get(GTK_LIST_STORE(model),&iter,0,&nom,1,&prenom,2,&cin,3,&jour,4,&mois,5,&annee,6,&type,7,&sexe,8,&ets,-1);

windowmodifier=create_window_modfiche();
windowgestionfiche=create_window_gestionfiche();
gtk_widget_hide(windowgestionfiche);
gtk_widget_show(windowmodifier);

nomp=lookup_widget(windowmodifier,"entry2_nom");
gtk_entry_set_text(GTK_ENTRY(nomp),nom);

prep=lookup_widget(windowmodifier,"entry2_prenom");
gtk_entry_set_text(GTK_ENTRY(prep),prenom);

cinp=lookup_widget(windowmodifier,"entry2_cin");
gtk_entry_set_text(GTK_ENTRY(cinp),cin);


jp=lookup_widget(windowmodifier,"spinbutton2_jour");
gtk_entry_set_text(GTK_ENTRY(jp),jour);

anp=lookup_widget(windowmodifier,"spinbutton2_annee");
gtk_entry_set_text(GTK_ENTRY(anp),annee);
}



}


void
on_button1_wndrdv_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowrdv, *windowgestionfiche;
windowgestionfiche=lookup_widget(button,"window_gestionfiche");
gtk_widget_destroy(windowgestionfiche);
windowrdv=create_window_rdvfiche ();
gtk_widget_show (windowrdv);
}


void
on_button_rechrdv_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
GdkColor color;
char mois[20];
int c; 
GtkWidget *ms,*tree,*windowrdv,*output;
windowrdv=lookup_widget(button,"window_rdvfiche");
ms = lookup_widget(button,"entry_rechrdv");
strcpy(mois,gtk_entry_get_text(GTK_ENTRY(ms)));
c=rechercher_rdv(mois);
if (c==0)
{
	output=lookup_widget(button,"label_rdvintrou");
	gdk_color_parse("red",&color);
	gtk_widget_modify_fg(output,GTK_STATE_NORMAL,&color);
	gtk_label_set_text(GTK_LABEL(output), "RENDEZ-VOUS INTROUVABLE");
}
if (c==1)
{	
tree=lookup_widget(windowrdv,"treeview1_rechrdv");
afficher_rechercher_rdv(tree);
}
}


void
on_treeview1_rechrdv_row_activated     (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

}
/////////linkage
void
on_button1_wndets_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowinteg, *windowgestionets;
windowinteg=lookup_widget(button,"window_integ");
gtk_widget_destroy(windowinteg);
windowgestionets=create_window_gestionets ();
gtk_widget_show (windowgestionets);
}


void
on_button1_wnduser_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowinteg, *windowgestion;
windowinteg=lookup_widget(button,"window_integ");
gtk_widget_destroy(windowinteg);
windowgestion=create_window_gestion();
gtk_widget_show (windowgestion);
}


void
on_button1_wnddon_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowinteg, *windowgestiondons;
windowinteg=lookup_widget(button,"window_integ");
gtk_widget_destroy(windowinteg);
windowgestiondons=create_window_gestiondons ();
gtk_widget_show (windowgestiondons);
}


void
on_button1_wndfiche_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowinteg, *windowgestionfiche;
windowinteg=lookup_widget(button,"window_integ");
gtk_widget_destroy(windowinteg);
windowgestionfiche=create_window_gestionfiche ();
gtk_widget_show (windowgestionfiche);
}



///////////////////////////////////////////ets

int xx,yy,zz;
int mm,nn,ll;


void
on_button40_retaj_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowajouter, *windowgestionets;
windowajouter=lookup_widget(button,"window_ajoutets");
gtk_widget_destroy(windowajouter);
windowgestionets=create_window_gestionets ();
gtk_widget_show (windowgestionets);
}


void
on_radiobutton40_E_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{xx=1;}
}


void
on_radiobutton40_P_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{xx=2;}
}


void
on_button40_confaj_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
etabli b;
GdkColor color;
GtkWidget *windowajout,*nm,*idd,*conn,*adree,*reg,*cap,*ett,*combobox1, *output, *output1;
windowajout=create_window_ajets();
nm= lookup_widget(button,"entry40_nom");
idd= lookup_widget(button,"entry40_id");
adree = lookup_widget(button,"entry40_adresse");
conn = lookup_widget(button,"entry40_contact");
cap = lookup_widget(button,"spinbutton40_cap");


combobox1=lookup_widget(button,"comboboxentry40_reg");

strcpy(b.nom,gtk_entry_get_text(GTK_ENTRY(nm)));
strcpy(b.id,gtk_entry_get_text(GTK_ENTRY(idd)));
strcpy(b.adresse,gtk_entry_get_text(GTK_ENTRY(adree)));
strcpy(b.contact,gtk_entry_get_text(GTK_ENTRY(conn)));




b.capacite=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON (cap));




if(xx==1)
{strcpy(b.etat,"ETHATIQUE");}
else if(xx==2)
{strcpy(b.etat,"PRIVE");}


if ((strcmp(b.nom,"")==0) || (strcmp(b.id,"")==0) ||(strcmp(b.adresse,"")==0) ||(strcmp(b.contact,"")==0) ){
output1=lookup_widget(button,"label1_nnajets");
	gdk_color_parse("red",&color);
	gtk_widget_modify_fg(output1,GTK_STATE_NORMAL,&color);
gtk_label_set_text(GTK_LABEL(output1), "Données manquantes. \n Veuillez remplir tout les champs!");
output=lookup_widget(button,"label1_ajetssucc");
gtk_label_set_text(GTK_LABEL(output), "");
}
if (combobox1 != NULL) {
        gchar *selected_text = gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox1));

        if (selected_text != NULL) {
            // Affiche le genre sélectionné dans la console (debug)
            g_print("Genre sélectionné : %s\n", selected_text);
            // Copie le genre sélectionné dans la structure c
            strcpy(b.region, selected_text);
           g_free(selected_text);
        } else {
            // Aucune option sélectionnée dans la combobox
            // Faites quelque chose en conséquence
           zz=0;
        }






if(yy==1){
 ajouter_etab(b,"ets.txt");

	output1=lookup_widget(button,"label1_nnajets");
	gtk_label_set_text(GTK_LABEL(output1), "");
output=lookup_widget(button,"label1_ajetssucc");
	gdk_color_parse("green",&color);
	gtk_widget_modify_fg(output1,GTK_STATE_NORMAL,&color);
gtk_label_set_text(GTK_LABEL(output1), "Ajouter avec Succes");
}
xx=0;
yy=0;
}
}


void
on_checkbutton40_confaj_toggled         (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{yy=1;}
}


void
on_treeview40_affets_row_activated      (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkTreeIter iter;
gchar* nom;
gchar* id;
gchar* adresse;
gchar* contact;
gchar* region;
gchar* capacite;
gchar* etat;


etabli b;
GtkTreeModel *model= gtk_tree_view_get_model(treeview);
GtkWidget* windowmodifier,*windowgestionets,*tre,*nomp,*idp,*adrep,*conp,*regp,*capp,*etap;

if (gtk_tree_model_get_iter(model, &iter,path))
{


gtk_tree_model_get(GTK_LIST_STORE(model),&iter,0,&nom,1,&id,2,&adresse,3,&contact,4,&region,5,&capacite,6,&etat,-1);

windowmodifier=create_window_modets();
windowgestionets=create_window_gestionets();
gtk_widget_hide(windowgestionets);
gtk_widget_show(windowmodifier);

nomp=lookup_widget(windowmodifier,"entry41_nom");
gtk_entry_set_text(GTK_ENTRY(nomp),nom);

idp=lookup_widget(windowmodifier,"entry41_id");
gtk_entry_set_text(GTK_ENTRY(idp),id);

adrep=lookup_widget(windowmodifier,"entry41_adresse");
gtk_entry_set_text(GTK_ENTRY(adrep),adresse);

conp=lookup_widget(windowmodifier,"entry41_contact");
gtk_entry_set_text(GTK_ENTRY(conp),contact);


capp=lookup_widget(windowmodifier,"spinbutton41_cap");
gtk_entry_set_text(GTK_ENTRY(capp),capacite);


}


}


void
on_button40_wndsupp_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
char noom[20];
GdkColor color;
GtkWidget *windowgestionets,*tree, *nmm,*output;
nmm = lookup_widget(button,"entry40_supp");
strcpy(noom,gtk_entry_get_text(GTK_ENTRY(nmm)));
supprimer_etab(noom,"ets.txt");
windowgestionets=lookup_widget(button,"window_gestionets");
tree=lookup_widget(windowgestionets,"treeview40_affets");
afficher_etab(tree);
output=lookup_widget(button,"label2_suppets");
	gdk_color_parse("green",&color);
	gtk_widget_modify_fg(output,GTK_STATE_NORMAL,&color);
gtk_label_set_text(GTK_LABEL(output), "Supprimer avec Succes");
gtk_widget_hide(windowgestionets);
gtk_widget_show(windowgestionets);
}


void
on_button40_wndrech_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window_rechets, *windowgestionets;
windowgestionets=lookup_widget(button,"window_gestionets");
gtk_widget_destroy(windowgestionets);
window_rechets=create_window_rechets ();
gtk_widget_show (window_rechets);
}


void
on_button40_wndmod_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowmodifier, *windowgestionets;
windowgestionets=lookup_widget(button,"window_gesionets");
gtk_widget_destroy(windowgestionets);
windowmodifier=create_window_modets ();
gtk_widget_show (windowmodifier);
}


void
on_button40_wndaj_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowajouter, *windowgestionets;
windowgestionets=lookup_widget(button,"window_gestionets");
gtk_widget_destroy(windowgestionets);
windowajouter=create_window_ajets ();
gtk_widget_show (windowajouter);
}




void
on_button40_afficher_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *tree,*windowgestionets;
windowgestionets=lookup_widget(button,"window_gestionets");
gtk_widget_destroy(windowgestionets);
windowgestionets=create_window_gestionets();
tree=lookup_widget(windowgestionets,"treeview40_affets");

afficher_etab(tree);

gtk_widget_hide(windowgestionets);
gtk_widget_show(windowgestionets);
}





void
on_button40_retmod_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowmodifier, *windowgestionets;
windowmodifier=lookup_widget(button,"window_modets");
gtk_widget_destroy(windowmodifier);
windowgestionets=create_window_gestionets();
gtk_widget_show (windowgestionets);
}


void
on_button40_confmod_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
etabli b1;
GdkColor color;
GtkWidget *windowmodifier,*nm1,*idd1,*conn1,*adree1,*reg1,*cap1,*ett1,*combobox11, *output2;
windowmodifier=create_window_modets();
nm1 = lookup_widget(button,"entry41_nom");
idd1 = lookup_widget(button,"entry41_id");
conn1 = lookup_widget(button,"entry41_contact");
adree1 = lookup_widget(button,"entry41_adresse");


cap1 = lookup_widget(button,"spinbutton41_cap");


combobox11=lookup_widget(button,"combobox41_reg");

strcpy(b1.nom,gtk_entry_get_text(GTK_ENTRY(nm1)));
strcpy(b1.id,gtk_entry_get_text(GTK_ENTRY(idd1)));
strcpy(b1.adresse,gtk_entry_get_text(GTK_ENTRY(adree1)));
strcpy(b1.contact,gtk_entry_get_text(GTK_ENTRY(conn1)));


b1.capacite=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON (cap1));





if(mm==1)
{strcpy(b1.etat,"ETHATIQUE");}
else if(mm==2)
{strcpy(b1.etat,"PRIVE");}


if (combobox11 != NULL) {
        gchar *selected_text = gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox11));

        if (selected_text != NULL) {
            // Affiche le genre sélectionné dans la console (debug)
            g_print("Genre sélectionné : %s\n", selected_text);
            // Copie le genre sélectionné dans la structure c
            strcpy(b1.region, selected_text);
           g_free(selected_text);
        } else {
            // Aucune option sélectionnée dans la combobox
            // Faites quelque chose en conséquence
           ll=0;
        }






if(n==1){
modifier_etab(b1.id,b1,"ets.txt");
	
	output2=lookup_widget(button,"label3_modsuuets");
	gdk_color_parse("green",&color);
	gtk_widget_modify_fg(output2,GTK_STATE_NORMAL,&color);
gtk_label_set_text(GTK_LABEL(output2), "Modifier avec Succes");
}
mm=0;
nn=0;

}	
}




void
on_treeview22_recherche_row_activated   (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

}


void
on_button44_retets_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window_rechets, *windowgestionets;
window_rechets=lookup_widget(button,"window_rechets");
gtk_widget_destroy(window_rechets);
windowgestionets=create_window_gestionets();
gtk_widget_show (windowgestionets);
}


void
on_button44_rechets_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
GdkColor color;
char nom[20];
int c; 
GtkWidget *nm,*tree,*windowrech,*output;
windowrech=lookup_widget(button,"window_rechets");
nm = lookup_widget(button,"entry44_rechets");
strcpy(nom,gtk_entry_get_text(GTK_ENTRY(nm)));
c=rechercher_etab(nom);
if (c==0)
{
	output=lookup_widget(button,"label44_rechintrou");
	gdk_color_parse("red",&color);
	gtk_widget_modify_fg(output,GTK_STATE_NORMAL,&color);
	gtk_label_set_text(GTK_LABEL(output), "FICHE INTROUVABLE");
}
if (c==1)
{	
tree=lookup_widget(windowrech,"treeview22_recherche");
afficher_rechercher_etab(tree);
}
}





void
on_radiobutton41_P_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{mm=2;}
}
////////////////////////////////////////////GEST DON

int dd,bb,aa;
int tt,ff,gg;

void
on_treeview50_afffiche_row_activated   (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkTreeIter iter;
gchar* nom;
gchar* id;
gchar* quantite;
gchar* jour;
gchar* mois;
gchar* annee;
gchar* type;

donss b;
GtkTreeModel *model= gtk_tree_view_get_model(treeview);
GtkWidget* windowmodifier,*windowgestiondons,*tre, *nomp,*idp,*quanp,*jrdv,*mrdv,*ardv,*typep;

if (gtk_tree_model_get_iter(model, &iter,path))
{


gtk_tree_model_get(GTK_LIST_STORE(model),&iter,0,&nom,1,&id,2,&quantite,3,&jour,4,&mois,5,&annee,6,&type,-1);

windowmodifier=create_window_modfiche();
windowgestiondons=create_window_gestiondons();
gtk_widget_hide(windowgestiondons);
gtk_widget_show(windowmodifier);

nomp=lookup_widget(windowmodifier,"entry51_nom");
gtk_entry_set_text(GTK_ENTRY(nomp),nom);

idp=lookup_widget(windowmodifier,"entry51_id");
gtk_entry_set_text(GTK_ENTRY(idp),id);

quanp=lookup_widget(windowmodifier,"entry51_quantite");
gtk_entry_set_text(GTK_ENTRY(quanp),quantite);

jrdv=lookup_widget(windowmodifier,"spinbutton51_jour");
gtk_entry_set_text(GTK_ENTRY(jrdv),jour);

mrdv=lookup_widget(windowmodifier,"comboboxentry51_mois");
gtk_entry_set_text(GTK_ENTRY(mrdv),mois);

ardv=lookup_widget(windowmodifier,"spinbutton51_anne");
gtk_entry_set_text(GTK_ENTRY(ardv),annee);
}
}





void
on_button52_afffiche_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *tree,*windowgestiondons;
windowgestiondons=lookup_widget(button,"window_gestiondons");
gtk_widget_destroy(windowgestiondons);
windowgestiondons=create_window_gestiondons();
tree=lookup_widget(windowgestiondons,"treeview50_afffiche");

afficher_done(tree);

gtk_widget_hide(windowgestiondons);
gtk_widget_show(windowgestiondons);
}


void
on_button50_wndsupp_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
char noom[20];
GtkWidget *windowgestiondons,*tree, *nmm,*output;
nmm = lookup_widget(button,"entry50_suppfich");
strcpy(noom,gtk_entry_get_text(GTK_ENTRY(nmm)));
supprimer_done(noom,"dons.txt");
windowgestiondons=lookup_widget(button,"window_gestiondons");
tree=lookup_widget(windowgestiondons,"treeview50_afdons");
afficher_done(tree);
output=lookup_widget(button,"label2_suppfiche");
gtk_label_set_text(GTK_LABEL(output), "Supprimer avec Succes");
gtk_widget_hide(windowgestiondons);
gtk_widget_show(windowgestiondons);
}


void
on_button50_wndaj_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowajouter, *windowgestiondons;
windowgestiondons=lookup_widget(button,"window_gestiondons");
gtk_widget_destroy(windowgestiondons);
windowajouter=create_window_ajdons ();
gtk_widget_show (windowajouter);
}


void
on_button50_wndmod_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowmodifier, *windowgestiondons;
windowgestiondons=lookup_widget(button,"window_gesiondons");
gtk_widget_destroy(windowgestiondons);
windowmodifier=create_window_moddons ();
gtk_widget_show (windowmodifier);
}


void
on_button50_wndrech_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window_rechdons, *windowgestiondons;
windowgestiondons=lookup_widget(button,"window_gestiondons");
gtk_widget_destroy(windowgestiondons);
window_rechdons=create_window_rechdons ();
gtk_widget_show (window_rechdons);
}


void
on_button50_confaj_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
donss b;
GtkWidget *windowajout,*nm,*idd,*quaan,*jr,*moi,*anne,*typ,*combobox1, *output, *output1;
windowajout=create_window_ajdons();
nm= lookup_widget(button,"entry50_nom");
idd= lookup_widget(button,"entry50_id");
quaan = lookup_widget(button,"entry50_quantite");
jr = lookup_widget(button,"spinbutton50_jour");
anne = lookup_widget(button,"spinbutton50_anne");

combobox1=lookup_widget(button,"comboboxentry50_mois");

strcpy(b.nom,gtk_entry_get_text(GTK_ENTRY(nm)));
strcpy(b.id,gtk_entry_get_text(GTK_ENTRY(idd)));
strcpy(b.quantite,gtk_entry_get_text(GTK_ENTRY(quaan)));



b.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON (jr));
b.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON (anne));



if(dd==1)
{strcpy(b.type,"A+");}
else if(dd==2)
{strcpy(b.type,"A-");}
else if(dd==3)
{strcpy(b.type,"AB+");}
else if(dd==4)
{strcpy(b.type,"AB-");}
else if(dd==5)
{strcpy(b.type,"B+");}
else if(dd==6)
{strcpy(b.type,"B-");}
else if(dd==7)
{strcpy(b.type,"O+");}
else if(dd==8)
{strcpy(b.type,"O-");}


if ((strcmp(b.nom,"")==0) || (strcmp(b.id,"")==0) ||(strcmp(b.quantite,"")==0) ) {
output1=lookup_widget(button,"label1_nnajtfiche");
gtk_label_set_text(GTK_LABEL(output1), "Données manquantes. \n Veuillez remplir tout les champs!");
output=lookup_widget(button,"label1_ajtfichesucc");
gtk_label_set_text(GTK_LABEL(output), "");
}
if (combobox1 != NULL) {
        gchar *selected_text = gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox1));

        if (selected_text != NULL) {
            // Affiche le genre sélectionné dans la console (debug)
            g_print("Genre sélectionné : %s\n", selected_text);

            // Copie le genre sélectionné dans la structure c
            strcpy(b.mois, selected_text);

            g_free(selected_text);
        } else {
            // Aucune option sélectionnée dans la combobox
            // Faites quelque chose en conséquence
           aa=0;
        }


if(bb==1){
ajouter_done(b,"dons.txt");

output1=lookup_widget(button,"label1_nnajfiche");
gtk_label_set_text(GTK_LABEL(output1), "");
output=lookup_widget(button,"label1_ajfichesucc");
gtk_label_set_text(GTK_LABEL(output), "Ajouter avec Succes");
}
bb=0;
dd=0;
}
}


void
on_button50_retaj_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowajouter, *windowgestiondons;
windowajouter=lookup_widget(button,"window_ajdons");
gtk_widget_destroy(windowajouter);
windowgestiondons=create_window_gestiondons ();
gtk_widget_show (windowgestiondons);
}


void
on_radiobutton50_AP_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{dd=1;}
}


void
on_radiobutton50_ABP_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{dd=3;}
}


void
on_radiobutton50_ABM_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{dd=4;}
}


void
on_radiobutton50_AM_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{dd=2;}
}


void
on_radiobutton50_OP_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{dd=7;}
}


void
on_radiobutton50_BP_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{dd=5;}
}


void
on_radiobutton50_BM_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{dd=6;}
}


void
on_radiobutton50_OM_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{dd=8;}
}




void
on_button50_confmod_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
donss b1;
GtkWidget *windowmodifier,*nm1,*idd1,*quaan1,*jr1,*moi1,*anne1,*typ1,*combobox2,*output2;
windowmodifier=create_window_moddons();
nm1= lookup_widget(button,"entry51_nom");
idd1= lookup_widget(button,"entry51_id");
jr1 = lookup_widget(button,"spinbutton511_jour");
quaan1= lookup_widget(button,"entry51_quantite");
anne1 = lookup_widget(button,"spinbutton51_ardv");

combobox2=lookup_widget(button,"comboboxentry51_mois");

strcpy(b1.nom,gtk_entry_get_text(GTK_ENTRY(nm1)));
strcpy(b1.id,gtk_entry_get_text(GTK_ENTRY(idd1)));
strcpy(b1.quantite,gtk_entry_get_text(GTK_ENTRY(quaan1)));
b1.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON (jr1));
b1.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON (moi1));

if (combobox2 != NULL) {
        gchar *selected_text = gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox2));

        if (selected_text != NULL) {
            // Affiche le genre sélectionné dans la console (debug)
            g_print("Genre sélectionné : %s\n", selected_text);

            // Copie le genre sélectionné dans la structure c
            strcpy(b1.mois, selected_text);

            g_free(selected_text);
        } else {
            // Aucune option sélectionnée dans la combobox
            // Faites quelque chose en conséquence
           gg=0;
        }


if(tt==1)
{strcpy(b1.type,"A+");}
else if(tt==2)
{strcpy(b1.type,"A-");}
else if(tt==3)
{strcpy(b1.type,"AB+");}
else if(tt==4)
{strcpy(b1.type,"AB-");}
else if(tt==5)
{strcpy(b1.type,"B+");}
else if(tt==6)
{strcpy(b1.type,"B-");}
else if(tt==7)
{strcpy(b1.type,"O+");}
else if(tt==8)
{strcpy(b1.type,"O-");}




if(ff==1){
modifier_done(b1.nom,b1,"dons.txt");
output2=lookup_widget(button,"label3_modsuufiche");
gtk_label_set_text(GTK_LABEL(output2), "Modifier avec Succes");

}
tt=0;
ff=0;
gg=0;
}
}


void
on_button50_retmod_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowmodifier, *windowgestiondons;
windowmodifier=lookup_widget(button,"window_moddons");
gtk_widget_destroy(windowmodifier);
windowgestiondons=create_window_gestiondons ();
gtk_widget_show (windowgestiondons);
}


void
on_checkbutton50_confmod_toggled       (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{ff=1;}
}


void
on_radiobutton51_OM_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{tt=8;}
}


void
on_radiobutton51_BM_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{tt=6;}
}


void
on_radiobutton51_OP_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{tt=7;}
}


void
on_radiobutton51_BP_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{tt=5;}
}


void
on_radiobutton51_ABM_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{tt=4;}
}


void
on_radiobutton51_AM_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{tt=2;}
}


void
on_radiobutton51_AP_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{tt=1;}
}


void
on_radiobutton51_ABP_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{tt=3;}
}


void
on_treeview55_recherche_row_activated  (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

}


void
on_button55_rechfiche_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{
char nom[20];
int c; 
GtkWidget *nm,*tree,*windowrech,*output;
windowrech=lookup_widget(button,"window_rechdons");
nm = lookup_widget(button,"entry_rechdons");
strcpy(nom,gtk_entry_get_text(GTK_ENTRY(nm)));
c=rechercher_done(nom);
if (c==0)
{
	output=lookup_widget(button,"label4_rechintrou");
	gtk_label_set_text(GTK_LABEL(output), "fiche INTROUVABLE");
}
if (c==1)
{	
tree=lookup_widget(windowrech,"treeview55_recherche");
afficher_rechercher_done(tree);
}
}


void
on_button55_rechret_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window_rechdons, *windowgestiondons;
window_rechdons=lookup_widget(button,"window_rechdons");
gtk_widget_destroy(window_rechdons);
windowgestiondons=create_window_gestiondons();
gtk_widget_show (windowgestiondons);
}


void
on_button80_retinteg_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowinteg, *windowgestionfiche;
windowgestionfiche=lookup_widget(button,"window_gestionfiche");
gtk_widget_destroy(windowgestionfiche);
windowinteg=create_window_integ ();
gtk_widget_show (windowinteg);
}


void
on_button60_retinteg_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowinteg, *windowgestiondons;
windowgestiondons=lookup_widget(button,"window_gestiondons");
gtk_widget_destroy(windowgestiondons);
windowinteg=create_window_integ ();
gtk_widget_show (windowinteg);
}


void
on_checkbutton100_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{z=1;}
}


void
on_radiobutton410_E_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{mm=1;}
}


void
on_checkbutton430_confmod_toggled      (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{nn=1;}
}


void
on_checkbutton500_confaj_toggled       (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{bb=1;}
}

