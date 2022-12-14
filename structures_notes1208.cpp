struct vitalsign {
	int ID;
	int Rpeak;
	float SBP;
	float DBP;
}

typeclef Struck vitalsign *Node

Node Current;
Current =>ID 數值
&Current =>ID (記憶體)位址

"linked list"
		p->next = (Node)malloc(sizeof(struct vitalsign)); //p指標內的位置初始話
		p = p->next; //把Pnext記憶體為紙袋到p裡面
		p->next= NULL; //head current end 的記憶體位址?


		head = p; current = p; end = p;
---------------------------------------------------------

#include <iostream>

using namespace std;

int a; //space
int *ap; //pointer
int &af = a; //ref/nickname

int main(){
    ap = &a; //address to pointer
    a = 10;
    cout << a << endl;
    *ap = 5;
    cout << a << endl;
    af = 15;
    cout << a << endl;
    return 0;
}

--------------------------------------------------------
// 10/20
//新增資料至cptr(copy delete paste)
int *cptr = new int [4];
int *c_cpt_temp = new int[5];
delete [] c_prt;
c_ptr = c_ptr_temp;

//使用DMA陣列完成一個整數串列
ADT: 
	建立一個class物件
		變數(private):
			data
			data_size
		方法(public):
			insert()
			delete()
			retrieve()
class int_dma_list{
	private members:
		int *data;
		int data_size;
	public member function:
		void Insert(int new_data, int ind); //void <- 不做回傳 or bool
		void Delete(int ind);
		int Retieve(int ind);
		int_dma_list();
		~int_dma_list();
};
// 建構子constructor->initialization (無型態) 程式執行時 先建立格式
// 解構子destructor->destroy 使用完格式後 把格式刪除
// float f(float x);
// f(x) = 3x + 5;
int_dma_list::int_dma_list(){ // ::為從屬運算子 代表右邊的function為左邊的子項
	data = NULL;
	data_size = 0;
}
void int_dma_list::Insert(int new_data, int ind){
	if(data_size == 0){
		data = new int[1];
		data[0] = new_data;
		data_size++;
	}
	else{
		int *data_temp = new int[data_size+1];
		for(int i = 0, i < ind, i++)
			data_temp[i] = data[i];
		for(int i = ind, i < data_size, i++)
			data_temp[i+1] = data[i];
		data_temp[ind] = new_data;
		delete[] data;
		data = data_temp;
		data_size++;
	}
}

--------------------------------------------------------------
// 10/27
//如果是實體的直接用. A.ID
//如果是間接的(指向記憶體空間的話)就用-> A->ID
struct student{
	int id;
	string name[10];
	int sex; //0:male 1:female
}
//node.hpp
struct node{
	int data;
	node* link;
}
// 建立一個儲存正整數的鏈結串列
ADT:
	變數(private):
		pHead(pointer)
		count(integer)
	方法(public):
		constructor
		Append()
		insert()
		destructor

node.hpp
intList.hpp
intList.cpp
mainList.cpp
//#include "相對路徑" <系統路徑>
//intList.cpp
#include "node.hpp"
Class intList{
	private:
		unsigned int count;
		node* pHead;
	public:
		intList();
		~intList();
		int Insert(int index, int newdata); //插入
		int Append(int newdata); //加入
}
//intList.cpp
#include"intList.hpp"
intList::intList(){
	pHead = NULL;
	count = 0;
}
int intList::Append(int newdata){ //p88 insertNode
	node* pNew = new node; //串建新指標協助產生新的node
	pNew->data = newdata;
	pNew->forward = NULL;
	node* pPre = pHead; //pPre指向開頭         pHead->[node-forward]->[node-forward]
	for(int i = 1; i < count; i++)
		pPre = pPre->forward;    //前幾行為讓pPre指向最後一個
	if(pPre == NULL)
		pNew->forward = pHead;
		pHead = pNew;
		cout << pHead->data << endl;
	else
		pPre->forward = pNew;	
	count++;	
}

int intList::Insert(int index, int newdata){ //p88 insertNode
	node* pNew = new node; //串建新指標協助產生新的node
	pNew->data = newdata;
	pNew->forward = NULL;
	node* pPre = pHead; //pPre指向開頭         pHead->[node-forward]->[node-forward]
	for(int i = 1; i < index; i++)
		pPre = pPre->forward;    //前幾行為讓pPre指向最後一個
	if(index == 0)
		pNew->forward = pHead;
		pHead = pNew;
		cout << pHead->data << endl;
	else
		pNew->forward = pPre->forward; //?
		pPre->forward = pNew;		
}
//mainList.cpp
#include"intList.hpp"
int main(){
	intList L;
	L.Append(10); //加入10

}


------------------------------------------------------------
// 11/3
class Templates <> P.129
templates <type>

Stack & Queue

	推入(push)
		要有足夠空間
	彈出(pop)
	頂端元素(Stack Top)

表頭<Head>:
	頂端指標(Pop Pointer)
	元素技術(Count)

堆疊應用
	-反轉
	-剖析
		ex:括號配對不正確
	-展延(Postponement)
	-中序轉為後序
		中序(Infix) 後序(Postfix) 前序(Prefix)
		將算式中所有運算加上括弧後把運算符號移置數字
		最後再把括弧拿掉
		+ - * / 仍保持運算規則 * / 具有優先級
		ex. A+B*C -> ABC*+
		ex. (A+B)*C+D+E*F-G -> AB+C*D+EF*G-
	-回朔(Backtracking)
		p.175
		使用分支(Brench)進行紀錄&搜尋
		ex.在每個Brench進行紀錄(B1 B2) 剛進行到結尾時紀錄End並回到前一分支 重複至搜尋到目標

佇列(Queues)
	-新增(enqueue)
	-刪除作業(dequeue)
	-佇列前端(Queue font)
	-佇列後端(Queue rear)
實作佇列需要兩種不同的結構:一個head結構與資料節點
佇列後會有一個head節點與0個或1個以上的資料節點

//鏈結串列
刪除節點;
class IntLinkedList{
	public:
		int Delete(int index);
		~IntLinkedList();
		int Retrieve(int index);
	private:
		node *pHead;
		int count;
}
int IntLinkedList::Delete(int index){
	if(index == 0){
		pLoc = pHead;
		pHead = pLoc->forward;
		delete pLoc;
	}
	else{
		pPre = pHead;
		for (int i = 1, i < index, i++){
			pPre = pPre->forward;
		}
		pLoc = pPre->forward;
		pPoc->forward = pLoc->forward;
		delete pLoc;
	}
	count--;
	return 0;
}
IntLinkedList::~IntLinkedList(){
	while(this->count > 0)
		Delete(0);
}
int IntLinkedList(){
	return count;
}
int IntLinkedList::Retrieve(int index){
	pLoc = pHead;
	for(int i = 0,i < index, i++)
		pLoc = pLoc->forward;
	return pLoc->data;
}

----------------------------------------------11/17
遞迴(recursion) p.242

ex.
-排列數/階層(factorial)
	n! = n*(n-1)!
	   = n*(n-1)*(n-2)!

	factorial.cpp

	#include <iostream>
	using namespace std;

	int factorial(int N){
		int factN = 1;
		for(int i = 1; i <= N; i++)
			factN = factN *i;
		return factN;  //把factN回傳給factorial(N)
	}
	main(){
		int N;
		cin >> N;
		cout << N << "!=" << factorial(N) << endl;
	}

	----
	int factorial(int N){
		if(N == 0)
			return 1;
		else{
			cout << N << endl;
			return factorial(N-1)*N;
		}
	}

-次方(power) p.246

int power (int x, int y){
	if(y == 0)
		return 1;
	else if {
		return (x * power(x, y-1));
	}
}

main(){
	int N;
    int P;
	cin >> N;
    cin >> P;
    cout << N << "^" << P << "=" << power (N, P) << endl;
}

-費氏數(Leonardo Fibonacci)
0, 1, 1, 2, 3, 5

-河內塔(Towers of Hanoi) p.255
| | |

-------------Append p.109
-------------Template p.131
Template <class Type>  //可改變型態
struct node{
	Type data;
	node* link;
};

int main(){
	int x = 10;
	node<int> A;
	A.data = 2;
	node<float> B;
	B.data = 1.234;
	cout << A << endl;
	cout << B << endl;
}

--------
c1 = a + bj;
c2 = c + dj;

class complex{
	private:
		double real;
		double image;
	public:
		int setReal(double R){
			real = R;
			return 0;
		}
		int setImage(double I){
			image = I;
			return 0;
		}
		complex();
		complex(double R, double I);
		double GetReal(){
			return real;
		}
		double GetImage(){
			return image;
		}
}
complex::complex(){
	real = 0;
	image = 0;
}
complex::complex(double R, double I){
	this->real = R;
	this->image = I;
}
int main(){
	complex C1;
	C1.SetReal(3);
	C1.SetImage(5);
	complex C2(3, 5);
}

-------C3 = (a+c) + (b+d)
operator+ //從重新定義加法
complex complex::operator+(complex C){

}

main(){
	c3 = c1 + c2;
	c3 = c1.operator+(c2);
}

--------------------------------------------11/24
Tree(樹) base on root p.270
	-每個node的分支數為"度"(分支度 Degree)
		根節點(Root)
		葉節點(Leaf node) : 外分支度為0的節點
		內部節點(Internal node) 既不是根結點也不是葉節點的節點
	ex.族譜
	-節點的階層數為(Level)
	 自Level 0算起，亦即Root 為Level 0
	-二元樹(Binary Tree)
		每個節點最多只有兩個子樹的樹稱為"二元樹"
		包含Null樹 (空樹)
	-平衡(Balabce)
		B = Hl-Hr 左樹高度減右樹高度
	-完全樹(Complete Tree)
	-二元樹的追蹤(Binary Tree Traversal)
		依預定的順序，處裡每一個節點
		-深度優先(Depth-First Traversal)
			-前序追蹤(Preoder Traversal)
				先處裡根結點，接著處理左子樹，最後處理右子樹
				因為樹的迴圈性質，適合以迴圈來做
				ex. Proc(A)
					PreO(Al)------->PreOrder(B)
					PreO(Ar)		|-proc(B)
									|-preO(Bl)
									|_preO(Br)
			-中序追蹤(Inorder Traversal)
				先處理左子樹，接著是根結點，最後是右子樹
			-後序追蹤(Postorder Traversal)
				先處理左子樹，接著處理右子樹，最後處理根結點
		-廣度優先(Breadth-First Traversal) p.284
			根到所有子節點，依水平的順序來處理
			First in last out.
			深度優先時，使用的是堆疊，廣度優先時，使用佇列
		-算式樹(Expression) p.286
			為二元樹的其中一個應用
			-中序追蹤(Infix Traversal)
			-後序追蹤(Postfix Traversal)
			-前序追蹤(Prefix Traversal)
	-將一般樹轉為二元樹
		由父子關係轉為兄弟關係
	-霍夫曼碼
		1.先依據字母出現頻率，將所有字元從高到低排成一列,將字元當成是葉節點
		2.將權重最小的兩個節點結合成第三個節點，形成一個二階的樹。(重複後，不論是新結點還是原節點)
		  加總原來兩個節點的權重，作為新節點的權重。
		  新節點比葉節點高一個階層。
		3.重複步驟2 ，直到每個階層的所有節點組合成一顆樹
	-建立樹 參考p.131~p.137
	template <class T>
	class Tree;
	template <class T>
	class TreeNode{
	friend class Tree<T>;
	private:
		T data;
		// int data;
		TreeNode<T> *leftSubTree;
		TreeNode<T> *rightSubTree;
	public:
		TreeNode();
		TreeNode(T newdata);
	};
	template <class T>
	class Tree{
	private:
		TreeNode<T> *root;
		int AddNode(T newdata);
		int AddNode(TreeNode<T> *&root, TreeNode<T> newnode_pt);
	public:
		//Tree Opeations
		Tree();
		int AddData(int key, T newdata);
		
	};
	template <class T>
	TreeNode<T>::TreeNode(){
		leftChild = NULL;
		rightChild = NULL;
		data = 0;
	}
	template <class T>
	TreeNode<T>::TreeNode(T newdata){
		leftChild = NULL;
		rightChild = NULL;
	}
	template <class T>
	Tree<T>::Tree(){
		root = NULL; 
	}
	
	int Tree<T>::AddNode(T newdata){
		if(root == NULL){
			root = new TreeNode<T>(newdata);
		}
		else{
			root->leftChild = new TreeNode<T>(newdata);
		}
	}

-----------------------------------------12/1
二元搜尋樹(Binary Search Tree, BST) p.302
	def:1.所有左子樹的值必須少於根結點
		2.所有右子樹的值必須大於或等於根結點
		3.每一顆子樹本身也是右子樹
	-分析(遞迴)
		1.Tree is empty -> set Root          ___________________               
		2.insert treenode on leaf           |    | int Key |    |     
									   Node | TN |---------| TN |
										    | 	 | T data  |    |
										    ---------------------
	-新增節點(遞迴)
		-如果搜尋到NULL樹或是NULL子樹，只要以節點的位置取代NULL樹即可
		-如果不是NULL樹，則要確定繼續追蹤哪個分支，並遞迴呼叫以確定是否達到葉節點
	-刪除節點 p.312
		四種可能情況:
			1.被刪除節點沒有仔節點
			2.被刪除的節點只有一個右子樹
			3.被刪除的節點只有一個左子樹
			4.被刪除的節點有兩個子樹(麻煩)

	-接上一次程式碼
	template <class T>
	int AddNode(TreeNode<T> *root, TreeNode<T> *newnode_pt){
		if(root = NULL){
			root = newnode_pt;
		}
		else{
			if(newnode_pt->key < root->key)
				AddNode(root->leftChild, newnode_pt);
			else
				AddNode(root->rightChild, newnode_pt);
		}
		cout(root->key);
		return 0;
	}
	int AddData(int key, T newdata){
		TreeNode<T> *newnode = new TreeNode<T>; //需用動態宣告否則跳出function數值會消失
		newnode->key = key;
		newnode->data = newdata;
		AddNode(this->root, newdata);
	}
	
	main(){
		Tree<int> BST;
		int k[7] = {23,18,44,12,20,35,52};
		int agc = 10;
		for (int i = 0; i <7; i ++){
			BST.AddData(k[i], agc);
			cout (i);
		}
	}

--------------------------------------------------12/28
VAL樹 p.315
	AVL樹就是子樹的"高度差"不超過1的樹
	-AVL樹藉由控制高度來取得平衡，因此也稱為高度平衡樹(Heught-balanced tree)
	-平衡作業
		1.左邊的左邊
		2.右邊的右邊
			-樹的右邊比較高，其他子樹也比較高
			-必須將不平衡的結點向左旋轉已恢復平衡
		3.左邊的右邊
			-需要旋轉兩個節點
			-一次向右旋轉，一次向左旋轉
		4.右邊的左邊
			-需要旋轉兩個節點
			-一次向左旋轉，一次向右旋轉
	-AVL樹的節點建構
	-AVL樹的新增節點

多向樹(muti-way Tree) p.380
	也稱為m向樹(m-way Tree)
	m向樹是一顆搜尋樹，他的每一個節點可以有0到m個子樹，m稱為樹的向次(order)
	-m向樹的結構
		健力項目的結構。
	-多向樹_B-Tree

		-新增節點作業