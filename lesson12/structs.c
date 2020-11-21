#include <stdio.h>
#include <string.h>

struct Book {
    char title[50];
    char author[50];
    char subject[100];
    int  book_id;
};
void printBook(struct Book book, int n) {
    printf("Book %d title : %s\n", n, book.title);
    printf("Book %d author : %s\n", n, book.author);
    printf("Book %d subject : %s\n", n, book.subject);
    printf("Book %d book_id : %d\n", n, book.book_id);
}
void buildBook(struct Book* book, char *title, char *author, char *subject, int book_id) {
    strcpy(book->title, "C Programming");
    strcpy(book->author, "Nuha Ali");
    strcpy(book->subject, "C Programming Tutorial");
    book->book_id = 6495407;
}
int main() {
    struct Book* Book1 = malloc(sizeof(struct Book));
    buildBook( Book1,
      "C Programming",
      "Nuha Ali",
      "C Programming Tutorial",
      6495407
    );
    struct Book* Book2 = malloc(sizeof(struct Book)); 
    buildBook( Book2,
      "Telecom Billing",
      "Zara Ali",
      "Telecom Billing Tutorial",
      6495700
    );
    printBook(*Book1, 1);
    printBook(*Book2, 2);
    free(Book1);
    free(Book2);
    return 0;
}