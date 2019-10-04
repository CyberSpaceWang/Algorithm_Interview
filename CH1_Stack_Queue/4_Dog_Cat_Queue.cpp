/*
2019-10.3
CH1 队列--猫狗队列
测试用例：
11
add cat 1
add dog 2
pollAll
isEmpty
add cat 5
isDogEmpty
pollCat
add dog 10
add cat 199
pollDog
pollAll

结果：
cat 1
dog 2
yes
yes
cat 5
dog 10
cat 199 
*/

#include <iostream>
#include <cstdio>
#include <queue>
#include <string>
using namespace std;

struct Pet
{
	string pet_name;
	int count, x;         // count表示当前动物在总队列数中的排名,num为该动物的编号
	Pet(int cnt, int xx, string pet):count(cnt), x(xx), pet_name(pet) {}        
};


void Pop1(queue<Pet> &pet)       // 删除队列的一个元素
{
	Pet animal = pet.front();
	pet.pop();
	cout << animal.pet_name << " " << animal.x << endl;
}

void Pop_all(queue<Pet> &pet)    // 删除队列中所有元素
{
	while (!pet.empty())
	{
		Pet animal = pet.front();
		pet.pop();
		cout << animal.pet_name << " " << animal.x << endl;
	}
}

void is_empty_queue(queue<Pet> pet)
{
	if (pet.empty())
		cout << "yes" << endl;
	else
		cout << "no" << endl;
}

int main()
{
	// freopen("in.txt", "r", stdin);
	int step, total = 0;
	cin >> step;
	queue<Pet> Dog, Cat;
	for (int i = 0; i < step; i++)
	{
		string s;
		cin >> s;
		if (s == "add")
		{
			int x;    // 猫狗的编号
			string pet_name;       // cat or dog
			cin >> pet_name >> x;
			if (pet_name == "dog")
				Dog.push(Pet(total++, x, "dog"));
			else
				Cat.push(Pet(total++, x, "cat"));
		}
		else if (s == "pollAll")
		{
			while(!Cat.empty() || !Dog.empty())       // 只要有一个队列非空就必须执行
			{
				if (!Cat.empty() && !Dog.empty())
				{
					Pet cat = Cat.front();
					Pet dog = Dog.front();
					if (cat.count < dog.count)
						Pop1(Cat);
					else
						Pop1(Dog);
				}
				else if (!Cat.empty())     // Cat非空,Dog空
					Pop1(Cat);
				else
					Pop1(Dog);
			}
		}
		else if (s == "pollDog")          // 注意何时全部弹出,何时弹出一个元素
			Pop_all(Dog);
		else if (s == "pollCat")
			Pop_all(Cat);
		else if (s == "isEmpty")
		{
			if (Dog.empty() && Cat.empty())
				cout << "yes" << endl;
			else
				cout << "no" << endl;
		}
		else if (s == "isDogEmpty")
			is_empty_queue(Dog);	
		else
			is_empty_queue(Cat);
	}
	return 0;
}
