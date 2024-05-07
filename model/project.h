#ifndef PROJECT_H
#define PROJECT_H

#include "./board.h"

class Project
{
private:
    int id;
    User *owner;
    string title;
    string description;
    Board board;
    std::set<User *> members;

public:
    Project() : owner(nullptr), title("") {
        id = rand() % 1000 + 1;
    }
    Project(string title) : owner(nullptr), title(title) {
        id = rand() % 1000 + 1;
    }
    Project(User *owner, string title) : owner(owner), title(title) {
        id = rand() % 1000 + 1;
    }

    int getId() const { return id; }
    User *getOwner() const { return owner; }
    string getTitle() const { return title; }
    string getDescription() const { return description; }
    Board getBoard() const { return board; }
    std::set<User *> getMembers() const { return members; }

    void setId(int id) { this->id = id; }
    void setOwner(User *owner) { this->owner = owner; }
    void setTitle(string title) { this->title = title; }
    void setDescription(string description) { this->description = description; }
    void setBoard(Board board) { this->board = board; }
    void setMembers(std::set<User *> members) { this->members = members; }
    void addMember(User *member) { members.insert(member); }

    ~Project() {}

    friend ostream &operator<<(ostream &os, const Project &project)
    {
        os << project.title;
        return os;
    }

    bool operator<(const Project &project) const
    {
        return id < project.getId();
    }

    bool operator==(const Project &project) const
    {
        return id == project.getId();
    }
};

#endif // PROJECT_H