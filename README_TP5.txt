TP5 - Tris et integration au mini-projet chapitre 8
1. Tri fusion -> tris.c / tris.h : diviser en deux, trier, fusionner. Toujours O(n log n), stable.
2. Tri rapide -> tris.c / tris.h : pivot = dernier element, partition de Lomuto.
3. Verification : tableau petit {5,2,9,1,7,3} -> 1 2 3 5 7 9 pour les deux tris.
COMPILATION : gcc -std=c17 -Wall -Wextra -g tris.c main_tris.c -o test_tris.exe
EXECUTION : .\test_tris.exe
PIRE CAS OBSERVE : Sur tableau deja trie, le tri rapide seffondre.
Pourquoi : Pivot = dernier element = deja le max. Partition = 0 a gauche, n-1 a droite. On recommence n fois. Donc O(n^2).
Le tri fusion ne bouge pas : il coupe toujours au milieu, donc toujours O(n log n).
Solution : pivot aleatoire, ou pivot mediane de 3, ou tri fusion si on veut la garantie.
MEMOIRE : Un seul malloc dans tri_fusion pour le tableau temporaire, libere avec free. Aucune fuite.
