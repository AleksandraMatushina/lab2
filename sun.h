typedef struct pochtovoeotdelenie{
	char adres[150];
	int  index;
	int num;
}po;
void create(po **arr,int *n);
void read(po **arr,int *n);
void write(po *arr,int n);
void search(po *arr,int n,int numpoiska);	
