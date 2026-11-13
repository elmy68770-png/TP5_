#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "tris.h"
static void melanger(int t[], int n){ for(int i=n-1;i>0;i--){ int j=rand()%(i+1); int tmp=t[i]; t[i]=t[j]; t[j]=tmp; } }
static double bench(void (*tri)(int*,int), int base[], int n){ int *c=malloc(sizeof(int)*n); copier(c,base,n); clock_t d=clock(); tri(c,n); clock_t f=clock(); double s=(double)(f-d)/CLOCKS_PER_SEC; if(!est_trie(c,n)) printf("ERREUR\n"); free(c); return s; }
int main(){ srand(42); int petit[]={5,2,9,1,7,3}; int n=6; int a[6], b[6]; copier(a,petit,n); tri_fusion(a,n); copier(b,petit,n); tri_rapide(b,n);
printf("Test petit : fusion = "); for(int i=0;i<n;i++) printf("%d ",a[i]);
printf(" | rapide = "); for(int i=0;i<n;i++) printf("%d ",b[i]); printf("\n");
int N=20000; int *alea=malloc(sizeof(int)*N); int *trie=malloc(sizeof(int)*N); for(int i=0;i<N;i++){ alea[i]=rand()%100000; trie[i]=i; } melanger(alea,N);
double fA=bench(tri_fusion,alea,N); double fT=bench(tri_fusion,trie,N); double rA=bench(tri_rapide,alea,N);
int N2=5000; int *trie2=malloc(sizeof(int)*N2); for(int i=0;i<N2;i++) trie2[i]=i; double rT=bench(tri_rapide,trie2,N2);
printf("FUSION_ALEA : %f\n",fA); printf("FUSION_TRIE : %f\n",fT); printf("RAPIDE_ALEA : %f\n",rA); printf("RAPIDE_TRIE : %f\n",rT);
printf("PIRE CAS : tri rapide pivot dernier element sur tableau trie -> partition 0 / n-1 -> O(n^2)\n");
free(alea); free(trie); free(trie2); return 0; }
