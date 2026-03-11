# f1_races(date,last_winner,location,winner_team,laps,times)
- date -> last winner, location, winner_driver
- location -> laps, times 
- {date}+ = {date,last winner, location, winner_driver,laps, times }
- date est clé
## réduction à droite
- date -> last_winner
- date -> location
- date -> winner_driver
- location -> laps
- location -> times

## réduction à gauche
R1(date,last_winner,location,winner_driver)
R2(location,laps,time)

# f1_championship(championship_key,year,team,pos_team,points_team,1stDriver,nationality_1stDriver,pos_1stDriver,points_1stDriver,nationality_2ndDriver,points_2ndDriver,pos_2ndDriver)
- championship_key -> year,
- year -> team,pos_team,points_team
- team -> 1stDriver,nationality_1stDriver,pos_1stDriver,points_1stDriver,nationality_2ndDriver,points_2ndDriver,pos_2ndDriver

- championship_key est clé
## réduction à droite
- championship_key -> year
- year -> team
- year -> pos_team
- year -> points_team
- team -> driver1,driver2 
- driver1 -> 1stDriver
- driver1 -> nationality_1stDriver
- driver1 -> pos_1stDriver
- driver1 -> points_1stDriver
- driver2 -> nationality_2ndDriver
- driver2 -> points_2ndDriver
- driver2 -> pos_2ndDriver

## réduction à gauche
R1(year)
R2(year,team,pos_team,points_team)
R3(driver1,driver2)
R4(nationality_1stDriver,pos_1stDriver,points_1stDriver)
R5(nationality_2ndDriver,points_2ndDriver,pos_2ndDriver)

#### à changer après team->Driver,nationality_Driver,pos_Driver,points_Driver
#### team->Driver
#### Driver->nationality_Driver
#### Driver->pos_Driver
#### Driver->points_Driver
etc

# f1_seasib(year,wdc,points_wdc_1st,number_titles_driver,winning_driver_team,wcc,points_wcc_1st,driver1,driver2,number_titles_team,secondPlaceDriver,secondPlaceWCC,points_wcc_2nd,secondPlaceWCC_1st_driver,secondPlaceWCC_2ndDriver)
- year -> winner
- winner -> wdc,wcc,driver,points_team1
- second -> secondPlaceDriver, points_team2,SecondPlaceWCC
- points_team1 -> points_wdc_1st,points_wcc_1st
- points_team2 -> points_wdc_2nd,points_wcc_2nd
- SecondPlaceWCC -> SecondPlaceWCC_1stDriver,SecondPlaceWCC_2nd_Driver
- driver -> driver1,driver2
- prestige -> number_titles_team,number_titles_driver
- 

- year est clé
## réduction à droite
- year -> winner
- driver -> driver1
- driver -> driver2
- prestige -> number_titles_team
- prestige -> number_titles_driver
- winner -> wdc
- winner -> wcc
- winner -> driver
- winner -> points_team1
- second -> secondPlaceDriver
- second -> points_team2
- second -> SecondPlaceWCC
- SecondPlaceWCC -> SecondPlaceWCC_1stDriver
- SecondPlaceWCC -> SecondPlaceWCC_2nd_Driver
- points_team2 -> points_wdc_2nd
- points_team2 -> points_wcc_2nd
- points_team1 -> points_wdc_1st
- points_team1 -> points_wcc_1st

## réduction à gauche
rien à faire

## spi/spd
- R1(year,winner)
- R2(driver,driver1,driver2)
- R3(prestige, number_titles_team,number_titles_driver)
- R4(winner,wdc,wcc,driver,points_team1)
- R5(second,secondPlaceDriver, points_team2,SecondPlaceWCC)
- R6(SecondPlaceWCC,SecondPlaceWCC_1stDriver,SecondPlaceWCC_2nd_Driver)
- R7(points_team2, points_wdc_2nd,points_wcc_2nd)
- R8(points_team1,points_wdc_1st,points_wcc_1st)