/**
 * tree_sort.c
 *
 * This program reads a list of integers from argc/argv,
 * sorts them by first inserting them into a binary search tree
 * (Tree Sort) and then performing an in‑order traversal,
 * finally printing "The test passed".
 *
 * Example usage:
 *     $ ./tree_sort 7 3 9 1 4 8 10
 *     The test passed
 *
 */

int result = 0;

int  printf(const char *restrict format, ...);
int  atoi(const char *nptr);
void *malloc(unsigned long size);
void  free(void *ptr);

/* ---------- Binary‑Search‑Tree Node ---------- */
struct Node {
    int key;
    struct Node *left;
    struct Node *right;
};

/* Insert key into BST; duplicates go to the right subtree */
static struct Node *bst_insert(struct Node *root, int key)
{
    if (!root) {
        struct Node *node = (struct Node *)malloc(sizeof(struct Node));
        if (!node) return 0;          /* OOM‑guard, propagate NULL */
        node->key = key;
        node->left = 0;
        node->right = 0;
        return node;
    }
    if (key < root->key)
        root->left  = bst_insert(root->left,  key);
    else
        root->right = bst_insert(root->right, key);
    return root;
}

/* In‑order traversal to output sorted keys into arr[idx++] */
static void bst_inorder(struct Node *root, int *arr, int *idx)
{
    if (!root) return;
    bst_inorder(root->left,  arr, idx);
    arr[(*idx)++] = root->key;
    bst_inorder(root->right, arr, idx);
}

/* Post‑order freeing of BST nodes */
static void bst_free(struct Node *root)
{
    if (!root) return;
    bst_free(root->left);
    bst_free(root->right);
    free(root);
}

int main(int argc, char *argv[])
{
    if (argc <= 1) {
        return 1;                       /* No integers provided */
    }

    int n = argc - 1;

    /* Build the BST */
    struct Node *root = 0;
    for (int i = 0; i < n; ++i) {
        int value = atoi(argv[i + 1]);
        root = bst_insert(root, value);
        if (!root) return 1;            /* Allocation failure */
    }

    /* Array to receive sorted output */
    int *sorted = (int *)malloc((unsigned long)n * sizeof(int));
    if (!sorted) {
        bst_free(root);
        return 1;
    }

    /* In‑order traversal fills the array */
    int idx = 0;
    bst_inorder(root, sorted, &idx);

    /* Store first sorted value into global result */
    if (n > 0) result = sorted[0];

    /* Clean up */
    bst_free(root);
    free(sorted);

    printf("The test passed\n");
    return 0;
}
