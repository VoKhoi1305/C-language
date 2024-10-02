#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct {
    char id[16];
    char name[40];
    int grade;
} data_t;

typedef struct node_s {
    data_t data;
    struct node_s *next;
} node_t, *root_t;

// Khai báo hàm llInsertTail
root_t llInsertTail(root_t root, const data_t data);

// Hàm hiển thị dữ liệu của một phần tử
void showdata(const data_t data)
{
    printf("%s - %s - %d\n",data.id, data.name, data.grade);
}

// Hàm chuyển đổi dữ liệu từ chuỗi sang kiểu data_t
data_t convert(char id[], char name[], int grade)
{
    data_t result;
    // Sử dụng hàm strcpy để sao chép chuỗi
    strcpy(result.id, id);
    strcpy(result.name, name);
    // Gán grade vào result
    result.grade = grade;
    return result;
}

// Hàm tạo một node mới
node_t* createNewNode(const data_t data) {
  node_t* newNode = (node_t*)malloc(sizeof(node_t));
  if (newNode == NULL) return NULL;

  newNode->data = data;
  newNode->next = NULL;
  return newNode;
}

// Hàm chèn một phần tử vào cuối danh sách liên kết
root_t llInsertTail(root_t root, const data_t data) {
  node_t* pNewNode = createNewNode(data);

  if (root == NULL) return (root_t)pNewNode;

  node_t* p = NULL;
  for (p = root; p->next != NULL; p = p->next)
    ;
  p->next = pNewNode;
  return root;
}

// Hàm khởi tạo danh sách liên kết rỗng
root_t llInit() { return NULL; }

// Hàm in ra danh sách liên kết
void llPrint(root_t root) {
  node_t* p = root;
  while (p != NULL) {
    showdata(p->data);
    p = p->next;
  }
}
void llSortByGrade(root_t root) {
  if (root == NULL || root->next == NULL) return;

  node_t* p = NULL; 
  node_t* q = NULL; 
  node_t* max = NULL; 
  while (root != NULL) {
    p = root;

    max = p;
    while (p->next != NULL) {

      q = p->next;
      if (q->data.grade > max->data.grade) {
        max = q;
      }
      p = q;
    }
    showdata(max->data);
    if (max == root) {
      root = root->next;
      free(max);
    }
    else {
      node_t* prev = root; 
      while (prev->next != max) {
        prev = prev->next;
      }
      prev->next = max->next;
      free(max);
    }
  }
}

int main(){
  root_t lst = llInit();

  char ids[10][16] = {"SV001", "SV002", "SV003", "SV004", "SV005", "SV006", "SV007", "SV008", "SV009", "SV010"};
  char names[10][40] = {"Nguyen Van A", "Tran Thi B", "Le Van C", "Pham Thi D", "Hoang Van E", "Do Thi F", "Bui Van G", "Nguyen Thi H", "Tran Van I", "Le Thi J"};
  int grades[10] = {9, 6, 4, 6, 7, 9, 6, 8, 3, 0};
  

  for (int i=0; i<10; i++) {

    data_t data = convert(ids[i], names[i], grades[i]);

    lst = llInsertTail(lst, data);

  }

llSortByGrade(lst);

 

}
