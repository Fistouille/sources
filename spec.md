#Spec Protocole
##Chapitre 1 : Connexion au robot

Le robot envoie un message de Tag 0 contenant son IP local pour signaler son arriver dans le réseau a tout les robots, à la suite de se message il devient le chef.
Le nombre de réponse déterminera son numéro dans l'essaim.

####Tag 0 : IP local     => Je suis nouveau  le robot devien le chef

##Chapitre 2 : Réponse a une connexion d'un autre robot

Si un robot reçoit un ping de Tag 0 il devras renvoyer une réponse de Tag 1 qui signal a l'autre robot qu'il n'est pas seul et lui permet de trouver son numéro.
Si le robot était chef l'envoie de se message le met au niveau de suiveur et incrémente le numéro du leader.

####Tag 1 : true        => Réponse réponse des autre robot a un Tag 0     le robot qui était le chef ne l'est plus sinon rien

##Chapitre 3 : Signalement d'un nouveau leader

Si le leader se déconnecte, les autres robots décrémentent le numéro du leader. Si le nouveau numéro du leader devient celui du robot il celui-ci envoie le message de Tag 2 en broadcast a tout les autres
 
####Tag 2 : IP local     => Je suis le nouveau leader

##Chapitre 3 : Le leader tourne 

Si le leader tourne il envoie la valeur de la boussole en broadcast grâce a un message de Tag 3, les autres robot devront adopter la même valeur
 
####Tag 3 : int        => valeur de la boussole ( de 0 a 360 anti horraire )

##Chapitre 4 : Le leader Avance ou Recule

Si le leader AVANCER il devra envoyer en broadcast  la valeur 1, le robot qui recevra le message devra s'adapter en conséquence.
Si le leader NE BOUGE PAS il devra envoyer en broadcast  la valeur 0, le robot qui recevra le message devra s'adapter en conséquence. 
Si le leader RECULE il devra envoyer en broadcast  la valeur 0, le robot qui recevra le message devra s'adapter en conséquence.

####Tag 4 : int        => valeur de la boussole ( -1 reculer, 0 stop , 1 avancer )

##Chapitre 5 : Détail 

La communication  est de type UDP

Les messages devront correspondre a un message de type
TLV ( Tag/ Length/ Value)
