#include<stdio.h>
#include<string.h>
typedef struct student
{
  char ten[31];
  int maso;
  float T,V,TB;
}
sv;
void print(sv svv[],int m); //In ra danh sach sinh vien
void print1(sv svv[],int i); //In ra danh sach trong chuc nang 3 va 4
void score_m(sv svv[],int i); //Kiem tra diem toan
void score_l(sv svv[],int i); //Kiem tra diem van

void print(sv svv[],int m)
{
    printf("STT | MSSV |            Ho ten          | Toan | Van |Trung binh|\n");
    for(int i=0;i<m;i++)
    {
        printf(" %-5d ",i+1);
        printf("%-5d",svv[i].maso);
        printf("%-31s",svv[i].ten);
        printf("%0.1f   ",svv[i].T);
        printf("%0.1f   ",svv[i].V);
        printf("%0.1f   \n",svv[i].TB);
    }
}

void print1(sv svv[],int i)
{
    printf(" %-5d ",i+1);
    printf("%-5d",svv[i].maso);
    printf("%-31s",svv[i].ten);
    printf("%0.1f   ",svv[i].T);
    printf("%0.1f   ",svv[i].V);
    printf("%0.1f   \n",svv[i].TB);
}

void score_m (sv svv[],int i)
{
    while(svv[i].T<0 || svv[i].T>10)
    {
        printf("Diem cua sinh vien phai thuoc [0;10], vui long nhap lai: ");
        scanf("%f",&svv[i].T);
    }
}

void score_l (sv svv[],int i)
{
    while(svv[i].V<0 || svv[i].V>10)
    {
        printf("Diem cua sinh vien phai thuoc [0;10], vui long nhap lai: ");
        scanf("%f",&svv[i].V);
    }
}


int main()
{
    int x,i,n,m,h; //n la so sinh vien can them
    float max;
    m=0; //So sinh vien ban dau
    sv svv[100];
    do
    {
        printf("\n");
        printf("1. Nhap thong tin sinh vien/Nhap them\n");
        printf("2. Danh sach sinh vien\n");
        printf("3. Danh sach sinh vien bi truot\n");
        printf("4. Danh sach sinh vien co diem trung binh cao nhat\n");
        printf("5. Thoat chuong trinh\n\n");
        scanf("%d",&x);
        switch(x)
        {
            case 1:
            do
            {
                if(m>100)
                {
                printf("So sinh vien toi da la 100, xin vui long nhap lai !\n");
                m=m-n;
                }
                printf("Nhap so sinh vien (toi da 100 nguoi): ");
                scanf("%d",&n);
                h=m;
                m=m+n;
            }
            while(m==0 || m>100);
            for(i=h;i<m;i++)
            {
                printf("Nhap vao ma so sinh vien thu %d: ",i+1);
                scanf("%d",&svv[i].maso);
                while(getchar()!='\n');
                printf("Nhap ten cua sinh vien thu %d: ",i+1);
                gets(svv[i].ten);
                printf("Nhap diem Toan: ");
                scanf("%f",&svv[i].T);
                score_m(svv,i);
                printf("Nhap diem Van: ");
                scanf("%f",&svv[i].V);
                score_l(svv,i);
                svv[i].TB = (svv[i].T + svv[i].V)/2;
            }
            break;

            case 2:
            print(svv,m);
            break;

            case 3:
            printf("STT | MSSV |            Ho ten          | Toan | Van |Trung binh|\n");
            for(i=0;i<m;i++)
            {
                if(svv[i].TB<4 || svv[i].T==0 || svv[i].V==0)
                print1(svv,i);
            }
            break;

            case 4:
            max=svv[0].TB;
            printf("STT | MSSV |            Ho ten          | Toan | Van |Trung binh|\n");
            for(i=0;i<m;i++)
            {
                if(max<svv[i+1].TB) max=svv[i+1].TB;
            }
	        for(i=0;i<m;i++)
            {
                if(max==svv[i].TB) print1(svv,i);
            }
            break;
        }
    }
    while(x!=5);
    return 0;
}
