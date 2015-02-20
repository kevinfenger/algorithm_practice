#include <stdio.h>
#include <stdlib.h>
#include <iostream> 
#include <math.h> 
using namespace std; 
void 
print_cube_roots(int n) { 

	int i,j,k,i3,j3,k3;

	int max_cube = static_cast<int>(pow( (double)n, (double)1/3 ));

	double cube_root = 0;

	int number = 0;

	for (  i = 1 ; i < max_cube ; i++ )
	{
		i3 = i*i*i;
		for (  j = i+1 ; j < max_cube ; j++ )
		{
			j3 = j*j*j;
			
			for ( k = i+1 ; k < max_cube ; k++ )
			{
				if ( k != j )
				{
					k3 = k*k*k;
					number = i3+j3-k3;
					cube_root = ceil( pow( (double)number, (double)1/3 ) );
				cout << "number : " << number << " pow cube_root : " << pow(cube_root,3) << endl; 	
					if ( ( pow( cube_root, 3 ) == number ) && ( cube_root > k ) )
					{
						printf("%d = %d^3 + %d^3 = %d^3 + %d^3\n", i3+j3 , i,j,k,(int)cube_root );
					}
				}
			}
		}
	}
}

int main() { 
   print_cube_roots(1729); 
}
