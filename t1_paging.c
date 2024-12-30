#include <stdio.h>
#include <unistd.h>
void main() {
int page_num,page_size,frame_num,i,offset,physical_address,logical_address;
int page_table[10];
int base_address[10];
int num=0;
printf("Enter the number of pages:\n");
scanf("%d",&page_num);

printf("Enter the page size:\n");
scanf("%d",&page_size);	

printf("Enter the number of frames:\n");
scanf("%d",&frame_num);


for(i=0;i<page_num;i++){
	printf("Enter the frame number for page: %d\n",i);
	scanf("%d", &page_table[i]);
}	
printf("\nPage Table:\n");
    printf("Page Number\tFrame Number\n");
    for (i = 0; i < page_num; i++) {
        printf("%d\t\t%d\n", i, page_table[i]);
    }

printf("\nEnter the base addresses:\n");
 for (i = 0; i < page_num; i++) {
 printf("Base address of page %d: ", i);
 scanf("%d", &base_address[i]);
 }

printf("Enter the page number you want to calculate logical address of:");
scanf("%d",&num);

if(num>=0 && num<page_num){
printf("Enter the offset of the page you want to calculate logical address of:");
scanf("%d",&offset);
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
 
 
}
else{
	printf("invalid page number");
}
}
