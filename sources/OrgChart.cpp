#include "OrgChart.hpp"

using namespace std;

namespace ariel{
    OrgChart& OrgChart::add_root(const std::string j){
       if(this->root == nullptr){
            string p = j;
            this->root = new Node{p};
            this->poses.push_back(j);
		}
        else{
            this->root->pos = j;
            this->poses.at(0) = j;
        }
        return *this;
    }
    OrgChart& OrgChart::add_sub(std::string j,std::string l){
            Node* p = find(j,this->root);
            if(p!=nullptr){
                (p->child).push_back(new Node(l,p));
                this->poses.push_back(l);
            }
            else{
                cout << "throw;" << endl;
                throw "parent not found";
            }
        return *this;
    }
    vector<string>::iterator OrgChart::begin(){

        return this->poses.begin();
    }
    vector<string>::iterator OrgChart::end(){

        return this->poses.end();
    }
    vector<string>::iterator OrgChart::begin_level_order(){
        // vector<string> jobs;
        // this->postord(this->root);
        // cout << endl;
        std::vector<std::vector<std::string>> n = this->levelOrder(this->root);
        vector<string> n1;
        for(unsigned long i = 0 ; i < n.size(); i++){
           for(unsigned long j = 0 ; j < n.at(i).size(); j++){
               n1.push_back(n.at(i).at(j));
           } 
        }
        // for(unsigned long i = 0 ; i < n1.size(); i++){
        //     cout << n1.at(i)+ " " ;
        // }
        // cout << n1.size() << " begin"<<endl;
        // cout << " begin";

        return this->poses.begin();
        //return n1.begin();
    }
    vector<string>::iterator OrgChart::end_level_order(){
        std::vector<std::vector<std::string>> n = this->levelOrder(this->root);
        std::vector<std::string> n1;
        for(unsigned long i = 0 ; i < n.size(); i++){
           for(unsigned long j = 0 ; j < n.at(i).size(); j++){
               n1.push_back(n.at(i).at(j));
           } 
        }
        // cout << n1.size() << " end"<<endl;
        return this->poses.end();
        // return n1.end();
    }
    vector<string>::iterator OrgChart::begin_reverse_order(){
        vector<string> jobs;

        // i.base
        return poses.begin();
    }
    vector<string>::iterator OrgChart::reverse_order(){
        vector<string> jobs;

        // i.base
        return poses.end();
    }
    vector<string>::iterator OrgChart::begin_preorder(){
        vector<string> jobs;

        // i.base
        return poses.begin();
    }
    vector<string>::iterator OrgChart::end_preorder(){
        vector<string> jobs;

        // i.base
        return poses.end();
    }
    ostream & operator<<(std::ostream & os, const OrgChart & self){
        // string rootset = "CEO";// = to_string(self.root);

        // string rootset = self.root->pos;
        // os << rootset;
        self.print_OrgChart(self.root,os);
        return os;
    }
}