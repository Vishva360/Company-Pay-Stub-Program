#include "person.cpp"
#include <vector>
#include <string>
#include <fstream>
#include <iomanip>

void readData(vector<Person> &employee);
void getCompanies(vector<Person> &employee, vector<string> &companyNames);
void printHighestPaid(vector<Person> &employee);
void seperateAndSave(vector<Person> &employee, vector<string> &companyNames);
int main(){

vector<Person> employee;
vector<string> companyNames;
fstream inData;

readData(employee);
getCompanies(employee, companyNames);
printHighestPaid(employee);
seperateAndSave(employee, companyNames);
}


void readData(vector<Person> &employee){

fstream inData;
  inData.open("input.txt", ios::in);

  string fName, lName, coName;
  int id;
  float hours, rate;
  Person emp;


      while(inData >> fName >> lName >> id >> coName >> hours >> rate){

          emp.setFirstName(fName);
          emp.setLastName(lName);
          emp.setEmployeeId(id);
          emp.setCompanyName(coName);
          emp.setHoursWorked(hours);
          emp.setPayRate(rate);

        employee.push_back(emp);
  }

  inData.close();
}
void getCompanies(vector<Person> &employee, vector<string> &companyNames){
  for(int i = 0; i < employee.size(); i++){
    bool different = true;
    if(companyNames.empty()){
      companyNames.push_back(employee.at(i).getCompanyName());
    }
    for(int j = 0; j < companyNames.size(); j++){

      if(companyNames.at(j) != employee.at(i).getCompanyName()){
        different = true;
      }
      else{
        different = false;
        break;
      }
}
    if(different == true){
      companyNames.push_back(employee.at(i).getCompanyName());
    }

  }

}
void printHighestPaid(vector<Person> &employee){


Person highest = employee[0];
for(int i = 1; i < employee.size();i++){
  if(employee[i].totalPay() > employee[i-1].totalPay())
  {
    highest = employee[i];
  }
}
  cout << "Highest Paid:\t" << highest.fullName() << endl << "Employee ID:\t " << highest.getEmployeeId()<< endl << "Employer:\t" << highest.getCompanyName() << endl<< "Total Pay: \t$" <<highest.totalPay() << endl;
}

void seperateAndSave(vector<Person> &employee, vector<string> &companyNames){
float total = 0;

ofstream data;

      data.open("Intel.txt", ios::in);
for(int i = 0; i < employee.size(); i++){
  if(employee[i].getCompanyName() == companyNames[0]){

      data << setw(20) << left <<employee[i].fullName() << " " << setw(5) << employee[i].getEmployeeId() << " " << setw(10) << employee[i].getCompanyName() << " $" << setprecision(6) << employee[i].totalPay() << endl;
      total += employee[i].totalPay();

  }
}
data << "Total\t$" << setprecision(6) << total << endl;
total = total - total;
  data.close();
  ///////////////////////////////////////////////
    data.open("Boeing.txt", ios::in);

for(int i = 0; i < employee.size(); i++){
  if(employee[i].getCompanyName() == companyNames[1]){

      data << setw(20) << employee[i].fullName() << " " << setw(5) << employee[i].getEmployeeId() << " " << setw(10) << employee[i].getCompanyName() << " $" << setprecision(6) << employee[i].totalPay() << endl;
      total += employee[i].totalPay();
  }
}
data << "Total\t$" << setprecision(6) << total << endl;
total = total - total;

data.close();
//////////////////////////////////////////////////
  data.open("Douglas.txt", ios::in);
for(int i = 0; i < employee.size(); i++){
  if(employee[i].getCompanyName() == companyNames[2]){

      data << setw(20) << employee[i].fullName() << " " << setw(5) << employee[i].getEmployeeId() << " " << setw(10) << employee[i].getCompanyName() << " $" << setprecision(6) << employee[i].totalPay() << endl;
      total += employee[i].totalPay();
  }
}
data << "Total\t$" << setprecision(6) << total << endl;
total = total - total;
data.close();
//////////////////////////////////////////////////
data.open("Raytheon.txt", ios::in);
for(int i = 0; i < employee.size(); i++){
  if(employee[i].getCompanyName() == companyNames[3]){

    data << setw(20) << employee[i].fullName() << " " << setw(5) << employee[i].getEmployeeId() << " " << setw(10) << employee[i].getCompanyName() << " $" << setprecision(6) << employee[i].totalPay() << endl;
    total += employee[i].totalPay();
  }
}
data << "Total\t$" << setprecision(6) << total << endl;
total = total - total;
data.close();
//////////////////////////////////////////////////
data.open("HealthTech.txt", ios::in);
for(int i = 0; i < employee.size(); i++){
  if(employee[i].getCompanyName() == companyNames[4]){

    data << setw(20) << employee[i].fullName() << " " << setw(5) << employee[i].getEmployeeId() << " " << setw(10) << employee[i].getCompanyName() << " $"  << setprecision(6) << employee[i].totalPay() << endl;
    total += employee[i].totalPay();
  }
}
data << "Total\t$" << setprecision(6) << total << endl;
total = total - total;
data.close();

}
