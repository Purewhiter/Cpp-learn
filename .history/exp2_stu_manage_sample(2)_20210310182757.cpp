#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ST_MAX 1000
#define Name_MAX 100

typedef struct {
    int num;
    char name[20];
    char sex[10];
    int age;
    char addr[20];
}st;//ѧ���ṹ�嶨��

st stArray[ST_MAX];//ȫ������
int aCount=0;//��������ƣ����ڼ�¼�����е�ѧ������
FILE *fp;   //ȫ���ļ���0������

/*������Ԥ������*/
int add();//��������һ��ѧ����¼��
int search();//����ʵ�ְ�ѧ�Ų�ѯ����
int search_id(int id);//ʵ�ְ�ѧ�Ų�ѯ���ܣ������������±ꡣ
int display();//��ʾ����ѧ����Ϣ
int display_file(void);//���ļ���ʾ��¼
void show_menu();//���˵�
int init();//���ļ����ݶ���ȫ�������С�
int saveback();//������ѧ���������д���ļ��С�
int del();//����ѧ��ɾ��ѧ����¼����
int modify();//�޸Ĺ���


int main(void)//������
{
    printf("init:%d\n",init());
    printf("��ǰѧ����¼��Ϊ��%d\n",aCount);
    int input=1,i=0;
    char s[Name_MAX];
    while(input)
    {
    	printf("\n��ѡ���ܣ�\n") ; 
        show_menu();
        printf("please input:>");
        scanf("%d",&input);
        switch(input)//�жϲ����ú���
        {
        case 1:
            {
                add();
                //system("cls");//������������
                break;
            }
        case 2:
            {
                del();
                //system("cls");//������������
                break;
            }
        case 3:
        	{ 
        		printf("������Ҫ���ҵ�ѧ��������\n");
        		char name[20];
        		scanf("%s",name);
            	search(name);
				//system("cls");//������������
            	break;
            } 
        case 4:
            {
                modify();
                //system("cls");//������������
                break;
            }
        case 5:
            printf("��ȫ�������ж��Ľ����\n");
            display();//��������ʾ��¼
            printf("ֱ�Ӷ��ļ��Ľ����\n");
            saveback();
            display_file();//���ļ���ʾ��¼
            break;
        case 0:
            break;
        default:
            break;
        }
    }
    return 0;
}

void show_menu()
{
    printf("      *********menu**************\n");
    printf("      *   1>add       2>del     *\n");
    printf("      *   3>search    4>modify  *\n");
    printf("      *   5>show      0>end     *\n");
    printf("      ***************************\n");
}

int init()
{
    st stu;
    int count=0;
    fp=fopen("stu_data","r");
    if(!fp)
    {
        printf("��û���κ�ѧ����Ϣ\n");
        return -1;
    }
    while(!feof(fp))
    {
        if(fread(&stu, sizeof(stu),1,fp))
            stArray[count++]=stu;
        else
            break;
    }
    aCount=count;
    rewind(fp);
    fclose(fp);
    printf("init done!\n");
    return 0;
}

int add(void)
{
    if(aCount<ST_MAX)
    {
    	printf("����ȷ������ѧ����Ϣ����ʽ��ѧ�� ���� �Ա� ���� ����ϵ�������ո�ָ������س�������\n");
    	scanf("%d %s %s %d %s",&stArray[aCount].num,stArray[aCount].name,stArray[aCount].sex,&stArray[aCount].age,stArray[aCount].addr);
    	aCount++;
    	printf("���Ӻ�\n");
    	display();
    	printf("add done!\n");
    	return 0;
	}
    else
    {
    	printf("�ռ䲻�㣡");
		return -1; 
	}
	
}


//����������,���������±꣬����ӡ��ѧ������
int search(char *s)
{
    char *t;
    int i=0;
    while(i<aCount)
    {
        t=stArray[i].name;
        if(strcmp(t,s)==0)
        {
            printf("���ҳɹ�����ѧ����ϢΪ��num=%d,name=%s,sex=%s,age=%d,addr=%s\n",stArray[i].num,stArray[i].name,stArray[i].sex,stArray[i].age,stArray[i].addr);
            return i;
        }
        i++;   
    }
    printf("search done!\n");
    return -1;;
}

//��ѧ�Ų���,���������±꣬����ӡ��ѧ������
int search_id(int id)
{
    int i=0;
    while(i<aCount)
    {
        if(stArray[i].num==id)
        {
            printf("���ҳɹ�����ѧ����ϢΪ��num=%d,name=%s,sex=%s,age=%d,addr=%s\n",stArray[i].num,stArray[i].name,stArray[i].sex,stArray[i].age,stArray[i].addr);
            return i;
        }  
        i++; 
    }  
	printf("search_id done!\n");   
    return -1;
}

//ͨ��ѧ��ɾ��ѧ����¼
int del()
{
    int id;
    printf("������Ҫɾ����ѧ����ţ�");
    scanf("%d",&id);
    int num=search_id(id);//��ѧ���������еı��
    if(num!=-1)
    {
        for(;num<aCount;num++)
            stArray[num]=stArray[num+1];
        aCount--;
        printf("�޸ĺ�\n");
        display();
        printf("del done!\n");
        return 0;
    }
    else
    {
        printf("û���ҵ���ѧ����\n");
        return -1;
    }   
}

int modify()
{
    int i;
    for(i=0;i<aCount;i++)
        stArray[i].age++;
    printf("�ò���������ѧ����������һ��,�޸ĺ�\n");
    display();
    printf("modify done!\n");
    return 0;
}       


int display(void)
{
    int i;
    for(i=0;i<aCount;i++)
        printf("num=%d,name=%s,sex=%s,age=%d,addr=%s\n",stArray[i].num,stArray[i].name,stArray[i].sex,stArray[i].age,stArray[i].addr);
    printf("display done!\n");
	return 0;
}

int saveback()
{
    int i;
    fp=fopen("stu_data","w");
    if(!fp)
    {
        printf("error\n");
        return -1;
    }

    for(i=0;i<=aCount;i++)
        fwrite(&stArray[i],sizeof(stArray[i]),1,fp);

    if(ferror(fp))
        printf("д�ļ�ʧ��\n");
    else
        printf("����ɹ�\n");
    rewind(fp);
    fclose(fp);
}

int display_file(void)
{
	st stu;
    fp=fopen("stu_data","r");
    if(!fp)
    {
        printf("�ļ���ʧ�ܣ�\n");
        exit(-1);
    }
    while(!feof(fp))
    {
        if(fread(&stu, sizeof(stu),1,fp))
            printf("num=%d,name=%s,sex=%s,age=%d,addr=%s\n",stu.num,stu.name,stu.sex,stu.age,stu.addr);
        else
            break;
    }
    rewind(fp);
    fclose(fp);
    return 0;
}
