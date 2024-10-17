#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include<time.h>
#include <dos.h>
typedef struct Categorie{
    int idCat;
    char nomCat[50];
} categorie ;
/*
void InitCat(categorie *cat){
    cat->idCat=0;
    strcpy(cat->nomCat,"");
}
*/

//DEF/INIT TYPE.
typedef struct Type{
    int idType;
    char nomType[50];
    categorie Cat;
} type ;
/*
void InitType(type *ty){
    ty->idType=0;
    strcpy(ty->nomType,"");
    InitCat(&ty->Cat);

}
*/

//DEF/INIT MADATE.
typedef struct MaDate{
    int jj;
    int mm;
    int aa;
} maDate ;
maDate InitMaDate(){
    maDate md;
    do{
        printf("\t\t\tjour :\n\t\t\t--> ");
        scanf("%d",&md.jj);
    }while(!(md.jj>=1 && md.jj<=31));

     do{
        printf("\t\t\tmois :\n\t\t\t--> ");
        scanf("%d",&md.mm);
    }while(!(md.mm>=1 && md.mm<=12));

    do{
        printf("\t\t\tannee :\n\t\t\t--> ");
        scanf("%d",&md.aa);
    }while(((md.aa)/1000 ==0));
    return md;
}

//DEF/INIT PROD.
typedef struct Produit{
    int id;
    int qte;
    char nom[50];
    type type ;
    maDate Date_Exp;
} produit ;
/*void InitProduit(produit *pt){
    pt->id=0;
    strcpy(pt->nom,"");
    InitType(&pt->type);
    InitMaDate(&pt->Date_Exp);
}
*/
//LISTE CAT.
typedef struct  liste_Cat{
    categorie val;
    struct liste_Cat *suivant;
} liste_Cat ;

//LISTE TYPE
typedef struct  liste_Type{
    type val;
    struct liste_Type *suivant;
} liste_Type ;

//Liste Prod.
typedef struct  liste_Prod{
    produit val;
    struct liste_Prod *suivant;
} liste_Prod ;
//AjoutCat
categorie saisirCategorie(){
    categorie C;
    printf("\t\t\tID_Categorie \n\t\t\t-->");
    scanf("%d", &C.idCat);
    printf("\t\t\tNom_Categorie \n\t\t\t-->");
    scanf("%s", C.nomCat);
    return C ;
}
//AjoutType
type saisirType(){
    //liste_Cat *first=NULL;
    type T;
    printf("\t\t\tID_Type \n\t\t\t-->");
    scanf("%d", &T.idType);
    printf("\t\t\tNom_Type \n\t\t\t-->");
    scanf("%s", T.nomType);
    T.Cat=saisirCategorie();
    return T ;
}
//AjoutProd

produit saisirProduit(){
    int i;
    produit P;
    printf("\t\t\tID_Produit \n\t\t\t-->");
    scanf("%d", &P.id);
    printf("\t\t\tNom_Produit \n\t\t\t-->");
    scanf("%s", P.nom);
    do{
        printf("\t\t\tQuantite_Produit \n\t\t\t-->");
        scanf("%d", &P.qte);
    }while(P.qte<=0);
    int n=P.qte;
    for(i=0;i<n;i++){
        printf("\t\t\tDate_Expiration du produit n%d\n",i+1);
        P.Date_Exp=InitMaDate();
    }
    //InitMaDate(&P.Date_Exp);
    P.type=saisirType();
    return P ;
}
//ExisterCat
int exister_Cat(liste_Cat* f, int x){
    liste_Cat *p=f;
    while(p!=NULL && p->val.idCat!=x)
        p=p->suivant;
    if (p==NULL)
        return 0;
    else return 1;
}

//ExisterType
int exister_Type(liste_Type* f, int x){
    liste_Type *p=f;
    while(p!=NULL && p->val.idType!=x)
        p=p->suivant;
    if (p==NULL)
        return 0;
    else return 1;
}
/*
// nombre de produits par type
int nb_produits(liste_Prod* f, int x){
    int nb=0;
    liste_Prod *p=f;
    while(p!=NULL){
        if(p!=NULL && p->val.type.idType==x){
            nb=nb+p->val.qte;
        }
        p=p->suivant;
   }
   return nb;
}*/

//ExisterProduit
int exister_Prod(liste_Prod* f, int x){
    liste_Prod *p=f;
    while(p!=NULL && p->val.id!=x)
        p=p->suivant;
    if (p==NULL) // 2 cas : liste deja vide ou la liste ne contient pas ce produit
        return 0;
    else return 1;
}
// calculer categorie
int nb_cat(liste_Cat *f){
    int nb=0;
    liste_Cat *p=f;
    while(p!=NULL){
        nb++;
    }
    return nb;
}
// calculer type
int nb_type(liste_Type *f){
    int nb=0;
    liste_Type *p=f;
    while(p!=NULL){
        nb++;
    }
    return nb;
}
// calculer produit
int nb_produit(liste_Prod *f){
    int nb=0;
    liste_Prod *p=f;
    while(p!=NULL){
        nb++;
    }
    return nb;
}
//AjouterListeCat
void Ajout_Liste_Categorie(categorie  ca,liste_Cat**f ){
        //if(exister_Cat(*f,ca.idCat)==0){
            liste_Cat *p;
            p=(liste_Cat *)malloc(sizeof(liste_Cat));
            p->val=ca;
            p->suivant=*f;
            *f=p;
    }
       // else
            //printf("\t cette categorie existe deja !\n");




//AjouterListeType
void Ajout_Liste_Type(type  ty,liste_Type **f ){
            liste_Type *p;
            p=(liste_Type *)malloc(sizeof(liste_Type));
            p->val=ty;
            p->suivant=*f;
            *f=p;
}

//AjouterListeProduit
void Ajout_Liste_Produit(produit  pdt,liste_Prod **f ){
    //liste_Type *f1=NULL;
    //if(exister_Prod(*f,pdt.id)==0){
            liste_Prod *p;
            p=(liste_Prod *)malloc(sizeof(liste_Prod));
            p->val=pdt; // on fait appel a la fonction saisieProduit
            p->suivant=*f;
            *f=p;
            //if(exister_Type(f1,pdt.type.idType)==0){
                    //Ajout_Liste_Type(pdt.type,&f1);
            //}
    //}else
    //printf("\t ce produit existe deja !\n");

}
//SuppimerCat

void supprimer_categorie(liste_Cat **f){
    liste_Cat *p=*f;
    int ID;
    printf("\t\t\tSaisir l'Id_categorie que vou voulez Supprimer \n");
    printf("\t\t\t--> ");
    scanf("%d",&ID);
    while(p!=NULL && p->val.idCat!=ID){
        p=p->suivant;
        }
        if(p!=NULL){
            if(p==*f){
                *f=p->suivant;
                free(p);
            }else{
                   liste_Cat *q=*f;
                   while(q->suivant!=p){
                   q=q->suivant;
                }
                q->suivant=p->suivant;
                free(p);
            }
        }
        else
            printf("\t\t\t netrez un ID valide !\n");

    }
    //SuppimerType
void supprimer_type(liste_Type **f){
    liste_Type *p=*f;
    int ID;
    printf("\t\t\tSaisir l'Id_Type que vous voulez Supprimer \n");
    printf("\t\t\t--> ");
    scanf("%d",&ID);
    while(p!=NULL && p->val.idType!=ID){
        p=p->suivant;
        }
        if(p!=NULL){
            if(p==*f){
                *f=p->suivant;
                free(p);

            }else{
                   liste_Type *q=*f;
                   while(q->suivant!=p){
                   q=q->suivant;
                }
                q->suivant=p->suivant;
                free(p);
            }
        }
        else
            printf("\t\t\t entrez un ID valide !\n");
    }
    //SuppimerProd
void supprimer_prod(liste_Prod **f){
    liste_Prod *p=*f;
    int ID;
    printf("\t\t\tSaisir l'Id_Produit que vous voulez Supprimer \n");
    printf("\t\t\t--> ");
    scanf("%d",&ID);
    while(p!=NULL && p->val.id!=ID){
        p=p->suivant;
        }
        if(p!=NULL){
            if(p==*f){
                free(p);
                *f=p->suivant;


            }else{
                   liste_Prod *q=*f;
                   while(q->suivant!=p){
                   q=q->suivant;
                }
                free(p);
                q->suivant=p->suivant;

            }
        }
        else
            printf("\t\t\t entrez un ID valide !\n");
    }

// C program to demonstrate getdate() method



struct date dt;
struct date()
{
    struct date dt;
    getdate(&dt);
    printf("%d/%d/%d",
           dt.da_day,
           dt.da_mon,
           dt.da_year);

    return ;
}



void vente(liste_Prod **f){
    FILE *fic;
    liste_Prod *p=*f;
    int ID;
    printf("\t\t\tSaisir l'Id_Produit a vendre \n");
    printf("\t\t\t--> ");
    scanf("%d",&ID);

    /*
    fic=fopen("fichier.txt","a");
    fprintf(fic,"idPdt\t\tNomPdt\t\tidType\t\tNomType\t\tidCat\t\tNomCat\t\tdate_de_vente\n");
    fclose(fic);
    */
    while(p!=NULL && p->val.id!=ID){
            p=p->suivant;
    }
    if(p!=NULL){
            if(p->val.qte==1){
                    fic=fopen("fichier2.txt","a");
                    fprintf(fic,"%d\t\t%s\t\t%d\t\t%s\t\t%d\t\t%s\t\t%s",p->val.id,p->val.nom,p->val.type.idType,p->val.type.nomType, p->val.type.Cat.idCat,p->val.type.Cat.nomCat,LoadDateSysteme());
                    fclose(fic);
                    if(p==*f){
                      *f=p->suivant;
                      free(p);

                    }else{
                        liste_Prod *q=*f;
                        while(q->suivant!=p){
                        q=q->suivant;
                        }
                        q->suivant=p->suivant;
                        free(p);
                    }
            }
            else{
                p->val.qte=p->val.qte-1;
                // faut vendre le produit ayant une date exp la plus grande pffffffffffffffffffff
                fic=fopen("fichier2.txt","a");
                fprintf(fic,"%d\t\t%s\t\t%d\t\t%s\t\t%d\t\t%s\t\t%s",p->val.id,p->val.nom,p->val.type.idType,p->val.type.nomType, p->val.type.Cat.idCat,p->val.type.Cat.nomCat,asctime(ptr));
                fclose(fic);
            }
    }
    else
        printf("\t\t\tID du produit introuvalble !\n");

    }

//statistique_durant_un_mois
void stat_mois(int m, int a){

}

/*
void vente(liste_Prod **f, FILE *fp){
    liste_Prod *p=*f;
    int ID;
    printf("\t\t\tSaisir l'Id_Produit a Supprimer \n");
    printf("\t\t\t--> ");
    scanf("%d",&ID);
    struct tm* ptr;
    time_t t;
    t = time(NULL);
    ptr = localtime(&t);
    fopen ("data.txt", "a");
    fprintf(fp,"%d\t\t%s\t\t%d\t\t%s\t\t%d\t\t%s\t\t%s",p->val.id,p->val.nom,p->val.type.idType,p->val.type.NomType, p->val.type.Cat.idCat,p->val.type.Cat.NomCat,asctime(ptr));
    fclose(fp);

    while(p!=NULL && p->val.type.idType!=ID){
        p=p->suivant;
        }
   /* p=ancien(p,f,p->val.Date_Exp.aa+p->val.Date_Exp.jj+p->val.Date_Exp.mm);
        if(p!=NULL){
            if(p=*f){
                free(p);
                *f=p->suivant;
            }else{
                   liste_Prod *q=*f;
                   while(q->suivant!=p){
                   q=q->suivant;
                }
                q->suivant=p->suivant;
                free(p);
            }
        }
    }
*/

int reponse(){
    int x;
    printf("\t\t\tVoulez_vous quitter ? \n\t\t\t1:Continuer \n\t\t\t2:Sortir \n\t\t\t-->");
    scanf("%d",&x);
    return x;
}

//AficheCat
void affiche_Liste_Cat(liste_Cat *p){
liste_Cat *f;
    f=p;

printf("\t\t\tID_Categorie    Nom_Categorie    \n");
    while(f!=NULL)
       {


        printf("\t\t\t%d\t",f->val.idCat);
        printf(" ");

        printf("    %s",f->val.nomCat);
        printf("  ");
        printf("\n");
    f=f->suivant;}

}

//AficheType
void affiche_Liste_type(liste_Type *p){
liste_Type *f;
    f=p;

printf("\t\t\tID_Type    Nom_Type    \n");
    while(f!=NULL)
       {


        printf("\t\t\t%d\t",f->val.idType);
        printf(" ");

        printf("    %s",f->val.nomType);
        printf("  ");
        printf("\n");
    f=f->suivant;}

}

//AficheProduit

void affiche_Liste_Prod(liste_Prod *p){
liste_Prod *f;
    f=p;
    int i;

printf("\t\t\tID_Produit   Nom_Produit    Qte    Categorie    Type    Date_Exp\n");
    while(f!=NULL)
       {


        printf("\t\t\t%d\t",f->val.id);

        printf(" \t %s",f->val.nom);
        printf(" \t%d",f->val.qte);
        printf(" \t%s",f->val.type.Cat.nomCat);
        printf(" \t%s",f->val.type.nomType);
        //printf("\t\t ");
        int n=f->val.qte;
        for(i=0;i<n;i++){
            printf(" \t\t%d/%d/%d",f->val.Date_Exp.jj,f->val.Date_Exp.mm,f->val.Date_Exp.aa);
            printf("\n");
            printf("\t\t\t\t\t\t");
        }
    f=f->suivant;}

}

/*
//AficheProduit

void affiche_Liste_Prod(liste_Prod *p){
liste_Prod *f;
    f=p;

printf("\t\t\tNomPt   Categorie    Type    Qte    id-pdt    date_exp\n");
    while(f!=NULL)
       {

        printf("\t\t\t%s\t",f->val.nom);
        printf(" ");

        printf("\t\t%s\t",f->val.type.Cat.nomCat);
        printf(" ");

        printf("   %s",f->val.type.nomType);
        printf("  ");

        printf("   %d",f->val.qte);
        printf("  ");

        printf("   %d",f->val.id);
        printf("  ");
        int i;
        for(i=0;i<f->val.qte;i++){
            printf("    %d/%d/%d",f->val.Date_Exp.jj,f->val.Date_Exp.mm,f->val.Date_Exp.aa);
            printf("\n");
            printf(" \t\t\t\t\t\t\t\t\t\t");
            //printf("  ");

        }
    f=f->suivant;}

}
*/
//AffichageMenuVS
int  affichage_menuVS(void){
    int ch;
    printf("\t\t\t\t\t\tVENTE ET STATISTIQUES\n");
    printf("\t\t\t****************************************************************\n");
    printf("\n");

    printf("\t\t\t1-Vente\n");
    printf("\t\t\t2-Statistiques\n");
    printf("\t\t\t3-Retour au Menu Principal\n");

    printf("\t\t\t--> ");
    scanf("%d",&ch);

    printf("\t\t\t****************************************************************\n");
    return ch;
}

//AffichageMenuStock
int  affichage_menuStock(void){
    int ch;
    printf("\t\t\t\t\t\tLA GESTION DU STOCK\n");
    printf("\t\t\t****************************************************************\n");
    printf("\n");

    printf("\t\t\t1-Gestion des Categories\n");
    printf("\t\t\t2-Gestion des Types\n");
    printf("\t\t\t3-Gestion des Produits\n");
    printf("\t\t\t4-Affichage du Stock\n");
    printf("\t\t\t5-Retour au Menu Principal\n");

    printf("\t\t\t--> ");
    scanf("%d",&ch);

    printf("\t\t\t****************************************************************\n");
    return ch;
}

//AffichageMenuCat.
int  affichage_menuCategorie(void){
    int ch;
    printf("\t\t\t\tLA GESTION DU STOCK/Gestion des Categories\n");
    printf("\t\t\t****************************************************************\n");
    printf("\n");

    printf("\t\t\t1-Ajouter une nouvelle categorie\n");
    printf("\t\t\t2-Supprimer une categorie\n");
    printf("\t\t\t3-Retour au Gesttion du Stock\n");
    printf("\t\t\t4-Retour au Menu Principal\n");

    printf("\t\t\t--> ");
    scanf("%d",&ch);

    printf("\t\t\t****************************************************************\n");
    return ch;
}

//AffichageMenuType
int  affichage_menuType(void){
    int ch;
    printf("\t\t\t\t\tLA GESTION DU STOCK/Gestion des Types\n");
    printf("\t\t\t****************************************************************\n");
    printf("\n");

    printf("\t\t\t1-Ajouter un nouveau type\n");
    printf("\t\t\t2-Supprimer un type\n");
    printf("\t\t\t3-Retour au Gesttion du Stock\n");
    printf("\t\t\t4-Retour au Menu Principal\n");
    printf("\t\t\t--> ");
    scanf("%d",&ch);
    printf("\t\t\t****************************************************************\n");
    return ch;
}

//AffichageMenuProduit
int  affichage_menuProduit(void){
    int ch;

    printf("\t\t\t\t\tLA GESTION DU STOCK/Gestion des Produits\n");
    printf("\t\t\t****************************************************************\n");
    printf("\n");

    printf("\t\t\t1-Ajouter un nouveau produit\n");
    printf("\t\t\t2-Supprimer un produit\n");
    printf("\t\t\t3-Retour au Gesttion du Stock\n");
    printf("\t\t\t4-Retour au Menu Principal\n");
    printf("\t\t\t--> ");
    scanf("%d",&ch);
    printf("\t\t\t****************************************************************\n");
    return ch;
}

//AffichageMenuPrin.
int  affichage_menu(void){
 int ch;
   //printf("\t\t\t****************************************************************\n");
   printf("\t\t\t\t\t\t\tMENU\n");
   printf("\t\t\t****************************************************************\n");

   printf("\t\t\t1-Gestion du Stock\n");
   printf("\t\t\t2-Vente et Statistiques\n");
   printf("\t\t\t3-Quitter le Menu\n");
   printf("\t\t\t--> ");
   scanf("%d",&ch);
   printf("\t\t\t****************************************************************\n");
return ch;}

//INT_MAIN
int  main(void){
liste_Cat *first=NULL;
liste_Type *first1=NULL;
liste_Prod *first2=NULL;
categorie I;
type J;
produit P;
int n,x;
/*FILE *fic;
    fp  = fopen ("data.txt", "w+");
    fprintf(fic,"idPdt\t\tNomPdt\t\tidType\t\tNomType\t\tidCat\t\tNomCat\t\tdate_de_vente\n");
    fclose(fic);
    */

void menu()

{
switch(affichage_menu())
    {
    case 1:
            switch(affichage_menuStock())
            {
            case 1 :
            switch(affichage_menuCategorie())
                {
                case 1 :
                do{
                    printf("\t\t\tNombre de Categorie :\n\t\t\t");
                    printf("-->");
                    scanf("%d",&n);
                    }while(nb_cat(first)+n>20);
                /*if(n>20){
                    do{
                        printf("\t\t\tentrez nombre de categorie valide !\n\t\t\t");
                        printf("-->");
                        scanf("%d",&n);
                }while(n>20);*/


                for(int i=0;i<n;i++)

                {
                    printf("\t\t\t-------------------------\n");
                    printf("\t\t\t\tCategorie_Num %d\t |\n",i+1);
                    printf("\t\t\t-------------------------\n");
                    I=saisirCategorie();
                    if(exister_Cat(first,I.idCat)==1)
                    {   do

                        {
                        printf("\t\t\tCategorie Existe deja !!\n");
                        I=saisirCategorie();
                        }while(exister_Cat(first,I.idCat)==1);
                    }
                    Ajout_Liste_Categorie(I,&first);
                }
                if(reponse()==1)
                menu();
                else
                {
                printf("\t\t\tA bientot");}
                break;

                case 2:
                supprimer_categorie(&first);


                if(reponse()==1)
                menu();
                else
                printf("\t\t\tA bientot");
                break;

                case 3:
                affichage_menuStock();
                if(reponse()==1)
                menu();
                else
                printf("\t\t\tA bientot");
                break;



                case 4:
                affichage_menu();

                    if(reponse()==1)
                menu();
                else
                printf("\t\t\tA bientot");
                break;

                case 5:

                printf("\t\t\t-------------------------------------------------\n\t\t\t|");
                printf("\t   Liste des Categories\t\t\t|\n");
                printf("\t\t\t-------------------------------------------------\n");
                affiche_Liste_Cat(first);
                if(reponse()==1)
                {
                    printf("\n\n\n");
                    menu();
                }

                else
                printf("\t\t\tA bientot");
                break;

                case 0 :
                if(reponse()==1)
                menu();
                else
                printf("\t\t\tA bientot");
                break;
                default:

                printf("\t\t\terror!!");
                printf("\n");
                affichage_menuCategorie();
                }
            break;
            case 2 :
            switch(affichage_menuType())
                    {
                    case 1 :

                    do{
                    printf("\t\t\tNombre de Type :\n\t\t\t");
                    printf("-->");
                    scanf("%d",&n);
                    }while(nb_type(first1)+n>50);

                    for(int i=0;i<n;i++)

                    {
                        printf("\t\t\t-------------------------\n");
                        printf("\t\t\t\tType_Num %d\t |\n",i+1);
                        printf("\t\t\t-------------------------\n");
                        J=saisirType();
                        if(exister_Type(first1,J.idType)==1)
                        {   do

                            {
                            printf("\t\tType Existe deja !!\n");

                            J=saisirType();
                            }while(exister_Type(first1,J.idType)==1);
                        }
                        if(!(exister_Cat(first,J.Cat.idCat)==1))
                        {
                            Ajout_Liste_Categorie(J.Cat,&first);
                        }
                        Ajout_Liste_Type(J,&first1);

                    }
                    if(reponse()==1)
                    menu();
                    else
                    {
                    printf("\t\t\tA bientot");}
                    break;

                    case 2:
                    supprimer_type(&first1);



                    if(reponse()==1)
                    menu();
                    else
                    printf("\t\t\tA bientot");
                    break;

              case 3:
                    affichage_menuStock();
                    if(reponse()==1)
                    menu();
                    else
                    printf("\t\t\tA bientot");
                    break;



              case 4:
                 affichage_menu();

                if(reponse()==1)
                    menu();
                    else
                    printf("\t\t\tA bientot");
                    break;

                    case 5:
                    printf("\t\t\t-------------------------------------------------\n\t\t\t|");
                    printf("\t   Liste des Types\t\t\t|\n");
                    printf("\t\t\t-------------------------------------------------\n");
                    affiche_Liste_type(first1);
                    if(reponse()==1)
                    {
                        printf("\n\n\n");
                        menu();
                    }

                    else
                    printf("\t\t\tA bientot");
                    break;


                case 0 :  if(reponse()==1)
                menu();
                else
                printf("\t\t\tA bientot");
                default:
                printf("\t\t\terror!!");
                printf("\n");
                affichage_menuType();
                    }
            break;
            case 3 :
            switch(affichage_menuProduit())
                        {
                        case 1 :
                            if(nb_produit(first2)>100)
                                printf("\t\t\tAjout impossible !\n\t\t\t");

                            else{
                                do{
                                    printf("\t\t\tNombre de Produits :\n\t\t\t");
                                    printf("-->");
                                    scanf("%d",&n);
                                }while(nb_produit(first2)+n>100);

                                for(int i=0;i<n;i++)

                                {
                                    printf("\t\t\t-------------------------\n");
                                    printf("\t\t\t\tType_Num %d\t |\n",i+1);
                                    printf("\t\t\t-------------------------\n");
                                    P=saisirProduit();
                                    if(exister_Prod(first2,P.id)==1)
                                    {   do

                                    {
                                        printf("\t\t\tProduit Existe deja !!\n");

                                        P=saisirProduit();
                                        }while(exister_Prod(first2,P.id)==1);
                                    }
                                    if(!(exister_Cat(first,P.type.Cat.idCat)==1))
                                    {
                                        Ajout_Liste_Categorie(P.type.Cat,&first);
                                    }
                                        if(!(exister_Type(first1,P.type.idType)==1))
                                        {
                                            Ajout_Liste_Type(P.type,&first1);
                                        }
                                    Ajout_Liste_Produit(P,&first2);

                            }

                        if(reponse()==1)
                        menu();
                        else
                        {
                        printf("\t\t\tA bientot");}
                        break;
                            }

                        case 2:
                        supprimer_prod(&first2);


                        if(reponse()==1)
                        menu();
                        else
                        printf("\t\t\tA bientot");
                        break;

                  case 3:
                        affichage_menuStock();
                        if(reponse()==1)
                        menu();
                        else
                        printf("\t\t\tA bientot");
                        break;



                  case 4:
                     affichage_menu();

                    if(reponse()==1)
                        menu();
                        else
                        printf("\t\t\tA bientot");
                        break;

                        case 5:

                        printf("\t\t\t-------------------------------------------------\n\t\t\t|");
                        printf("\t   Liste des Produit\t\t\t|\n");
                        printf("\t\t\t-------------------------------------------------\n");
                        affiche_Liste_Prod(first2);
                        if(reponse()==1)
                        {
                            printf("\n\n\n");
                            menu();
                        }

                        else
                        printf("\t\t\tA bientot");
                        break;


                    case 0 :  if(reponse()==1)
                    menu();
                    else
                    printf("\t\t\tA bientot");
                    default:
                    printf("\t\t\terror!!");
                    printf("\n");
                    affichage_menuProduit();
                        }
                break;
                case 4:

                        printf("\t\t\t-------------------------------------------------\n\t\t\t|");
                        printf("\t   Etat du stock\t\t\t|\n");
                        printf("\t\t\t-------------------------------------------------\n");
                        affiche_Liste_Prod(first2);
                        if(reponse()==1)
                        {
                            printf("\n\n\n");
                            menu();
                        }

                        else
                        printf("\t\t\tA bientot");
                break;
                case 5 : menu();
                break;
                case 0 :  if(reponse()==1)
                menu();
                else
                printf("\t\t\tA bientot");
              default:
                printf("\t\t\terror!!");
                printf("\n");
                affichage_menuStock();
              break;
            }
        break;


case 2: switch(affichage_menuVS())
            {
                case 1 :

                printf("\t\t\t\t\t\tVENTE ET STATISTIQUES/Vente\n");
                printf("\t\t\t****************************************************************\n");
                printf("\n");
                vente(&first2);
                if(reponse()==1)
                        menu();
                        else
                        printf("\t\t\tA bientot");
                        break;

                case 3 : menu();
                break;
                case 0 :  if(reponse()==1)
                menu();
                else
                printf("\t\t\tA bientot");
              default:
                printf("\t\t\terror!!");
                printf("\n");
                affichage_menuVS();
              break;
            }
break;


case 3:
  printf("\t\t\tVous etes sur ?\n\t\t\t1-Oui\n\t\t\t2-Non\n");

  printf("\t\t\t-->");
  scanf("%d",&x);
  if(x==1)
    printf("\t\t\tA Bientot !");
  else
    menu();

  break;
  default:

                printf("\t\t\terror!!");
                printf("\n");
                menu();



    } }menu();}
