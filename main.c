#include <stdio.h>
#include <stdlib.h>
#include "sun.h"
int main(){
	po *arr=NULL;
	int n=0;
	int stop=0;
	while (stop!=1){
		int key;
		printf("1-load db  2-print  3-search  4-stop\n");
		scanf("%d", &key);
		switch(key){
			case 1:{
		  		int key2;
				printf("1-create,  2-read\n");
				scanf("%d", &key2);
				if (key2==1){
					create(&arr,&n);
					if (!arr)
						printf("error");
					else{
						printf("created %d\n",n);
						write(arr,n);
					}
				}
				else{
					read(&arr,&n);
					 if (!arr)
                                                printf("error");
                                        else
                                                printf("load  %d",n);
				}
				break;
			}
			case 2:
				for(int i=0;i<n;i++)
					printf("%s %d %d\n", arr[i].adres, arr[i].index, arr[i].num);
				break;
			case 3:
				read(&arr,&n);
				printf("perfom a search by :\n");
				printf("1-adres\n2-index\n3-num\n");
				int numpoiska;
				printf("numpoiska= ");
				scanf("%d",&numpoiska);
				search(arr,n,numpoiska);
				break;
			case  4:
				stop=1;
				break;
		}
	}
	if (arr)
		free(arr);
	return 0;
}

