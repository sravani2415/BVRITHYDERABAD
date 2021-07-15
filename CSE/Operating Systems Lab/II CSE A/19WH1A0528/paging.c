#include <stdio.h>

struct pstruct {
	int fno;
	int pbit;
}ptable[10];

int pmsize, lmsize, page, frame, partition, frameno, ftable[10];
void info() {
	printf("\nMEMORY MANAGEMENT USING PAGING\n");
	printf("Enter the size of Physical memory: ");
	scanf("%d", &pmsize);
	printf("Enter the size of Logical memory: ");
	scanf("%d", &lmsize);
	printf("Enter the partition size: ");
	scanf("%d", &partition);
	page = (int) lmsize/partition;
	frame = (int) pmsize/partition;
	printf("The Physical Memory is divided into %d number of frames\n", frame);
	printf("The Logical Memory is divided into %d number of pages\n\n", page);
}

void assign() {
	int i;
	for (i = 0; i < page; i++) {
		ptable[i].fno = -1;
		ptable[i].pbit = -1;
	}
	for (i = 0; i < frame; i++)
		ftable[i] = 32555;

	for (i = 0; i < page; i++) {
		printf("Enter the frame number where the page %d must be placed: ", i);
		scanf("%d", &frameno);

		ftable[frameno] = i;
		if (ptable[i].pbit == -1) {
			ptable[i].fno = frameno;
			ptable[i].pbit = i;
		}
	}
	printf("\n\nPAGE TABLE\n");
	printf("Page Address\tFrame Number\tPresence Bit\n");
	for (i = 0; i < page; i++) 
		printf("%d\t\t %d\t\t %d\n", i, ptable[i].fno, ptable[i].pbit);
}

int main() {
	info();
	assign();
}

