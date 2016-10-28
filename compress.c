#include <stdio.h>
#include <stdlib.h>
main(){
	FILE *fp;
	int i=0,j,k=0, c, count=0;
	char *buff;
	fp=fopen("file.txt","r");
	if(fp==NULL){
		perror("Error ");
		return(-1);
	}
	if(fp!=NULL){
		while((c=getc(fp))!=EOF){
			//printf("%c",c );
			count++;
		}
		rewind(fp);
	buff=(char *)malloc(sizeof(char)*count);
	//char buff[count];
	while(((c=getc(fp))!=EOF)){
		buff[i]=c;	
		//printf("%c",buff[i] );
		//printf("%c",c );
		for(j=0;j<i;j++){
			if(buff[j]==c){
				c=getc(fp);
				printf("%c\n",buff[j] );
				continue;
				//printf("%c %d\n",c,k);
				//c=getc(fp);
				k++;
			}
		}
		//printf("%d\n",k );

		i++;	
	}

}
	fclose(fp);
	return(0);
}