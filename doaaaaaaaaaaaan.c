#include <stdio.h>


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
    char gioitinh[10];
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

    //NHp gioi tinh
    printf("\nNhap gioi tinh "); 
    scanf("%s",sv_nhap.gioitinh);

    // Nhap MSSV
    printf("\nNhap MSSV: "); 
    scanf("%d",&sv_nhap.MSSV);

    // Nhap Nganh hoc
    printf("\nNhap nganh hoc: "); 
    scanf("%s",sv_nhap.Nganh);

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
        printf("|stt\t|hovaten\t\t\t|gioitinh\t|MSSV\t\t|ttNganh\t\t|namsinh\n");
        while (p != NULL)
        {
            printf("|%d\t|%s\t\t\t|%s\t\t|%d\t\t|%s\t\t|%d/%d/%d\n",stt,p->data_SV.HvT,p->data_SV.gioitinh, p->data_SV.MSSV,p->data_SV.Nganh,p->data_SV.namsinh.Ngay,p->data_SV.namsinh.Thang,p->data_SV.namsinh.Nam);
            p = p->next;
            stt++;
        }
    }
    
}

//___________________________________________________________________________________________________________________    
//                  GHI SINH VIEN
void ghi_SV(st_nH * head)
{
    int a,b;
    int c,d;

    
    st_Note * p;
    
    

    p = head->next;
    int stt = 1;
    FILE *f = NULL;
    fopen_s(&f,"SINHVIEN.csv","w");
    while (p != NULL)
    {
        fprintf(f,"%s,%s,%d,%s,%d,%d,%d\n",p->data_SV.HvT,p->data_SV.gioitinh,p->data_SV.MSSV,p->data_SV.Nganh,p->data_SV.namsinh.Ngay,p->data_SV.namsinh.Thang,p->data_SV.namsinh.Nam);
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
//      
st_Note * themNotedoc(st_sv data)
{
    st_Note *note_add;
    note_add = (st_Note*)malloc(sizeof(st_Note));
    note_add->data_SV = data;
    note_add->next = NULL;

    return note_add;
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
        printf("\t[0] De nhap sinh vien\n");        ///xong
        printf("\t[1] De xoa sinh vien\n");         //chua
        printf("\t[2] De sua thong tin sinh vien\n");//chua
        printf("\t[3] De sap xep sinh vien\n");     //gan xong
        printf("\t[4] In het\n");                   //xong
        printf("\t[5] Nhap du lieu tu file\n");     //xong
        printf("\t[6] Xuat du lieu ra file \n");    //xong
        printf("\t[7] Tim sinh vien\n");            //chua
        printf("\t[9] De thoat\n");                 //xong
        printf("\tNhap: ");
        
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
            break;
        case 1:
            /* code */
            printf("hi 1");
            break;

        case 2:
            /* code */
            printf("hi 2");
            break;

//___________________________________________________________________________________________________________________
// SAP XEP SV
        case 3:
            if (head->next == NULL)
            {
                printf("HIEN TAI CHUA CO SINH VIEN NAO");
            }
            else{
                p_A = sapxepsv(head);
                head->next = p_A;
                printnote(head);
            }
            
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
                    sscanf(line,"%[^,],%[^,],%d,%[^,],%d,%d,%d",sv.HvT, sv.gioitinh, &sv.MSSV, sv.Nganh, &sv.namsinh.Ngay, &sv.namsinh.Thang, &sv.namsinh.Nam);
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
        case 9:
            seclect = 9;
            break;
        default:
            break;
        }
        

    }
}
