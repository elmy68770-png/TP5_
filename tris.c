#include <stdlib.h>
#include "tris.h"
void copier(int dest[], int src[], int n){ for(int i=0;i<n;i++) dest[i]=src[i]; }
int est_trie(int t[], int n){ for(int i=1;i<n;i++) if(t[i]<t[i-1]) return 0; return 1; }
void tri_insertion(int t[], int n){ for(int i=1;i<n;i++){ int x=t[i]; int j=i-1; while(j>=0 && t[j]>x){ t[j+1]=t[j]; j--; } t[j+1]=x; } }
static void fusionner(int t[], int g, int m, int d, int tmp[]){ int i=g, j=m+1, k=g; while(i<=m && j<=d){ if(t[i]<=t[j]) tmp[k++]=t[i++]; else tmp[k++]=t[j++]; } while(i<=m) tmp[k++]=t[i++]; while(j<=d) tmp[k++]=t[j++]; for(int p=g;p<=d;p++) t[p]=tmp[p]; }
static void fusion_rec(int t[], int g, int d, int tmp[]){ if(g>=d) return; int m=(g+d)/2; fusion_rec(t,g,m,tmp); fusion_rec(t,m+1,d,tmp); fusionner(t,g,m,d,tmp); }
void tri_fusion(int t[], int n){ if(n<=1) return; int *tmp=malloc(sizeof(int)*n); if(!tmp) exit(1); fusion_rec(t,0,n-1,tmp); free(tmp); }
static int partitionner(int t[], int g, int d){ int pivot=t[d]; int i=g-1; for(int j=g;j<d;j++){ if(t[j]<=pivot){ i++; int tmp=t[i]; t[i]=t[j]; t[j]=tmp; } } int tmp=t[i+1]; t[i+1]=t[d]; t[d]=tmp; return i+1; }
static void rapide_rec(int t[], int g, int d){ while(g<d){ int p=partitionner(t,g,d); if(p-g < d-p){ rapide_rec(t,g,p-1); g=p+1; } else { rapide_rec(t,p+1,d); d=p-1; } } }
void tri_rapide(int t[], int n){ if(n>1) rapide_rec(t,0,n-1); }
