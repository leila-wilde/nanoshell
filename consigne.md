<a id="fr"></a>

<div align="center">
  <a href="#en">EN</a> · 
  <a href="#fr">FR</a>
</div>

# Nanoshell
*fork() + execve() is all you need.*

## Introduction

L’objectif de ce projet est d’implémenter un **shell Unix**.

Il y a environ 10.000 features possibles à implémenter dans un shell. Le vôtre n’aura que les features essentielles. Le but est de recoder les fonctionnalités essentielles et de comprendre **comment les fonctions fork() / execve() / waitpid() s’emboîtent !**

# Le projet

Voici les fonctionnalités à gérer :
- Quand vous lancez votre programme, vous devez **afficher un prompt.**
- L’utilisateur **saisit une chaîne de caractères** et appuie sur “Entrée” (on ne vous demande pas une gestion avancée de la ligne de saisie : ni déplacement, ni raccourcis, etc… [Curieux](https://zestedesavoir.com/tutoriels/1733/termcap-et-terminfo/) ? )
- Si la chaîne décrit un **exécutable présent dans le path**, celui-ci est exécuté avec les paramètres.
- Si la chaîne est un **builtin** reconnu, ce builtin est exécuté avec les paramètres. Builtins à implémenter : `cd`, `exit`, `pwd`, `env`
- Sinon, votre shell doit afficher une erreur :
```
?> grutcblu
nanoshell: weird, grutcblu is not here… :/
```
Concernant `cd`, on vous demande simplement de gérer “cd ..”, “cd ~”, “cd” tout court, et `cd somedir` (un répertoire du dossier courant, pas de chemin sophistiqué).

## Implémentation

**Lecture de la ligne :**
- Vous lisez sur le file descriptor `stdin` (càd 0)
- Vous pouvez découper la ligne par espaces, sans parsing sophistiqué
- Pas de gestion des guillemets requise, ni d’échappement de caractères
- Une ligne vide ne fait rien

**Gestion du PATH :**
Si la commande contient un “/”, tenter d’exécuter la commande dans le répertoire courant. Sinon :
- Lire la variable d’environnement PATH
- Tester chaque répertoire qui s’y trouve
- Construire le chemin complet du binaire avec la première “solution” trouvée (ex. : `/usr/local/bin/python3`)

## Aller plus loin

- Ctrl-D (EOF) quitte le shell proprement
- Epurage et parsing avant d'exécuter la commande
- Gestion des esperluettes
- [Gestion des pipes](https://man7.org/linux/man-pages/man2/pipe.2.html)
- Gestion des redirections

## Compétences visées

- C
- environnement UNIX

## Rendu

Le projet est à rendre sur votre github : https://github.com/prenom-nom/nanoshell

## Base de connaissances

- https://man7.org/linux/man-pages/man2/execve.2.html
- https://man7.org/linux/man-pages/man2/fork.2.html
- https://man7.org/linux/man-pages/man2/wait.2.html
- https://man7.org/linux/man-pages/man2/getpid.2.html
- https://man7.org/linux/man-pages/man2/chdir.2.html
- https://en.wikipedia.org/wiki/Shell_builtin

<a id="en"></a>

<div align="center">
  <a href="#en">EN</a> · 
  <a href="#fr">FR</a>
</div>

# Nanoshell
*fork() + execve() is all you need.*

## Introduction

The objective of this project is to implement a **Unix shell**.

There are approximately 10,000 possible features to implement in a shell. Yours will only have the essential features. The goal is to recode the essential functionalities and understand **how fork() / execve() / waitpid() functions fit together!**

# The Project

Here are the features to manage:
- When you launch your program, you must **display a prompt.**
- The user **enters a string of characters** and presses "Enter" (we are not asking for advanced input line handling: no movement, no shortcuts, etc… [Curious](https://zestedesavoir.com/tutoriels/1733/termcap-et-terminfo/)? )
- If the string describes an **executable present in the path**, it is executed with the parameters.
- If the string is a recognized **builtin**, this builtin is executed with the parameters. Builtins to implement: `cd`, `exit`, `pwd`, `env`
- Otherwise, your shell must display an error:
```
?> grutcblu
nanoshell: weird, grutcblu is not here… :/
```
Regarding `cd`, you are simply asked to handle "cd ..", "cd ~", "cd" alone, and `cd somedir` (a directory in the current folder, no sophisticated path).

## Implementation

**Reading the line:**
- You read from the file descriptor `stdin` (i.e. 0)
- You can split the line by spaces, without sophisticated parsing
- No quote handling required, nor character escaping
- An empty line does nothing

**PATH Management:**
If the command contains a "/", try to execute the command in the current directory. Otherwise:
- Read the PATH environment variable
- Test each directory found in it
- Build the complete path of the binary with the first "solution" found (e.g.: `/usr/local/bin/python3`)

## Going Further

- Ctrl-D (EOF) gracefully exits the shell
- Cleanup and parsing before executing the command
- Ampersand handling
- [Pipe management](https://man7.org/linux/man-pages/man2/pipe.2.html)
- Redirection handling

## Targeted Skills

- C
- UNIX environment

## Submission

The project is to be submitted on your github: https://github.com/first-name-last-name/nanoshell

## Knowledge Base

- https://man7.org/linux/man-pages/man2/execve.2.html
- https://man7.org/linux/man-pages/man2/fork.2.html
- https://man7.org/linux/man-pages/man2/wait.2.html
- https://man7.org/linux/man-pages/man2/getpid.2.html
- https://man7.org/linux/man-pages/man2/chdir.2.html
- https://en.wikipedia.org/wiki/Shell_builtin