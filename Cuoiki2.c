#include<stdio.h>
#include<string.h>
#include<ctype.h>
typedef struct Game
{
	char Name[25];
	int Old;
	int Score[5];
}
Game;

int main()
{
    int x,b,i,j,k,l,n,z;
    char a[41],c[40],e[40],d[5];
    n=0;
    do
	{
		Game Person[4];
        printf("\n");
		printf("1. Khoi dong tro choi\n");
		printf("2. Choi doan chu\n");
		printf("3. Tong hop ket qua\n");
		printf("4. Thoat\n");
        printf("\n");
		scanf("%d",&x);
		
		switch(x)
        {
	       	case 1:
                while(getchar()!='\n');
                int check;
                do
                {
                    printf("Nhap xau ki tu trong doan [20,40]: ");
                    gets(a);
                    z=strlen(a);
                    check=1;
                    for(int m=0;m<z;m++)
                    {
                        if(isspace(a[m]) !=0) check=0;
                    }

                    if(z<20 || z>40) check=0;
                }
                while(check==0);
                
		       	printf("Nhap so nguoi choi: ");
		       	scanf("%d",&b);
	       		for(i=0;i<b;i++)
		       	{
                    printf("Nhap ten nguoi thu %d: ",i+1);
                    scanf("%*c");
                    gets(Person[i].Name);
                    printf("Nhap tuoi nguoi thu %d: ",i+1);
	      	       	scanf("%d",&Person[i].Old);
				}
				printf("Ho va ten              | Tuoi \n");
				for(i=0;i<b;i++)
				{
					printf("%-25s",Person[i].Name);
					printf("%-3d\n",Person[i].Old);
				}
		        break;

			case 2:
				for(i=0;i<b;i++)
				{
					printf("Luot choi cua nguoi thu %d: \n",i+1);
					strcpy(c,a);
					for(j=0;j<z;j++)
					{
						c[j]='*';
					}
					k=0;
					puts(c);
					for(k=0;k<=4;k++)
					{
						if(k!=4)
						{
                            char r;
                            printf("Doan lan thu %d: ",k+1);
                            scanf("%s",&r);
                            for(l=0;l<z;l++)
                            {
                                if(r==a[l]) 
                                {
                                    c[l]=a[l];
                                    n=n+1;
                                }
                            }
                            Person[i].Score[k]=n;
                            printf("%s\n",c);
                            n=0;
						}
						else
                        {
					       	printf("Doan ca o chu: ");
						    scanf("%*c");
                            gets(e);
					       	if(strcmp(e,a)==0) Person[i].Score[4] = 20+Person[i].Score[0] + Person[i].Score[1] + Person[i].Score[2] + Person[i].Score[3];
					       	if(strcmp(e,a)!=0) Person[i].Score[4] = Person[i].Score[0] + Person[i].Score[1] + Person[i].Score[2] + Person[i].Score[3];					
						}
					}
				}
				printf("Ho va ten             | L1 | L2 | L3 | L4 | Ket qua \n");
				for(i=0;i<b;i++)
				{
					printf("%-24s",Person[i].Name);
					printf("%-2d   ",Person[i].Score[0]);
					printf("%-2d   ",Person[i].Score[1]);
					printf("%-2d   ",Person[i].Score[2]);
					printf("%-2d   ",Person[i].Score[3]);
					printf("%-2d\n",Person[i].Score[4]);
				}
				break;
                
				case 3:
                    printf("Ho va Ten             | L1 | L2 | L3 | L4 | Ket qua \n");
                    int temp;
                    for(i=0;i<b;i++)
                    {
                        for(j=0;j<b;j++)
                        {
                            if(Person[i].Score[4]<Person[i+1].Score[4])
                            {
                                temp=Person[i].Score[4];
                                Person[i].Score[4]=Person[i+1].Score[4];
                                Person[i+1].Score[4]=temp;
                            }
                        }
                    }
                    for(i=0;i<b;i++)
                    {
                        printf("%-24s",Person[i].Name);
                        printf("%-2d   ",Person[i].Score[0]);
                        printf("%-2d   ",Person[i].Score[1]);
                        printf("%-2d   ",Person[i].Score[2]);
                        printf("%-2d   ",Person[i].Score[3]);
                        printf("%-2d\n",Person[i].Score[4]);
                    }
                    break;
	    }
    }
    while(x!=4);
}