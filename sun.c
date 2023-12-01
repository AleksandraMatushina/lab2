#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "sun.h"
void create(po ** arr,int *n){
        printf("n= ");
	scanf("%d",n);
	if (*n<=0)
		return;
	*arr=(po*)calloc(*n,sizeof(po));
	for (int i=0;i<*n;i++){
		printf("adres= ");
		scanf("%s", (*arr)[i].adres);
	        printf("index");
                scanf("%d",& (*arr)[i].index);
		printf("num");
                scanf("%d",& (*arr)[i].num);
	}
}
void read(po **arr,int *n){
	FILE *k=fopen("file.txt","r");
	if (!k)
		return;
	if (fscanf(k,"%d",n)!=1){
		fclose(k);
		return;
	}
	if (*n<=0){
		fclose(k);
		return;
	}
	*arr=(po*)calloc(*n,sizeof(po));
	for (int i=0;i<*n;i++){
		if (fscanf(k, "%s %d %d", (*arr)[i].adres,&(*arr)[i].index,& (*arr)[i].num)!=3)
			break;
	fclose(k);
	}
}
void write(po *arr,int n){
	if (n<=0)
		return;
	FILE *k=fopen("file.txt","a");
	 if (!k)
                return;
	for (int i=0;i<n;i++){
                fprintf(k, "%s %d %d\n", arr[i].adres,arr[i].index,arr[i].num);
	}
	fclose(k);
}
void search(po *arr,int n, int numpoiska){
	char sadres[150];
	int sindex;
	int snum;
	switch(numpoiska){
		case 1:
			printf("What pochtoviy adres are you interested in?");
			scanf("%s",sadres);
			while (getchar()!='\n'){
				for (int i=0;i<n;i++){
					if(!strcmp(arr[i].adres, sadres))
						printf("%s %d %d\n", arr[i].adres,arr[i].index,arr[i].num);
				}
			}
			break;
		 case 2:
                        printf("What index are you interested in?");
                        scanf("%d",&sindex);
                                for (int i=0;i<n;i++){
                                        if(sindex==arr[i].index)
                                                printf("%s %d %d\n", arr[i].adres,arr[i].index,arr[i].num);
                                }
                        break;
		case 3:
                        printf("Which branch number are you interested in?");
                        scanf("%d",&snum);
                                for (int i=0;i<n;i++){
                                        if(snum==arr[i].num)
                                                printf("%s %d %d\n", arr[i].adres,arr[i].index,arr[i].num);
                                }
                        break;
		default:
			printf("error");
	}
}

