#include <stdio.h>

//hello there


//___________________________________________________________________________________________________________________    
// kieu du lieu struct

typedef struct SV
{
    char HvT[20];
    int MSSV;
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
//input student input

st_sv nhapdulieusv()
{   
    st_sv sv_nhap;

    printf("Nhap ho va ten sinh vien: "); 
    scanf("%s",sv_nhap.HvT);

    printf("Nhap MSSV: "); 
    scanf("%d",&sv_nhap.MSSV);
    
    printf("Nhap ngaanh hoc: "); 
    scanf("%s",sv_nhap.Nganh);

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
    st_Note *p;
    p = head->next;
    if(p == NULL)
    {
        printf(" List is Null\n");
    }
    else
    {   
        printf("\n\t\tlist\n");
        while (p != NULL)
        {
            printf("Ho&Ten\t: %s\t|\tMSSV\t: %d\t|\tNganh\t: %s\t\n",p->data_SV.HvT,p->data_SV.MSSV,p->data_SV.Nganh);
            p = p->next;
        }
    }
    
}

void main()
{

    st_Note *p_A, *p_B;
    st_nH *head;
    p_A = (st_Note*)malloc(sizeof(st_Note));
    p_A->next =NULL;
    head->next = p_A->next;

    // display user
    int seclect = 99;
    while (seclect != 9) // neu seclect khac ba thi chay tiep
    {
        printf("\n\t\t-- menu --\t\t\n");
        printf("\t[0] De nhap sinh vien\n");
        printf("\t[1] De xoa sinh vien\n");
        printf("\t[2] De sua thong tin sinh\n");
        printf("\t[3] De xap sap sinh\n");
        printf("\t[4] In het\n");

        printf("\t[9] De thoat\n");
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
// IN SV
        case 3:
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

            break;    
        case 9:
            seclect = 9;
            break;
        default:
            break;
        }
        

    }
}
