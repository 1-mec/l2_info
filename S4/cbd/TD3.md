# TD3
## ex1 
#### 1 . Que signie chaque DF ?
- l'age et le nom font parti du matricule
- le club fait parti du matricule
- la salle fait parti d'un club

#### 2 . Quelle(s) est(sont) la(les) clé(s) de la relation ?
- Matricule car elle n'est pas redéfinie par un autre attribut

#### 3 . Mettre ces informations dans un ensemble de schémas de relations en 3FN
<img width="1222" height="264" alt="image" src="https://github.com/user-attachments/assets/aa93a568-0c0d-4791-a847-3e8e18d88876" />

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
- 
