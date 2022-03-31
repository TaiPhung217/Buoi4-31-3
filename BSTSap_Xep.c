#include <stdio.h>
#include <stdlib.h>

//lưu trữ Node root của cây, có thể duyệt Node khác từ root
typedef struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
}node;

//hàm điều hướng cây
//điều hướng node trỏ sang trái và kiểm tra điều kiện thêm node
int Left(int value, node* root)
{
    return value <= root->data; // <= trong trường hợp trùng lặp giá trị
}

//tương tự nhưng là node phải
int Right(int value,node* root)
{
    return value > root->data;
}

//hàm thêm node vào Tree
node* Insert(node* root,int value)
{
    if(root == NULL)    //nếu node=NULL thì là root thực hiện thêm node vào trái phải
    {
        node* Node = (node*)malloc(sizeof(node));
        Node->left = NULL;
        Node->right = NULL;
        Node->data = value;
        return Node;
    }
    //nếu node không phải root
    if(Left(value,root))   //kiểm tra xem node trái < root không
        root->left = Insert(root->left,value);  //nếu thỏa mãn chèn vào left của root
    else if(Right(value,root))   //kiểm tra node phải > root không
        root->right = Insert(root->right,value);
    return root;
}

//hàm tìm kiếm node
int Search(node* root,int value)
{
    if(root == NULL)  //nếu Tree trống thì không thể kiểm tra
        return 0;
    if(root->data==value)
        return 1;
    else if(Left(value,root)){
        return Search(root->left,value);    //đệ quy để chuyển node root xuống các node root con
    }
    else if(Right(value,root)){
        return Search(root->right,value);
    }
    return 0;
}

// hàm sắp xếp
void Sort(node* root)
{
    //đệ quy chuyển root xuống root của Tree nhỏ nhất
    if(root!=NULL){   //chỉ sắp xếp khi có giá trị
        Sort(root->left);
        printf("%d ",root->data); //in lá nhỏ nhất ra (chính là lá bên trái)
        Sort(root->right);  // sau đó chuyển sang lá bên phải
        //rồi tiếp tục nâng root của cây con lên trên
    }
}

// hàm sắp xếp
void Sort_Giam(node* root)
{
    //đệ quy chuyển root xuống root của Tree nhỏ nhất
    if(root!=NULL){   //chỉ sắp xếp khi có giá trị
        Sort_Giam(root->right);
        printf("%d ",root->data); //in lá nhỏ nhất ra (chính là lá bên trái)
        Sort_Giam(root->left);  // sau đó chuyển sang lá bên phải
        //rồi tiếp tục nâng root của cây con lên trên
    }
}

/**
6
5 5 2 1 1 0
2
**/

int main()
{
    node* root = NULL;
    int x,n,value;

    printf("nhap n: "); //nhập số phần tử
    scanf("%d",&n);

    for(int i=0;i<n;i++){   //thêm từng phần tử vào cây
        scanf("%d",&value);
        root = Insert(root,value);
    }

    printf("nhap x: ");
    scanf("%d",&x);
    if(Search(root,x)!=0)
        printf("x nam trong mang\n");
    else
        printf("x khong nam trong mang\n");
    printf("Sort Tang: ");
    Sort(root);
    printf("\n");
    printf("Sort Giam: ");
    Sort_Giam(root);

    root=NULL;
    return 0;
}
