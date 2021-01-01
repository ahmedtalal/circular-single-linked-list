
typedef struct circularNode {
    int data ;
    struct circularNode *next ;
}node ;

void createNode() ;
int isEmpty() ;
void firstInsert(int value) ;
void lastInsert(int value) ;
void firstDelete() ;
void lastDelete() ;
void searchItemValue(int position) ;
void display() ;
