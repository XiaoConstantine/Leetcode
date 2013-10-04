/*
 * =====================================================================================
 *
 *       Filename:  PopulatingNextRightPointersII.cc
 *
 *    Description:  LeetCode Populating Next Right Pointers II
 *        Version:  1.0
 *        Created:  03/30/13 16:56:29
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Xiao Cui (XC), 
 *   Organization:  
 *
 * =====================================================================================
 */


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  connect
 *  Description:  Recursvie with 3 pointers  
 * =====================================================================================
 */
void
connect (TreeLinkNode* root)
{
	if(root == NULL) return;
	TreeLinkNode* p = root;
	TreeLinkNode* q = NULL;
	TreeLinkNode* nextNode = NULL;
	while(p){
		if(p->left){
			if(q){
				q->next = p->left;
			}
			q = p->left;
			if(nextNode == NULL ){
				nextNode = q;
			}
		}
		if(p->right){
			if(q){
				q->next = p->right;
			}
			q = p->right;
			if(nextNode == NULL){
				nextNode = q;
			}
		}
	   p = p->next;
	}
	connect(nextNode);
}		
/* -----  end of function connect  ----- */
