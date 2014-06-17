#include<stdio.h>
#include<stdlib.h>

struct btnode{
	struct btnode *l;
	struct btnode *r;
	int value;
}*root = NULL, *temp = NULL, *t1, *t2;


void insert();
void delete();
void delete_node(struct btnode *t);
void search(struct btnode *t);
void deletion_search(struct btnode *t, int data);
void create();
void inorder(struct btnode *t);
void preorder(struct btnode *t);
void postorder(struct btnode *t);

main(){
	int choice;
	printf("\n 1. Insert an element into BST");
	printf("\n 2. Delete an element from BST");
	printf("\n 3. Inorder traversal of BST");
	printf("\n 4. Preorder traversal of BST");
	printf("\n 5. Postorder traversal of BST");
	printf("\n 6. Exit");
	while(1){
		printf("\nYour Choice: ");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				insert();
				break;
			case 2:
				delete();
				break;
			case 3:
				inorder(root);
				break;
			case 4:
				preorder(root);
				break;
			case 5:
				postorder(root);
				break;
			case 6:
				exit(0);
			default:
				break;
		}
		
	}
}

void delete(){
	int data;
	if(root == NULL){
		printf("No elements to delete");
		return;
	}
	
	printf("Enter the data to be deleted: ");
    scanf("%d", &data);
	t1 = root;
	t2 = root;
	deletion_search(t1, data);
}

void deletion_search(struct btnode *t, int data){
	if(t->value < data){
		t1 = t;
		search(t->r);
	}else if(t->value > data){
		t1 = t;
		search(t->r);
	}else if(t->value == data){
		delete_node(t);
	}
}

void delete_node(struct btnode *t){
	if(t->r != NULL && t->l != NULL){
		//not yet implemented
	}else if(t->r != NULL){
		if (t1 == t){
			root = t->r;
			t1 = root;
		}else if (t1->r == t){
            t1->r = t->r;
		}else{
            t1->l = t->r;
		}
        
        t == NULL;
        free(t);
        return;
	}else if(t->l != NULL){
		if (t1 == t){
			root = t->l;
			t1 = root;
        }else if (t1->l == t){
			t1->l = t->l;
		}else{
            t1->r = t->l;
        }

        t = NULL;
        free(t);
        return;
	}else{
		if(t1->l == t){
			t1->l = NULL;
		}else{
			t1->r = NULL;
		}
		t = NULL;
		free(t);
		return;
	}
}

void inorder(struct btnode *t){
	if(root == NULL){
		printf("No elements to display");
		return;
	}	
	
	if(t->l != NULL){
		inorder(t->l);
	}
	
	printf("%d -> ", t->value);
	
	if(t->r != NULL){
		inorder(t->r);
	}
}

void preorder(struct btnode *t){
	if(root == NULL){
		printf("No elements to display");
		return;
	}	
	
	printf("%d -> ", t->value);
	
	if(t->l != NULL){
		preorder(t->l);
	}
	
	if(t->r != NULL){
		preorder(t->r);
	}
}

void postorder(struct btnode *t){
	if(root == NULL){
		printf("No elements to display");
		return;
	}	
	
	if(t->l != NULL){
		postorder(t->l);
	}
	
	if(t->r != NULL){
		postorder(t->r);
	}

	printf("%d -> ", t->value);
}

void insert(){
	create();
    if (root == NULL) 
    	root = temp;
    else    
       	search(root);    
}

void search(struct btnode *t){
	if((t->value < temp->value) && t->r == NULL){
		t->r = temp;
	}else if((t->value < temp->value) && t->r != NULL){
		search(t->r);
	}else if((t->value > temp->value) && t->l == NULL){
		t->l = temp;
	}else if((t->value > temp->value) && t->l != NULL){
		search(t->l);
	}
}

void create(){
	int data;
	printf("Enter data of node that is to be inserted: ");
	scanf("%d", &data);
	temp = (struct btnode*)malloc(1*sizeof(struct btnode));
	temp->value = data;
	temp->l = NULL;
	temp->r = NULL;	
}
