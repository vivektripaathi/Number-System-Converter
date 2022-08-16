#include <bits/stdc++.h>

using namespace std;

string decimal_to_binary(string);
string binary_to_decimal(string);
string decimal_to_octal(string);
string octal_to_decimal(string);
string binary_to_hexa(string);
string hexa_to_binary(string);

string binary_to_octal(string binary)
{
    string decimal = binary_to_decimal(binary);
    string octal = decimal_to_octal(decimal);
    return octal;
}

string binary_to_decimal(string binary)
{
    int decimal_check = -1;
    string decimal;
    for (int i = 0; i < binary.length(); i++)
    {
        if (binary[i] == '.')
        {
            decimal_check = i;
        }
    }
    if (decimal_check == -1)
    {
        int decimal_int = 0, base = 1;
        for (int i = (binary.length() - 1); i >= 0; i--)
        {
            decimal_int += (binary[i] - '0') * base;
            base *= 2;
        }
        decimal = to_string(decimal_int);
    }
    else
    {
        float base = 1.0;
        float decimal_float = 0;
        for (int i = (decimal_check - 1); i >= 0; i--)
        {
            decimal_float += (binary[i] - '0') * base;
            base *= 2;
        }
        base = 2;
        for (int i = (decimal_check + 1); i < binary.length(); i++)
        {
            decimal_float += (binary[i] - '0') * (1 / base);
            base *= 2;
        }
        decimal = to_string(decimal_float);
    }
    return decimal;
}

void createMap(unordered_map<string, char> *um)
{
	(*um)["0000"] = '0';
	(*um)["0001"] = '1';
	(*um)["0010"] = '2';
	(*um)["0011"] = '3';
	(*um)["0100"] = '4';
	(*um)["0101"] = '5';
	(*um)["0110"] = '6';
	(*um)["0111"] = '7';
	(*um)["1000"] = '8';
	(*um)["1001"] = '9';
	(*um)["1010"] = 'A';
	(*um)["1011"] = 'B';
	(*um)["1100"] = 'C';
	(*um)["1101"] = 'D';
	(*um)["1110"] = 'E';
	(*um)["1111"] = 'F';
}
string binary_to_hexa(string binary)
{
	int l = binary.size();
	int t = binary.find_first_of('.');
	int len_left = t != -1 ? t : l;
	for (int i = 1; i <= (4 - len_left % 4) % 4; i++)
		binary = '0' + binary;
	if (t != -1)
	{
		int len_right = l - len_left - 1;
		for (int i = 1; i <= (4 - len_right % 4) % 4; i++)
			binary = binary + '0';
	}
	unordered_map<string, char> bin_hex_map;
	createMap(&bin_hex_map);
	int i = 0;
	string hex = "";
	while (1)
	{
		hex += bin_hex_map[binary.substr(i, 4)];
		i += 4;
		if (i == binary.size())
			break;
			
		if (binary.at(i) == '.')
		{
			hex += '.';
			i++;
		}
	}
	return hex;
}

string octal_to_decimal(string octal)
{
    int point_check = -1;
    string decimal;
    for (int i = 0; i < octal.length(); i++)
    {
        if (octal[i] == '.')
        {
            point_check = i;
        }
    }
    if (point_check == -1)
    {
        int decimal_int = 0, base = 1;
        for (int i = (octal.length() - 1); i >= 0; i--)
        {
            decimal_int += (octal[i] - '0') * base;
            base *= 8;
        }
        decimal = to_string(decimal_int);
    }
    else
    {
        float decimal_float = 0.00, base = 1;
        for (int i = point_check - 1; i >= 0; i--)
        {
            decimal_float += (octal[i] - '0') * base;
            base *= 8;
        }
        base = 8;
        for (int i = point_check + 1; i < octal.length(); i++)
        {
            decimal_float += (octal[i] - '0') * (1 / base);
            base *= 8;
        }
        decimal = to_string(decimal_float);
    }
    return decimal;
}

string octal_to_binary(string octal)
{
    string decimal = octal_to_decimal(octal);
    return (decimal_to_binary(decimal));
}

string octal_to_hexa(string octal){
    string binary = octal_to_binary(octal);
    string hexa = binary_to_hexa(binary);
    return hexa;
}

string decimal_to_octal(string decimal)
{
    int check_point = -1;
    string octal;
    for (int i = 0; i < decimal.length(); i++)
    {
        if (decimal[i] == '.')
        {
            check_point = i;
        }
    }
    if (check_point == -1)
    {
        int decimal_int = stoi(decimal);
        while (decimal_int > 0)
        {
            octal.push_back(('0' + (decimal_int % 8)));
            decimal_int /= 8;
        }
        reverse(octal.begin(), octal.end());
    }
    else
    {
        int decimal_int = stoi(decimal);
        while (decimal_int > 0)
        {
            octal.push_back(('0' + (decimal_int % 8)));
            decimal_int /= 8;
        }
        reverse(octal.begin(), octal.end());
        octal.push_back('.');
        float decimal_float = (stof(decimal) - stoi(decimal));
        for (int i = 0; i < 3; i++)
        {
            int temp = decimal_float * 8.00;
            octal.push_back(('0' + temp));
            decimal_float = (decimal_float * 8.00) - temp;
        }
    }
    return octal;
}

string decimal_to_hexa(string decimal){
    string binary = decimal_to_binary(decimal);
    string hexa = binary_to_hexa(binary);
    return hexa;
}

string decimal_to_binary(string decimal)
{
    int point_check = -1;
    string binary;
    for (int i = 0; i < decimal.length(); i++)
    {
        if (decimal[i] == '.')
        {
            point_check = i;
        }
    }
    if (point_check == -1)
    {
        int decimal_int = stoi(decimal);
        while (decimal_int > 0)
        {
            binary.push_back('0' + (decimal_int % 2));
            decimal_int /= 2;
        }
        reverse(binary.begin(), binary.end());
    }
    else
    {
        int decimal_int = stoi(decimal);
        while (decimal_int > 0)
        {
            binary.push_back('0' + (decimal_int % 2));
            decimal_int /= 2;
        }
        reverse(binary.begin(), binary.end());
        binary.push_back('.');
        float decimal_float = stof(decimal) - stoi(decimal);
        while (decimal_float > 0.00)
        {
            int temp = decimal_float * 2;
            binary.push_back('0' + temp);
            decimal_float = (decimal_float * 2.00) - temp;
        }
    }
    return binary;
}

string hexa_to_binary(string hexa){
    string binary;
    for(int i = 0;i<hexa.length();i++){
        switch(hexa[i]){
            case '0':{
                binary += "0000";
                break;
            }
            case '1':{
                binary += "0001";
                break;
            }
            case '2':{
                binary += "0010";
                break;
            }
            case '3':{
                binary += "0011";
                break;
            }
            case '4':{
                binary += "0100";
                break;
            }
            case '5':{
                binary += "0101";
                break;
            }
            case '6':{
                binary += "0110";
                break;
            }
            case '7':{
                binary += "0111";
                break;
            }
            case '8':{
                binary += "1000";
                break;
            }
            case '9':{
                binary += "1001";
                break;
            }
            case 'a':{
                binary += "1010";
                break;
            }
            case 'b':{
                binary += "1011";
                break;
            }
            case 'c':{
                binary += "1100";
                break;
            }
            case 'd':{
                binary += "1101";
                break;
            }
            case 'e':{
                binary += "1110";
                break;
            }
            case 'f':{
                binary += "1111";
                break;
            }
            case 'A':{
                binary += "1010";
                break;
            }
            case 'B':{
                binary += "1011";
                break;
            }
            case 'C':{
                binary += "1100";
                break;
            }
            case 'D':{
                binary += "1101";
                break;
            }
            case 'E':{
                binary += "1110";
                break;
            }
            case 'F':{
                binary += "1111";
                break;
            }
            case '.':{
                binary += '.';
                break;
            }
        }
    }
    return binary;
}

string hexa_to_octal(string hexa){
    string binary = hexa_to_binary(hexa);
    string octal = binary_to_octal(binary);
    return octal;
}

string hexa_to_decimal(string hexa){
    string binary = hexa_to_binary(hexa);
    string decimal = binary_to_decimal(binary);
    return decimal;
}

int main()
{
// Tittle
    printf("\n\t\t\t\t\t*************************\n\t\t\t\t\t NUMBER SYSTEM CONVERTER\n\t\t\t\t\t*************************\n");
    main_program_begin:
    printf("\nChoose the type of number that you want to convert\nPress\n1 for Binary Number \n2 for Octal Number \n3 for Decimal Number \n4 for Hexa Decimal Number\n");
    int choice;
    cin >> choice;
    switch (choice)
    {
    case 1:
    {
        printf("\nEnter a Binary Number\n");
        string binary;
        cin >> binary;
    conversion_type_binary:
        printf("\nChoose the conversion type\nPress\n1 for Binary --> Octal\n2 for Binary --> Decimal\n3 for Binary --> Hexa-Decimal\n");
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << endl
                 << "The Octal Equivalent of " << binary << " is " << binary_to_octal(binary) << endl
                 << endl;
            break;
        case 2:
            cout << endl
                 << "The Decimal Equivalent of " << binary << " is " << binary_to_decimal(binary) << endl
                 << endl;
            break;
        case 3:
            cout<<endl<<"The Hexa-Decimal Equivalent of "<<binary<<" is "<<binary_to_hexa(binary)<<endl<<endl;
            // break;
            break;
        default:
            cout << endl
                 << "Invalid Input Found! Please Enter a valid number" << endl
                 << endl;
            goto conversion_type_binary;
        }
        break;
    }
    case 2:
    {
        printf("\nEnter a Octal Number\n");
        string octal;
        cin >> octal;
    conversion_type_octal:
        printf("\nChoose the conversion type\nPress\n1 for Octal --> Decimal \n2 for Octal --> Hexa-Decimal\n3 for Octal --> Binary\n");
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << endl
                 << "The Decimal Equivalent of " << octal << " is " << octal_to_decimal(octal) << endl
                 << endl;
            break;
        case 2:
            cout<<endl<<"The Hexa-Decimal Equivalent of "<<octal<<" is "<<octal_to_hexa(octal)<<endl<<endl;
            break;
        case 3:
            cout << endl
                 << "The Binary Equivalent of " << octal << " is " << octal_to_binary(octal) << endl
                 << endl;
            break;
        default:
            cout << endl
                 << "Invalid Input Found! Please Enter a valid number" << endl
                 << endl;
            goto conversion_type_octal;
        }
        break;
    }
    case 3:
    {
        printf("\nEnter a Decimal Number\n");
        string decimal;
        cin >> decimal;
    conversion_type_decimal:
        printf("\nChoose the conversion type\nPress\n1 for Decimal --> Hexa-Decimal \n2 for Decimal --> Binary\n3 for Decimal --> Octal\n");
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout<<endl<<"The Hexa-Decimal Equivalent of "<<decimal<<" is "<<decimal_to_hexa(decimal)<<endl;
            break;
        case 2:
            cout << endl
                 << "The Binary Equivalent of " << decimal << " is " << decimal_to_binary(decimal) << endl;
            break;
        case 3:
            cout << endl
                 << "The Octal Equivalent of " << decimal << " is " << decimal_to_octal(decimal) << endl;
            break;
        default:
            cout << endl
                 << "Invalid Input Found! Please Enter a valid number" << endl
                 << endl;
            goto conversion_type_decimal;
        }
        break;
    }
    case 4:
    {
        printf("\nEnter a Hexa-Decimal Number\n");
        string hexa_decimal;
        cin >> hexa_decimal;
    conversion_type_hexa:
        printf("\nChoose the conversion type\nPress\n1 for Hexa-Decimal --> Binary \n2 for Hexa-Decimal --> Octal\n3 for Hexa-Decimal --> Decimal\n");
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout<<endl<<"The Binary Equivalent of "<<hexa_decimal<<" is "<<hexa_to_binary(hexa_decimal)<<endl;
            break;
        case 2:
            cout<<endl<<"The Octal Equivalent of "<<hexa_decimal<<" is "<<hexa_to_octal(hexa_decimal)<<endl;
            break;
        case 3:
            cout<<endl<<"The Decimal Equivalent of "<<hexa_decimal<<" is "<<hexa_to_decimal(hexa_decimal)<<endl;
            break;
        default:
            cout << endl
                 << "Invalid Input Found! Please Enter a valid number" << endl
                 << endl;
            goto conversion_type_hexa;
        }
        break;
    }
    default:
    {
        cout << endl
             << "Invalid Input Found! Please Enter a valid number" << endl
             << endl;
        goto main_program_begin;
    }
    }
    printf("Do you want more conversion?\nPress\nY for Yes\nN for No\n");
    char ch;
    cin>>ch;
    if(ch == 'y'||ch == 'Y'){
        goto main_program_begin;
    }
    else{
        goto program_end_point;
    }
    program_end_point:
    printf("\nNice To See You Here \nEnter any key to exit\n%c\n",1);
    cin>>ch;
    return 0;
}