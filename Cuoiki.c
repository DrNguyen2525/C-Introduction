#include <stdio.h>
#include <string.h>
#include <ctype.h>
typedef struct student
{
	char ten[100],ten_cat[100];
	int maso;
	float GK,CK,HD,PB,HD1,HD2,HD3;
}
sv;
void print(sv svv[],int m); //In ra danh sach sinh vien/sap xep
void print1(sv svv[],int m); //In ra danh sach sinh vien bao ve thanh cong
void name(sv svv[], int i); //Kiem tra dieu kien ten
void sort(sv svv[],int m); //Sap xep ten
void score1(sv svv[],int i); //Kiem tra dieu kien diem
void score2(sv svv[],int i);
void score3(sv svv[],int i);
void score4(sv svv[],int i);
void score5(sv svv[],int i);

void print(sv svv[],int m)
{
	int i;
	printf("MSSV |		Ho va ten	   | HD  | PB  | HD1 | HD2 | HD3 | GK  | CK  |\n");
	for(i=0;i<m;i++)
	{
		printf("%-6d",svv[i].maso);
		printf("%-31s",svv[i].ten);
		printf("%0.1f   ",svv[i].HD);
		printf("%0.1f   ",svv[i].PB);
		printf("%0.1f   ",svv[i].HD1);
		printf("%0.1f   ",svv[i].HD2);
		printf("%0.1f   ",svv[i].HD3);
		printf("%0.1f   ",svv[i].GK);
		printf("%0.1f\n",svv[i].CK);
	}
}

void print1(sv svv[],int i)
{
    printf("%-6d",svv[i].maso);
	printf("%-31s",svv[i].ten);
	printf("%0.1f   ",svv[i].HD);
	printf("%0.1f   ",svv[i].PB);
	printf("%0.1f   ",svv[i].HD1);
	printf("%0.1f   ",svv[i].HD2);
	printf("%0.1f   ",svv[i].HD3);
	printf("%0.1f   ",svv[i].GK);
	printf("%0.1f\n",svv[i].CK);
}

void name(sv svv[], int i)
{
	int a,j,n,check;
	while(getchar()!='\n');
	do
	{
		printf("Nhap ten cua sinh vien thu %d: ",i+1);
		gets(svv[i].ten);
		n=strlen(svv[i].ten);
		a=0;
		check=1;
		for(j=0;j<n;j++) //Truong hop ten khong co dau cach
		{
			if(isspace(svv[i].ten[j]) !=0) a++;
		}
		if(a==0) check=0;

		if(isspace(svv[i].ten[n-1]) !=0) check=0; //Truong hop ten ket thuc bang dau cach

		if(strlen(svv[i].ten)>30) check=0; //Truong hop ten vuot qua 30 ki tu
	}
	while(check==0);
}

void sort(sv svv[],int m)
{
	int i,j,k;
	sv svv1[20];
	sv TG; //Bien trung gian
	for(i=0;i<m;i++) svv1[i]=svv[i]; //Sao chep mang svv[] sang mang svv1[]

	for(i=0;i<m;i++) //Tach rieng ten
		for(j=strlen(svv1[i].ten)-1;j>=0;j--)
		{
			if(svv1[i].ten[j]==' ')
			{
				k=0;
				while(svv1[i].ten[j] !='\0')
				{
					svv1[i].ten_cat[k]=svv1[i].ten[j+1];
					j++;
					k++;
				}
				break;
			}
		}
	/*for(i=0;i<m;i++) //Truong hop trong svv1[i].ten khong co dau cach
	{
		if(strlen(svv1[i].ten_cat)==0) strcpy(svv1[i].ten_cat,svv1[i].ten);
	}*/
	
	for(i=0;i<m-1;i++) //So sanh ten va sap xep
		for(j=i+1;j<m;j++)
		{
			if(strcmp(svv1[i].ten_cat,svv1[j].ten_cat)>0) //Truong hop ten khac nhau
			{
				TG=svv1[i];
				svv1[i]=svv1[j];
				svv1[j]=TG;
			}
			if(strcmp(svv1[i].ten_cat,svv1[j].ten_cat)==0) //Truong hop ten giong nhau
			{
				if(strcmp(svv1[i].ten,svv1[j].ten)>0)
				{
					TG=svv1[i];
					svv1[i]=svv1[j];
					svv1[j]=TG;
				}
			}
		}

	print(svv1,m);
}

void score1(sv svv[],int i)
{
	while(svv[i].HD<0 || svv[i].HD>10)
	{
		printf("Diem cua sinh vien phai thuoc [0;10], vui long nhap lai: ");
		scanf("%f",&svv[i].HD);
	}
}
void score2(sv svv[],int i)
{
	while(svv[i].PB<0 || svv[i].PB>10)
	{
		printf("Diem cua sinh vien phai thuoc [0;10], vui long nhap lai: ");
		scanf("%f",&svv[i].PB);
	}
}
void score3(sv svv[],int i)
{
	while(svv[i].HD1<0 || svv[i].HD1>10)
	{
		printf("Diem cua sinh vien phai thuoc [0;10], vui long nhap lai: ");
		scanf("%f",&svv[i].HD1);
	}
}
void score4(sv svv[],int i)
{
	while(svv[i].HD2<0 || svv[i].HD2>10)
	{
		printf("Diem cua sinh vien phai thuoc [0;10], vui long nhap lai: ");
		scanf("%f",&svv[i].HD2);
	}
}
void score5(sv svv[],int i)
{
	while(svv[i].HD3<0 || svv[i].HD3>10)
	{
		printf("Diem cua sinh vien phai thuoc [0;10], vui long nhap lai: ");
		scanf("%f",&svv[i].HD3);
	}
}

int main()
{
	int i,j,k,x,m,n,h;
	sv svv[20];
	m=0;
	do
	{
		printf("\n");
		printf("1. Nhap thong tin sinh vien/Nhap them\n");
		printf("2. Bang danh sach sinh vien\n");
		printf("3. Danh sach bao ve thanh cong\n");
		printf("4. Sap xep ten sinh vien\n");
		printf("5. Thoat\n");
		printf("\n");
		scanf("%d",&x);
		switch(x)
		{
			case 1:
				do
				{
					if(m>20)
					{
						printf("So sinh vien toi da la 20, xin vui long nhap lai !\n");
						m=m-n;
					}
					printf("Nhap so sinh vien (toi da 20 nguoi): ");
					scanf("%d",&n);
					h=m;
					m=m+n;
				}
                while(m==0 || m>20);
				for(i=h;i<m;i++)
				{
					printf("Nhap ma so sinh vien thu %d: ",i+1);
					scanf("%d",&svv[i].maso);
                    for(j=i;j>0;j--)
                    {
						while(svv[i].maso==svv[j-1].maso)
						{
							printf("MSSV vua nhap trung voi MSSV thu %d, hay nhap lai: ",j);
							scanf("%d",&svv[i].maso);
							j=i;
						}
                    }
					name(svv,i);
					printf("Nhap diem HD: ");
					scanf("%f",&svv[i].HD);
					score1(svv,i);
					printf("Nhap diem PB: ");
					scanf("%f",&svv[i].PB);
					score2(svv,i);
					printf("Nhap diem HD1: ");
					scanf("%f",&svv[i].HD1);
					score3(svv,i);
					printf("Nhap diem HD2: ");
					scanf("%f",&svv[i].HD2);
					score4(svv,i);
					printf("Nhap diem HD3: ");
					scanf("%f",&svv[i].HD3);
					score5(svv,i);
					if(svv[i].HD <5.5 || svv[i].PB <5.5 || svv[i].HD1 <5.5 || svv[i].HD2 <5.5|| svv[i].HD3 <5.5)
					svv[i].GK=svv[i].CK=0;
					else
					{
						svv[i].GK = (svv[i].HD + svv[i].PB)/2;
						svv[i].CK = (svv[i].HD1 + svv[i].HD2+svv[i].HD3)/3;
					}
				}
				break;

			case 2:
				print(svv,m);
				break;

			case 3:
				printf("MSSV |		Ho va ten	   | HD  | PB  | HD1 | HD2 | HD3 | GK  | CK  |\n");
				for(i=0;i<m;i++)
				{
					if(svv[i].CK>=4)
					print1(svv,i);
				}
				break;
			
			case 4:
				sort(svv,m);
				break;
		}
	}
	while(x!=5);
	return 0;
}
