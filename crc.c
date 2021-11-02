#include<stdio.h>
#include<string.h>
char data[20],div[20],temp[20],total[100];
int i,j,datalen,divlen,len,flag=1;
void check();
int main()
{	
 	printf("\nEnter the data:");
 	scanf("%s",data);
	datalen=strlen(data);		      
    printf("\nEnter the divisor:");
    scanf("%s",div);
	divlen=strlen(div); 
    len=datalen+divlen-1;                                                                                                                                      
	strcat(temp,data);
	strcat(total,data);  
	for(i=datalen;i<len;i++)			
        total[i]='0';   //G(x) adding 0's
	check();								// check for crc
 	for(i=0;i<divlen;i++)	 			// append crc output (remainder) at end of temp 
	  	temp[i+datalen]=data[i];
 	printf("\nTransmitted Code Word:%s",temp);	  	
	printf("\n\nEnter the received code word:");
    scanf("%s",total); 
 	check();		 	  
	for(i=0;i<divlen-1;i++)
		if(data[i]=='1')
		{
			flag=0;
			break;
		}		
	if(flag==1)
	printf("\nSuccessfull !!");
	else
	printf("\nReceived word contains errors...\n");	
}
void check()
{
    for(j=0;j<divlen;j++)
        data[j]=total[j];
    while(j<=len)
	{
        if(data[0]=='1')				// in XOR ans remains as it is except in case of 1
            for(i = 1;i <divlen ; i++)
   				data[i] = (( data[i] == div[i])?'0':'1');
        for(i=0;i<divlen-1;i++)			// left shift data word by 1 after div
            data[i]=data[i+1];
        data[i]=total[j++];				// replace empty right by total
    }
}