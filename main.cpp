#include <fstream>
#include <iostream>
#include <chrono>
#include <iomanip>
using namespace std;

int main()
{
    int polynomials, variables, no_of_non_zeros = 0, choice;
    string name_of_file;
    clock_t time_req;
    cout << "\nEnter File name in format(file_name.txt)\n";
    cin >> name_of_file;
    ifstream in(name_of_file);
    if (in.fail())
    {
        cout << "\nFile doesnot exists of failed to open";
        return 1;
    }
    else
    {
        in >> polynomials;
        in >> variables;
        int data[polynomials][variables];
        int matrix[variables];
        for (int i = 0; i < variables; i++)
        {
            matrix[i] = 0;
        }
        for (int i = 0; i < polynomials; i++)
        {
            for (int j = 0; j < variables; j++)
            {
                in >> data[i][j];
            }
        }
        in.close();
        cout << "\nWant to Display?\n1)YES OR 2)NO\n";
        cin >> choice;
        if (choice == 1)
        {
            for (int i = 0; i < polynomials; i++)
            {
                for (int j = 0; j < variables; j++)
                {
                    cout << data[i][j] << "\t";
                }
                cout << endl;
            }
        }
        auto begin = std::chrono::high_resolution_clock::now();
        for (int i = 0; i < variables; i++)
        {
            for (int j = 0; j < polynomials; j++)
            {
                matrix[i] += data[j][i];
            }
        }

        auto end = std::chrono::high_resolution_clock::now();
        auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
        ofstream out("result_addition.txt");

        for (int i = 0; i < variables; i++)
        {
            if (matrix[i] != 0)
            {
                no_of_non_zeros++;
            }
        }
        out << "File name: " << name_of_file;
        out << "\nNo of Polynomials: " << polynomials << "\nNo of Variables: " << variables;
        out << "\nNo of non-zero values: " << no_of_non_zeros;
        out << "\nData Structure Used: Array";
        out << "\nTotal Time Taken for Addition: " << (double)(elapsed.count() * 1e-9) << setprecision(5) << " seconds" << endl;
        out << "\nCo-efficients : ";
        for (int i = 0; i < variables; i++)
        {
            out << matrix[i] << "\t";
        }
        out << "\n\nPolynomial: ";
        for (int i = 0; i < variables; i++)
        {
            if (i == 0)
            {
                out << matrix[i];
            }
            else
            {
                out << "+" << matrix[i] << "x" << i;
            }
        }
        out.close();
        return 0;
    }
}
