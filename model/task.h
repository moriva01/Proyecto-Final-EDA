#ifndef TASK_H
#define TASK_H

#include "./note.h"

/**
 * @brief Estructura interna de una fecha
 */
struct Date
{
    int day;
    int month;
    int year;
    Date() : day(1), month(1), year(2000) {}
    Date(int day, int month, int year) : day(day), month(month), year(year) {}
};

class Task
{
private:
    string title;
    string description;
    Date dueDate;
    StatusType status;
    PriorityType priority;
    User *assignee;
    User *reporter;
    vector<User *> watchers;
    stack<Note> notes;
    map<ReactionType, int> reactions;

public:
    /**
     * @brief Constructor vacío de la clase Task
     */
    Task() : title(""), description(""), dueDate(Date()), status(OPEN), priority(LOW), assignee(nullptr), reporter(nullptr) {
        reactions[LIKE] = 0;
        reactions[LAUGH] = 0;
        reactions[WOW] = 0;
        reactions[SAD] = 0;
        reactions[ANGRY] = 0;
        reactions[NONE] = 0;
    }
    /**
     * @brief Constructor de la clase Task
     */
    Task(string title, string description, User *reporter, Date dueDate) : title(title), description(description), dueDate(dueDate), status(OPEN), priority(LOW), assignee(nullptr), reporter(reporter) {
        reactions[LIKE] = 0;
        reactions[LAUGH] = 0;
        reactions[WOW] = 0;
        reactions[SAD] = 0;
        reactions[ANGRY] = 0;
        reactions[NONE] = 0;
    }

    // Getters
    string getTitle() const { return title; }
    string getDescription() const { return description; }
    Date getDueDate() const { return dueDate; }
    StatusType getStatus() const { return status; }
    PriorityType getPriority() const { return priority; }
    User *getAssignee() const { return assignee; }
    User *getReporter() const { return reporter; }
    vector<User *> getWatchers() const { return watchers; }
    stack<Note> getNotes() const { return notes; }
    map<ReactionType, int> getReactions() const { return reactions; }
    set<ReactionType> getReactionsKeys() const
    {
        set<ReactionType> reactionSet;
        for (auto reaction : reactions)
        {
            reactionSet.insert(reaction.first);
        }
        return reactionSet;
    }

    set<int> getReactionsValues() const
    {
        set<int> reactionValues;
        for (auto reaction : reactions)
        {
            reactionValues.insert(reaction.second);
        }
        return reactionValues;
    }

    // Setters

    void setTitle(string title) { this->title = title; }
    void setDescription(string description) { this->description = description; }
    void setDueDate(Date dueDate) { this->dueDate = dueDate; }
    void setStatus(StatusType status) { this->status = status; }
    void setPriority(PriorityType priority) { this->priority = priority; }
    void setAssignee(User *assignee) { this->assignee = assignee; }
    void setReporter(User *reporter) { this->reporter = reporter; }

    // Métodos

    /**
     * @brief Método para añadir un usuario a la lista de observadores de la tarea
     * @param watcher Usuario a añadir
     * @return void
     */
    void addWatcher(User *watcher)
    {
        if (find(watchers.begin(), watchers.end(), watcher) == watchers.end())
        {
            watchers.push_back(watcher);
            return;
        }

        if (watcher == reporter)
        {
            cout << "El usuario ya es el reportador de la tarea" << endl;
            return;
        }

        if (watcher == assignee)
        {
            cout << "El usuario ya es el asignado de la tarea" << endl;
            return;
        }
        cout << "El usuario ya es espectador de la tarea" << endl;
    }
    /**
     * @brief Método para eliminar un usuario de la lista de observadores de la tarea
     * @param watcher Usuario a eliminar
     * @return void
     */
    void removeWatcher(User *watcher)
    {
        if (watchers.empty())
        {
            cout << "No hay espectadores que eliminar" << endl;
            return;
        }

        if (find(watchers.begin(), watchers.end(), watcher) == watchers.end())
        {
            cout << "El usuario no es espectador de la tarea" << endl;
            return;
        }
        watchers.erase(remove(watchers.begin(), watchers.end(), watcher), watchers.end());
    }

    /**
     * @brief Método para añadir una nota a la tarea
     * @param author Usuario que añade la nota
     * @param title Título de la nota
     * @param content Contenido de la nota
     * @return void
     */
    void addNote(User *author, string title, string content)
    {
        if (find(watchers.begin(), watchers.end(), author) != watchers.end())
        {
            cout << "El usuario no puede añadir notas a la tarea" << endl;
            return;
        }

        if (title.empty() || content.empty())
        {
            cout << "El título y el contenido de la nota no pueden estar vacíos" << endl;
            return;
        }

        if (title.size() > 50 || content.size() > 500)
        {
            cout << "El título no puede tener más de 50 caracteres y el contenido no puede tener más de 500 caracteres" << endl;
            return;
        }

        notes.push(Note(author, title, content));
    }

    /**
     * @brief Método para eliminar la última nota añadida a la tarea
     * @return void
     * @pre La pila de notas no está vacía
     */
    void removeNote()
    {
        if (!notes.empty())
        {
            notes.pop();
            return;
        }
        cout << "No hay notas que eliminar" << endl;
    }

    void addReaction(ReactionType reaction)
    {
        reactions[reaction]++;
    }

    void removeReaction(ReactionType reaction)
    {
        if (reactions[reaction] == 0)
        {
            cout << "No hay reacciones que eliminar" << endl;
            return;
        }
        reactions[reaction]--;
    }

    void showNotes()
    {
        if (notes.empty())
        {
            cout << "No hay notas que mostrar" << endl;
            return;
        }
        stack<Note> temp = notes;
        while (!temp.empty())
        {
            cout << temp.top().getTitle() << ": " << temp.top().getContent() << endl;
            temp.pop();
        }
    }

    ~Task()
    {
        while (!notes.empty())
        {
            notes.pop();
        }
    }

    friend ostream &operator<<(ostream &os, const Task &task)
    {
        os << "Title: " << task.getTitle() << endl;
        os << "Description: " << task.getDescription() << endl;
        os << "Due Date: " << task.getDueDate().day << "/" << task.getDueDate().month << "/" << task.getDueDate().year << endl;
        os << "Status: " << statusToString(task.getStatus()) << endl;
        os << "Priority: " << priorityToString(task.getPriority()) << endl;
        os << "Assignee: " << task.getAssignee() << endl;
        os << "Reporter: " << task.getReporter() << endl;
        os << "Watchers: ";
        for (User *watcher : task.getWatchers())
        {
            os << watcher << " ";
        }
        os << endl;
        os << "Notes: ";
        stack<Note> temp = task.getNotes();
        while (!temp.empty())
        {
            os << temp.top().getTitle() << ": " << temp.top().getContent() << endl;
            temp.pop();
        }
        os << "Reactions: ";
        for (auto reaction : task.getReactions())
        {
            os << reaction.first << ": " << reaction.second << " ";
        }
        os << endl;
        return os;
    }

    bool operator<(const Task &task) const
    {
        return this->dueDate.year < task.getDueDate().year;
    }

    bool operator==(const Task &task) const
    {
        return this->title == task.getTitle();
    }
};

#endif // TASK_H