#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include"tree.h"
#include"CRUD.h"
GtkTreeSelection *selection1;

void
on_AcceuilGestionw_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
/*preparation du treeView*/
GtkWidget *p;
gtk_widget_hide (acceuilw);
gestionw = create_gestionw ();
p=lookup_widget(gestionw,"treeview2w");
Afficherelection(p,"election.txt");
gtk_widget_show (gestionw);
i=0;
j=0;
}


void
on_Ajouterelection_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{
election o;






GtkWidget *entrymunw;

GtkWidget *entryIdw;
GtkWidget *entrynbhw;

GtkWidget *entryncw;




GtkWidget *labelIdw;
GtkWidget *labelmunw;
GtkWidget *labelnbhw;
GtkWidget *labelDatew;
GtkWidget *labelncw;
GtkWidget *existew;
GtkWidget* successw;
GtkWidget *calw;
int b=1;
int jj1,mm1,aa1;

FILE*f=NULL;



entryIdw=lookup_widget(gestionw,"entry5w");
entrymunw=lookup_widget(gestionw,"combobox1w");
entrynbhw=lookup_widget(gestionw,"combobox2w");
entryncw=lookup_widget(gestionw,"entry3w");

labelIdw=lookup_widget(gestionw,"label13w");
labelmunw=lookup_widget(gestionw,"label7w");
labelnbhw=lookup_widget(gestionw,"label8w");
labelncw=lookup_widget(gestionw,"label10w");
existew=lookup_widget(gestionw,"label34w");


successw=lookup_widget(gestionw,"label35w");
calw=lookup_widget(gestionw,"yawmia");
        strcpy(o.id,gtk_entry_get_text(GTK_ENTRY(entryIdw) ) );
        strcpy(o.municipalite,gtk_combo_box_get_active_text(GTK_COMBO_BOX(entrymunw)));
        strcpy(o.nombrehabitant,gtk_combo_box_get_active_text(GTK_COMBO_BOX(entrynbhw)));
        strcpy(o.nombrec,gtk_entry_get_text(GTK_ENTRY(entryncw) ) );
     
    
 gtk_widget_hide (successw);

 gtk_calendar_get_date (GTK_CALENDAR(calw),
                       &aa1,
                       &mm1,
                       &jj1);
 gtk_widget_hide (successw);


// controle saisie
if(strcmp(o.id,"")==0){
		  gtk_widget_show (labelIdw);
b=0;
}
else {
		  gtk_widget_hide(labelIdw);
}

if(strcmp(o.municipalite,"")==0){
		  gtk_widget_show (labelmunw);
b=0;
}
else {
		  gtk_widget_hide(labelmunw);
}
if(strcmp(o.nombrehabitant,"")==0){
		  gtk_widget_show (labelnbhw);
b=0;
}
else {
		  gtk_widget_hide(labelnbhw);
}

if(strcmp(o.nombrec,"")==0){
		  gtk_widget_show (labelncw);
b=0;
}
else {
		  gtk_widget_hide(labelncw);
}





if(b==1){

        if(exist_election(o.id)==1)
        {

				  gtk_widget_show (existew);
                }
                else {
                     gtk_widget_hide (existew);

       f=fopen("election.txt","a+");
fprintf(f,"%s %s %s %d/%d/%d %s\n",o.id,o.municipalite,o.nombrehabitant,jj1,mm1+1,aa1,o.nombrec);
fclose(f);
     
//ajouter_election(o);
                  gtk_widget_show (successw);


//mise a jour du treeView
        GtkWidget* p=lookup_widget(gestionw,"treeview2w");

        Afficherelection(p,"election.txt");
}

}
}



void
on_Modifierelection_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
      GtkWidget *combobox3w;
        GtkWidget *combobox4w;
     combobox3w=lookup_widget(button,"combobox3w");
     combobox4w=lookup_widget(button,"combobox4w");
       	 election o;

        strcpy(o.id,gtk_label_get_text(GTK_LABEL(lookup_widget(gestionw,"label20w"))));
        
   strcpy(o.municipalite,gtk_combo_box_get_active_text(GTK_COMBO_BOX(lookup_widget(gestionw,"combobox3w"))));
   strcpy(o.nombrehabitant,gtk_combo_box_get_active_text(GTK_COMBO_BOX(lookup_widget(gestionw,"combobox4w"))));
        strcpy(o.nombrec,gtk_entry_get_text(GTK_ENTRY(lookup_widget(gestionw,"entry8w"))));
        strcpy(o.date,gtk_entry_get_text(GTK_ENTRY(lookup_widget(gestionw,"entry9w"))));

  
   
        supprimer_election(o.id);
        ajouter_election(o);
//mise ajour du tree view 
        Afficherelection(lookup_widget(gestionw,"treeview1"),"election.txt");
	gtk_widget_show(lookup_widget(gestionw,"label37w"));
        GtkWidget *p=lookup_widget(gestionw,"treeview2w");
        Afficherelection(p,"election.txt");
}





void
on_chercherelection_clicked              (GtkButton       *button,
                                       gpointer         user_data)
{
GtkWidget *p1w;
GtkWidget *entryw;
GtkWidget *labelidw;
GtkWidget *nbResultatw;
GtkWidget *messagew;
char id[30];
char chnb[30];
int b=0,nb; //b=0  entry  cherche vide 
entryw=lookup_widget(gestionw,"entry10w");
labelidw=lookup_widget(gestionw,"label28w");
p1w=lookup_widget(gestionw,"treeview2w");
strcpy(id,gtk_entry_get_text(GTK_ENTRY(entryw)));

if(strcmp(id,"")==0){
  gtk_widget_show (labelidw);b=0;
}else{
b=1;
gtk_widget_hide (labelidw);}

if(b==0)
    {return;
    }
    else
    {

nb=Chercherelection(p1w,"election.txt",id);

 

sprintf(chnb,"%d",nb);        
//conversion int==> chaine car la fonction gtk_label_set_text naccepte que chaine
nbResultatw=lookup_widget(gestionw,"label27");
messagew=lookup_widget(gestionw,"label26w");
gtk_label_set_text(GTK_LABEL(nbResultatw),chnb);

gtk_widget_show (nbResultatw);
gtk_widget_show (messagew);
}
}


void
on_GestionAcceuilw_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
gtk_widget_show (acceuilw);
gtk_widget_destroy (gestionw);

}




void
on_bmodifier_clickedw                   (GtkButton       *button,
                                        gpointer         user_data)
{
        gchar *id;
        gchar *municipalite;
        gchar *nombrehabitant;
        gchar *date;
        gchar *nombrec;

  
        GtkTreeModel     *model;
        GtkTreeIter iter;
        if (gtk_tree_selection_get_selected(selection1, &model, &iter))
        {

        gtk_widget_hide(lookup_widget(gestionw,"label37w"));//cacher label modifier avec succees
                gtk_tree_model_get (model,&iter,0,&id,1,&municipalite,2,&nombrehabitant,3,&date,4,&nombrec,-1);//recuperer les information de la ligne selectionneé   
        // //remplir les champs de entry  
                gtk_entry_set_text(GTK_ENTRY(lookup_widget(gestionw,"combobox3w")),municipalite);
                gtk_entry_set_text(GTK_ENTRY(lookup_widget(gestionw,"combobox4w")),nombrehabitant);
                gtk_entry_set_text(GTK_ENTRY(lookup_widget(gestionw,"entry9w")),date);
                gtk_entry_set_text(GTK_ENTRY(lookup_widget(gestionw,"entry8w")),nombrec);


	
		


                GtkWidget* msgId=lookup_widget(gestionw,"label20w");
                GtkWidget* msg1=lookup_widget(gestionw,"label36w");
                gtk_label_set_text(GTK_LABEL(msgId),id);
                gtk_widget_show(msgId);
                gtk_widget_show(msg1);
                gtk_widget_show(lookup_widget(gestionw,"button4w"));//afficher le bouton modifier
                gtk_notebook_prev_page(GTK_NOTEBOOK(lookup_widget(gestionw,"notebook1w")));//redirection vers la page precedente
        gtk_entry_set_text(GTK_ENTRY(lookup_widget(gestionw,"entry9w")),date);
        }

}


void
on_bsupprimer_clickedw                  (GtkButton       *button,
                                        gpointer         user_data)
{
   gchar *id;
        gchar *municipalite;
        gchar *nombrehabitant;
        gchar *date;
        gchar *nombrec;

  
    GtkTreeModel     *model;
    GtkTreeIter iter;
       if (gtk_tree_selection_get_selected(selection1, &model, &iter))
        {
            gtk_tree_model_get (model,&iter,0,&id,1,&municipalite,2,&nombrehabitant,3,&date,4,&nombrec,-1);//recuperer les information de la ligne selectionneé
            supprimer_election(id);
            Afficherelection(lookup_widget(gestionw,"treeview2w"),"election.txt");        
        }
}


void
on_bafficher12w_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
        GtkWidget *p=lookup_widget(gestionw,"treeview2w");
        Afficherelection(p,"election.txt");
}


void
on_treeview2w_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)//signale du treeView (Double click)
{
    	 gchar *id;
        gchar *municipalite;
        gchar *nombrehabitant;
        gchar *date;
        gchar *nombrec;

      
        GtkTreeModel     *model;
        GtkTreeIter iter;
        GtkWidget *p=lookup_widget(gestionw,"treeview2w");
        selection1 = gtk_tree_view_get_selection(GTK_TREE_VIEW(p));
       
}










void
on_checkbutton1_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{GtkWidget *i1,*i2;
i1=lookup_widget(togglebutton,"radiobutton1");
i2=lookup_widget(togglebutton,"radiobutton2");

if(gtk_toggle_button_get_active(togglebutton))
{
gtk_widget_show(i1);
gtk_widget_show(i2);
}
else
{
gtk_widget_hide(i1);
gtk_widget_hide(i2);
}

}


void
on_radiobutton2_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *p=lookup_widget(gestionw,"treeview2w");
        Afficherelectionnbh2(p,"election.txt");

}


void
on_radiobutton1_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *p=lookup_widget(gestionw,"treeview2w");
        Afficherelectionnbh1(p,"election.txt");

}

