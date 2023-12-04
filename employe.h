#ifndef EMPLOYE_H
#define EMPLOYE_H

#include <string>

class Employe {
    int IDemploye;
    std::string nom{};
    std::string contact{};
    std::string role{};
    int heures{};
    int performance{};
    static int nb_employes;

public:
    Employe(std::string _nom, std::string _contact="--", std::string _role="--", int _heures=0, int _performance=0);
    ~Employe();

    void set_contact(std::string);
    void set_role(std::string);
    void set_heures(int);
    void set_performance(int);

    void affiche_id();
    void affiche_employe();

    int getIDemploye() const;
    const std::string& getNom() const;
    const std::string& getContact() const;
    const std::string& getRole() const;
    int getHeures() const;
    int getPerformance() const;
};

#endif // EMPLOYE_H
