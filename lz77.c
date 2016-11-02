#include <stdio.h>
#include <stdlib.h>
char *buff;
int repeat(int m){
	//printf("%dk\n",k );
	int repeats=0;
	//printf("%cb\n",buff[m] );
	while(1){
		if(buff[m]==buff[m+1]){
			//printf("%c\n",buff[m] );
			repeats++;
			m++;
		}
		else 
			break;
		//return repeats;
	}
	return repeats;
}
int word(int m,int n){
	int repeats=0;
	while(1){
		if(buff[m]==buff[n]){
			//printf("%c",buff[m] );
			repeats++;
			m++;
			n++;
		}
		else
			break;
	}
	printf("%d\n",repeats );
	return repeats;
}
main(){
	FILE *fp;
	//char *buff;
	int i=0,j,k=0,c,count=0;
	fp=fopen("file.txt","r");
	while((c=getc(fp))!=EOF){
		count++;
	}
	//printf("%d\n",count );
	buff=(char*)malloc(sizeof(char)*count);
	rewind(fp);
	while((c=getc(fp))!=EOF){
		//printf("%c\n",c );
		buff[i]=c;
		i++;
		//printf("%c%c ",buff[i],c );
	}
	//rewind(fp);
	//for(i=0;i<count;i++)
		//printf("%c",buff[i] );
	i=0;
	while(i<count){
		for(j=0;j<i;j++){
		//j=0;
		//if(j<i){
			if((buff[j]==buff[i]) && (i-j==1)){
				//printf("%cj %ci %d %d\n",buff[j],buff[i],j,i );
				//printf("%di\n",i );
				k=repeat(j);
				//printf("%d\n",k);
				//fseek(fp,(k+i),SEEK_SET);
				i=k+i;
				//j++;
				printf("%d ",k );
				//c=getc(fp);
				//printf("%c",buff[k+i] );
				//printf("%c %c",buff[i],buff[j]);
			}
			else{
				if(buff[j]==buff[i]){
					k=word(i,j);
					//i=fseek(fp,(k+i),SEEK_SET);
					i+=k;
					//j++;
					printf("%d",k );
				}
				else{
					//i=fseek(fp,i,SEEK_SET);
					//i++;
					//j++;
					//printf("%d i3\n",i );
					printf("%c ",buff[j] );
					//i++;
				}
			}
		}
		//}
		i++;
	}
	fclose(fp);
	return(0);
}