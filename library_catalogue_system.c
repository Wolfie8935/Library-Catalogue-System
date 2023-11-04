#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Book {
    char title[100];
    char author[50];
    int isbn;
};

struct Node {
    struct Book book;
    struct Node* next;
};

#define TABLE_SIZE 100
struct HashTable {
    struct Node* table[TABLE_SIZE];
};

struct HashTable catalog;

struct Book books[100];
int bookCount = 0;

struct TreeNode {
    struct Book book;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode* root = NULL;

struct TreeNode* insertIntoBST(struct TreeNode* node, struct Book book);

void addBookToCatalog(struct Book book) {
    int index = book.isbn % TABLE_SIZE;

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->book = book;
    newNode->next = catalog.table[index];
    catalog.table[index] = newNode;

    books[bookCount++] = book;
    root = insertIntoBST(root, book);
}

struct TreeNode* insertIntoBST(struct TreeNode* node, struct Book book) {
    if (node == NULL) {
        struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
        newNode->book = book;
        newNode->left = newNode->right = NULL;
        return newNode;
    }

    if (book.isbn < node->book.isbn) {
        node->left = insertIntoBST(node->left, book);
    } else if (book.isbn > node->book.isbn) {
        node->right = insertIntoBST(node->right, book);
    }

    return node;
}

struct Book* searchBookByISBN(int isbn) {
    int index = isbn % TABLE_SIZE;
    struct Node* current = catalog.table[index];

    while (current != NULL) {
        if (current->book.isbn == isbn) {
            return &current->book;
        }
        current = current->next;
    }

    return NULL;
}

void displayBook(struct Book book) {
    printf("Title: %s\nAuthor: %s\nISBN: %d\n\n", book.title, book.author, book.isbn);
}

void displayCatalog() {
    printf("Catalog:\n");
    for (int i = 0; i < bookCount; i++) {
        displayBook(books[i]);
    }
}

int main() {
    // Adding 10 books to the catalog
    struct Book book1 = {"Adventures of Tom Sawyer", "Mark Twain", 12345};
    struct Book book2 = {"Alice in Wonderland", "Lewis Carrol", 67890};
    struct Book book3 = {"Animal Farm", "George Orwell", 54321};
    struct Book book4 = {"Gulliver's Travels", "Jonathan Swift", 11111};
    struct Book book5 = {"Das Kapital","Karl Marx", 22222};
    struct Book book6 = {"Adventures of Sherlock Holmes", " Arthur Conan Doyle", 33333};
    struct Book book7 = {"Utopia", "Utopia", 44444};
    struct Book book8 = {"Origin of Species", "Charles Darwin", 55555};
    struct Book book9 = {"Time Machine", "H.G. Wells", 66666};
    struct Book book10 = {"Arms and the Man", "G.B.Shaw", 77777};

    addBookToCatalog(book1);
    addBookToCatalog(book2);
    addBookToCatalog(book3);
    addBookToCatalog(book4);
    addBookToCatalog(book5);
    addBookToCatalog(book6);
    addBookToCatalog(book7);
    addBookToCatalog(book8);
    addBookToCatalog(book9);
    addBookToCatalog(book10);

    int choice;
    int isbn;
    struct Book newBook;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Add a Book to the Catalog\n");
        printf("2. Search for a Book by ISBN\n");
        printf("3. Display Catalog\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter book title: ");
                scanf(" %[^\n]s", newBook.title);
                printf("Enter author name: ");
                scanf(" %[^\n]s", newBook.author);
                printf("Enter ISBN: ");
                scanf("%d", &newBook.isbn);
                addBookToCatalog(newBook);
                printf("Book added to the catalog:\n");
                displayBook(newBook);
                break;

            case 2:
                printf("Enter ISBN to search for a book: ");
                scanf("%d", &isbn);
                struct Book* foundBook = searchBookByISBN(isbn);
                if (foundBook != NULL) {
                    printf("Book found in catalog:\n");
                    displayBook(*foundBook);
                } else {
                    printf("Book not found in catalog.\n");
                }
                break;

            case 3:
                displayCatalog();
                break;

            case 4:
                printf("Exiting the program.\n");
                exit(0);

            default:
                printf("Invalid choice. Please select a valid option.\n");
        }
    }

    return 0;
}