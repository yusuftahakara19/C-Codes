#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100
#define MAX_NAME_LEN 256
#define MAX_LINE_LEN 255
#define MAX_LINES 1024

typedef struct Node {
	int num;
	char name[MAX_NAME_LEN];
    char surname[MAX_NAME_LEN];
    int visited;
    
    struct Node *follow[MAX_NODES];
    int numberOfFollow;
    int numberOfFollower; // in-degree 
  
} Node;

typedef struct Graph {
  Node *nodes[MAX_NODES];
  int nodeCount;
} Graph;







// BFS algoritmas�n� kullanarak, d���me do�rudan ve dolayl� yoldan gelen toplam ba�lant� say�s�n� hesaplayan fonksiyon
int getTotalConnectionCount(Graph *graph, Node *node) {
	int totalConnections,j,exist = 0;
   totalConnections = node->numberOfFollower;  // do�rudan gelen ba�lant�lar
 
  node->visited = 1;
  Node *queue[MAX_NODES], *curr,*neighbor;  
  int head = 0, tail = 0,i;
  queue[tail++] = node;  // ba�lang�� d���m�n� kuyru�a eklendi
  while (head < tail) {
    curr = queue[head++];  // kuyruktaki ilk d���m� ziyaret edildi
    for ( i = 0; i < curr->numberOfFollow; i++) {
      neighbor = curr->follow[i];
      // neighbor'�n takip ettiklerinde bizim d���m�m�z var m�? y�nl� graf oldu�u i�in bu i�lemi yapt�k
      exist=0;
      for(j=0;j<neighbor->numberOfFollow;j++){
      	if(neighbor->follow[j]->num == curr->num){
      		exist= 1;
		  }
	  }
      if (!neighbor->visited && exist == 1) {
        // Ziyaret edilmemi� d���mler kuyru�a eklendi
        neighbor->visited = 1;
        queue[tail++] = neighbor;
        totalConnections += neighbor->numberOfFollower;  // in-degree de�erleri topland�
      }
    }
  }

  return totalConnections;
}




// in-degree de�eri M'den k���k olan d���mlerin elenmesi
void removeNodesWithLowInDegree(Graph *graph, int M) {
  int i, j,nodesRemoved=0;
 Node *node,*followingNode;
  // Eleme i�lemini yaparken, d���mler s�rayla gezilecek

  for (i = 0; i < graph->nodeCount; i++) {
    node = graph->nodes[i];
  
    if (node->numberOfFollower < M) {

    	nodesRemoved=1;
      // Eleme i�lemini yaparken, d���m�n takip etti�i di�er d���mler gezilecek
      for (j = 0; j < node->numberOfFollow; j++) {
      		 
        followingNode = node->follow[j];
        followingNode->numberOfFollower--;  // Takip edilen d���mlerin in-degree de�erleri
      }

      // Eleme i�lemini yaparken, nodes dizisinde bo�luk b�rak�lmayacak
      for (j = i; j < graph->nodeCount; j++) {
        graph->nodes[j] = graph->nodes[j + 1];
      }
      
      graph->nodeCount--;
      i--;  // Eleme i�leminden sonra, d���mlerin indeksleri bir ad�m gerilece�i i�in i de�eri azalt�lacak
    }	 
  }

  // Eleme i�lemini M'in alt�na d��en d���mler kalmayana kadar devam edilecek
  if (graph->nodeCount > 0 && nodesRemoved==1) {
    removeNodesWithLowInDegree(graph, M);
  }
}

int main() {
	int i, lineCount =0,node_index,m,y,x,secim;
		  Graph *graph = malloc(sizeof(Graph));
  graph->nodeCount = 0;

   
  FILE *file = fopen("socialNET.txt", "r");

// Sat�rlar� depolamak i�in bir dizi olu�turduk
char *lines[MAX_LINES];

// Dosyay� sat�r sat�r okuyarak diziye ekledik
char line[MAX_LINE_LEN];
char input_string[MAX_LINE_LEN];
char *node_number, *first_name, *last_name,*parca;
 

while (fgets(line, MAX_LINE_LEN, file) != NULL) {
  lines[lineCount++] = strdup(line);
}

   // Initialize nodes
   for(i=0;i<lineCount;i++){
	if(i%2==0){
	     graph->nodes[graph->nodeCount] = malloc(sizeof(Node));
		strcpy(input_string, lines[i]);
		node_number = strtok(input_string, ",");
        first_name = strtok(NULL, ",");
        last_name = strtok(NULL, ",");

         graph->nodes[graph->nodeCount]->num = atoi(node_number);
         graph->nodes[graph->nodeCount]->visited = 0;
         graph->nodes[graph->nodeCount]->numberOfFollow = 0;
         graph->nodes[graph->nodeCount]->numberOfFollower = 0;
        strcpy(graph->nodes[graph->nodeCount]->name, first_name);
        strcpy(graph->nodes[graph->nodeCount]->surname, last_name);
        graph->nodeCount ++;
    	}
   }

  for(i=0;i<lineCount;i++){
	if(i%2==1){
		
	strcpy(input_string, lines[i-1]);
	node_number = strtok(input_string, ",");
	node_index = atoi(node_number)-1;

	parca = strtok(lines[i], ",");
    while (parca != NULL && atoi(parca) !=0) {

  	graph->nodes[node_index]->follow[graph->nodes[node_index]->numberOfFollow++] = graph->nodes[atoi(parca)-1];
  	graph->nodes[atoi(parca)-1]->numberOfFollower ++ ;
    parca = strtok(NULL, ",");
  }
	}
}
		
		
		
		
		
		
		printf ("\n\n 1- Normal modda calistima");
		printf ("\n 2- Detay modda calistirma");
		printf("\n Seciminizi  yapiniz : ");
		scanf("%d",&secim);
		
		  printf("\n\n M degerini giriniz : ");
          scanf("%d",&m);
          printf("\n X degerini giriniz : ");
          scanf("%d",&x);
  
          printf("\n Y degerini giriniz : ");
          scanf("%d",&y);
	
		switch(secim){
			case 1:
				 removeNodesWithLowInDegree(graph, m) ;
                 printf("\n Nodes with an in-degree value less than M are removed...");
				     printf("\n\n\n **************** Influencer ****************");
                for (i = 0; i < graph->nodeCount; i++) {
                	int totalConnections = getTotalConnectionCount(graph, graph->nodes[i]);
	                if(totalConnections>=y && graph->nodes[i]->numberOfFollower >= x) {
	                	printf("\n");
	                	printf ("\n No        : %d",graph->nodes[i]->num);
	        			printf("\n Name      : %s", graph->nodes[i]->name);
	    				printf("\n Surname   : %s", graph->nodes[i]->surname);
	    				printf (" Number of Followers (After elimination with M)     : %d",graph->nodes[i]->numberOfFollower);
	    				printf ("\n Number of Follow      : %d",graph->nodes[i]->numberOfFollow);
	    				printf ("\n Number of Total Connections  : %d",totalConnections);
	    				printf("\n");
   					}				
				}
				
				break;
				
			case 2:
				  for(i=0;i<graph->nodeCount;i++){
              printf("\n %d.Dugum, in-degree : %d",graph->nodes[i]->num,graph->nodes[i]->numberOfFollower );
                 }
                 
					printf("\n\n");
				  removeNodesWithLowInDegree(graph, m) ;
                  printf("\n Nodes with an in-degree value less than M are removed...");
    
    			  for(i=0;i<graph->nodeCount;i++){
       				printf("\n %d. Dugum, in-degree : %d, ad-soyad : %s %s ", graph->nodes[i]->num,graph->nodes[i]->numberOfFollower,graph->nodes[i]->name,graph->nodes[i]->surname);
                }     
				
				printf("\n\n\n **************** Influencer ****************");
   				 for (i = 0; i < graph->nodeCount; i++) {
   				 	int totalConnections = getTotalConnectionCount(graph, graph->nodes[i]);
	  				  if(totalConnections>=y && graph->nodes[i]->numberOfFollower >= x) {
	    				printf("\n");
	    				printf ("\n No        : %d",graph->nodes[i]->num);
	    				printf("\n Name      : %s", graph->nodes[i]->name);
	    				printf("\n Surname   : %s", graph->nodes[i]->surname);
	    				printf (" Indegree (Number of Followers (After elimination with M) )    : %d",graph->nodes[i]->numberOfFollower);
	    				printf ("\n Number of Follow      : %d",graph->nodes[i]->numberOfFollow);
	    				printf ("\n Number of Total Connections  : %d",totalConnections);
	    				printf("\n");
   						}
            }
                
                
					break;				
			}
				
			
			
		
		  return 0;

	}
