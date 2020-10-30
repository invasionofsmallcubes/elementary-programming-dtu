#include <stdlib.h>

struct CourseStruct {
    char *name;
    int   code;
    int   maxStudents;
};
typedef struct CourseStruct Course;

int main(void) {
    Course* c = malloc(sizeof(Course));
    c->name        = "Something";
    c->code        = 1234;
    c->maxStudents = 4;
}
