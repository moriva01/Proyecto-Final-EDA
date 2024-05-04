#ifndef PROJECT_H
#define PROJECT_H

#include "./board.h"

class Project
{
private:
    User *owner;
    string title;
    Board board;
    set<User *> members;

public:
    Project() : owner(nullptr), title("") {}
    Project(string title) : owner(nullptr), title(title) {}
    Project(User *owner, string title) : owner(owner), title(title) {}

    User *getOwner() const { return owner; }
    string getTitle() const { return title; }
    Board getBoard() const { return board; }
    set<User *> getMembers() const { return members; }

    void setOwner(User *owner) { this->owner = owner; }
    void setTitle(string title) { this->title = title; }
    void setBoard(Board board) { this->board = board; }
    void setMembers(set<User *> members) { this->members = members; }

    ~Project() {}

    friend ostream &operator<<(ostream &os, const Project &project)
    {
        os << project.title;
        return os;
    }

    bool operator<(const Project &project) const
    {
        return title < project.title;
    }

    bool operator==(const Project &project) const
    {
        return title == project.title;
    }
};

#endif // PROJECT_H