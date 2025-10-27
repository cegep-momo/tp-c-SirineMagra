#include <sstream>

#include "book.h"

using namespace std;

//constructeur par defaut
Book::Book() : title(""), author(""),isbn(""){}

//constructeur avec parametres
Book::Book(const string& title, const string& author, const string& isbn)
: title(title), author(author),isbn(isbn){}

//gettters
string Book::getTitle() const {return title;}
string Book::getAuthor() const {return author;}
string Book::getISBN() const {return isbn;}
bool Book::getAvailability() const {return isAvailable;}
string Book::getBorrowerName() const {return borrowerName;}

//setters
void Book::setTitle(const string& title){this->title = title;}
void Book::setAuthor(const string& author){this->author = author;}
void Book::setISBN(const string& isbn){this->isbn = isbn;}
void Book::setAvailability(bool available){this->isAvailable = available;}
void Book::setBorrowerName(const string& name){this->borrowerName = name;}

//méthodes

//emprunt d'un livre
void Book::checkOut(const string& borrower){
    this->borrowerName = borrower;
    this->isAvailable = 0;
}

//retour d'un livre
void Book::returnBook(){
    this->borrowerName= "";
    this->isAvailable = 1;
}

//affichage des infos du livre
string Book::toString() const{
    string affichage ="Titre : "+title+"\nAutheur : "+author+"\nISBN : "+isbn;

    if(borrowerName!=""){
        affichage+="\nIndisponible";
    }else{
        affichage+="\nDisponible";
    }

    return affichage;
}

//retourne sous format fichier 
string Book::toFileFormat() const{
    string fichier =title+"|"+author+"|"+isbn+"|";

    fichier +=isAvailable+"|";

    if(!isAvailable){
        fichier+=borrowerName+"|";
    }

    return fichier;
}

//récupère les infos d'un fichier
void Book::fromFileFormat(const string& line){
    stringstream ss(line);
    string available="";

    getline(ss,title,'|');
    getline(ss,author,'|');
    getline(ss,isbn,'|');
    getline(ss,available,'|');

    if(available=="0"){
        isAvailable=0;
    }else{
        isAvailable=1;
    }

    if(available=="0"){
        getline(ss,borrowerName,'|');
    }
}