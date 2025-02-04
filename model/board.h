#ifndef BOARD_H
#define BOARD_H

#include "./task.h"


class Board
{
private:
    string title;
    vector<Task> tasks;
    map<PriorityType, queue<Task>> taskQueues;

public:
    Board() : title("") {}
    Board(string title) : title(title) {}

    string getTitle() const { return title; }
    vector<Task> getTasks() const { return tasks; }
    map<PriorityType, queue<Task>> getTaskQueues() const { return taskQueues; }
    set<PriorityType> getPriorities() const
    {
        set<PriorityType> priorities;
        for (auto &task : tasks)
        {
            priorities.insert(task.getPriority());
        }
        return priorities;
    }
    set<queue<Task>> getTasksQueue() const
    {
        set<queue<Task>> queues;
        for (auto &taskQueue : taskQueues)
        {
            queues.insert(taskQueue.second);
        }
        return queues;
    }

    void setTitle(string title) { this->title = title; }
    void setTasks(vector<Task> tasks) { this->tasks = tasks; }
    void setTaskQueues(map<PriorityType, queue<Task>> taskQueues) { this->taskQueues = taskQueues; }

    void addTask(Task task)
    {
        tasks.push_back(task);
        taskQueues[task.getPriority()].push(task);
    }

    void removeTask(Task task)
    {
        tasks.erase(remove(tasks.begin(), tasks.end(), task), tasks.end());
        taskQueues[task.getPriority()].pop();
    }

    void showTasks()
    {
        for (auto &task : tasks)
        {
            cout << task.getTitle() << endl;
        }
    }

    void showTaskQueues()
    {
        for (auto &taskQueue : taskQueues)
        {
            cout << "Priority: " << priorityToString(taskQueue.first) << endl;
            queue<Task> temp = taskQueue.second;
            while (!temp.empty())
            {
                cout << temp.front().getTitle() << endl;
                temp.pop();
            }
        }
    }

    ~Board()
    {
        tasks.clear();
        taskQueues.clear();
    }

    friend ostream &operator<<(ostream &os, const Board &board)
    {
        os << "Title: " << board.title << endl;
        os << "Tasks: " << endl;
        for (auto &task : board.tasks)
        {
            os << task << endl;
        }
        os << "Task Queues: " << endl;
        for (auto &taskQueue : board.taskQueues)
        {
            os << "Priority: " << priorityToString(taskQueue.first) << endl;
            queue<Task> temp = taskQueue.second;
            while (!temp.empty())
            {
                os << temp.front() << endl;
                temp.pop();
            }
        }
        return os;
    }

    bool operator<(const Board &board) const
    {
        return title < board.title;
    }

    bool operator==(const Board &board) const
    {
        return title == board.title;
    }
};

#endif // BOARD_H