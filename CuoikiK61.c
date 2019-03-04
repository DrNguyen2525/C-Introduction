#include <stdio.h>
#include <string.h>
#include <ctype.h>
typedef struct restaurant
{
    char name[31];
    char des[501];
    float rate;
    char add[101];
}
rest;
 
void print(rest nhahang[],int m) //In danh sach nha hang
{
    int i;
    for(i=0;i<m;i++)
    {
        printf("Nha hang %d\n",i+1);
        printf("Name: %-31s\n",nhahang[i].name);
        printf("Description: %-50s\n",nhahang[i].des);
        printf("Rating: %0.1f\n",nhahang[i].rate);
        printf("Address: %-50s\n",nhahang[i].add);
        printf("\n");
    }
}
 
void print1(rest nhahang[],int i) //In ra nha hang theo yeu cau
{
    printf("Nha hang %d\n",i+1);
    printf("Name: %-31s\n",nhahang[i].name);
    printf("Description: %-50s\n",nhahang[i].des);
    printf("Rating: %0.1f\n",nhahang[i].rate);
    printf("Address: %-50s\n",nhahang[i].add);
    printf("\n");
}
 
void sort(rest nhahang[],int m) //Sap xep nha hang theo rating
{
    int i,j,k;
    rest nhahang1[20];
    rest TG; //Bien trung gian
    for(i=0;i<m;i++) nhahang1[i]=nhahang[i]; //Sao chep mang nhahang[] sang mang nhahang1[]
    
    for(i=0;i<m-1;i++) //So sanh rating
        for(j=i+1;j<m;j++)
        {
            if(nhahang1[i].rate < nhahang1[j].rate)
            {
                TG=nhahang1[i];
                nhahang1[i]=nhahang1[j];
                nhahang1[j]=TG;
            }
        }
 
    print(nhahang1,m);
}
 
int main()
{
    int i,j,x,m,n,h;
    rest nhahang[20];
    m=0;
    do
    {
        printf("\n");
        printf("1. Nhap thong tin cac nha hang\n");
        printf("2. In thong tin nha hang\n");
        printf("3. Tim kiem theo ten\n");
        printf("4. Tim kiem theo mo ta\n");
        printf("5. Sap xep\n");
        printf("6. Thoat\n");
        printf("\n");
        scanf("%d",&x);
        switch(x)
        {
            case 1:
                printf("Nhap so nha hang: ");
                scanf("%d",&n);
                h=m;
                m=m+n;
                while(getchar()!='\n');
                printf("\n");
                for(i=h;i<m;i++)
                {
                    printf("Nhap ten nha hang %d: ",i+1);
                    gets(nhahang[i].name);
                    printf("Mo ta nha hang: ");
                    gets(nhahang[i].des);
                    printf("Danh gia nha hang: ");
                    scanf("%f",&nhahang[i].rate);
                    while(nhahang[i].rate<0 || nhahang[i].rate>5)
                    {
                        printf("Danh gia nha hang phai thuoc [0;10], hay nhap lai: ");
                        scanf("%f",&nhahang[i].rate);
                    }
                    while(getchar()!='\n');
                    printf("Nhap dia chi nha hang: ");
                    gets(nhahang[i].add);
                    printf("\n");
                }
                break;
    
            case 2:
                print(nhahang,m);
                break;
        
            case 3:
                while(getchar()!='\n');
                char name[30];
                int dem=0;
                printf("Nhap ten nha hang can tim: ");
                gets(name);
                printf("\n");
                for(i=0;i<m;i++)
                {
                    if(strcasecmp(name,nhahang[i].name)==0)
                    {
                        print1(nhahang,i);
                        dem++;
                    }
                }
                if(dem==0) printf("Khong co nha hang can tim !\n");
                break;
        
            case 4:
                while(getchar()!='\n');
                char description[30];
                int dem1=0;
                printf("Nhap mon an can tim: ");
                gets(description);
                printf("\n");
                for(i=0;i<m;i++)
                {
                    if(strcasestr(nhahang[i].des,description)!=NULL)
                    {
                        print1(nhahang,i);
                        dem1++;
                    }
                }
                if(dem1==0) printf("Khong co nha hang nao co mon an can tim !\n");
                break;
        
            case 5:
                sort(nhahang,m);
                break;
        }
    }
    while(x!=6);
    return 0;
}
