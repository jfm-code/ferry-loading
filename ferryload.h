#include <stdio.h>
#include <stdlib.h>

enum status { FAILURE, SUCCESS };
typedef enum status Status;

enum boolean { FALSE, TRUE };
typedef enum boolean Boolean;

#define DEBUG 1
#define CRITICAL 1
#define LOG_DEBUG if(DEBUG)printf
#define LOG_CRITICAL if(CRITICAL)printf

typedef void* QUEUE;

QUEUE queue_init_default();
Status queue_enqueue(QUEUE* hQueue, int value);
Status queue_dequeue(QUEUE* hQueue);
Boolean queue_is_empty(QUEUE* hQueue);
void queue_destroy(QUEUE** hQueue);
void clear_keyboard_buffer(void);
