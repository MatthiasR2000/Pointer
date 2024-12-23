#include <iostream>
#include <memory> // Für Smart Pointers
using namespace std;
/*
Zeiger in C++ sind wie Wegweiser, die auf die Adresse einer anderen Variable zeigen. 
Anstatt direkt mit dem Wert einer Variable zu arbeiten, kannst du mit einem Zeiger auf die Adresse zugreifen, an der der Wert gespeichert ist.

Das ist besonders nützlich, wenn du:

->Daten effizient bearbeiten möchtest, ohne sie zu kopieren.
->Elemente in einem Array direkt ansprechen möchtest.
->Variablen in einer Funktion ändern möchtest, ohne sie zurückzugeben.
->Zeiger sind ein wichtiges Konzept in Algorithmen und objektorientierter Programmierung. 
Aber Vorsicht: Ein falsch angewendeter Zeiger kann schnell zu Fehlern führen, wie Speicherlecks oder Programmabstürzen. Deshalb ist es wichtig, sorgfältig damit umzugehen.
*/

// Funktion zur Inkrementierung eines Wertes
void increment(int* ptr) {
    (*ptr)++;
}

int main() {
    // Zeiger auf eine normale Variable
    int x = 42;
    int* ptr = &x; // Adresse von x wird im Zeiger gespeichert

    cout << "Wert von x: " << x << endl;
    cout << "Adresse von x: " << &x << endl;
    cout << "Wert von ptr (Adresse von x): " << ptr << endl;
    cout << "Wert von *ptr (Inhalt von x) auch Dereferenzierung genannt: " << *ptr << endl;
    // Zeiger auf nullptr setzen
    ptr = nullptr; // Der Zeiger wird auf nullptr gesetzt, da er nicht mehr gebraucht wird
    cout << "Wert des Zeigers nach dem Setzen auf nullptr: " << ptr << endl;
    // Folgende Zeile würde zu einem Laufzeitfehler führen, da der Zeiger auf nullptr zeigt
    // cout << "Wert des Zeigers nach dem Setzen auf nullptr mit Dereferenzierung: " << *ptr << endl;


    cout << "\nZeigerarithmetik" << endl;
    // Zeigerarithmetik mit Arrays
    int arr[3] = { 10, 20, 30 };
    ptr = arr; // Zeiger auf das erste Element des Arrays
    cout << "\nErstes Element: " << *ptr << endl; // 10
    ptr++; // Zeiger zeigt auf das nächste Element
    cout << "Durch ptr++ jetzt das zweite Element: " << *ptr << endl; // 20


    cout << "\nZeiger auf Zeiger" << endl;
    int** ptr_to_ptr = &ptr;
    cout << "Wert von **ptr_to_ptr: " << **ptr_to_ptr << endl; // 20


    cout << "\nDynamische Speicherverwaltung" << endl;
    int* dynamic_ptr = new int(42); // Dynamischen Speicher auf dem Heap für einen int-Wert anlegen und initialisieren
    cout << "Wert von dynamic_ptr: " << *dynamic_ptr << endl; // 42
    delete dynamic_ptr; // Speicher freigeben
    dynamic_ptr = nullptr; // Zeiger auf nullptr setzen


    cout << "\nSmart Pointer" << endl;
    std::unique_ptr<int> smart_ptr = std::make_unique<int>(42);
    cout << "Wert von smart_ptr: " << *smart_ptr << endl; // 42
    // Speicher wird automatisch freigegeben, wenn smart_ptr aus dem Gültigkeitsbereich fällt


    cout << "Funktion die ein Zeiger inkrementiert/erhöht" << endl;
    increment(&x);
    cout << "Wert von x nach Inkrementierung: " << x << endl; // 43

    return 0;
}
