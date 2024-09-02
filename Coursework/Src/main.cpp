#include <cstdio>
#include <cstring>

typedef struct {
    char author[50];
    char title[50];
    char publisher[50];
    int year;
    int pages;
} Book;

void swap(Book* book1, Book* book2) {
    Book temp = *book1;
    *book1 = *book2;
    *book2 = temp;
}

int partition(Book* arr, int low, int high) {
    char pivotAuthor[50];
    strcpy(pivotAuthor, arr[low].author);

    int i = low + 1;
    int j = high;

    while (i <= j) {
        while (strcmp(arr[i].author, pivotAuthor) < 0 && i <= high) {
            i++;
        }

        while (strcmp(arr[j].author, pivotAuthor) > 0 && j >= low) {
            j--;
        }

        if (i <= j) {
            swap(&arr[i], &arr[j]);
            i++;
            j--;
        }
    }

    swap(&arr[low], &arr[j]);

    return j;
}

void quickSort(Book* arr, int low, int high) {
    if (low < high) {
        int pivot = partition(arr, low, high);

        quickSort(arr, low, pivot - 1);
        quickSort(arr, pivot + 1, high);
    }
}


int main() {
    FILE* file = fopen("/Users/BobroMacbook/CLionProjects/SAoDP/Coursework/Data/testBase1.dat", "r");
    if (file == NULL) {
        printf("Ошибка при открытии файла.\n");
        return 1;
    }

    Book books[10];
    for (int i = 0; i < 10; i++) {
        fscanf(file, "%s\n", books[i].author);
        fscanf(file, "%s\n", books[i].title);
        fscanf(file, "%s\n", books[i].publisher);
        fscanf(file, "%d\n", &(books[i].year));
        fscanf(file, "%d\n", &(books[i].pages));
    }

    fclose(file);

    quickSort(books, 0, 9);

    printf("Результат сортировки:\n");
    for (int i = 0; i < 10; i++) {
        printf("Автор: %s\n", books[i].author);
        printf("Название: %s\n", books[i].title);
        printf("Издательство: %s\n", books[i].publisher);
        printf("Год: %d\n", books[i].year);
        printf("Страницы: %d\n", books[i].pages);
        printf("---------------------\n");
    }

    return 0;
}