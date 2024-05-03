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

#endif // ENUMS_H
