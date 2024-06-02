#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// 定义一个学生成绩结构体
struct score
{
    double chinese;
    double math;
    double english;
    double physics;
    double chemistry;
    double biology;
    double sum;
    int list;
};

// 定义一个学生列表结构体
struct student
{
    long long id;
    string name;
    struct score studentsScore;
};

// 定义一个学生管理系统结构体
struct manager
{
    int number;
    struct student studentList[30];
};

// 主界面函数
void main_Menu()
{
    cout << "==================你干嘛哎呦=================" << endl;
    cout << "This system is wirtten by:Monica:) ,plase click👉 骑小电驴浪迹天涯" << endl;
    cout << "1 ----->录入每个学生的学号、姓名和各科考试成绩<-------------------------------------------------------------------" << endl;
    cout << "2 ----->计算每门课程的总分和平均分<------------------------------------------------------------------------------" << endl;
    cout << "3 ----->计算每个学生的总分和平均分<------------------------------------------------------------------------------" << endl;
    cout << "4 ----->按每个学生的总分由高到低排出名次表<-----------------------------------------------------------------------" << endl;
    cout << "5 ----->按每个学生的总分由低到高排出名次表<-----------------------------------------------------------------------" << endl;
    cout << "6 ----->按学号由小到大排出成绩表<--------------------------------------------------------------------------------" << endl;
    cout << "7 ----->按姓名的字典顺序排出成绩表<------------------------------------------------------------------------------" << endl;
    cout << "8 ----->按学号查询学生排名及其考试成绩<--------------------------------------------------------------------------" << endl;
    cout << "9 ----->按姓名查询学生排名及其考试成绩<--------------------------------------------------------------------------" << endl;
    cout << "10 ----->按优秀、良好、中等、及格、不及格，对每门课程分别统计每个类别的人数以及所占的百分比<--------------------------" << endl;
    cout << "11 ----->输出每个学生的学号、姓名、各科考试成绩，以及每门课程的总分和平均分<----------------------------------------" << endl;
    cout << "0 EXIT 退出程序" << endl;
    cout << "==================哎呦你干嘛=================" << endl;
    cout << "请输入数字进行您想要的操作：" << endl;
}

// 01录入功能
void signIn(manager *studentManager)
{
    cout << "请按照顺序依次输入每位学生的学号、姓名、各科成绩👉：" << endl;

    for (int i = studentManager->number; i < 30; i++)
    {
        cout << "现在进行第" << i + 1 << "位同学的信息录入，请输入姓名：";
        cin >> studentManager->studentList[i].name;
        cout << "请输入学号：";
        cin >> studentManager->studentList[i].id;
        cout << "=======================" << endl;
        cout << "========请输入各科成绩=========" << endl;
        cout << "请输入语文成绩：" << endl;
        cin >> studentManager->studentList[i].studentsScore.chinese;

        cout << "请输入数学成绩：" << endl;
        cin >> studentManager->studentList[i].studentsScore.math;

        cout << "请输入英语成绩：" << endl;
        cin >> studentManager->studentList[i].studentsScore.english;

        cout << "请输入物理成绩：" << endl;
        cin >> studentManager->studentList[i].studentsScore.physics;

        cout << "请输入化学成绩：" << endl;
        cin >> studentManager->studentList[i].studentsScore.chemistry;

        cout << "请输入生物成绩：" << endl;
        cin >> studentManager->studentList[i].studentsScore.biology;

        studentManager->number++;

        while (true)
        {
            cout << "第" << studentManager->number << "位学生信息录入成功！现在是否进行下一位同学信息录入？请输入[y/n]？" << endl;
            string chance;
            cin >> chance;

            if (chance == "y")
            {
                break;
            }
            else if (chance == "n")
            {
                i = 30;
                break;
            }
            else
            {
                cout << "警告：请按照要求输入！！！！" << endl;
                continue;
            }
        }
    }
    cout << "========所有信息录入成功!按ENTER键返回到主页面！=========" << endl;
}

// 02计算各个科的总分和平均值
void AllScore(manager *studentManager)
{
    double average[6] = {0};
    if (studentManager->number == 0)
    {
        cout << "学生列表为空！请添加学生列表再进行操作！" << endl;
    }
    else
    {
        cout << "正在计算各个科目的总分平均值中........." << endl;
        for (int j = 0; j < studentManager->number; j++)
        {
            average[0] += studentManager->studentList[j].studentsScore.chinese;
            average[1] += studentManager->studentList[j].studentsScore.math;
            average[2] += studentManager->studentList[j].studentsScore.english;
            average[3] += studentManager->studentList[j].studentsScore.physics;
            average[4] += studentManager->studentList[j].studentsScore.chemistry;
            average[5] += studentManager->studentList[j].studentsScore.biology;
        }
        cout << "各个科目的总分平均值计算成功！结果如下：" << endl;
        cout << "总共有" << studentManager->number << "位学生:" << endl;
        cout << "语文平均分：" << fixed << setprecision(2) << average[0] / double(studentManager->number) << endl;
        cout << "数学平均分：" << fixed << setprecision(2) << average[1] / double(studentManager->number) << endl;
        cout << "英语平均分：" << fixed << setprecision(2) << average[2] / double(studentManager->number) << endl;
        cout << "物理平均分：" << fixed << setprecision(2) << average[3] / double(studentManager->number) << endl;
        cout << "化学平均分：" << fixed << setprecision(2) << average[4] / double(studentManager->number) << endl;
        cout << "生物平均分：" << fixed << setprecision(2) << average[5] / double(studentManager->number) << endl;
        cout << "===========程序结束==========" << endl;
    }
}

// 03计算每个学生的总分和平均值
void studentAllScore(manager *studentManager)
{
    cout << "计算每个学生的总分和平均值中......." << endl;
    for (int i = 0; i < studentManager->number; i++)
    {
        studentManager->studentList[i].studentsScore.sum += studentManager->studentList[i].studentsScore.chinese;
        studentManager->studentList[i].studentsScore.sum += studentManager->studentList[i].studentsScore.math;
        studentManager->studentList[i].studentsScore.sum += studentManager->studentList[i].studentsScore.english;
        studentManager->studentList[i].studentsScore.sum += studentManager->studentList[i].studentsScore.physics;
        studentManager->studentList[i].studentsScore.sum += studentManager->studentList[i].studentsScore.chemistry;
        studentManager->studentList[i].studentsScore.sum += studentManager->studentList[i].studentsScore.biology;
        cout << "以下是同学的总分以及平均分：" << endl;
        cout << i + 1 << ". " << studentManager->studentList[i].name << "同学：总分" << studentManager->studentList[i].studentsScore.sum;
        cout << "平均分：" << studentManager->studentList[i].studentsScore.sum / double(studentManager->number) << endl;
    }
    cout << "录入的同学总分还有平均值都成功录入！即将返回主页......." << endl;
}

// 04按成绩从高到低排名
void ScoreDown(manager *studentManager)
{
    cout << "正在进行排序，排名将从高到低！" << endl;
    for (int i = 0; i < studentManager->number; i++)
    {
        studentManager->studentList[i].studentsScore.sum += studentManager->studentList[i].studentsScore.chinese;
        studentManager->studentList[i].studentsScore.sum += studentManager->studentList[i].studentsScore.math;
        studentManager->studentList[i].studentsScore.sum += studentManager->studentList[i].studentsScore.english;
        studentManager->studentList[i].studentsScore.sum += studentManager->studentList[i].studentsScore.physics;
        studentManager->studentList[i].studentsScore.sum += studentManager->studentList[i].studentsScore.chemistry;
        studentManager->studentList[i].studentsScore.sum += studentManager->studentList[i].studentsScore.biology;
    }
    double down[studentManager->number] = {0};
    for (int i = 0; i < studentManager->number; i++)
    {
        down[i] = studentManager->studentList[i].studentsScore.sum;
    }
    cout << "排名(降序)：" << endl;
    for (int i = 0; i < studentManager->number - 1; i++)
    {
        for (int j = 0; j < studentManager->number - i - 1; j++)
        {
            if (down[j + 1] > down[j])
            {
                double temp;
                temp = down[j];
                down[j] = down[j + 1];
                down[j + 1] = temp;
            }
        }
    }
    cout << "排序成功！降序结果如下：" << endl;
    for (int i = 0; i < studentManager->number; i++)
    {
        cout << "降序第" << i << "名：" << down[i] << endl;
    }
    cout << "程序结束！返回主页面中......." << endl;
}

// 05按成绩从低到高排名
void ScoreUp(manager *studentManager)
{
    cout << "正在进行排序，排名将从低到高！" << endl;
    for (int i = 0; i < studentManager->number; i++)
    {
        studentManager->studentList[i].studentsScore.sum += studentManager->studentList[i].studentsScore.chinese;
        studentManager->studentList[i].studentsScore.sum += studentManager->studentList[i].studentsScore.math;
        studentManager->studentList[i].studentsScore.sum += studentManager->studentList[i].studentsScore.english;
        studentManager->studentList[i].studentsScore.sum += studentManager->studentList[i].studentsScore.physics;
        studentManager->studentList[i].studentsScore.sum += studentManager->studentList[i].studentsScore.chemistry;
        studentManager->studentList[i].studentsScore.sum += studentManager->studentList[i].studentsScore.biology;
    }
    double up[studentManager->number] = {0};
    for (int i = 0; i < studentManager->number; i++)
    {
        up[i] = studentManager->studentList[i].studentsScore.sum;
    }
    cout << "排名(升序)：" << endl;
    for (int i = 0; i < studentManager->number - 1; i++)
    {
        for (int j = 0; j < studentManager->number - i - 1; j++)
        {
            if (up[j + 1] < up[j])
            {
                double temp;
                temp = up[j];
                up[j] = up[j + 1];
                up[j + 1] = temp;
            }
        }
    }
    cout << "排序成功！升序结果如下：" << endl;
    for (int i = 0; i < studentManager->number; i++)
    {
        cout << "升序第" << i + 1 << "名：" << up[i] << endl;
    }
    cout << "程序结束！返回主页面中......." << endl;
}

// 06按学号从低到高排名
void IdUp(manager *studentManager)
{
    cout << "正在进行学号大小排序！" << endl;
    manager studentManagerCopy = *studentManager;
    for (int i = 0; i < studentManagerCopy.number; i++)
    {
        studentManagerCopy.studentList[i].studentsScore.sum += studentManagerCopy.studentList[i].studentsScore.chinese;
        studentManagerCopy.studentList[i].studentsScore.sum += studentManagerCopy.studentList[i].studentsScore.math;
        studentManagerCopy.studentList[i].studentsScore.sum += studentManagerCopy.studentList[i].studentsScore.english;
        studentManagerCopy.studentList[i].studentsScore.sum += studentManagerCopy.studentList[i].studentsScore.physics;
        studentManagerCopy.studentList[i].studentsScore.sum += studentManagerCopy.studentList[i].studentsScore.chemistry;
        studentManagerCopy.studentList[i].studentsScore.sum += studentManagerCopy.studentList[i].studentsScore.biology;
    }
    cout << "排名(升序)：" << endl;
    for (int i = 0; i < studentManagerCopy.number - 1; i++)
    {
        for (int j = 0; j < studentManagerCopy.number - i - 1; j++)
        {
            if (studentManagerCopy.studentList[j + 1].id < studentManagerCopy.studentList[j].id)
            {
                student temp = studentManagerCopy.studentList[j];
                studentManagerCopy.studentList[j] = studentManagerCopy.studentList[j + 1];
                studentManagerCopy.studentList[j + 1] = temp;
            }
        }
    }
    cout << "按ID排序成功！升序结果如下：" << endl;
    for (int i = 0; i < studentManagerCopy.number; i++)
    {
        cout << "===========成绩表==========" << endl;
        cout << "学号：" << studentManagerCopy.studentList[i].id << ",成绩如下：" << endl;
        cout << "语文：" << studentManagerCopy.studentList[i].studentsScore.chinese << endl;
        cout << "数学：" << studentManagerCopy.studentList[i].studentsScore.math << endl;
        cout << "英语：" << studentManagerCopy.studentList[i].studentsScore.english << endl;
        cout << "物理：" << studentManagerCopy.studentList[i].studentsScore.physics << endl;
        cout << "化学：" << studentManagerCopy.studentList[i].studentsScore.chemistry << endl;
        cout << "生物：" << studentManagerCopy.studentList[i].studentsScore.biology << endl;
        cout << "总分：" << studentManagerCopy.studentList[i].studentsScore.sum << endl;
    }
    cout << "程序结束！返回主页面中......." << endl;
}

// 07按姓名的字典顺序排出成绩表
void dictionary(manager *studentManager)
{
    cout << "不想写，别看了" << endl;
}

// 08按学号查询成绩
void IdSearch(manager *studentManager)
{
    double down[studentManager->number] = {0};
    for (int i = 0; i < studentManager->number; i++)
    {
        studentManager->studentList[i].studentsScore.sum += studentManager->studentList[i].studentsScore.chinese;
        studentManager->studentList[i].studentsScore.sum += studentManager->studentList[i].studentsScore.math;
        studentManager->studentList[i].studentsScore.sum += studentManager->studentList[i].studentsScore.english;
        studentManager->studentList[i].studentsScore.sum += studentManager->studentList[i].studentsScore.physics;
        studentManager->studentList[i].studentsScore.sum += studentManager->studentList[i].studentsScore.chemistry;
        studentManager->studentList[i].studentsScore.sum += studentManager->studentList[i].studentsScore.biology;
    }
    for (int i = 0; i < studentManager->number; i++)
    {
        down[i] = studentManager->studentList[i].studentsScore.sum;
    }
    for (int i = 0; i < studentManager->number - 1; i++)
    {
        for (int j = 0; j < studentManager->number - i - 1; j++)
        {
            if (down[j + 1] > down[j])
            {
                double temp;
                temp = down[j];
                down[j] = down[j + 1];
                down[j + 1] = temp;
            }
        }
    }
    for (int i = 0; i < studentManager->number; i++)
    {
        for (int j = 0; j < studentManager->number; j++)
        {
            if (down[i] == studentManager->studentList[j].studentsScore.sum)
            {
                studentManager->studentList[j].studentsScore.list = i + 1;
            }
        }
    }
    cout << "请输入您想要查询的学号：" << endl;
    long long searchId;
    cin >> searchId;
    for (int i = 0; i < studentManager->number; i++)
    {
        if (searchId == studentManager->studentList[i].id)
        {
            cout << "查询成功！学号：" << studentManager->studentList[i].id << endl;
            cout << "总分：" << down[studentManager->studentList[i].studentsScore.list - 1] << endl;
            cout << "排名：" << studentManager->studentList[i].studentsScore.list << endl;
            cout << "语文：" << studentManager->studentList[i].studentsScore.chinese << endl;
            cout << "数学：" << studentManager->studentList[i].studentsScore.math << endl;
            cout << "英语：" << studentManager->studentList[i].studentsScore.english << endl;
            cout << "物理：" << studentManager->studentList[i].studentsScore.physics << endl;
            cout << "化学：" << studentManager->studentList[i].studentsScore.chemistry << endl;
            cout << "生物：" << studentManager->studentList[i].studentsScore.biology << endl;
            break;
        }
    }
    cout << "程序结束！返回主页面中......." << endl;
}

// 09按姓名查询成绩
void NameSearch(manager *studentManager)
{
    double down[studentManager->number] = {0};
    for (int i = 0; i < studentManager->number; i++)
    {
        studentManager->studentList[i].studentsScore.sum += studentManager->studentList[i].studentsScore.chinese;
        studentManager->studentList[i].studentsScore.sum += studentManager->studentList[i].studentsScore.math;
        studentManager->studentList[i].studentsScore.sum += studentManager->studentList[i].studentsScore.english;
        studentManager->studentList[i].studentsScore.sum += studentManager->studentList[i].studentsScore.physics;
        studentManager->studentList[i].studentsScore.sum += studentManager->studentList[i].studentsScore.chemistry;
        studentManager->studentList[i].studentsScore.sum += studentManager->studentList[i].studentsScore.biology;
    }
    for (int i = 0; i < studentManager->number; i++)
    {
        down[i] = studentManager->studentList[i].studentsScore.sum;
    }
    for (int i = 0; i < studentManager->number - 1; i++)
    {
        for (int j = 0; j < studentManager->number - i - 1; j++)
        {
            if (down[j + 1] > down[j])
            {
                double temp;
                temp = down[j];
                down[j] = down[j + 1];
                down[j + 1] = temp;
            }
        }
    }
    for (int i = 0; i < studentManager->number; i++)
    {
        for (int j = 0; j < studentManager->number; j++)
        {
            if (down[i] == studentManager->studentList[j].studentsScore.sum)
            {
                studentManager->studentList[j].studentsScore.list = i + 1;
            }
        }
    }
    cout << "请输入您想要查询的姓名：" << endl;
    string searchName;
    cin >> searchName;
    for (int i = 0; i < studentManager->number; i++)
    {
        if (searchName == studentManager->studentList[i].name)
        {
            cout << "查询成功！姓名：" << studentManager->studentList[i].name << endl;
            cout << "总分：" << down[studentManager->studentList[i].studentsScore.list - 1] << endl;
            cout << "排名：" << studentManager->studentList[i].studentsScore.list << endl;
            cout << "语文：" << studentManager->studentList[i].studentsScore.chinese << endl;
            cout << "数学：" << studentManager->studentList[i].studentsScore.math << endl;
            cout << "英语：" << studentManager->studentList[i].studentsScore.english << endl;
            cout << "物理：" << studentManager->studentList[i].studentsScore.physics << endl;
            cout << "化学：" << studentManager->studentList[i].studentsScore.chemistry << endl;
            cout << "生物：" << studentManager->studentList[i].studentsScore.biology << endl;
            break;
        }
    }
    cout << "程序结束！返回主页面中......." << endl;
}

// 10按照分数段排名
void greats(manager *studentManager)
{
    int arr[6][5] = {(0, 0)};
    cout << "======现在将每个科目进行分数段排名======" << endl;
    for (int i = 0; i < studentManager->number; i++)
    {
        if (studentManager->studentList[i].studentsScore.chinese <= 100 && studentManager->studentList[i].studentsScore.chinese >= 90)
        {
            arr[0][0]++;
        }
        if (studentManager->studentList[i].studentsScore.chinese < 90 && studentManager->studentList[i].studentsScore.chinese >= 80)
        {
            arr[0][1]++;
        }
        if (studentManager->studentList[i].studentsScore.chinese < 80 && studentManager->studentList[i].studentsScore.chinese >= 70)
        {
            arr[0][2]++;
        }
        if (studentManager->studentList[i].studentsScore.chinese < 70 && studentManager->studentList[i].studentsScore.chinese >= 60)
        {
            arr[0][3]++;
        }
        if (studentManager->studentList[i].studentsScore.chinese < 60)
        {
            arr[0][4]++;
        }
    }
    cout << "语文优秀人数:" << arr[0][0] << "所占比例：" << double(arr[0][0]) / double(studentManager->number) << endl;
    cout << "语文良好人数:" << arr[0][1] << "所占比例：" << double(arr[0][1]) / double(studentManager->number) << endl;
    cout << "语文中等人数:" << arr[0][2] << "所占比例：" << double(arr[0][2]) / double(studentManager->number) << endl;
    cout << "语文合格人数:" << arr[0][3] << "所占比例：" << double(arr[0][3]) / double(studentManager->number) << endl;
    cout << "语文不合格人数:" << arr[0][4] << "所占比例：" << double(arr[0][4]) / double(studentManager->number) << endl;
    cout << "=============================" << endl;
    for (int i = 0; i < studentManager->number; i++)
    {
        if (studentManager->studentList[i].studentsScore.chinese <= 100 && studentManager->studentList[i].studentsScore.chinese >= 90)
        {
            arr[1][0]++;
        }
        if (studentManager->studentList[i].studentsScore.chinese < 90 && studentManager->studentList[i].studentsScore.chinese >= 80)
        {
            arr[1][1]++;
        }
        if (studentManager->studentList[i].studentsScore.chinese < 80 && studentManager->studentList[i].studentsScore.chinese >= 70)
        {
            arr[1][2]++;
        }
        if (studentManager->studentList[i].studentsScore.chinese < 70 && studentManager->studentList[i].studentsScore.chinese >= 60)
        {
            arr[1][3]++;
        }
        if (studentManager->studentList[i].studentsScore.chinese < 60)
        {
            arr[1][4]++;
        }
    }
    cout << "数学优秀人数:" << arr[1][0] << "所占比例：" << double(arr[1][0]) / double(studentManager->number) << endl;
    cout << "数学良好人数:" << arr[1][1] << "所占比例：" << double(arr[1][1]) / double(studentManager->number) << endl;
    cout << "数学中等人数:" << arr[1][2] << "所占比例：" << double(arr[1][2]) / double(studentManager->number) << endl;
    cout << "数学合格人数:" << arr[1][3] << "所占比例：" << double(arr[1][3]) / double(studentManager->number) << endl;
    cout << "数学不合格人数:" << arr[1][4] << "所占比例：" << double(arr[1][4]) / double(studentManager->number) << endl;
    cout << "=============================" << endl;
    for (int i = 0; i < studentManager->number; i++)
    {
        if (studentManager->studentList[i].studentsScore.chinese <= 100 && studentManager->studentList[i].studentsScore.chinese >= 90)
        {
            arr[2][0]++;
        }
        if (studentManager->studentList[i].studentsScore.chinese < 90 && studentManager->studentList[i].studentsScore.chinese >= 80)
        {
            arr[2][1]++;
        }
        if (studentManager->studentList[i].studentsScore.chinese < 80 && studentManager->studentList[i].studentsScore.chinese >= 70)
        {
            arr[2][2]++;
        }
        if (studentManager->studentList[i].studentsScore.chinese < 70 && studentManager->studentList[i].studentsScore.chinese >= 60)
        {
            arr[2][3]++;
        }
        if (studentManager->studentList[i].studentsScore.chinese < 60)
        {
            arr[2][4]++;
        }
    }
    cout << "英语优秀人数:" << arr[2][0] << "所占比例：" << double(arr[2][0]) / double(studentManager->number) << endl;
    cout << "英语良好人数:" << arr[2][1] << "所占比例：" << double(arr[2][1]) / double(studentManager->number) << endl;
    cout << "英语中等人数:" << arr[2][2] << "所占比例：" << double(arr[2][2]) / double(studentManager->number) << endl;
    cout << "英语合格人数:" << arr[2][3] << "所占比例：" << double(arr[2][3]) / double(studentManager->number) << endl;
    cout << "英语不合格人数:" << arr[2][4] << "所占比例：" << double(arr[2][4]) / double(studentManager->number) << endl;
    cout << "=============================" << endl;
    for (int i = 0; i < studentManager->number; i++)
    {
        if (studentManager->studentList[i].studentsScore.chinese <= 100 && studentManager->studentList[i].studentsScore.chinese >= 90)
        {
            arr[3][0]++;
        }
        if (studentManager->studentList[i].studentsScore.chinese < 90 && studentManager->studentList[i].studentsScore.chinese >= 80)
        {
            arr[3][1]++;
        }
        if (studentManager->studentList[i].studentsScore.chinese < 80 && studentManager->studentList[i].studentsScore.chinese >= 70)
        {
            arr[3][2]++;
        }
        if (studentManager->studentList[i].studentsScore.chinese < 70 && studentManager->studentList[i].studentsScore.chinese >= 60)
        {
            arr[3][3]++;
        }
        if (studentManager->studentList[i].studentsScore.chinese < 60)
        {
            arr[3][4]++;
        }
    }
    cout << "物理优秀人数:" << arr[3][0] << "所占比例：" << double(arr[3][0]) / double(studentManager->number) << endl;
    cout << "物理良好人数:" << arr[3][1] << "所占比例：" << double(arr[3][1]) / double(studentManager->number) << endl;
    cout << "物理中等人数:" << arr[3][2] << "所占比例：" << double(arr[3][2]) / double(studentManager->number) << endl;
    cout << "物理合格人数:" << arr[3][3] << "所占比例：" << double(arr[3][3]) / double(studentManager->number) << endl;
    cout << "物理不合格人数:" << arr[3][4] << "所占比例：" << double(arr[3][4]) / double(studentManager->number) << endl;
    cout << "=============================" << endl;
    for (int i = 0; i < studentManager->number; i++)
    {
        if (studentManager->studentList[i].studentsScore.chinese <= 100 && studentManager->studentList[i].studentsScore.chinese >= 90)
        {
            arr[4][0]++;
        }
        if (studentManager->studentList[i].studentsScore.chinese < 90 && studentManager->studentList[i].studentsScore.chinese >= 80)
        {
            arr[4][1]++;
        }
        if (studentManager->studentList[i].studentsScore.chinese < 80 && studentManager->studentList[i].studentsScore.chinese >= 70)
        {
            arr[4][2]++;
        }
        if (studentManager->studentList[i].studentsScore.chinese < 70 && studentManager->studentList[i].studentsScore.chinese >= 60)
        {
            arr[4][3]++;
        }
        if (studentManager->studentList[i].studentsScore.chinese < 60)
        {
            arr[4][4]++;
        }
    }
    cout << "化学优秀人数:" << arr[4][0] << "所占比例：" << double(arr[4][0]) / double(studentManager->number) << endl;
    cout << "化学良好人数:" << arr[4][1] << "所占比例：" << double(arr[4][1]) / double(studentManager->number) << endl;
    cout << "化学中等人数:" << arr[4][2] << "所占比例：" << double(arr[4][2]) / double(studentManager->number) << endl;
    cout << "化学合格人数:" << arr[4][3] << "所占比例：" << double(arr[4][3]) / double(studentManager->number) << endl;
    cout << "化学不合格人数:" << arr[4][4] << "所占比例：" << double(arr[4][4]) / double(studentManager->number) << endl;
    cout << "=============================" << endl;
    for (int i = 0; i < studentManager->number; i++)
    {
        if (studentManager->studentList[i].studentsScore.chinese <= 100 && studentManager->studentList[i].studentsScore.chinese >= 90)
        {
            arr[5][0]++;
        }
        if (studentManager->studentList[i].studentsScore.chinese < 90 && studentManager->studentList[i].studentsScore.chinese >= 80)
        {
            arr[5][1]++;
        }
        if (studentManager->studentList[i].studentsScore.chinese < 80 && studentManager->studentList[i].studentsScore.chinese >= 70)
        {
            arr[5][2]++;
        }
        if (studentManager->studentList[i].studentsScore.chinese < 70 && studentManager->studentList[i].studentsScore.chinese >= 60)
        {
            arr[5][3]++;
        }
        if (studentManager->studentList[i].studentsScore.chinese < 60)
        {
            arr[5][4]++;
        }
    }
    cout << "生物优秀人数:" << arr[5][0] << "所占比例：" << double(arr[5][0]) / double(studentManager->number) << endl;
    cout << "生物良好人数:" << arr[5][1] << "所占比例：" << double(arr[5][1]) / double(studentManager->number) << endl;
    cout << "生物中等人数:" << arr[5][2] << "所占比例：" << double(arr[5][2]) / double(studentManager->number) << endl;
    cout << "生物合格人数:" << arr[5][3] << "所占比例：" << double(arr[5][3]) / double(studentManager->number) << endl;
    cout << "生物不合格人数:" << arr[5][4] << "所占比例：" << double(arr[5][4]) / double(studentManager->number) << endl;
    cout << "=============================" << endl;
}

// 11输出每个学生的学号、姓名、各科考试成绩，以及每门课程的总分和平均分
void cxkBasketBallTeam(manager *studentManager)
{
    cout << "输出每个学生的信息：" << endl;
    for (int i = 0; i < studentManager->number; i++)
    {
        cout << "学号：" << studentManager->studentList[i].id << endl;
        cout << "姓名：" << studentManager->studentList[i].name << endl;
        cout << "语文：" << studentManager->studentList[i].studentsScore.chinese << endl;
        cout << "数学：" << studentManager->studentList[i].studentsScore.math << endl;
        cout << "英语：" << studentManager->studentList[i].studentsScore.english << endl;
        cout << "物理：" << studentManager->studentList[i].studentsScore.physics << endl;
        cout << "化学：" << studentManager->studentList[i].studentsScore.chemistry << endl;
        cout << "生物：" << studentManager->studentList[i].studentsScore.biology << endl;
        cout << "=============================" << endl;
    }
    AllScore(studentManager);
}

// 主函数入口+
int main()
{
    int chose;
    manager studentManager;    // 定义学生管理结构体
    studentManager.number = 0; // 初始化数组值

    // 界面开始循环
    while (true)
    {
        main_Menu();
        cin >> chose;
        // 判断是否输入正确
        // 输入正确后的不同情况
        switch (chose)
        {
        case 1:
            signIn(&studentManager);
            break;
        case 2:
            AllScore(&studentManager);
            break;
        case 3:
            studentAllScore(&studentManager);
            break;
        case 4:
            ScoreDown(&studentManager);
            break;
        case 5:
            ScoreUp(&studentManager);
            break;
        case 6:
            IdUp(&studentManager);
            break;
        case 7:
            dictionary(&studentManager);
            break;
        case 8:
            IdSearch(&studentManager);
            break;
        case 9:
            NameSearch(&studentManager);
            break;
        case 10:
            greats(&studentManager);
            break;
        case 11:
            cxkBasketBallTeam(&studentManager);
            break;
        case 0:
            cout << "成功退出程序，欢迎下次使用！！！" << endl;
            system("pause");
            return 0;
        default:
            break;
        }
    }
}