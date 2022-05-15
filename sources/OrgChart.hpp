#ifndef ORGCHART_
#define ORGCHART_

#include <iostream>
#include <sstream>
#include <vector>
#include <fstream>
#include <sstream>
#include <bits/stdc++.h>
#include <stdexcept>

namespace ariel
{
    // template<typename T>
    class OrgChart
    {

    public:
        struct Node{
            Node *parent = nullptr;   //parent node
            std::vector<Node *> child;
            std::string pos;
            Node(std::string &po, Node *p = nullptr) : pos(po), parent(p){}
        };
        Node* find(std::string pos, Node* node){
				Node* ans = nullptr;          //the node holding the value
				if(node != nullptr){
                    if(node->pos == pos){ return node;}
                    for(unsigned long i = 0 ; i < node->child.size(); i++){
                       ans = find(pos, node->child.at(i));
                       if(ans) {return ans;}
                    }
				}
				return ans;
		}
        std::vector<std::string > poses;
        Node * root =nullptr;
        void print_OrgChart(Node *node, std::ostream& os , int spaces=0) const{ 
				if (node != nullptr){
                    spaces += 1;
                    for (int i = 1; i < spaces; i++){
                            os << "    "; 
                    } 
                    os << node->pos << '\n';
                    for(unsigned long i = 0; i < node->child.size(); i++){ 
                        print_OrgChart(node->child.at(i), os, spaces); 
			    	} 
                }
			}
            void postord(Node* root)
            {
                if (root == NULL)
                    return;
                for (unsigned long i = 0; i < root->child.size(); i++)
                    postord(root->child[i]);
                std::cout << root->pos << " ";
            }
            std::vector<std::vector<std::string>> levelOrder(Node* root) {
                std::vector<std::vector<std::string>> ans;
                if(!root){
                    return ans;
                }
                std::queue <Node*> q;
                q.push(root);
                while(!q.empty()){
                    int sz = q.size();
                    std::vector<std::string> temp;
                    while(sz--){
                        Node* curr = q.front();
                        temp.push_back(curr->pos);
                        q.pop();
                        for(unsigned long i = 0; i < curr->child.size(); i++){
                            q.push(curr->child.at(i));
                        }
                    }
                    ans.push_back(temp);
                }
                return ans;
            }
        OrgChart(){
            // this->root = nullptr;

        }
        // OrgChart<T>(OrgChart<T> &&bt) noexcept{     //move constructor
		// 		root = bt.root;
		// 		bt.root = nullptr;
		// 	}
        // ~OrgChart();
        OrgChart & add_root(const std::string j);
        OrgChart &add_sub(std::string j,std::string l);
        std::vector<std::string>::iterator begin();
        std::vector<std::string>::iterator end();
        std::vector<std::string>::iterator begin_level_order();
        std::vector<std::string>::iterator end_level_order();
        std::vector<std::string>::iterator begin_reverse_order();
        std::vector<std::string>::iterator reverse_order();
        std::vector<std::string>::iterator begin_preorder();
        std::vector<std::string>::iterator end_preorder();

        friend std::ostream & operator<<(std::ostream & os, const OrgChart & self);
    };
    
}
#endif