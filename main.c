#include <stdio.h>
#include <stdlib.h>
#include<string.h>

typedef struct _student* posST;
typedef struct _podatci* posPO;
typedef struct _kolegij* posKO;


typedef struct _student
{
    int id_student;
    char ime[100];
    char prezime[100];
    int god_rod;

    posST next;
    posPO down;

}student;

typedef struct _podatci
{
    double prosjek;
    int pol_ects;
    int skolarina;

    posKO down;

}podatci;

typedef struct _kolegij
{
    int id_kolegij;
    char ime_kolegij[100];
    int ects_kol;
    int ocjena;

    posKO down;

}kolegij;


posST CreateNodeST(void);
posKO CreateNodeKO(void);
posPO CreateNodePO(void);

int ListStudent(char* FileName, posST p);
void PrintStudentList(posST p);

int tempListKolegij(char *filename, posKO p);
void PrintKolegijList(posKO p);

void UnosStudenata(posST);
void ListKolegij(posST p, posKO q);

int FindStudent(posST p, int);
int FindKolegij(posKO p, int);

int main()
{
    posST headST= NULL;
    posKO headKO= NULL;

    headST = CreateNodeST();
    headKO = CreateNodeKO();

    char filename[50];
    printf("Unesite ime datoteke koja sadrzi podatke o studentima\n");
    scanf("%s", filename);

    //bilo &headST
    if(ListStudent(filename, headST))
    {
        printf("\nUspjesno unesena lista studenata.\n");
        PrintStudentList(headST->next);
    }

    printf("Unesite ime datoteke koja sadrzi kolegije\n");
    scanf("%s", filename);

    //bilo &headKO
    if(tempListKolegij(filename, headKO))
    {
        printf("\nUspjesno unesena lista kolegija.\n");
        PrintKolegijList(headKO->down);
    }

    return 0;
}


posST CreateNodeST(void)
{
    posST q = NULL;
    q = (posST)malloc(sizeof(student));
    q -> next = NULL;

    if(q == NULL)
    {
        printf("Neuspjela alokacija memorije u funkciji CreateNode Student. Vracen NULL pointer");
        return NULL;
    }

    return q;
}

posKO CreateNodeKO(void)
{
    posKO q = NULL;
    q = (posKO)malloc(sizeof(kolegij));
    q -> down = NULL;

    if(q == NULL)
    {
        printf("Neuspjela alokacija memorije u funkciji CreateNode Kolegij. Vracen NULL pointer");
        return NULL;
    }

    return q;
}

posPO CreateNodePO(void)
{
    posPO q = NULL;
    q = (posPO)malloc(sizeof(podatci));
    q -> down = NULL;

    if(q == NULL)
    {
        printf("Neuspjela alokacija memorije u funkciji CreateNode Polozeno. Vracen NULL pointer");
        return NULL;
    }

    return q;
}

int ListStudent(char* FileName, posST p)
{

    if(p == NULL)
    {
        printf("U funkciji ListStudent poslana prazna lista. Vracena nula.\n");
        return 0;
    }

    FILE *fp = NULL;
    fp = fopen(FileName, "r");

    if(fp == NULL)
    {
        printf("U funkciji ListStudent neuspjelo otvaranje datoteke. Vracena nula.\n");
        return 0;
    }

    posST q = NULL;
    posPO d = NULL;

    while(!feof(fp))
    {
        q = CreateNodeST();
        d = CreateNodePO();
        fscanf(fp, "%d %s %s %d", &q->id_student, q ->ime, q->prezime, &q->god_rod);

        q->next = p->next;
        p->next = q;
        q->down = d;
    }

    return 1;
}

void PrintStudentList(posST p)
{
    while(p!=NULL)
    {
        printf("%d %s %s %d\n", p->id_student, p->ime, p->prezime, p->god_rod);
        p = p->next;
    }
}

void PrintKolegijList(posKO p)
{
    while(p!=NULL)
    {
        printf("%d %s %d %d\n", p->id_kolegij, p->ime_kolegij, p->ects_kol, p->ocjena);
        p = p->down;
    }
}

int tempListKolegij(char *filename, posKO p)
{

    if(p == NULL)
    {
        printf("U funkciji tempListKolegij poslana prazna lista. Vracena nula.\n");
        return 0;
    }
    else
        printf("U funkciji tempListKolegij poslana dobra lista.\n");

    FILE *fp = NULL;
    fp = fopen(filename, "r");

    if(fp == NULL)
    {
        printf("U funkciji tempListKolegij neuspjelo otvaranje datoteke. Vracena nula.\n");
        return 0;
    }
    else
        printf("U funkciji tempListKolegij uspjesno otvorena datoteka.\n");


    while(!feof(fp))
    {
        posKO q = NULL;
        q = CreateNodeKO();
        fscanf(fp, "%d %s %d", &q->id_kolegij, q->ime_kolegij, &q->ects_kol);
        q->ocjena = 0;
        //printf("%d %s %d %d\n", q->id_kolegij, q->ime_kolegij, q->ects_kol, q->ocjena);

        q->down = p->down;
        p->down = q;
    }
    return 1;
}

void ListKolegij(posST p, posKO q)
{
    posST headST = p;
    posKO headKO = q;
    posKO nodeKolegij = NULL;

    FILE *fp = NULL;
    fp = fopen("polozeno.txt","r");

    int student;
    int kolegij;
    int ocjena;

    posST tempST = NULL;
    posKO tempKO = NULL;

    /*while(!feof(fp))
    {
        fscanf("%d %d %d", student, kolegij, ocjena);
        tempST = FindStudent(headST, student);
        tempKO = FindKolegij(headKO, kolegij);
        nodeKolegij = CreateNodeKO();
        nodeKolegij->id_kolegij = tempKO->id_kolegij;
        strcpy(nodeKolegij->ime_kolegij, tempKO->ime_kolegij);
        nodeKolegij->ects_kol = tempKO->ects_kol;
        nodeKolegij->down = tempKO->down->down;
        tempST->down->down = nodeKolegij;
    }*/

}