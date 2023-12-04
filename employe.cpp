#include "employe.h"

#include "employe.h"
#include <iostream>

int Employe::nb_employes = 0;

Employe::Employe(std::string _nom, std::string _contact, std::string _role, int _heures, int _performance)
    : nom(_nom), contact(_contact), role(_role), heures(_heures), performance(_performance) {
    IDemploye = ++nb_employes;
}

Employe::~Employe() {
    nb_employes--;
}

void Employe::set_contact(std::string _contact) {
    contact = _contact;
}

void Employe::set_role(std::string _role) {
    role = _role;
}

void Employe::set_heures(int _heures) {
    heures = _heures;
}

void Employe::set_performance(int _performance) {
    performance = _performance;
}

void Employe::affiche_id() {
    std::cout << "Employee ID: " << IDemploye << std::endl;
}

void Employe::affiche_employe() {
    std::cout << "Name: " << nom << std::endl;
    std::cout << "Contact: " << contact << std::endl;
    std::cout << "Role: " << role << std::endl;
    std::cout << "Hours: " << heures << std::endl;
    std::cout << "Performance: " << performance << std::endl;
}

int Employe::getIDemploye() const {
    return IDemploye;
}

const std::string& Employe::getNom() const {
    return nom;
}

const std::string& Employe::getContact() const {
    return contact;
}

const std::string& Employe::getRole() const {
    return role;
}

int Employe::getHeures() const {
    return heures;
}

int Employe::getPerformance() const {
    return performance;
}
