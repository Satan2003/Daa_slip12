//  Huffman Code using greedy 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Node {
    char data;
    int freq;
    struct Node *left, *right;
} Node;

int compare(const void *a, const void *b) {
    Node *nodeA = *(Node**)a;
    Node *nodeB = *(Node**)b;
    return nodeA->freq - nodeB->freq;
}

Node* newNode(char data, int freq) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->freq = freq;
    node->left = node->right = NULL;
    return node;
}

Node* buildHuffmanTree(char data[], int freq[], int size) {
    Node** nodes = (Node**)malloc(size * sizeof(Node*));
    int n = size;
    
    // initial nodes
    for (int i = 0; i < size; i++) {
        nodes[i] = newNode(data[i], freq[i]);
    }
    

    while (n > 1) {
        
        qsort(nodes, n, sizeof(Node*), compare);
        
        // Create a new internal node with the two lowest frequency nodes
        Node* internal = newNode('$', nodes[0]->freq + nodes[1]->freq);
        internal->left = nodes[0];
        internal->right = nodes[1];
        
        // Replace the first node with the new internal node
        nodes[0] = internal;
        
        // Remove the second node by shifting the array
        for (int i = 1; i < n - 1; i++) {
            nodes[i] = nodes[i + 1];
        }
        n--;
    }
    
    // The remaining node is the root
    Node* root = nodes[0];
    free(nodes);

    return root;
}

void printCodes(Node* root, char code[], int top) {
    
    if (root->left) {
        code[top] = '0';
        printCodes(root->left, code, top + 1);
    }
    
    if (root->right) {
        code[top] = '1';
        printCodes(root->right, code, top + 1);
    }
    
    // If this is a leaf node, print the character and its code
    if (!root->left && !root->right) {
        code[top] = '\0';
        printf("%c: %s\n", root->data, code);
    }
}

int main() {
    int n;
    printf("Enter number of characters: ");
    scanf("%d", &n);
    
    char data[n];
    int freq[n];
    
    printf("Enter characters and their frequencies:\n");
    for (int i = 0; i < n; i++) {
        scanf(" %c %d", &data[i], &freq[i]);
    }
    
    
    Node* root = buildHuffmanTree(data, freq, n);
    
    char code[100];
    printf("\nHuffman Codes:\n");
    printCodes(root, code, 0);
    
    return 0;
}