#include<stdio.h>
int main(){
    int memsize = 50,pagesize,nofpage,logadd,phyadd,offset,frameno,p[10];
    printf("\nenter the pagesize\n");
    scanf("%d",&pagesize);
    nofpage = memsize / pagesize;
    for(int i= 0; i< nofpage; i++){
        printf("\nenter the frame of page %d\n",i+1);
        scanf("%d",&p[i]);
    }printf("\nenter the logical address\n");
    scanf("%d",&logadd);
    frameno = logadd/pagesize;
    offset = logadd%pagesize;
    phyadd = (p[frameno]*pagesize) + offset;
    printf("\nphysical address iss %d\n",phyadd);
}
