/*
 
						"LESCO WAPDA MANAGEMENT SYSTEM"

			Group: Binary Beasts
			Group Members: Muhammad Anas , Ali Ahmad,
			               Mustafa Hassan, Abdur Rafay

*/
#pragma once
#include<iostream>
#include <string>
#include<fstream>
#include <ctime>
#include <sstream>
using namespace std;


class Record_Registereduser;
class LESCOWORKERS;
class BillSystem;
class _WapdaLESCO;

class HelperFunction
{

public:
	static int StringLenght(char* str)
	{
		int stringLen = 0;
		for (char* temp = str; *temp != '\0'; temp++)
			stringLen++;

		return stringLen;

	}
	static char* GetStringFromBuffer(char* buffer)
	{

		int strLen = StringLenght(buffer);
		char* str = 0;

		if (strLen > 0)
		{
			str = new char[strLen + 1];
			char* tempDest = str;
			for (char* tempSrc = buffer; *tempSrc != '\0'; tempSrc++, tempDest++)
			{
				*tempDest = *tempSrc;
			}
			*tempDest = '\0';
		}
		return str;
	}

	static void _DateValidation(int  year, int  month, int date)
	{
		bool validDate = false;
		int count = 0;
		if (year > 999 && year <= 9999)
		{
			if (month <= 12)
			{
				if (date <= 31)
				{
					validDate = true;
				}
				else validDate = false;
			}

		}

		if (validDate == true)
		{
			return;
		}
		else
		{
			cout << "Incorrect Data! Please Press again:\n";
			cin >> year >> month >> date;
			_DateValidation(year, month, date);
		}


	}
};



class Record_Registereduser
{
	string ContactNumber;
	string ResidentialAddress;
	int _RegistereduserType;
	int ConnectionMeter;
	string DateOfConnection;
	int Units_Regular;
	int Units_peaks;
	BillSystem** BillingSystem;
	int TotalBillingSystem;
	string _RegistereduserName;
	int Unique_RegistereduserId;
	string DOB;

public:
	Record_Registereduser();
	int To_Get_MeterReading()
	{
		return ConnectionMeter;
	}
	int To_Get__Registereduser_Type()
	{
		return _RegistereduserType;
	}

	int To_Get_PeaksUnit()
	{
		return Units_peaks;
	}
	int GetId()
	{
		return Unique_RegistereduserId;
	}
	int To_Get_RegUnits()
	{
		return Units_Regular;
	}


	void Read_File_Data(ifstream&); // Loading The Data from FIles
	void _PresentSituation();
	void TotalUnit(); // Total Units
	void _Get_RecordOfUser();
	void Save(ofstream&);
	bool ValidationCheck(int, string);
	void SetBillSystem(BillSystem*);
	void UpdateInfo();
};
class LESCOWORKERS
{
	string _RegistereduserName;
	string Password;
public:
	LESCOWORKERS();
	void Read_File_Data(ifstream&);
	void InputLESCOWORKERSData(string, string);
	void Save(ofstream&);
	bool ValidationCheck(string, string);
	void ChangeStatus();
};



void LESCOWORKERS::Read_File_Data(ifstream& inputLESCOWORKERS)
{
	string temp;
	int count = 0;

	getline(inputLESCOWORKERS, _RegistereduserName, ',');
	getline(inputLESCOWORKERS, Password);
}
LESCOWORKERS::LESCOWORKERS()
{
	_RegistereduserName = "0";
	Password = "0";
}

void LESCOWORKERS::InputLESCOWORKERSData(string Name, string Pass)
{

	_RegistereduserName = Name;
	Password = Pass;
}



bool LESCOWORKERS::ValidationCheck(string name, string pass)
{
	if ((name == _RegistereduserName && Password == pass))
		return true;
	return false;

}
void LESCOWORKERS::Save(ofstream& OutputLESCOWORKERS)
{
	OutputLESCOWORKERS << _RegistereduserName << ",";
	OutputLESCOWORKERS << Password << endl;
}

void Record_Registereduser::Read_File_Data(ifstream& Input_UserRecord)
{
	string y, m, d;
	char _skip;
	Input_UserRecord >> Unique_RegistereduserId;
	Input_UserRecord >> _skip;
	getline(Input_UserRecord, DOB, ',');
	getline(Input_UserRecord, _RegistereduserName, ',');
	getline(Input_UserRecord, ResidentialAddress, ',');
	getline(Input_UserRecord, ContactNumber, ',');
	Input_UserRecord >> _RegistereduserType;
	Input_UserRecord >> _skip;
	Input_UserRecord >> ConnectionMeter;
	Input_UserRecord >> _skip;
	getline(Input_UserRecord, DateOfConnection, ',');
	Input_UserRecord >> Units_Regular;
	Input_UserRecord >> _skip;
	Input_UserRecord >> Units_peaks;

}
Record_Registereduser::Record_Registereduser()
{
	DateOfConnection = "";
	_RegistereduserType = 0;
	ConnectionMeter = 0;
	Units_Regular = 0;
	Units_peaks = NULL;
	BillingSystem = 0;
	TotalBillingSystem = 0;
	_RegistereduserName = "";
	Unique_RegistereduserId = 0;
	ContactNumber = "";
	ResidentialAddress = "";
	DOB = "";

}


void Record_Registereduser::Save(ofstream& _out_Record)
{
	_out_Record << Unique_RegistereduserId << ",";
	_out_Record << DOB << ",";
	_out_Record << _RegistereduserName << ",";
	_out_Record << ResidentialAddress << " ,";
	_out_Record << ContactNumber << ",";
	_out_Record << _RegistereduserType << ",";
	_out_Record << ConnectionMeter << ",";
	_out_Record << DateOfConnection << ",";
	_out_Record << Units_Regular << "," << Units_peaks << endl;
}
void Record_Registereduser::_Get_RecordOfUser()
{
	string _tmpYear, _tmpMonth, _tmpDay;
	int Year, Month, Day, Valid = 0;
	Unique_RegistereduserId = rand() % 9000 + 1000;

	cout << "Please Press Name:\t";
	getline(cin, _RegistereduserName);

	cout << "\nPlease Press User Phone number:\t";
	getline(cin, ContactNumber);

	cout << "\nPress Press Residential Address:\t";
	getline(cin, ResidentialAddress);

	cout << "\n Please Press Record User's date of birth in the format YYYYMMDD :\t";
	cin >> Year >> Month >> Day;
	HelperFunction::_DateValidation(Year, Month, Day);
	_tmpYear = to_string(Year);    // Converts a signed integer to a string 
	_tmpMonth = to_string(Month);  // Converts a signed integer to a string 
	_tmpDay = to_string(Day);      // Converts a signed integer to a string 
	if (Month < 10 && Day < 10)
	{
		DOB = _tmpYear + '0' + _tmpMonth + '0' + _tmpDay;
	}
	else
		DOB = _tmpYear + _tmpMonth + _tmpDay;
	if (Month < 10 && Day>9)
		DOB = _tmpYear + '0' + _tmpMonth + _tmpDay;
	if (Day < 10 && Month>9)
		DOB = _tmpYear + _tmpMonth + '0' + _tmpDay;


	cout << "\n Please Select Your Customer type - 1 for Commercial Or Press-- 2 For Domestic :\t";
	cin >> _RegistereduserType;

	int count = 0;
	cout << "\nPlease Select Your Meter Type 1 for Single phase , 3 for Three Phase : \t";
	cin >> ConnectionMeter;
	while (count < 2 && Valid != true)
	{
		if (ConnectionMeter == 1 || ConnectionMeter == 3)
		{
			Valid = true;
			break;
		}
		else
		{
			cout << "Meter type is not Incorrect ! \n Please Press 1 for Single Phase Meter and 3 for three phase meter\n";
			cin >> ConnectionMeter;
			count++;
			Valid = false;
		}

	}

	if (Valid == true)
	{
		cout << "\n Please Select Connection Date in this format (YYYYMMDD):\t";
		cin >> Year >> Month >> Day;
		HelperFunction::_DateValidation(Year, Month, Day);
		_tmpYear = to_string(Year); // converts a signed integer to a string
		_tmpMonth = to_string(Month); // Converts a signed integer to a string 
		_tmpDay = to_string(Day);
		if (Month < 10 && Day < 10)
		{
			DateOfConnection = _tmpYear + '0' + _tmpMonth + '0' + _tmpDay;
		}
		else
			DateOfConnection = _tmpYear + _tmpMonth + _tmpDay;
		if (Month < 10 && Day>9)
			DateOfConnection = _tmpYear + '0' + _tmpMonth + _tmpDay;
		if (Day < 10 && Month>9)
			DateOfConnection = _tmpYear + _tmpMonth + '0' + _tmpDay;

		if (ConnectionMeter == 1)
		{
			cout << "\nPlease Press the Regular units to be consumed:\t";
			cin >> Units_Regular;
			cout << endl;
		}
		else
			if (ConnectionMeter == 3)
			{
				cout << "\nPlease Select the Regular units which is consumed:\t";
				cin >> Units_Regular;
				cout << endl;

				cout << "\nPlease Select the Peak Hour units consumed:\t";
				cin >> Units_peaks;
				cout << endl;
			}
		cout << "You are sucessfully registered \n";
		cout << "Press customer id is " << " \"" << Unique_RegistereduserId << "\" \n";
	}
	else
	{
		cout << "Alas! you cannot be registered. Please Try again later.Bye bye";
	}
}

bool Record_Registereduser::ValidationCheck(int _id, string dob)
{
	if ((_id == Unique_RegistereduserId && dob == DOB))
		return true;
	return false;

}
void Record_Registereduser::SetBillSystem(BillSystem* _user)
{
	if (BillingSystem == 0)
	{
		BillingSystem = new BillSystem * [10];
	}
	BillingSystem[TotalBillingSystem] = _user;
	BillingSystem[TotalBillingSystem + 1] = 0;
	TotalBillingSystem++;
}
void Record_Registereduser::UpdateInfo()
{
	int Option;
	cout << "Please Press 1 to Update All the Pressies belonging to this unique Customer id\n"
		<< "Please Press 2 2 to Update Particular User's Information\n";

	cin >> Option;

	if (Option == 1)
	{
		cin.ignore();
		_Get_RecordOfUser();
	}
	if (Option == 2)
	{
		int choice;
		system("cls");
		cout << "Press 1 to Update _RegistereduserName \n"
			<< "Press 2 to Update Phone Number\n"
			<< " Press 3 to update ResidentialAddress\n"
			<< "Press 4 to update DOB\n"
			<< "Press 5 to Update Customer Type\n"
			<< "Press 6 to Update Meter Type\n"
			<< "Press 7 to Update Regular units consumed\n"
			<< "Press 8 to Update Units consumed in Peak hour\n";

		cin >> choice;

		if (choice == 1)
		{
			cin.ignore();
			cin >> _RegistereduserName;
		}
		if (choice == 2)
		{
			cin.ignore();
			getline(cin, ContactNumber);
		}
		if (choice == 3)
		{
			cin.ignore();
			getline(cin, ResidentialAddress);
		}
		if (choice == 4)
		{
			cin.ignore();
			int Year, Month, Day;
			cin >> Year >> Month >> Day;
			HelperFunction::_DateValidation(Year, Month, Day);
			string _tmpYear = to_string(Year);
			string _tmpMonth = to_string(Month);
			string _tmpDay = to_string(Day);

			if (Month < 10 && Day < 10)
			{
				DOB = _tmpYear + '0' + _tmpMonth + '0' + _tmpDay;
			}
			else
				DOB = _tmpYear + _tmpMonth + _tmpDay;
			if (Month < 10 && Day>9)
				DOB = _tmpYear + '0' + _tmpMonth + _tmpDay;
			if (Day < 10 && Month>9)
				DOB = _tmpYear + _tmpMonth + '0' + _tmpDay;

		}
		if (choice == 5)
		{
			cin.ignore();
			cin >> _RegistereduserType;
		}
		if (choice == 6)
		{
			cin.ignore();
			cin >> ConnectionMeter;
		}
		if (choice == 7)
		{
			cin.ignore();
			cin >> Units_Regular;
		}
		if (choice == 8)
		{
			cin.ignore();
			cin >> Units_peaks;
		}
	}
}

class BillSystem
{
	string IssueDate;
	int Energy_Cost;
	int Taxing_Sale;
	int amount_Fixed_Charges;
	int TBillSystem;
	Record_Registereduser* _Registereduser;
	int Unique_RegistereduserId;
	int BillSystemMonth;
	int Peak_Meter_Reading;
	int Regular_Meter_Reading;

	string _LDueDate;
	bool BillSystemPaidStatus;
	string BillSystemPayementDate;
public:
	BillSystem();
	void DomesticPhase3Bill(int, int, int, int, int, int);
	void CommercialPhase1Bill(int, int, int, int);
	int GetId();
	void Set_Registereduser(Record_Registereduser*);
	void BillGenerator(int, int, int, int, int, int, int, int, int, int[], int[]);
	void DisplayBill();
	void Read_File_Data(ifstream&);
	void SaveBillSystemInFile(ofstream&);
	void DomesticPhase1Bill(int, int, int, int);
	void CommercialPhase3Bill(int, int, int, int, int, int);


};

BillSystem::BillSystem()
{
	Unique_RegistereduserId = 0;
	BillSystemMonth = 0;
	Peak_Meter_Reading = 0;
	Regular_Meter_Reading = 0;
	IssueDate = "";
	Energy_Cost = 0;
	Taxing_Sale = 0;
	amount_Fixed_Charges = 0;
	TBillSystem = 0;
	_LDueDate = "";
	BillSystemPaidStatus = 0;
	BillSystemPayementDate = "";
}

int BillSystem::GetId()
{
	return Unique_RegistereduserId;
}
void BillSystem::Read_File_Data(ifstream& innBillSystem)
{
	char _skip;
	innBillSystem >> Unique_RegistereduserId;
	innBillSystem >> _skip;
	innBillSystem >> BillSystemMonth;
	innBillSystem >> _skip;
	innBillSystem >> Peak_Meter_Reading;
	innBillSystem >> _skip;
	innBillSystem >> Regular_Meter_Reading;
	innBillSystem >> _skip;
	getline(innBillSystem, IssueDate, ',');
	innBillSystem >> Energy_Cost;
	innBillSystem >> _skip;
	innBillSystem >> Taxing_Sale;
	innBillSystem >> _skip;
	innBillSystem >> amount_Fixed_Charges;
	innBillSystem >> _skip;
	innBillSystem >> TBillSystem;
	innBillSystem >> _skip;
	getline(innBillSystem, _LDueDate, ',');
	innBillSystem >> BillSystemPaidStatus;
	innBillSystem >> _skip;
	getline(innBillSystem, BillSystemPayementDate, '\n');
}
void BillSystem::Set_Registereduser(Record_Registereduser* Record_Registereduser)
{
	_Registereduser = Record_Registereduser;
}

void BillSystem::BillGenerator(int id, int ConnectionMeter, int _RegistereduserType, int regUnit, int PeakUnit, int taxDomestic, int taxCommercial
	, int amount_Fixed_ChargesDomestic, int amount_Fixed_ChargesCommercial, int RegUnitPrice[4], int PeakUnitPrice[4])
{
	Unique_RegistereduserId = id;
	int Year, Month, Day;
	string _tmpYear, _tmpMonth, _tmpDay;
	cout << "Press Bill  Month: ";cin >> BillSystemMonth;
	if (ConnectionMeter == 3)
	{
		cout << "Please Press Peak Meter Reading : ";
		cin >> Peak_Meter_Reading;
	}
	cout << "Please Press the Meter Reading REGULAR : ";
	cin >> Regular_Meter_Reading;
	cout << "\nPlease Pressing the Issue Date of BillSystem in the format YYYY MM DD :\t";
	cin >> Year >> Month >> Day;
	HelperFunction::_DateValidation(Year, Month, Day);
	_tmpYear = to_string(Year);
	_tmpMonth = to_string(Month);
	_tmpDay = to_string(Day);
	if (Month < 10 && Day < 10)
	{
		IssueDate = _tmpYear + '0' + _tmpMonth + '0' + _tmpDay;
	}
	else
		IssueDate = _tmpYear + _tmpMonth + _tmpDay;
	if (Month < 10 && Day>9)
		IssueDate = _tmpYear + '0' + _tmpMonth + _tmpDay;
	if (Day < 10 && Month>9)
		IssueDate = _tmpYear + _tmpMonth + '0' + _tmpDay;


	cout << "\nPress the Due Date of BillSystem in the following format YYYY MM DD :\t";
	cin >> Year >> Month >> Day;
	HelperFunction::_DateValidation(Year, Month, Day);
	_tmpYear = to_string(Year);
	_tmpMonth = to_string(Month);
	_tmpDay = to_string(Day);
	if (Month < 10 && Day < 10)
	{
		_LDueDate = _tmpYear + '0' + _tmpMonth + '0' + _tmpDay;
	}
	else
		_LDueDate = _tmpYear + _tmpMonth + _tmpDay;
	if (Month < 10 && Day>9)
		_LDueDate = _tmpYear + '0' + _tmpMonth + _tmpDay;
	if (Day < 10 && Month>9)
		_LDueDate = _tmpYear + _tmpMonth + '0' + _tmpDay;


	if (ConnectionMeter == 1 && _RegistereduserType == 2)
		DomesticPhase1Bill(regUnit, taxDomestic, RegUnitPrice[0], amount_Fixed_ChargesDomestic);
	if (ConnectionMeter == 3 && _RegistereduserType == 2)
		DomesticPhase3Bill(regUnit, PeakUnit, taxDomestic, RegUnitPrice[2], amount_Fixed_ChargesDomestic, PeakUnitPrice[2]);
	if (ConnectionMeter == 1 && _RegistereduserType == 1)
		CommercialPhase1Bill(regUnit, taxCommercial, RegUnitPrice[1], amount_Fixed_ChargesCommercial);
	if (ConnectionMeter == 3 && _RegistereduserType == 1)
		CommercialPhase3Bill(regUnit, PeakUnit, taxCommercial, RegUnitPrice[3], amount_Fixed_ChargesCommercial, PeakUnitPrice[3]);

	cout << "The Bill System has been Generated Successfully!" << endl;
}
void BillSystem::DomesticPhase1Bill(int regUnit, int taxdomestic, int regUnitPrice, int fixedChargeDomestic)
{
	int cost;
	if (regUnit)
	{
		cost = regUnit - Regular_Meter_Reading;
	}
	else
		cost = Regular_Meter_Reading;
	cost = cost * regUnitPrice;
	Energy_Cost = cost;
	Taxing_Sale = taxdomestic;
	cost = (cost * taxdomestic) / 100;
	amount_Fixed_Charges = fixedChargeDomestic;
	cost = cost + fixedChargeDomestic;
	TBillSystem = cost;
	return;
}
void BillSystem::DomesticPhase3Bill(int regUnit, int PeakUnit, int taxdomestic, int regUnitPrice, int fixedChargeDomestic, int PeakUnitPrice)
{
	int cost, peakCost;
	if (regUnit)
	{
		cost = regUnit - Regular_Meter_Reading;
	}
	else
		cost = Regular_Meter_Reading;
	if (PeakUnit)
	{
		peakCost = PeakUnit - Peak_Meter_Reading;
	}
	else
	{
		peakCost = Peak_Meter_Reading;
	}

	cost = cost * regUnitPrice;
	peakCost = peakCost * PeakUnitPrice;
	cost = cost + peakCost;
	Energy_Cost = cost;
	cost = (cost * taxdomestic) / 100;
	Taxing_Sale = taxdomestic;
	cost = cost + fixedChargeDomestic;
	amount_Fixed_Charges = fixedChargeDomestic;
	TBillSystem = cost;
	return;
}
void BillSystem::CommercialPhase3Bill(int regUnit, int PeakUnit, int taxCommercial, int regUnitPrice, int fixedChargeCommercial, int PeakUnitPrice)
{
	int cost, peakCost;
	if (regUnit)
	{
		cost = regUnit - Regular_Meter_Reading;
	}
	else
		cost = Regular_Meter_Reading;
	if (PeakUnit)
	{
		peakCost = PeakUnit - Peak_Meter_Reading;
	}
	else
	{
		peakCost = Peak_Meter_Reading;
	}
	cost = cost * regUnitPrice;
	peakCost = peakCost * PeakUnitPrice;
	cost = peakCost + cost;
	Energy_Cost = cost;
	cost = (cost * taxCommercial) / 100;
	Taxing_Sale = taxCommercial;
	cost = cost + fixedChargeCommercial;
	amount_Fixed_Charges = fixedChargeCommercial;
	TBillSystem = cost;
	return;
}
void BillSystem::CommercialPhase1Bill(int regUnit, int taxCommercial, int regUnitPriceForCommercial, int fixedChargeCommercial)
{
	int cost;
	if (regUnit)
	{
		cost = regUnit - Regular_Meter_Reading;
	}
	else
		cost = Regular_Meter_Reading;
	cost = cost * regUnitPriceForCommercial;
	Energy_Cost = cost;
	cost = (cost * taxCommercial) / 100;
	Taxing_Sale = taxCommercial;
	cost += fixedChargeCommercial;
	amount_Fixed_Charges = fixedChargeCommercial;
	TBillSystem = cost;
}
void BillSystem::SaveBillSystemInFile(ofstream& OutputBillSystem)
{
	OutputBillSystem << Unique_RegistereduserId << ",";
	OutputBillSystem << BillSystemMonth << ",";
	OutputBillSystem << Peak_Meter_Reading << ",";
	OutputBillSystem << Peak_Meter_Reading << ",";
	OutputBillSystem << IssueDate << ",";
	OutputBillSystem << Energy_Cost << ",";
	OutputBillSystem << Taxing_Sale << ",";
	OutputBillSystem << amount_Fixed_Charges << ",";
	OutputBillSystem << TBillSystem << ",";
	OutputBillSystem << _LDueDate << ",";
	OutputBillSystem << BillSystemPaidStatus << ",";
	OutputBillSystem << BillSystemPayementDate << endl;
}



class Tarrif
{
	friend class _WapdaLESCO;
private:

	int Reg_Unit_Price[6];
	int Absolute_Charges_Commercial;
	int Peek_Unit_Price[6];
	int Tax_Percentage_Domestic;
	int Tax_Percentage_Commercial;
	int Absolute_Charges_Domestic;
public:
	Tarrif()
	{
		for (int i = 0; i < 4; i++)
		{
			Reg_Unit_Price[i] = 0;
			Peek_Unit_Price[i] = 0;
		}
		Tax_Percentage_Domestic = 0;
		Tax_Percentage_Commercial = 0;
		Absolute_Charges_Domestic = 0;
		Absolute_Charges_Commercial = 0;
	}


	void LoadTarrifFile()
	{
		string temp;
		ifstream Tariff("TarrifTaxInfo.txt");
		if (Tariff)
		{
			for (int i = 0; i < 4; i++)
			{
				getline(Tariff, temp, ',');


				getline(Tariff, temp, ',');
				Reg_Unit_Price[i] = stoi(temp);

				getline(Tariff, temp, ',');
				if (temp == "")
				{
					Peek_Unit_Price[i] = 0;
				}
				else
					Peek_Unit_Price[i] = stoi(temp);


				if (i == 0 || i == 2)
				{
					getline(Tariff, temp, ',');
					Tax_Percentage_Domestic = stoi(temp);

					getline(Tariff, temp, '\n');
					Absolute_Charges_Domestic = stoi(temp);
				}
				if (i == 1 || i == 3)
				{
					getline(Tariff, temp, ',');
					Tax_Percentage_Commercial = stoi(temp);

					getline(Tariff, temp, '\n');
					Absolute_Charges_Commercial = stoi(temp);
				}
			}
		}
		else
		{
			cout << endl << "Sorry the Tariff File can't be open " << endl;
		}

	}
	void UpdateTarrifFile()
	{
		system("cls");
		int Pressed_value = 0;
		cout << "To Modify the tax percentage for domestic customers, Press 1.\n"
			 << "To Modify the tax percentage for Commercial Customers, Press 2.\n"
			 << "Change the Fixed Charges for Domestic Customers by Pressing 3-\n"
			 << "Change the Fixed Charges for Commercial Customers by Pressing 4-\n"
			 << "To change Regular Unit Price , Press 5- \n"
			 << "To change Peak Hour Unit Price,Press 6- \n\n\n";
		cin  >> Pressed_value;
		if (Pressed_value == 1)
		{
			cout << "Please Press the Tax Percentage for Domestic Customers";
			cin >> Tax_Percentage_Domestic;
		}
		if (Pressed_value == 2)
		{
			cout << "Please Press the Tax Percentage for Commercial Customers";
			cin >> Tax_Percentage_Commercial;
		}
		if (Pressed_value == 3)
		{
			cout << "Please Press the Fixed Charges for Domestic Customers";
			cin >> Absolute_Charges_Domestic;
		}
		if (Pressed_value == 4)
		{
			cout << "Plase Press the Fixed Charges for Commercial Customers";
			cin >> Absolute_Charges_Commercial;
		}
		system("cls");
		if (Pressed_value == 5)
		{
			int count;
			cout << "++++++++++++++Regular Unit Price++++++++++++++\n\n";
			cout << "Press 1- Phase 1 and Domestic\n "
				<< "Press 2- Phase 1 and Commercial\n"
				<< "Press 3- Phase 3 and Domestic\n"
				<< "Press 4- Phase 3 and Commercial\n\n";
			cin >> count;
			if (count == 1)
			{
				cout << "Press Regular Unit Price for Phase 1 Domestic Customers\n";
				cin >> Reg_Unit_Price[0];
			}
			if (count == 2)
			{
				cout << "Press Regular Unit Price for Phase 1 Commercial Customers\n";
				cin >> Reg_Unit_Price[1];
			}
			if (count == 3)
			{
				cout << "Press Regular Unit Price for Phase 3 Domestic Customers\n";
				cin >> Reg_Unit_Price[2];
			}
			if (count == 4)
			{
				cout << "Press Regular Unit Price for Phase 3 Commercial Customers\n";
				cin >> Reg_Unit_Price[3];
			}
		}
		if (Pressed_value == 6)
		{
			int count;
			cout << "--------------Peak Hour Unit--------------\n\n";
			cout << "Press 1 Phase 3 Domestic \n"
				<< "Press 2 Phase 3 Commercial \n\n";
			cin >> count;
			if (count == 1)
			{
				cout << "Press Peak Hour Unit for Phase 3 Domestic\n ";
				cin >> Peek_Unit_Price[2];
			}
			if (count == 2)
			{
				cout << "Press Peak Hour Unit for Phase 3 Commercial\n ";
				cin >> Peek_Unit_Price[3];
			}
		}

		InputUpdateTarrif();


	}
	void InputUpdateTarrif()
	{
		ofstream Update("TarrifTaxInfo.txt");
		for (int i = 0; i < 4; i++)
		{
			if (i == 0)
			{
				Update << "1Phase, "
					<< Reg_Unit_Price[i] << ","
					<< Peek_Unit_Price[i] << ","
					<< Tax_Percentage_Domestic << ","
					<< Absolute_Charges_Domestic << endl;
			}
			if (i == 1)
			{
				Update << "1Phase, "
					<< Reg_Unit_Price[i] << ","
					<< Peek_Unit_Price[i] << ","
					<< Tax_Percentage_Commercial << ","
					<< Absolute_Charges_Commercial << endl;
			}
			if (i == 2)
			{
				Update << "3Phase, "
					<< Reg_Unit_Price[i] << ","
					<< Peek_Unit_Price[i] << ","
					<< Tax_Percentage_Domestic << ","
					<< Absolute_Charges_Domestic << endl;
			}
			if (i == 3)
			{
				Update << "3Phase, "
					<< Reg_Unit_Price[i] << ","
					<< Peek_Unit_Price[i] << ","
					<< Tax_Percentage_Commercial << ","
					<< Absolute_Charges_Commercial << endl;
			}

		}
	}
};



class _WapdaLESCO
{
	Record_Registereduser** Record_RegistereduserList;
	LESCOWORKERS** LESCOWORKERSList;
	Record_Registereduser* CurrentRecord_Registereduser;
	LESCOWORKERS* CurrentLESCOWORKERS;
	BillSystem** BillSystemingList;
	Tarrif File;
	int TotalRecord_Registeredusers;
	int TotalLESCOWORKERSs;
	int TBillSystems;
public:
	_WapdaLESCO();
	void Read_File_DataRecord_Registeredusers();
	void Read_File_DataLESCOWORKERSs();
	void Read_File_DataBillSystems();
	void LoadDataFromTarrifFile();

	void RegisterUsers();
	void RegisterEmplyees();

	bool CheckCorrectName(string);
	bool CheckCorrectPassword(string);

	void Printing_RegistrationDetail_LescoWorkers(); // Saving After Registration of Lesco Worker 
	void Printing_RegistrationDetail_User();
	void PrintInfo_BillSystem();      // Saving after Generation Detail of Bill System

	Record_Registereduser* SearchById(int);
	void AddingEntry();         // Adding or Updating Entry
	void Link_user_toBillSystem();
	void LinkBillingSystem(); // Associating Bill to Billing System
	void BillGenerator();
	bool LinkingUserToRecord(); // Setting Current Record to the Registered User
	bool SetCurrentLESCOWORKERS();
	bool Password_Changing();    // Changing Password
};

_WapdaLESCO::_WapdaLESCO()
{
	Record_RegistereduserList = 0;
	LESCOWORKERSList = 0;
	TotalRecord_Registeredusers = 0;
	TotalLESCOWORKERSs = 0;
	BillSystemingList = 0;
	TBillSystems = 0;
}
void _WapdaLESCO::Read_File_DataRecord_Registeredusers()
{
	ifstream Input_UserRecords("CustomerInfo.txt");

	if (Input_UserRecords)
	{
		Input_UserRecords >> TotalRecord_Registeredusers;
		Record_RegistereduserList = new Record_Registereduser * [10];
		for (int i = 0; i < TotalRecord_Registeredusers;i++)
		{
			Record_RegistereduserList[i] = new Record_Registereduser;
			Record_RegistereduserList[i]->Read_File_Data(Input_UserRecords);
		}
		Input_UserRecords.close();
	}

}
void _WapdaLESCO::Read_File_DataLESCOWORKERSs()
{
	ifstream inputLESCOWORKERS("EmployeesData.txt");
	if (inputLESCOWORKERS)
	{
		inputLESCOWORKERS >> TotalLESCOWORKERSs;
		string ign;
		getline(inputLESCOWORKERS, ign);
		LESCOWORKERSList = new LESCOWORKERS * [10];
		for (int i = 0; i < TotalLESCOWORKERSs;i++)
		{
			LESCOWORKERSList[i] = new LESCOWORKERS;
			LESCOWORKERSList[i]->Read_File_Data(inputLESCOWORKERS);
		}
		inputLESCOWORKERS.close();
	}
	else
	{
		cerr << "No File can be found of LESCOWORKERS's Data!" << endl;
	}
}
void _WapdaLESCO::Read_File_DataBillSystems()
{
	ifstream inputBillSystems("BillSystemingInfo.txt");
	if (inputBillSystems)
	{
		inputBillSystems >> TBillSystems;
		BillSystemingList = new BillSystem * [10];
		for (int i = 0;i < TBillSystems;i++)
		{
			BillSystemingList[i] = new BillSystem;
			BillSystemingList[i]->Read_File_Data(inputBillSystems);
		}
		inputBillSystems.close();
	}
}
void  _WapdaLESCO::LoadDataFromTarrifFile()
{
	File.LoadTarrifFile();
}
void _WapdaLESCO::RegisterUsers()
{
	if (Record_RegistereduserList == 0)
	{
		Record_RegistereduserList = new Record_Registereduser * [12];
	}
	Record_RegistereduserList[TotalRecord_Registeredusers] = new Record_Registereduser;

	Record_RegistereduserList[TotalRecord_Registeredusers]->_Get_RecordOfUser();
	TotalRecord_Registeredusers++;
	Printing_RegistrationDetail_User();
}
void _WapdaLESCO::RegisterEmplyees()
{
	if (LESCOWORKERSList == 0)
	{
		LESCOWORKERSList = new LESCOWORKERS * [12];
	}

	string Name, pass;
	int PasswordCount = 3;
	cout << "Press _RegistereduserName : ";
	cin.ignore();
	getline(cin, Name);

	if (CheckCorrectName(Name))
	{
		cout << "Press your password of 5 digits: ";
		getline(cin, pass);
		if (CheckCorrectPassword(pass) == 0)
		{
			while (CheckCorrectPassword(pass) != true)
			{
				if (PasswordCount < 0)
				{
					cout << "Sorry you can't be registered.....You have attempted all your 3 extra tries " << endl;
					break;
				}
				cout << "Invalid Password. You have " << PasswordCount - 1 << "  Attempts left" << endl;
				PasswordCount--;

				cout << "Press your password of 5 digits: ";
				getline(cin, pass);
			}

		}
		if (CheckCorrectPassword(pass))
		{
			cout << "Your Registeration is Done. Welcome to _WapdaLESCO Company as LESCOWORKERS " << endl;
			LESCOWORKERSList[TotalLESCOWORKERSs] = new LESCOWORKERS;
			LESCOWORKERSList[TotalLESCOWORKERSs]->InputLESCOWORKERSData(Name, pass);
			TotalLESCOWORKERSs++;
		}
	}
	else
	{
		cerr << "Sorry the name is already registered. Please Try Again " << endl;
		return;
	}

	Printing_RegistrationDetail_LescoWorkers();


}

bool _WapdaLESCO::CheckCorrectName(string Name)
{
	ifstream inputLESCOWORKERS("EmployeesData.txt");
	string temp;
	if (TotalLESCOWORKERSs == 0)
	{
		return true;
	}
	else
	{
		getline(inputLESCOWORKERS, temp);
		for (int i = 0; i < TotalLESCOWORKERSs; i++)
		{
			getline(inputLESCOWORKERS, temp, ',');
			if (Name.compare(temp) == 0)
				return false;
			else
			{
				return true;
			}
		}
	}
}
bool _WapdaLESCO::CheckCorrectPassword(string Password)
{
	bool ValidPassword = false;
	if (Password.length() < 5 || Password.length() > 5)
	{
		ValidPassword = false;
	}
	if (Password.length() == 5)
	{
		ValidPassword = true;
	}
	return ValidPassword;
}

void _WapdaLESCO::Printing_RegistrationDetail_User()
{
	ofstream _out_Record("CustomerInfo.txt");
	_out_Record << TotalRecord_Registeredusers << endl;
	for (int i = 0;i < TotalRecord_Registeredusers;i++)
	{
		Record_RegistereduserList[i]->Save(_out_Record);
	}
}
void _WapdaLESCO::Printing_RegistrationDetail_LescoWorkers()
{
	ofstream OutputLESCOWORKERS("EmployeesData.txt");
	OutputLESCOWORKERS << TotalLESCOWORKERSs << endl;
	for (int i = 0;i < TotalLESCOWORKERSs;i++)
	{
		LESCOWORKERSList[i]->Save(OutputLESCOWORKERS);
	}
}
void  _WapdaLESCO::PrintInfo_BillSystem()
{
	ofstream OutputBillSystem("BillSystemingInfo.txt");
	OutputBillSystem << TBillSystems << endl;
	for (int i = 0;i < TBillSystems;i++)
	{
		BillSystemingList[i]->SaveBillSystemInFile(OutputBillSystem);
	}
}

Record_Registereduser* _WapdaLESCO::SearchById(int id)
{
	for (int i = 0;i < TotalRecord_Registeredusers;i++)
	{
		if (Record_RegistereduserList[i]->GetId() == id)
			return Record_RegistereduserList[i];
	}
	cerr << "No Id is Found" << endl;
	return 0;
}

void _WapdaLESCO::Link_user_toBillSystem()
{
	for (int i = 0;i < TBillSystems;i++)
	{
		BillSystemingList[i]->Set_Registereduser(SearchById(BillSystemingList[i]->GetId()));
	}
}
void _WapdaLESCO::LinkBillingSystem()
{
	for (int i = 0;i < TotalRecord_Registeredusers;i++)
	{
		for (int j = 0;j < TBillSystems;j++)
			if (Record_RegistereduserList[i]->GetId() == BillSystemingList[j]->GetId())
			{
				Record_RegistereduserList[i]->SetBillSystem(BillSystemingList[j]);
				return;
			}
	}
}

void _WapdaLESCO::BillGenerator()
{
	int id;
	cout << "-------------------ADD Information Into A BillSystem-------------------" << endl << endl;
	cout << "Press the Record_Registereduser Id: ";
	cin >> id;
	Record_Registereduser* temp = SearchById(id);
	if (temp)
	{
		if (BillSystemingList == 0)
		{
			BillSystemingList = new BillSystem * [10];
		}
		BillSystemingList[TBillSystems] = new BillSystem;
		BillSystemingList[TBillSystems + 1] = 0;
		BillSystemingList[TBillSystems]->BillGenerator(id, temp->To_Get_MeterReading(), temp->To_Get__Registereduser_Type(), temp->To_Get_RegUnits(), temp->To_Get_PeaksUnit(), File.Tax_Percentage_Domestic, File.Tax_Percentage_Commercial,
			File.Absolute_Charges_Domestic, File.Absolute_Charges_Commercial, File.Reg_Unit_Price, File.Peek_Unit_Price);
		TBillSystems++;
		PrintInfo_BillSystem();
	}
	else
	{
		cerr << "Press correct Record_Registereduser Id to Generate a BillSystem" << endl;
	}
}

bool _WapdaLESCO::SetCurrentLESCOWORKERS()
{
	cout << "--------------------------LESCOWORKERS Login ------------------------------" << endl;
	string Name, Password;
	cin.ignore();
	cout << "Press your name :  ";
	getline(cin, Name);

	cout << "Press your Password : ";
	getline(cin, Password);
	for (int i = 0;i < TotalLESCOWORKERSs;i++)
	{
		if (LESCOWORKERSList[i]->ValidationCheck(Name, Password))
		{
			CurrentLESCOWORKERS = LESCOWORKERSList[i];
			cout << "You are logged in ;) " << endl;
			return 1;
		}
	}
	cout << "You are not Logged in !!! No match Found!" << endl;
	return 0;
}
bool _WapdaLESCO::Password_Changing()
{
	if (CurrentLESCOWORKERS == 0)
	{
		cout << "you have to be login First" << endl;
		return 0;
	}
	else
	{
		string Name, Password;
		cout << "Press your name :  ";
		cin.ignore();
		getline(cin, Name);

		cout << "Press your Password : ";
		getline(cin, Password);
		if (CurrentLESCOWORKERS->ValidationCheck(Name, Password))
		{
			cout << "Press your  New Password : ";
			getline(cin, Password);
			if (CheckCorrectPassword(Password))
			{
				CurrentLESCOWORKERS->InputLESCOWORKERSData(Name, Password);
				Printing_RegistrationDetail_LescoWorkers();
				cout << "Your Password is updated successfully !!!!! " << endl;
				return 1;
			}
			else
			{
				cerr << "your Password's Syntax is not Right! Try again Later" << endl;
				return 0;
			}
		}
		else
		{
			cerr << "UserName or Password is Incorrect." << endl;
		}
	}

}
bool _WapdaLESCO::LinkingUserToRecord()
{
	cout << "--------------------------Record_Registereduser Login ------------------------------" << endl;
	int Id;
	string Dob;
	cout << "Press your Record_Registereduser Id :  ";
	cin >> Id;

	cout << "Press your Date of Birth (Without Spaces of Format YYYYMMDD) : ";
	cin.ignore();
	getline(cin, Dob);
	for (int i = 0;i < TotalRecord_Registeredusers;i++)
	{
		if (Record_RegistereduserList[i]->ValidationCheck(Id, Dob))
		{
			CurrentRecord_Registereduser = Record_RegistereduserList[i];
			cout << "You are logged in ;) " << endl;
			return 1;
		}
	}
	cout << "You are not Logged in !!! No match Found!" << endl;
	return  0;
}



void _WapdaLESCO::AddingEntry()
{
	cout << "Press Customer'id for updation:\t";
	int  id;
	cin >> id;

	Record_Registereduser* temp = SearchById(id);
	if (temp)
	{
		temp->UpdateInfo();
		Printing_RegistrationDetail_User();
	}
}







void main()
{
	int choice = 0;
	_WapdaLESCO _WapdaLESCO;

	cout << "-------------------------------Welcome To the Wapda-LESCO Official PORTAL-------------------------------					" << endl << endl << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Menue~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl << endl;
	cout << "Press 1 For LESCO EMPLOYEES Registeration-------------" << endl;
	cout << "Press 2 for Login for LESCO USERS------------" << endl;
	cout << "Press 3 For LESCO EMPLOYEES Login-------------" << endl;
	cin >> choice;
	if (choice == 1)
	{
		int turn = 0;
		while (turn != -1)
		{
			_WapdaLESCO.Read_File_DataLESCOWORKERSs();
			_WapdaLESCO.RegisterEmplyees();
			_WapdaLESCO.Read_File_DataLESCOWORKERSs();
			cout << "Press -1 to Exit or 1 for Again Registeration.. Thank you" << endl;
			cin >> turn;
		}
		cout << "----Going To Main Menue----" << endl;
	}
	if (choice == 2)
	{
		_WapdaLESCO.Read_File_DataRecord_Registeredusers();
		_WapdaLESCO.Read_File_DataLESCOWORKERSs();
		_WapdaLESCO.LinkingUserToRecord();
	}
	if (choice == 3)
	{
		_WapdaLESCO.Read_File_DataRecord_Registeredusers();
		_WapdaLESCO.Read_File_DataBillSystems();
		_WapdaLESCO.Read_File_DataLESCOWORKERSs();
		_WapdaLESCO.LoadDataFromTarrifFile();
		if (_WapdaLESCO.SetCurrentLESCOWORKERS())
		{
			int option = 0;
			cout << "Press 1 to change your Password" << endl;
			cout << "Press 2 to Generate A new BillSystem" << endl;
			cout << "Press 3 to Update Customer info" << endl;
			cin >> option;
			if (option == 1)
			{
				_WapdaLESCO.Password_Changing();
			}
			if (option == 2)
			{
				_WapdaLESCO.BillGenerator();
			}
			if (option == 3)
			{
				_WapdaLESCO.AddingEntry();
			}
		}

	}
}