#include "Consortium.h"

Consortium::Consortium():Company()
{

}
Consortium::Consortium(const char * name):Company(name)
{
}
Consortium::Consortium(const Consortium & other):Company(other)
{
	int contractorCount=other.contractors.capacity();
	this->contractors.resize(contractorCount);
	for (int i=0;i<other.contractors.size();i++)
	{
		this->contractors[i]=other.contractors[i]->copy();	
	}

}
void Consortium::addContractor(const Company & contractor)
{
	contractors.push_back(contractor.copy());
}
void Consortium::removeContractor(const Company & contractor)
{
	int contIdx=this->findContractorByName(contractor.getName());
	if (contIdx!=-1)
	{
		delete this->contractors[contIdx];
		this->contractors.erase(this->contractors.begin()+contIdx);
	}
}
void Consortium::printStatus()
{
	for (int i=0;i<this->contractors.size();i++)
	{
		cout<<contractors[i]->getName()<<" "<<contractors[i]->reliabilityRate()<<endl;
	}
}

int Consortium::findContractorByName(const char * name)
{
	for (int i=0;i<this->contractors.size();i++)
	{
		if (strcmp(contractors[i]->getName(),name)==0)
		{
			return i;
		}
	}
	return -1;
}

Consortium::~Consortium()
{
	for (int i=0;i<this->contractors.size();i++)
	{
		delete this->contractors[i];
	}
}

bool Consortium::perform(const char * project)
{
	if(contractors.size()==0)
	{
		cout<<"No contractors! Can't perform project "<<project<<endl;
	}
	this->totalProjects++;
	int minProjects=contractors[0]->getTotalProjects();
	int contIdx=0;
	for (int i=1;i<this->contractors.size();i++)
	{
		if (contractors[i]->getTotalProjects()<minProjects)
		{
			minProjects=contractors[i]->getTotalProjects();
			contIdx=i;
		}
	}
	if(contractors[contIdx]->perform(project))
		{
			this->successfulProjects++;
			return true;
		}
	return false;

}

ostream& operator<<(ostream& out, const Consortium& company)
{
	out << "consortium: "<< company.contractors.size() <<" "<< company.getName() << endl;

	for(int i=0;i<company.contractors.size();i++)
	{
		out<<company.contractors[i]->getName();
	}
	out << endl;

}
