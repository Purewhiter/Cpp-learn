#include <fstream>
#include <iostream>
using namespace std;
#define ST_MAX 1000
#define Name_MAX 100
struct st
{
    int num;
    string name;
    string sex;
    int age;
    string addr;
};                  //学生结构体定义
static st stArray[ST_MAX]; //全局数组
int aCount = 0;     //数组记数计，用于记录数组中的学生数。
fstream fp;         //全局文件流
/*程序函数预定义区*/
int add();               //用于输入一条学生记录。
int search(string name); //用于实现按学号查询功能
int search_id(int id);   //实现按学号查询功能，并返回数组下标。
int display();           //显示所有学生信息
int display_file(void);  //读文件显示记录
void show_menu();        //主菜单
int init();              //将文件内容读入全局数组中。
int saveback();          //将更新学生后的数组写回文件中。
int del();               //按照学号删除学生记录功能
int modify();            //修改功能

int main(void) //主程序
{
    printf("init:%d\n", init());
    printf("当前学生记录数为：%d\n", aCount);
    int input = 1, i = 0;
    char s[Name_MAX];
    while (input)
    {
        printf("\n请选择功能：\n");
        show_menu();
        printf("please input:>");
        scanf("%d", &input);
        switch (input) //判断并调用函数
        {
        case 1:
        {
            add();
            //system("cls");//调用清屏函数
            break;
        }
        case 2:
        {
            del();
            //system("cls");//调用清屏函数
            break;
        }
        case 3:
        {
            printf("请输入要查找的学生姓名：\n");
            string name;
            cin >> name;
            search(name);
            //system("cls");//调用清屏函数
            break;
        }
        case 4:
        {
            modify();
            //system("cls");//调用清屏函数
            break;
        }
        case 5:
            printf("从全局数组中读的结果：\n");
            display(); //读数组显示记录
            printf("直接读文件的结果：\n");
            display_file(); //读文件显示记录
            break;
        case 0:
            saveback();
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
    int count = 0;
    fp.open("stu_data.txt", ios::in);
    if (!fp)
    {
        printf("还没有任何学生信息\n");
        return -1;
    }
    while (!fp.eof())
    {
        fp >> stArray[count].num >> stArray[count].name >> stArray[count].sex >> stArray[count].age >> stArray[count].addr;
        count++;
        // if(fread(&stu, sizeof(stu),1,fp))
        //     stArray[count++]=stu;
        // else
        //     break;
    }
    aCount = count;
    fp.close();
    printf("init done!\n");
    return 0;
}

int add(void)
{
    if (aCount < ST_MAX)
    {
        printf("请正确的输入学生信息，格式：学号 姓名 性别 年龄 所在系（单个空格分隔），回车键结束\n");
        cin >> stArray[aCount].num >> stArray[aCount].name >> stArray[aCount].sex >> stArray[aCount].age >> stArray[aCount].addr;
        aCount++;
        printf("增加后：\n");
        display();
        printf("add done!\n");
        saveback();
        return 0;
    }
    else
    {
        printf("空间不足！");
        return -1;
    }
}

//按姓名查找,返回数组下标，并打印该学生数据
int search(string s)
{
    string t;
    int i = 0;
    while (i < aCount)
    {
        t = stArray[i].name;
        if (t == s)
        {
            cout << "查找成功，该学生信息为：num=" << stArray[i].num << ",name=" << stArray[i].name << ",sex=" << stArray[i].sex << ",age=" << stArray[i].age << ",addr=" << stArray[i].addr << endl;
            return i;
        }
        i++;
    }
    printf("search done!\n");
    return -1;
    ;
}

//按学号查找,返回数组下标，并打印该学生数据
int search_id(int id)
{
    int i = 0;
    while (i < aCount)
    {
        if (stArray[i].num == id)
        {
            cout << "查找成功，该学生信息为：num=" << stArray[i].num << ",name=" << stArray[i].name << ",sex=" << stArray[i].sex << ",age=" << stArray[i].age << ",addr=" << stArray[i].addr << endl;
            return i;
        }
        i++;
    }
    printf("search_id done!\n");
    return -1;
}

//通过学号删除学生记录
int del()
{
    int id;
    printf("请输入要删除的学生编号：");
    scanf("%d", &id);
    int num = search_id(id); //该学生在数组中的标号
    if (num != -1)
    {
        for (; num < aCount; num++)
            stArray[num] = stArray[num + 1];
        aCount--;
        printf("修改后：\n");
        display();
        printf("del done!\n");
        return 0;
    }
    else
    {
        printf("没有找到该学生！\n");
        return -1;
    }
}

int modify()
{
    int i;
    for (i = 0; i < aCount; i++)
        stArray[i].age++;
    printf("该操作将所有学生年龄增加一岁,修改后：\n");
    display();
    printf("modify done!\n");
    return 0;
}

int display(void)
{
    int i;
    for (i = 0; i < aCount; i++)
        cout << stArray[i].num << ",name=" << stArray[i].name << ",sex=" << stArray[i].sex << ",age=" << stArray[i].age << ",addr=" << stArray[i].addr << endl;
    printf("display done!\n");
    return 0;
}

int saveback()
{
    int i;
    fp.open("stu_data.txt", ios::out);
    if (!fp)
    {
        printf("error\n");
        return -1;
    }

    for (i = 0; i <= aCount; i++)
    {
        fp << stArray[i].num <<" "<< stArray[i].name <<" " <<stArray[i].sex <<" "<< stArray[i].age <<" "<< stArray[i].addr << endl;
    }

    // if(fp.)
    //     printf("写文件失败\n");
    // else
    //     printf("保存成功\n");
    fp.close();
    printf("保存成功\n");
    // rewind(fp);
    // fclose(fp);
}

int display_file(void)
{
    st stu;
    fp.open("stu_data.txt", ios::in);
    // if()
    // {
    //     printf("文件打开失败！\n");
    //     exit(-1);
    // }
    while (fp << stu.num << stu.name << stu.sex << stu.age << stu.addr << endl)
    {
        // if(fread(&stu, sizeof(stu),1,fp))
        //     printf("num=%d,name=%s,sex=%s,age=%d,addr=%s\n",stu.num,stu.name,stu.sex,stu.age,stu.addr);
        // else
        //     break;
        
        cout << stu.num << stu.name << stu.sex << stu.age << stu.addr << endl;
    }
    fp.close();
    return 0;
}
