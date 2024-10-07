#include <gtk/gtk.h>
  GtkWidget *acceuilw;
  GtkWidget *gestionw;
typedef struct election election ;
struct election{
char id[30];
char municipalite[30];
char nombrehabitant[30];
char date[30];
char nombrec[30];

};
int i,j;


void
on_AcceuilGestionw_clicked              (GtkButton       *button,
                                        gpointer         user_data);


void
on_GestionAcceuilw_clicked              (GtkButton       *button,
                                        gpointer         user_data);


void
on_bmodifier_clickedw                   (GtkButton       *button,
                                        gpointer         user_data);

void
on_bsupprimer_clickedw                  (GtkButton       *button,
                                        gpointer         user_data);

void
on_bafficher12w_clicked                 (GtkButton       *button,
                                        gpointer         user_data);

void
on_treeview2w_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);




void
on_button_calcule_clicked              (GtkButton       *button,
                                        gpointer         user_data);


void
on_Ajouterelection_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_Modifierelection_clicked            (GtkButton       *button,
                                        gpointer         user_data);



void
on_chercherelection_clicked            (GtkButton       *button,
                                        gpointer         user_data);

void
on_checkbutton1_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton2_clicked                (GtkButton       *button,
                                        gpointer         user_data);

void
on_radiobutton1_clicked                (GtkButton       *button,
                                        gpointer         user_data);
