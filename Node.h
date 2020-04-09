#ifndef Node_H
#define Node_H

#define DEBUG

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Node
{
  private:
  static int id;
    std::string name;
    std::vector<Node*> children;
  public:

    /*  Konstruktor
        Übergabe des Namens als Referenz.
        Diese Art der Übergabe ist günstig, weil der Konstruktor
        nach der Übergabe auf dem originalen Objekt arbeitet.
        Das spart Speicherplatz, weil kein neues Objekt oder ein
        Pointer angelegt wird.
    */
    Node(const std::string& name = std::string());

    /*  Destruktor
        Der virtualle Destruktor sorgt dafür, dass auch bei Aufruf
        des delete Operators auf Objekten aus von Node abgeleiteten 
        Klassen zusätzlich dieser Destruktor aufgrufen wird.
    */
    virtual ~Node();

    /*  getName
        Das Schlüsselwort 'const' macht die Funktion Read-only.
        Die Funktion GetName darf die Attribute des Objektes nur
        lesen. Als 'const' deklarierte Funktionen können von
        anderen Funktionen aufgerufen werden. Nicht mit 'const'
        gekennzeichnete Funktionen können nur von anderen nicht
        mit 'const' gekennzeichneten Funktionen aufgerufen werden.
        Dieses Schlüsselwort ist hilfreich, da es Übersichtlichkeit
        schafft und versehentliche Änderungen von Attributen
        verhindert.
    */
    std::string getName() const;
    void setName(std::string& name);
    int getNrOfChildren() const;
    /*  getChild
        Gültige Werte sind gültige Indizes des children-vectors
        des Objekts. Der kleinste valide Wert ist 0 (bei einem 
        Kindknoten) und der größte die Anzahl der Kindknoten -1.
        Wird ein ungültiger Wert angegeben, löst die Funktion
        eine Exception aus.
    */
    Node* getChild(const int i) const;
    void addChild(Node* child);
    void createCompleteTree(int nrChildNodes, int treeDepth);
    void print(std::ostream &str, int depth) const;
    friend ostream& operator<<(ostream& os, Node& node);
};

#endif