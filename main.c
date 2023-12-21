#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int pixelValue;
    char *huffmanCode;
    struct Node *next;
} Node;

Node *createNode(int pixelValue, char *huffmanCode) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->pixelValue = pixelValue;
    newNode->huffmanCode = huffmanCode;
    newNode->next = NULL;
    return newNode;
}

void showList(Node *head) {
    printf("Pixel Value\tHuffman Code\n");
    while (head != NULL) {
        printf("%d\t\t%s\n", head->pixelValue, head->huffmanCode);
        head = head->next;
    }
}


int main() {

    int image[10][10];

    char *dummyHuffmanCodes[256];
    for (int i = 0; i < 256; i++) {
        char *dummyCode = (char *)malloc(5);
        sprintf(dummyCode, "%d", i);
        dummyHuffmanCodes[i] = dummyCode;
    }

    Node *head = NULL;
    for (int i = 0; i < 256; i++) {
        if (dummyHuffmanCodes[i] != NULL) {
            Node *newNode = createNode(i, dummyHuffmanCodes[i]);
            newNode->next = head;
            head = newNode;
        }
    }

    showList(head);

    while (head != NULL) {
        Node *temp = head;
        head = head->next;
        free(temp->huffmanCode);
        free(temp);
    }

    return 0;
}
