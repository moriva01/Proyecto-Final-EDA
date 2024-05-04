#ifndef ENUMS_H
#define ENUMS_H

/**
 * @brief Enumeración de los tipos de estado de una tarea
 */
enum StatusType
{
    OPEN, // Tarea abierta
    IN_DEV, // Tarea en desarrollo
    IN_CODE_REVIEW, // Tarea en revisión de código
    READY_TO_MERGE, // Tarea lista para ser fusionada
    CLOSED // Tarea cerrada
};

/**
 * @brief Enumeración de los tipos de roles de un usuario
*/
enum RoleType
{
    ADMIN, // Administrador
    DEVELOPER, // Desarrollador
    TESTER // Tester
};

/**
 * @brief Enumeración de los tipos de reacciones a un comentario
*/
enum ReactionType
{
    LIKE, // Me gusta
    HEART, // Corazón
    LAUGH, // Risa
    WOW, // Sorpresa
    SAD, // Triste
    ANGRY, // Enojado
    NONE // Ninguno
};


/**
 * @brief Enumeración de los tipos de prioridad de una tarea
*/
enum PriorityType
{
    LOW, // Baja
    MEDIUM, // Media
    HIGH // Alta
};

std::string statusToString(const StatusType &status) {
    switch (status) {
        case OPEN:
            return "OPEN";
        case IN_DEV:
            return "IN_DEV";
        case IN_CODE_REVIEW:
            return "IN_CODE_REVIEW";
        case READY_TO_MERGE:
            return "READY_TO_MERGE";
        case CLOSED:
            return "CLOSED";
        default:
            return "UNKNOWN";
    }
}

std::string roleToString(const RoleType &role) {
    switch (role) {
        case ADMIN:
            return "ADMIN";
        case DEVELOPER:
            return "DEVELOPER";
        case TESTER:
            return "TESTER";
        default:
            return "UNKNOWN";
    }
}

std::string reactionToString(const ReactionType &reaction) {
    switch (reaction) {
        case LIKE:
            return "LIKE";
        case HEART:
            return "HEART";
        case LAUGH:
            return "LAUGH";
        case WOW:
            return "WOW";
        case SAD:
            return "SAD";
        case ANGRY:
            return "ANGRY";
        case NONE:
            return "NONE";
        default:
            return "UNKNOWN";
    }
}

std::string priorityToString(const PriorityType &priority) {
    switch (priority) {
        case LOW:
            return "LOW";
        case MEDIUM:
            return "MEDIUM";
        case HIGH:
            return "HIGH";
        default:
            return "UNKNOWN";
    }
}

#endif // ENUMS_H
