#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

struct Assignee
{
	string id, name, email, phone;
};

struct Task
{
	string id, name, assigneeId, status;
};

struct ChecklistItem
{
	string taskId, description;
	bool isCompleted;
};


vector<Assignee> assignees;
vector<Task> tasks;
vector<ChecklistItem> checklistItems;


void addAssignee()
{
	Assignee a;
	cout <<"Enter Assignee ID: ";
	cin >> a.id;
	cout <<"Enter Assignee Name: ";
	cin.ignore();
	getline(cin, a.name);
	cout <<"Enter Assignee Email: ";
	cin >>a.email;
	cout <<"Enter Assignee Phone: ";
	cin >>a.phone;
	assignees.push_back(a);
	cout <<"Assignee Added Successfully."<< endl;
}

void addTask()
{
	Task t;
	cout <<"Enter Task ID: ";
	cin >> t.id;
	cout <<"Enter Task Name: ";
	cin.ignore();
	getline(cin, t.name);
	cout <<"Enter Assignee ID: ";
	cin >>t.assigneeId;
	cout <<"Enter Task Status (Pending/In Progress/Completed): ";
	cin >>t.status;
	tasks.push_back(t);
	cout <<"Task Added Successfully." <<endl;
}

void addChecklistItem()
{
	ChecklistItem c;
	cout <<"Enter Task ID: ";
	cin >>c.taskId;
	cout <<"Enter Checklist Description: ";
	cin.ignore();
	getline(cin, c.description);
	c.isCompleted = false;
	checklistItems.push_back(c);
	cout <<"Checklist Item Added Successfully." <<endl;
}

void markChecklistCompleted()
{
	string taskId, desc;
	cout <<"Enter Task ID: ";
	cin >>taskId;
	cout <<"Enter Checklist Description: ";
	cin.ignore();
	getline(cin, desc);

	bool found = false;
	for (int i=0; i < checklistItems.size(); i++)
	{
		if (checklistItems[i].taskId == taskId && checklistItems[i].description == desc)
		{
			checklistItems[i].isCompleted = true;
			cout <<"Checklist Item Marked as Completed." <<endl;
			found = true;
			break;
		}
	}
	if (!found)
	{
		cout <<"Checklist Item Not Found." <<endl;
	}
}

void displayAssignees()
{
	for (int i=0; i < assignees.size(); i++)
	{
		cout <<"ID: " <<assignees[i].id <<", Name: " <<assignees[i].name
		<<", Email: "<< assignees[i].email <<", Phone: " <<assignees[i].phone <<endl;
	}
}

void displayTasks()
{
	for (int i=0; i < tasks.size(); i++)
	{
		cout <<"Task ID: " <<tasks[i].id <<", Name: " <<tasks[i].name
		<<", Assignee ID: " <<tasks[i].assigneeId <<", Status: " <<tasks[i].status <<endl;
	}
}

void generateReport()
{
	for (int i=0; i < assignees.size(); i++)
	{
		ofstream file(assignees[i].id + "_report.txt");
		file <<"Assignee ID: " <<assignees[i].id <<endl;
		file <<"Name: " <<assignees[i].name <<endl;
		file <<"Email: " <<assignees[i].email <<endl;
		file <<"Phone: " <<assignees[i].phone <<endl;
		file <<endl <<"Tasks:" <<endl;
		for (int j=0; j < tasks.size(); j++)
		{
			if (tasks[j].assigneeId == assignees[i].id)
			{
				file <<"- Task] ID: " <<tasks[j].id <<", Name: " <<tasks[j].name
				<<", Status: " <<tasks[j].status <<endl;
				file <<"  Checklist Items:" <<endl;
				for (int k=0; k < checklistItems.size(); k++)
				{
					if (checklistItems[k].taskId == tasks[j].id)
					{
						file <<"    - " <<checklistItems[k].description
						<<" [" <<(checklistItems[k].isCompleted ? "Completed" : "Pending") << "]" <<endl;
					}
				}
			}
		}
		file.close();
		cout <<"Report Generated for Assignee: " <<assignees[i].name <<endl;
	}
}

void menu()
{
	int choice;
	do {

		cout <<endl;
		cout <<"===========================================" << endl;
		cout <<"      Welcome to Task Management System    " << endl;
		cout <<"===========================================" << endl;

		cout <<"1. Add Assignee" <<endl;
		cout <<"2. Add Task" <<endl;
		cout <<"3. Add Checklist Item" <<endl;
		cout <<"4. Mark Checklist Item Completed" <<endl;
		cout <<"5. View Assignees" <<endl;
		cout <<"6. View Tasks" << endl;
		cout <<"7. Generate Reports" <<endl;
		cout <<"8. Exit" <<endl;
		cout <<"Enter your choice: ";
		cin >>choice;

		if (choice == 1)
		{
			addAssignee();
		}
		else if (choice == 2)
		{
			addTask();
		}
		else if (choice == 3)
		{
			addChecklistItem();
		}
		else if (choice == 4)
		{
			markChecklistCompleted();
		}
		else if (choice == 5)
		{
			displayAssignees();
		}
		else if (choice == 6)
		{
			displayTasks();
		}
		else if (choice == 7)
		{
			generateReport();
		}
			else if (choice == 8)
		{
			cout <<"Exiting Program." <<endl;
		} else
		{
			cout <<"Invalid Choice! Try Again." <<endl;
		}
	} while (choice != 8);
}


int main()
{
	menu();
	return 0;
}
