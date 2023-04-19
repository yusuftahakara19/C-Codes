#include <stdio.h>
#include <stdlib.h>


void labirentiOku(char* dosyaAdi,int elmaAdet,int satir,int sutun,char **labirent,int *baslangic_i,int *baslangic_j)
{
	char c;

	FILE* labirentFile = fopen(dosyaAdi, "r");
    int i,j,k;
	if (labirentFile) 
	{
       for(i=0;i<satir;i++){
       	for(j=0;j<sutun;j++){
       		c=getc(labirentFile);
       		
       		if(c=='\n' || c=='\r')
			   c=getc(labirentFile);
			
			labirent[i][j]=c;
			if(c=='b'){
				*baslangic_i = i;
				*baslangic_j = j;
			}
			
			   
		   }
	   }
	   
	   
	   for(k=0;k<elmaAdet;k++){
	   	 i = rand()%satir+1;
	   	 j = rand()%sutun+1;
	   	 
	   	 if(labirent[i][j]==' '){
	   	 	labirent[i][j] ='O';
			}
	   }
	} 
	else {
		printf("labirent.txt bulunamadý...");
		return;
	}

	fclose(labirentFile);
}

void labirentYazdir(int satir,int sutun,char **labirent){
  int i,j;
  for(i=0;i<satir;i++){
  	for(j=0;j<sutun;j++){
  		printf("%c",labirent[i][j]);
	  }
	  printf("\n");
  }
}

int** gezilenler_doldur(char** labirent,int** gezilenler,int satir,int sutun){
  int i,j;
  for(i=0;i<satir;i++){
  	for(j=0;j<sutun;j++){
  		if(labirent[i][j]=='c')
  		 gezilenler[i][j] = 1;
  		else if(labirent[i][j]=='-' || labirent[i][j]=='+' || labirent[i][j]=='|')
	  	 gezilenler[i][j] = 0;
  		else if(labirent[i][j]=='O')
  		 gezilenler[i][j] = 2;
		else if(labirent[i][j]=='*')
		  gezilenler[i][j] = 7;
		else 
		  gezilenler[i][j] = 3; 
		  
	  }
  }
  
  return gezilenler;
}




int dfs(int row, int col,int **gezilenler,char **labirent,int l_satir,int l_sutun,int *point,int *cikmazaGirildiMi)
{
	int* konum = &gezilenler[row][col];

	if (*konum == 1) {
		return 1;
	}
	
	if (*konum == 3 || *konum == 2) {
		if(*konum == 2){
			 *point += 10;
		}
		
		*konum = 7;
		
		labirent[row][col] = '*';
        labirentYazdir(l_satir,l_sutun,labirent);
        printf("\n\n  Score : %d", *point);
        Sleep(10);
        system("cls");
        
		if (dfs(row, col - 1,gezilenler,labirent,l_satir,l_sutun,point,cikmazaGirildiMi)){
			*konum = 7;
			*cikmazaGirildiMi=0;
			return 1;
		} 
		if (dfs(row + 1, col,gezilenler,labirent,l_satir,l_sutun,point,cikmazaGirildiMi)){
			*konum = 7;
			*cikmazaGirildiMi=0;
			return 1;
		} 
		if (dfs(row, col + 1,gezilenler,labirent,l_satir,l_sutun,point,cikmazaGirildiMi)){
			*konum = 7;
			*cikmazaGirildiMi=0;
			return 1;		
		} 
		if (dfs(row - 1, col,gezilenler,labirent,l_satir,l_sutun,point,cikmazaGirildiMi)){
			*konum = 7;
			*cikmazaGirildiMi=0;
			return 1;
		}
		
	   	if(*cikmazaGirildiMi == 1)
	      *point -= 5;
	
		    
	 	
	
	}



	return 0;
}




int main(int argc, char *argv[]) {
	int satir,sutun,elmaAdeti,i;
	int **gezilenler;
	char **labirent;
	int *labirent_baslangic_x = malloc(sizeof(int));
	int *labirent_baslangic_y = malloc(sizeof(int));
	int *point;
	int p = 0;
	point = &p;
    int c = 0;
	int *cikmazaGirildiMi;
	cikmazaGirildiMi = &c;
	printf("Enter the number of rows (31 for the given maze):");
	scanf("%d",&satir);
	printf("Enter the number of columns (64 for the given maze):");
	scanf("%d",&sutun);
	printf("Enter the maximum number of apples:");
	scanf("%d",&elmaAdeti);
	
	labirent = malloc(satir*sizeof(char*));
	for(i=0; i<sutun;i++){
		 labirent[i]=malloc(sutun*sizeof(char*));
	}
	
	gezilenler = malloc(satir * sizeof(int*));
    for(i=0; i<satir;i++){
		 gezilenler[i]=malloc(sutun * sizeof(int*));
	}
    labirentiOku("labirent.txt",elmaAdeti,satir,sutun,labirent,labirent_baslangic_x,labirent_baslangic_y);
    labirentYazdir( satir, sutun, labirent);
    gezilenler_doldur(labirent,gezilenler,satir,sutun);

 if (!dfs(*labirent_baslangic_x  , *labirent_baslangic_y,gezilenler,labirent,satir,sutun,point,cikmazaGirildiMi)) {
		printf("The exit could not be reached...\n");
	} else {
		printf("\n");
		labirentYazdir(satir,sutun,labirent);
		printf("\n\n Score : %d",p);
	}

	return 0;

}
