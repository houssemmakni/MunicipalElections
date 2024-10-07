#include <stdlib.h>
#include <stdio.h>
#include<string.h>
#include <gtk/gtk.h>
#include "interface.h"
#include "callbacks.h"
#include "tree.h"


GtkListStore *adstore;/*creation du modele de type liste*/
GtkTreeViewColumn *adcolumn;/*visualisation des colonnes*/
GtkCellRenderer *cellad;/*afficheur de cellule(text,image..)*/
FILE *f;

void Afficherelection(GtkWidget* treeview1,char*l)
{

election o;


adstore = gtk_tree_view_get_model(treeview1);
if (adstore ==NULL)
	{


	/* Creation de la 1ere colonne */
	cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("id",
                                                            cellad,
                                                            "text", 0,
                                                            NULL);


        /* Ajouter la 1er colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);


	/* Creation de la 2eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("municipalite",
                                                            cellad,
                                                            "text", 1,
                                                            NULL);
	/* Ajouter la 2emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);

	/* Creation de la 3eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("nombrehabitant",
                                                            cellad,
                                                            "text", 2,
                                                            NULL);
	/* Ajouter la 3emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);

	/* Creation de la 4eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("DATE",
                                                            cellad,
                                                            "text", 3,
                                                            NULL);
	/* Ajouter la 4emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);

	/* Creation de la 5eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("NOMbrec",
                                                            cellad,
                                                            "text", 4,
                                                            NULL);
	

	}



/* Creation du modele */
        adstore = gtk_list_store_new(5,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
				     G_TYPE_STRING);

        /* Insertion des elements */
        f=fopen(l,"r");
	if (f==NULL)
	{
		return;
	}
        else
	{

        	while(fscanf(f,"%s %s %s %s %s\n",o.id,o.municipalite,o.nombrehabitant,o.date,o.nombrec)!=EOF)
			{
                 		 GtkTreeIter pIter;

				 /* Creation de la nouvelle ligne */
				 gtk_list_store_append(adstore, &pIter);
				 /* Mise a jour des donnees */
				 gtk_list_store_set(adstore, &pIter,
		                    0,o.id,
		                    1,o.municipalite,
		                    2,o.nombrehabitant,
		                    3,o.date,
		                    4,o.nombrec,
		                  -1);
                        }
	fclose(f);



	gtk_tree_view_set_model ( GTK_TREE_VIEW (treeview1),
		                          GTK_TREE_MODEL(adstore)  );
	g_object_unref(adstore);
        }
    

}
//===============================================================

//==========================================================

void Afficherelectionnbh1(GtkWidget* treeview1,char*l)
{

election o;
int nbh1=0;

adstore = gtk_tree_view_get_model(treeview1);
if (adstore ==NULL)
	{


	/* Creation de la 1ere colonne */
	cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("id",
                                                            cellad,
                                                            "text", 0,
                                                            NULL);


        /* Ajouter la 1er colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);


	/* Creation de la 2eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("municipalite",
                                                            cellad,
                                                            "text", 1,
                                                            NULL);
	/* Ajouter la 2emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);

	/* Creation de la 3eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("nombrehabitant",
                                                            cellad,
                                                            "text", 2,
                                                            NULL);
	/* Ajouter la 3emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);

	/* Creation de la 4eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("DATE",
                                                            cellad,
                                                            "text", 3,
                                                            NULL);
	/* Ajouter la 4emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);

	/* Creation de la 5eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("NOMbrec",
                                                            cellad,
                                                            "text", 4,
                                                            NULL);
	

	}



/* Creation du modele */
        adstore = gtk_list_store_new(5,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
				     G_TYPE_STRING);

        /* Insertion des elements */
        f=fopen(l,"r");
	if (f==NULL)
	{
		return;
	}
        else
	{

        	while(fscanf(f,"%s %s %s %s %s\n",o.id,o.municipalite,o.nombrehabitant,o.date,o.nombrec)!=EOF)
			{       sprintf(o.nombrehabitant,"%d", nbh1);
				if( nbh1<5000)
				{
                 		 GtkTreeIter pIter;

				 /* Creation de la nouvelle ligne */
				 gtk_list_store_append(adstore, &pIter);
				 /* Mise a jour des donnees */
				 gtk_list_store_set(adstore, &pIter,
		                    0,o.id,
		                    1,o.municipalite,
		                    2,o.nombrehabitant,
		                    3,o.date,
		                    4,o.nombrec,
		                  -1);}
                        }
	fclose(f);



	gtk_tree_view_set_model ( GTK_TREE_VIEW (treeview1),
		                          GTK_TREE_MODEL(adstore)  );
	g_object_unref(adstore);
        }
    

}


//===============================================================

//==========================================================

void Afficherelectionnbh2(GtkWidget* treeview1,char*l)
{

election o;
int nbh2 = 0 ;

adstore = gtk_tree_view_get_model(treeview1);
if (adstore ==NULL)
	{


	/* Creation de la 1ere colonne */
	cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("id",
                                                            cellad,
                                                            "text", 0,
                                                            NULL);


        /* Ajouter la 1er colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);


	/* Creation de la 2eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("municipalite",
                                                            cellad,
                                                            "text", 1,
                                                            NULL);
	/* Ajouter la 2emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);

	/* Creation de la 3eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("nombrehabitant",
                                                            cellad,
                                                            "text", 2,
                                                            NULL);
	/* Ajouter la 3emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);

	/* Creation de la 4eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("DATE",
                                                            cellad,
                                                            "text", 3,
                                                            NULL);
	/* Ajouter la 4emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);

	/* Creation de la 5eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("NOMbrec",
                                                            cellad,
                                                            "text", 4,
                                                            NULL);
	

	}



/* Creation du modele */
        adstore = gtk_list_store_new(5,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
				     G_TYPE_STRING);

        /* Insertion des elements */
        f=fopen(l,"r");
	if (f==NULL)
	{
		return;
	}
        else
	{

        	while(fscanf(f,"%s %s %s %s %s\n",o.id,o.municipalite,o.nombrehabitant,o.date,o.nombrec)!=EOF)
			{       sprintf(o.nombrehabitant,"%d",nbh2);
				if( nbh2>=5000)
				{
                 		 GtkTreeIter pIter;

				 /* Creation de la nouvelle ligne */
				 gtk_list_store_append(adstore, &pIter);
				 /* Mise a jour des donnees */
				 gtk_list_store_set(adstore, &pIter,
		                    0,o.id,
		                    1,o.municipalite,
		                    2,o.nombrehabitant,
		                    3,o.date,
		                    4,o.nombrec,
		                  -1);}
                        }
	fclose(f);



	gtk_tree_view_set_model ( GTK_TREE_VIEW (treeview1),
		                          GTK_TREE_MODEL(adstore)  );
	g_object_unref(adstore);
        }
    

}



//===============================================================

//==========================================================


int Chercherelection(GtkWidget* treeview1,char*l,char*id)
{

election o ;
int nb=0;
adstore = gtk_tree_view_get_model(treeview1);
if (adstore ==NULL)
	{


	/* Creation de la 1ere colonne */
	cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("id",
                                                            cellad,
                                                            "text", 0,
                                                            NULL);


        /* Ajouter la 1er colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);


	/* Creation de la 2eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("municipalite",
                                                            cellad,
                                                            "text", 1,
                                                            NULL);
	/* Ajouter la 2emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);

	/* Creation de la 3eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("nombrehabitant",
                                                            cellad,
                                                            "text", 2,
                                                            NULL);
	/* Ajouter la 3emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);

	/* Creation de la 4eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("DATE",
                                                            cellad,
                                                            "text", 3,
                                                            NULL);
	/* Ajouter la 4emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);

	/* Creation de la 5eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("NOMbrec",
                                                            cellad,
                                                            "text", 4,
                                                            NULL);
	

	}



/* Creation du modele */
        adstore = gtk_list_store_new(5,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
				     G_TYPE_STRING);

        /* Insertion des elements */
        f=fopen(l,"r");
	if (f==NULL)
	{
		return;
	}
        else
	{

        	while(fscanf(f,"%s %s %s %s %s\n",o.id,o.municipalite,o.nombrehabitant,o.date,o.nombrec)!=EOF)
			{if( strcmp(id,o.id)==0)
				{ nb++;
                 		 GtkTreeIter pIter;

				 /* Creation de la nouvelle ligne */
				 gtk_list_store_append(adstore, &pIter);
				 /* Mise a jour des donnees */
				 gtk_list_store_set(adstore, &pIter,
		                    0,o.id,
		                    1,o.municipalite,
		                    2,o.nombrehabitant,
		                    3,o.date,
		                    4,o.nombrec,
		                  -1);
				}
                        }
	fclose(f);



	gtk_tree_view_set_model ( GTK_TREE_VIEW (treeview1),
		                          GTK_TREE_MODEL(adstore)  );
	g_object_unref(adstore);
        }
    
return nb;
}



