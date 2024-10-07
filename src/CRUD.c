#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include "callbacks.h"
#include<string.h>

//Ajouter un election 

void ajouter_election (election o){
FILE*f=NULL; //flot de donnée
f=fopen("election.txt","a+");// creation du fichier election .txt et ouverture en  mode lecture et ecriture a la fin
fprintf(f,"%s %s %s %s %s\n",o.id,o.municipalite,o.nombrehabitant,o.date,o.nombrec); //f variable de type file 
fclose(f);
 //retour NULL si operation fini 
}
//********************************************************




//verifier l'existance 

int exist_election(char*id){
FILE*f=NULL;
election o;
f=fopen("election.txt","r");// ouverture du fichier obsr en  mode lecture 
while(fscanf(f,"%s %s %s %s %s\n",o.id,o.municipalite,o.nombrehabitant,o.date,o.nombrec)!=EOF){
if(strcmp(o.id,id)==0)
return 1;   //id existe deja 
}
fclose(f);
return 0;
}

//*****************************************************************




//supprimer tr
void supprimer_election(char*id){
FILE*f=NULL;
FILE*f1=NULL;
election  o ;
f=fopen("election.txt","r");
f1=fopen("ancien.txt","w+");//mode lecture et ecriture 
while(fscanf(f,"%s %s %s %s %s\n",o.id,o.municipalite,o.nombrehabitant,o.date,o.nombrec)!=EOF){
if(strcmp(id,o.id)!=0)fprintf(f1,"%s %s %s %s %s\n",o.id,o.municipalite,o.nombrehabitant,o.date,o.nombrec);
}
fclose(f);
fclose(f1);
remove("election.txt");
rename("ancien.txt","election.txt");
}

//******************************************************************









