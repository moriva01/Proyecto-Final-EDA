#include "../model/user.h"
#include <deque>

deque<User> users;
set<Project> projects;
set<string> projectsTitles;
set<User *> projectsOwners;
set<StatusType> projectStates;
set<string> projectsDescriptions;

bool isDateValid(string date)
{
    if (date.size() != 10)
        return false;
    if (date[2] != '-' || date[5] != '-')
        return false;
    if (stoi(date.substr(0, 2)) > 31 || stoi(date.substr(0, 2)) < 1)
        return false;
    if (stoi(date.substr(3, 2)) > 12 || stoi(date.substr(3, 2)) < 1)
        return false;
    if (stoi(date.substr(6, 4)) < 1900 || stoi(date.substr(6, 4)) > 2053)
        return false;
    return true;
}

void createProject(User &user)
{
    Project newProject;
    int id = rand() % 1000 + 1;
    string title;
    string description;
    newProject.setId(id);
    for (auto &project : projects)
    {
        if (project.getId() == id)
        {
            cout << "Project with this id already exists!" << endl;
            return;
        }
    }
    newProject.setOwner(&user);
    cout << "Enter project title: ";
    cin >> title;
    newProject.setTitle(title);
    newProject.setDescription(description);
    newProject.addMember(&user);
    user.addProject(&newProject);
    projects.insert(newProject);
    projectsTitles.insert(title);
    projectsOwners.insert(&user);
    projectsDescriptions.insert(description);
    projectStates.insert(newProject.getBoard().getState());
    cout << "Project created successfully!" << endl;
}

void getProjectInfo(Project &project)
{
    if (projects.find(project) == projects.end())
    {
        cout << "Project not found!" << endl;
        return;
    }
    cout << "Project title: " << project.getTitle() << endl;
    cout << "Project description: " << project.getDescription() << endl;
    cout << "Project owner: " << project.getOwner()->getUsername() << endl;
    cout << "Project state: " << project.getBoard().getStateString() << endl;
    cout << endl;
}
