#include <stdio.h>
#include <unistd.h>
void main() {
 int b[20], n, i, pa, p, d;
 // Initialize variables properly
 d = 0;
 printf("\nProgram for paging\n");
 // Input number of pages
 printf("\nEnter the number of pages: ");
 scanf("%d", &n);
 // Input base addresses for the pages
 printf("\nEnter the base addresses:\n");
 for (i = 0; i < n; i++) {
 printf("Base address of page %d: ", i);
 scanf("%d", &b[i]);
 }
 // Input logical address
printf("\nEnter the page number for the logical address: ");
 scanf("%d", &p);
 if (p >= 0 && p < n) {
 printf("\nEnter the offset (displacement): ");
 scanf("%d", &d);
 // Calculate physical address
 pa = b[p] + d;
 printf("\n\tPageNo.\tBaseAdd.\tPhysicalAdd.\n");
 printf("\t%d\t%d\t\t%d\n", p, b[p], pa);
 } else {
 printf("\nInvalid page number\n");
 }
}

