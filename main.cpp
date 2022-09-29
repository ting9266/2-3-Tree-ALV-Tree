// 10827232 魯霈恩 資工二乙 
// 10827233 林庭 資工二乙 
#include <iostream>                   // cout, endl
#include <fstream>                    // open, is_open, close, ignore
#include <string>                     // string, find_last_of, substr
#include <vector>                    // vector, push_back
#include <cstdlib>                   // system, atoi
#include <iomanip>                   // setw
#include <string.h>
#include <Windows.h>
#include <stdio.h> 
#include <stdlib.h>   
#include <sstream>                    // stringstream
#include <cstdlib>                    // atoi,system
#include <ctime>                      // clock,CLOCK_PER_SEC
#include <cmath>
 #include <cstddef>                                                        
using namespace std;

//******************************************      class    **********************************************************/

int noe = 1 ;

struct data { 
  int id;
  string name;
  string type1; 
  string shift;
  string level;   
  int snum;
};

typedef struct tree23 { 
  vector<struct data> key1;
  vector<struct data> key2;
  vector<struct data> keytemp;  
  bool done = false;
  struct tree23 *child[4], *parent;    
}tree23, *bst; 

typedef struct AVL
{
	vector<int> no ;
	vector<string> department ;
	vector<string> cname ;
	vector<string> dayornight ;
	vector<string> degree;
	vector<int> num ;
	struct AVL *left, *right;
}  AVLType,*atree;


class Data{    
 
 public:
     vector<AVLType> list ; 	 
     bool isdig(char number[]) ; 
	 bool isfilename(char name[],char number[]) ;
	 int getNO( char filename[] ) ;  
	 void readandAcc(string line);   
} ;

class mT{     
 public:
 	 int num = 0;//編號 
 	 int size = 0;
 	 int node = 1;
 	 bst root = NULL;
 	 bst no;
 	 vector<data> newtn;
 	 vector<data> list ;
	 vector<AVLType> avllist ;
	 vector<int> tree23list ;   	 
     bool isdig(char number[]) ; 
	 bool isfilename(char name[],char number[]) ;
	 int getNO( char filename[] ) ;  
	 string Degital(string r6);
	 void readandAcc(string line);
	 int checkisleaf( bst now );
	 tree23* backtoroot( bst now);
	 void clearnode( bst newn );
	 void sort( vector<struct data>newtn, bst parent );
	 tree23* split( bst now );
	 tree23* splitleaf(bst now, vector< data> newtn); 
	 tree23* tree23insert( bst now, int k, int time, bool back  );           //插入新一筆資料  
     int Height(bst root);
     void Searchtree23(string school, bst root );
} ;

class AVLTree{    
 
 public:
 	vector<AVLType> savllist ;
 	atree root = NULL ;
 	int Height(atree root);
 	int countBF(atree A);
 	void avltreeinsert(AVLType A); 
 	atree rotateLL(atree x);
 	atree rotateRR(atree x);
 	atree rotateLR(atree x);
 	atree rotateRL(atree x);
	void balance(atree x,bool balance) ;
 	void avlsearch(string ideparment,atree root);
} ;

class mS{     
 public:
 	 int num = 0;//編號 
 	 bst lastroot = NULL;
 	 atree avlroot = NULL;
 	 vector<data> slist ;
 	 //vector<int> tree23list ; 
     //tree23* Searchtree23(bst now, string school);
} ;

//********************************************  Data function ********************************************/

bool mT::isdig(char number[]) {
  for( int i = 0 ; i < strlen(number) ; i ++ )
    if ( isdigit(number[i]) == false && number[i]!= '\0')
	  return false ;
  return true ;	
}  // isdig

bool mT::isfilename(char name[],char number[]) {
  if( name[0]=='i' && name[1]=='n' && name[2]=='p'
      &&name[3]=='u' && name[4]=='t' && name[8]=='.' 
	  &&name[9]=='t' && name[10]=='x' && name[11]=='t'){
     if ( isdigit(name[5]) == true && isdigit(name[6]) == true 
	     && isdigit(name[7]) == true) {
		 number[0] == name[5] ;
		 number[1] == name[6] ;
		 number[0] == name[7] ;
	     return true ;	
		 }
	}
	
  return false ;
} // isfilename 

int mT::getNO( char filename[] ) {
  char name[ ]= "\0";
  char number[ ]= "\0";
  cin >> name ;
  if ( isdig(name)== true ){
  	 strcat( filename,"input" );
     strcat( filename,name );
     strcat( filename,".txt" );
     return atoi(name) ;
  } // end if
  else if ( isfilename( name, number) == true ) {
  	strcpy( filename, name );
  	return atoi(number);
  } // end else if
  else if ( strcmp( filename, "0")==0 ) {
  	return 0 ;
  }
  else {
  	cout << endl << "### input" << name << ".txt does not exist! ###" << endl;
  	cout << endl << "Input a file number (e.g., 401, 402, 403, ...): ";
  	return getNO(filename) ;
  }  
} // getNO

string mT::Degital(string r6) {
	char newr6[10];
	int n = 0;
    for (int i = 0;i < r6.size();i++) {
      if (r6.at(i) <= '9' && r6.at(i) >= '0'){
       newr6[n] = r6.at(i);	
       n++;
	  }     
    }
    r6 = newr6;
    return r6;
}


void mT::readandAcc(string line) { //把一行line裡的資訊存進list
    string temp = "\0";  
    
    int i = 0 ;
	vector<string> result;            	
    stringstream input(line);
    while(getline(input, temp, '\t')){ 
	  result.push_back(temp); 
	  i++;   
	}
	
	AVL current;
	current.no.push_back( noe);		
	current.department.push_back(result[3]) ;
	current.cname.push_back(result[1]) ;
	current.dayornight.push_back(result[4]) ;
	current.degree.push_back(result[5]) ;
	current.num.push_back(atoi(result[6].c_str())) ;
	
	
    avllist.push_back(current); 
	
	data current1;
	current1.id = noe ;	
	current1.name = result[1];
    current1.type1 = result[3]; 
    current1.shift = result[4];
    current1.level = result[5];   
	string r6 = Degital(result[6]);
	current1.snum = atoi(r6.c_str());
	
	list.push_back(current1); 
	 
    noe ++; 
} // readandAcc()

int mT::checkisleaf( bst now ){
	int judge = 1;
  for(int i = 0; i < 3; i++){
    if( now->child[i] !=NULL ){
	  judge = 0;     
	}

  }
  return judge; 	
}

void mT::sort( vector< data> newtn, bst parent   ){
  if( parent->key2.empty() ){
  	if( parent->key1[0].name.compare( newtn[0].name ) < 0 ){
  	  parent->key2.assign(newtn.begin(), newtn.end());
	}
	else{
   	  parent->key1.swap(newtn);
      parent->key2.assign(newtn.begin(), newtn.end());  	  
	}
  }
  else{
  	if( parent->key1[0].name.compare( newtn[0].name ) > 0 ){
   	  parent->key1.swap(newtn);
      parent->keytemp.assign(newtn.begin(), newtn.end()); 	

	   	  	  
	}
	else if ( parent->key2[0].name.compare( newtn[0].name ) < 0 ){
      parent->keytemp.assign(parent->key2.begin(), parent->key2.end()); 
      parent->key2.swap(newtn);  	  	   	  
	}  	
	else{
      parent->keytemp.assign(newtn.begin(), newtn.end()); 	   	
	}
  }
}

tree23* mT::split( bst now ){
  bst parent = now->parent;
  bst tool = NULL;
  bst temp = new tree23;
  temp->key1.assign(now->key2.begin(), now->key2.end());
  temp->child[0] = now->child[2];
  temp->child[1] = now->child[3];
  now->child[3]->parent = temp;
  now->child[2]->parent = temp;
  node++;	 
  for( int i = 2; i < 4; i++){
  	temp->child[i] = NULL;
  	now->child[i] = NULL;
  }
   now->key2.clear();
  if(now->parent == NULL ){
  	bst newroot = new tree23;
	newroot->key1.assign(now->keytemp.begin(), now->keytemp.end());	
    newroot->child[0] = now;
    newroot->child[1] = temp;
    newroot->child[2] = NULL;
    newroot->child[3] = NULL;
    newroot->parent = NULL;
    node++;
	root = newroot; 
	now->keytemp.clear();
	temp->parent = now->parent = root;
    return NULL;
  } 
  else{
  	if( parent->key2.empty() ){
  	  sort( now->keytemp, parent );	
  	  if( parent->child[0] == now ){
  		parent->child[2] = parent->child[1];   	
  		parent->child[1] = temp;
	  }   
	  else{
  	    parent->child[2] = temp;   	
	  }  
	  now->keytemp.clear();
	  temp->parent = now->parent;
	  return NULL; 					
	} 
	else{
	  sort( now->keytemp, parent );	
  	  if( parent->child[0] == now ){
  		tool = parent->child[1];   	
  		parent->child[1] = temp;
  	  	parent->child[3] = parent->child[2];
  		parent->child[2] = tool;
	  }   
	  else if( parent->child[1] == now ){
  		tool = parent->child[2]; 			
  		parent->child[2] = temp;   
  		parent->child[3] = tool;					
	  } 
	  else if( parent->child[2] == now ){
  		parent->child[3] = temp;   	
	  } 
	  now->keytemp.clear(); 
	  temp->parent = now->parent;
	  return now;		
	} 
  } 

}

tree23* mT::splitleaf( bst now, vector< data> newtn ){
  bst parent = now->parent;
  bst tool = NULL;
  bst temp = new tree23;
  node++;
  temp->key1.assign(now->key2.begin(), now->key2.end());	 
  for( int i = 0; i < 4; i++){
  	temp->child[i] = NULL;
  }
  temp->parent = NULL;
  now->key2.clear();
  if(now->parent == NULL ){
  	if(now->child[0] == NULL){
  		node++;
  	  bst newroot = new tree23;
	  newroot->key1.assign(newtn.begin(), newtn.end());	
      newroot->child[0] = now;
      newroot->child[1] = temp;
      newroot->child[2] = NULL;
      newroot->child[3] = NULL;
	  newroot->parent = NULL;      
	  root = newroot;  
    }
    temp->parent = now->parent= root;
    return NULL;
  } 
  else{

  	if( parent->key2.empty() ){
  	  sort( newtn, parent );
	
  	  if( parent->child[0] == now ){ 
  		parent->child[2] = parent->child[1];  	
		parent->child[1] = NULL;  	
  		parent->child[1] = temp;

	  }   
	  else{
  	    parent->child[2] = temp;   	
	  }  
	  temp->parent = now->parent;
	  return NULL; 					
	} 
	else{
  	  sort( newtn, parent );
			
  	  if( parent->child[0] == now ){
  		tool = parent->child[1];   	
  		parent->child[1] = temp;
  	  	parent->child[3] = parent->child[2];
  		parent->child[2] = tool;
	  }   
	  else if( parent->child[1] == now ){
  		tool = parent->child[2]; 			
  		parent->child[2] = temp;   
  		parent->child[3] = tool;  					
	  } 
	  else if( parent->child[2] == now ){
  		parent->child[3] = temp;
	  }  
	     temp->parent = now->parent;
	  return now;		
	}
  } 

}

tree23* mT::backtoroot( bst now){ 
  while( now->parent!=NULL){
  	now = now->parent;
  }
  return now;
}
tree23* mT::tree23insert( bst now, int k, int time, bool back ){ 
  int i = 0;
  bst check = NULL;
  int isleaf = 1;
  //建立節點內容
  if( time == 0 && k!=0 ){ 	
    newtn.push_back(list[k]); 	
  }
	  
  //cout << newtn->key1[0].id << " " << newtn->key1[0].name<< " " << newtn->key1[0].type1<< " " << newtn->key1[0].shift<<\
   " " << newtn->key1[0].level<< " " << newtn->key1[0].snum<<endl;
   
   //Empty Tree
  if( now == NULL ){
  	  now = new tree23;
      now->key1.push_back(list[k]); 
	  now->key2.empty();
	  for(int i = 0; i < 4; i++){
        now->child[i] = NULL;
	  }
      now->parent = NULL; 	  
	return now ; 
  }

  else{
  //找到newtn正確leaf node 
  if( now->key1[0].name.compare( newtn[0].name ) == 0 ){
    now->key1.push_back(newtn[0]);
	now = backtoroot( now );  	
    return now; 
	}    

   if( !now->key2.empty()){
     if( now->key2[0].name.compare( newtn[0].name ) == 0 ){
       now->key2.push_back(newtn[0]);
	   now = backtoroot( now);
       return now; 
	}   	
   }
	
   isleaf = checkisleaf( now );	
  //not leaf 尋找child 	

  	if(isleaf == 0){
		 	
        if( newtn[0].name.compare( now->key1[0].name ) < 0 ){
		  check =  tree23insert( now->child[0], k , 1, 0);
	    } 
  	    else if( now->key2.empty() && newtn[0].name.compare( now->key1[0].name ) > 0 ){
		  check =tree23insert( now->child[1], k , 1, 0 );
	    } 
  	    else if( newtn[0].name.compare( now->key2[0].name ) < 0 &&  newtn[0].name.compare( now->key1[0].name ) > 0 ){
		  check =  tree23insert( now->child[1], k , 1, 0 );
	    } 	  
	    else{
		  check =tree23insert( now->child[2], k , 1, 0 );	 	  
	    }  	  	
	
	  	if( !now->keytemp.empty() ){
	  	  check = split(now);
	  	  if(check == NULL){
	  	  	now = backtoroot( now )	;
	  	  	return now;
		  }
          else {
		  	return now->parent;  
		  }   
		}
		else{	
          return now ; 	
		}
      
    }	     	

	
	//leaf time to insert
	if( isleaf == 1 ){
		// node with one key 
		if( now->key2.empty() ){
		  if(now->key1[0].name.compare( newtn[0].name ) < 0){
		  	now->key2.push_back(newtn[0]);		  	
		  }	
		  else {
		  	now->key2.assign(now->key1.begin(), now->key1.end());
		  	now->key1.swap(newtn);
		  }
		  now = backtoroot( now)	;	 
		  return now;	  	
	    } 
		//node with two key  
		else{ 	  
		  if(newtn[0].name.compare( now->key1[0].name ) < 0 ){
		  	now->key1.swap(newtn);
		  }
		  else if( newtn[0].name.compare( now->key2[0].name ) > 0 ){
		  	now->key2.swap(newtn);
		  }
		  else{
		  } 
          check = splitleaf( now, newtn );  
          
          if( check == NULL){
          	now = backtoroot( now)	;         	       
          	return now;
		  }
		  else {		  	
		  	return now->parent;  
		  }    	    	
		} 	
    }
    return now;	
  }

  
} // TREE23insert
  
int mT::Height(bst root) {
	if(root==NULL)
		return 0;

	else
	{
		int lb=Height(root->child[0]);
		return lb+1;
	}
}

void mT::Searchtree23( string school, bst root ){
 
 bst now = NULL;
 now = root ;
 int find = 0;
 while( find == 0 && now != NULL ){
   if(school.compare( now->key1[0].name ) == 0){
    find = 1;
    //cout<< "find1"<<endl;
    
   } 
   else if(school.compare( now->key2[0].name ) == 0){
    find = 2;
        //cout<< "find2"<<endl;

   }
   else{
     if( school.compare( now->key1[0].name ) < 0){
      now = now->child[0] ;
     }
     else if( now->key2.empty() && school.compare( now->key1[0].name ) > 0 ){
      now = now->child[1] ;
     }
     else if( school.compare( now->key2[0].name ) < 0 &&  school.compare( now->key1[0].name ) > 0 ){
      now = now->child[1] ;
     }
     else{
    now = now->child[2];     
     }        
   }
      
 }
    if( find == 0 ){
    	    //cout<< "find0"<<endl;

 }
 else if( find == 1 ){ 
   for(int i = 0 ; i < now->key1.size(); i++ ){
     tree23list.push_back(now->key1[i].id);
   }  
 }
 else { 
   for(int i = 0 ; i < now->key2.size(); i++ ){
     tree23list.push_back(now->key2[i].id);
   }  
 }
}

//********************************************  AVL function ********************************************/
int AVLTree::Height(atree root) {
	if(root==NULL)
		return 0;

	else
	{
		int lb=Height(root->left);
		int rb=Height(root->right);
		return max(lb,rb)+1;
	}
} // Height()


int AVLTree::countBF(atree A){
  return ( Height( A->left ) - Height( A->right ) ) ;
} // countBF()


atree AVLTree::rotateLL(atree x){
  atree y = x -> left ;
  x-> left = y -> right;
  y -> right = x ;
  return y ;	
} // rotateLL() 


atree AVLTree::rotateRR(atree x){
  atree y = x-> right ;
  x-> right = y -> left;
  y -> left = x ;
  return y ;	
} // rotateRR()


atree AVLTree::rotateLR(atree x){	
  x-> left = rotateRR(x-> left);
  //x -> parent = x ;
  return rotateLL(x) ;	
} // rotateLR()


atree AVLTree::rotateRL(atree x){
  x-> right = rotateLL(x-> right); 
  return rotateRR(x) ;	
} // rotateRL()


void AVLTree::balance(atree now,bool bal){
	if( now == root){
		if( countBF(now) == 2 ){
	 	  if( countBF(now -> left) == -1){
	 		  root = rotateLR(now) ;
	 		  //cout << "LR" << endl;
		  }
	 	  else {
	 		  root = rotateLL(now);
	 		  //cout << "LL" << endl;
	 	  }
		  bal = true ;	
	    }
	    else if( countBF(now) == -2 ){
		  if( countBF(now -> right) == 1){
	 		  root = rotateRL(now) ; 
	 		  //cout << "RL" << endl;
	 	  }
	 	  else {
	 	      root = rotateRR(now);
	 	      //cout << "RR" << endl;
	 	   }
	 	  bal = true ;
	    }  	
	}
	else if((bal == false) ){
		
	  //  找到NOW的parent
  	  atree temp = NULL;
	  temp = new AVL ;
	  temp = root ;
	
	  while( (temp->left != now ) && ( temp->right != now )  ){
		if( now->department[0].compare( temp->department[0] ) > 0 )
		  temp = temp -> right ; 
		else 
		  temp = temp -> left ; 
	  }
	  

	  // check now 的BF
	  if (temp->department[0].compare( now ->department[0] ) > 0){
	  
	    if( countBF(now) == 2 ){
	 	  if( countBF(now -> left) == -1){
	 		  temp -> left = rotateLR(now) ;
	 		  //cout << "LR" << endl;
		  }
	 	  else {
	 		  temp -> left = rotateLL(now);
	 		  //cout << "LL" << endl;
	 	  }
		  bal = true ;	
	    }
	    else if( countBF(now) == -2 ){
		  if( countBF(now -> right) == 1){
	 		  temp -> left = rotateRL(now) ; 
	 		   //cout << "RL" << endl;
	 	  }
	 	  else {
	 	      temp -> left = rotateRR(now);
	 	      //cout << "RR" << endl;
	 	   }
	 	  bal = true ;
	    }  
      }   
	  else if (temp->department[0].compare( now ->department[0] ) < 0){
	  
	    if( countBF(now) == 2 ){
	 	  if( countBF(now -> left) == -1){
	 		  temp -> right = rotateLR(now) ; 
	 		   //cout << "LR" << endl;
	 	  }
	 	  else {
	 		  temp -> right = rotateLL(now);
	 		   //cout << "LL" << endl;
	 	  }
		  bal = true ;	
	    }
	    else if( countBF(now) == -2 ){
		  if( countBF(now -> right) == 1){
	 		  temp -> right = rotateRL(now) ; 
	 		   //cout << "RL" << endl;
	 	  }
	 	  else {
	 	      temp -> right = rotateRR(now);
	 	       //cout << "RR" << endl;
	 	   }
	 	  bal = true ;
	    }  
      }  
	
	  //找上一個節點 
	  now = temp ;
	  balance( now, bal);
	
	
    } // if
} // balance()


void AVLTree::avltreeinsert(AVLType A){
	atree now = NULL;
	atree newnode = NULL ;
	bool insert = false ;
	bool bal = false ;
	int bos = 0 ;
	now = new AVL ;
   
	
	//將資料放進節點 
	newnode = new AVL ;
	newnode->no.push_back(A.no[0]);
	newnode->department.push_back(A.department[0])  ;
	newnode->cname.push_back(A.cname[0])  ;
	newnode->dayornight.push_back(A.dayornight[0])  ;
	newnode->degree.push_back(A.degree[0])  ;
	newnode->num.push_back(A.num[0])  ;
	newnode->left = NULL ;
    newnode->right = NULL ;
	
	//插入新節點 
	if( root == NULL){ 
	  root = newnode ;
	} 
	else{
	  now = root ; 
      while( insert == false){
	    if ( newnode->department[0].compare(now->department[0]) < 0 ) { // 若新增資料比now小 
	    	if( now->left == NULL ){  // 且 now左側已無節點，則插入 
	    	  now->left = newnode ;
			  //cout << "bigger " << newnode->no[0]  << endl ;	
	    	  insert = true ;	
			} // if
			else 
			  now = now -> left ; // 若有則往左繼續比較 
		}
		else if ( newnode->department[0].compare(now->department[0]) > 0 ) { // 若新增資料比now大 
	    	if( now->right == NULL ){  // 且 now右側已無節點，則插入 
	    	  now->right = newnode ;
			  //cout << "smaller " << newnode->no[0]  << endl ;
	    	  insert = true ;	
			} // if
			else 
			  now = now -> right ; // 若有則往右繼續比較 
		}
		else if ( newnode->department[0].compare(now->department[0]) == 0 ) { // 若新增資料和now相同 
	    	 now->department.push_back(newnode->department[0]); // 將資料push進now 
	    	 now->no.push_back(newnode->no[0]);
	    	 now->cname.push_back(newnode->cname[0]);
	    	 now->dayornight.push_back(newnode->dayornight[0]);
	    	 now->degree.push_back(newnode->degree[0]);
	    	 now->num.push_back(newnode->num[0]);
	    	 newnode  = now ;
	    	 //cout << "same " << newnode->no[1] << endl ;
	    	 insert = true ; 
		}	// else if
	   } // while
	   
	   
	   
	 // 確認其是否平衡
	 if(now != newnode){
       balance(now,bal);	
	 } // if
	 
    } // else
	
} //avltreeinsert()

 
void AVLTree::avlsearch(string ideparment,atree root1){
	atree now = NULL;
	now = root1 ;
  
	
	while( (now->left!= NULL) && (now->right!= NULL) && ideparment.compare(now->department[0]) != 0){
	  if( ideparment.compare(now->department[0]) > 0){
	  	now = now -> right ;
	  }
	  else if( ideparment.compare(now->department[0]) < 0){
	  	now = now -> left ;
	  }
	}
    
    
	for(int i = 0 ; i < now->no.size(); i++ ){
		AVL current;
	    current.no.push_back( now->no[i]);		
     	current.department.push_back(now->department[i]) ;
     	current.cname.push_back(now->cname[i]) ;
	    current.dayornight.push_back(now->dayornight[i]) ;
	    current.degree.push_back(now->degree[i]) ;
	    current.num.push_back(now->num[i]) ;
	
	
        savllist.push_back(current); 
	}	
}


//*******************************************  SEARCH TREE23 function ***********************************************************/




     
int main(void)
{ int command = 0 ;
    mT fun ; 
    Data dfun ;
    mS sfun;  
	AVLTree avl; 
  do 
  {
    ifstream file ;        
    cout << endl << "*** Search Tree Utilities **";
    cout << endl << "* 0. QUIT                  *";
    cout << endl << "* 1. Build 2-3 tree        *";
    cout << endl << "* 2. Build AVL tree        *";
    cout << endl << "* 3. Intersection Query    *";
    cout << endl << "****************************";
    cout << endl << "Input a choice(0, 1, 2, 3):";
    cin >> command ;
      
    switch(command){
      case 0 : break ;
      
	  case 1 :if (1){ 
       // Mission One: read & save a file
       
          cout << endl << "Input a file number [0: quit]: " ; 
          
          
          // 讀取檔案名 
          char filename[] = "\0";
          int numberoffile = 0 ;
          numberoffile = fun.getNO(filename); 
          if ( numberoffile== 0 )
              break ;
            
            
		  // 開啟檔案 
          file.open( filename, ios::in );
          while(!file){
            cout << endl << "### " << filename << " does not exist! ###" << endl;
            cout << endl << "Input a file number [0: quit]: ";
            strcpy(filename, "\0");
            numberoffile = fun.getNO(filename); 
            if ( numberoffile== 0 )
              break ;
            file.open( filename, ios::in );
          } // end while
		  
		   
          if (file){
       
                               
            // 將資料放入
	        string line = "/0",skipline ="/0" ;
	        
	        int k = 0;
	        while( k < 3 ){
	          getline(file,skipline) ;
	          k ++;
			}
			
			//int h = 0;
			fun.list.clear();
			fun.avllist.clear();
            while(getline(file,line)){
              //cout<<"read"<<h<<endl;
              fun.readandAcc(line); 
			  //h++;             
			} // WHILE

            // 建立23tree
            k = 0;           
            while( k<fun.list.size() ){
              //cout<<"tree"<<endl;
			  fun.root = fun.tree23insert( fun.root, k, 0, 0);
              fun.newtn.clear();
			  k++; 
			}

			
			cout << "Tree height ="  << fun.Height(fun.root) << endl;	
			k = 0;
			int j = 0;			
			if( !fun.root->key1.empty() && !fun.root->key2.empty() ){   
			  if( fun.root->key1[0].id < fun.root->key2[0].id ){
                while( k < fun.root->key1.size() ){
                  cout << k + 1 <<": ["<< fun.root->key1[k].id << "] " << fun.root->key1[k].name << ", " << fun.root->key1[k].type1 <<", "<< fun.root->key1[k].shift <<", "\
				  << fun.root->key1[k].level <<", "<< fun.root->key1[k].snum<<endl;
				  k++;
			    }
			    j = k;
			    k=0; 
				while( k < fun.root->key2.size() ){
                  cout << j + 1 <<": ["<< fun.root->key2[k].id << "] " << fun.root->key2[k].name << ", " << fun.root->key2[k].type1 <<", "<< fun.root->key2[k].shift <<", "\
				  << fun.root->key2[k].level <<", "<< fun.root->key2[k].snum<<endl;
				  k++;
				  j++;
			    }						  	
			  }  
			  else{
				while( k < fun.root->key2.size() ){
                  cout << k + 1 <<": ["<< fun.root->key2[k].id << "] " << fun.root->key2[k].name << ", " << fun.root->key2[k].type1 <<", "<< fun.root->key2[k].shift <<", "\
				  << fun.root->key2[k].level <<", "<< fun.root->key2[k].snum<<endl;
				  k++;
			    }
				j = k;	
			    k = 0;
                while( k < fun.root->key1.size() ){
                  cout << j + 1 <<": ["<< fun.root->key1[k].id << "] " << fun.root->key1[k].name << ", " << fun.root->key1[k].type1 <<", "<< fun.root->key1[k].shift <<", "\
				  << fun.root->key1[k].level <<", "<< fun.root->key1[k].snum<<endl;
				  k++;
				  j++;
			    }						  	
			  }       
	  
			}
			
			else{
                while( k < fun.root->key1.size() ){
                  cout << k + 1 <<": ["<< fun.root->key1[k].id << "] " << fun.root->key1[k].name << ", " << fun.root->key1[k].type1 <<", "<< fun.root->key1[k].shift <<", "\
				  << fun.root->key1[k].level <<", "<< fun.root->key1[k].snum<<endl;
				  k++;
			    }				
			}
			
		    sfun.lastroot = fun.root;  
			 
	        sfun.slist.assign( fun.list.begin(), fun.list.end() );
	
			fun.num = 0;
			fun.node = 0;
		    fun.list.clear();
		    free(fun.root);
		    fun.root = NULL;				
			// 關閉檔案   
	        file.close();       
	    } // end if      
       } // end if
       break;
       
	  case 2 :if (1){ 
	  
        if(sfun.lastroot == NULL){
          cout<<"### Choose 1 first. ###"<<endl;	
		}	  
	      		  
		else{
		  
		  //排成AVL Tree 
		  int bottom = 0 ;
		  
		  while ( bottom < fun.avllist.size() ){
		  	avl.avltreeinsert(fun.avllist[bottom]);
		  	bottom++;
		  }
		  
		  
		  // 輸出
		  cout << "Tree height = " << avl.Height(avl.root) << endl ;
		  for(int i = 0 ; i < avl.root->no.size(); i++ ){
		    cout << i+1 << ": [" <<  avl.root->no[i] << "] " << avl.root->cname[i] << ", " << avl.root->department[i] << ", " ;
			cout << avl.root->dayornight[i] << ", " <<  avl.root->degree[i] << ", " <<  avl.root->num[i] << endl ; 
	      }
	
	      // 關閉檔案 
		  noe = 1 ;   
		  sfun.avlroot = avl.root; 			      
		  avl.root = NULL;			
		}  

	  } // end if 
      break;
	         
	  case 3 :if( 1 ){  
        if(sfun.lastroot == NULL){
          if( avl.root == NULL ){
            cout<<"### Choose 1 first. ###"<<endl;          	
		  }	 	  	
		}
		else if( sfun.avlroot == NULL ){
            cout<<"### Choose 2 first. ###"<<endl;  			
		} 
        else{
          string school;
          cout<<"Enter a college name to search [*]:"<<endl;
		  cin>> school;
		  
		  string depart;
          cout<<"Enter a department name to search [*]:"<<endl;
		  cin>> depart;
		  avl.savllist.clear();
		  if(depart.compare("*") == 0 ){
		  	for(int i = 0 ; i < fun.avllist.size(); i++)
		  	  avl.savllist.push_back(fun.avllist[i]); 
		  }
		  else
		   avl.avlsearch(depart,sfun.avlroot) ;
		   
		  
		   	  
		  if( school.compare("*")== 0  ){
		    for(int i = 0 ; i < fun.avllist.size(); i++)
		  	  fun.tree23list.push_back(i);
		  }
		  else 
		  	fun.Searchtree23( school, sfun.lastroot );	
		  
		  // cout << fun.tree23list.size() << endl;
		  
		  if(avl.savllist.size() != 0 && fun.tree23list.size() != 0 ){
		  for(int i = 0 ; i < avl.savllist.size(); i++){
		  	for(int j = 0 ; j < fun.tree23list.size(); j++){
		  		if( avl.savllist[i].no[0] == fun.tree23list[j]  ){
		  		  cout << i+1 << ": [" <<  avl.savllist[i].no[0] << "] " << avl.savllist[i].cname[0] << ", " << avl.savllist[i].department[0] << ", " ;
			      cout << avl.savllist[i].dayornight[0] << ", " <<  avl.savllist[i].degree[0] << ", " << avl.savllist[i].num[0] << endl ;
		    }
		  }
	     }
	 }    
		  
		 
		  
		}
		sfun.slist.clear();
		dfun.list.clear();
		avl.root = NULL;			
		sfun.lastroot = NULL; 		
       } // end if
	   break;
	   
	   default: cout << endl << "Command does not exist!" << endl ;
	   
    } // end switch

  } while(command!=0) ;

  return 0 ;
  
} //end main
