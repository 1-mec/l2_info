# TD3
## ex1 
#### 1 . Que signie chaque DF ?
- l'age et le nom font parti du matricule
- le club fait parti du matricule
- la salle fait parti d'un club

#### correction : 
- matricule détermine nom et age
- un étudiant peut jouer dans un seul club
- club se trouve dans salle

#### 2 . Quelle(s) est(sont) la(les) clé(s) de la relation ?
- Matricule car elle n'est pas redéfinie par un autre attribut

#### correction :
- Matricule n'est dans aucune df et sa fermeture transitive détermine tout le monde

#### 3 . Mettre ces informations dans un ensemble de schémas de relations en 3FN
<img width="1222" height="264" alt="image" src="https://github.com/user-attachments/assets/aa93a568-0c0d-4791-a847-3e8e18d88876" />

#### correction :
1. ouverture minimal

- Matricule->nom

- Matricule->age

- Matricule->club

- Club->salle

2. décomposition

Eleve(Matricule,Nom,age,club) ; clé matricule

Club(club,salle) ; clé club

3. on vérifie qu'au moins une clé de la relation initiale est une des bouvelles relation

## ex2
#### 1 . liminer les DFs redondantes
dans :
1.Mle-Etud -> Nom-Etud, Classe

2.No-Ens -> Nom-Ens

3.Cours -> Module

4.Cours, Module -> Nb-h

5.Classe, Cours, Module -> No-Ens, Nom-Ens

6.Mle-Etud, Cours, Module -> Note

on peut supprimer la 3 et la 2

#### 2 . Quelle(s) est(sont) la(les) clé(s) de la relation ?
- Mle-Etud, Cours et Module

#### 3 . Normalier la relation en 3FN
- Departement (Mle-Etud, Note, Classe, Cours, Module, No-Ens, Nom-Ens, Nom-Etud, Nb-h)

on décompose en :
- Departement (Classe,Cours,Module,Nb-h,No-Ens) ; Module
- Etudiant(Mle-Etud,Note,Cours) ; Mle-Etud
  
## ex3
EMPLOYES (NumE, Nom, Salaire, Département, Bâtiment)

#### 1 . Déterminer les dépendances fonctionnelles (voir TD1)
- NumE -> NumE,Nom,Salaire,Departement
- Departement -> Batiment

#### 2. 
- {NumE}+ = {Nom,Salaire,Département,Bâtiment}
- a-1Fn ? oui car attributs = valeurs atomiques
- b-Fn ? oui car la clé n'est pas décomposée
- c-3Fn ? non car on a Departement -> Bâtiement

#### 3.
- Departement -> NumE
#### correction
- a. ouverture minimal
NumE -> Nom

NumE -> salaire

NumE -> département

Département -> Batiment

- b. décomposition de df
Employés(NUmE,Nom,Salaire,département)

Département(département,batiment)

- c. vérification

On a : - NumE clé pour employé
       - Toutes les df sont préservées

C'est en 3fn

Employés(NUmE,Nom,Salaire,département)

Département(département,batiment)

## ex4
Commandes (NumCom, DateCom, NumCli, AdrCli, NumProd, Prix, Qte)
#### 1 . Déterminer les dépendances fonctionnelles
- NumProd -> Prix
- NumCom -> DateCom, NumCli, AdrCli, Prix, Qte, NumProduit

#### 2 . Quelle(s) est(sont) la(les) clé(s) de cette relation ?
- NumProd et NumCom

#### 3 . En quelle forme normale elle est ? 
- la relation est en 2nf car il y a qu'une clé

#### correction
#### 1
- NumCom -> DateCom,NumCli,AdrCli
- NumProd -> Prix
- NumCom , NumProd -> gte

#### 2 .clé 
- {NumCom,NumProd}+ = {DateCom,NumCLi,AdrCli,Prix,gte}

Donc clé = (NumCom,NumProd)

#### 3 . Vérif
- a . 1nf oui 
- b . 2nf non -> prix dépend partiellement de la clé (NumProd->Prix)
  
## ex5
Projection (NoFilm, TitreFilm, DuréeFilm, NoSalle, CapacitéSalle,TypePlace, PrixPlace, DateProjection, HeureDeb)
#### 1 . Déterminer les dépendances fonctionnelles (voir TD1)
- NoSalle -> TitreFilm, DuréeFilm,NoSalle , CapaitéSalle, TypePlace, HeureDeb,DateProjection
- NoFilm -> TitreFilm, HeureDeb, 

#### 2 . En déduire un schéma de relations en 3FN
- NoSalle -> TitreFilm, DuréeFilm,NoSalle , CapaitéSalle, TypePlace, HeureDeb,DateProjection
- NoFilm -> TitreFilm, HeureDeb, 

## ex 6
L'Entreprise Vendetout voudrait créer une base de données relationnelle pour automatiser la gestion de ses ventes
et de ses approvisionnements. Elle gère d'une part des informations sur les commandes des clients, et d'autre
part les produits en stock avec leurs fournisseurs.
Les informations à garder sont :
      
      - Pour un client, un numéro unique, un nom ou raison sociale, le solde client et les adresses possibles de livraison. 
      - Pour chaque commande de client, un numéro unique, la date de commande, l'adresse de livraison et les produits commandés avec la quantité éventuelle. 
      - Pour un produit, on a un numéro unique, un nom, la quantité actuelle en stock, le seuil minimum, la liste des fournisseurs avec le prix correspondant.
      - Les fournisseurs sont décrits quant à eux, par un numéro unique, un nom et une adresse.


#### 1
- Client(NoCli,Nom, Solde, adresses, date_commandes, NoCommande)
- Commande (NoCommande,NumProduit, NomProduit, Qte)
- Produit(NoProd,Nom_Prod,Qte_Stock,Seuil,Fournisseur)
- Fournisseur(Nom_Fourniseeur,Adresses_Fournisseur, Numero_Fournisseur)






