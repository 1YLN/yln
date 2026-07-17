#include<iostream>
using namespace std;
#include<string>
#define max 1000
void showMenu() {
	cout << "**********************" << endl;
	cout << "*****1.添加联系人*****" << endl;
	cout << "*****2.显示联系人*****" << endl;
	cout << "*****3.删除联系人*****" << endl;
	cout << "*****4.查找联系人*****" << endl;
	cout << "*****5.修改联系人*****" << endl;
	cout << "*****6.清空联系人*****" << endl;
	cout << "*****0.退出通讯录*****" << endl;
	cout << "**********************" << endl;
}
//联系人
struct Person {
	string name;
	int sex;
	int age;
	int phone;
	string addr;
};
//通讯录
struct Addressbooks {
	Person arr[max];
	int size;
};
//添加
void addPerson(Addressbooks* abs) {
	if (abs->size == 1000) {
		cout << "已满" << endl;
	}
	else
	{
		cout << "请输入姓名" << endl;
		cin >> abs->arr[abs->size].name;
		cout << "请输入性别\n" << "1--男\n" << "2--女" << endl;
		int sex = 0;
		while (1) {
			cin >> sex;
			if (sex == 1 || sex == 2) {
				abs->arr[abs->size].sex = sex;
				break;
			}
			cout << "输入错误" << endl;
		}
		cout << "请输入年龄" << endl;
		cin >> abs->arr[abs->size].age;
		cout << "请输入电话号码" << endl;
		cin >> abs->arr[abs->size].phone;
		cout << "请输入家庭住址" << endl;
		cin >> abs->arr[abs->size].addr;
		abs->size++;
		cout << "成功" << endl;
		system("pause");
		system("cls");//清屏
	}
}
void showPerson(Addressbooks* abs) {

	if (abs->size == 0) {
		cout << "无人" << endl;
	}
	else {
		for (int i = 0; i < abs->size; i++) {
			cout << "姓名 :" << abs->arr[i].name;
			cout << "\t性别 :" << (abs->arr[i].sex == 1 ? "男" : "女");
			cout << "\t年龄 :" << abs->arr[i].age;
			cout << "\t电话号码 :" << abs->arr[i].phone;
			cout << "\t家庭住址 :" << abs->arr[i].addr << endl;
			
		}
		cout << "通讯录有" << abs->size << "人" << endl;
	}
	system("pause");
	system("cls");
}
int isExist(Addressbooks* abs, string name) {
	for (int i = 0; i < abs->size; i++) {
		if (abs->arr[i].name == name) {
			return i;
		}
	}
	return -1;
}
void deletePerson(Addressbooks* abs,string name,int j) {
	for (int i = j; i < abs->size; i++) {
		abs->arr[i] = abs->arr[i + 1];
	}
	abs->size--; 
	cout << "删除成功" << endl;
	cout << "通讯录有" << abs->size << "人" << endl;
	system("pause");
	system("cls");
}
void findPerson(Addressbooks * abs) {
	cout << "请输入查找人姓名" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if ( ret!=-1) {
		cout << "姓名 :" << abs->arr[ret].name;
		cout << "\t性别 :" << abs->arr[ret].sex ;
		cout << "\t年龄 :" << abs->arr[ret].age;
		cout << "\t电话号码 :" << abs->arr[ret].phone;
		cout << "\t家庭住址 :" << abs->arr[ret].addr << endl;
	}
	else
	{
		cout << "查无此人" << endl;
	}
	system("pause");
	system("cls");
}
void modifyPerson(Addressbooks* abs) {
	cout << "请输入修改人姓名" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1) {
		cout << "请输入姓名:" << endl;
		cin >> abs->arr[ret].name;
		cout << "请输入性别\n" << "1--男\n" << "2--女" << endl;
		int sex = 0;
		while (1) {
			cin >> sex;
			if (sex == 1 || sex == 2) {
				abs->arr[ret].sex = sex;
				break;
			}
			cout << "输入错误" << endl;
		}
		cout << "请输入年龄" << endl;
		cin >> abs->arr[ret].age;
		cout << "请输入电话号码" << endl;
		cin >> abs->arr[ret].phone;
		cout << "请输入家庭住址" << endl;
		cin >> abs->arr[ret].addr;
		cout << "修改成功" << endl;
	}
	else
	{
		cout << "查无此人" << endl;
	}
	system("pause");
	system("cls");
}
void cleanPerson(Addressbooks* abs) {
	int a = 0;
	cout << "确认请按1,退出请按2" << endl;
	while (1){
		cin >> a;
	if (a == 1) {
		abs->size = 0;
		cout << "通讯录已清空" << endl;
		system("pause");
		system("cls");
		break;
	}
	else if (a == 2) {
		cout << "退出" << endl;
		system("pause");
		system("cls");
		break;
	}
	else {
		cout << "输入错误请重新输入" << endl;
	}
	}

}
int main() {
	int select = 0;
	
	Addressbooks abs;
	abs.size = 0;
	while (1) 
	{
		showMenu();
		cin >> select;
		switch (select) {
		case 1:
			addPerson(&abs);
			break;
		case 2:
			showPerson(&abs);
			break;
		case 3:
		{
			cout << "请输入删除人姓名" << endl;
			string name;
			cin >> name;
			if (isExist(&abs, name)== -1) {
				cout << "查无此人" << endl;
				system("pause");
				system("cls");
			}
			else
			{
				deletePerson(&abs, name, isExist(&abs, name));
			}
		}
			break;
		case 4:
			findPerson(&abs);
			break;
		case 5:
			modifyPerson(&abs);
			break;
		case 6:
			cleanPerson(&abs);
			break;
		case 0:
			cout << "欢迎下次使用" << endl;
			system("pause");
			return 0;
			break;
		default:
			cout << "输入错误" << endl;
			break;
		}
	}
	system("pause");
	return 0;
}