[Retour à la Liste des Projets](../README.md)

# Générateur d'Acronymes

**Auteur :** pmnv

**Date :** 31/10/2023

## Description

Ce programme ouvre un fichier, lit son contenu et génère des acronymes pour chaque phrase. Un acronyme est créé en prenant la première lettre de chaque mot dans une phrase, et les signes de ponctuation tels que les points, les points d'exclamation ou les points d'interrogation sont inclus dans l'acronyme.

## Exemple

- Entrée : "Bonjour le Monde !"
- Sortie : "BLM !"

- Entrée : "Bonjour le Monde."
- Sortie : "BLM."

## Utilisation

Pour utiliser le programme, compilez-le et exécutez-le avec le nom du fichier en tant qu'argument de ligne de commande. Il lira le contenu du fichier, générera des acronymes et affichera le résultat.

```bash
./acronym fichier.txt
```

## Fonctionnement

1. Le programme lit le fichier spécifié en tant qu'argument de ligne de commande.

2. Il traite le contenu et crée des acronymes en se basant sur les règles définies.

3. Les acronymes générés sont ensuite affichés.

## Compilation

Pour compiler le programme, utilisez la commande suivante :

```bash
gcc -o acronym acronym.c
```

## Exécution

Exécutez le programme en spécifiant le nom du fichier en tant qu'argument de ligne de commande :

```bash
./acronym sentences
```

## Licence

Ce code est fourni sous une licence MIT. N'hésitez pas à l'utiliser et à le modifier selon vos besoins.

## Contributions

Les contributions sont les bienvenues. Veuillez soumettre des problèmes ou des demandes de tirage si vous avez des améliorations ou des suggestions.

---

[Retour à la Liste des Projets](../README.md)