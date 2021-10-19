#include<string.h>
#include<arpa/inet.h>
#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<fcntl.h>
#include<sys/stat.h>
int main()
{
	int s,r,recb,sntb,x;
	printf("INPUT port number: ");
	scanf("%d", &x);
	struct sockaddr_in server;
	char buff[50];
	char rbuff[INT_MAX];
	s=socket(AF_INET,SOCK_STREAM,0);
	if(s==-1)
	{
		printf("\nSocket creation error.");
		exit(0);
	}
	printf("\nSocket created.");

	server.sin_family=AF_INET;
	server.sin_port=htons(x);
	server.sin_addr.s_addr=inet_addr("127.0.0.1");

	r=connect(s,(struct sockaddr*)&server,sizeof(server));
	if(r==-1)
	{
		printf("\nConnection error.");
		exit(0);
	}
	printf("\nSocket connected.");
	
	int input[100];
	int n; 
	printf("Enter the size of an array\n");
	scanf("%d", &n);
	for(int i = 0 ; i < n ; i ++)
	{
	   scanf("%d",&input[i]);
	}
	for(int i = 0 ; i< n ; i ++)
	{ 
	   arr[i]=input[i];
	}
	
	sntb=send(s,arr,sizeof(arr),0);
	
	if(sntb==-1)
	{
	  close(s);
	  printf("\n Message Sending Failed");
	  exit(0);
	}
        
        int ch;
        
        while(ch!=-1)
        {  int buff[3];
           printf(" Enter you choice according to the given menu \n 
           Enter 1 to search a number \n 
           Enter 2 to sort the array \n 
           Enter 3 to split the array\n
           Enter -1 to Exit the program\n");
           
           scanf("%d", &ch);
           
           if(ch==1)
           {   int num;
              printf("Enter the value to be searched in array");
              scanf("%d",&num);
              buff[0]=ch;
              buff[1]=n;
              buff[2]=num;
           }
           
           if(ch==2)
           { 
           	buff[0]=ch;
           	buff[1]=n;
           }
           
           if(ch==3)
           {
             buff[0]=ch;
             buff[1]=n;
           }
           
           if(ch==-1)
           {
              break;
           } 
           
           
           sntb = send(s,buff, sizeof(buff),0);
              
	      if(sntb==-1)
		{
		  close(s);
		  printf("\n Message Sending Failed");
		  exit(0);
		}
	   rcvb = send(s,rbuff, sizeof(rbuff),0);
	   printf("%s",rbuff);
    
        }
	
	close(s);
	exit(0);
}
