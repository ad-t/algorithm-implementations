#include <assert.h>
#include "bst.h"

int main (void) {
    printf("Creating tree...");
    TreeRep t = createTree();
    printf("Done\nCheck size 0...");
    assert(getSize(t) == 0);
    int i = 0;
    printf("Done\nAdding 100 nodes...");
    for (i = 0; i < 100; i++) {
        addNode(t, i);
    }
    printf("\nChecking size... Actual size = %d\n", getSize(t));
    assert(getSize(t) == 100);
    for (i = 0; i < 100; i++) {
        assert(getValue(getNode(t, i)) == i);
    }   
    assert(getMin(t) == 0);
    assert(getMax(t) == 99);
    destroyTree(t);
    return EXIT_SUCCESS;
}   
