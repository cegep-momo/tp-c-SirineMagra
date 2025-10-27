# Construire le projet
Vous pouvez utiliser un dev container de base C++ de VScode.
Le projet utilise cmake, pensez à l'inclure dans votre dev container.

Voici les lignes de commandes pour compiler le projet:
```
$ mkdir build
$ cd build
$ cmake ..
$ make
```

# Répertoire data

Il contient 2 fichiers `books.txt`et `users.txt` que vous pouvez utilisez pour tester votre code.
Pour ca il suffit de les copiers dans le repertoire `build` avec l'application `bibliotheque`

# Question 1:C++

L'importation des données à partir d'un fichier(.txt/.csv).
La fonction se trouve dans le filemanager. 
Pour débuter, il va falloit créer un ifstream(ça va permettre de lire le contenu du fichier). Si le fichier est acessible, on va pouvoir lire ligne par ligne (getline()) le contenu du fichier et par la suite le stocker si néessaire. (Dans le filemanager, à chaque ligne on récupère le contenu (selon un motif présent dans la classe Book) et on insère les données dans une nouvelle variable Book)

# Question 2:Options de développement possible

La meilleure solution serait d'instaurer une base de données en MySQL. La gestion des éléments sera plus pratique et il y aura moins de gestion (ça pourrait aussi permettre d'éviter quelques erreurs de gestion de fichiers, etc). Et comme MySQL est compatible avec C++, il sera facile de l'instaurer dans notre programme.