#include <iostream>
#include <iomanip>
#include <limits>

using namespace std;

void tregobalancin(double bilanci);
double deposit();
double terhek(double bilanci);
bool verifyPin(int enteredPin, int correctPin)
{
    return enteredPin == correctPin;
}

 
int main()
{
 double bilanci = 0;
 int zgjedh = 0;
 int correctPin = 1234;
    int enteredPin;
       

    do 
    {
        cout << "Ju lutem shkruani PIN kodin tuaj: ";
        cin >> enteredPin;

        if (!verifyPin(enteredPin, correctPin)) 
        {
            std::cout << "PIN-i eshte i gabuar. Provojeni perseri." << endl;

            cin.clear();                                                  // buffer clearing
            cin.ignore(std::numeric_limits<streamsize>::max(), '\n');     // buffer clearing
        }

    } while (!verifyPin(enteredPin, correctPin));

    cout << "PIN-i eshte i sakte. Ju jeni te kyqur!" << endl;
    cout << '\n';

    

 do { 
    
 cout << "******************************\n";
 cout << "Vendos zgjedhjen tende : \n"; 
 cout << "******************************\n";
 cout << "1.Trego bilancin\n";
 cout << "2.Deposito fonde\n";
 cout << "3.Terhek fonde\n";
 cout << "4.Exit\n";
 cin >> zgjedh;

 switch(zgjedh)
 {
    case 1: tregobalancin(bilanci);
             break;

    case 2: bilanci += deposit();
            tregobalancin(bilanci);
             break;

    case 3: bilanci -= terhek(bilanci);
            tregobalancin(bilanci);
             break; 
    
    case 4: cout << "Faleminderit per viziten!\n";
             break;
    deafult : cout << "Zgjedhje gabuar\n"; 
    cin >> zgjedh;
 
 }

 } while (zgjedh != 4);

 return 0;

}


void tregobalancin(double bilanci)
{ 
 cout <<  "Balanci juaj eshte : $" <<  setprecision(2) << fixed << bilanci << '\n';
}
    double deposit()
   {
    double shuma = 0;
    cout << "Jep shumen per depozim : ";
    cin >> shuma;
      
      if (shuma > 0)
      {
       return shuma;
      }
         else 
         {
         cout << "Shuma jo valide !";
         return 0;
         }
   } 

    double terhek(double bilanci)
    {
        double shuma = 0;
        cout << "jep shumen per terheqje : ";
        cin >> shuma;
        
        if (shuma > bilanci)
        {
            cout << "Nuk keni mjete te mjaftueshme !";
            return 0;
        }
            else if (shuma < 0)
            {
             cout << "Shuma jo valide\n";
              return 0;
            } 
               else 
               {
                 return shuma;
               }
    }    