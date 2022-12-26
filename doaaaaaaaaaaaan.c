#include <stdio.h>
#include <stdlib.h>

// hello there

#define N 256


//___________________________________________________________________________________________________________________    
// kieu du lieu struct
typedef struct date
{
    int Ngay;
    int Thang;
    int Nam;
}date_t;


typedef struct SV
{
    char HvT[200];
    int gioitinh;
    int MSSV;
    date_t namsinh;
    char Nganh[25];

}st_sv;

//___________________________________________________________________________________________________________________    
// Head_list

typedef struct H_note
{
    struct Note *next;

}st_nH;

//___________________________________________________________________________________________________________________    
// linked list

typedef struct Note
{
    //du lieu cua note
    struct SV data_SV;
    struct Note *next;

}st_Note;

//___________________________________________________________________________________________________________________    
//input date
date_t nhapnamsinh()
{
    date_t namsinh;

    printf("nhap ngay sinh: ");
    scanf("%d",&namsinh.Ngay);

    printf("nhap thang sinh: ");
    scanf("%d",&namsinh.Thang);

    printf("nhap nam: ");
    scanf("%d",&namsinh.Nam);

    return namsinh;

}

//___________________________________________________________________________________________________________________    
//input student input
st_sv nhapdulieusv()
{   
    st_sv sv_nhap;

    //NHap Ho va Ten
    printf("Nhap ho va ten sinh vien: ");
    fflush(stdin); 
    gets(sv_nhap.HvT);

    // Nhap MSSV
    printf("Nhap MSSV: "); 
    scanf("%d",&sv_nhap.MSSV);

    //NHp gioi tinh
    int b = 1; 
    while (b != 0)
    {
        int gioitinhn;
        printf("Nhap gioi tinh Nam = 0, Nu = 1 :");
        scanf("%d",&gioitinhn);
        if (gioitinhn == 1)
        {
            sv_nhap.gioitinh = 1;
            b = 0;   
        }
        else if (gioitinhn == 0)
        {
            sv_nhap.gioitinh = 0;
            b = 0;
        }    
    }

    // Nhap Nganh hoc
    printf("Nhap nganh hoc: "); 
    fflush(stdin);
    gets(sv_nhap.Nganh);

    // Nhap nam sinh
    sv_nhap.namsinh = nhapnamsinh();

    return sv_nhap;
}
//___________________________________________________________________________________________________________________    
//      THEM SV VAO LIST
st_Note * themNote()
{
    st_Note *note_add;
    note_add = (st_Note*)malloc(sizeof(st_Note));
    note_add->data_SV = nhapdulieusv();
    note_add->next = NULL;

    return note_add;
}

//___________________________________________________________________________________________________________________    
//  CHINH SUA SINH VIEN
void chinhsuasinhvien(st_nH * head)
{
    st_Note * p;
    p = head->next;
    

    if(p == NULL)
    {
        printf(" List is Null\n");
    }
    else
    {   
        int stt = 1;
        int a = 0;
        int b = 0;
        printf("Nhap MSSV can sua:");
        scanf("%d",&a);

        while (p != NULL)
        {   
            if(a == p->data_SV.MSSV)
            {
                int sel = 0;
                b = 1;
                
                printone(p,stt);
                printf("\n0: Sua HOVATEN");
                printf("\n1: Sua MSSV");
                printf("\n2: Sua GIOITINH");
                printf("\n3: Sua NGANH HOC");
                printf("\n4: Sua NGAYSINH ");
                printf("\n5: sua Het");
                printf("\nNhap: ");
                fflush(stdin);
                scanf("%d",&sel);
                switch (sel)
                {
                case 0:
                    printf("Nhap ho va ten sinh vien: ");
                    fflush(stdin); 
                    gets(p->data_SV.HvT);

                    break;
                case 1:
                    printf("Nhap MSSV: "); 
                    scanf("%d",&p->data_SV.MSSV);

                    break;
                case 2:
                    /* code */
                    int b = 1; 
                    while (b != 0)
                    {
                        int gioitinhn;
                        printf("Nhap gioi tinh Nam = 0, Nu = 1 :");
                        scanf("%d",&gioitinhn);
                        if (gioitinhn == 1)
                        {
                            p->data_SV.gioitinh = 1;
                            b = 0;   
                        }
                        else if (gioitinhn == 0)
                        {
                            p->data_SV.gioitinh = 0;
                            b = 0;
                        }    
                    }
                    break;
                case 3:
                    printf("Nhap nganh hoc: "); 
                    fflush(stdin);
                    gets(p->data_SV.Nganh);
                    break;
                case 4:
                    p->data_SV.namsinh = nhapnamsinh();
                    break;
                case 5:
                    /* code */
                    p->data_SV = nhapdulieusv();
                    break;
                
                default:
                    break;
                }
            }
            stt++;
            p = p->next;
        }

        // neu khong tim thay SV
        if (b != 1)
        {
            printf(" khong tim thay sinh vien");
        }
    }
}

//___________________________________________________________________________________________________________________
//                  XOA SINH VIEN
void XOASV(st_nH *head)
{
st_Note *p = head->next;
int count = 0;
int x = 0;
scanf_s("%d",&x);
while( p != NULL)
{
    if(p->data_SV.MSSV == x)
        break;
    else 
    {
        p = p->next;
        count = count + 1;
    }
}
st_Note *q = head->next;
if (count == 0)
{
    st_Note * temp = q->next;
    head->next = head->next->next;
    free(temp);
}
else
{
    for(int i = 0; i < count - 1; i++)
    {
            q = q->next;
    }
st_Note * temp = q->next;
q->next = q->next->next;
free(temp);
}
}
//___________________________________________________________________________________________________________________    
//      In 1 SV
void printone(st_Note * A,int stt)
{
    printf("| %d\t",stt);
    printf("| %s\t",A->data_SV.HvT);
    printf("| %d\t",A->data_SV.MSSV);
    if (A->data_SV.gioitinh == 0)
    {
        printf("| Nam   ");
    }
    else if (A->data_SV.gioitinh == 1)
    {
        printf("| Nu    ");
    }
    printf("| %s\t\t",A->data_SV.Nganh);
    printf("| %d/%d/%d\t\n  ",A->data_SV.namsinh.Ngay,A->data_SV.namsinh.Thang,A->data_SV.namsinh.Nam);

}   

//___________________________________________________________________________________________________________________    
//      In SV
void printnote(st_nH *head)
{
    int stt = 1;
    st_Note *p;
    p = head->next;
    if(p == NULL)
    {
        printf(" List is Null\n");
    }
    else
    {   
        printf("\n\t\tlist\n");
        printf("|STT \t|HOVATEN\t\t|MSSV\t\t|GIOITINH NGANH \t|NAMSINH \n");
        while (p != NULL)
        {
            printone(p,stt);
            p = p->next;
            stt++;
        }
    }

}

//___________________________________________________________________________________________________________________    
//                  GHI SINH VIEN
void ghi_SV(st_nH * head)
{
    st_Note * p;
    p = head->next;
    int stt = 1;

    FILE *f = NULL;
    fopen_s(&f,"SINHVIEN.csv","w");
    while (p != NULL)
    {
        fprintf(f,"%s,%d,%d,%s,%d,%d,%d\n",p->data_SV.HvT,p->data_SV.gioitinh,p->data_SV.MSSV,p->data_SV.Nganh,p->data_SV.namsinh.Ngay,p->data_SV.namsinh.Thang,p->data_SV.namsinh.Nam);
        p = p->next;
    }
    fclose(f);

    printf("Da XONG");
}
//___________________________________________________________________________________________________________________    
//       SAP XEP SINH VIEN
void sortedInsert(st_Note ** sorted, st_Note* newnode)
{

    if (*sorted == NULL || (*sorted)->data_SV.MSSV >= newnode->data_SV.MSSV) {
        newnode->next = *sorted;
        *sorted = newnode;
    }
    else {
        st_Note* current = *sorted;

        while (current->next != NULL
            && current->next->data_SV.MSSV < newnode->data_SV.MSSV) {
            current = current->next;
        }
        newnode->next = current->next;
        current->next = newnode;
    }
}
st_Note* sapxepsv(st_nH *head)
{
    st_Note * sorted = NULL;

    st_Note * current;

    current = head->next;
    while (current != NULL) {

        st_Note* next = current->next;

        sortedInsert(&sorted, current);

        current = next;
    }

    return sorted;
}

//___________________________________________________________________________________________________________________    
//      Doc note tu trong file
st_Note * themNotedoc(st_sv data)
{
    st_Note *note_add;
    note_add = (st_Note*)malloc(sizeof(st_Note));
    note_add->data_SV = data;
    note_add->next = NULL;

    return note_add;
}

//___________________________________________________________________________________________________________________    
//  Tim kiem
void TIMKIEM(st_nH * head)
{
    st_Note * p;
    p = head->next;
    int stt = 1;

    if(p == NULL)
    {
        printf(" List is Null\n");
    }
    else
    {   
        int stt = 1;
        int a = 0;
        int b = 0;
        printf("Nhap MSSV can tim:");
        scanf("%d",&a);

        while (p != NULL)
        {   
            if(a == p->data_SV.MSSV)
            {
                b = 1;
                printone(p,stt);
            }
            stt++;
            p = p->next;
        }

        // neu khong tim thay SV
        if (b != 1)
        {
            printf(" khong tim thay sinh vien");
        }
    }
}


//___________________________________________________________________________________________________________________    
//                  MAIN
void main()
{
    st_Note *p_A, *p_B;
    st_nH *head;
    p_A = (st_Note*)malloc(sizeof(st_Note));
    p_A->next = NULL;
    head = (st_nH*)malloc(sizeof(st_nH));
    head->next = p_A->next;

    // display user
    int seclect = 99;

    while (seclect != 9) // neu seclect khac ba thi chay tiep
    {
        printf("\n\t\t-- menu --\t\t\n");
        printf("\t[0] De nhap sinh vien\n");            //xong
        printf("\t[1] De xoa sinh vien\n");             //xong
        printf("\t[2] De sua thong tin sinh vien\n");   //xong
        printf("\t[3] De sap xep sinh vien\n");         //xong
        printf("\t[4] In het\n");                       //xong
        printf("\t[5] Nhap du lieu tu file\n");         //xong
        printf("\t[6] Xuat du lieu ra file \n");        //xong
        printf("\t[7] Tim sinh vien\n");                //xong
        printf("\t[9] De thoat\n");                     //xong
        printf("\tNhap: ");
        fflush(stdin);
        scanf("%d",&seclect);

        switch (seclect)
        {

//___________________________________________________________________________________________________________________    
// NHAP SV
        case 0:
            if (head->next == NULL)
            {   
                printf("NHAP CLASS DAU TIEN\n");
                p_A = themNote();
                head->next = p_A;
            }
            else
            {   
                printf("NHAP CLASS TIEP THEO\n");
                p_B = themNote();
                // p_A next mang dia chi cua p_B
                p_A->next = p_B;
                // luu vi tri o next
                p_A = p_A->next;
            }
            break;
        case 1:
            /* code */
            XOASV(head); 
            break;

        case 2:
            /* code */
            chinhsuasinhvien(head);
            break;

//___________________________________________________________________________________________________________________    
// IN SV
        case 4:
            /* code */
            if (head->next == NULL)
            {
                printf("VUI LONG NHAP SINH VIEN");
            }
            else
            {
                printnote(head);
            }
            break;    

//___________________________________________________________________________________________________________________    
// Nhap sinh vien tu file           
        case 5:
            st_sv sv;
            char dichi[50];

            printf("Nhap dia chi file.csv: VD: C:\\\\Program Files\\\\Google\\\\SINHVIEN.csv\nNhap: ");
            scanf("%s",dichi); 

            FILE *f;
            f = fopen(dichi,"r");
            if(f == NULL) 
            {
                printf("%s file not open!");
            }
            else
            {
                char line[N];
                while ( fgets(line,N,f) !=NULL)
                {
                    sscanf(line,"%[^,],%d,%d,%[^,],%d,%d,%d",sv.HvT,&sv.gioitinh,&sv.MSSV,sv.Nganh, &sv.namsinh.Ngay, &sv.namsinh.Thang, &sv.namsinh.Nam);
                    
                    if (head->next == NULL)
                    {   
                        printf("NHAP CLASS DAU TIEN\n");
                        p_A = themNotedoc(sv);
                        head->next = p_A;
                        
                    }
                    else
                    {   
                        printf("NHAP CLASS TIEP THEO\n");
                        p_B = themNotedoc(sv);
                        // p_A next mang dia chi cua p_B
                        p_A->next = p_B;
                        // luu vi tri o next
                        p_A = p_A->next;

                    }
                }
                printf("DA XONG");
            }
            fclose(f);
            //in ra
            printnote(head);

            break;

//___________________________________________________________________________________________________________________    
// Xuat sinh vien tu file              
        case 6:
            /* code */
            if (head->next == NULL)
            {
                printf("VUI LONG NHAP SINH VIEN");
            }
            else
            {
                ghi_SV(head);
            }
            break;

//___________________________________________________________________________________________________________________    
//          TImkiem
        case 7:
            TIMKIEM(head);                
            break;
//___________________________________________________________________________________________________________________    
//          EXIT        
        case 9:
            seclect = 9;
            break;
        default:
            break;
        }
    }
}
