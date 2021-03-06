#include <iostream>
#include <cmath>
#include "Ellipse.hpp"

Ellipse::Ellipse(ulong color, int thick, bool remplir, uint x, uint y, uint _demiHauteur, uint _demiLargeur)
	: Forme(color, thick, remplir, x, y), demiHauteur(_demiHauteur), demiLargeur(_demiLargeur)
{}

Ellipse::Ellipse(istream &is)
	: Forme(is), demiHauteur(0), demiLargeur(0)
{
    bool _thickness = false;
	uint _remplir = 0;
    is >> demiHauteur >> demiLargeur >> _thickness >> _remplir;
	setThickness(_thickness);
	setRemplir(_remplir);
}

Ellipse::~Ellipse()
{}

double Ellipse::perimetre() const
{
	return ((2*3.14159265359)*sqrt(0.5*(((demiHauteur/2)*(demiHauteur/2))+((demiLargeur/2)*(demiLargeur/2)))));
}

void Ellipse::dessiner(EZWindow &w/*, bool isActive*/) const
{
	Forme::dessiner(w);
	Point ancre = getAncre();
	uint _x = ancre.getx();
	uint _y = ancre.gety();
	if(getRemplir()) w.fillCircle(_x-demiLargeur, _y-demiHauteur, _x+demiLargeur, _y+demiHauteur);
	else w.drawCircle(_x-demiLargeur, _y-demiHauteur, _x+demiLargeur, _y+demiHauteur);
}

void Ellipse::ecrire(ostream &os) const
{
	os << "Ellipse " << getCouleur() << " " << getAncre().getx() << " " << getAncre().gety() << " " << demiHauteur << " " << demiLargeur;
}
