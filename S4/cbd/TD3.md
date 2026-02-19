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
Commandes (NumCom, DateCom, NumCli, AdrCli, NumProd, Prix, Qte)
#### 1 . Déterminer les dépendances fonctionnelles
- NumProd -> Prix
- NumCom -> DateCom, NumCli, AdrCli, Prix, Qte

#### 2 . Quelle(s) est(sont) la(les) clé(s) de cette relation ?
- NumProd et NumCom

#### 2 . En quelle forme normale elle est ? 
- la relation est en 3nf

  
