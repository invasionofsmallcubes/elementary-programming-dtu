// POINT OF ATTENTION
// THIS CODE RUN ON XCODE, IT DOESN'T ON PURE CLANG
// SHOULD GO IN DEBUG BUT NO TIME

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define NAME_LENGTH 30

typedef struct {
    char *name;
    int   code;
    int   maxStudents;
} Coursed;

typedef struct {
    char * name;
    char **students;
    int    size;
} Course;

Course *buildCourse(char *name, int size) {
    Course *c = malloc(sizeof(Course));
    c->name   = malloc(NAME_LENGTH * sizeof(char));
    strncpy(c->name, name, NAME_LENGTH);
    c->size     = size;
    c->students = malloc(c->size * sizeof(char));
    for (int i = 0; i < c->size; i++) {
        c->students[i] = malloc(NAME_LENGTH * sizeof(char));
    }
    return c;
}

void cleanCourse(Course *c) {
    free(c->name);
    for (int i = 0; i < c->size; i++) {
        free(c->students[i]);
    }
    free(c->students);
    free(c);
}

Course *createCourse() {
    printf("\nTell me the name of the course\n");
    char name[NAME_LENGTH];
    scanf("%s", name);
    printf("How many students?\n");
    int size;
    scanf("%d", &size);
    Course *course = buildCourse(name, size);
    printf("Students names:\n");
    for (int i = 0; i < size; i++) {
        char student[NAME_LENGTH];
        printf("Name %d: ", i);
        scanf("%s", student);
        strncpy(course->students[i], student, NAME_LENGTH);
    }
    return course;
}

void printCourse(Course *c) {
    printf("------\n");
    printf("Course name is %s\n", c->name);
    for (int i = 0; i < c->size; i++) {
        printf("Student %d is %s\n", i, c->students[i]);
    }
    printf("------\n");
}

Course *mergeCourse(char newName[], Course *c, Course *p) {
    Course *mergedCourse = buildCourse(newName, c->size + p->size);
    for (int i = 0; i < c->size; i++) {
        mergedCourse->students[i] = c->students[i];
    }
    for (int i = 0; i < p->size; i++) {
        mergedCourse->students[i + c->size] = p->students[i];
    }
    return mergedCourse;
}

int main(void) {

    Coursed c;
    c.name        = "Something";
    c.code        = 1234;
    c.maxStudents = 4;

    printf("First course configuration\n");
    Course *firstCourse = createCourse();
    printCourse(firstCourse);
    printf("Second course configuration\n");
    Course *secondCourse = createCourse();
    printCourse(secondCourse);
    printf("Merging\n");
    Course *mergedCourse = mergeCourse("newName", firstCourse, secondCourse);
    printCourse(mergedCourse);
}
