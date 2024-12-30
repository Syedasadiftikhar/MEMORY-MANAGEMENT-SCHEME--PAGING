#include <stdio.h>
#include <unistd.h>
#include <time.h>
void main() {
int page_num,page_size,frame_num,i,offset,physical_address,logical_address,x,page_query;
int page_table[100];
int base_address[10];
int num=0;
printf("Enter the number of pages:\n");
scanf("%d",&page_num);

printf("Enter the page size:\n");
scanf("%d",&page_size);	

printf("\nRandom Page Table:\n");
    printf("Page Number\tFrame Number\n");
    for (i = 0; i < page_num; i++) {
        page_table[i] = rand() % page_num; 
        printf("%d\t\t%d\n", i, page_table[i]);
    }


    printf("\nEnter the page number to query its frame number (0 to %d):\n", page_num-1);
    scanf("%d", &page_query);
    
    if (page_query >= 0 && page_query < page_num) {
        printf("The frame number for Page %d is: %d\n", page_query, page_table[page_query]);
    } else {
        printf("Invalid page number.\n");
    }

printf("\nEnter the base addresses:\n");
 for (i = 0; i < page_num; i++) {
 printf("Base address of page %d: ", i);
 scanf("%d", &base_address[i]);
 }

do{

printf("Enter the page number you want to calculate logical address of:");
scanf("%d",&num);

if(num>=0 && num<page_num){
printf("Enter the offset of the page you want to calculate logical address of:");
scanf("%d",&offset);
}else{
	printf("invalid page number\n");
}

if(offset>=0 && offset<page_size){

logical_address=base_address[num]+offset;
printf("-------LOGICAL ADDRESS-------------\n");
printf("\n\tPageNo.\tBaseAdd.\tlogicalAdd.\n");
printf("\t%d\t%d\t\t%d\n", num, base_address[num], logical_address);
printf("-----------------------------------\n\n");

physical_address=((page_table[num]*page_size)+offset);
printf("-------PHYSICAL ADDRESS-------------\n");
printf("\n\tPageNo.\tBaseAdd.\tPhysicalAdd.\n");
printf("\t%d\t%d\t\t%d\n", num, base_address[num], physical_address);
printf("-----------------------------------\n");
}else{
	printf("invalid offset number\n");
}

printf("Enter 0 to exit and 1 to find logical address of other pages:\n");
scanf("%d",&x);
}while(x != 0);

}
