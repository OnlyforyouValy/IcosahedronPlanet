
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    const int Num_triangle_icosahedron = 20, Num_triangle_pyramid = 4;
    const int Num_coefficient_radix = 10, Num_coefficient_id = 1, Num_coefficient_slice_icosahedron = 5;
    const int Num_min_size = 1, Num_max_size = 7;
    int Size = 0;
    vector < vector <int>> Planet(0);

    // Planet size input
    while ((Size < Num_min_size) || (Size > Num_max_size))
    {
        cout << "Size of planet = N\n" << "1 <= Size of planet <= 7\n" << "Input size of planet:";
        cin >> Size;
    }

    // Planet sectors list resize
    Planet.resize(Num_triangle_icosahedron * pow(Num_triangle_pyramid, Size));
    for (int i = 0; i < Planet.capacity(); i++)
        Planet[i].resize(2);

    // Planet sectors list filling
    for (int i = 0; i < Planet.capacity(); i++)
    {
        int p = 0;
        // Sector id filling
        Planet[i][0] = i + Num_coefficient_id;
        // Sector coordinates filling
        Planet[i][1] = ((i / pow(Num_triangle_pyramid, Size)) / Num_coefficient_slice_icosahedron) + Num_coefficient_id;
        p = (i / pow(Num_triangle_pyramid, Size)) / Num_coefficient_slice_icosahedron;
        Planet[i][1] = (Planet[i][1] * Num_coefficient_radix) + (i / pow(Num_triangle_pyramid, Size)) - (p * Num_coefficient_slice_icosahedron) + Num_coefficient_id;
        for (int j = 0; j < Size; j++)
        {
            Planet[i][1] = Planet[i][1] * Num_coefficient_radix;
            p = i / pow(Num_triangle_pyramid, (Size - j));
            p = (i - (p * pow(Num_triangle_pyramid, (Size - j)))) / pow(Num_triangle_pyramid, (Size - j - Num_coefficient_id));
            Planet[i][1] = Planet[i][1] + p + Num_coefficient_id;
        }
    }

    // Planet sectors list output
    cout << "Planet sectors list:\n";
    for (int i = 0; i < Planet.capacity(); i++)
        for (int j = 0; j < Planet[i].capacity(); j++)
        {
            if (j == 0)
                cout << "id: " << Planet[i][j] << " ";
            if (j == 1)
                cout << "cord: " << Planet[i][j] << "\n";
        }
}