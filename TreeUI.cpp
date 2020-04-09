/**
  @file    TreeUI.cpp
  @author  Frieder Keilholz
  @date    29.03.2020 - 09.04.2020
  @brief   Enthält main. Erstellt Bäume unter Nutzung der Node Klasse.
*/

#include "Node.h"
#include <string>
#include <iostream>

using namespace std;

int main()
{
    std::string name = "root";
    Node* root1 = new Node(name);    
    name = "left child";
    Node* left_child = new Node(name);
    root1->addChild(left_child);
    name = "right child";
    Node* right_child = new Node(name);
    root1->addChild(right_child);
    delete root1;
    /*  Die nach Aufruf des delete Operators entstehende 
        Ausgabe zeigt das rekursive Löschen der Kindknoten.
        Der Destruktor des root-Nodes geht alle zwei Kind-
        knoten durch und ruft deren Destruktoren über den
        delete Operator auf.
        Der rekursive Abstieg endet, wenn ein Node keinen
        Kindknoten mehr hat.
        Erst wenn alle Kindknoten der Kindknoten des root-
        Nodes gelöscht sind wird der Destruktor des root-
        Nodes verlassen.
    */


    Node* root = new Node();
    try{
        root->createCompleteTree(2,4);
        root->createCompleteTree(2,-1);
    }catch (const char* msg){
        cout << "An error occured: " << msg << endl;
    }
    //root->print(cout, 0);
    cout << *root;
    delete root;
    return 0;
}