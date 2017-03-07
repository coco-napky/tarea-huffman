#include "Test.h"
#include <iostream>
#include <cstdlib>
using namespace std;

struct QueueNode
{
    char data;
    int freq;
    struct QueueNode *left, *right;
};

queue<QueueNode *> fillQ1(vector<char> characters, vector<int> frequencies)
{
    queue<QueueNode * > q1;
    for(int i =0 ; i< frequencies.size(); i++)
    {
        QueueNode  * q = new QueueNode();
        q->data = characters[i];
        q->freq = frequencies[i];
        q->left = 0;
        q->right = 0;
        q1.push(q);
    }
    return q1;
}

QueueNode * selectNode( queue<QueueNode *>& q1, queue<QueueNode * >& q2 )
{
    QueueNode * res = new QueueNode();
    if(q1.empty())
    {
       res = q2.front();
       q2.pop();
       return res;
    }
    if(q2.empty())
    {
        res = q1.front();
        q1.pop();
        return res;
    }
    if (q1.front()->freq <= q2.front()->freq)
    {
        res = q1.front();
        q1.pop();
        return res;
    }
   res = q2.front();
   q2.pop();
   return res;
}

struct QueueNode* buildHuffmanTree(vector<char> characters, vector<int> frequencies)
{
    queue<QueueNode *> q1 = fillQ1(characters,frequencies);
    queue<QueueNode *> q2;
    QueueNode * n1, * n2, *res;
    while(!(q1.empty() && q2.size() == 1 ))
    {
        n1 = selectNode(q1,q2);
        n2 = selectNode(q1,q2);
        QueueNode * ni = new QueueNode();
        ni->left =0;
        ni->right =0;
        ni->data = '~';
        ni->freq = n1->freq + n2->freq;
        ni->left = n1;
        ni->right= n2;
        q2.push(ni);
    }
     res = q2.front();
     q2.pop();
     return res;
}

int isLeaf(struct QueueNode* root)
{
    return !(root->left) && !(root->right) ;
}


 void getHuffman(struct QueueNode* root,string val,  map<char,string> &answer)
{

    if (root->left)
    {
        getHuffman(root->left, val+"0",answer);
    }

    if (root->right)
    {
        getHuffman(root->right, val+"1",answer);
    }

    if (isLeaf(root))
    {
      cout << root->data << " " << val << endl;
      answer[root->data] = val;
    }

}
map<char,string> getHuffman(vector<char> characters, vector<int> frequencies)
{
    struct QueueNode * root = buildHuffmanTree(characters,frequencies);
    map<char,string> answer;
    getHuffman(root,"",answer);
    return answer;
}

int main ()
{
    test();
    return 0;
}
