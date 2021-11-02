#include<stdio.h>
#include<string.h>
char data[50], stuff[50],dstuff[50];
int i, j, cnt, len, op, c,n, pos;
char b1[50],b2[100],s[100]="STXDLE",end[6]="ETXDLE";
void bit_stuffing();
void bit_destuffing();
void byte_stuffing();
void byte_destuffing();
void main()
{
	int flag,ch;
	while(c!=3){
		flag=0,ch=0;
		printf("\n1.bit Stuffing\t2.byte Stuffing\t3.Exit\n");
		printf("\nEnter your choice : ");
		scanf("%d",&c);
		switch(c){
			case 1: while(ch!=3){
					printf("\n1.Stuffing\t2.De-stuffing\t3.Exit\n");
					printf("\nEnter your choice : ");
					scanf("%d",&ch);
					switch(ch){
						case 1: bit_stuffing();
							flag=1;
							break;
						case 2: if(flag==1)
							bit_destuffing();
							else
							printf("\nCan't perform destuffing.\n");
						break;
						case 3: printf("\nExit Bit Stuffing");
							break;
						default: printf("\nWrong Choice !");
					}
				}
				break;
			case 2: while(ch!=3){
						printf("\n1.Stuffing\t2.De-stuffing\t3.Exit\n");
						printf("\nEnter your choice : ");
						scanf("%d",&ch);
						switch(ch){
							case 1: byte_stuffing();
									flag=1;
									break;
							case 2: if(flag==1)
									byte_destuffing();
									else
									printf("\nCan't perform destuffing.\n");
									break;
							case 3: printf("\nExit Byte Stuffing");
									break;
							default: printf("\nWrong Choice !");
						}
					}
				break;
			case 3 : printf("\nExit");
					break;
     	}
	}
}

void bit_stuffing()
{
	printf("Stuffing\n");
    printf("Enter message = ");
    scanf("%s", data);
    len = strlen(data);
    strcpy(stuff, "01111110");
    cnt = 0, j = 8;
    for(i=0; i<len; i++)
    {
        if(data[i] == '1')
        {
            cnt++;
        }
        else
        {
            cnt = 0;
        }
        stuff[j] = data[i];
        j++;
        if(cnt== 5 && data[i+1] == '1')
        {
            stuff[j] = '0';
            j++;
            cnt = 0;
        }
    }
    stuff[j] = '\0';
    strcat(stuff, "01111110");
    printf("Stuff = %s\n", stuff);
}
void bit_destuffing()
{
    printf("Dstuffing\n");
    // destiffing
    int x = strlen(stuff);
    cnt = 0; j=0;
    if(x==0)
    {
        printf("Empty message\n");
    }
    else
    {
        for(i=8; i<x-8; i++)
        {
            if(stuff[i] == '1')
            {
                cnt++;
            }
            else
            {
                cnt = 0;
            }
            dstuff[j] = stuff[i];
            j++;
            if(cnt == 5 && stuff[i+1] == '0')
            {
                cnt = 0;
                i++;
            }
        }
    }
    dstuff[j] = '\0';
    printf("Dstuff = %s\n",dstuff);
}
void byte_stuffing()
{
	printf("Enter length of your message : ");
	scanf("%d",&n);
	printf("\nEnter string message : ");
	scanf("%s",b1);
	strcat(s, b1);
	len = strlen(s);
	for(i=6;i<len;i++)
	{
	 if((s[i]=='S'&&s[i+1]=='T'&&s[i+2]=='X')||(s[i]=='E'&&s[i+1]=='T'&&s[i+2]=='X')||(s[i]=='D'&&s[i+1]=='L'&&s[i+2]=='E'))
	 {
	    pos = i+3;
	    for(j=len-1;j>pos-1;j--){
            s[j+3]=s[j]; 
        }
        s[pos] = 'D'; 
        s[pos+1] = 'L';
        s[pos+2] = 'E';	
        i = pos+2;
        len = strlen(s);
	 }	
	}
	strcat(s,end);
	printf("\tStuffing :\n%s",s);
}
void byte_destuffing()
{
	len= strlen(s);
	for(i=6,j=0;i<len-6;i++,j++)
	{
		b2[j]=s[i];
		if((s[i]=='S'&&s[i+1]=='T'&&s[i+2]=='X')||(s[i]=='E'&&s[i+1]=='T'&&s[i+2]=='X')||(s[i]=='D'&&s[i+1]=='L'&&s[i+2]=='E')){
	 		b2[j+1]=s[i+1];
	 		b2[j+2]=s[i+2];
		 	i=i+5;
		 	j=j+2;
	 	}
	}
	printf("\n\tDe-stuffing\n%s",b2);
}